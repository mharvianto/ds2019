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

Node **getLargest(Node **curr){
	if(*curr){
		if((*curr)->right == 0) {
			return curr;
		} else {
			return getLargest(&(*curr)->right);
		}
	} else return 0;
}

void pop(Node **curr, int angka){
	if(*curr){
		if(angka == (*curr)->angka) {
			if((*curr)->left == 0 && (*curr)->right == 0){
				free(*curr);
				*curr = 0;
			} else if((*curr)->left && (*curr)->right) {
				Node **temp = getLargest(&(*curr)->left);
				(*curr)->angka = (*temp)->angka;
				pop(temp, (*temp)->angka);
			} else if((*curr)->right){
				Node *temp = *curr;
				*curr = (*curr)->right;
				free(temp);
			} else {
				Node *temp = *curr;
				*curr = (*curr)->left;
				free(temp);
			}
		} else if(angka < (*curr)->angka) {
			pop(&(*curr)->left, angka);
		} else {
			pop(&(*curr)->right, angka);
		}
	}
}

int main(){
	int input = 0, angka;
	do{
		viewTree(root, 0);
		printf( "Menu\n"
				"1. push\n"
				"2. inOrder\n"
				"3. preOrder\n"
				"4. postOrder\n"
				"5. search\n"
				"6. pop\n"
				"7. exit\n"
				"Input: ");
		scanf("%d", &input);
		switch(input){
			case 1:	
				printf("Input number: ");
				scanf("%d", &angka);
				push(&root, angka);
				break;
			case 2:
				inOrder(root); printf("\n"); break;
			case 3:
				preOrder(root); puts(""); break;
			case 4:
				postOrder(root); puts(""); break;
			case 5:
				printf("Input number: ");
				scanf("%d", &angka);
				if(search(root, angka)){
					printf("Found\n");
				}else{
					printf("Not found\n");
				}
				break;
			case 6:
				printf("Input number: ");
				scanf("%d", &angka);
				pop(&root, angka);
				break;
			case 7:
				printf("Thanks for using app\n"); break;
			default:
				printf("Wrong input\n"); break;
		}
	}while(input != 7);
	popAll(&root);
//	push(&root, 50);
//	push(&root, 45);
//	push(&root, 75);
//	push(&root, 60);
//	push(&root, 30);
//	push(&root, 47);
//	push(&root, 65);
//	push(&root, 61);
//	push(&root, 68);
//	inOrder(root); printf("\n");
//	preOrder(root); printf("\n");
//	postOrder(root); printf("\n");
//	viewTree(root, 0);
//	int input;
//	scanf("%d", &input);
//	if(search(root, input)){
//		printf("Ketemu\n");
//	} else {
//		printf("Tidak ketemu\n");
//	}
//	pop(&root, input);
//	viewTree(root, 0);
//	popAll(&root);
	return 0;
}




