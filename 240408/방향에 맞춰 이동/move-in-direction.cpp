#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int y=0;
    int x=0;
    for(int i=0;i<n;i++){
        string str;
        int t;
        cin>>str>>t;

        if(str=="N"){
            for(int j=0;j<t;j++){
                y+=1;
            }
        }
        else if(str=="E"){
            for(int j=0;j<t;j++){
                x+=1;
            }
        }
        else if(str=="S"){
            for(int j=0;j<t;j++){
                y+=-1;
            }
        }
        else if(str=="W"){
            for(int j=0;j<t;j++){
                x+=-1;
            }
        }

    }
    cout<<x<<" "<<y;
}