#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>visit;
queue<pair<int,int>>q;
vector<vector<int>>temp;
int n;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<tuple<int,int,int>>group;
int range(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}
void bfs(int y,int x){

    q=queue<pair<int,int>>();
    q.push(make_pair(y,x));
    int cnt=0;
    visit[y][x]=1;
    cnt++;
    
    while(!q.empty()){

        int nowy,nowx;
        tie(nowy,nowx)=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ny=nowy+dy[k];
            int nx=nowx+dx[k];
            if(!range(ny,nx))continue;
            if(visit[ny][nx]==0&&map[ny][nx]==map[nowy][nowx]){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=1;
                cnt++;
            }
        }

    }

    group.push_back(make_tuple(y,x,cnt));
    return;

}

int calc(int a,int b){
    int ret=0;
    int ay,ax,ac;
    int by,bx,bc;
    tie(ay,ax,ac)=group[a];
    tie(by,bx,bc)=group[b];
    visit=vector<vector<int>>(n,vector<int>(n,0));
    
    

    q=queue<pair<int,int>>();
    q.push(make_pair(ay,ax));
    
    visit[ay][ax]=1;
    
    while(!q.empty()){

        int nowy,nowx;
        tie(nowy,nowx)=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int ny=nowy+dy[k];
            int nx=nowx+dx[k];
            if(!range(ny,nx))continue;
            if(visit[ny][nx]==0&&map[ny][nx]==map[nowy][nowx]){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=1;
                
            }
        }

    }

    

    q=queue<pair<int,int>>();
    q.push(make_pair(by,bx));
    visit[by][bx]=2;
    int cnt=0;

    while(!q.empty()){

        int nowy,nowx;
        tie(nowy,nowx)=q.front();
        //cout<<nowy<<" "<<nowx<<'\n';
        q.pop();
        for(int k=0;k<4;k++){
            int ny=nowy+dy[k];
            int nx=nowx+dx[k];
            if(!range(ny,nx))continue;
            if(visit[ny][nx]==1){
                //cout<<"check"<<nowy<<" "<<nowx<<' '<<ny<<" "<<nx<<'\n';
                cnt++;
            }
            else if(visit[ny][nx]==0&&map[ny][nx]==map[nowy][nowx]){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=2;
            }
            
        }

    }

    ret=(ac+bc)*map[ay][ax]*map[by][bx]*cnt;
    //cout<<ac<<' '<<bc<<' '<<map[ay][ax]<<' '<<map[by][bx]<<" "<<cnt<<'\n';
    //cout<<a<<' '<<b<<' '<<ret<<'\n';
    return ret;


}

int score(){
    int ret=0;
    for(int i=0;i<group.size();i++){
        for(int j=i+1;j<group.size();j++){
            ret+=calc(i,j);
        }
    }
    return ret;
}

void sett(){
    group=vector<tuple<int,int,int>>();
    visit=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==0){
                bfs(i,j);
            }
        }
    }
    return;
}

void rotate90(int sy,int sx,int size){
    
    temp=vector<vector<int>>(size,vector<int>(size));

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            int y=i+sy;
            int x=j+sx;
            temp[i][j]=map[y][x];
        }
    }

    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            map[j+sy][size-1-i+sx]=temp[i][j];
        }
    }

    
    return;

}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void rotate(){
    int cent=n/2;
    vector<int>cy;
    vector<int>cx;
    for(int i=0;i<n;i++){
        cy.push_back(map[cent][i]);
        cx.push_back(map[i][cent]);
    }
    for(int i=0;i<n;i++){
        map[cent][i]=cx[i];
        map[i][cent]=cy[n-i-1];
    }
    
    rotate90(0,0,n/2);
    rotate90(n/2+1,0,n/2);
    rotate90(0,n/2+1,n/2);
    rotate90(n/2+1,n/2+1,n/2);
    

    //pr();

    return;
}

int main() {
    
    cin>>n;
    map=vector<vector<int>>(n,vector<int>(n));
    visit=vector<vector<int>>(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<4;i++){
        sett();
        ans+=score();
        rotate();
        //cout<<ans<<'\n';
    }
    cout<<ans;
    

}