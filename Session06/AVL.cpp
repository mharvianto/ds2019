#include<stdio.h>
#include<stdlib.h>

struct Node{
	int angka;
	Node *left, *right, *parent;
} *root = 0;

int getHeight(Node *curr) {
	if(!curr) return 0;
	int leftHeight = getHeight(curr->left);
	int rightHeight = getHeight(curr->right);
	if(leftHeight > rightHeight){
		return leftHeight + 1;
	} else {
		return rightHeight + 1;
	}
}

void viewTree(Node *curr, int level) {
	if(curr){
		viewTree(curr->right, level+1);
		for(int i=0;i<level;i++)printf("\t");
		printf("%d\n", curr->angka);
		viewTree(curr->left, level+1);
	}
}

Node *leftRotate(Node *curr) {
	Node *pivot = curr->left;
	pivot->parent = curr->parent;
	curr->left = pivot->right;
	if(curr->left){
		curr->left->parent = curr;
	}	
	curr->parent = pivot;
	pivot->right = curr;
	return pivot;
}

Node *rightRotate(Node *curr) {
	Node *pivot = curr->right;
	pivot->parent = curr->parent;
	curr->right = pivot->left;
	if(curr->right){
		curr->right->parent = curr;
	}
	curr->parent = pivot;
	pivot->left = curr;
	return pivot;
}

void rebalance(Node *curr) {
	if(curr) {
		int leftHeight = getHeight(curr->left);
		int rightHeight = getHeight(curr->right);
		int diff = leftHeight - rightHeight;
		Node *parent = curr->parent;
		if(diff == 2 || diff == -2){
			viewTree(root, 0);
			printf("-------------------------------------\n");
			if(diff == 2) { // left
				int ll = getHeight(curr->left->left);
				int lr = getHeight(curr->left->right);
				if(lr > ll) {
					curr->left = rightRotate(curr->left);
					viewTree(root, 0);
					printf("-------------------------------------\n");
				}
				if(parent) {
					if(parent->left == curr) {
						parent->left = leftRotate(curr);
					} else {
						parent->right = leftRotate(curr);
					}
				} else {
					root = leftRotate(curr);
				}
			} else { // right
				int rr = getHeight(curr->right->right);
				int rl = getHeight(curr->right->left);
				if(rl > rr) {
					curr->right = leftRotate(curr->right);
					viewTree(root, 0);
					printf("-------------------------------------\n");
				}
				if(parent) {
					if(parent->left == curr) {
						parent->left = rightRotate(curr);
					} else {
						parent->right = rightRotate(curr);
					}
				} else {
					root = rightRotate(curr);
				}
			}
		}
		rebalance(parent);
	}
}

void push(Node **curr, Node *parent, int angka) {
	if(!(*curr)) {
		*curr = (Node*)malloc(sizeof(Node));
		(*curr)->angka = angka;
		(*curr)->left = (*curr)->right = 0;
		(*curr)->parent = parent;
		printf("Insert %d\n", angka);
		rebalance(parent);
	} else if(angka < (*curr)->angka) {
		push(&(*curr)->left, *curr, angka);
	} else if(angka > (*curr)->angka) {
		push(&(*curr)->right, *curr, angka);
	}
}

Node **getRightMost(Node **curr){
	if((*curr)->right){
		return getRightMost(&(*curr)->right);
	}else{
		return curr;
	}
}

void pop(Node **curr, int angka) {
	if(*curr){
		if(angka == (*curr)->angka) {
			if(!(*curr)->left && !(*curr)->right) {
				Node *parent = (*curr)->parent;
				free(*curr);
				*curr = 0;
				rebalance(parent);
			} else if((*curr)->left && (*curr)->right) {
				Node **temp = getRightMost(&(*curr)->left);
				(*curr)->angka = (*temp)->angka;
				pop(temp, (*temp)->angka);
			} else if((*curr)->left) {
				(*curr)->left->parent = (*curr)->parent;
				*curr = (*curr)->left;
				rebalance((*curr)->parent);	
			} else {
				(*curr)->right->parent = (*curr)->parent;
				*curr = (*curr)->right;
				rebalance((*curr)->parent);
			}
		} else if(angka < (*curr)->angka) {
			pop(&(*curr)->left, angka);
		} else {
			pop(&(*curr)->right, angka);
		}
	}
}

void inorder(Node *curr) {
	if(curr) {
		inorder(curr->left);
		printf("%d, ", curr->angka);
		inorder(curr->right);
	}
}

void popAll(Node **curr){
	if(*curr){
		popAll(&(*curr)->left);
		popAll(&(*curr)->right);
		free(*curr);
		*curr = 0;
	}
}

int main(){
	for(int i=0;i<20;i++){
		push(&root, 0, rand() % 100);
		viewTree(root, 0);
		printf("-------------------------------------\n");
	}
	pop(&root, 0);
	viewTree(root, 0);
	pop(&root, 5);
	viewTree(root, 0);
	pop(&root, 34);
	viewTree(root, 0);
	inorder(root);
	popAll(&root);
	return 0;
}
