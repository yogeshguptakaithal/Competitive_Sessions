/*We can classify the edges using the entry and exit time of the end nodes u and v of the edges (u,v). These classifications are often used for problems like finding bridges and finding articulation points.

We perform a DFS and classify the encountered edges using the following rules:

If v is not visited:

Tree Edge - If v is visited after u then edge (u,v) is called a tree edge. In other words, if v is visited for the first time and u is currently being visited then (u,v) is called tree edge. These edges form a DFS tree and hence the name tree edges.
If v is visited before u:

Back edges - If v is an ancestor of u, then the edge (u,v) is a back edge. v is an ancestor exactly if we already entered v, but not exited it yet. Back edges complete a cycle as there is a path from ancestor v to descendant u (in the recursion of DFS) and an edge from descendant u to ancestor v (back edge), thus a cycle is formed. Cycles can be detected using back edges.

Forward Edges - If v is a descendant of u, then edge (u,v) is a forward edge. In other words, if we already visited and exited v and entry[u]<entry[v] then the edge (u,v) forms a forward edge.

Cross Edges: if v is neither an ancestor or descendant of u, then edge (u,v) is a cross edge. In other words, if we already visited and exited v and entry[u]>entry[v] then (u,v) is a cross edge.
Note: Forward edges and cross edges only exist in directed graphs.*/

//as in undirected it is not possible fora vertex  to have a neighbour visited but it is unvisited in that call
//as if naighour is visited by other path then it is also visted as u-v and v-u edje are same thing
#include<bits/stdc++.h>
#define N 1000000007
using namespace std;
//generally bidirctional edjes are not counted in back edje but is still a cycle with 2 edjes
//so take that according to Q

//back edjes can be used to detect cycles so here we use 3 states i.e we add state exited also
vector<vector<int>> adj; // graph represented as an adjacency list
int n; // number of vertices

vector<int> color;

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}