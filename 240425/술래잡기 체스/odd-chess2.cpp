#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int score;
vector<tuple<int,int,int>>th(18);
vector<vector<int>>map;
vector<int>pos;
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
int dx[9]={0,0,-1,-1,-1,0,1,1,1};

int isrange(int y,int x){
    if(y<1||y>4)return 0;
    if(x<1||x>4)return 0;
    return 1;
}



int bt(vector<vector<int>>&map,vector<tuple<int,int,int>>&th){
    int ret=0;
    for(int i=1;i<=16;i++){
        int y,x,d;
        tie(y,x,d)=th[i];
        
        if(pos[i]==0)continue;
        int ny=0;
        int nx=0;
        while(1){
            ny=y+dy[d];
            nx=x+dx[d];
            
            if(!isrange(ny,nx)||map[ny][nx]==17){
                
                if(d==8)d=1;
                else{
                    d=d+1;
                }
                continue;
            }
            
            int temp=map[ny][nx];
            
            int a,b,c;
            tie(a,b,c)=th[temp];
            th[temp]=make_tuple(y,x,c);
            map[y][x]=temp;
            th[i]=make_tuple(ny,nx,d);
            map[ny][nx]=i;
    
            break;
            
            

        }

    }
    
    int cy,cx,cd;
    tie(cy,cx,cd)=th[17];
    int f=0;
    for(int i=1;i<=3;i++){

        int ny=cy+dy[cd]*i;
        int nx=cx+dy[cd]*i;
        if(!isrange(ny,nx)||map[ny][nx]==0)continue;
        f=1;
        int next=map[ny][nx];
        pos[next]=0;
        map[cy][cx]=0;
        map[ny][nx]=17;
        th[17]=make_tuple(ny,nx,cd);
        
        ret=max(ret,bt(map,th)+next);
        
        pos[next]=1;
        map[cy][cx]=17;
        map[ny][nx]=next;
        th[17]=make_tuple(cy,cx,cd);

    }
    if(f==0)return 0;
    
    /*
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            cout<<" "<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    */
    return ret;
    

}

int main() {
    map=vector<vector<int>>(5,vector<int>(5));
    pos=vector<int>(18,1);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            int p,d;
            cin>>p>>d;
            map[i][j]=p;
            th[p]=make_tuple(i,j,d); 
        }
    }
    th[17]=th[map[1][1]];
    pos[map[1][1]]=0;
    map[1][1]=17;
    score+=map[1][1];

    cout<<bt(map,th);

}