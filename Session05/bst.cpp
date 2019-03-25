#include<stdio.h>
#include<stdlib.h>

struct Node{
	int angka;
	Node *left, *right;
} *root;

void push(Node **curr, int angka){
	if(*curr == 0){ // !(*curr)
		(*curr) = (Node*)malloc(sizeof(Node));
		(*curr)->angka = angka;
		(*curr)->left = (*curr)->right = 0;
	} else {
		if(angka < (*curr)->angka){
			push(&(*curr)->left, angka);
		} else if(angka > (*curr)->angka){
			push(&(*curr)->right, angka);
		}
	}
}

void inOrder(Node *curr){// left middle right
	if(curr){ // curr != 0
		inOrder(curr->left); 			// left
		printf("%d, ", curr->angka); 	// middle
		inOrder(curr->right); 			// right
	}
}

void viewTree(Node *curr, int lvl){
	if(curr){
		viewTree(curr->right, lvl+1);
		for(int i=0;i<lvl;i++)printf("  ");
		printf("%d\n", curr->angka);
		viewTree(curr->left, lvl+1);
	}
//	else
//	{
//		for(int i=0;i<lvl;i++)printf("  ");
//		printf("NULL\n");
//	}
}

void preOrder(Node *curr){ // middle left right
	if(curr){ // curr != 0
		printf("%d, ", curr->angka); 	// middle
		preOrder(curr->left); 			// left
		preOrder(curr->right); 			// right
	}
}

void postOrder(Node *curr){// left right middle
	if(curr){ // curr != 0
		postOrder(curr->left); 			// left
		postOrder(curr->right); 		// right
		printf("%d, ", curr->angka); 	// middle
	}
}

void popAll(Node **curr){
	if(*curr){
		popAll(&(*curr)->left); 	// left
		popAll(&(*curr)->right); 	// right
		free(*curr); 				// middle
		*curr = 0;
	}
}

Node *search(Node *curr, int angka){
	if(curr){
		if(curr->angka == angka){
			return curr;
		}else if(angka < curr->angka){
			return search(curr->left, angka);
		}else{
			return search(curr->right, angka);
		}
	}else return 0;
}

void pop(Node **curr, int angka){
	if(*curr){
		if(angka == (*curr)->angka) {
			if((*curr)->left == 0 && (*curr)->right == 0){
				free(*curr);
				*curr = 0;
			}
		} else if(angka < (*curr)->angka) {
			pop(&(*curr)->left, angka);
		} else {
			pop(&(*curr)->right, angka);
		}
	}
}

int main(){
	push(&root, 50);
	push(&root, 45);
	push(&root, 75);
	push(&root, 60);
	push(&root, 30);
	push(&root, 47);
	inOrder(root); printf("\n");
	preOrder(root); printf("\n");
	postOrder(root); printf("\n");
	viewTree(root, 0);
	int input;
	scanf("%d", &input);
	if(search(root, input)){
		printf("Ketemu\n");
	} else {
		printf("Tidak ketemu\n");
	}
	pop(&root, input);
	viewTree(root, 0);
	popAll(&root);
	return 0;
}




