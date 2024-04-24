#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;
int n,m;
int ncnt;
vector<int>arr;
vector<int>ret;
vector<vector<int>>map;
vector<pair<int,int>>num;
vector<pair<int,int>>se;
int ans=987654321;
int dist(int a,int b){
    int ay,ax;
    tie(ay,ax)=num[a];
    int by,bx;
    tie(by,bx)=num[b];
    int d=abs(ay-by)+abs(ax-bx);
    return d; 

}

void sol(){
    int res=0;
    res+=dist(0,ret[0]);
    for(int i=0;i<2;i++){
        res+=dist(ret[i],ret[i+1]);
    }
    res+=dist(ret[2],10);
    ans=min(ans,res);
    //cout<<res<<'\n';
    return;

}
void pr(){
    for(int i=0;i<11;i++){
        int y,x;
        tie(y,x)=num[i];
        cout<<"#"<<i<<' '<<y<<' '<<x;
        cout<<"\n";

    }
    cout<<"\n";
    return;
}
void pr2(){
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<' ';
    }
    cout<<'\n';
    return;
}
void bt(int now,int cnt){

    if(cnt==3){
        sol();
        //pr();
        //pr2();
        return;
    }
    for(int i=now+1;i<=ncnt;i++){
        ret.push_back(i);
        bt(i,cnt+1);
        ret.pop_back();
    }
    return;

}

int main() {
    int n;
    cin>>n;
    ncnt=0;
    num=vector<pair<int,int>>(11);
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    se=vector<pair<int,int>>(2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='.'){map[i][j]=0;}
            else if(c=='S'){num[0]=make_pair(i,j);}
            else if(c=='E'){num[10]=make_pair(i,j);}
            else{
                map[i][j]=c-'0';
                ncnt++;
                num[map[i][j]]=make_pair(i,j);
            }
            
        }
    }

    bt(0,0);
    if(ans=987654321){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    



}