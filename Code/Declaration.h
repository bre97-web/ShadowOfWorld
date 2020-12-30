#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

// Other.Platform.vec.NonGraphic.h
void _Console_Write_WriteSleep(int sleepTime, char message[]);
void _Console_Write_Repeatedly(int sleepTime, char message[], char messageTwo[], char messageThree[]);
void _Console_Write_CutToEnd(char message[], int startDelay, int endDelay, int whetherToEnd);
void _Console_Write_CutToEndWithAscii(char message[], int startDelay, int endDelay);
void _Console_Write_Frame(char log[], unsigned int short mode, unsigned int short endFrame);
void _Console_Write_LoadingAnimation(void);
void _Console_Write_LoadingAnimationSec(void);

int _Data_Convert_AsciiToNum(int ascii);
char *_Data_Convert_ArrayLinkBoth(char object[], char message[], char result[]);

int _IO_File_Create(char fileNameAddress[], char mode[]);
int _IO_File_Write(char fileNameAddress[], char mode[], char message[]);
int _IO_File_Read_State(char fileNameAddress[]);
int _IO_File_Log(char log[], unsigned int mode);
int _IO_Folder_Create(char folderNameAddress[]);

// Ep0.c
void EP0_Start000(void);
void EP0_NorthLight011(void);

// TextInformation.c
void pulseOn(void);

// Main.c
int list(int num, int mode);
int getMenu(int num);
int getGamePassage(int num);
void getHelp(void);

// UserGroup.c
void userAddrssProcess(char id[]);
int userAddressProcessDefend(char id[]);
int userLogin(void);
int userNameDefend(char id[]);
int userNameSakeDefend(char id[], char userId[]);
void sendValueToDataFile(char message[]);
int getProceed(void);

















#endif