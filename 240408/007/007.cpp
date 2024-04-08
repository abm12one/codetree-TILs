#include <iostream>

using namespace std;

class node{
    public:
        string code;
        char place;
        int time;
        node(string code,char place,int time){
            this->code=code;
            this->place=place;
            this->time=time;


        }

};

int main() {
    string str;
    char c;
    int time;
    cin>>str>>c>>time;

    node n=node(str,c,time);

    cout<<"secret code : "<<n.code<<'\n';
    cout<<"meeting point : "<<n.place<<'\n';
    cout<<"time : "<<n.time<<'\n';


        
}