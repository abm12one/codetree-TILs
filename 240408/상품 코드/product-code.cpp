#include <iostream>

using namespace std;

class node{
    public:
        string id;
        int level;

        node(string i="codetree",int l=50){
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

    cout<<"product "<<n1.level<<" is "<<n1.id<<'\n';
    cout<<"product "<<n2.level<<" is "<<n2.id<<'\n';
    


        
}