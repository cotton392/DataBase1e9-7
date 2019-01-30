#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//単語検索
void WordSearch() {
	FILE *fp;
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
		if (strcmp(word, search) == 0) {
			printf("%sを発見しました\n",word);
			break;
		}
	}
	fclose(fp);
	return;
}

//単語登録
void WordRegister() {
	int check = 0;//既に登録されていれば1になる
	FILE *fp;
	char word[100], search[100];
	scanf("%s", search);
	fp = fopen("DataBaseFile", "r");
	if (fp == NULL) {
		printf("開けませんでした\n");
		exit(1);
	}
	
	while (1) {
		if (fscanf(fp, "%s", word) == EOF) {
			break;
		}
		if (strcmp(word, search) == 0) {
			check++;
			break;
		}
	}
	fclose(fp);
	//↑単語検索

	FILE *fp;
	char word[100];
	fp = fopen("DataBaseFile", "a");
	if (fp == NULL) {
		printf("開けませんでした\n");
		exit(1);
	}
	if (check == 1) {
		printf("%sは既に登録されています\n",word);
		exit(1);
	}
	if (fprintf(fp, "%s\n", word) == 0) {
		printf("失敗\n");
	}
	printf("%sが登録されました.\n", word);
	fclose(fp);
	return ;
}

//単語削除
void WordDelete() {
	int check = 0;//単語があれば1
	char word[100], search[100];
	FILE *fp, *tmp;

	printf("消去したい言葉を入力してください >> ");
	scanf("%s", search);

	fp = fopen("DataBaseFile", "r");
	if (fp == NULL) {
		printf("開けなかった\n");
		exit(1);
	}

	//コピーのファイルを作る
	tmp = fopen("CopyFile", "w");
	while (fscanf(fp, "%s", word) != EOF) {
		if (strcmp(word, search) != 0) {
			fprintf(tmp, "%s\n", word);
			check++;
		}
	}
	fclose(fp);
	fclose(tmp);
	if (check == 0) {
		printf("%sは登録されていません.\n\n", word);
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


