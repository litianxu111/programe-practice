#include<stdio.h>
#define MAX 1001

int main()
{
	int a[MAX], n, i, j, t;

	for(i = 0; i <= MAX; i++){
		a[i] = 0;
	}
	
	printf("Please input n:\n");
	scanf("%d", &n);

	printf("Please input some numbers:\n");
	for(i = 1; i <= n; i++){
		scanf("%d", &t);
		a[t]++;
	}

	printf("------sorting result------\n");
	printf("ascending order:\n");

	for(i = 0; i<= MAX-1; i++){
		for(j = 1; j <=a[i]; j++){
			printf("%d ", i);
		}
	}

	printf("\ndecending order:\n");
	for(i = MAX-1; i > 0; i--){
		for(j = 1; j <= a[i]; j++){
			printf("%d ", i);
		}
	}

	getchar();
	getchar();

	return 0;
}
