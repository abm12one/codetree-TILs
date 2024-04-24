#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<int>arr;
vector<int>ret;
int ans=0;
void sol(){
    int res=ret[0];
    for(int i=1;i<ret.size();i++){
        res^=ret[i];
    }
    //cout<<res<<'\n';
    ans=max(ans,res);
    return;
}
void pr(){
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<" ";
    }
    cout<<'\n';
    return;
}

void bt(int now,int cnt){
    if(cnt==m){
        sol();

        //pr();
        return;
    }
    for(int i=now+1;i<n;i++){
        ret.push_back(arr[i]);
        bt(i,cnt+1);
        ret.pop_back();

    }
    return;

}

int main() {
    
    cin>>n>>m;
    arr=vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bt(-1,0);
    cout<<ans;

}