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
int n;
class trienode{
    public:
        trienode *child[10];
        int isend;

        trienode(){
            isend=0;
            for(int i=0;i<10;i++){
                child[i]=nullptr;
            }
        }

};

trienode *root=new trienode();

void insert(string s){
    trienode *t=root;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'0';
        if(t->child[next]==nullptr){
            t->child[next]=new trienode();

        }
        t=t->child[next];
    }
    t->isend=1;


}

int search(string s){
    trienode *t=root;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'0';
        if(t->isend==1){
            return 1;
        }
        t=t->child[next];
    }
    return 0;

}




int main() {
    
    cin>>n;
    vector<string>words(n);

    for(int i=0;i<n;i++){
        cin>>words[i];
        insert(words[i]);
    }

    int flag=0;
    
    for(int i=0;i<n;i++){
        if(search(words[i])){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<0<<"\n";

    }
    else{
        cout<<1<<"\n";
    }






	
}