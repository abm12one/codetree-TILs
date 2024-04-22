#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>arr;
vector<int>visit;
int n;
int main() {
    
    cin>>n;
    arr=vector<int>(n+2);
    visit=vector<int>(n+2,-1);
    queue<int>q;
    q.push(n);
    visit[n]=0;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        //
        if(now+1<=n+1&&visit[now+1]==-1){
            q.push(now+1);
            visit[now+1]=visit[now]+1;
        }
        if(now-1>0&&visit[now+1]==-1){
            q.push(now-1);
            visit[now-1]=visit[now]+1;
        }
        if(now%2==0&&now/2>0&&visit[now/2]==-1){
            q.push(now/2);
            visit[now/2]=visit[now]+1;
        }
        if(now%3==0&&now/3>0&&visit[now/3]==-1){
            q.push(now/3);
            visit[now/3]=visit[now]+1;
        }


    }
    cout<<visit[1];
}