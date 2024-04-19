#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n,k;

vector<vector<int>>map;
vector<vector<int>>visit;
int sy,sx;
int fy,fx;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

void find(){

    int temp=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]>=map[sy][sx])continue;
            if(map[i][j]>temp){
                temp=map[i][j];
                fy=i;
                fx=j;
            }
        }
    }


}

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}
int ty;
int tx;
void bfs(int r,int c){
    int temp=-1;
    ty=-1;
    tx=-1;
    queue<pair<int,int>>q;
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    q.push(make_pair(r,c));
    visit[r][c]=1;
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!range(ny,nx))continue;
            if((map[ny][nx]<map[r][c])&&(visit[ny][nx]==0)){
                visit[ny][nx]=1;
                q.push(make_pair(ny,nx));
                //cout<<temp<<" "<<map[ny][nx]<<" "<<ny<<" "<<nx<<'\n';
                if(map[ny][nx]>temp){
                    temp=map[ny][nx];
                    ty=ny;
                    tx=nx;
                    //cout<<temp<<' '<<ty<<" "<<tx<<"\n";
                }
                if(map[ny][nx]==temp){
                    if(ny<ty){
                        ty=ny;
                        tx=nx;
                        //cout<<temp<<' '<<ny<<" "<<nx<<"\n";
                    }
                    else if(ny==ty){
                        if(nx<tx){
                            ty=ny;
                            tx=nx;
                            //cout<<temp<<' '<<ny<<" "<<nx<<"\n";
                        }
                    }
                }

            }

        }
    }
    fy=ty;
    fx=tx;
    return;

}

int main() {

    
    cin>>n>>k;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    
    
    cin>>sy>>sx;
    for(int t=1;t<=k;t++){
        
        //cout<<sy<<' '<<sx<<'\n';
        bfs(sy,sx);
        if(ty==-1&&tx==-1){
            break;
        }
        else{
            sy=fy;
            sx=fx;
        }
        

    }
    cout<<sy<<' '<<sx;


    


}