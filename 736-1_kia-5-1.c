#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int key;
	int value;
	struct node *left;
	struct node *right;
} node;

typedef node *tree;

int init(tree *root) {
	*root=NULL;
	return 0;
}

_Bool isEmpty(tree root) {
	if(root==NULL) return 1;
	return 0;
}

int add(tree *root, int key, int value) {
	tree p=*root;
	if(*root != NULL) {
		while(*root != NULL ) {
			if(key > (*root)->key) {
				if((*root)->right == NULL) {
					(*root)->right=malloc(sizeof(node));
					*root=(*root)->right;
					break;
				}
				*root=(*root)->right;
			}
			else 
				if(key < (*root)->key) {
					if((*root)->left == NULL) {
						(*root)->left=malloc(sizeof(node));
						*root=(*root)->left;
						break;
					}
					*root=(*root)->left;
				}
				else {
					(*root)->value=value;
					return 0;
				}
		}	
	}
	else {*root=malloc(sizeof(node)); p=*root;}
	(*root)->left=NULL;
	(*root)->right=NULL;
	(*root)->key=key;
	(*root)->value=value;
	*root=p;
	return 0;
}

int found(tree root, int key) {
	tree p=root; int lvl=0;
	if(!isEmpty(root)) {
		while(p->key != key) {
			if (p->key > key) p=p->left;
			else if(p->key != key) p=p->right;
			lvl++;
			if (p == NULL) return -1;
		}
		printf("%d ", lvl);
		return p->value;
	}
	return -1;
}

int destroy(tree *root) {
	if((*root)->left != NULL) destroy(&((*root)->left));
	if((*root)->right != NULL) destroy(&((*root)->right));
	if(((*root)->left == NULL)&&((*root)->right == NULL)) {
		free(*root);
		*root=NULL;
		return 0;
	}	
}

int main() {
	tree t;
	int n,i,abc,k,v;
	init(&t);
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d %d",&k,&v);
		add(&t,k,v);
	}
	for(i=0; i<3; i++) {
		scanf("%d", &abc);
		printf("%d\n", found(t,abc));
	}
	destroy(&t);
	return 0;
}
