#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// stdlib -> malloc

struct Node{
	// data
	char nama[50];
	int umur;
	// link
	struct Node* next;
} *head, *tail;

void push_b(char t_nama[], int t_umur){ // belakang / back
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	strcpy(temp->nama, t_nama);
	temp->umur = t_umur;
	if(head == NULL){// data belum ada sama sekali
		head = temp;
		tail = temp;
		// head = tail = temp;
	}else{// sudah ada data pada linked list
		tail->next = temp;
		tail = temp;
		// tail = tail->next = temp;
	}
	tail->next = NULL;
}

void push_d(char t_nama[], int t_umur){ // depan / front
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	strcpy(temp->nama, t_nama);
	temp->umur = t_umur;
	if(head == NULL){// data belum ada sama sekali
		head = temp;
		tail = temp;
		// head = tail = temp;
	}else{// sudah ada data pada linked list
		temp->next = head;
		head = temp;
	}
	tail->next = NULL;
}

void view(){
	struct Node *temp;
	temp = head; // pindahkan temp ke head
	printf("%20s | %s\n", "Nama", "Umur");
	while(temp != NULL){
		printf("%20s | %4d\n", temp->nama, temp->umur);
		temp = temp->next; // tunjuk ke data berikutnya
	}
	printf("\n");
}

void pop_d(){ // front / depan
	if(head != NULL){ // ada data
		struct Node *temp;
		temp = head; // temp tunjuk ke head
		head = head->next; // head tunjuk ke data berikutnya
		free(temp); // melepaskan memori
	}
}

int main(){
	push_b("Kevin", 18);
	push_b("Gideon", 19);
	push_b("Jojo", 17);
	view();
	pop_d(); // hapus kevin
	push_d("Butet", 20);
	view();
	return 0;
}





