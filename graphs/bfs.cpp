#include<bits/stdc++.h>
using namespace std;
int r,c;
queue<pair<int,int>>q;
vector<vector<int>> adj;
map<pair<int,int>,bool>vis;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
map<pair<int,int>,int>rn;  //it is the time second going on
int tme;
int main()
{
    int t;
    cin>>t;
    int tt=t;
    int ct,ctt; //counts of 1 and  new 2;
    int a,b,temp;
    while(t--){
    cin>>r>>c;
    adj.assign(r,vector<int>(c,0));
    ct=ctt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
        cin>>adj[i][j];
        if(adj[i][j]==1)ct++;
        if(adj[i][j]==2)ctt--;  //as these countshould not be included while bfs 
        if(adj[i][j]==2){q.push({i,j}); vis[{i,j}]=true;}
        }
    }
    tme=0;
    while(!q.empty()){
        
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    
    adj[x][y]=2;
    ctt++;
    //cout<<x<<y<<endl;
    for(int i=0;i<4;i++){
        
          int a=x+dr[i];
          int b=y+dc[i];
          if(a<r&&a>=0&&b>=0&&b<c&&!vis[{a,b}]&&adj[a][b]==1){
              
              q.push({a,b});
              rn[{a,b}]=rn[{x,y}]+1;
              vis[{a,b}]=true;
              

          }
    }
    
    if(tme<rn[{x,y}]){tme=rn[{x,y}]; }

    }
    
   if(ctt!=ct)
   tme=-1;
    cout<<tme<<endl;

    vis.clear();
   adj.clear();
   rn.clear();

    }
    
    return 0;
    
}
