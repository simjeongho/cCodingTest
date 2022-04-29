#include <iostream>
#include <cstdlib>
#define MAX_SIZE 100;
using namespace std;


void ShellSort(int* arr, int n)
{
	int gap, i, j, key;
	for (gap = n / 2; gap > 0; gap /= 2)//gap을 줄이는 과정 
	{
		if (gap % 2 == 0)//gap이 짝수면 홀수로 만들어준다. 
			++gap;

		for (i = gap; i <= n; ++i)//insertion sort 
		{
			key = arr[i];

			// for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
			// 	arr[j] = arr[j - gap];//오름차순 

			for (j = i; j >= gap && arr[j - gap] < key; j -= gap)
				arr[j] = arr[j - gap];//내림차순 

			arr[j] = key;
		}
	}
}
int main()
{
	int n = MAX_SIZE;
	int arr[n];
	

	for(int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << '	';

	ShellSort(arr, n);

	cout << '\n';
	for (int i = 0; i < n; ++i)
		cout << arr[i] << '	';

}