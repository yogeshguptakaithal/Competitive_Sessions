//Q->Uva10004
//sol->https://ide.geeksforgeeks.org/41Lv5eVF4E
//***ImppQ->Uva11080
//sol->https://ide.geeksforgeeks.org/25IF7yanan

//Q->uva11396
//sol->https://ideone.com/m22tBG

#include<bits/stdc++.h>
#include <fstream>
using namespace std;
vector<vector<int>>adj;
vector<int>side;
bool bipart =true;
int main(){
    ofstream myfile;
        myfile.open ("output.txt");    
        int n,e;
        cin>>n>>e;
        if(n==0)return 0;
        int a,b;
        adj.assign(n,vector<int>());  //here it assigns number of empty vectors in adj
        side.assign(n,-1);
        while(e--){
        cin>>a>>b;
        if(a==0&&b==0)break;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);  //if undirected
        }
        queue<int>q;
         bipart=true;
        for(int i=0;i<n;i++){  //because graph can have unconnected regions 
        if(side[i]==-1){ //side -1 means not added to queue yet
        side[i]=0; 
        q.push(i);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int u:adj[v]){
            
                if(side[u]==-1){
                    if(side[v]==0)
               { side[u]=1;} else {side[u]=0; }
                q.push(u);
                }
                else if(side[u]==side[v])
                {bipart=false; break;}
                

            }
            if(!bipart)break;
        }

        //below is important logic
        }
        }

        if(bipart)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


     side.clear();
     adj.clear();
    
     myfile.close();

    return 0;
}