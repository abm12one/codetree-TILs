#include <iostream>
#include <vector>

using namespace std;
int n;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int ans=0;
vector<vector<int>>map;

int range(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}

void sol(int y,int x){
    int num=0;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        if(map[ny][nx]==1)num++;
    }
    if(num>=3){
        ans++;
    }
    return;


}

int main() {


    
    cin>>n;

    map=vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sol(i,j);
        }
    }
    cout<<ans<<'\n';


    
}