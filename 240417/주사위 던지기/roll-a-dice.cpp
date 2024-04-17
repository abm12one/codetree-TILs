#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<int>>map;

int n,m,r,c;
int y,x;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

tuple<int,int,int> state;

int range(int y,int x){

    if(y<0||y>n)return 0;
    if(x<0||x>n)return 0;
    return 1;

}
int ans=0;
void simulate(int d){
    
    int ny=y+dy[d];
    int nx=x+dx[d];

    if(!range(ny,nx)){
        return;
    }

    int u,f,r;
    tie(u,f,r)=state;

    if(d==0){
        state=make_tuple(f,7-u,r);
        map[ny][nx]=7-f;
        
    }
    else if(d==1){
        state=make_tuple(7-r,f,u);
        map[ny][nx]=r;
        
    }
    else if(d==2){
        state=make_tuple(7-f,u,r);
        map[ny][nx]=f;
        
    }
    else if(d==3){
        state=make_tuple(r,f,7-u);
        map[ny][nx]=7-r;
        
    }

    y=ny;
    x=nx;

}

int main() {
    
    cin>>n>>m;

    map=vector<vector<int>>(n+1,vector<int>(n+1));

    cin>>r>>c;
    y=r;
    x=c;
    map[r][c]=6;
    state=make_tuple(1,2,3);
    
    for(int i=0;i<m;i++){
        char c;
        cin>>c;
        if(c=='U'){
            simulate(0);
        }
        else if(c=='R'){
            simulate(1);
        }
        else if(c=='D'){
            simulate(2);
        }
        else if(c=='L'){
            simulate(3);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //cout<<map[i][j]<<' ';
            ans+=map[i][j];
        }
        //cout<<'\n';
    }
    //cout<<'\n';
    cout<<ans;
    
    
}