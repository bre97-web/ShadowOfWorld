#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

// MUSTER.h
void _Sleep_puts(int sleepTime, char call[]);
void Sleep_puts_(char call[], int sleepTime);
void _Repeatedly_puts_(int sleepTime, int frequency, char call[],char callAgain[], char callAgainAndAgain[]);
int _ASCII_num(int *asc);
int ASCII_num_(int *num);
int _ASCII_arr(char call);
int ASCII_arr_(char call);
int _Arr_add_arr(char toCall[], char call[], char result[]);
int Arr_add_arr_(char toCall[], char call[], char result[]);
void _Create_file_(char fileName[], char mode[]);
void _Create_file_puts_(char fileName[], char mode[], char message[]);
int _Read_file_live_(char fileName[]);
void _Cut_puts_(char call[], int start, int end, int endSure, char addCall[]);
void _Cut_puts_ASCII_(char call[], int start, int end, char addCall[]);
int _For_puts_(int startNum, int mode, int endObjective, int addStartNum,char call[]);
void _logEvent_(char log[], unsigned int mode);
void _Square_puts_(int padding, int width, int height, char message);
void _l_Puts_(char log[], unsigned mode);
void _Color_(unsigned short int x);
void _Loading_(void);

// EP0.c
void EP0_Start000(void);
void EP0_NorthLight011(void);

// TEXT_INFORMATION.c
void pulseOn(void);
void writer(void);

// main.c
void getMenu(void);
void getPassageMenu(void);
void getHelp(void);
void getWriter(void);

// USER_GROUP.c
void userAddrssProcess(char id[]);
void userAddressProcessDefend(char id[]);
void userLogin(void);
int userNameDefend(char id[]);
int userNameSakeDefend(char id[], char userId[]);
void sendValueToDataFile(char message[]);
void getProceed(void);

















#endif