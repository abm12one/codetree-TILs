#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

set<pair<int,int>>point;
int n;
vector<pair<int,int>>marvel;
vector<int>weight;
vector<int>dir;
vector<int>pos;
vector<vector<vector<pair<int,int>>>>temp;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int direct(char d){
    if(d=='U')return 0;
    else if(d=='R')return 1;
    else if(d=='D')return 2;
    else if(d=='L')return 3;

}

void shift(int y,int x,int id){
    
    int ny=y+dy[dir[id]];
    int nx=x+dx[dir[id]];
    marvel[id]=make_pair(ny,nx);

}
int ans=-1;

void sol(int time){
    
    for(int i=1;i<=n;i++){
        int y,x;
        tie(y,x)=marvel[i];
        if(pos[i]==0)continue;
        shift(y,x,i);
    }

    vector<pair<int,int>>arr;
    for(int i=1;i<=n;i++){
        int y,x;
        tie(y,x)=marvel[i];
        if(pos[i]==0)continue;
        arr.push_back(make_pair(weight[i],i));
    }
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    
    set<pair<int,int>>point;

    for(int i=0;i<arr.size();i++){
        int w,id;
        tie(w,id)=arr[i];
        int y,x;
        tie(y,x)=marvel[id];
        if(point.find(make_pair(y,x))!=point.end()){
            pos[i]=0; 
            marvel[id]=make_pair(y,x);
            ans=time;
        }
        else{
            point.insert(make_pair(y,x));
        }

    }

    return;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        ans=-1;
        marvel.clear();
        cin>>n;
        marvel.push_back(make_pair(0,0));
        weight=vector<int>(n+1);
        dir=vector<int>(n+1);
        pos=vector<int>(n+1,1);
        pos[0]=0;

        for(int i=1;i<=n;i++){
            int y,x;
            char d;
            cin>>x>>y>>weight[i]>>d;
            dir[i]=direct(d);
            marvel.push_back(make_pair(-y*2,2*x));
        
        }

        for(int i=1;i<=4000;i++){
            sol(i);
        }
        
        cout<<ans<<"\n";
        

    }





    
}