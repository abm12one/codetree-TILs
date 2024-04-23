#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
using namespace std;
int n,m,c;
vector<vector<int>>map;
vector<vector<int>>psum;
vector<vector<int>>p;
vector<int>wh;
int ans=0;
vector<int>arr;
int result;
void btt(int now,int sum,int hap){

    if(hap>c){
        return;
    }
    result=max(result,sum);

    for(int i=now+1;i<arr.size();i++){
        
        btt(i,sum+pow(arr[i],2),hap+arr[i]);

    }
    return;

}

int find(int y,int x){
    arr=vector<int>();
    for(int i=x;i<=x+m-1;i++){
        arr.push_back(map[y][i]);
    }
    sort(arr.begin(),arr.end(),greater<int>());
    
    result=0;
    btt(-1,0,0);
    
    return result;

}

void sol3(int y, int x1,int x2){
    
    int ret1=0;
    int t1=p[y][x1+m-1]-p[y][x1-1];
    if(t1>c){
        int temp=find(y,x1);
        ret1=max(ret1,temp);
        //cout<<"#1 1 "<<x1<<" "<<temp<<'\n';
    }
    else{
        int temp=psum[y][x1+m-1]-psum[y][x1-1];
        ret1=max(ret1,temp);
        //cout<<"#1 2 "<<x1<<" "<<temp<<'\n';
    }
        
    
    int ret2=0;
   
    int t2=p[y][x2+m-1]-p[y][x2-1];
    if(t2>c){
        int temp=find(y,x2);
        ret2=max(ret2,temp);
        //cout<<"#2 1 "<<x2<<" "<<temp<<'\n';
    }
    else{
        int temp=psum[y][x2+m-1]-psum[y][x2-1];
        ret2=max(ret2,temp);  
        //cout<<"#2 2 "<<x2<<" "<<temp<<'\n';
    }
       

    
    ans=max(ans,ret1+ret2);
    return;



}

void sol2(int y){
    for(int i=1;i<=1-2*m+n;i++){
        for(int j=i+m;j<=n-m+1;j++){

            sol3(y,i,j);

        }
    }
    return;
    
}

void sol(){

    int y1=wh[0];
    int y2=wh[1];
    
    int ret1=0;
    for(int i=1;i<=n-m+1;i++){
        int t=p[y1][i+m-1]-p[y1][i-1];
        if(t>c){
            int temp=find(y1,i);
            ret1=max(ret1,temp);
            //cout<<"#1 1 "<<i<<" "<<temp<<'\n';
        }
        else{
            int temp=psum[y1][i+m-1]-psum[y1][i-1];
            ret1=max(ret1,temp);
            //cout<<"#1 2 "<<i<<" "<<temp<<'\n';
        }
        
    }
    int ret2=0;
    for(int i=1;i<=n-m+1;i++){
        int t=p[y2][i+m-1]-p[y2][i-1];
        if(t>c){
            int temp=find(y2,i);
            ret2=max(ret2,temp);
            //cout<<"#2 1 "<<i<<" "<<temp<<'\n';
        }
        else{
            int temp=psum[y2][i+m-1]-psum[y2][i-1];
            ret2=max(ret2,temp);  
            //cout<<"#2 2 "<<i<<" "<<temp<<'\n';
        }
       
    }
    //cout<<ret1<<'\n';
    //cout<<ret2<<'\n';
    //cout<<'\n';
    ans=max(ans,ret1+ret2);
    return;
    

}

void bt(int now,int num){
    if(num==2){
        if(wh[0]==wh[1]){
            sol2(wh[0]);
        }
        else{
            //cout<<wh[0]<<' '<<wh[1]<<'\n';
            sol();
        }

        return;
    }
    for(int i=now;i<=n;i++){
        wh.push_back(i);
        bt(i,num+1);
        wh.pop_back();
    }
    return;


}
int main() {
    
    cin>>n>>m>>c;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    psum=vector<vector<int>>(n+1,vector<int>(n+1));
    p=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            psum[i][j]=psum[i][j-1]+pow(map[i][j],2);
            p[i][j]=p[i][j-1]+map[i][j];
        }
    }

    bt(0,0);
    cout<<ans;
}