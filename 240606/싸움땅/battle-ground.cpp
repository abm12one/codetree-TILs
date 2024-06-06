#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n,m,k;
vector<vector<vector<int>>>map;
vector<vector<int>>pmap;
vector<int>gun;
vector<int>sp;
vector<int>score;
vector<int>temp;
vector<tuple<int,int,int>>player;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){

    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;

}

void sett(){

    pmap=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        int y,x,d;
        tie(y,x,d)=player[i];
        pmap[y][x]=i;
    }
    return;

}

void getgun(int p,int y,int x){
    
    //cout<<"getgun"<<'\n';
    //cout<<y<<" "<<x<<'\n';
    int nowgun=gun[p];
    //cout<<nowgun<<'\n';
    if(map[y][x].size()==0)return;

    temp=vector<int>();
    
    int mmax=0;
    for(int i=0;i<map[y][x].size();i++){
        mmax=max(mmax,map[y][x][i]);
    }

    if(nowgun>=mmax)return;
    int f=0;
    for(int i=0;i<map[y][x].size();i++){
        if(f==0&&map[y][x][i]==mmax){
            f=1;
            continue;
        }
        temp.push_back(map[y][x][i]);
        //cout<<map[y][x][i]<<' ';
    }
    //cout<<'\n';

    if(nowgun!=0){
        temp.push_back(nowgun);
    }
    
    gun[p]=mmax;
    map[y][x]=temp;
    return;


}

void win(int y,int x,int a,int b){
    //cout<<a<<"win"<<'\n';
    pmap[y][x]=a;

    int nowgun=gun[b];
    if(nowgun!=0){
        map[y][x].push_back(nowgun);
    }
    gun[b]=0;
    getgun(a,y,x);
    int by,bx,d;
    tie(by,bx,d)=player[b];

    for(int k=0;k<4;k++){
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(!range(ny,nx)){
            d=(d+1)%4;
            continue;
        }
        if(pmap[ny][nx]!=0){
            d=(d+1)%4;
            continue; 
        }
        pmap[ny][nx]=b;
        player[b]=make_tuple(ny,nx,d);
        getgun(b,ny,nx);
        break;
    }
    return;


}

void fight(int y,int x,int a,int b){
    //cout<<"fight"<<'\n';
    int ap=gun[a]+sp[a];
    int bp=gun[b]+sp[b];
    //cout<<ap<<"         "<<bp<<'\n';
    if(ap>bp){
        win(y,x,a,b);
        score[a]+=ap-bp;
    }
    else if(bp>ap){
        win(y,x,b,a);
        score[b]+=bp-ap;
    }
    else{
        if(sp[a]>sp[b]){
            win(y,x,a,b);
            score[a]+=ap-bp;
        }
        else if(sp[b]>sp[a]){
            win(y,x,b,a);
            score[b]+=bp-ap;
        }
    }
    return;

}

void moveall(){
    
    for(int i=1;i<=m;i++){
        //cout<<i<<"player"<<' ';
        int y,x,d;
        tie(y,x,d)=player[i];
        int ny=y+dy[d];
        int nx=x+dx[d];

        if(!range(ny,nx)){
            d=(d+6)%4;
            ny=y+dy[d];
            nx=x+dx[d];
        }

        player[i]=make_tuple(ny,nx,d);
        
        if(pmap[ny][nx]==0){
            getgun(i,ny,nx);
            pmap[y][x]=0;
            pmap[ny][nx]=i;
        }

        else{
            pmap[y][x]=0;
            fight(ny,nx,i,pmap[ny][nx]);
        }
        

    }

}

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j].size()==0){
                cout<<"-1"<<' ';
                continue;
            }
            cout<<map[i][j][0]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void pr2(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<pmap[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void pr3(){
    for(int i=1;i<=m;i++){
        cout<<gun[i]<<' ';
    }
    cout<<'\n';
    cout<<'\n';
    for(int i=1;i<=m;i++){
        cout<<score[i]<<' ';
    }
    cout<<'\n';
    cout<<'\n';
    return;
}

int main() {
    
    cin>>n>>m>>k;
    map=vector<vector<vector<int>>>(n+1,vector<vector<int>>(n+1,vector<int>()));
    gun=vector<int>(m+1);
    sp=vector<int>(m+1);
    player=vector<tuple<int,int,int>>(m+1);
    score=vector<int>(m+1);
    pmap=vector<vector<int>>(n,vector<int>(n));


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int temp;
            cin>>temp;
            if(temp==0)continue;
            map[i][j].push_back(temp);
        }
    }

    for(int i=1;i<=m;i++){
        int y,x,d;
        cin>>y>>x>>d>>sp[i];
        player[i]=make_tuple(y,x,d);
    }
    
    for(int i=1;i<=k;i++){
        sett();
        moveall();
        //pr();
        //pr2();
        //pr3();
    }
    
    for(int i=1;i<=m;i++){
        cout<<score[i]<<' ';
    }
    

}