#include <iostream>
#include <vector>

using namespace std;

int n,t;
int dy[4]={-1,0,0,1};
int dx[4]={0,1,-1,0};
vector<vector<int>>map;

int findd(char c){
    if(c=='U'){
        return 0;
    }
    else if(c=='R'){
        return 1;
    }
    else if(c=='L'){
        return 2;
    }
    else if(c=='D'){
        return 3;
    }

}

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

int main() {
    
    cin>>n>>t;

    map=vector<vector<int>>(n+1,vector<int>(n+1));

    int y,x;
    char c;
    cin>>y>>x>>c;

    int d=findd(c);

    while(t--){

        int ny=y+dy[d];
        int nx=x+dx[d];

        if(!range(ny,nx)){
            d=3-d;
            continue;
        }
        y=ny;
        x=nx;

    }

    cout<<y<<' '<<x;

 
    
}