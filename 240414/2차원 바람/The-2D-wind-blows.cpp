#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n,m,q;
vector<vector<int>>map;
vector<vector<int>>map2;

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

void sol(int y1,int x1,int y2,int x2){

    map2=vector<vector<int>>(n+2,vector<int>(m+2));

    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            map2[i][j]=map[i][j];
        }
    }


    for(int i=x2-1;i>=x1;i--){
        map2[y1][i+1]=map[y1][i];
    }

    for(int i=y2-1;i>=y1;i--){
        map2[i+1][x2]=map[i][x2];
    }

    for(int i=x1+1;i<=x2;i++){
        map2[y2][i-1]=map[y2][i];
    }

    for(int i=y1+1;i<=y2;i++){
        map2[i-1][x1]=map[i][x1];
    }
    /*
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cout<<map2[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    */

    for(int i=y1;i<=y2;i++){
        for(int j=x1;j<=x2;j++){
            int sum=map2[i][j];
            int cnt=1;
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(ny<1||ny>n||nx<1||nx>m)continue;
                cnt++;
                sum+=map2[ny][nx];
            }
            map[i][j]=sum/cnt;
        }
    }

    

    return ;



}

int main() {
    
    cin>>n>>m>>q;

    map=vector<vector<int>>(n+2,vector<int>(m+2));
    map2=vector<vector<int>>(n+2,vector<int>(m+2));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    /*
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    */


    for(int i=0;i<q;i++){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        sol(y1,x1,y2,x2);

    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    
    

 


}