 #include <iostream>
using namespace std;

#define INF 999

int main()
{
    int n = 4;

    int graph[4][4] = {
        {0, 2, 3, 0},
        {2, 0, 1, 4},
        {3, 1, 0, 5},
        {0, 4, 5, 0}
    };

    int selected[4] = {0};
    int edges = 0;
    int totalCost = 0;

    // Convert 0 to INF
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    selected[0] = 1;

    cout << "Edges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;

        totalCost += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
