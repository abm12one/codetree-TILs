#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits.h>
#include<cassert>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define MAX_M 100000

using namespace std;
int n;
int t;
vector<string>words;

class trienode{
    public:
        map<string,trienode*>child;



};

trienode *root=new trienode();

void insert(vector<string>s){
    trienode *t=root;
    for(int i=0;i<s.size();i++){
        string next=s[i];
        if(!t->child[next]){
            t->child[next]=new trienode();
        }
        t=t->child[next];
    }
    
    return;

}

void search(trienode*root,int d){
    trienode *t=root;
    for(auto it=t->child.begin();it!=t->child.end();it++){
        string next=it->first;
        for(int i=0;i<d;i++){
            cout<<"--";
        }
        cout<<next<<'\n';
        search(t->child[next],d+1);
            
    }
    return ;



}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>t;
        words=vector<string>(t);
        for(int j=0;j<t;j++){
            cin>>words[j];
        }
        insert(words);

    }
    search(root,0);

    
	
}