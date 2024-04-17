#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <unordered_set>

using namespace std;

namespace std {
    template <> struct hash<pair<int, int> > {
        inline size_t operator()(const pair<int, int> &v) const {
            hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second);
        }
    };
}

int n,m,k;
int y,x;
int stop=0;
int t;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>>map;
list<pair<int,int>>snake;
unordered_set<pair<int,int>>body;


int isrange(int y,int x){
    if(x<1||x>n)return 0;
    if(y<1||y>n)return 0;
    return 1;
}

void move(int d,int p){
    for(int i=0;i<p;i++){
        t++;
        //cout<<snake.size()<<" "<<snake.begin()->first<<' '<<snake.begin()->second<<'\n';
        int ny=y+dy[d];
        int nx=x+dx[d];
        if(!isrange(ny,nx)){
            //cout<<"out"<<'\n';
            stop=1;
            return;
        }
        if(body.find(make_pair(ny,nx))!=body.end()){
            //cout<<ny<<' '<<nx<<'\n';
            //cout<<"twist"<<'\n';
            stop=1;
            return;
        }
        
        if(map[ny][nx]==1){
            snake.push_front(make_pair(ny,nx));
            body.insert(make_pair(ny,nx));
            map[ny][nx]=0;
            
        }
        else{
            snake.push_front(make_pair(ny,nx));
            body.insert(make_pair(ny,nx));
            body.erase(*snake.rbegin());
            snake.pop_back();
            
        }
        y=ny;
        x=nx;
        

    }

}


int main() {
    
    cin>>n>>m>>k;
    t=0;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a][b]=1;
    }
    y=1;
    x=1;
    snake.push_back(make_pair(1,1));
    body.insert(make_pair(1,1));
    for(int i=0;i<k;i++){
        char c;
        int p;
        cin>>c>>p;
        if(c=='U'){
            move(0,p);
        }
        else if(c=='R'){
            move(1,p);
        }
        else if(c=='D'){
            move(2,p);
        }
        else if(c=='L'){
            move(3,p);
        }
        if(stop==1){
            break;
        }
        
    }
    cout<<t;


}