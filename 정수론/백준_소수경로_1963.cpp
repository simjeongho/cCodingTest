#include<iostream>
#include<cstring>
#include<queue>
#include<string>

#define endl "\n"
#define MAX 10000
using namespace std;

bool EraTos[MAX];
bool Visit[MAX];

int Start, End;

void Initialize()
{
    memset(EraTos, true, sizeof(EraTos));
    for (int i = 2; i < MAX; i++)
    {
        for (int j = 2; i * j < MAX; j++)
        {
            EraTos[i * j] = false;
        }
    }
    memset(Visit, false, sizeof(Visit));
}

void Input()
{
    cin >> Start >> End;
}

void Solution()
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(Start, 0));
    Visit[Start] = true;

    while (Q.empty() == 0)
    {
        int Cur_Num = Q.front().first;
        int Cnt = Q.front().second;
        Q.pop();

        if (Cur_Num == End)
        {
            cout << Cnt << endl;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int Next_Num;
            for (int j = 0; j < 10; j++)
            {
                string s = to_string(Cur_Num);
                s[i] = j + '0';
                Next_Num = stoi(s);

                if (EraTos[Next_Num] == false) continue;
                if (Visit[Next_Num] == true) continue;
                if (Next_Num >= 10000 || Next_Num < 1000) continue;

                Visit[Next_Num] = true;
                Q.push(make_pair(Next_Num, Cnt + 1));
            }
        }
    }
    cout << "Impossible" << endl;
}

void Solve()
{
    int Tc;
    cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //    freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
