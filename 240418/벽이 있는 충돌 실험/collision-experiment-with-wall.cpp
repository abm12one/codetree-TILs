#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>temp;
vector<vector<int>>cop;
int t;
int n,m;
int dy[5]={0,-1,0,1,0};
int dx[5]={0,0,1,0,-1};

int range(int y,int x){
    if(x<1||x>n)return 0;
    if(y<1||y>n)return 0;
    return 1;
}

int change(int d){
    if(d==1)return 3;
    else if(d==2)return 4;
    else if(d==3)return 1;
    else if(d==4)return 2;

}

void shift(int y,int x,int d){
    int ny=y+dy[d];
    int nx=x+dx[d];
    if(!range(ny,nx)){
        temp[y][x]++;
        cop[y][x]=change(d);
        return;
    }
    temp[ny][nx]++;
    cop[ny][nx]=d;

    return;

}

void sol(){

    temp=vector<vector<int>>(n+1,vector<int>(n+1));
    cop=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==0)continue;
            shift(i,j,map[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(temp[i][j]>1){
                cop[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=cop[i][j];
        }
    }



}
void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int dir(char c){
    if(c=='U'){
        return 1;
    }
    else if(c=='R'){
        return 2;
    }
    else if(c=='D'){
        return 3;
    }
    else if(c=='L'){
        return 4;
    }


}

int main(){
    
    cin>>t;
    while(t--){
        
        cin>>n>>m;
        map=vector<vector<int>>(n+1,vector<int>(n+1));

        for(int i=0;i<m;i++){
            int r,c;
            char d;
            cin>>r>>c>>d;
            map[r][c]=dir(d);    
        }
        //pr();
        int rep=2*n+1;
        while(rep--){
            sol();
            //pr();
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][j]!=0){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';




    }
    
   

    
}