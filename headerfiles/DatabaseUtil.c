#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void WordSearch() {
	FILE *fp;
	char word[100], search[100];
	scanf("%s", search);
	fp = fopen("hoge.txt", "r");
	if (fp == NULL) {
		printf("ないよぉ～～\n");
		exit(1);
	}
	//あるかな？
	while (1) {
		if (fscanf(fp, "%s", word) == EOF) {
			printf("ないよぉ～～\n");
			break;
		}
		if (strcmp(word, search) == 0) {
			printf("あったよ\n");
			break;
		}
	}
	fclose(fp);
	return;
}

void WordRegister() {
	int check = 0;
	FILE *fp;
	char word[100], search[100];
	scanf("%s", search);
	fp = fopen("hoge.txt", "r");
	if (fp == NULL) {
		printf("ないよぉ～～\n");
		exit(1);
	}
	//あるかな？
	while (1) {
		if (fscanf(fp, "%s", word) == EOF) {
			printf("ないよぉ～～\n");
			break;
		}
		if (strcmp(word, search) == 0) {
			printf("あったよ\n");
			check++;
			break;
		}
	}
	fclose(fp);


	FILE *fp;
	char word[100];
	fp = fopen("hoge.txt", "a");
	if (fp == NULL) {
		printf("ないよぉ～～\n");
		exit(1);
	}
	if (check == 1) {
		printf("既に存在\n");
		exit(1);
	}
	if (fprintf(fp, "%s\n", word) == 0) {
		printf("しっぱ～い。もう少し頑張るドン!!\n");
	}
	printf("%sが登録されました.\n", word);
	fclose(fp);
	return ;
}

void WordDelete() {
	int check = 0;
	char word[100], search[100];
	FILE *fp, *tmp;

	printf("消去したい言葉を入力してください >> ");
	scanf("%s", search);

	fp = fopen("hoge.txt", "r");
	if (fp == NULL) {
		printf("開けない\n");
		exit(1);
	}

	tmp = fopen("copyhoge", "w");
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

	fp = fopen("hoge", "w");
	tmp = fopen("copyhoge", "r");
	
	while (fscanf(tmp, "%s", word) != EOF) {
		fprintf(fp, "%s\n", word);
	}
	fclose(fp);
	fclose(tmp);
	printf("%sを消去しました。\n", search);
	return ;
}


