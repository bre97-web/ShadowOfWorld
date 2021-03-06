#include <direct.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"
#include "Error.h"

struct Contralet {
  char userAddress[32], localUserAddressFolder[64], localUserAddressData_DataFile[64],
      localuserAddressData_AchievementFile[64];
};
struct Contralet userAddress;

/*
 *  Function : userLogin()
 *  Effect : Use placed address of user, Find new "userAddress.userAddress" , or Delete.
 *  Update : FALSE - 12-24-2020
 */
int userLogin(void) {
  system("cls");
  systemAddressProceed(0);

  FILE *userAddressOpen = NULL;
  fopen_s(&userAddressOpen, "./resource/data/save/user.txt", "r");
  if (userAddressOpen == NULL) {
    return REPORT_ERROR_USER_FILE_OPEN;
  }
  
  char userName[32][9];
  int userLocalSize = 0;
  while(!feof(userAddressOpen)){
    for (int count = 0; count < 8;count ++) {
      userName[userLocalSize][count] = (char)fgetc(userAddressOpen);
    }
    userName[userLocalSize][8] = '\0';
    userLocalSize ++;
  }
  int userNameWidth = userLocalSize - 1;
  fclose(userAddressOpen);

  if(userLocalSize == 1){
    _Console_Write_Frame("User null\n",'-',1);
  } else {
    _Console_Write_WriteSleep(200,"User List\n");
    for (int stTemp = 0; stTemp < userNameWidth;stTemp++) {
      _Console_Write_Frame(userName[stTemp],'-',1);
    }
  } 

  _Console_Write_Frame("0:Delete  0~8:Name Value" ,'=',1);
  _Console_Write_WriteSleep(200,"Put your user name:\n");

  reProcess:;
  scanf_s("%s", &userAddress.userAddress, 9);

  if (userAddress.userAddress[0] == '0') {
    _Console_Write_WriteSleep(200,"Delete your user name:");
    scanf_s("%s", &userAddress.userAddress, 9);

    if (userNameDefend(userAddress.userAddress) == 0) {
      goto reProcess;
    }

    userAddrssProcess(userAddress.userAddress);
    remove(userAddress.localUserAddressData_DataFile);
    remove(userAddress.localuserAddressData_AchievementFile);
    if (_rmdir(userAddress.localUserAddressFolder) != 0) {
      return REPORT_ERROR_USER_FILE_DELETE;
    }
    remove("./resource/data/save/user.txt");

    for (int count = 0;count < userNameWidth;count ++) {
      if (strcmp(userAddress.userAddress,userName[count]) != 0) {
        _IO_File_Write("./resource/data/save/user.txt", "a+", userName[count]);
      }
    }
    userLogin();
    return REPORT_ACTIVE_FUNCTION_END;
  }

  if (userNameDefend(userAddress.userAddress) == 0){
    goto reProcess; 
  }
  int numCount = 0;
  for (int count = 0; count < userNameWidth;count++) {
    if (userNameSakeDefend(userAddress.userAddress,userName[count]) == 0) {
      numCount = 1;
      break;
    }
  }
  if (numCount != 1) {
    _IO_File_Write("./resource/data/save/user.txt", "a+", userAddress.userAddress);
  }
  userAddrssProcess(userAddress.userAddress);
  systemAddressProceed(userAddress.userAddress);

  _Console_Write_WriteSleep(200, "Opened user name:");
  _Console_Write_Frame(userAddress.userAddress,'-',1);
 
  return REPORT_ACTIVE_FUNCTION_END;
}

/*
 *  user name sake :123456789(1~9) and 8bit
 */
int userNameDefend(char id[]) {
  if (id[7] == 0 || id[8] != 0) {
    puts("8bit number");
    return REPORT_ACTIVE_FALSE;
  }
  for (int count = 0; count < 8; count++) {
    if (id[count] < 48 || id[count] > 57) {
      puts("8bit number 0~9");
      return REPORT_ACTIVE_FALSE;
    }
  }
  return REPORT_ACTIVE_FUNCTION_END;
} 
int userNameSakeDefend(char id[] , char userId[]) {
  if (strcmp(id,userId) == 0) {
    return REPORT_ACTIVE_FALSE;
  }
  return REPORT_ACTIVE_FUNCTION_END;
}
/*
*  Link both array
*  DON'T TOUCH !!!
*
*  List:
*    1 ./resource/data/save/id
*    2 ./resource/data/save/id/data
*    3 ./resource/data/save/id/achievement
*/
void userAddrssProcess(char id[]) {
  _Data_Convert_ArrayLinkBoth("./resource/data/save/",id,userAddress.localUserAddressFolder);
  _Data_Convert_ArrayLinkBoth(userAddress.localUserAddressFolder,"/data",userAddress.localUserAddressData_DataFile);
  _Data_Convert_ArrayLinkBoth(userAddress.localUserAddressFolder,"/achievement",userAddress.localuserAddressData_AchievementFile);
}

/*
*  Sure local file/folder life.
*  DON'T TOUCH !!!
*
*  List:
*    < Folder >
*    1 ./resource
*    2 ./resource/data
*    3 ./resource/data/save
*    4 ./resource/core
*    5 ./resource/core/ptr
*    *6 ./resource/data/save/id
*    < File >
8    1. ./resource/data/save/user.txt
*    *2 ./resource/data/save/id/data.txt
*    *3 ./resource/data/save/id/achievement.txt
*    *4 ./resource/core/ptr/ptr.txt
*/
int systemAddressProceed(char id[]) {
  _IO_Folder_Create("./resource");
  _IO_Folder_Create("./resource/data");
  _IO_Folder_Create("./resource/data/save");
  _IO_Folder_Create("./resource/core");
  _IO_Folder_Create("./resource/core/ptr");
  _IO_File_Create("./resource/data/save/user.txt", "a+");

  if (id == 0) {
    return REPORT_ACTIVE_FUNCTION_END;
  }
  _IO_Folder_Create(userAddress.localUserAddressFolder);
  _IO_File_Create(userAddress.localUserAddressData_DataFile, "a+");
  _IO_File_Create(userAddress.localuserAddressData_AchievementFile, "a+");

  return REPORT_ACTIVE_FUNCTION_END;
}
//  Write local "data".
void sendValueToDataFile(char message[]) {
  _IO_File_Write(userAddress.localUserAddressData_DataFile, "w+", message);
}

/*
 *  Function : getProceed()
 *  Effect : Read local "data" file.
 *  Update : TRUE
 */
int getProceed(void) {
  char userData[3];

  //  Read local "data" file
  FILE *userDataRead = NULL;
  fopen_s(&userDataRead, userAddress.localUserAddressData_DataFile, "r");
  if (userDataRead == NULL) {
    return REPORT_ERROR_USER_FILE_OPEN;
  }
  if (!feof(userDataRead)) {
    _IO_File_Write(userAddress.localUserAddressData_DataFile, "w+", "0000");
  }
  fgets(userData, 3, userDataRead);
  fclose(userDataRead);

  game(userData);


  return REPORT_ACTIVE_FUNCTION_END;
}



