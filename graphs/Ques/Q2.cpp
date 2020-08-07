//modified bellman ford i.e for shortest path of atmost k edjes
//simple bellman ford with k iterations and with condition of path lenght cannot do this

//this algo work as realxation here is based on distances from previous iteration so it cant find path with more than k edjees before kth iterations

#include<bits/stdc++.h>
using namespace std;



int main(){
    vector<vector<double>>ed;   
    vector<double>dis;
    double a,b,k,n,m,s,w;
    cin>>n>>m>>k>>s;
    for(long i=0;i<m;i++){
        cin>>a>>b>>w;    
        ed.push_back({w,a,b}); //do twice if undirected
        

    }
dis.assign(n,LONG_MAX);  
dis[s]=0;


for (int i=0; i<k; ++i){
    map<long,long>tempdis; tempdis.clear();
        for (int j=0; j<m; ++j){
            if (dis[ed[j][1]] > LONG_MIN){
                
                if(dis[ed[j][2]]>dis[ed[j][1]] + ed[j][0])
                tempdis[ed[j][2]]=dis[ed[j][1]] + ed[j][0];
                
                }
            }

         for(auto x:tempdis)dis[x.first]=x.second; //i.e do for vertices only added to map  
            }

           


    for(long i=0;i<n;i++)cout<<dis[i]<<endl;



    
    return 0;
}