#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>>blue;
vector<vector<int>>yellow;
vector<vector<int>>red;

int findr(int y){
    for(int i=0;i<6;i++){
        if(red[y][i]==1){
            return i;
        }
    }
    return 6;
}
int findy(int x){
    for(int i=0;i<6;i++){
        if(yellow[i][x]==1){
            return i;
        }
    }
    return 6;
}


void set(int t,int y,int x){
    if(t==1){
        
        int nx=findr(y);
        red[y][nx-1]=1;

        int ny=findy(x);
        yellow[ny-1][x]=1;
       
    }
    else if(t==2){
        
        int nx=findr(y);
        red[y][nx-1]=1;
        red[y][nx-2]=1;
        
        int ny=min(findy(x),findy(x+1));

        yellow[ny-1][x]=1;
        yellow[ny-1][x+1]=1;




    }
    else if(t==3){

        int ny=findy(x);
        yellow[ny-1][x]=1;
        yellow[ny-2][x]=1;
        int nx=min(findr(y),findr(y+1));
        red[y][nx-1]=1;
        red[y+1][nx-1]=1;

    }
    return;
}

int checkred(){
    for(int i=0;i<4;i++){
        if(red[i][0]==1){
            return 2;
        }
    }
    for(int i=0;i<4;i++){
        if(red[i][1]==1){
            return 1;
        }
    }
    return 0;

}
int checkyellow(){
    for(int i=0;i<4;i++){
        if(yellow[0][i]==1){
            return 2;
        }
    }
    for(int i=0;i<4;i++){
        if(yellow[1][i]==1){
            return 1;
        }
    }
    return 0;



}

void movered(int n){
    for(int j=5;j>=2;j--){
        for(int i=0;i<4;i++){
            red[i][j]=red[i][j-n];
            red[i][j-n]=0;
        }
    }
    return;
}
void moveyellow(int n){
    for(int i=5;i>=2;i--){
        for(int j=0;j<4;j++){
            yellow[i][j]=yellow[i-n][j];
            yellow[i-n][j]=0;
        }
    }
    return;
}

void sol(){
    int mr=checkred();
    int my=checkyellow();

    if(mr!=0){
        movered(mr);
    }

    if(my!=0){
        moveyellow(my);
    }
    return;
}

void pr(){
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            cout<<yellow[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            cout<<red[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void erasered(int x){
    for(int j=x;j>=2;j--){
        for(int i=0;i<4;i++){
            red[i][j]=red[i][j-1];
            red[i][j-1]=0;
        }
    }
}
void eraseyellow(int y){
    for(int i=y;i>=2;i--){
        for(int j=0;j<4;j++){
            yellow[i][j]=yellow[i-1][j];
            yellow[i-1][j]=0;
        }
    }
}
int ans=0;
void sol2(){
    for(int i=2;i<6;i++){
        if(red[0][i]==1&&red[1][i]==1&&red[2][i]==1&&red[3][i]==1){
            erasered(i);
            ans++;
        }
    }
    for(int i=2;i<6;i++){
        if(yellow[i][0]==1&&yellow[i][1]==1&&yellow[i][2]==1&&yellow[i][3]==1){
            eraseyellow(i);
            ans++;
        }
    }

}


int main() {
    
    cin>>n;

    blue=vector<vector<int>>(4,vector<int>(4));
    red=vector<vector<int>>(4,vector<int>(6));
    yellow=vector<vector<int>>(6,vector<int>(4));
    for(int i=0;i<n;i++){
        int t,y,x;
        cin>>t>>y>>x;
        set(t,y,x);
        sol2();
        sol();
        //pr();
    }
    cout<<ans<<"\n";
    
    int cnt=0;
    for(int i=0;i<4;i++){
        for(int j=2;j<6;j++){
            if(red[i][j]==1){
                cnt++;
            }
        }
    }
    for(int i=2;i<6;i++){
        for(int j=0;j<4;j++){
            if(yellow[i][j]==1){
                cnt++;
            }
        }
    }
    cout<<cnt;
    

}