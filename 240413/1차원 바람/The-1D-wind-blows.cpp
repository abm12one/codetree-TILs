#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n,m,q;
vector<vector<int>>map;

void shift(int col,int p){
    if(p==1){
        int temp=map[col][0];
        for(int i=1;i<m;i++){
            map[col][i-1]=map[col][i];
        }
        map[col][m-1]=temp;

    }
    else{
        int temp=map[col][m-1];
        for(int i=m-2;i>=0;i--){
            map[col][i+1]=map[col][i];
        }
        map[col][0]=temp;
    }
    return;
}

int checkup(int col){
    if(col-1<0)return 0;

    for(int i=0;i<m;i++){
        if(map[col][i]==map[col-1][i])return 1;
    }
    return 0;

}
int checkdown(int col){
    if(col+1>=n)return 0;

    for(int i=0;i<m;i++){
        if(map[col][i]==map[col+1][i])return 1;
    }
    return 0;

}


void pushup(int col,int p){

    shift(col,p);
    if(checkup(col)){
        pushup(col-1,1-p);
    }
    return;
}

void pushdown(int col,int p){
    shift(col,p);
    if(checkdown(col)){
        pushdown(col+1,1-p);
    }
    return;
}

void push(int col,int p){

    shift(col,p);
    
    if(checkup(col)){
        pushup(col-1,1-p);
    }
    if(checkdown(col)){
        pushdown(col+1,1-p);
    }
    

    return;
}

int main() {

    
    cin>>n>>m>>q;
    map=vector<vector<int>>(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<q;i++){
        int col;
        char p;
        cin>>col>>p;
        if(p=='L'){
            push(col-1,0);
        }
        else if(p=='R'){
            push(col-1,1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }


    
    

 


}