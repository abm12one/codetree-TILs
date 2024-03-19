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

vector<vector<int>>map;

int n;

int sol(int now,int mark){
    if(mark==(1<<n)-1){
        return map[now][0];
    }

    int ret=987654321;

    for(int next=0;next<n;next++){
        if(mark&(1<<next))continue;
        ret=min(ret,map[now][next]+sol(next,mark|(1<<next)));
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

    cout<<sol(0,1);
 
}