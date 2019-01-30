#ifndef HEADER_H
#define HEADER_H

//UserUtilに実装する関数
void UserRegister();
int  UserCheck(int* CheckFlag);
void UserDelete();

//DatabaseUtilに実装する関数
int  WordRegister();
int WordSearch();
int WordDelete();


#endif