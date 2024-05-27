#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n,k;
vector<int>dough;
vector<vector<int>>map;
vector<vector<int>>tmap;
vector<pair<int,int>>roll;
vector<int>temp;

int range(int y,int x){
    if(y<0||y>map.size()-1)return 0;
    if(x<0||x>map[0].size()-1)return 0;
    return 1;
}

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
void pr3(){
    for(int i=0;i<dough.size();i++){
       cout<<dough[i]<<' ';
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
            //cout<<row<<' '<<col<<'\n';
            setting(row,col);
            break;
        }
        rotate(row,col);
        //pr();
        
        int temp=row;
        row=col;
        col=temp;
        for(int i=0;i<col;i++){
            roll.push_back(make_pair(row,i));
        }
        row++;
    }
}

void halfandhalf(){
    //pr3();
    vector<int>first;
    vector<int>second;
    vector<int>third;
    vector<int>fourth;
    map=vector<vector<int>>(4,vector<int>(n/4,0));
    int s=0;
    for(int i=s;i<n/4;i++,s++){
        first.push_back(dough[i]);
        reverse(first.begin(),first.end());
    }
    for(int i=s;i<n/2;i++,s++){
        second.push_back(dough[i]);
    }
    for(int i=s;i<n/4*3;i++,s++){
        third.push_back(dough[i]);
        reverse(third.begin(),third.end());
    }
    for(int i=s;i<n;i++,s++){
        fourth.push_back(dough[i]);
    }
    for(int i=0;i<n/4;i++){
        map[2][i]=first[i];
        map[1][i]=second[i];
        map[0][i]=third[i];
        map[3][i]=fourth[i];
        
    }
    //pr2();
    return;
    
    

}


int dy[2]={1,0};
int dx[2]={0,1};

void push(){
    
    tmap=vector<vector<int>>(map.size(),vector<int>(map[0].size()));

    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            if(map[i][j]==0)continue;
            for(int k=0;k<2;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]==0)continue;
                int now=map[i][j];
                int next=map[ny][nx];
                int dif=(now-next)/5;
                tmap[i][j]-=dif;
                tmap[ny][nx]+=dif;

            }
            
        }
    }

    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            map[i][j]+=tmap[i][j];     
        }
    }


    temp=vector<int>();
    
    for(int j=map[0].size()-1;j>=0;j--){
        for(int i=0;i<map.size();i++){
            if(map[i][j]==0){
                continue;
            }
            temp.push_back(map[i][j]);
        }
    }
    reverse(temp.begin(),temp.end());
    dough=temp;
    return;
}



void sol(){
    plusone();
    rollup();
    //pr2();
    push();
    //pr2();
    halfandhalf();
    push();
    //pr3();
}

int check(){
    int mmin=987654321;
    int mmax=0;
    for(int i=0;i<n;i++){
        if(mmin>dough[i]){
            mmin=dough[i];
        }
        if(mmax<dough[i]){
            mmax=dough[i];
        }
    }
    if(mmax-mmin<=k)return 1;
    return 0;
}


int main() {
    
    cin>>n>>k;
    dough=vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>dough[i];
    }

    for(int i=1;i<=3000;i++){
        sol();
        if(check()){
            cout<<i<<'\n';
            break;
        }
    }
    return 0;



}