#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int output(int n, int *a) {
        int i;
        for (i=0; i<n-1; i++) printf("%d ",*(a+i));
        printf("%d\n",*(a+n-1));
        return 0;
}

int shell(int n, int *a) {
	int step=n/2,i,j,k;
        while (step>=1) {
                for (i=step; i<n; i++) {
			k=*(a+i);
                        for (j=i; j>=step; j-=step) {
				if(*(a+j-step)>k) *(a+j)=*(a+j-step);
				else break;
                        }
			*(a+j)=k;
                }
                step/=2;
        }
        return 0;

}

int main() {
	int n, i;
	int  *a;
	
	scanf("%d",&n);
        a=malloc(n*sizeof(int));
        for (i=0; i<n; i++) scanf("%d",&a[i]);
        shell(n, a);
        output(n, a);
        free(a);

	return 0;
}
