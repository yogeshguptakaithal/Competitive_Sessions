#include<bits/stdc++.h>
#include <fstream>
using namespace std;
vector<vector<int>>adj;
map<int,int>num,low,art;
map<int,bool>vis;
int tim;
int ans=0;
vector<pair<int,int>>at,g;


void dfs(int v,int p){
    
    vis[v]=true;
    num[v]=low[v]=tim;
    tim++;
    for(int u:adj[v]){
    if(u==p)continue;
    if(vis[u])low[v]=min(low[v],num[u]);
    else{
        dfs(u,v);
        low[v]=min(low[v],low[u]);
        if(low[u]>num[v]){ans++; at.push_back({min(u,v),max(u,v)});}  
       
    }

    }
    
    return;
}


int main(){
  ofstream myfile;
  myfile.open ("output.txt");    //cin stops at space and newline both so no effect so use getline which stops at newline only
int x,n,a,b;
char c;

cin>>n>>x;
    tim=0;
adj.assign(n,vector<int>());
for(int i=0;i<x;i++){
    cin>>a>>b;
    g.push_back({a-1,b-1});
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
}
        
        ans=0;
        for(int i=0;i<n;i++)
        if(!vis[i])
        dfs(i,-1); //as connected graph to we can start anywhere
       
      
        

       cout<<ans<<" critical links"<<endl;
       sort(at.begin(),at.end());
       for(auto x:at)
       cout<<x.first<<" - "<<x.second<<endl;
       cout<<endl;
       at.clear();
      art.clear();
      vis.clear();
      adj.clear();
      num.clear();
      low.clear();  




myfile.close();

    return 0;
}
