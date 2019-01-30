#ifndef HEADER_H
#define HEADER_H

//UserUtilに実装する関数
void UserRegister();
int UserCheckFlager(int* CheckFlag);
void UserDelete();

//DatabaseUtilに実装する関数
void WordRegister();
void WordSearch();
void WordDelete();


#endif