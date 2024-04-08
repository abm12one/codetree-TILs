#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
using namespace std;

class node{
    public:
        char grade;
        int score;

        node(char g,int sc){
            grade=g;
            score=sc;
        }
        node(){}

        bool operator < (node & n1){
            return this->score < n1.score;
        }
};

bool cmp(node n1,node n2){
    return n1.score>n2.score;
}

vector<node>nodes(5);

int main() {
    for(int i=0;i<5;i++){
        char c;
        int t;
        cin>>c>>t;
        nodes[i]=node(c,t);
    }
    sort(nodes.begin(),nodes.end());
    cout<<nodes[0].grade<<' '<<nodes[0].score;
    


        
}