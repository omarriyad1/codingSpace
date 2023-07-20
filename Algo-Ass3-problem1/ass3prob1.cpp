#include <iostream>
#include <vector>
#include <string>  
#include <climits>
#include <algorithm>  
#include <cctype>  
#define nVer 7
using namespace std;
void PrintingMST(int a[nVer], int b[nVer], int weight[nVer])
{
    int MinWeight = 0;
    for (int i = 1; i < nVer - 1; i++)
    {
        cout << "Edge: " << "v" << a[i] + 1 << "-" << "v" << b[i] + 1 << " "
            << "cost: " << weight[i] << endl;
        MinWeight += weight[i];

    }
    cout << "Minimum Weight is " << MinWeight << endl;
}

void prim(int cost[nVer][nVer])
{
    int u, v, k = 0, counti = 0;
    int visited[nVer] = { 0 };
    int a[nVer];
    int b[nVer];
    int weight[nVer];
    int Minimum_Num;

    for (int i = 0; i < nVer; i++)
        for (int j = 1; j <= nVer; j++)
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;

    visited[0] = 1;

    while (counti < nVer - 1)
    {
        Minimum_Num = INT_MAX;
        for (int i = 0; i < nVer; i++)
        {
            for (int j = 0; j < nVer; j++)
            {
                if (visited[i] != 0 && cost[i][j] < Minimum_Num)
                {
                    Minimum_Num = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0)
        {
            a[k] = u;
            b[k] = v;
            weight[k] = cost[u][v];
            counti++;
            k++;
            visited[v] = 1;
        }

        cost[u][v] = cost[v][u] = INT_MAX;
    }

    PrintingMST(a, b, weight);
}

int main()
{
    int cost[nVer][nVer] = {
        { 0, 2, 4, 1, 0 , 0 ,0 },
        { 2 , 0 ,0 ,3 ,10 ,0 ,0},
        { 4 , 0 ,0 ,2 ,0 , 5, 0},
        { 1 ,3 ,2 ,0 ,7 ,8  ,4 },
        {0, 10 ,0 ,7 ,0 ,0  ,6 },
        { 0, 0, 5, 8, 0, 0 ,1  },
        { 0 ,0 ,0 , 4 , 6,1 , 0}
    };

    prim(cost);
    return 0;
}