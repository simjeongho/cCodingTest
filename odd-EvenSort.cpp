// c++ Program for Odd-Even Transposition sort
//쓰레드를 이용할 것이다.  
  
#include <bits/stdc++.h>
#include <pthread.h>
#include <time.h>
  
using namespace std;
  
// 배열 크기  
#define n 5000
  
// 쓰레드 크기는 데이터 총 수의 /2 + 1 
int max_threads = (n + 1) / 2;
  
int a[n]; 
int tmp;
  

void* compare(void* arg)
{
    int index = tmp; // index를 받는다.  
    tmp = tmp + 2; // 홀수는 홀수끼리 짝수는 짝수끼 리 
  
  	
    if ((a[index] > a[index + 1]) && (index + 1 < n)) {
        swap(a[index], a[index + 1]);// 바꿔준다.  
    }
    
}
  
void oddEven(pthread_t threads[])
{
    int i, j;
  
    for (i = 1; i <= n; i++) {
        // 홀수  
        if (i % 2 == 1) {
            tmp = 0;
  
            // thread를 만들어 compare함수를 실행해준다.  
            for (j = 0; j < max_threads; j++)
                pthread_create(&threads[j], NULL, compare, NULL);
              //  cout << "odd index " << endl;
           /* for(int i = 0 ; i < n; i++){
            
    			cout << a[i] << " ";
			}
				cout << endl;*/
  
            // 모든 thread가 끝날 때까지 기다렸다가 합쳐준다.  
            for (j = 0; j < max_threads; j++)
                pthread_join(threads[j], NULL);
        }
  
        // 짝수 thread 
        else {
            tmp = 1;
  
            // thread를 만들어 각 thread에 대해 compare함수를 실행해준다.  
            for (j = 0; j < max_threads - 1; j++)
                pthread_create(&threads[j], NULL, compare, NULL);
            
          //  cout << "even index" << endl;
           /* for(int i = 0 ; i < n; i++){
    			cout << a[i] << " ";
			}
				cout << endl;*/
  
            // 쓰레드가 끝날 때까지 기다렸다가 합쳐준다.  
            for (j = 0; j < max_threads - 1; j++)
                pthread_join(threads[j], NULL);
        }
    }
}
  
// 배열을 출력하는 함수  
void printArray()
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

}

void checkSort(int a[], int num){
    int i, sorted;
    sorted = 1;
    for( i = 0; i < num; i ++) {
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
	clock_t start, finish;
	double duration;
  
    pthread_t threads[max_threads];//전체 인풋의 /2 +1 
    
    /*for( int i=0 ; i < n; i ++) {
		cin >> a[i];
	}// a입력 받는다*/
	
	for(int i= 0; i < n; i++){
		a[i] = rand() % 1000;
	} 	
  
    cout << "Given array is: ";
    //printArray();
  	start = clock();
    oddEven(threads);
    finish = clock();
	duration = (double)(finish - start) /CLOCKS_PER_SEC;  
    cout << "\nSorted array is: ";
	cout << "duration" << duration << endl;
   // printArray();
    checkSort(a, n);
  
    return 0;
}
