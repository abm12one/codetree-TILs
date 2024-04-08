#include <iostream>
#include <vector>

using namespace std;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int ans;
int main() {

    string str;
    cin>>str;
    int d=0;
    int y=0;
    int x=0;
    int num=0;
    int flag=0;
    
    for(int i=0;i<str.size();i++){
        num++;
        char c=str[i];
        if(c=='L'){
            d=(d-1+4)%4;

        }
        else if(c=='R'){
            d=(d+1)%4;
        }
        else if(c=='F'){
            int ny=y+dy[d];
            int nx=x+dx[d];
            if(ny==0&&nx==0&&flag==0){
                ans=num;
                flag=1;
                break;
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