#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<int>>map;
vector<vector<int>>psum;

int n,m;
int findsum(int y,int x){
    int ret=-987654321;
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            ret=max(ret,psum[y][x]-psum[y][j-1]-psum[i-1][x]+psum[i-1][j-1]);
        }
    }
    return ret;
}

int find(int y,int x){
    int ret=-987654321;
    for(int i=y;i<=n;i++){
        for(int j=x;j<=m;j++){
            ret=max(ret,psum[i][j]-psum[i][x-1]-psum[y-1][j]+psum[y-1][x-1]);
        }
    }
    return ret;

}

int findmax(int y,int x){
    int ans=-987654321;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i<=y&&j<=x)continue;
            ans=max(ans,find(i,j));
        }
    }
    return ans;
}

int main() {
    
    cin>>n>>m;
    
    map=vector<vector<int>>(n+1,vector<int>(m+1));
    psum=vector<vector<int>>(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+map[i][j];
        }
    }
    int res=-987654321;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int fir=findsum(i,j);
            int sec=findmax(i,j);
            res=max(res,fir+sec);
        }
    }
    cout<<res;
    
    

 


}