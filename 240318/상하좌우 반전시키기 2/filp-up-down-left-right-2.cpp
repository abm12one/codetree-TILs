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

vector<int>arr;
int n,m;
int res;
int ans;

int push(int st,int now){
    int u=now-m;
    int d=now+m;
    int l=now-1;
    int r=now+1;
    if(u<0){}
    else{
        st^=(1<<u);
    }
    if(d>n*m-1){}
    else{
        st^=(1<<d);
    }
    if(now%m==0){}
    else{
        st^=(1<<l);
    }
    if((now+1)%m==0){}
    else{
        st^=(1<<r);
    }
    st^=(1<<now);
    return st;
}

void sol(int st,int now,int cnt){

    if(st==((1<<n*m)-1)){
        res=min(res,cnt);
        return;
    }

    if(now==m*n)return;
    
    sol(st,now+1,cnt);
    
    int next=push(st,now);

    sol(next,now+1,cnt+1);
    
    return;

}

int main() {

    ans=0;
    res=987654321;

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            if(t==0)continue;
            
            ans|=(1<<(i*m+j));
        }
    } 
    
    
    sol(ans,0,0);
    if(res==987654321){
        cout<<-1;
    }
    else{
        cout<<res<<'\n';
    }
    
   
}