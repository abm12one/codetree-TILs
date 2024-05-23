#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

using namespace std;
int n,m;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<vector<int>>temp;
queue<pair<int,int>>q;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    return 0 <= x && x < n && 0 <= y && y < n;
}
void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
pair<int,int> bfs(int y,int x,int now){
    
    int cnt=0;
    int red=0;
    visit=vector<vector<int>>(n,vector<int>(n,0));
    
    q.push(make_pair(y,x));
    visit[y][x]=1;
    cnt++;

    while(!q.empty()){
        int nowy,nowx;
        tie(nowy,nowx)=q.front();
        //cout<<nowy<<' '<<nowx<<'\n';
        q.pop();
        for(int i=0;i<4;i++){
            int ny=nowy+dy[i];
            int nx=nowx+dx[i];
            if(!range(ny,nx))continue;
            if(visit[ny][nx]==1)continue;
            if(map[ny][nx]==0||map[ny][nx]==now){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=1;
                cnt++;
                if(map[ny][nx]==0){
                    red++;
                }
            }
        }

    }
    
    return make_pair(cnt,red);

}

void remove(int y,int x,int now){
    
    visit=vector<vector<int>>(n,vector<int>(n));
    queue<pair<int,int>>q;
    q.push(make_pair(y,x));
    visit[y][x]=1;
    while(!q.empty()){
        int nowy,nowx;
        tie(nowy,nowx)=q.front();
        map[nowy][nowx]=-2;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=nowy+dy[i];
            int nx=nowx+dx[i];
            if(!range(ny,nx))continue;
            if(visit[ny][nx]==0&&map[ny][nx]==0||map[ny][nx]==now){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=1;
                
            }
        }

    }
    return ;



}

void rotate(){
    /*
    temp=vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=map[i][j];
        }
    }
    */
    temp=map;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[n-1-j][i]=map[i][j];
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=temp[i][j];
        }
    }
    */
    map=temp;
    return ;
}


void down(){
    temp=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=-2;
        }
    }
    int now=0;
    for(int i=0;i<n;i++){
        now=n-1;
        for(int j=n-1;j>=0;j--){
            if(map[j][i]==-2)continue;
            else if(map[j][i]==-1){
                temp[j][i]=map[j][i];
                now=j-1;
            }
            else if(map[j][i]>=0){
                temp[now][i]=map[j][i];
                now--;
            }
        }
    }
    map=temp;
    return;
}

int sol(){
    int c=0;
    int r=-1;
    int y=-1;
    int x=-1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(map[i][j]>=1){
                int cnt=0,red=0;
                tie(cnt,red)=bfs(i,j,map[i][j]);
                //cout<<i<<' '<<j<<' '<<cnt<<' '<<red<<"\n";
                if(cnt<2)continue;

                if(cnt>c){
                    c=cnt;
                    r=red;
                    y=i;
                    x=j;
                }
                else if(cnt==c){
                    if(red<r){
                        c=cnt;
                        r=red;
                        y=i;
                        x=j;
                    }
                }
            }
        }
    }

    
    if(y==-1){
        return 0;
    }
    
    remove(y,x,map[y][x]);
    //pr();
    down();
    //pr();
    rotate();
    //pr();
    down();
    //pr();
    return c*c;
    
}

int main() {
    
    int ans=0;
    cin>>n>>m;
    map=vector<vector<int>>(n,vector<int>(n));
    visit=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    
    

 
    while(1){
        int score=sol();
        if(score==0)break;
        ans+=score;
    }

    cout<<ans;


}