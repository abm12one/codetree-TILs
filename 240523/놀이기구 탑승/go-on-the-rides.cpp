#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
vector<vector<int>>fr;
vector<vector<int>>map;
vector<vector<int>>vmap;
vector<vector<int>>fmap;
int dy[4]={-1,0,1,0};
int dx[4]={0,-1,0,1};

int isrange(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}

void sol(int now){
    vmap=vector<vector<int>>(n,vector<int>(n));
    fmap=vector<vector<int>>(n,vector<int>(n));

    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]>0)continue;
            
            for(int k=0;k<4;k++){
                
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(isrange(ny,nx)){
                    if(map[ny][nx]==0){
                        vmap[i][j]++;
                    }
                    for(int l=0;l<4;l++){
                        if(fr[now][l]==map[ny][nx]){
                            fmap[i][j]++;
                        }
                    }

                }
            }
        }
    }

    int v=-1;
    int f=-1;
    int y=-1;
    int x=-1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]>0)continue;

            if(fmap[i][j]>f){
                f=fmap[i][j];
                v=vmap[i][j];
                y=i;
                x=j;
            }
            else if(fmap[i][j]==f){
                if(vmap[i][j]>v){
                    f=fmap[i][j];
                    v=vmap[i][j];
                    y=i;
                    x=j;
                }
            }

        }
    }
    map[y][x]=now;
    return ;

}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    return;
}

void check(){
    int ret=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int now=map[i][j];
            int cnt=0;
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(isrange(ny,nx)==0)continue;
                for(int l=0;l<4;l++){
                    if(map[ny][nx]==fr[now][l]){
                        cnt++;
                        break;
                    }

                }

            }
            if(cnt==0)ret+=0;
            else{
                ret+=pow(10,cnt-1);
            }
            //cout<<ret<<'\n';
        }
    }
    cout<<ret;
}


int main() {

    cin>>n;
    fr=vector<vector<int>>(n*n+1);
    map=vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n*n;i++){
        
        int now;
        cin>>now;
        
        for(int j=0;j<4;j++){
            int temp;
            cin>>temp;
            fr[now].push_back(temp);
        }
        
        sol(now);
        
    }

    check();
    
    
    
    
   


}