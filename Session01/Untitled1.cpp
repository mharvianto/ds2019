#include<stdio.h>
// passing by reference
void bacaInput(int *input){
	scanf("%d", input);
}

// passing by value
void print(int a){
	a = 4;
	printf("%d\n", a);
}

int main(){
	int angka = 10;
	int *p;
	p = &angka;
	printf("%d\n", angka);
	printf("%d\n", &angka);
	printf("%d\n", *p);
	printf("%d\n", p);
	printf("%d\n", &p);
	angka = 11;
	printf("%d\n", *p);
	*p = 13;
	printf("%d\n", angka);
	bacaInput(&angka);
	printf("%d\n", angka);
	print(angka); // 4
	printf("%d\n", angka); // 13
	return 0;
}






