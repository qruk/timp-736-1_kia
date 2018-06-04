#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int output(int n, int *a) {
        int i;
        for (i=0; i<n-1; i++) printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
        return 0;
}

int supp(int *a, int left, int right) {
	int o=a[right];
	if(((a[left] > a[(right+left)/2]) && (a[left] < a[right])) || ((a[left] < a[(right+left)/2]) && (a[left] > a[right]))) o=a[left];
	else if(((a[left] <  a[(right+left)/2]) && (a[(right+left)/2] < a[right])) || ((a[left] > a[(right+left)/2]) && (a[(right+left)/2] > a[right]))) o=a[(right+left)/2];
	return o;
}

void quicksort (int *a, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle;
	middle = supp(a,left,right);
        do
        {
            while (a[left] < middle) left++;
            while (a[right] > middle) right--;
            if (left <= right)
            {
                int tmp = a[left];
		a[left] = a[right];
                a[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quicksort(a, first, right);
        quicksort(a, left, last);
    }
}

int hoar(int n, int *a) {
	quicksort(a, 0, n-1);
	return 0;
}

int main() {
	int n, i;
	int  *a;

	scanf("%d",&n);
	a=malloc(n*sizeof(int));
	for (i=0; i<n; i++) scanf("%d",&a[i]);
	hoar(n, a);
	output(n, a);
	free(a);

	return 0;
}
