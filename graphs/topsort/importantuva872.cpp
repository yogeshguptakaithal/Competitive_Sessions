#include<bits/stdc++.h>
#include <fstream>
using namespace std;
map<char,vector<char>>adj; //as here size is one for adj list of eaach node
map<char,bool>vis;
vector<char>v,tp;
map<char,int>in,out;
int s=0;ofstream myfile;
vector<vector<char>>vv; int z;
 //count processed nodes

  //here we can have cycles also
  void tpsort(vector<char>tp,int ct,map<char,bool>vis,map<char,int>in){
     // cout<<ct;
      //if(ct>tp.size()){ myfile<<"NO"<<endl; return; }
     z=0;  
   for(char c:v){
     if(in[c]==0&&!vis[c]){
    tp.push_back(c);
    vis[c]=true;
    z=1;
     
     for(char x:adj[c]){
        // if(!vis[x])
         in[x]--;
     }
    
    tpsort(tp,ct+1,vis,in);
    //now restore;
    for(char x:adj[c]){
        //if(!vis[x])
         in[x]++;

     }
     tp.pop_back();

    vis[c]=false;
     }

   }
    if(tp.size()==v.size()){
        
          for(int i=0;i<tp.size();i++){myfile<<tp[i];
          if(i!=tp.size()-1)myfile<<" ";}
          myfile<<endl; z=1;
          return;
      }
     if(z==0&&tp.size()<v.size())
    { myfile<<"NO"<<endl; z=1; return; }
return;
  }


int main(){
    
    myfile.open ("output.txt");
    int t; char c='c'; 
    cin>>t;
    int tt=t;
    //for \n after t as we read getchar after it
    while(t--){
        string str="";
       //blank            //cin dont take spaces so whether char has spaces or not cin>>char takes 
    
    while (str.length()==0 ) 
            getline(cin, str); 
    
    for(char c:str){
        if(c!=' '&&c!='\n')v.push_back(c);
    }
    c='c';
    int sw=0; s=0;
    str="";
    while (str.length()==0 ) 
            getline(cin, str); 
    
    
    char a,b,d;
    for(char c:str){
        if(c=='<'||c==' '||c=='\n')continue;
        if(sw==0){
        a=c; sw=1; continue;
        }
        if(sw==1){
            b=c;
            adj[a].push_back(b); sw=0;
            in[b]++;
            out[a]++;
        }
    }
    sort(v.begin(),v.end());
  tp={};
    tpsort(tp,0,vis,in);



   
    if(t!=0)
    myfile<<endl;
    v.clear();    
    adj.clear();
    vis.clear();
    tp.clear();
    vv.clear();
    in.clear();
    out.clear();
    }
    myfile.close();
    return 0;
}