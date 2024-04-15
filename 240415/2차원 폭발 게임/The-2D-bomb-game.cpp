#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int>>map;

int n,m,k;
int ans;
void sol(int x,int a,int b){
    for(int i=a;i<=b;i++){
        map[i][x]=0;
    }
    ans-=(b-a+1);
    return;

}

void erase(int x){
    int s=-1;
    for(int i=0;i<n;i++){
        if(map[i][x]!=0){
            s=i;
            break;
        }
    }
    if(s==-1)return;

    int cnt=1;

    for(int i=s+1;i<=n;i++){
        if(map[i][x]==map[s][x]){
            cnt++;
        }
        else if(map[i][x]!=map[s][x]){
            if(cnt>=m){
                sol(x,s,i-1);
            }
            cnt=1;
            s=i;
        }
    }
    if(cnt>=m){
        sol(x,s,n);
    }
    return;

}
void bomb(){
    for(int i=1;i<=n;i++){
        erase(i);
    }

}

void down(int x){
    vector<int>arr(n+1);
    for(int i=0;i<=n;i++){
        arr[i]=map[i][x];
        map[i][x]=0;
    }
    int s=n;
    for(int i=n;i>=1;i--){
        if(arr[i]==0)continue;
        map[s][x]=arr[i];
        s--;
    }

}
void godown(){
    for(int i=1;i<=n;i++){
        down(i);
    }

}

void rotate(){
    vector<vector<int>>map2(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map2[i][j]=map[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[j][n+1-i]=map2[i][j];
        }
    }

}

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;

}
int main() {
    
    cin>>n>>m>>k;
    if(m==1){
        cout<<0;
        return 0;
    }
    ans=n*n;
    map=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    while(k--){

        while(1){
            int tn=ans;
            bomb();
            godown();
            if(tn==ans)break;
        }
        rotate();
        //pr();
        godown();
        //pr();
    }
    while(1){
        int tn=ans;
        bomb();
        godown();
        if(tn==ans)break;
    }
    cout<<ans;
    

}