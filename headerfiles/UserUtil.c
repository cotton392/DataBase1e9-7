#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void UserRegister(){
  char name[100],username[100];
  FILE *fp;

  printf("登録したいユーザー名を入力してください >> ");
  scanf("%s", name);

  fp = fopen("UserList", "r");
  if(fp == NULL){
    printf("UserListがありません。\n\n");
    exit(1);
  }
  //重複チェック
  while(fscanf(fp, "%s", username) != EOF){
    if(strcmp(name, username) == 0){
      printf("このユーザー名は既に使用されています。\n\n");
      return ;
    }
  }
  fclose(fp);

  //登録(UserListに書き込む)
  fp = fopen("UserList", "a");
  if(fprintf(fp, "%s\n", name) == 0){
    //エラー処理
    printf("登録に失敗しました。\n\n");
  }
  printf("ユーザー名:%sが登録されました。\n\n", name);
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
    printf("UserListがありません。\n\n");
    exit(1);
  }
  while(fscanf(fp, "%s", username) != EOF){
    if(strcmp(name, username) == 0){
      return 1;
    }
  }
  fclose(fp);
  return 0;
}

void UserDelete(){
  int judge=0;
  char name[100],username[100];
  FILE *fp, *tmp;

  printf("消去したいユーザー名を入力してください >> ");
  scanf("%s", name);
  
  fp = fopen("UserList", "r");
  if(fp == NULL){
    printf("UserListがありません。\n\n");
    exit(1);
  }

  //消去する名前以外をTemporaryに移す
  tmp = fopen("Temporary", "w");
  while(fscanf(fp, "%s", username) != EOF){
    if(strcmp(name, username) != 0){
      fprintf(tmp, "%s\n", username);
      judge++;
    }
  }
  fclose(fp);
  fclose(tmp);
  if(judge==0){
    printf("ユーザー名:%sは登録されていません。\n\n", name);
    return ;
  }

  fp = fopen("UserList", "w");
  tmp = fopen("Temporary", "r");
  //UserListの更新
  while(fscanf(tmp, "%s", username) != EOF){
    fprintf(fp, "%s\n", username);
  }
  fclose(fp);
  fclose(tmp);
  printf("ユーザー名:%sを消去しました。\n\n", name);
  return ;
}
