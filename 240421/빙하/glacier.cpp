#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<vector<int>>map;
vector<vector<int>>water;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int cnt;
int range(int y, int x){
    if(y<1||y>n)return 0;
    if(x<1||x>m)return 0;
    return 1;
}

void setw(int y,int x){
    water[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        if(water[ny][nx]==0&&map[ny][nx]==0){
            setw(ny,nx);
        }
    }
    return;

}

void checkwater(){
    water=vector<vector<int>>(n+1,vector<int>(m+1));
    setw(1,1);
    return ;
}

int check(int y,int x){
    int ret=0;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(water[ny][nx]==1){
            return 1;
        }
    }
    return 0;
}

void melt(){
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]==1){
                if(check(i,j)==0)continue;
                map[i][j]=0;
                
                cnt++;
                
            }


        }
    }
    return;
}

int main() {

    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }

    
    int time=0;
    int ans=0;
    while(1){
        
        checkwater();
        melt();
        if(cnt==0)break;
        ans=cnt;
        time++;

    }
    cout<<time<<' '<<ans;

    
    
}