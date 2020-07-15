#include<bits/stdc++.h>
#include <fstream>
using namespace std;

map<long,long>adj; //as here size is one for adj list of eaach node
map<long,bool>vis;
map<long,long>cnt;
bool cycle; long c; long ct=0;
  //here we can have cycles also
void dfs(long v){
    ct++;
    vis[v]=true; //i.e its cnt will be known now
    if(vis[adj[v]]){
        cycle=true; c=adj[v];cnt[v]=ct; return;
    }
    
    if(adj[v]==0){cnt[v]=1; return;}
    if(cnt[adj[v]]==0)dfs(adj[v]); //see vis here is for this connectted dfs path only
    
    if(cycle==true)cnt[v]=cnt[adj[v]];
    else
    cnt[v]=1+cnt[adj[v]];
    
    if(v==c){cycle=false; c=0; ct=0;}
   
    return;
}

int main(){
    ofstream myfile;
    myfile.open ("output.txt");
    int t;
    cin>>t;
    int tt=t;
    while(t--){
     long n,a,b,ans;
     cin>>n;
     for(long i=1;i<=n;i++){
         adj[i]=0; cnt[i]=0; vis[i]=false;
     }
     for(long i=0;i<n;i++){
     cin>>a>>b;
     adj[a]=b;   //directed
     }
     
     long mx=0;  ans=0;
    for(long i=1;i<=n;i++){
        vis.clear();
        c=0; cycle=false; ct=0;
        if(cnt[i]==0){dfs(i);}
        //cout<<cnt[i]<<endl;
        if(cnt[i]>mx){
            mx=cnt[i]; ans=i;
        }
     
    }
    
   
    myfile<<"Case "<<tt-t<<": "<<ans<<endl;
    cnt.clear();    
    adj.clear();
    vis.clear();
    }
    myfile.close();
    return 0;
}