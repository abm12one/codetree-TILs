#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n,k;
vector<int>dough;
vector<vector<int>>map;
vector<pair<int,int>>roll;
vector<int>temp;
void plusone(){
    int mmin=987654321;
    for(int i=0;i<n;i++){
        if(mmin>dough[i]){
            mmin=dough[i];
        }
    }
    for(int i=0;i<n;i++){
        if(mmin==dough[i]){
            dough[i]++;
        }
    }
    return;
}

void rotate(int row,int col){

    for(int i=0;i<roll.size();i++){
        int y,x;
        tie(y,x)=roll[i];
        roll[i]=make_pair(x,row-y-1);
    }
    return;

}

void pr(){
    for(int i=0;i<roll.size();i++){
        int y,x;
        tie(y,x)=roll[i];
        cout<<"("<<y<<' '<<x<<")"<<" ";
    }
    cout<<"\n";
    return;
}

void pr2(){
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n";
    return;
}

void setting(int row,int col){
    map=vector<vector<int>>(row,vector<int>(col+n-roll.size()));
    for(int i=0;i<roll.size();i++){
        int y,x;
        tie(y,x)=roll[i];
        map[y][x]=dough[i];
    }
    int s=col;
    for(int i=roll.size();i<n;i++){
        map[row-1][s++]=dough[i];
    }

    return;
}

void rollup(){
    roll=vector<pair<int,int>>();
    roll.push_back(make_pair(0,0));
    roll.push_back(make_pair(1,0));
    int row=2;
    int col=1;

    while(1){
        if(n-roll.size()<row){
            cout<<row<<' '<<col<<'\n';
            setting(row,col);
            break;
        }
        rotate(row,col);
        pr();
        
        int temp=row;
        row=col;
        col=temp;
        for(int i=0;i<col;i++){
            roll.push_back(make_pair(row,i));
        }
        row++;
    }
}



void sol(){
    plusone();
    rollup();
    pr2();
    //push();

}


int main() {
    
    cin>>n>>k;
    dough=vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>dough[i];
    }

    sol();



}