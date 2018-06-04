#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int output(int n, int *a) {
        int i;
        for (i=0; i<n-1; i++) printf("%d ",*(a+i));
        printf("%d\n",*(a+n-1));
        return 0;
}

int pusirek(int n, int *a) {
	int i, j, k;
	bool flag = false;
	for (i = 0; i<n - 1; i++) {
		for (j = 0; j<n - i - 1; j++)
			if (*(a + j)<*(a + j + 1)) {
				flag = true;
				k = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = k;
			}
		if (!flag) break;
		flag = false;
	}
	return 0;
}

int comb(int n, int *a) {
        int step=n/2,i,j,k;
        while (step>=1) {
                for (i=0; i<n-step; i++) {
                        if(*(a+i)<*(a+i+step)) {
                                k=*(a+i);
                                *(a+i)=*(a+i+step);
                                *(a+i+step)=k;
                        }
                }
                step/=2;
        }
        pusirek(n, a);
        return 0;
}

int main() {
	int n, i;
	int  *a;

	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for (i=0; i<n; i++) scanf("%d",&a[i]);
	comb(n, a);
	output(n, a);
	free(a);

	return 0;
}
