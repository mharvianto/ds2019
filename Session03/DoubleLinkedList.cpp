#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
	// data
	int angka;
	// link
	struct Node *next, *prev;
} *head, *tail;

void push_d(int angka){
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->angka = angka;
	if(head == NULL) {
		head = tail = temp;
	} else {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	head->prev = tail->next = NULL;
}

void push_b(int angka){
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->angka = angka;
	if(head == NULL) {
		head = tail = temp;
	} else {
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	head->prev = tail->next = NULL;
}

void view(){
	struct Node *temp = head;
	while(temp != NULL){
		printf("%d, ", temp->angka);
		temp = temp->next;
	}
	printf("\n");
}

void pop_d(){
	if(head != 0){
		struct Node *temp;
		temp = head;
		if(head == tail) { // datanya cuma 1
			head = tail = 0;
		} else {
			head = head->next;
			head->prev = 0;
		}
		free(temp);
	}
}

void pop_b(){
	if(head != 0) {
		struct Node * temp;
		temp = tail;
		if(head == tail){
			head = tail = 0;
		} else {
			tail = tail->prev;
			tail->next = 0;
		}
		free(temp);
	}
}

void pop_all(){
	while(head != 0){
		pop_d();
	}
}

int main(){
	//srand(time(0));
	for(int i=0;i<10;i++){
		push_b(rand() % 100 + 1);
		// 0..30000 % 100 -> 0..99 + 1 -> 1..100
		printf("tail: %d\n", tail->angka);
	}
	view();
//	for(int i=0;i<15;i++){
//		if(tail != 0){
//			printf("tail: %d\n", tail->angka);
//		}
//		pop_b();
//	}
	pop_all();
	view();
	return 0;
}
