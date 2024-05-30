#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int n,m,h,k;
vector<tuple<int,int,int>>thief;
vector<tuple<int,int,int>>temp;
vector<vector<int>>tr;
vector<vector<int>>map;
vector<tuple<int,int,int>>path;
vector<tuple<int,int,int>>path2;

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int d=0;
void pr3(){
    for(int i=0;i<path.size();i++){
        int y,x,d;
        tie(y,x,d)=path[i];
        cout<<y<<" "<<x<<' '<<d<<"\n";
    }
    return;
}
void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void setting(){
    int y=n/2+1;
    int x=n/2+1;
    int cnt=0;
    int s=1;
    
    while(1){
        if(cnt==2){
            cnt=0;
            s++;
        }
        for(int j=0;j<s-1;j++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(!range(ny,nx))return;
            path.push_back(make_tuple(ny,nx,d));
            //cout<<cnt<<' '<<ny<<' '<<nx<<' '<<d<<"\n";
            y=ny;
            x=nx;
        }
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(!range(ny,nx))return;
        d=(d+1)%4;
        path.push_back(make_tuple(ny,nx,d));
        //cout<<cnt<<' '<<ny<<' '<<nx<<' '<<d<<"\n";
        y=ny;
        x=nx;
        cnt++;
    }
    
    return;
    
}

void setting2(){

    path.pop_back();
    path.push_back(make_tuple(1,1,2));
    int y=1;
    int x=1;
    int cnt=0;
    int s=n-1;
    int d=2;
    
    for(int j=0;j<n-2;j++){
        int ny=y+dy[d];
        int nx=x+dx[d];
        path.push_back(make_tuple(ny,nx,d));
        //cout<<cnt<<' '<<ny<<' '<<nx<<' '<<d<<"\n";
        y=ny;
        x=nx;
    }
    int ny=y+dy[d];
    int nx=x+dx[d];
    if(!range(ny,nx))return;
    d=(d+3)%4;
    path.push_back(make_tuple(ny,nx,d));
    //cout<<cnt<<' '<<ny<<' '<<nx<<' '<<d<<"\n";
    y=ny;
    x=nx;
    //cout<<y<<x<<'\n';

    
    while(1){
        if(cnt==2){
            cnt=0;
            s--;
        }
        for(int j=0;j<s-1;j++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            
            path.push_back(make_tuple(ny,nx,d));
            if(y==n/2+1&&x==n/2+1)return;
            //cout<<cnt<<' '<<ny<<' '<<nx<<' '<<d<<"\n";
            y=ny;
            x=nx;
        }
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(y==(n/2+1)&&x==(n/2+1))return;
        d=(d+3)%4;
        path.push_back(make_tuple(ny,nx,d));
        //cout<<cnt<<' '<<ny<<' '<<nx<<' '<<d<<"\n";
        y=ny;
        x=nx;
        cnt++;
    }
    
    

}
void sett(){
    path.push_back(make_tuple(n/2+1,n/2+1,0));
    setting();
    setting2();
    path.pop_back();
    
    return;
}

int dist(int cy,int cx,int y,int x){
    int dis=abs(cy-y)+abs(cx-x);
    return dis;
}

void move(int now){
    map=vector<vector<int>>(n+1,vector<int>(n+1,0));

    int cy,cx,cd;
    tie(cy,cx,cd)=path[now];
    //cout<<cy<<" "<<cx<<"\n";

    for(int i=0;i<thief.size();i++){
        int y,x,d;
        tie(y,x,d)=thief[i];
        //cout<<y<<' '<<x<<' '<<d<<'\n';
        if(dist(cy,cx,y,x)>3){
            map[y][x]++;
            thief[i]=make_tuple(y,x,d);
            continue;
        }
        int ny=y+dy[d];
        int nx=x+dx[d];
        
        if(!range(ny,nx)){
            d=(d+6)%4;
            ny=y+dy[d];
            nx=x+dx[d];
        }
        //cout<<ny<<" "<<nx<<'\n';
        if(ny==cy&&nx==cx){
            map[y][x]++;
            thief[i]=make_tuple(y,x,d);
            //cout<<y<<" "<<x<<" "<<d<<'\n';
            //cout<<'\n';
           
        }
        else{
            map[ny][nx]++;
            thief[i]=make_tuple(ny,nx,d);
            //cout<<ny<<" "<<nx<<" "<<d<<'\n';
            //cout<<'\n';   
        }
        
    }
    return;
}
int ans=0;
void seek(int turn,int now){
    int cy,cx,cd;
    tie(cy,cx,cd)=path[now];
    for(int i=0;i<3;i++){
        int ny=cy+dy[cd]*i;
        int nx=cx+dx[cd]*i;
        if(!range(ny,nx))continue;
        if(tr[ny][nx]==1)continue;
        ans+=turn*map[ny][nx];
        //cout<<turn<<" "<<ans<<'\n';
        map[ny][nx]=0;
        
    }
    return;


}
void erase(int now){
    temp=vector<tuple<int,int,int>>();
    for(int i=0;i<thief.size();i++){
        int y,x,d;
        tie(y,x,d)=thief[i];
        if(map[y][x]==0)continue;
        temp.push_back(make_tuple(y,x,d));

    }
    thief=temp;
    return;

}

void sol(int turn, int now){
    move(now);
    //pr();
    seek(turn,((now+1)%path.size()));
    //pr();
    erase((now+1)%path.size());
    return;
}

int main() {
    

    cin>>n>>m>>h>>k;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    tr=vector<vector<int>>(n+1,vector<int>(n+1));
    
    for(int i=0;i<m;i++){
        int y,x,d;
        cin>>y>>x>>d;
        thief.push_back(make_tuple(y,x,d));
    }

    for(int i=0;i<h;i++){
        int y,x;
        cin>>y>>x;
        tr[y][x]=1;
    }

    sett();
    
    for(int i=0;i<k;i++){
        int now=i%path.size();
        sol(i+1,now);
    }
    
    //pr3();
    
    cout<<ans;
    

}