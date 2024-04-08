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

        node(string a,string b, string c){
            name=a;
            number=b;
            place=c;
        }
        node(){}

        bool operator < (node & n1){
            return this->name > n1.name;
        }
};


vector<node>nodes;

int main() {
    int n;
    cin>>n;
    nodes=vector<node>(n);
    for(int i=0;i<n;i++){
        string a,b,c;
        cin>>a>>b>>c;
        nodes[i]=node(a,b,c);
    }

    sort(nodes.begin(),nodes.end());
    cout<<"name "<<nodes[0].name<<'\n';
    cout<<"addr "<<nodes[0].number<<'\n';
    cout<<"city "<<nodes[0].place<<'\n';
    
    


        
}