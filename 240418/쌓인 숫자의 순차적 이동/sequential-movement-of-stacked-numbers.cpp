#include <iostream>
#include <vector>

using namespace std;

int n,m;

vector<int>map[21][21];
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

void shift(int y,int x,int k){
    int ret=0;
    int my=-1;
    int mx=-1;
    for(int i=0;i<8;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        for(int k=0;k<map[ny][nx].size();k++){
            if(map[ny][nx][k]>ret){
                ret=map[ny][nx][k];
                my=ny;
                mx=nx;
            }
        }
    }
    if(my==-1&&mx==-1){
        return;
    }

    for(int i=k;i<map[y][x].size();i++){
        map[my][mx].push_back(map[y][x][i]);
    }


    int sz=map[y][x].size();
    for(int i=k;i<sz;i++){
        map[y][x].pop_back();
    }

    return;


}

void sol(int num){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<map[i][j].size();k++){
                if(map[i][j][k]==num){
                    shift(i,j,k);
                    return;
                }
            }
        }
    }

}

void pr(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j].size()==0){
                cout<<"None"<<'\n';
            }
            else{
                for(int k=map[i][j].size()-1;k>=0;k--){
                    cout<<map[i][j][k]<<' ';
                }
                cout<<'\n';
            }
        }
    }

}

int main(){
    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t;
            cin>>t;
            map[i][j].push_back(t);
        }
    }

    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        sol(t);
    }
    pr();




   

    
}