#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int n,m;
vector<vector<int>>map;
vector<vector<int>>tmap;
vector<vector<int>>visit;
vector<pair<int,int>>con;
vector<pair<int,int>>people;
int curtime=0;
int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};

void bfs(int py,int px){
    
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    queue<pair<int,int>>q;
    q.push(make_pair(py,px));
    visit[py][px]=1;

    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        for(int d=0;d<4;d++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(!range(ny,nx))continue;
            if(visit[ny][nx]!=0)continue;
            if(map[ny][nx]==2)continue;
            visit[ny][nx]=visit[y][x]+1;
            q.push(make_pair(ny,nx));

        }
    }
    return;



}

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<visit[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
    return;
}


void sol(){
    for(int i=1;i<=m;i++){
        int py,px;
        tie(py,px)=people[i];

        int cy,cx;
        tie(cy,cx)=con[i];

        if(py==-1&&px==-1)continue;
        if(people[i]==con[i])continue;

        
        bfs(cy,cx);
        //pr();
        //cout<<i<<" "<<py<<" "<<px<<"\n";
        int mmin=987654321;
        int ansy=-1;
        int ansx=-1;

        for(int d=0;d<4;d++){
            int ny=py+dy[d];
            int nx=px+dx[d];
            if(!range(ny,nx))continue;
            if(map[ny][nx]==2)continue;
            if(mmin>visit[ny][nx]){
                mmin=visit[ny][nx];
                ansy=ny;
                ansx=nx;
            }
        }
        //cout<<"next"<<ansy<<" "<<ansx<<"\n";

        people[i]=make_pair(ansy,ansx);

    }

    for(int i=1;i<=m;i++){
        if(people[i]==con[i]){
            int py, px;
            tie(py, px) = people[i];
            map[py][px]=2;
        }
    }

    int mmin=987654321;
    int ansy=-1;
    int ansx=-1;
    if(curtime>m)return;
    int py,px;
    tie(py,px)=con[curtime];
    bfs(py,px);

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=n; j++) {
            if(visit[i][j] && map[i][j] == 1 && mmin > visit[i][j]) {
                mmin= visit[i][j];
                ansy= i; ansx = j;
            }
        }
    }

    people[curtime]=make_pair(ansy,ansx);
    map[ansy][ansx]=2;
    
    return;

}

int check(){
    for(int i=1;i<=m;i++){
        if(people[i]!=con[i]){
            return 0;
        }
    }
    return 1;
}

void prs(){
    tmap=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        int y,x;
        tie(y,x)=people[i];
        if(y==-1)continue;
        tmap[y][x]=i;

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<tmap[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
    return;
}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    tmap=vector<vector<int>>(n+1,vector<int>(n+1));
    con=vector<pair<int,int>>(m+1);
    people=vector<pair<int,int>>(m+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=m;i++){
        int y,x;
        cin>>y>>x;
        con[i]=make_pair(y,x);
    }   
    for(int i=1;i<=m;i++){
        people[i]=make_pair(-1,-1);
    } 
    
    while(1){
        curtime++;
        sol();
        //prs();
        if(check())break;
    }
    cout<<curtime<<'\n';


}