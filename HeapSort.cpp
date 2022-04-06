#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>

#define MAX 10
using namespace std;
//int Arr = { 6, 2, 8, 1, 3, 9, 4, 5, 10, 7 };
int Arr[MAX + 1];
int arr[MAX + 1];
bool Flag[MAX + 1];


void Build_MaxHeap()
{
    for (int Cur_Idx = 2; Cur_Idx <= MAX; Cur_Idx++)
    {
        while (Cur_Idx > 1)    // 루트일 때는 안한다. 
        {
            int Parent_Idx = Cur_Idx / 2; // 부모 인덱스는 현재 인덱스의 1/2
            if (Arr[Cur_Idx] > Arr[Parent_Idx]) // 만약 현재 인덱스의 노드 값보다 부모 인덱스의 값이 더 작다면 
            {
                swap(Arr[Cur_Idx], Arr[Parent_Idx]); // 바꿔준다. min heap
                Cur_Idx = Parent_Idx;
            }
            else break;
        }
    }
}

void Build_minHeap()
{
    for (int Cur_Idx = 2; Cur_Idx <= MAX; Cur_Idx++)
    {
        while (Cur_Idx > 1)    // 루트일 때는 안한다. 부모가 없기 때문에 
        {
            int Parent_Idx = Cur_Idx / 2; // 부모 인덱스는 현재 인덱스의 1/2
            if (Arr[Cur_Idx] < Arr[Parent_Idx]) // 만약 현재 인덱스의 노드 값보다 부모 인덱스의 값이 더 크다면
            {
                swap(Arr[Cur_Idx], Arr[Parent_Idx]); // 바꿔준다. min heap
                Cur_Idx = Parent_Idx;
            }
            else break;
        }
    }
}

void minHeapify(int Current, int N) // minheap으로 만들어주는 역할 
{
    int Cur_Idx = Current;
    int Left_Child = Current * 2; // left child
    int Right_Child = Current * 2 + 1; // right child 

    if ((Left_Child <= N) && (Arr[Left_Child] < Arr[Cur_Idx])) Cur_Idx = Left_Child; // 
    if ((Right_Child <= N) && (Arr[Right_Child] < Arr[Cur_Idx])) Cur_Idx = Right_Child;

    if (Cur_Idx != Current) // 기저사례
    {
        swap(Arr[Cur_Idx], Arr[Current]);
        minHeapify(Cur_Idx, N);
    }
}

void maxHeapify(int Current, int N) // maxheap으로 만들어주는 역할 
{
    int Cur_Idx = Current;
    int Left_Child = Current * 2; // left child
    int Right_Child = Current * 2 + 1; // right child 

    if ((Left_Child <= N) && (Arr[Left_Child] > Arr[Cur_Idx])) Cur_Idx = Left_Child; // 
    if ((Right_Child <= N) && (Arr[Right_Child] > Arr[Cur_Idx])) Cur_Idx = Right_Child;

    if (Cur_Idx != Current) // 기저사례
    {
        swap(Arr[Cur_Idx], Arr[Current]);
        maxHeapify(Cur_Idx, N);
    }
}
void checkMaxSort(int a[], int num) {
    int i, sorted;
    sorted = 1;
    for (i = 0; i < num; i++) {
        if (a[i] > a[i + 1]) {
            sorted = 0;
        }
        if (!sorted) {
            break;
        }
    }
    if (sorted == 0) {
        cout << "sort error" << endl;
    }
    else {
        cout << "sort complete" << endl;
    }
}

void checkMinSort(int a[], int num) {
    int i, sorted;
    sorted = 1;
    for (i = 1; i < num; i++) {
        if (a[i] < a[i + 1]) {
            sorted = 0;
        }
        if (!sorted) {
            break;
        }
    }
    if (sorted == 0) {
        cout << "sort error" << endl;
    }
    else {
        cout << "sort complete" << endl;
    }
}
void maxHeapSort()
{
    Build_MaxHeap();
    for (int i = MAX; i >= 2; i--)
    {
        swap(Arr[i], Arr[1]);
        maxHeapify(1, i - 1);
    }
}

void minHeapSort()
{
    Build_minHeap();
    for (int i = MAX; i >= 2; i--)
    {
        swap(Arr[i], Arr[1]);
        minHeapify(1, i - 1);
    }
}

void swap(int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void makeheap(int root, int n) {
    int temp = arr[root]; // 해당 부모 노드
    int child = root * 2; // 왼쪽 자식 노드
    while (child <= n) {
        // 더 큰 자식 노드 찾기
        if (child < n && arr[child] < arr[child + 1])
            child++;
        if (temp < arr[child]) { // 자식 노드가 더 클 경우
            arr[child / 2] = arr[child];
            child *= 2; // 레벨 낮추기
        }
        else break;
    }
    arr[child / 2] = temp;

}
void heapsort(int n) {
    // 최대 힙 구성
    for (int i = n / 2; i > 0; i--) {
        makeheap(i, n);
    }

    int temp;
    for (int i = n; i > 0; i--) {
        swap(1, i);
        makeheap(1, i - 1);
    }
}
int main(void)
{
    clock_t start1, start2, finish1, finish2;
    double duration1, duration2;
    //Arr[1] = 6; Arr[2] = 2; Arr[3] = 8; Arr[4] = 1; Arr[5] = 3; Arr[6] = 9; Arr[7] = 4; Arr[8] = 5; Arr[9] = 10; Arr[10] = 7;
    srand((unsigned)time(NULL));
    for (int i = 1; i <= MAX; )
    {
        Arr[i] = rand();
       
    }

    cout << "[ Initialize Array State ]" << endl;
    //Print();
    start1 = clock();
    maxHeapSort();
    //heapsort(MAX);
    finish1 = clock();
    duration1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
    checkMaxSort(Arr, MAX);
    cout << "Max heap Sorting " << "(N = " << MAX << " ) time cost : " << duration1 << endl;
    cout << "[ After max Sorting Array State]" << endl;
   // Print();

    srand((unsigned)time(NULL));
    for (int i = 1; i <= MAX; )
    {
        Arr[i] = rand();
       
    }

    cout << "[ Initialize Array State ]" << endl;
    //Print();
    start2 = clock();
    minHeapSort();
    finish2 = clock();
    cout << "[ After min Sorting Array State]" << endl;
    duration2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
    checkMinSort(Arr, MAX);
    cout << "Min heap Sorting " << "(N = " << MAX << " ) time cost : " << duration2 << endl;
    //Print();



    return 0;
}
