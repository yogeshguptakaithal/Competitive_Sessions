#include<bits/stdc++.h>
#include <fstream>
using namespace std;
int m,n,a,b;
char c;
vector<vector<int>>adj;
set<int,greater<int>>st;
map<int,vector<int>>g;
map<int,int>num,low;
map<int,bool>vis,art;
int tim;
int h=0;
vector<pair<int,int>>at;


void dfs(int v,int p){
    int ct=0; int ctt=0;
    vis[v]=true;
    num[v]=low[v]=tim;
    tim++;
    for(int u:adj[v]){
        
    if(u==p)continue;
    if(vis[u])low[v]=min(low[v],num[u]);
    else{
        dfs(u,v);
        low[v]=min(low[v],low[u]);
        if(low[u]>=num[v]&&p!=-1) {
            art[v]=true;ct++;
        } 
        ctt++; //count unvisited children 
       
    }
   
    
    }
    if(p==-1&&ctt>1){
     art[v]=true; ct=ctt-1; //-1 as baad mein +1 hoga even if no parent
    }
    if(!art[v])ct=1; else ct=ct+1;//+1 for parent--important
    g[ct].push_back(v); //g[int f] has all nodes with pigion value f
    auto it=st.end();
    
    if(h<m||ct>*(--it)){
     st.insert(ct); h++;
    }
    
    
    return;
}


int main(){
  ofstream myfile;
  myfile.open ("output.txt");    //cin stops at space and newline both so no effect so use getline which stops at newline only


while(1){
    
     h=0;
    cin>>n>>m;
    if(n==0&&m==0)return 0;
    
    tim=0;
adj.assign(n,vector<int>());
while(1){
    cin>>a>>b;
    if(a==-1&&b==-1)break;
    adj[a].push_back(b);
    adj[b].push_back(a);
}

        
        
        
        dfs(0,-1); //as connected graph to we can start anywhere
        int sw=0; int z=0;
        for(auto x:st){
            sort(g[x].begin(),g[x].end());
            for(int f:g[x]){
            myfile<<f<<" "<<x<<endl;
            z++;
            if(z==m){
                sw=1; break;
            }
            }
            if(sw==1)break;
            
        }
       
      myfile<<endl;
        

       at.clear();
      art.clear();
      vis.clear();
      adj.clear();
      num.clear();
      low.clear();  
      st.clear();
      g.clear();

}


myfile.close();

    return 0;
}
