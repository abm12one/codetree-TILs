#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int ans=0;
int n,m;
vector<vector<int>>map;
vector<int>arr;
vector<int>temp;
vector<pair<int,int>>spin;
int d,p;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int range(int y,int x){
    if(x<0||x>=n)return 0;
    if(y<0||y>=n)return 0;
    return 1;
}

void pre(){
    
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
            
            spin.push_back(make_pair(ny,nx));
            
        }
    }
}

void setting(){
    arr=vector<int>();
    for(int i=0;i<spin.size();i++){
        int y,x;
        tie(y,x)=spin[i];
        if(map[y][x]==0)continue;
        arr.push_back(map[y][x]);
    }
}
void pr(){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<' ';
        
    }
    cout<<'\n';
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
        ans+=map[ny][nx];
        map[ny][nx]=0;
        y=ny;
        x=nx;
    }

}

void exp(){
    temp=vector<int>();
    int cnt=0;
    int s=0;
    for(int i=0;i<arr.size();i++){
        if(arr[s]==arr[i]){
            cnt++;
        }
        if(arr[s]!=arr[i]){
            
            temp.push_back(cnt);
            temp.push_back(arr[s]);
            cnt=1;
            s=i;

        }
    }
    
    temp.push_back(cnt);
    temp.push_back(arr[s]);
    
    arr=temp;
    return;
}

void put(){
    map=vector<vector<int>>(n,vector<int>(n));
    int s=min(arr.size(),spin.size());
    for(int i=0;i<s;i++){
        int y,x;
        tie(y,x)=spin[i];
        map[y][x]=arr[i];
    }
    return;
}

void shr(int s,int cnt){
    for(int i=0;i<cnt;i++){
        ans+=arr[s+i];
        arr[s+i]=0;
    }
    return;
}

int com(){
    int cnt=0;
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
    if(cnt>=4){
        shr(s,cnt);
        f=1;
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

void sol(int d,int p){
    remove(d,p);
    setting();
    //pr();
    
    while(true){
        int k=com();
        if(!k){
            break;
        }
        compact();

    }
    //pr();
    
    exp();
    //pr();
    
   
    
   
    put();
    //pr();
    
}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    pre();
    for(int i=0;i<m;i++){
        cin>>d>>p;
        sol(d,p);
        
    }

    cout<<ans;


}