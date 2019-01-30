#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../header.h"

//単語検索
void WordSearch() {
	FILE *fp;
	int index=0;
	char word[100], search[100];
	scanf("%s", search);
	fp = fopen("DataBaseFile", "r");
	if (fp == NULL) {
		printf("開けなかった\n");
		exit(1);
	}
	while (1) {
		if (fscanf(fp, "%s", word) == EOF) {
			printf("ありませんでした\n");
			break;
		}
		if (strcmp(word, search) == 0 && index%3==0) {
			char mean[100];
			fscanf(fp, "%s", mean);
			fscanf(fp, "%s", search);
			printf("単語: %s , 意味: %s ,ユーザー: %s\n" ,word,mean,search);
			break;
		}
		index++;
	}
	fclose(fp);
	return;
}

//単語登録
void WordRegister() {
	int check = 0;//既に登録されていれば1になる
	int index=0;
	FILE *fp;
	char word[100], search[100],user[100],mean[100];
	printf("user: ");
	scanf("%s",user);
	printf("意味: ");
	scanf("%s",mean);
	printf("単語: ");
	scanf("%s", search);
	fp = fopen("DataBaseFile", "r");
	if (fp == NULL) {
		printf("DataBaseFileが存在しません。\n");
		exit(1);
	}
	
	while (1) {
		if (fscanf(fp, "%s", word) == EOF) {
			break;
		}
		if (strcmp(word, search) == 0 && index%3==0) {
			check++;
			break;
		}
		index++;
	}
	fclose(fp);
	//↑単語検索

	fp = fopen("DataBaseFile", "a");
	if (fp == NULL) {
		printf("DataBaseFileが存在しません。\n");
		exit(1);
	}
	if (check == 1) {
		printf("%sは既に登録されています。\n",search);
		exit(1);
	}
	fprintf(fp,"%s %s %s",search,mean,user);
	printf("%sが登録されました。\n", search);
	fclose(fp);
	return ;
}

//単語削除
void WordDelete() {
	int check = 0;//単語があれば1
	char word1[100],word2[100],word3[100], search[100],user[100],mean[100];
	FILE *fp, *tmp;

	printf("消去したい単語を入力してください >> ");
	scanf("%s", search);
	printf("意味を入力してください >> ");
	scanf("%s",mean);
	printf("ユーザー名を入力してください >> ");
	scanf("%s",user);
	
	fp = fopen("DataBaseFile", "r");
	if (fp == NULL) {
		printf("開けなかった\n");
		exit(1);
	}

	//コピーのファイルを作る
	tmp = fopen("CopyFile", "w");
	while (fscanf(fp, "%s", word1) != EOF) {
		fscanf(fp,"%s",word2);
		fscanf(fp,"%s",word3);
		if (strcmp(word1, search) != 0) {
			 fprintf(tmp, "%s\n", word1);
			 fprintf(tmp, "%s\n", word2);
			 fprintf(tmp, "%s\n", word3);
		         check++;
		}
	}
	fclose(fp);
	fclose(tmp);
	if (check == 0) {
		printf("%sは登録されていません.\n", search);
		return ;
	}

	fp = fopen("DataBaseFile", "w");
	tmp = fopen("CopyFile", "r");
	
	while (fscanf(tmp, "%s", word) != EOF) {
		fprintf(fp, "%s\n", word);
	}
	fclose(fp);
	fclose(tmp);
	printf("%sを消去しました。\n", search);
	return ;
}


