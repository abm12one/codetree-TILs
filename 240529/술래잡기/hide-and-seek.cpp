#include <iostream>
#include <vector>
#include <tuple>
int n,m,h,k;
vector<tuple<int,int,int>>thief
vector<tuple<int,int,int>>trees;
vector<vector<int>>tree;
vector<vector<int>>map;
vector<tuple<int,int,int>>path;

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

void setting(){
    int y=n/2;
    int x=n/2;
    int cnt=0;
    for(int i=1;i<=n;i++){
        
        if(cnt==2){
            cnt=0;
            break;
        }
        for(int j=0;j<i-1;j++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(!range(ny,nx))return;
            path.push_back(ny,nx,d);
            y=ny;
            x=dx;
        }
        d=(d+1)%4;
        int ny=y+dy[d];
        int nx=x+dx[d];
        path.push_back(ny,nx,d);
        cnt++;
    }
}

int main() {
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    tree=vector<vector<int>>(n+1,vector<int>(n+1));

    cin>>n>>m>>h>>k;
    
    for(int i=0;i<m;i++){
        int y,x,d;
        thief.push_back(make_tuple(y,x,d));
    }

    for(int i=0;i<h;i++){
        int y,x;
        trees.push_back(make_tuple(y,x));
    }

    setting();
    for(int i=0;i<path.size();i++){
        int y,x,d;
        tie(y,x,d)=path[i];
    }

}