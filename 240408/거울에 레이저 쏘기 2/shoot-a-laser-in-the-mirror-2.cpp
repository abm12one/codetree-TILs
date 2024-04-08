#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>map;
int d;
int y;
int x;
int n;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

void setst(int st){

    if((st-1)/n==0){
        d=2;
        x=((st-1)%n)+1;
        y=1;
    }
    else if((st-1)/n==1){
        d=3;
        x=n;
        y=((st-1)%n)+1;
    }
    else if((st-1)/n==2){
        d=0;
        x=n-((st-1)%n);
        y=n;

    }
    else if((st-1)/n==3){
        d=1;
        x=1;
        y=n-((st-1)%n);
    }

}

void changed(int m,int d){
    if(m==0){
        if(d==0){
            d=1;
        }
        if(d==1){
            d=0;
        }
        if(d==2){
            d=3;
        }
        if(d==3){
            d=2;
        }
        
        
    }
    else if(m==1){
        d=3-d;
    }
    return ;
}

int range(int y,int x){
    if(x<1||x>n)return 0;
    if(y<1||y>n)return 0;
    return 1;
}






int main() {

    
    cin>>n;
    map=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            
            char c;
            cin>>c;
            if(c=='/'){
                map[i][j]=0;
            }
            else if(c=='\\'){
                map[i][j]=1;
            }
            
        }
    }

    int st;
    cin>>st;
    setst(st);

    int ans=0;

    while(1){

        ans++;

        int mir=map[y][x];
        changed(mir,d);
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(!range(ny,nx))break;
        y=ny;
        x=nx;

        


    }
    cout<<ans;




  
}