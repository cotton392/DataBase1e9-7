#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void WordSearch(){
	FILE *fp;
	char hoge[10];
	fp=fopen("hoge.txt","r");
	if(fp==NULL){
		printf("hoge\n");
		exit(1);
	}
	while(1){
		fscanf(fp,"hoge = %s",hoge);
		if()
		if(feof(fp) != 0){
			break;
		}
		if()
	}
	fclose(fp);
	printf("%s\n", hoge);
}

void WordRegister(){
	FILE *fp;
	char hoge[10];
	fp=fopen("hoge.txt","a+");
	if(fp==NULL){
		printf("hoge\n");
		exit(1);
	}
	while(1)
}
void WordDelete();.


