#include <iostream>

using namespace std;

void ShellSort(int* arr, int n)
{
	int gap, i, j, key;
	for (gap = n / 2; gap > 0; gap /= 2)//gap을 줄이는 과정 
	{
		if (gap % 2 == 0)
			++gap;

		for (i = gap; i <= n; ++i)//insertion sort 
		{
			key = arr[i];

			for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = key;
		}
	}
}
int main()
{
	int arr[15] = { 4, 8, 3, 6, 2, 1, 13, 15, 37, 56, 4, 2, 46, 24, 99};

	for (int i = 0; i < 15; ++i)
		cout << arr[i] << '	';

	ShellSort(arr, 14);

	cout << '\n';
	for (int i = 0; i < 15; ++i)
		cout << arr[i] << '	';

}