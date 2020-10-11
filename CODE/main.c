#include <stdlib.h>
#include <string.h>

#include "muster.h"
#include "statement.h"

//  Use Google-Code-Style
//  Use UTF-8 coding.

int main(void) {
  system("mode con cols=105 lines=30");
  system("color 70");

  _logEvent_(".exe start core...");

  writer();
  pulseOn();
  addUserData();
  getMenu();

  _logEvent_(".exe return 0...");

  //	puts("\n By:Bre97 \n");
  /*
   *  cout<<"aYOaYO\n";
   *  cout<<"Fly your Lonely!\n";
   */
  return 0;
}

void getMenu(void) {
s:;

  char gamePassage[32] = "-gamePassage";
  char gameStart[32] = "-gameStart";
  char gameProceed[32] = "-gameProceed";
  char gameHelp[32] = "-gameHelp";
  char gameWriter[32] = "-gameWriter";
  char gameSetting[32] = "-gameSetting";
  char strTemp[32];

  gameCenterGra();

  gets_s(strTemp, 32);

  plotInitial(0, 0, 0, 0);
  _logEvent_("function.getMenu() : user put strTemp");

  //  game menu
  if (strcmp(strTemp, gamePassage) == 0) {
    getPassageMenu();
  }
  //  in gameCore.c File
  else if (strcmp(strTemp, gameStart) == 0) {
    EP0_friend011();
  } else if (strcmp(strTemp, gameHelp) == 0) {
    getHelp();
    goto s;
  } else if (strcmp(strTemp, gameProceed) == 0) {
    getProceed();
  } else if (strcmp(strTemp, gameWriter) == 0) {
    getWriter();
    goto s;
  } else if (strcmp(strTemp, gameSetting) == 0) {
    getCharacter();
    goto s;
  } else {
    goto s;
  }
}

void getPassageMenu(void) {
  char EP0_01[32] = "PLAYER_PASSAGE_ONE";
  char EP0_02[32] = "PLAYER_PASSAGE_TWO";
  char strTemp[32];

  system("cls");

  _Repeatedly_puts_(0, 1, "GIVE_PLAYER_PASSAGE: DISPLAY\n",
                    "No.1:Friend[EP0_01]",
                    "----------PLAYER_PASSAGE_ONE\n");
  _Repeatedly_puts_(0, 1, "No.2:[EP0_02]",
                    "----------PLAYER_PASSAGE_TWO\n",
                    "No.3:");

  gets_s(strTemp, 32);

  _logEvent_("function.getPassageMenu() : user put strTemp");

  if (strcmp(strTemp, EP0_01) == 0) {
    EP0_friend011();
  } else if (strcmp(strTemp, EP0_02) == 0) {
  }
}