//Q-> https://codeforces.com/problemset/problem/580/C
//sol->https://codeforces.com/contest/580/submission/70590876

//impQ->https://codeforces.com/problemset/problem/744/A
//sol->https://codeforces.com/contest/744/submission/88707934


//Q->https://codeforces.com/problemset/problem/520/B
//sol->https://codeforces.com/contest/520/submission/86323102

//Q->https://codeforces.com/problemset/problem/489/B
//sol->https://codeforces.com/contest/489/submission/80914049

//Q->https://codeforces.com/problemset/problem/510/B
//sol->https://codeforces.com/contest/510/submission/85614988


//Q->https://codeforces.com/problemset/problem/522/A
//sol-.https://codeforces.com/contest/522/submission/71528930

//Q->https://codeforces.com/problemset/problem/377/A
//sol->https://codeforces.com/contest/377/submission/70613660



#include<bits/stdc++.h>
using namespace std;
int v,m;
vector<int> adj[100000];
vector<bool>vis;

void dfs(int v)
{
    vis[v]=true;

    for(int u:adj[v])
    {
        if(!vis[u])
        dfs(u);
    }
   
    return;
}

int main()
{
    
    int a,b,temp;

    cin>>v>>m;
    
    vis.assign(v,false);
    
    for(int j=0;j<m;j++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);  //if undirected
    }
    for(int i=0;i<v;i++){
        if(!vis[i])
    dfs(i);
    }

    
    vis.clear();
    
   
    cout<<endl;
    
    
    return 0;
    
}
