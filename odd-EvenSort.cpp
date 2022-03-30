// c++ Program for Odd-Even Transposition sort
//�����带 �̿��� ���̴�.  
  
#include <bits/stdc++.h>
#include <pthread.h>
#include <time.h>
  
using namespace std;
  
// �迭 ũ��  
#define n 5000
  
// ������ ũ��� ������ �� ���� /2 + 1 
int max_threads = (n + 1) / 2;
  
int a[n]; 
int tmp;
  

void* compare(void* arg)
{
    int index = tmp; // index�� �޴´�.  
    tmp = tmp + 2; // Ȧ���� Ȧ������ ¦���� ¦���� �� 
  
  	
    if ((a[index] > a[index + 1]) && (index + 1 < n)) {
        swap(a[index], a[index + 1]);// �ٲ��ش�.  
    }
    
}
  
void oddEven(pthread_t threads[])
{
    int i, j;
  
    for (i = 1; i <= n; i++) {
        // Ȧ��  
        if (i % 2 == 1) {
            tmp = 0;
  
            // thread�� ����� compare�Լ��� �������ش�.  
            for (j = 0; j < max_threads; j++)
                pthread_create(&threads[j], NULL, compare, NULL);
              //  cout << "odd index " << endl;
           /* for(int i = 0 ; i < n; i++){
            
    			cout << a[i] << " ";
			}
				cout << endl;*/
  
            // ��� thread�� ���� ������ ��ٷȴٰ� �����ش�.  
            for (j = 0; j < max_threads; j++)
                pthread_join(threads[j], NULL);
        }
  
        // ¦�� thread 
        else {
            tmp = 1;
  
            // thread�� ����� �� thread�� ���� compare�Լ��� �������ش�.  
            for (j = 0; j < max_threads - 1; j++)
                pthread_create(&threads[j], NULL, compare, NULL);
            
          //  cout << "even index" << endl;
           /* for(int i = 0 ; i < n; i++){
    			cout << a[i] << " ";
			}
				cout << endl;*/
  
            // �����尡 ���� ������ ��ٷȴٰ� �����ش�.  
            for (j = 0; j < max_threads - 1; j++)
                pthread_join(threads[j], NULL);
        }
    }
}
  
// �迭�� ����ϴ� �Լ�  
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
  
    pthread_t threads[max_threads];//��ü ��ǲ�� /2 +1 
    
    /*for( int i=0 ; i < n; i ++) {
		cin >> a[i];
	}// a�Է� �޴´�*/
	
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
