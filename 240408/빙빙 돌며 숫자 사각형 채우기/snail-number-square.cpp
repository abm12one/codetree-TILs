#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>ans;
int n,m;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int range(int y,int x){
    if(x<0||x>=m)return 0;
    if(y<0||y>=n)return 0;
    return 1;

}

int main() {

    cin>>n>>m;

    map=vector<vector<int>>(n,vector<int>(m));

    int y=0;
    int x=0;
    map[0][0]=1;

    int d=0;

    while(1){
        if(map[y][x]==n*m)break;
        int ny=y+dy[d];
        int nx=x+dx[d];

        if(!range(ny,nx)||map[ny][nx]!=0){
            d=(d+1)%4;
            continue;
        }

        map[ny][nx]=map[y][x]+1;
        
        y=ny;
        x=nx;
        

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';

    }

    

 
    
}