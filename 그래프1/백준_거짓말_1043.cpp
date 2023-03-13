#include<iostream>
#include<vector>

#define endl "\n"
#define MAX 55
using namespace std;

int N, M, Answer;
int Parent[MAX];
vector<int> Know_Truth;
vector<int> Party[MAX];

void Input()
{
    cin >> N >> M;
    int K; cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a; cin >> a;
        Know_Truth.push_back(a);
    }
    for (int i = 0; i < M; i++)
    {
        int Num; cin >> Num;
        for (int j = 0; j < Num; j++)
        {
            int a; cin >> a;
            Party[i].push_back(a);
        }
    }
    Answer = M;
}

int Find_Parent(int A)
{
    if (A == Parent[A]) return A;
    return Parent[A] = Find_Parent(Parent[A]);
}

void Union(int A, int B)
{
    A = Find_Parent(A);
    B = Find_Parent(B);
    Parent[B] = A;
}

bool Same_Parent(int A, int B)
{
    A = Find_Parent(A);
    B = Find_Parent(B);
    if (A == B) return true;
    return false;
}

void Solution()
{
    for (int i = 1; i <= N; i++) Parent[i] = i;
    for (int i = 0; i < M; i++)
    {
        int N1 = Party[i][0];
        for (int j = 1; j < Party[i].size(); j++)
        {
            int N2 = Party[i][j];
            Union(N1, N2);
        }
    }

    for (int i = 0; i < M; i++)
    {
        bool Go_Party = true;
        for (int j = 0; j < Party[i].size(); j++)
        {
            if (Go_Party == false) break;
            int N1 = Party[i][j];
            for (int k = 0; k < Know_Truth.size(); k++)
            {
                int N2 = Know_Truth[k];
                if (Same_Parent(N1, N2) == true)
                {
                    Go_Party = false;
                    break;
                }
            }
        }

        if (Go_Party == false) Answer--;
    }
    cout << Answer << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
