#include<bits/stdc++.h>
using namespace std;
 int m,n,a,b,sw,ans;
vector<vector<char>>arr;
vector<vector<int>>vis;
char l,w;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
int floodfill(int r, int c){
      // cout<<r<<c<<endl;
    vis[r][c]=1;                      //also we can do ki arr[r][c] ko hi change krden to show vis
    if(r==a&&c==b)sw=1;
    int ct=1;
    for(int i=0;i<4;i++){
    
if(r+dr[i]>=0&&r+dr[i]<m&&!vis[r+dr[i]][(c+dc[i]+n)%n]&&arr[r+dr[i]][(c+dc[i]+n)%n]==l){
  
    ct=ct+floodfill(r+dr[i],(c+dc[i]+n)%n); //as there is wrap around of first and last column as it a map
                                            //so if c==0 and we go west we reacha at last ans for last...
                                            //so we do (c+dc+n)%n
                                            //+n for c==0 ans we go left case                                                                           
}
    }
    return ct;
    
}

int main(){
    int t=10;
    while(cin>>m>>n){
    ans=0;
    //cin>>m>>n;
    char temp1,temp2;
    arr.assign(m,vector<char>(n,'0'));
    vis.assign(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
    cin>>arr[i][j];
    temp1=arr[0][0];
    if(arr[i][j]!=temp1)temp2=arr[i][j];
    }
    cin>>a>>b;
    l=arr[a][b];
    if(l==temp1)w=temp2; else w=temp1;
    //cout<<w<<endl;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {    sw=0;
     
        if((vis[i][j])||arr[i][j]==w)continue;
       // cout<<arr[i][j]<<endl;
        int cnt=floodfill(i,j);
       
        if(sw!=1&&ans<cnt)ans=cnt;
        
    }
     //in terminal below you can run code
    
     cout<<ans<<endl;
}
    return 0;
}
