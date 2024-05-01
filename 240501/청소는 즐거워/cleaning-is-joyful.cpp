#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<int>>map;
int d=0;
int dy[4]={0,1,0,-1};
int dx[4]={-1,0,1,0};
int isrange(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

void sol(int y,int x,int d){
    int sum=map[y][x];
    int ret=sum;
    if(d==0){

        int temp=(sum*5)/100;
        if(isrange(y,x-2)){
            map[y][x-2]+=temp;  
        }
        ret-=temp;
        
        temp=(sum*10)/100;
        if(isrange(y-1,x-1)){
            map[y-1][x-1]+=temp;
        }
        ret-=temp;
        if(isrange(y+1,x-1)){
            map[y+1][x-1]+=temp;
        }
        ret-=temp;

        temp=(sum*2)/100;
        if(isrange(y-2,x)){
            map[y-2][x]+=temp;
            
        }
        ret-=temp;
        if(isrange(y+2,x)){
            map[y+2][x]+=temp;
            
        }
        ret-=temp;

        temp=(sum*7)/100;
        if(isrange(y-1,x)){
            map[y-1][x]+=temp;
            
        }
        ret-=temp;
        if(isrange(y+1,x)){
            map[y+1][x]+=temp;
            
        }
        ret-=temp;

        temp=(sum*1)/100;
        if(isrange(y-1,x+1)){
            map[y-1][x+1]+=temp;
            
        }
        ret-=temp;
        if(isrange(y+1,x+1)){
            map[y+1][x+1]+=temp;
            
        }
        ret-=temp;

        if(isrange(y,x-1)){
            map[y][x-1]+=ret;
        }

    }
    else if(d==3){
        int temp=(sum*5)/100;
        if(isrange(y-2,x)){
            map[y-2][x]+=temp;  
        }
        ret-=temp;
        
        temp=(sum*10)/100;
        if(isrange(y-1,x-1)){
            map[y-1][x-1]+=temp;
        }
        ret-=temp;
        if(isrange(y-1,x+1)){
            map[y-1][x+1]+=temp;
        }
        ret-=temp;

        temp=(sum*2)/100;
        if(isrange(y,x+2)){
            map[y][x+2]+=temp;
            
        }
        ret-=temp;
        if(isrange(y,x-2)){
            map[y][x-2]+=temp;
            
        }
        ret-=temp;

        temp=(sum*7)/100;
        if(isrange(y,x+1)){
            map[y][x+1]+=temp;
            
        }
        ret-=temp;
        if(isrange(y,x-1)){
            map[y][x-1]+=temp;
            
        }
        ret-=temp;

        temp=(sum*1)/100;
        if(isrange(y+1,x+1)){
            map[y+1][x+1]+=temp;
            
        }
        ret-=temp;
        if(isrange(y+1,x-1)){
            map[y+1][x-1]+=temp;
            
        }
        ret-=temp;

        if(isrange(y-1,x)){
            map[y-1][x]+=ret;
        }
    }
    else if(d==2){
        int temp=(sum*5)/100;
        if(isrange(y,x+2)){
            map[y][x+2]+=temp;  
        }
        ret-=temp;
        
        temp=(sum*10)/100;
        if(isrange(y-1,x+1)){
            map[y-1][x+1]+=temp;
        }
        ret-=temp;
        if(isrange(y+1,x+1)){
            map[y+1][x+1]+=temp;
        }
        ret-=temp;

        temp=(sum*2)/100;
        if(isrange(y-2,x)){
            map[y-2][x]+=temp;
            
        }
        ret-=temp;
        if(isrange(y+2,x)){
            map[y+2][x]+=temp;
            
        }
        ret-=temp;

        temp=(sum*7)/100;
        if(isrange(y-1,x)){
            map[y-1][x]+=temp;
            
        }
        ret-=temp;
        if(isrange(y+1,x)){
            map[y+1][x]+=temp;
            
        }
        ret-=temp;

        temp=(sum*1)/100;
        if(isrange(y-1,x-1)){
            map[y-1][x-1]+=temp;
            
        }
        ret-=temp;
        if(isrange(y+1,x-1)){
            map[y+1][x-1]+=temp;
            
        }
        ret-=temp;

        if(isrange(y,x+1)){
            map[y][x+1]+=ret;
        }

    }
    else if(d==1){
        int temp=(sum*5)/100;
        if(isrange(y+2,x)){
            map[y+2][x]+=temp;  
        }
        ret-=temp;
        
        temp=(sum*10)/100;
        if(isrange(y+1,x-1)){
            map[y+1][x-1]+=temp;
        }
        ret-=temp;
        if(isrange(y+1,x+1)){
            map[y+1][x+1]+=temp;
        }
        ret-=temp;

        temp=(sum*2)/100;
        if(isrange(y,x+2)){
            map[y][x+2]+=temp;
            
        }
        ret-=temp;
        if(isrange(y,x-2)){
            map[y][x-2]+=temp;
            
        }
        ret-=temp;

        temp=(sum*7)/100;
        if(isrange(y,x+1)){
            map[y][x+1]+=temp;
            
        }
        ret-=temp;
        if(isrange(y,x-1)){
            map[y][x-1]+=temp;
            
        }
        ret-=temp;

        temp=(sum*1)/100;
        if(isrange(y-1,x+1)){
            map[y-1][x+1]+=temp;
            
        }
        ret-=temp;
        if(isrange(y-1,x-1)){
            map[y-1][x-1]+=temp;
            
        }
        ret-=temp;

        if(isrange(y+1,x)){
            map[y+1][x]+=ret;
        }
    }

    map[y][x]=0;
    return;

}

int pr(){
    int ret=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ret+=map[i][j];
            //cout<<map[i][j]<<' ';
        }
        //cout<<'\n';
    }
    //cout<<'\n';
    return ret;
}
int main() {
    
    cin>>n;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    int msum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            msum+=map[i][j];
        }
    }

    int cnt=0;
    int sum=0;
    int y=(n+1)/2;
    int x=(n+1)/2;
    int ny,nx;
    while(1){
        
        if(!isrange(y,x))break;
        if(d%2==0){
            cnt++;
        }
        for(int k=0;k<cnt;k++){
            ny=y+dy[d];
            nx=x+dx[d];
            //cout<<ny<<" "<<nx<<" "<<d<<"\n";
            sol(ny,nx,d);
            //pr();
            y=ny;
            x=nx;
        }
        d=(d+1)%4;
    }
    int nsum=pr();
    cout<<msum-nsum;


}