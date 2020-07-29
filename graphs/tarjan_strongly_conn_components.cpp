//Q->Uva247 Calling Circles
//sol->https://ide.geeksforgeeks.org/8Ot4Ugenoj

//impQ->Uva 11504 Dominos
//sol->https://ide.geeksforgeeks.org/3lOLXSnUFU

//Q->uva 11838 come and go
//sol->https://ide.geeksforgeeks.org/a5U7Ta0xa8


#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int n,m;
vector<int> adj[100000];
vector<bool>vis;
vector<int>stk,low,id; 
map<int,bool>onstk;
map<int,bool>lk; //link low link value to bool i.e. a strong conn comp to a bool as low of all comp same 
int c; ofstream myfile;
int ans;

void dfs(int v){
    
 id[v]=low[v]=c;
c++;
    vis[v]=true;
    stk.push_back(v);
    onstk[v]=true;
    for(int u:adj[v])
    {
        if(!vis[u])
        dfs(u);
        if(onstk[u])low[v]=min(low[v],low[u]);
        
    }
    if(id[v]==low[v]){
        int a=0;

        while (1)
        {
            int d=stk.back();
            onstk[d]=false;
            stk.pop_back();
            low[d]=id[v];
            a++;
            if(d==v)break;
        }
        if(a==n)ans=1;  //as whole graph should be a component 
        
    }
   
    return;
}

int main()
{   
    myfile.open("output.txt");
    
    while(cin>>n>>m){
        ans=0;
        if(n==0&&m==0)return 0;

        c=0;
    int a,b,temp,p;
    
    vis.assign(n,false);
    low.assign(n,-1);
    id.assign(n,-1);
    for(int i=0;i<n;i++)adj[i].clear();
    
    for(int j=0;j<m;j++)
    {
        cin>>a>>b>>p;
        adj[a-1].push_back(b-1);
        if(p==2)
        adj[b-1].push_back(a-1);
        
    }
     
    dfs(0);

    
    
    cout<<ans<<endl;

    
    vis.clear();
    onstk.clear(); stk.clear();
    lk.clear();
   low.clear(); id.clear();
    

    }
    
    
    return 0;
    
}
