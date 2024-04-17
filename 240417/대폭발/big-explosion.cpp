#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

vector<vector<int>>map;
vector<vector<int>>temp;

int n,m,r,c;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;

}

void bomb(int t){
    temp=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            temp[i][j]=map[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==1){
                for(int k=0;k<4;k++){
                    int ny=i+(dy[k]*pow(2,t-1));
                    int nx=j+(dx[k]*pow(2,t-1));
                    if(!range(ny,nx))continue;
                    temp[ny][nx]=1;

                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=temp[i][j];

        }
       
    }
    
    


    return ;
}

int main() {
    
    cin>>n>>m>>r>>c;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    

    map[r][c]=1;

    for(int t=1;t<=m;t++){
        bomb(t);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==1)ans++;
        }
    }
    cout<<ans;
    
    
    
    
}