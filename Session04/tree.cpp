#include<stdlib.h>
#include<stdio.h>

struct Node{
	//data
	int angka;
	//link
	struct Node *left, *right;
} *root;

void push(struct Node **curr, int angka){
	if(*curr == 0) {
		*curr = (struct Node*)malloc(sizeof(struct Node));
		(*curr)->angka = angka;
		(*curr)->left = (*curr)->right = 0;
	}else{
		int input = 0;
		printf("Curr: %d\n"
			"Angka: %d\n"
			"1. left\n"
			"2. Right\n"
			"Input: ", (*curr)->angka, angka);
		scanf("%d", &input);
		if(input == 1){
			push(&(*curr)->left, angka);
		}else{
			push(&(*curr)->right, angka);
		}
	}
}

void view(struct Node **curr, int level){
	if(*curr != 0){// l m r
		view(&(*curr)->left, level+1);
		for(int i=0;i<level;i++){
			printf("\t");
		}
		printf("%d\n", (*curr)->angka);
		view(&(*curr)->right, level+1);
	}
}

void pre_view(struct Node **curr){
	if(*curr != 0){// m l r
		printf("%d, ", (*curr)->angka);
		pre_view(&(*curr)->left);
		pre_view(&(*curr)->right);
	}
}

void post_view(struct Node **curr){
	if(*curr != 0){// l r m
		post_view(&(*curr)->left);
		post_view(&(*curr)->right);
		printf("%d, ", (*curr)->angka);
	}
}

int main(){
	push(&root, 5);
	push(&root, 7);
	push(&root, 4);
	push(&root, 3);
	push(&root, 8);
	view(&root, 0);
	printf("\n");
	pre_view(&root);
	printf("\n");
	post_view(&root);
	printf("\n");
	return 0;
}

