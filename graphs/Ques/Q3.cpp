#include<bits/stdc++.h>
using namespace std;
vector<long>par;

long findset(long v) {
    if (v == par[v])
        return v;
    return par[v] = findset(par[v]);
}

void unionsets(long a, long b) {
    a = findset(a);
    b = findset(b);
    if (a != b)
        par[b] = a;
}

int main(){
    long n,a,b;
    cin>>n;
    pair<long,long>ans; 
    par.assign(n,-1);
    for(long i=0;i<n;i++){par[i]=i;}

    for(long i=0;i<n;i++){cin>>a>>b;  a--;b--;
      if(findset(a)==findset(b)){ans.first=a; ans.second=b;}
      else unionsets(a,b);
    
     }

     cout<<ans.first<<" "<<ans.second<<endl;

   


return 0;
}