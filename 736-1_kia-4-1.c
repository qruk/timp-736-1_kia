#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node;
typedef node* stack;

int init(stack *stk) {
	*stk=NULL;
	return 0;
}

_Bool isEmpty(stack stk) {
	if(stk == NULL) return 1;
	return 0;
}

int destroy(stack *stk) {
	stack p;
	while(*stk != NULL) {
		p=*stk;
		*stk=(*stk)->next;
		free(p);
	}
	return 0;
}

int top(stack stk) {
	if(!isEmpty(stk)) return stk->value;
}

int view(stack stk) {
	stack p=stk;
	while(p != NULL) {
		printf("%d ", p->value);
		p=p->next;
	}
	return 0;
}

int push(stack *stk, int value) {
	stack p;
	if(!isEmpty(*stk)) {
		p=*stk;
		*stk=malloc(sizeof(node));
		(*stk)->next=p;
	}
	else {
		*stk=malloc(sizeof(node));
		(*stk)->next=NULL;
	}
	(*stk)->value=value;
	return 0;
} 

int pop(stack *stk) {
	stack p;
	if(!isEmpty(*stk)) {
		p=*stk;
		*stk=(*stk)->next;
		free(p);
	}
	return 0;
}

int main() {
	stack x; int i;
	init(&x);
	for(i=0; i<10; i++) {
		push(&x,i);
	}
	view(x);
	destroy(&x);
	if(isEmpty(x)) printf("free\n");
	return 0;
}
