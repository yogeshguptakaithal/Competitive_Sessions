#include<bits/stdc++.h>
#include <fstream> //for debugging in vs code so that output writes in a different file
using namespace std;
 int m,n,a,b,sw,ans;
vector<vector<char>>arr;
vector<vector<int>>vis;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
void floodfill(int r, int c){
       
    vis[r][c]=1;                      //also we can do ki arr[r][c] ko hi change krden to show vis
    if(arr[r][c]=='x'){sw=1;}
    int ct=1;
    for(int i=0;i<4;i++){
    
if(r+dr[i]>=0&&r+dr[i]<n&&c+dc[i]>=0&&c+dc[i]<n&&!vis[r+dr[i]][c+dc[i]]&&arr[r+dr[i]][c+dc[i]]!='.'){
  
    floodfill(r+dr[i],(c+dc[i]+n)%n);                                                                           
}
    }
    return ;
    
}

int main(){
    ofstream myfile;

    int t,tt;
    cin>>t;
    tt=t;
    myfile.open ("output.txt");
    while(t--){
     cin>>n;
    ans=0;
    
    arr.assign(n,vector<char>(n,'0'));
    vis.assign(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
    cin>>arr[i][j];
    
    }
   
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {    sw=0;
     
        if((vis[i][j])||arr[i][j]=='.')continue;
     floodfill(i,j);
        if(sw==1)ans++;
        
    }
     //in terminal below you can run code
     
     myfile<<"Case "<<tt-t<<": "<<ans<<endl;
}
    myfile.close();

    return 0;
}
