#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int output(int n, int *a) {
        int i;
        for (i=0; i<n-1; i++) printf("%d ",*(a+i));
        printf("%d\n",*(a+n-1));
        return 0;
}
int pros(int *a, int pos, int last) {
	int max, swap;
	bool end =false;
	while((pos*2 <= last)&&(!end)) {
		if(pos*2==last) max=pos*2;
		else if(a[pos*2] > a[pos*2+1]) max=pos*2;
		else max=pos*2+1;
		if(a[pos] < a[max])
		{
			swap = a[pos];
			a[pos]=a[max];
			a[max]=swap; 
			pos=max;
		}
		else end=true;
	}
}

int piramidka(int n, int *a) {
	int i, swap;
	for(i=(n/2)-1; i>=0; i--) {
		pros(a, i, n);
	}
	for(i=n-1; i>= 1; i--)
	{
		swap=a[0];
		a[0]=a[i];
		a[i]=swap;
		pros(a,0,i-1);
	}
        return 0;

}

int main() {
	int n, i;
	int  *a;
	
	scanf("%d",&n);
        a=malloc(n*sizeof(int));
        for (i=0; i<n; i++) scanf("%d",&a[i]);
        piramidka(n, a);
        output(n, a);
        free(a);

	return 0;
}
