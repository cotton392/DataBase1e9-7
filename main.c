#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"

void Menu(void){
	printf("DataBase1e9-7へようこそ!\n");
	printf("\n");
	printf("1.単語登録(R)\n");
	printf("2.単語検索(S)\n");
	printf("3.単語削除(W)\n");
	printf("4.ユーザー削除(D)\n");
	printf("5.終了(Q)\n");
	printf(">>");
} //メニュー表示関数

void UserRegisterQuestion(void){
	printf("ログイン情報を入力します。\n");
	printf("ユーザー登録を完了している場合はY,そうでない方はNを入力してください。\n");
	printf(">>");
} //登録済みかの確認関数

int main(void){
	char menu_str[10]; //menuの選択入力用文字列
	char UserRegisterCheck[10]; //初回登録かどうかの確認用文字列
	int UserAuthFlag = 0; //ユーザーログイン確認用変数

	UserRegisterQuestion();
	scanf("%s", UserRegisterCheck);
	if(toupper(UserRegisterCheck[0])=='Y'){
		while(UserAuthFlag == 1){
			UserCheckFlager(&UserAuthFlag);
		} //ログイン成功までログイン試行
	}
	else if(toupper(UserRegisterCheck[0])=='N'){
		UserRegister(); //未登録の場合の登録処理
	}
	else{
		printf("YかNで入力してください。\n");
		exit(1);
	}

	while(1){
		Menu();
		scanf("%s", menu_str);
		switch(toupper(menu_str[0])){
			case 'R': WordRegister(); break;                //単語登録
			case 'S': WordSearch(); break;                  //単語検索
			case 'W': WordDelete(); break;                  //単語削除
			case 'D': UserDelete(); break;                  //ユーザー削除
			case 'Q': exit(1);                              //プログラム終了
			default: printf("コマンドが間違っています。\n");
		}

	}


	return 0;
}