#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<int>arr;

void pr(){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    return;
}

void bt(int now,int cnt){
    if(cnt==m){
        pr();
        return;
    }
    for(int i=now+1;i<=n;i++){
        arr.push_back(i);
        bt(i,cnt+1);
        arr.pop_back();
    }
}

int main() {
    
    cin>>n>>m;
    bt(0,0);

}