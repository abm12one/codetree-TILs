#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<pair<int,int>>arr;
vector<int>bomb;

int bcnt,n;
int dy[4][5]={
    {0,0,0,0,0},
    {-2,-1,1,2,0},
    {-1,0,1,0,0},
    {-1,1,1,-1,0}
};
int dx[4][5]={
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,1,0,-1,0},
    {-1,1,-1,1,0}
};

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}
int ans=0;
void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<visit[i][j]<<' ';
        }
        cout<<'\n';
    }
    
}

void check(){
    int cnt=0;
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=0;i<bcnt;i++){
        int y,x;
        tie(y,x)=arr[i];
        int bombid=bomb[i];
        for(int j=0;j<5;j++){
            int ny=y+dy[bombid][j];
            int nx=x+dx[bombid][j];
            if(!range(ny,nx))continue;
            visit[ny][nx]++;

        }
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visit[i][j]>0){
                cnt++;
            }
        }
    }
   // pr();
    //cout<<cnt<<'\n';
    //cout<<'\n';
    ans=max(ans,cnt);
    return ;

}



void bt(int num){
    if(num==bcnt){
        check();
        return;
    }
    
    for(int i=1;i<=3;i++){
        bomb[num]=i;
        bt(num+1);
        bomb[num]=0;
    }
    return;


}

int main() {
    cin>>n;

    map=vector<vector<int>>(n+1,vector<int>(n+1));
    bcnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                bcnt++;
                arr.push_back(make_pair(i,j));
            }
        }
    }
    bomb=vector<int>(bcnt);

    bt(0);
    cout<<ans;




    
    

}