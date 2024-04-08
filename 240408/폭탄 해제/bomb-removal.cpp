#include <iostream>

using namespace std;

class node{
    public:
        string code;
        char place;
        int time;
        node(string c,char p,int t){
            code=c;
            place=p;
            time=t;


        }

};

int main() {
    string str;
    char c;
    int time;
    cin>>str>>c>>time;

    node n=node(str,c,time);

    cout<<"code : "<<n.code<<'\n';
    cout<<"color : "<<n.place<<'\n';
    cout<<"second : "<<n.time<<'\n';


        
}