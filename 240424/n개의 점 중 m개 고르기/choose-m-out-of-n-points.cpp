#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
using namespace std;

vector<pair<int,int>>p;
vector<int>ret;
int n,m;
double ans=987654321;
double dist(int a,int b){
    int ay,ax;
    int by,bx;
    tie(ay,ax)=p[a];
    tie(by,bx)=p[b];
    return (double)sqrt(pow(abs(ay-by),2)+pow(abs(ax-bx),2));

}
void sol(){
    double res=0;
    for(int s=0;s<=m-2;s++){
        for(int e=s+1;e<=m-1;e++){
            res=max(res,dist(ret[s],ret[e]));
        }
    }
    ans=min(ans,pow(res,2));
    return;


}

void bt(int now,int cnt){
    if(cnt==m){
        sol();
        return;
    }
    for(int i=now+1;i<n;i++){
        ret.push_back(i);
        bt(i,cnt+1);
        ret.pop_back();
    }
    return;

}
int main() {
    
    cin>>n>>m;
    p=vector<pair<int,int>>(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        p[i]=make_pair(a,b);
    }

    bt(-1,0);
    cout<<ans;


}