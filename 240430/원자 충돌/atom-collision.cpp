#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int n,m,k;

vector<vector<vector<tuple<int,int,int>>>>map;
vector<vector<vector<tuple<int,int,int>>>>temp;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,1,1,1,0,-1,-1,-1};

pair<int,int>getnext(int y,int x,int s,int d){
    int ny;
    int nx;
    for(int i=0;i<s;i++){
        ny=y+dy[d];
        nx=x+dx[d];
        if(ny>n){
            ny=1;
        }
        else if(ny<1){
            ny=n;
        }
        if(nx>n){
            nx=1;
        }
        else if(nx<1){
            nx=n;
        }
        y=ny;
        x=nx;
    }
    return make_pair(ny,nx);
}


void move(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j].size()==0)continue;
            for(int k=0;k<map[i][j].size();k++){
                int w,s,d;
                tie(w,s,d)=map[i][j][k];
                int ny,nx;
                tie(ny,nx)=getnext(i,j,s,d);
                temp[ny][nx].push_back(make_tuple(w,s,d));
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<temp[i][j].size();
        }
        cout<<'\n';
    }
    cout<<'\n';
    */

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(temp[i][j].size()==0||temp[i][j].size()==1)continue;
            int sumw=0;
            int sums=0;
            int dd[2]={0,0};
            int siz=temp[i][j].size();
            for(int k=0;k<siz;k++){
                int w,s,d;
                tie(w,s,d)=temp[i][j][k];
                sumw+=w;
                sums+=s;
                if(d%2==0){
                    dd[0]++;
                }
                else{
                    dd[1]++;
                }
            }

            for(int k=0;k<siz;k++){
                temp[i][j].pop_back();
            }
            //cout<<i<<","<<j<<" "<<sumw<<" "<<sums<<'\n';
            if((sumw/5)==0)continue;

            if(dd[0]>0&&dd[1]>0){
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,1));
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,3));
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,5));
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,7));
            }
            else{
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,0));
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,2));
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,4));
                temp[i][j].push_back(make_tuple(sumw/5,sums/siz,6));
            }

        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=temp[i][j];
        }
    }
    return;

}



void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j].size()<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

int check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j].size()==0)continue;
            for(int k=0;k<map[i][j].size();k++){
                int w,s,d;
                tie(w,s,d)=map[i][j][k];
                cnt+=w;
            }
        }
        
    }
    
    return cnt;
}

int main() {
    
   
    cin>>n>>m>>k;
    temp=vector<vector<vector<tuple<int,int,int>>>>(n+1,vector<vector<tuple<int,int,int>>>(n+1,vector<tuple<int,int,int>>()));
    map=vector<vector<vector<tuple<int,int,int>>>>(n+1,vector<vector<tuple<int,int,int>>>(n+1,vector<tuple<int,int,int>>()));

    for(int i=0;i<m;i++){
        int y,x,w,s,d;
        cin>>y>>x>>w>>s>>d;
        map[y][x].push_back(make_tuple(w,s,d));
    }
    

    
    for(int i=0;i<k;i++){
        move();
        //pr();
    }
    cout<<check();


    

}