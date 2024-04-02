#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;
vector<vector<int>>psum;

int main() {
    
    int n,k;
    cin>>n>>k;

    map=vector<vector<int>>(n+1,vector<int>(n+1));
    psum=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            psum[i][j]=psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1]+map[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-k<0||j-k<0)continue;

            ans=max(ans,psum[i][j]-psum[i-k][j]-psum[i][j-k]+psum[i-k][j-k]);
        }
    }

    cout<<ans;






}