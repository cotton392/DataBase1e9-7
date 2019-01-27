#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

void Menu(void){
	printf("DataBase1e9-7へようこそ!\n");
	printf("\n");
	printf("1.単語登録(R)\n");
	printf("2.単語検索(S)\n");
	printf("3.ユーザー削除(D)\n");
	printf("4.終了(Q)\n");
	printf(">>");
}

void UserRegisterQuestion(void){
	printf("ログイン情報を入力します。\n");
	printf("ユーザー登録を済ませている人はY,そうでない方はNを入力してください。\n");
	printf(">>");
}

void main(void){
	char menu_str[10];
	char UserRegisterCheck[10];

	UserRegisterQuestion();
	scanf("%s", UserRegisterCheck);
	if(UserRegisterCheck[0]=='Y'){
		while(UserCheck()==1){
			UserCheck();
		}
	}
	else if(UserRegisterCheck[0]=='N'){
		UserRegister();
	}
	else{
		printf("YかNで入力してください。\n");
		exit(1);
	}

	while(1){
		menu();
		scanf("%s", menu_str);
		switch(toupper(menu_str[0]){
			case 'R': WordRegister(); break;
			case 'S': WordSearch(); break;
			case 'D': UserDelete(); break;
			case 'Q': exit(1);
			default: printf("コマンドが間違っています。\n");
		}

	}


	return 0;
}