#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void WordSearch(){
	FILE *fp;
	char hoge[10];
	fp=fopen("hoge.txt","r");
	if(fp==NULL){
		printf("hoge");
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
	return 0;
}

void WordRegister(){
	
}
void WordDelete();.


