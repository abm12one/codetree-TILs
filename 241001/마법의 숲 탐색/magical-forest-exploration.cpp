#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int r,c,k;
vector<vector<int>>map;
vector<pair<int,int>>pnode;
vector<int>darr;
vector<int>mh;
vector<int>visit;


int canmoveleft(int y,int x){
    if(x-2<=0||y+2>r+2)return 0;
    if(map[y-1][x-1]!=0)return 0;
    if(map[y+1][x-1]!=0)return 0;
    if(map[y+2][x-1]!=0)return 0;
    if(map[y][x-2]!=0)return 0;
    if(map[y+1][x-2]!=0)return 0;
    return 1;

}

int canmoveright(int y,int x){
    
    if(x+2>c||y+2>r+2)return 0;
    if(map[y-1][x+1]!=0)return 0;
    if(map[y+1][x+1]!=0)return 0;
    if(map[y+2][x+1]!=0)return 0;
    if(map[y][x+2]!=0)return 0;
    if(map[y+1][x+2]!=0)return 0;
    return 1;

}

int put(int p,int d,int num){
    int ah=mh[p-1];
    int bh=mh[p];
    int ch=mh[p+1];
    int resh=min(ah,ch);
    int ty=0,tx=0;
    if(resh<bh){
        
        ty=resh-1;
        tx=p;
    }
    else if(bh<=resh){
        
        ty=bh-2;
        tx=p;
    }
   
    while(1){
       
        if(canmoveleft(ty,tx)){
            
            ty+=1;
            tx-=1;
            d=(d+3)%4;
            continue;
        }
        
        if(canmoveright(ty,tx)){
           
            ty+=1;
            tx+=1;
            d=(d+1)%4;
            continue;
        }
        
        break;

    }

    

    pnode[num]=make_pair(ty,tx);
    darr[num]=d;
    mh[tx-1]=ty;
    mh[tx]=ty-1;
    mh[tx+1]=ty;
    
    map[ty][tx]=num;
    map[ty+1][tx]=num;
    map[ty-1][tx]=num;
    map[ty][tx+1]=num;
    map[ty][tx-1]=num;


    
    if(ty-1<=2)return 0;
    return 1;
    
    

}

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ret=0;

int range(int y,int x){
    if(y<=0||y>r+2)return 0;
    if(x<=0||x>c)return 0;
    return 1;
}

void dfs(int num){
    visit[num]=1;
    int nowy,nowx;
    tie(nowy,nowx)=pnode[num];
    ret=max(ret,nowy+1);
    int d=darr[num];
    nowy+=dy[d];
    nowx+=dx[d];

    for(int nd=0;nd<4;nd++){
        int nexty=nowy+dy[nd];
        int nextx=nowx+dx[nd];
        if(!range(nexty,nextx))continue;
        int nextdest=map[nexty][nextx];
        if(nextdest==0)continue;
        if(visit[nextdest]==1)continue;
        dfs(nextdest);
    }
    return;
    

}


void pmap(){
    for(int i=1;i<=r+2;i++){
        for(int j=1;j<=c;j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main() {
    int ans=0;
    cin>>r>>c>>k;
    map=vector<vector<int>>(r+3,vector<int>(c+1,0));
    mh=vector<int>(c+1,r+3);
    pnode=vector<pair<int,int>>(k+1);
    visit=vector<int>(k+1,0);
    darr=vector<int>(k+1);

    for(int i=0;i<k;i++){
        //cout<<"#"<<i+1<<"\n";
        int pos,d;
        cin>>pos>>d;
        
        if(put(pos,d,i+1)==0){
            //cout<<"fail"<<"\n";
            map=vector<vector<int>>(r+3,vector<int>(c+1,0));
            mh=vector<int>(c+1,r+3);
            continue;
        }
        /*
        int qy,qx;
        tie(qy,qx)=pnode[i+1];
        cout<<"fin "<<i+1<<" "<<qy<<" "<<qx<<" "<<darr[i+1]<<"\n";
        pmap();
        */
        
        ret=0;
        visit=vector<int>(k+1,0);
        dfs(i+1);
        //cout<<ret-2<<'\n';
        ans+=ret-2;
       
    }
    
    cout<<ans<<'\n';

}