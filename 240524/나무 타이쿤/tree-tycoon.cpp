#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int n,m;
int d,p;
int dy[9]={0,0,-1,-1,-1,0,1,1,1};
int dx[9]={0,1,1,0,-1,-1,-1,0,1};
vector<vector<int>>map;
vector<vector<int>>temp;
vector<pair<int,int>>med;
vector<vector<int>>visit;
int range(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<visit[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
void pr2(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
    
}

pair<int,int> nextpos(int y,int x){
    int nexty=y+dy[d]*p;
    int nextx=x+dx[d]*p;
    nexty+=n;
    nextx+=n;
    nexty%=n;
    nextx%=n;
    return make_pair(nexty,nextx);

}

void move(){
    temp=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==1){
                int ny,nx;    
                tie(ny,nx)=nextpos(i,j);
                //cout<<ny<<' '<<nx<<'\n';
                
                temp[ny][nx]=1;
                map[ny][nx]++;
            }
        }
    }
    visit=temp;
    /*
    cout<<"move"<<'\n';
    pr();
    pr2();
    */
    return;

}

void grow(){
    temp=map;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt=1;
            if(visit[i][j]==0)continue;
            for(int k=2;k<=8;k+=2){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(temp[ny][nx]>=1){
                    map[i][j]++;
                    
                }
                

            }

        }
    }
    /*
    cout<<"grow"<<'\n';
    pr();
    pr2();
    */
    
    return;

}

void cut(){
    //pr2();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==1){
                visit[i][j]=0;
            }
            else if(map[i][j]>=2){
                map[i][j]-=2;
                visit[i][j]=1;
            }
        }
    }
}

void sol(){
    move();
    grow();
    cut();


}


int main() {
    cin>>n>>m;
    map=vector<vector<int>>(n,vector<int>(n));
    visit=vector<vector<int>>(n,vector<int>(n));
    
    visit[n-1][0]=1;
    visit[n-1][1]=1;
    visit[n-2][0]=1;
    visit[n-2][1]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    

    for(int i=0;i<m;i++){
        cin>>d>>p;
        sol();
    }
    /*
    pr();
    pr2();
    */
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=map[i][j];
        }
    }

    cout<<ans<<'\n';

}