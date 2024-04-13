#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef struct{
    int y;
    int x;
}node;

vector<vector<node>>arr;
vector<vector<int>>map;
int n,m;
int ans=0;
void setting(){
    arr[0].push_back(node{0,0});
    arr[0].push_back(node{1,0});
    arr[0].push_back(node{1,1});
    arr[1].push_back(node{0,0});
    arr[1].push_back(node{1,-1});
    arr[1].push_back(node{1,0});
    arr[2].push_back(node{0,0});
    arr[2].push_back(node{1,0});
    arr[2].push_back(node{0,1});
    arr[3].push_back(node{0,0});
    arr[3].push_back(node{0,1});
    arr[3].push_back(node{1,1});
    arr[4].push_back(node{0,0});
    arr[4].push_back(node{0,1});
    arr[4].push_back(node{0,2});
    arr[5].push_back(node{0,0});
    arr[5].push_back(node{1,0});
    arr[5].push_back(node{2,0});

}

int ispos(int y,int x,int k){
    for(int i=0;i<3;i++){
        int dy=arr[k][i].y;
        int dx=arr[k][i].x;
        int ny=y+dy;
        int nx=x+dx;
        if(ny<0||nx<0||ny>=n||nx>=m){
            return 0;
        }
    }
    return 1;


}

void sol(int y,int x,int k){
    int ret=0;
    for(int i=0;i<3;i++){
        int dy=arr[k][i].y;
        int dx=arr[k][i].x;
        int ny=y+dy;
        int nx=x+dx;
        ret+=map[ny][nx];
    }
    ans=max(ans,ret);
    return;
}

int main() {
    arr=vector<vector<node>>(6);
    setting();

    
    cin>>n>>m;

    map=vector<vector<int>>(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<6;k++){
                if(!ispos(i,j,k))continue;
                sol(i,j,k);
            }
        }
    }
    cout<<ans;
 


}