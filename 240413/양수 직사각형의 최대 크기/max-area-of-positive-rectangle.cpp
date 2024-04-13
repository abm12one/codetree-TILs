#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<int>>map;
vector<vector<int>>m;
vector<vector<int>>psum;
vector<vector<int>>p;

int ispos(int y,int x,int i,int j){
    int bit=p[y][x]-p[y][j-1]-p[i-1][x]+p[i-1][j-1];
    int num=(y-i+1)*(x-j+1);
    if(bit==num)return 1;
    return 0;
}

int find(int y,int x){
    int ret=-1;
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            if(!ispos(y,x,i,j))continue;;
            ret=max(ret,(y-i+1)*(x-j+1));
        }
    }
    return ret;
}

int main() {
    int n,k;
    cin>>n>>k;
    map=vector<vector<int>>(n+1,vector<int>(k+1));
    m=vector<vector<int>>(n+1,vector<int>(k+1));
    psum=vector<vector<int>>(n+1,vector<int>(k+1));
    p=vector<vector<int>>(n+1,vector<int>(k+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>map[i][j];
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+map[i][j];
            if(map[i][j]>0){
                m[i][j]=1;
            }
            p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+m[i][j];
        }
    }

    int ans=-1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            ans=max(ans,find(i,j));
        }
    }
    cout<<ans;



    
    

 


}