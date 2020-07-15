#include<bits/stdc++.h>
using namespace std;
int v,m;
vector<int> adj[100000];
int ans=0;
vector<bool>vis;
vector<int> tp;
void dfs(int v)
{
    vis[v]=true;

    for(int u:adj[v])
    {
        if(!vis[u])
        dfs(u);
    }
    tp.push_back(v+1);
    return;
}

int main()
{
    
    int a,b,temp;
    while(1){
    cin>>v>>m;
    for(int i=0;i<v;i++)adj[i].clear();
    if(v==m&&m==0)return 0;
    vis.assign(v,false);
    
    for(int j=0;j<m;j++)
    {
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        //adj[b-1].push_back(a-1);
    }
    for(int i=0;i<v;i++){
        if(!vis[i])
    dfs(i);
    }
    reverse(tp.begin(),tp.end());
    for(int i=0;i<tp.size();i++){
    cout<<tp[i];
    if(i!=tp.size()-1)
    cout<<" ";
    }
    vis.clear();
    tp.clear();
   
    cout<<endl;
    }
    
    return 0;
    
}
