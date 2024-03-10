#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits.h>
#include<cassert>
//#include<unordered_map>
//#include<map>
#include<unordered_set>
#include<set>
#define MAX_M 100000

using namespace std;

typedef struct{
    int x;
    int y;
}node;

bool compare(node n1,node n2){
    return n1.x<n2.x;
}

vector<node>arr;
vector<vector<int>>dp;

int dist(int a,int b){
    int dy=abs(arr[a].y-arr[b].y);
    int dx=abs(arr[a].x-arr[b].x);
    return pow(dy,2)+pow(dx,2);
}

int main() {
    
    int n;
    cin>>n;
    
    arr=vector<node>(n+1);
    arr[0]=node{0,0};
    for(int i=1;i<n+1;i++){
        int a,b;
        cin>>a>>b;
        arr[i]=node{a,b};
    }

    sort(arr.begin(),arr.end(),compare);

    /*
    for(int i=0;i<n+1;i++){
        cout<<arr[i].x<<' '<<arr[i].y<<'\n';
    }
    */

    dp=vector<vector<int>>(n+1,vector<int>(n+1,(int)1e9));

    dp[1][1]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            int k=max(i,j)+1;
            if(k==n+1){
                continue;
            }

            dp[k][j]=min(dp[k][j],dp[i][j]+dist(i,k));
            dp[i][k]=min(dp[i][k],dp[i][j]+dist(j,k));

        }
    }

    int ans=(int)1e9;
    for(int i=1;i<n;i++){
        ans=min(ans,dp[i][n]+dist(i,n));
    }
    cout<<ans<<'\n';

	
}