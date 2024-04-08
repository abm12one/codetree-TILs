#include <iostream>

using namespace std;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

int main() {

    string str;
    cin>>str;
    int d=0;
    int y=0;
    int x=0;

    for(int i=0;i<str.size();i++){
        char t=str[i];
        if(t=='L'){
            d=(d-1+4)%4;
            
        }
        else if(t=='R'){
            d=(d+1)%4;
        }
        else if(t=='F'){
            x+=dx[d];
            y+=dy[d];
        }




    }
    cout<<x<<" "<<y;


    
}