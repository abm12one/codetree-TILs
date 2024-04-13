#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<int>>map;
int n,m;
typedef struct{
    int y;
    int x;
}node;

int cost(int k){
    return k*k+(k+1)*(k+1);
}
int ans=0;

int gold(int y,int x,int k){
    int ret=0;
    //4
    for(int i=1;i<=k;i++){
        int dy=i;
        int dx=k-i;
        int ny=y-dy;
        int nx=x+dx;

        if(ny<0||nx<0||nx>=n||ny>=n)continue;

        if(map[ny][nx]==1)ret++;
    }
    //2
    for(int i=1;i<=k;i++){
        int dy=i;
        int dx=k-i;
        int ny=y+dy;
        int nx=x-dx;

        if(ny<0||nx<0||nx>=n||ny>=n)continue;

        if(map[ny][nx]==1)ret++;
    }
    //3
    for(int i=1;i<=k;i++){
        int dy=k-i;
        int dx=i;
        int ny=y-dy;
        int nx=x-dx;

        if(ny<0||nx<0||nx>=n||ny>=n)continue;

        if(map[ny][nx]==1)ret++;
    }
    //1
    for(int i=1;i<=k;i++){
        int dy=k-i;
        int dx=i;
        int ny=y+dy;
        int nx=x+dx;

        if(ny<0||nx<0||nx>=n||ny>=n)continue;

        if(map[ny][nx]==1)ret++;
    }

    
    return ret;



}

void sol(int y,int x,int k){
    int ret=0;
    int c=cost(k);
    for(int i=1;i<=k;i++){
        ret+=gold(y,x,i);  
    }
    if(map[y][x]==1)ret++;
    int g=ret*m;
    if(g>=c){
        ans=max(ans,ret);
    }
    return;
}


int main() {
    
    cin>>n>>m;
    
    map=vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                sol(i,j,k);
            }

        }
    }    

    cout<<ans;

 


}