#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int n,k,m;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<pair<int,int>>arr;
int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}


int ans=0;
int ret;
void sol(){
    
    for(int t=0;t<arr.size();t++){
        ret=0;
        queue<pair<int,int>>q;
        visit=vector<vector<int>>(n+1,vector<int>(n+1));
        int r,c;
        tie(r,c)=arr[t];
        visit[r][c]=1;
        ret++;
        q.push(make_pair(r,c));
        while(!q.empty()){
            int y,x;
            tie(y,x)=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ny=y+dy[i];
                int nx=x+dx[i];
                if(!range(ny,nx))continue;
                if(visit[ny][nx]==0&&map[ny][nx]==0){
                    visit[ny][nx]=1;
                    q.push(make_pair(ny,nx));
                    ret++;
                }
            }
            
        }
        //cout<<ret<<'\n';
        
        ans=max(ans,ret);
    }
    //cout<<'\n';
    
    return ;

}

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    return;
}
int cnt=1;
void bt(int y,int x,int num){
    //cout<<y<<' '<<x<<"\n";
    if(num==m){
    
        //pr();
        sol();

        return;
    }
    for(int i=y;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==y&&j<=x)continue;
            if(map[i][j]==1){
                map[i][j]=0;
                bt(i,j,num+1);
                map[i][j]=1;

            }
        }
    }
    return;


}

int main() {

    
    cin>>n>>k>>m;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<k;i++){
        int y,x;
        cin>>y>>x;
        arr.push_back(make_pair(y,x));
    }
    int f=0;
    bt(0,0,0);
    cout<<ans;
    


}