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

int n;
vector<vector<int>>map;

int mdis(int visit,int now){
    int ret=-1;
    for(int i=0;i<n;i++){
        if(visit&(1<<i)){
            ret=max(ret,map[i][now]);
        }

    }
    return ret;
}

int sol(int visit,int now){
    
    int dis=mdis(visit,now);
    int ret=1;
    for(int i=0;i<n;i++){
        if(visit&(1<<i))continue;
        if(map[now][i]<=dis)continue;

        ret=max(ret,1+sol(visit|(1<<i),i));

    }
    return ret;

}


int main() {
 
    cin>>n;

    map=vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    cout<<sol(1,0);


    

 
}