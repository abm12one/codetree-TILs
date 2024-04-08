#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>ans;
int n,m;
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};

int range(int y,int x){
    if(x<0||x>=m)return 0;
    if(y<0||y>=n)return 0;
    return 1;

}

int main() {

    cin>>n;

    map=vector<vector<int>>(n,vector<int>(n));

    int y=(n-1)/2;
    int x=(n-1)/2;
    map[(n-1)/2][(n-1)/2]=1;

    int d=0;
    int num=1;


    while(1){
        if(map[y][x]==n*n)break;
        
        for(int j=0;j<num;j++){
            if(map[y][x]==n*n)break;
            int ny=y+dy[d];
            int nx=x+dx[d];
            map[ny][nx]=map[y][x]+1;
            y=ny;
            x=nx;
        }
        if(map[y][x]==n*n)break;
        

        d=(d+1)%4;
        if(d==0||d==2){
            num++;
        }
        

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            

            cout<<map[i][j]<<' ';
        }
        cout<<'\n';

    }

    

 
    
}