#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;

int n,m;

int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void simul(int y,int x){
    int ret=0;
    int my=-1;
    int mx=-1;
    for(int i=0;i<8;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        if(map[ny][nx]>ret){
            ret=map[ny][nx];
            my=ny;
            mx=nx;
        }
    }
    

    int temp=map[y][x];
    map[y][x]=map[my][mx];
    map[my][mx]=temp;
    //pr();
    return;

}

void sol(int num){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==num){
                simul(i,j);
                return;
            }
        }
    }

}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    while(m--){
        for(int i=1;i<=n*n;i++){
            sol(i);
        }        
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }

    
}