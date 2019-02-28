#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	// data
	int angka;
	// link
	struct Node *next;
};
struct Node *head = NULL, *tail;
void push_b(int angka){
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->angka = angka;
	if(head == NULL){ // head tidak ada/data masih kosong
		head = tail = temp;
	}else{
		tail->next = temp;
		tail = tail->next;// tail = temp
	}
	tail->next = NULL;
}

void view(){
	struct Node *temp = head;
	while(temp != NULL){
		printf("%d\n", temp->angka);
		temp = temp->next;
	}
}

void pop_d(){
	if(head != NULL){
		struct Node *temp = head;
		head = head->next;
		free(temp);
	}
}


int main(){
	// create node
//	head = (struct Node*)malloc(sizeof(struct Node));
//	(*head).angka = 10;
//	printf("%d\n", (*head).angka);
//	printf("%d\n", head->angka);
//	head->angka = 15;
//	tail = head;
//	printf("%d\n", head->angka);
//	tail->next = (struct Node*)malloc(sizeof(struct Node));
//	tail->next->angka = 7;
//	tail = tail->next;
//	printf("%d\n", head->next->angka);
//	tail->next = (struct Node*)malloc(sizeof(struct Node));
//	tail->next->angka = 10;
//	tail = tail->next;
//	printf("%d\n", head->next->next->angka);
	push_b(15);
	push_b(7);
	push_b(10);
	push_b(17);
	view();
	pop_d();
	view();
	for(int i=0;i<1000000000;i++){
		push_b(rand()%1000);
	}
	//view();
	printf("%d\n", tail->angka);
	return 0;
}







