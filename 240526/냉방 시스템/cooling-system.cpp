#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int n,m,k;
vector<vector<int>>map;
vector<vector<int>>cold;
vector<vector<int>>temp;
vector<vector<int>>wall;
vector<pair<int,int>>office;
vector<tuple<int,int,int>>aircon;

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<cold[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
    return;
}

int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};

int range(int y,int x){
    if(x<1||x>n)return 0;
    if(y<1||y>n)return 0;
    return 1;
}

void dfs(int y,int x,int d,int c){
    if(!range(y,x))return;
    if(c==0)return;
    if(temp[y][x]!=0)return;
    temp[y][x]+=c;
    if(d==0){
        if(wall[y][x]!=1&&wall[y][x]!=3&&wall[y-1][x]!=2&&wall[y-1][x]!=3){
            dfs(y-1,x-1,d,c-1);
        }
        if(wall[y][x]!=2&&wall[y][x]!=3){
            dfs(y,x-1,d,c-1);
        }
        if(wall[y+1][x]!=1&&wall[y+1][x]!=3&&wall[y+1][x]!=2&&wall[y+1][x]!=3){
            dfs(y+1,x-1,d,c-1);
        }
    }

    else if(d==2){
        if(wall[y][x]!=1&&wall[y][x]!=3&&wall[y-1][x+1]!=2&&wall[y-1][x+1]!=3){
            dfs(y-1,x+1,d,c-1);
        }
        if(wall[y][x+1]!=2&&wall[y][x+1]!=3){
            dfs(y,x+1,d,c-1);
        }
        if(wall[y+1][x]!=1&&wall[y+1][x]!=3&&wall[y+1][x+1]!=2&&wall[y+1][x+1]!=3){
            dfs(y+1,x+1,d,c-1);
        }
    }

    else if(d==1){
        if(wall[y][x-1]!=1&&wall[y][x-1]!=3&&wall[y][x]!=2&&wall[y][x]!=3){
            dfs(y-1,x-1,d,c-1);
        }
        if(wall[y][x]!=1&&wall[y][x]!=3){
            dfs(y-1,x,d,c-1);
        }
        if(wall[y][x+1]!=1&&wall[y][x+1]!=3&&wall[y][x+1]!=2&&wall[y][x+1]!=3){
            dfs(y-1,x+1,d,c-1);
        }
    }

    else if(d==3){
        if(wall[y+1][x-1]!=1&&wall[y+1][x-1]!=3&&wall[y][x]!=2&&wall[y][x]!=3){
            dfs(y+1,x-1,d,c-1);
        }
        if(wall[y+1][x]!=1&&wall[y+1][x]!=3){
            dfs(y+1,x,d,c-1);
        }
        if(wall[y+1][x+1]!=1&&wall[y+1][x+1]!=3&&wall[y][x+1]!=2&&wall[y][x+1]!=3){
            dfs(y+1,x+1,d,c-1);
        }
    }
    
}

void hap(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cold[i][j]+=temp[i][j];
        }
    }
    return;
}

void blow(){
    for(int i=0;i<aircon.size();i++){
        temp=vector<vector<int>>(n+1,vector<int>(n+1,0));
        int y,x,d;
        tie(y,x,d)=aircon[i];
        if(d-2==0){
            dfs(y,x-1,d-2,5);
        }
        else if(d-2==1){
            dfs(y-1,x,d-2,5);
        }
        else if(d-2==2){
            dfs(y,x+1,d-2,5);
        }
        else if(d-2==3){
            dfs(y+1,x,d-2,5);
        }
        hap();
        pr();
    }
}

void mix(){
    temp=vector<vector<int>>(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=2;k<4;k++){

                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                /*
                if(k==0){
                    if(wall[i][j]==2||wall[i][j]==3){
                        continue;
                    }
                }
                else if(k==1){
                    if(wall[i][j]==1||wall[i][j]==3){
                        continue;
                    }
                }
                */
                if(k==2){
                    if(wall[i][j+1]==2||wall[i][j+1]==3){
                        continue;
                    }
                }
                else if(k==3){
                    if(wall[i+1][j]==1||wall[i+1][j]==3){
                        continue;
                    }
                }

                int now=cold[i][j];
                int next=cold[ny][nx];
                int dif=now-next;
                //cout<<i<<' '<<j<<' '<<ny<<' '<<nx<<' '<<dif/4<<'\n';
                temp[i][j]-=(dif/4);
                temp[ny][nx]+=(dif/4);

            }
        }
    }
    hap();
    
    return;
}

void hot(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1||i==n||j==1||j==n){
                cold[i][j]--;
            }
        }
    }
}

void sol(){
    blow();
    //pr();
    mix();
    //pr();
    hot();
}
int check(){
    
    for(int i=0;i<office.size();i++){
        int y,x;
        tie(y,x)=office[i];
        if(cold[y][x]<k){
            return 0;
        }
    }
    return 1;
}
int main() {
    
    cin>>n>>m>>k;

    map=vector<vector<int>>(n+1,vector<int>(n+1));
    cold=vector<vector<int>>(n+1,vector<int>(n+1));
    wall=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                office.push_back(make_pair(i,j));
            }
            else if(map[i][j]>=2){
                aircon.push_back(make_tuple(i,j,map[i][j]));
            }
        }
    }
    for(int i=0;i<m;i++){
        int y,x,w;
        cin>>y>>x>>w;
        if(w==0){
            wall[y][x]+=1;
        }
        else if(w==1){
            wall[y][x]+=2;
        }
    }
    int ans=-1;
    for(int i=1;i<=100;i++){
        sol();
        if(check()){
            ans=i;
            break;
        }
    }
    cout<<ans;

    









}