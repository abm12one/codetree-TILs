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

using namespace std;

int n,k;
vector<vector<int>>map;
vector<vector<int>>dp;

int count(int num){
    int ret=0;
    for(int i=0;i<n;i++){
        if(num&(1<<i))ret++;
    }
    return ret;
}

int sol(int visit,int now){
    
    if(count(visit)==k+1){
        return map[now][0];
    }

    int ret=1e9;

    for(int i=1;i<n;i++){
        if(visit&(1<<i))continue;

        ret=min(ret,map[now][i]+sol(visit|(1<<i),i));
    }
    return ret;



}

int main() {

    cin>>n>>k;

    map=vector<vector<int>>(n,vector<int>(n));
    dp=vector<vector<int>>(1<<n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    cout<<sol(1,0);




    

 
}