#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n;
int ans=0;
vector<vector<int>>map;
vector<vector<int>>cop;
void down(int x,int a,int b){
    int s=a-1;
    
    for(int i=a;i<=b;i++){
        cop[i][x]=0;

    }

    for(int i=a-1;i>=1;i--){
        cop[i+b+1-a][x]=cop[i][x];
        cop[i][x]=0;
    }
   

}

int find(){
    int ret=0;
    for(int j=1;j<=n;j++){
        for(int i=1;i<n;i++){
            if(cop[j][i]==cop[j][i+1]&&cop[j][i]!=0)ret++;
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<n;i++){
            if(cop[i][j]==cop[i+1][j]&&cop[i][j]!=0)ret++;
        }
    }
    return ret;
    
}

void sol(int y,int x,int t){
    cop=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cop[i][j]=map[i][j];
        }
    }

    int s,e;
    if(x-t+1<1){
        s=1;
    }
    else{
        s=x-t+1;
    }
    if(x+t-1>n){
        e=n;
    }
    else{
        e=x+t-1;
    }

    for(int i=s;i<=e;i++){
        down(i,y,y);
    }
    
    if(y-t+1<1){
        s=1;
    }
    else{
        s=y-t+1;
    }
    if(y+t-1>n){
        e=n;
    }
    else{
        e=y+t-1;
    }

    
    down(x,s+1,e);
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<cop[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    */

    int fnum=find();

    ans=max(ans,fnum);


}


int main() {
    
    
    cin>>n;

    map=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sol(i,j,map[i][j]);
        }
    }
    
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
    */
    cout<<ans;

}