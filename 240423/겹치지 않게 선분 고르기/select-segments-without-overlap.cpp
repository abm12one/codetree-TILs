#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int n;
vector<int>visit;
vector<pair<int,int>>arr;
int ans=0;



void bt(int now,int cnt){
    ans=max(ans,cnt);

    for(int i=now+1;i<n;i++){
        int a,b;
        tie(a,b)=arr[i];
        if(visit[a]==0&&visit[b]==0){
            visit[a]=1;
            visit[b]=1;
            bt(i,cnt+1);
            visit[a]=0;
            visit[b]=0;

        }

    }
    return;

}


int main() {
    
    cin>>n;
    visit=vector<int>(1001);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));

    }
    sort(arr.begin(),arr.end());

    bt(-1,0);
    cout<<ans;

}