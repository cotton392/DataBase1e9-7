#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void UserRegister(){
  char name[100],username[100];
  FILE *fp;

  printf("登録したいユーザー名を入力してください >> ");
  scanf("%s", name);

  //重複チェック
  fp = fopen("UserList", "r");
  if(fp == NULL){
    printf("UserListがありません。\n");
    exit(1);
  }
  while(fscanf(fp, "%s", username)>0){
    if(strcmp(name, username) == 0){
      printf("このユーザー名は既に使用されています。\n");
      return ;
    }
  }
  fclose(fp);

  //登録(UserListに書き込む)
  fp = fopen("UserList", "a");
  if(fprintf(fp, "%s", name) == 0){
    //エラー処理
    printf("登録に失敗しました。\n");
  }
  fclose(fp);

  return ;
}

int UserCheck(){
  char name[100],username[100];
  FILE *fp;
  printf("ユーザー名を入力してください >> ");
  scanf("%s", name);

  fp = fopen("UserList", "r");
  if(fp == NULL){
    printf("UserListがありません。\n");    
    exit(1);
  }
  while(fscanf(fp, "%s", username)>0){
    if(strcmp(name, username) == 0){
      return 1;
    }
  }
  fclose(fp);
  return 0;
}

void UserDelete(){
  char name[100];
  printf("消去したいユーザー名を入力してください >> ");
  scanf("%s", name);
  /*
  ユーザー名探索 -> 消去
  */
  return ;
}

