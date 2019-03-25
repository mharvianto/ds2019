#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

char table[N][20];

int hash(char kata[]){
	int total = 0;
	int l = strlen(kata);
	for(int i=0;i<l;i++){
		total += kata[i];
	}
	return total % N;
}

void linearProbing(char kata[]){
	int key = hash(kata);
	while(strcmp(table[key], "") != 0){
		key++;
		key %= N;
		printf("%s %d %s next\n", table[key-1], key-1, kata);
	}
	strcpy(table[key], kata);
}

void clearTable(){
	for(int i=0;i<N;i++){
		strcpy(table[i], "");
	}
}

int main(){
	linearProbing("kevin");
	linearProbing("udin");
	linearProbing("andi");
	linearProbing("dian");
	linearProbing("jojo");
	linearProbing("bibi");
	linearProbing("lili");
	linearProbing("budi");
	linearProbing("william");
	linearProbing("didi");
	
	for(int i=0;i<N;i++) {
		printf("%d %s\n", i, table[i]);
	}
	
	return 0;
}
