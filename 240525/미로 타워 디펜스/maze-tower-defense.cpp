#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>>map;
vector<int>arr;
vector<int>temp;
int d,p;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int range(int y,int x){
    if(x<0||x>=n)return 0;
    if(y<0||y>=n)return 0;
    return 1;
}

void setting(){
    arr=vector<int>();
    int y=n/2;
    int x=n/2;
    int dir=3;
    int cnt=0;
    int s=1;
    while(1){
        dir=(dir+3)%4;
        //cout<<dir<<'\n';
        if(cnt==2){
            cnt=0;
            s++;
        }
        cnt++;
        for(int i=0;i<s;i++){
            int ny=y+dy[dir];
            int nx=x+dx[dir];
            y=ny;
            x=nx;
            //cout<<dir<<' '<<s<<' '<<ny<<' '<<nx<<'\n';
            if(!range(ny,nx))return;
            if(map[ny][nx]==0)continue;
            arr.push_back(map[ny][nx]);
            
        }
    }
}

void pr(){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
        
    }
    cout<<'\n';
    return;
}

void pr2(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void remove(int d,int p){
    
    int y=n/2;
    int x=n/2;
    for(int i=0;i<p;i++){
        int ny=y+dy[d];
        int nx=x+dx[d];
        map[ny][nx]=0;
        y=ny;
        x=nx;
    }

}

void put(){
    map=vector<vector<int>>(n,vector<int>(n));
    int y=n/2;
    int x=n/2;
    int dir=3;
    int cnt=0;
    int now=0;
    int s=1;
    while(now<=arr.size()-1){
        dir=(dir+3)%4;
        //cout<<dir<<'\n';
        if(cnt==2){
            cnt=0;
            s++;
        }
        cnt++;
        for(int i=0;i<s;i++){
            int ny=y+dy[dir];
            int nx=x+dx[dir];
            y=ny;
            x=nx;
            
            if(!range(ny,nx))return;
            map[ny][nx]=arr[now++];
            
        }
    }
    return;
}

void shr(int s,int cnt){
    for(int i=0;i<cnt;i++){
        arr[s+i]=0;
    }
    return;
}

int com(){
    int cnt=1;
    int s=0;
    int f=0;
    for(int i=0;i<arr.size();i++){
        if(arr[s]==arr[i]){
            cnt++;
        }
        if(arr[s]!=arr[i]){
            if(cnt>=4){
                shr(s,cnt);
                f=1;
            }
            cnt=1;
            s=i;

        }
    }
    return f;

}

void compact(){
    temp=vector<int>();
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0)continue;
        temp.push_back(arr[i]);
    }
    arr=temp;
    return;
}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<m;i++){
        cin>>d>>p;
    }
    
    
    remove(d,p);
    setting();
    pr();
    
    while(1){
        int k=com();
        if(k==0)return;
    }
    
    compact();
    pr();
    put();
    pr2();



}