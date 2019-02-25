#include<stdio.h>

struct Mahasiswa{
	char nim[10]; // 10
	char name[50]; // 50
	int age; // 4
	char gender; // 1
	double gpa; // 8
	// 10+50+4+8+1 = 73
};

// adt

int main(){
	struct Mahasiswa budi;
	Mahasiswa andi;
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(budi));
	return 0;
}
