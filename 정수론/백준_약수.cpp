#include<stdio.h>
void sort(int a[], int n) //오름차순 선택정렬
{
	int i, j, m, t;
	for (i = 0; i < n; i++)
	{
		m = i;
		for (j = i; j < n; j++)
		{
			if (a[m] > a[j])
			{
				m = j;
			}
		}

		t = a[i];
		a[i] = a[m];
		a[m] = t;

	}
}
int main(void)
{
	int N;
	int a[51];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}

	sort(a, N);

	printf("%d", a[0] * a[N - 1]);
}