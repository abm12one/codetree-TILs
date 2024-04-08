#include <iostream>
#include <vector>

using namespace std;

int ans=0;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

int findd(char c){
    if(c=='N'){
        return 0;
    }
    else if(c=='E'){
        return 1;
    }
    else if(c=='S'){
        return 2;
    }
    else if(c=='W'){
        return 3;
    }


}

int main() {
    int n;
    cin>>n;
    
    int num=0;

    int y=0;
    int x=0;
    int flag=0;

    for(int i=0;i<n;i++){
        char c;
        int t;
        cin>>c>>t;
        
        int d=findd(c);
        for(int j=0;j<t;j++){
            int ny=y+dy[d];
            int nx=x+dx[d];
            num++;

            if(ny==0&&nx==0&&flag==0){
                ans=num;
                flag=1;
            }
            y=ny;
            x=nx;
        }



    }
    if(flag==0){
        cout<<-1;
    }
    else{
        cout<<ans;
    }



    

 
    
}