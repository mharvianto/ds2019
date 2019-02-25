#include<stdio.h>
#include<stdlib.h>

int main(){
	int arr[10];
	arr[0] = 10;
	int *petunjuk = &arr[0];
	printf("%d\n", arr[0]);
	printf("%d\n", arr);
	printf("%d\n", &arr[0]);
	printf("%d\n", &arr[1]);
	*petunjuk = 8;
	printf("%d\n", arr[0]);
	int *parr;
	//type cast / convert type
	parr = (int*)malloc(4*5);
	parr[0] = 10;
	parr[1] = 5;
	printf("%d\n", parr[0]);
	printf("%d\n", parr[1]);
	printf("%d\n", parr);
	realloc(parr, 4*100);
	parr[50] = 45;
	printf("%d\n", parr);
	printf("%d\n", parr[50]);
	printf("%d\n", parr[0]);
	return 0;
}








