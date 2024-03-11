

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool visited[10000];
vector<int> V[10000];

int main()
{
    int n, m, i, v1, v2;
    bool spojny;
    stack<int> S;
    cout << "Enter number of node and number of edges:";
    cin >> n >> m;
    cout << "Enter The Data:";
    for (i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        V[v1].push_back(v2);
        V[v2].push_back(v1);
    }

    cout << "\n";

    S.push(0);
    while (!S.empty())
    {
        v1 = S.top();
        S.pop();
        if (!visited[v1])
        {
            visited[v1] = true;
            for (int i = 0; i < V[v1].size(); i++)
                if (!visited[V[v1][i]])
                {
                    S.push(V[v1][i]);
                }
        }
    }

    spojny = true;
    for (i = 0; i < n; i++)
        if (!visited[i])
        {
            spojny = false;
            break;
        }

    cout << endl;

    if (spojny)
        cout << "this graph is consistent";
    else
        cout << "this graph is inconsistent";
}
