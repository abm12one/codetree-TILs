#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
vector<pair<int,int>>arr;
int n,m;
vector<int>visit;
vector<int>origin;
vector<int>use;
vector<int>ret;
void twist(int a){
    int temp=visit[a];
    visit[a]=visit[a+1];
    visit[a+1]=temp;
    return;


}
void twistorigin(int a){
    int temp=origin[a];
    origin[a]=origin[a+1];
    origin[a+1]=temp;
    return;


}

int check(){
    for(int i=1;i<=n;i++){
       if(visit[i]!=origin[i])return 0;
    }
    return 1;
}

int alluse(){
    for(int i=1;i<=n-1;i++){
        if(use[i]==0)return 0;
    }
    return 1;
}
int ans=987654321;

void pr(){
    for(int i=1;i<=n-1;i++){
        cout<<use[i]<<' ';
    }
    cout<<"\n";
    return;
}
void pr2(){
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<' ';
    }
    cout<<"\n";
    return;
}
void pr3(){
    for(int i=1;i<=n;i++){
        cout<<visit[i]<<' ';
    }
    cout<<"\n";
    return;
}

void bt(int now,int cnt){
    /*
    if(cnt==4){
        pr2();
        pr();
        pr3();
        cout<<'\n';
    }
    */

    if(cnt!=0&&check()&&alluse()){
        ans=min(ans,cnt);
    }
    
    for(int i=now+1;i<m;i++){
        int b,a;
        tie(b,a)=arr[i];
        twist(a);
        use[a]++;
        //ret.push_back(i);
        bt(i,cnt+1);
        //ret.pop_back();
        twist(a);
        use[a]--;


    }
    return;

}

int main() {
    
    cin>>n>>m;
    origin=vector<int>(n+1);
    visit=vector<int>(n+1);
    for(int i=1;i<=n;i++){
        visit[i]=i;
        origin[i]=i;
    }

    use=vector<int>(n+1,0);

    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(b,a));
        
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
       int a,b;
       tie(b,a)=arr[i];
       twistorigin(a);
    }
    /*
    for(int i=1;i<=n;i++){
        cout<<origin[i]<<' ';
    }
    cout<<'\n';
    cout<<'\n';
    */
    sort(arr.begin(),arr.end());
    bt(-1,0);
    cout<<ans;

}