#include<stdio.h>

int main()
{
	double a[100], t;
	int n;

	printf("Please input n\n");
	scanf("%d", &n);


	printf("Please input array whose length is n\n");
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}	
	}

	printf("Result:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%.2lf ", a[i]);
	}

	printf("\n");

	return 0;
}
