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

void push_t_index(int index, char t_nama[], int t_umur){// tengah / middle by index
	if(index == 0){
		push_d(t_nama, t_umur);
	}else{
		struct Node *temp;
		temp = head;
		for(int i=0;i<index-1;i++){
			if(temp != NULL){
				temp = temp->next;
			}
		}
		if(temp == NULL || temp == tail){
			push_b(t_nama, t_umur);
		}else{
			struct Node *new_node;
			new_node = (struct Node*)malloc(sizeof(struct Node));
			strcpy(new_node->nama, t_nama);
			new_node->umur = t_umur;
			// ubah linknya
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}
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

void pop_all(){ // hapus semua data
	while(head != NULL){
		pop_d();
	}
}

void pop_b(){ // hapus belakang / back
	if(head != NULL){ // ada data
		if(head == tail){ // cuma 1 data
			free(head);
			head = NULL;
			tail = NULL;
		}else{ // lebih dari 1 data
			struct Node *temp;
			temp = head;
			while(temp->next != tail){ 
				temp = temp->next;
			}
			// logika 1 (swap tail dan temp)
			tail = temp; // tail tunjuk temp
			temp = temp->next; // temp tunjuk ke berikutnya
			free(temp); // melepaskan memori
			tail->next = NULL; // set tail ke next jadi null
			// logika 2 (langsung hapus tail)
			// free(tail);
			// tail = temp;
			// tail->next = NULL;
		}
	}
}

void pop_t_index(int index){ // hapus tengah/middle by index
	if(index == 0){
		pop_d();
	}else{
		struct Node *temp;
		temp = head;
		for(int i=0;i<index-1;i++){
			if(temp != NULL){
				temp = temp->next;
			}
		}
		if(temp == NULL || temp == tail){
			
		}else if(temp->next == tail){
			pop_b();
		}else{
			struct Node *del;
			del = temp->next;
			temp->next = del->next;
			free(del);
		}
	}
}

int main(){
	push_b("Kevin", 18);
	push_b("Gideon", 19);
	push_b("Jojo", 17);
	view();
	pop_d(); // hapus kevin
	push_d("Butet", 20);
	push_t_index(3, "Lili", 21);
	pop_t_index(1);
	view();
	pop_b(); // hapus jojo
	view();
	pop_all();
	view();
	return 0;
}





