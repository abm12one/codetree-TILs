#include <iostream>
#include <vector>
using namespace std;

int n,m,k,c;
vector<vector<int>>map;
vector<vector<int>>temp;
vector<vector<int>>fkill;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ddy[4]={-1,-1,1,1};
int ddx[4]={-1,1,-1,1};
int ans=0;
int range(int y,int x){

    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;

}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void pr2(){
    cout<<"kill"<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<fkill[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void grow(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(map[i][j]<=0)continue;
            int cnt=0;
            
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]>0&&fkill[ny][nx]==0){
                    cnt++;
                }
            }

            map[i][j]+=cnt;
            
        }
    }
    
    
    return;

}

void growchild(){

    temp=vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(map[i][j]<=0)continue;
            int cnt=0;
            
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]==0&&fkill[ny][nx]==0){
                    cnt++;
                }
            }

            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]==0&&fkill[ny][nx]==0){
                    temp[ny][nx]+=map[i][j]/cnt;
                }
            }
        }
    }
    
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]+=temp[i][j];
        }
        
    }
    
    return;

}


int check(int y,int x,int k){
    int ret=0;
    //cout<<y<<"    "<<x<<'\n';
    for(int d=0;d<4;d++){
        for(int i=1;i<=k;i++){
            int ny=y+ddy[d]*i;
            int nx=x+ddx[d]*i;
            if(!range(ny,nx))continue;
            if(map[ny][nx]<=0)break;
            //cout<<"  "<<ny<<" "<<nx<<'\n';
            ret+=map[ny][nx];
        }
    }
    ret+=map[y][x];
    return ret;

}

int kill(int y,int x,int k){
    fkill[y][x]=c;
    
    map[y][x]=0;
    
    //cout<<y<<' '<<x<<"\n";
    int ret=0;
    for(int d=0;d<4;d++){
        for(int i=1;i<=k;i++){
            int ny=y+ddy[d]*i;
            int nx=x+ddx[d]*i;
            if(!range(ny,nx))continue;
            if(map[ny][nx]<=0){
                fkill[ny][nx]=c;
                
                break;
            }
            fkill[ny][nx]=c;
            
            map[ny][nx]=0;
            
            
        }
    }
    
    return ret;

}

void findbug(){
    int my=-1;
    int mx=-1;
    int mcnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]<=0)continue;
            int cnt=check(i,j,k);
            //cout<<i<<' '<<j<<' '<<cnt<<"\n";
            if(cnt>mcnt){
                mcnt=cnt;
                my=i;
                mx=j;
            }

        }
    }
    if(my==-1&&mx==-1)return;

    ans+=mcnt;
    kill(my,mx,k);
    
    return;
}

void blow(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fkill[i][j]==0)continue;
            fkill[i][j]--;
        }
    }
    return;
}

void sol(){
    blow();
    //pr2();
    grow();
    
    growchild();
    
    //pr();
    //pr2();
    findbug();
    //pr();
    //pr2();
    
}

int main() {
    
    cin>>n>>m>>k>>c;
    map=vector<vector<int>>(n,vector<int>(n));
    fkill=vector<vector<int>>(n,vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        sol();
    }
    cout<<ans<<'\n';

}