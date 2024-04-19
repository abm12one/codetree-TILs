#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
vector<vector<int>>map;
vector<vector<int>>temp;
vector<int>weight;
vector<int>dir;
int n,m,t;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<tuple<int,int,int>>marvel;
vector<tuple<int,int,int>>nmarvel;

int direct(char d){
    if(d=='U'){
        return 0;
    }
    else if(d=='R'){
        return 1;
    }
    else if(d=='D'){
        return 2;
    }
    else if(d=='L'){
        return 3;
    }

}

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}
int change(int d){
    if(d==0){
        return 2;
    }
    else if(d==1){
        return 3;
    }
    else if(d==2){
        return 0;
    }
    else if(d==3){
        return 1;
    }

}
void simul(){
    
    vector<tuple<int,int,int>>nmarvel;

    for(int i=0;i<marvel.size();i++){
        
        int y,x,id;
        tie(y,x,id)=marvel[i];
        
        int ny=y+dy[dir[id]];
        int nx=x+dx[dir[id]];

        if(!range(ny,nx)){
            int od=dir[id];
            dir[id]=change(od);
            ny=y;
            nx=x;
        }
        
        if(temp[ny][nx]==-1){
            nmarvel.push_back(make_tuple(ny,nx,id));
            temp[ny][nx]=nmarvel.size()-1;
        }

        else{
            int here=temp[ny][nx];
            int hy,hx,hid;
            tie(hy,hx,hid)=nmarvel[here];
            if(hid>id){
                weight[hid]+=weight[id];

            }
            else{
                weight[id]+=weight[hid];
                nmarvel[here]=make_tuple(ny,nx,id);
            }

        }
        
        


    }
    //cout<<nmarvel.size()<<"\n";
        
    marvel=nmarvel;

    for(int i=0;i<marvel.size();i++){
        int y,x,id;
        tie(y,x,id)=marvel[i];
        temp[y][x]=-1;
    }
    //cout<<marvel.size()<<"\n";
    return;

}

int main() {
    
    cin>>n>>m>>t;
    
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    temp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    weight=vector<int>(m+1);
    dir=vector<int>(m+1);

    for(int i=1;i<=m;i++){
        int y,x;
        char d;
        cin>>y>>x>>d>>weight[i];
        dir[i]=direct(d);
        marvel.push_back(make_tuple(y,x,i));
    }

    for(int i=0;i<t;i++){
        simul();
    }
    int ans=0;
    cout<<marvel.size()<<" ";
    for(int i=0;i<marvel.size();i++){
        int y,x,id;
        tie(y,x,id)=marvel[i];
        ans=max(ans,weight[id]);
    }
    cout<<ans;


    
}