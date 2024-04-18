#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>temp;
vector<vector<int>>temp2;
int n,m,t;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;

}

void simul(int y,int x){
    
    int ret=0;
    int my=0;
    int mx=0;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        if(map[ny][nx]>ret){
            ret=map[ny][nx];
            my=ny;
            mx=nx;
        }

    }
    temp2[my][mx]++;
}

void sol(){
    temp2=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(temp[i][j]==0)continue;
            
            simul(i,j);
                      
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(temp2[i][j]>1){
                temp[i][j]=0;
            }      
            else{
                temp[i][j]=temp2[i][j];
            }      
        }
    }
}

int main() {
    
    cin>>n>>m>>t;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    temp=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;i++){
        int r,c;
        cin>>r>>c;
        temp[r][c]=1;
    }

    while(t--){
        sol();
        
       
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(temp[i][j]==1){
                ans++;
            }
        }
    }
        
    cout<<ans<<'\n';
    
}