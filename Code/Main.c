#include "Other.Platform.C.vec.NonGraphic.h"
#include "Declaration.h"
#include "conio.h"

int main(void) {
  system("color F0");

  _IO_File_Log(".exe start core.",'=');

  pulseOn();
  _Console_Write_LoadingAnimationSec();
  
  userLogin();
  getMenu(0);

  _IO_File_Log(".exe end core.",'=');

  return 0;
}

int getMenu(int num) {
  system("cls");
  _Console_Write_CutToEnd("1. Game Start\n2. Game Passage\n3. Help\n4. Back User\n0. Game Exit\n", 0, 0, 0);
  _Console_Write_Frame("Which:" ,'=',1 );
  char arr[5][20] = {"Game Start","Game Passage","Help","Back User","Game Exit"};
  printf("%s", arr[num]);

  int userPuts = _getch();
  switch (userPuts) {
    case 119:
      if (num != 0) {
        num--;
      }
      break;
    case 115:
      if (num != 4) {
        num++;
      }
      break;
    case 13:
      if (list(num, 1) == 0) {
        return 0;
      }
      break;
  }
  getMenu(num);
  return 0;
}

int list(int num,int mode) {
  if (mode == 1) {
    if (num == 0) {
      getProceed();
    } else if (num == 1) {
      getGamePassage(0);
    } else if (num == 2) {
      getHelp();
    } else if (num == 3) {
      userLogin();
    } else if (num == 4) {
      return 0;
    }
  } else if (mode == 2) {
    if (num == 0) {
      EP0_Start000();
    }
    else if (num == 1) {
      EP0_NorthLight011();
    }
    else if (num == 2) {
      return 0;
    }
  }



  return 1;
}

int getGamePassage(int num) {
  system("cls");
  _Console_Write_CutToEnd("GIVE_PLAYER_PASSAGE: DISPLAY\n"
                          "1. Start[EP0_000]\n"
                          "2. NorthLight[EP0_011]\n"
                          "0. Passage Back\n"
                          ,0,0,0);
  _Console_Write_Frame("Which:", '=', 1);
  char arr[5][20] = { "Start[EP0_000]","NorthLight[EP0_011]","Passage Back"};
  printf("%s", arr[num]);

  int userPuts = _getch();
  switch (userPuts) {
  case 119:
    if (num != 0) {
      num--;
    }
    break;
  case 115:
    if (num != 4) {
      num++;
    }
    break;
  case 13:
    if (list(num, 2) == 0) {
      return 0;
    }
    break;
  }
  getGamePassage(num);
  return 0;
}

void getHelp(void) {
  system("cls");
  _Console_Write_CutToEnd("In the v0.1 alpha.2 version.\n"
                          "a lot of user operations have been reduced. Now you can enter 1 to indicate the first item.\n"
                          "Plan to expand and support the expansion in the future.\n"
                          , 25, 25, 0);
  _Console_Write_Frame("Author Information:", '=' ,0);
  _Console_Write_Frame("Google - Mail:BY.SGATN3@Gmail.com", '-', 1);
  _Console_Write_Frame("Outlook - Mail:PRIVATE.BY_SGATN3.re@Outlook.com",'-',1);

  system("pause");
}

void pulseOn(void) {
  system("color f0");
  system("mode con cols=120 lines=30");

  _Console_Write_Repeatedly(0, "\n\n\n\n                               ------------------------------------------------------------\n",
    "                               |     **           **      ************       *******     |\n",
    "                               |    ***           ***     **               **       *    |\n");
  _Console_Write_Repeatedly(0, "                               |     ***         ***      **              **             |\n",
    "                               |      ***       ***     *********        **              |\n",
    "                               |       ***     ***        **             **              |\n");
  _Console_Write_Repeatedly(0, "                               |        ***   ***         **              **             |\n",
    "                               |         *** ***          **               **       *    |\n",
    "                               |           ***            *************      *******     |\n");
  _Console_Write_Repeatedly(0, "                               ------------------------------------------------------------\n", 0, 0);
  Sleep(2000);
}

