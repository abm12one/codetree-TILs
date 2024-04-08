#include <iostream>

using namespace std;

class node{
    public:
        string id;
        int level;
        node(){
            id="codetree";
            level=10;
        }

        node(string i,int l){
            id=i;
            level=l;


        }

};

int main() {
    string str;
    
    int time;
    cin>>str>>time;

    
    node n1=node();
    node n2=node(str,time);

    cout<<"user "<<n1.id<<" lv "<<n1.level<<'\n';
    cout<<"user "<<n2.id<<" lv "<<n2.level<<'\n';
    


        
}