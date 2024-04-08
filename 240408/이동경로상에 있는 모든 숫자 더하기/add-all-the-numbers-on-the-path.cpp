#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<vector<int>>map;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}

int main() {

    
    cin>>n>>m;
    map=vector<vector<int>>(n,vector<int>(n));
    string str;
    cin>>str;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }


    int d=0;
    int y=(n-1)/2;
    int x=(n-1)/2;

    int ans=map[(n-1)/2][(n-1)/2];

    for(int i=0;i<m;i++){
        char c=str[i];
        if(c=='R'){
            d=(d+1)%4;
        }
        else if(c=='L'){
            d=(d-1+4)%4;
        }
        else if(c=='F'){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(!range(ny,nx))continue;
            ans+=map[ny][nx];
            y=ny;
            x=nx;

        }
        



    }
    cout<<ans;



    
    
    

 
    
}