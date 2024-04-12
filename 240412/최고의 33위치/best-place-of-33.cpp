#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>psum;
int ispos(int y,int x){

    int sy=y-3;
    int sx=x-3;

    if(sy<0||sx<0)return 0;

    return 1;


}
int sol(int y,int x){
    int sy=y-3;
    int sx=x-3;
    return psum[y][x]-psum[y][sx]-psum[sy][x]+psum[sy][sx];
}


int main() {
    int n;
    cin>>n;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    psum=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+map[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!ispos(i,j))continue;
            ans=max(ans,sol(i,j));
        }
    }
    cout<<ans;
    


}