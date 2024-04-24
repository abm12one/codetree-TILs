#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
int sum=0;
vector<int>arr;
vector<int>ret;
int ans=987654321;
void sol(){
    int s=0;
    for(int i=0;i<ret.size();i++){
        s+=arr[ret[i]];
    }
    int left=sum-s;
    //cout<<s<<' '<<left<<'\n';
    ans=min(ans,abs(left-s));
    return;
}

void pr(){
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<' ';
    }
    cout<<'\n';
    return;
}

void bt(int now,int cnt){
    if(cnt==n){
        sol();
        //pr();
        return;
    }
    for(int i=now+1;i<2*n;i++){
        ret.push_back(i);
        bt(i,cnt+1);
        ret.pop_back();
    }
    return;
}

int main() {
    
    cin>>n;
    arr=vector<int>(2*n);
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    //cout<<sum<<'\n';
    bt(-1,0);
    cout<<ans;
}