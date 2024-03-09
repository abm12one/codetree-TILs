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

vector<string>words;

class trienode{
    public:
        trienode *child[26];
        int isend;
        int num;
        trienode(){
            isend=0;
            num=0;
            for(int i=0;i<26;i++){
                child[i]=nullptr;
            }
        }

};

trienode *root=new trienode();


void insert(string s){
    trienode *t=root;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'a';
        if(t->child[next]==nullptr){
            t->num++;
            t->child[next]=new trienode();
        }
        t=t->child[next];
       
    }
    t->isend=1;

    return ;
}

void search(string s){
    trienode  *t= root;
    int cnt=0;
    for(int i=0;i<s.size();i++){

        int next=s[i]-'a';
        if(t==root||t->isend||t->num>1){
            cnt++;
        }
    
        t=t->child[next];


    }
    cout<<cnt<<' ';
    return;

}


int n,m;

int main() {
    
    cin>>n;
    
    words=vector<string>(n);

    for(int i=0;i<n;i++){
        cin>>words[i];
        insert(words[i]);
    }
    for(int i=0;i<n;i++){
        search(words[i]);
    }

    

	
}