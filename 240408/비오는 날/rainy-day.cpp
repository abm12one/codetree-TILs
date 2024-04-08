#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
using namespace std;

class node{
    public:
        string name;
        string number;
        string place;

        node(string a="9999-99-99",string b="yes", string c="yes"){
            name=a;
            number=b;
            place=c;
        }
        node(){}

        bool operator < (node & n1){
            return this->name < n1.name;
        }
};


vector<node>nodes;

int main() {
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string a,b,c;
        cin>>a>>b>>c;
        if(c=="Rain"){
            nodes.push_back(node(a,b,c));
        }
        
    }

    sort(nodes.begin(),nodes.end());
    cout<<nodes[0].name<<" "<<nodes[0].number<<' '<<nodes[0].place<<'\n';
    
    


        
}