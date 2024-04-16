#include <iostream>
#include <vector>

using namespace std;

int n,m;

vector<vector<int>>map;
vector<int>visit;
int ans=0;
void dfs(int n){
    ans++;
    visit[n]=1;
    for(int i=0;i<map[n].size();i++){
        int next=map[n][i];
        if(visit[next]==0){
            dfs(next);
        }
    }
    return ;


}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n+1);
    visit=vector<int>(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    dfs(1);
    cout<<ans-1;


}