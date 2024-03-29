#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
map<int, bool> visited;
map<int, list<int>> adj;
void addEdge(int v, int w)
{
adj[v].push_back(w);
}
void DFS(int v)
{
visited[v] = true;
cout << v << " ";
list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i)
{
if (!visited[*i])
DFS(*i);
}
}
};
int main()
{
Graph g;
g.addEdge(0, 3);
g.addEdge(0, 1);
g.addEdge(1, 3);
g.addEdge(2, 1);
g.addEdge(1, 0);
g.addEdge(3, 3);
cout << "Following is DFS traversal (starting from node 2)\n";
g.DFS(2);
cout<<endl;
return 0;
}
