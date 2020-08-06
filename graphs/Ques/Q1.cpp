#include<bits/stdc++.h>
#include<fstream>
using namespace std;


int main() {
    ofstream myfile;
    myfile.open("output.txt");
    long t,n,k,x,y;
    double q;
    vector<pair<long,long>>v;
    
    
        cin>>n>>k;
    for(long i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    
    vector<pair<double,pair<long,long>>>adj;  // adj[wt,{i,j}] means weight of edje between ith index point of v and jth point is wt
    for(long i=0;i<v.size()-1;i++){
        for(long j=i+1;j<v.size();j++){
             double dis=sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second));
             adj.push_back({dis,{i,j}});
        }
    }
     q=0;
    sort(adj.begin(),adj.end()); //sort acc to wt
    vector<long>id; //id[i] is tree id of ith vertex in v
    id.assign(n,-1);
    for(long i=0;i<n;i++){
        id[i]=i;
    }
    
    ; long ct=n;
    map<long,vector<long>>st;

    for(auto a:adj){
        if(ct==k){
            q=a.first; break;//any 2 neighbouring befre that having less weight has been merged so
             //as before this edje we  got our sets and it is thte least edje weight after that
        }
        
        if(id[a.second.first]!=id[a.second.second]){
            
            ct--; //as one conn comp decreases
            
            
            long id1=id[a.second.first]; long id2=id[a.second.second];
            for(long i=0;i<n;i++){
                if(id[i]==id1)id[i]=id2;
            
            }
        

        }
        
    }
    for(long i=0;i<n;i++){
        st[id[i]].push_back(i);
    }

    cout<<"q is "<<q<<endl;
    for(auto x:st){
        for(auto z:x.second)
        cout<<"("<<v[z].first<<","<<v[z].second<<")"<<" ";
        cout<<endl;
    }
    
    

    adj.clear();
    v.clear();
    
    myfile.close();
    return 0;
}
