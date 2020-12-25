#include <direct.h>
#include <stdio.h>
#include <windows.h>

#include "Declaration.h"

struct Contralet {
  char userAddress[32], localUserAddressFolder[32], localUserAddressData_DataFile[32],
      localuserAddressData_AchievementFile[32];
};
struct Contralet userAddress;


/*
 *  Sure local file/folder life.
 *  DON'T TOUCH !!!
 *  List:
 *    1:./userSave/
 *    2:userSave/user.txt
 *    3:userSave/userName/data
 *    4:userSave/userName/achievement
 */
void userAddrssProcess(char id[]) {
  _Data_Convert_ArrayLinkBoth("./userSave/",id,
               userAddress.localUserAddressFolder);
  _Data_Convert_ArrayLinkBoth(userAddress.localUserAddressFolder, "/data",
               userAddress.localUserAddressData_DataFile);
  _Data_Convert_ArrayLinkBoth(userAddress.localUserAddressFolder, "/achievement",
               userAddress.localuserAddressData_AchievementFile);
}
int userAddressProcessDefend(char id[]) {
  _IO_Folder_Create("userSave");
  _IO_File_Create("userSave/user.txt", "a+");

  if (id == 0) {
    return -1;
  }
  _mkdir(userAddress.localUserAddressFolder);
  _IO_File_Create(userAddress.localUserAddressData_DataFile, "a+");
  _IO_File_Create(userAddress.localuserAddressData_AchievementFile, "a+");

  _IO_File_Log(userAddress.userAddress, 2);
  _IO_File_Log(userAddress.localUserAddressFolder, 2);
  _IO_File_Log(userAddress.localUserAddressData_DataFile, 2);
  _IO_File_Log(userAddress.localuserAddressData_AchievementFile, 2);

  return 1;
}

/*
 *  Function : userLogin()
 *  Effect : Use placed address of user, Find new "userAddress.userAddress" , or Delete.
 *  Update : FALSE - 12-24-2020
 */
int userLogin(void) {
  userAddressProcessDefend(0);

  FILE *userAddressOpen = NULL;
  fopen_s(&userAddressOpen, "userSave/user.txt", "r");
  if (userAddressOpen == NULL) {
    return -1;
  }
  
  size_t userLocalSize = 0;
  char userLocal[64];
  while(!feof(userAddressOpen)){
    userLocal[userLocalSize] = (char)fgetc(userAddressOpen);
    userLocalSize ++;
  }
  userLocal[userLocalSize] = '\0';
  fclose(userAddressOpen);

  size_t userNameWidth = strlen(userLocal) / 8 , stTemp = 0 , numCount = 0 , numCountAdd = 0;
  char userName[15][9];  

  if(userLocalSize == 1){
    _Console_Write_Frame("User null",2);
  } else {
    _Console_Write_WriteSleep(200,"User List");
    for (stTemp = 0; stTemp < userNameWidth;stTemp++) {
      for (numCount = 0;numCount < 8;numCount ++) {
  	    userName[stTemp][numCount] = userLocal[numCountAdd];
  	    numCountAdd ++;
     	}
  	  userName[stTemp][8] = '\0';
      _Console_Write_Frame(userName[stTemp],1);
    }
  }  

  reProcess:;

  _Console_Write_Frame("0:Delete  0~8:Name Value" , 2);
  _Console_Write_WriteSleep(200,"Put your user name:");
  scanf_s("%s", &userAddress.userAddress, 9);
  getchar();

  if (userAddress.userAddress[0] == '0') {
    _Console_Write_WriteSleep(200,"Delete your user name:");
    scanf_s("%s", &userAddress.userAddress, 9);
    getchar();

    if (userNameDefend(userAddress.userAddress) == 0) {
      goto reProcess;
    }

    userAddrssProcess(userAddress.userAddress);
    remove(userAddress.localUserAddressData_DataFile);
    remove(userAddress.localuserAddressData_AchievementFile);
    _rmdir(userAddress.localUserAddressFolder);
    remove("userSave/user.txt");

    for (stTemp = 0;stTemp < userNameWidth;stTemp ++) {
      if (strcmp(userAddress.userAddress,userName[stTemp]) != 0) {
        _IO_File_Write("userSave/user.txt", "a+", userName[stTemp]);
      }
    }
    userLogin();
    return 1;
  }

  if (userNameDefend(userAddress.userAddress) == 0){
    goto reProcess; 
  }
  numCount = 0;
  for (stTemp = 0; stTemp < userNameWidth;stTemp++) {
    if (userNameSakeDefend(userAddress.userAddress,userName[stTemp]) == 0) {
      numCount = 1;
      break;
    }
  }
  if (numCount != 1) {
    _IO_File_Write("userSave/user.txt", "a+", userAddress.userAddress);
  }
  userAddrssProcess(userAddress.userAddress);
  userAddressProcessDefend(userAddress.userAddress);

  _Console_Write_WriteSleep(200, "Opened user name:");
  _Console_Write_Frame(userAddress.userAddress, 2);
 
  return 1;
}

/*
 *  user name sake :123456789(1~9) and 8bit
 */
int userNameDefend(char id[]) {
  size_t stTemp = 0;
  if (id[7] == 0 || id[8] != 0) {
    puts("8bit number");
    return 0;
  }
  for (stTemp = 0; stTemp < 8; stTemp++) {
    if (id[stTemp] < 48 || id[stTemp] > 57) {
      puts("8bit number 0~9");
      return 0;
    }
  }
  return 1;
} 
int userNameSakeDefend(char id[] , char userId[]) {
  if (strcmp(id,userId) == 0) {
    return 0;
  }
  return 1;
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
  char userData[5];

  //  Read local "data" file
  FILE *userDataRead = NULL;
  fopen_s(&userDataRead, userAddress.localUserAddressData_DataFile, "r");
  if (userDataRead == NULL) {
    return -1;
  }

  if (userDataRead == NULL || feof(userDataRead)) {
    _IO_File_Write(userAddress.localUserAddressData_DataFile,"w+","0011");
  }
  fgets(userData, 5, userDataRead);
  fclose(userDataRead);

  //  EP0__xxx
  if (userData[0] == '0') {
    //  EP0_0xx
    if (userData[1] == '0') {
      //  EP0_00x
      if (userData[2] == '0') {
        //  EP0_000
        if (userData[3] == '0') {
          EP0_Start000();
        
        }
      //  EP0_01x
      } else if (userData[2] == '1') {
        //  EP0_011
        if (userData[3] == '1') {
          EP0_NorthLight011();

        } 

      }
    } else if (userData[1] == '1') {
    } else if (userData[1] == '2') {
    }
  } else if (userData[0] == '1') {
  }



  return 1;
}



