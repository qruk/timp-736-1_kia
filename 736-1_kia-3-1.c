#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node *next;
	struct node  *prev;
} node;
typedef node* list;

int init(list *root) {
	*root=NULL;
	return 0;
}

_Bool isEmpty(list root) {
	if(root==NULL) return 1;
	else return 0;
}

int destroy(list *root) {
	list clear;
	if(!isEmpty(*root)) {
		while((*root)->next != NULL) {
			clear=(*root)->next;
			free(*root);
			*root=clear;
		}
		free(*root);
		*root=NULL;
	}
	return 0;
}

list found(list root, int value) {
	list p=root;
	if(!isEmpty(root)) {
		while((p->next != NULL)&&(p->value != value)) p=p->next;
		if (p->value == value) return p;
		else return NULL; 
	}
	else return NULL;
}

int append(list *lst, int value) {
	list p; 
	if(*lst!=NULL) {
		p=malloc(sizeof(node));
		p->next=(*lst)->next;
		if(p->next!=NULL) p->next->prev=p;
		p->prev=(*lst);
		(*lst)->next=p;
		p->value=value;
	}
	return 0;
}

int prepend(list *lst, int value) {
	list p;
	if(*lst!=NULL) {
		p=malloc(sizeof(node));
		p->prev=(*lst)->prev;
		if(p->prev!=NULL) p->prev->next=p;
		p->next=(*lst);
		(*lst)->prev=p;
		p->value=value;
		if(p->prev==NULL) *lst=p;
	}
	return 0;
}

int remover(list *lst) {
	list p;
	if(*lst!=NULL) {
		if( ((*lst)->next==NULL) && ((*lst)->prev==NULL) ) destroy(&(*lst));
		else {
			if((*lst)->prev!=NULL) (*lst)->prev->next=(*lst)->next; 
			if((*lst)->next!=NULL) (*lst)->next->prev=(*lst)->prev;
			if((*lst)->prev==NULL) {
				p=*lst;
				*lst=(*lst)->next;
				free(p);
			}
			else {
				free(*lst);
				*lst=NULL;
			}		
		}
	}
	return 0;
}

int print(list *root) {
	list p=*root;
	if(!isEmpty(*root)) {
		while(p!=NULL) {
			printf("%d ", p->value);
			p=p->next; 
			}
	printf("\n");
	} 
	return 0;
}

int main() {
	list x, p;
	int n,k,m,a,b,c,d,i,xi;
	init(&x); 
	x=malloc(sizeof(node)); p=x;
	x->value=0; x->next=NULL; x->prev=NULL;

	scanf("%d", &n); scanf("%d", &xi); x->value=xi; 
	for(i=1;i<n;i++) {
		scanf("%d", &xi);
		append(&p, xi);
		p=p->next;
	}  
	print(&x);

	p=x; scanf("%d", &k); i=1;
	while(i<k) {
		p=p->next;
		i++;
	}
	remover(&p); 
	if(k==1) x=p;
	print(&x);
	
	scanf("%d", &m);
	if(x->value == m) remover(&x);
	else {
		p=found(x,m);
		remover(&p);
	}
	print(&x); 
	
	p=x; i=1; scanf("%d", &a); scanf("%d", &b);
	while(i<a) {
		p=p->next;
		i++;
	}
	append(&p, b); 
	print(&x);	
	
	p=x; i=1; scanf("%d", &c); scanf("%d", &d);
	while(i<c) {
		p=p->next;
		i++;
	}
	prepend(&p, d);
	if(c==1) x=p;
	print(&x);

	destroy(&x);
	return 0;
}
