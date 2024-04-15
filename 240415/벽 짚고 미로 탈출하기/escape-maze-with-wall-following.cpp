#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;

int n;
int y,x;

int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int cdy[4]={1,1,-1,-1};
int cdx[4]={1,-1,-1,1};

int isout(int y,int x){
    if(y<1||y>n)return 1;
    if(x<1||x>n)return 1;
    return 0;
}

int main() {
    
    
    cin>>n;
    
    cin>>y>>x;
    map=vector<vector<int>>(n+2,vector<int>(n+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='#'){
                map[i][j]=1;
            }
            else if(c=='.'){
                map[i][j]=0;
            }
            
        }
    }
    int dir=0;
    int t=0;
    int num=0;
    while(1){
        //cout<<y<<' '<<x<<' '<<t<<" "<<dir<<'\n';
        int ny=y+dy[dir];
        int nx=x+dx[dir];
        int cny=y+cdy[dir];
        int cnx=x+cdx[dir];

        if(map[ny][nx]==1){
            dir=(dir-1+4)%4;
            continue;
        }

        else if(map[cny][cnx]==1){
            y=ny;
            x=nx;
            t+=1;
            if(isout(y,x)){
                break;
            }
        }

        else if(map[cny][cnx]==0){
            y=cny;
            x=cnx;
            dir=(dir+1)%4;
            t+=2;
            if(isout(y,x)){
                break;
            }
        }
        num++;
        if(num>n*n){
            cout<<-1;
            return 0;
        }
        

    }
    
    t--;
    cout<<t;




    

    
    
}