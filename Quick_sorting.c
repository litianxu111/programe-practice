#include<stdio.h>

void printArray(double* array, int top, int bottom)
{
	for(int i = top; i <= bottom; i++)
	{
		printf("%.2lf ", array[i]);
	}
	printf("\n");
}

void quick_sort(double* a, int top, int bottom )
{
	
	if(top > bottom)
	{
		return;
	}
	
	double t;
	int standard = top;
	int length = bottom;

	while(top <= bottom)
	{
		if(a[bottom] < a[standard])
		{
			while(a[top] <= a[standard] && top != bottom)
			{
				top++;
			}
			t = a[top];
			a[top] = a[bottom];
			a[bottom] = t;
		}
		if(top == bottom)
		{
			t = a[standard];
			a[standard] = a[bottom];
			a[bottom] = t;
		}
		bottom--;
	}

	quick_sort(a, 0, bottom);
	quick_sort(a, top+1, length);

}

int main()
{
	double a[100], t;
	int n;

	printf("Please input n:\n");
	scanf("%d", &n);
		
	printf("Please input array whose length is n:\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	quick_sort(a, 0, n-1);s

	printf("Result:\n");
	printArray(a, 0, n-1);
	
	return 0;
}
