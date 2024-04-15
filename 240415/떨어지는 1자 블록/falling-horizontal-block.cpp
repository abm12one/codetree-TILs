#include <iostream>
#include <vector>

using namespace std;

int n,m,k;

vector<vector<int>>map;

int isok(int y){
    for(int i=k;i<=k+m-1;i++){
        if(map[y][i]!=0)return 0;
    }
    return 1;
}
int isdown(int y){
    for(int i=y;i>=1;i--){
        for(int j=k;j<=k+m-1;j++){
            if(map[i][j]!=0)return 0;
        }
       
    }
    return 1;
}

void pr(int y){
    for(int i=k;i<=k+m-1;i++){
        map[y][i]=1;
    }
    return ;
}

int main() {
    
    cin>>n>>m>>k;
    map=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=n;i>=1;i--){
        if(isok(i)&&isdown(i)){
            //cout<<i<<'\n';
            pr(i);
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }

    

    
    
}