#include <stdio.h>

int main() {
	int n,i,x;
	float p=1;
	scanf("%d", &n);
	for (i=1; i<n+1; i++) {
		scanf("%d", &x);
		p=p*(x-i);
	}
	printf("%f\n", p);
}
