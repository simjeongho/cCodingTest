#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 30
#define MAX1 100000
#define MAX2 500000
#define MAX3 1000000
#define MAX4 5000000
#define MAX5 10000000
using namespace std;
void shell_sort3h1(int a[], int n)
{   /* h = 3*h + 1 이용 */
    int i, j, k, h, v;
    for (h = 1; h < n; h = 3 * h + 1); /* n 보다 작은 h 의 최대값 가짐 */
    for (; h > 0; h /= 3)// h의 값을 줄여가면서 계산 
    {
        for (i = h; i <= n; i++) // 최대값 h가 n보다 작을 때까지 부분 배열
        {
            v = a[i];// v에 a[i]값 저장
            j = i; // j는 인덱스를 기억 
            while(j >= h && a[j - h] > v) {
                a[j] = a[j-h];
                j = j - h;
            }
            a[j] = v;
        }
    }
}
void shell_sort3h(int a[], int n)
{   /* h = 3*h + 1 이용 */
    int i, j, k, h, v;
    for (h = 1; h < n; h = 3 * h); /* n 보다 작은 h 의 최대값 가짐 */
    for (; h > 0; h /= 3)// h의 값을 줄여가면서 계산 
    {
        for (i = h; i <= n; i++) // 최대값 h가 n보다 작을 때까지 부분 배열
        {
            v = a[i];// v에 a[i]값 저장
            j = i; // j는 인덱스를 기억 
            while(j >= h && a[j - h] > v) {
                a[j] = a[j-h];
                j = j - h;
            }
            a[j] = v;
        }
    }
}
void shell_sort5h1(int a[], int n)
{   /* h = 3*h + 1 이용 */
    int i, j, k, h, v;
    for (h = 1; h < n; h = 5 * h + 1); /* n 보다 작은 h 의 최대값 가짐 */
    for (; h > 0; h /= 5)// h의 값을 줄여가면서 계산 
    {
        for (i = h; i <= n; i++) // 최대값 h가 n보다 작을 때까지 부분 배열
        {
            v = a[i];// v에 a[i]값 저장
            j = i; // j는 인덱스를 기억 
            while(j >= h && a[j - h] > v) {
                a[j] = a[j-h];
                j = j - h;
            }
            a[j] = v;
        }
    }
}
void checkSort(int a[], int n){
    int i, sorted;
    sorted = 1;
    for( i = 0; i < n; i ++) {
        if(a[i] > a[i + 1]) {
            sorted = 0;
        }
        if(!sorted) {
            break;
        }
    }
    if(sorted == 0) {
        cout << "sort error" << endl;
    }
    else {
        cout << "sort complete" << endl;
    }
}
int main()
{
	int n1 = MAX1;
    int n2 = MAX2;
    int n3 = MAX3;
    int n4 = MAX4;
    int n5 = MAX5;

	int arr[n1];
    int arr2[n2];
	clock_t start, finish, start1, finish1;
    double duration, duration1;

	for(int i = 0; i < n1; i++) {
		arr[i] = rand() % n1;
	}
    // for (int i = 0; i < n; ++i)
	// 	cout << arr[i] << '	';
    start = clock();
    shell_sort3h1(arr, n1);
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "increament : 3h + 1, decreament h/3 shell sort time(N = " << n1 << ") : " << duration <<"sec";
    cout << '\n';
    checkSort(arr, n1);

    // //3h+1 500000
    // for(int i = 0; i < n2; i++) {
	// 	arr2[i] = rand() % n2;
	// }
    // start1 = clock();
    // shell_sort3h1(arr2, n2);
    // finish1 = clock();
    // duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    // cout << "increament : 3h + 1, decreament h/3 shell sort time(N = " << n2 << ") : " << duration1 <<"sec" ;
    // cout << '\n';
    // checkSort(arr2, n2);
	// // for (int i = 0; i < n; ++i)
	// // 	cout << arr[i] << '	';

    return 0;
}