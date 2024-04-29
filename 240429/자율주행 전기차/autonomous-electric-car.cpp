#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int n,m,c;
vector<vector<int>>map;
pair<int,int>car;
vector<pair<int,int>>passenger;
vector<pair<int,int>>dest;
vector<int>exist;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

int isrange(int y,int x){
    if(x<1||x>n)return 0;
    if(y<1||y>n)return 0;
    return 1;
}
/*
pair<int,int> find(int cy,int cx){
    queue<tuple<int,int,int>>q;
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        if(exist[i]==0)continue;
        int y,x;
        tie(y,x)=passenger[i];
        q.push(make_pair(y,x,i));
        visit[y][x]=1;
    }

    while(!q.empty()){
        int y,x,id;
        tie(y,x,id)=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(isrange(ny,nx))continue;
            if(visit[ny][nx]==0&&map[ny][nx]==0){
                visit[ny][nx]=visit[y][x]+1;
                if(ny==cy&&nx==cx){
                    exist[id]=0;
                    return make_pair(id,visit[cy][cx]-1);
                }

            }

        }


    }


}
*/
int bfs(int id){
    queue<pair<int,int>>q;
    vector<vector<int>>visit(n+1,vector<int>(n+1));
    int sy,sx,desty,destx;
    tie(sy,sx)=passenger[id];
    visit[sy][sx]=1;
    tie(desty,destx)=dest[id];
    q.push(make_pair(sy,sx));
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isrange(ny,nx))continue;
            if(visit[ny][nx]==0&&map[ny][nx]==0){
                visit[ny][nx]=visit[y][x]+1;
                q.push(make_pair(ny,nx));
                if(ny==desty&&nx==destx){
                    return visit[ny][nx]-1;
                }

            }
        }

    }
    return 0;
}

pair<int,int> find(int cy,int cx){
    
    int ret;
    int ans=0;
    ret=987654321;

    queue<pair<int,int>>q;
    vector<vector<int>>visit(n+1,vector<int>(n+1));
    vector<vector<int>>temp(n+1,vector<int>(n+1));

    for(int i=1;i<=m;i++){
        if(exist[i]==0)continue;
        int y,x;
        tie(y,x)=passenger[i];
        temp[y][x]=i;
    }

    q.push(make_pair(cy,cx));
    
    visit[cy][cx]=1;

    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isrange(ny,nx))continue;
            if(visit[ny][nx]==0&&map[ny][nx]==0){
                visit[ny][nx]=visit[y][x]+1;
                q.push(make_pair(ny,nx));

            }

        }

    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(temp[i][j]==0)continue;
            if(visit[i][j]<ret){
                ret=visit[i][j];
                ans=temp[i][j];
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<visit[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    */
    exist[ans]=0;
    return make_pair(ans,ret-1);


}




int flag=0;
void sol(){
    int cary,carx;
    tie(cary,carx)=car;
    
    int pid=0,oil=0;
    tie(pid,oil)=find(cary,carx);
    //cout<<pid<<" "<<oil<<'\n';
    
    c-=oil;
    //cout<<c<<"\n";
    int useoil=bfs(pid);
    if(useoil>c){
        flag=1;
    }
    else{
        c+=useoil;
    }
    //cout<<c<<"\n";
    //cout<<"\n";
    
    int py,px;
    tie(py,px)=dest[pid];
    car=make_pair(py,px);
    return;
    

}

int main() {
    
    cin>>n>>m>>c;

    map=vector<vector<int>>(n+1,vector<int>(n+1));
    passenger=vector<pair<int,int>>(m+1);
    dest=vector<pair<int,int>>(m+1);
    exist=vector<int>(m+1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    int y,x;
    cin>>y>>x;
    car=make_pair(y,x);

    for(int i=1;i<=m;i++){
        int sy,sx,desty,destx;
        cin>>sy>>sx>>desty>>destx;
        passenger[i]=make_pair(sy,sx);
        dest[i]=make_pair(desty,destx);
    }
    
    
    for(int i=1;i<=m;i++){
        sol();
        if(flag==1){
            cout<<-1;
            return 0;
        }
    }
    
    cout<<c;




}