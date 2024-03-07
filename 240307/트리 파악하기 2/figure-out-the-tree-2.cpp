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
//#include< map>
#include<unordered_set>
#include<set>
#define MAX_M 100000

using namespace std;

class trienode{
    public:
        trienode *child[26];
        int isend;

        trienode(){
            for(int i=0;i<26;i++){
                child[i]=nullptr;
            }

        }

};

trienode *root=new trienode();

void insert(string s){
    trienode *t=root;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'A';
        if(t->child[next]==nullptr){
            t->child[next]=new trienode();
        }
        t=t->child[next];
    }
    t->isend=1;

}

void solve(trienode *root,int cnt){
    trienode *t=root;
    /*
    if(t->isend==0){
        return;
    }
    */
    for(int i=0;i<26;i++){
        if(t->child[i]==nullptr)continue;
        for(int j=0;j<cnt-1;j++){
            cout<<"--";
        }
        char c='A'+i;
        cout<<c<<'\n';
        solve(t->child[i],cnt+1);

    }
    return;

}


int n;
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        string str="";
        for(int j=0;j<m;j++){
            string temp;
            cin>>temp;
            str=str+temp;

        }
        insert(str);
    }
    solve(root,1);
	
}