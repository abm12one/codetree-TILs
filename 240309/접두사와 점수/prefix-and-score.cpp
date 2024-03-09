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
vector<int>arr;
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
int ans=0;

void insert(string s){
    trienode *t=root;
    for(int i=0;i<s.size();i++){
        int next=s[i]-'a';
        if(t->child[next]==nullptr){
            t->child[next]=new trienode();
        }
        t=t->child[next];
        t->num+=i+1;
        
        ans=max(ans,t->num);
    }

    return ;
}

void search(string s){
    trienode  *t= root;
    int flag=0;
    for(int i=0;i<s.size();i++){

        int next=s[i]-'a';
        if(t->child[next]==nullptr){
            flag=1;
            break;
        }
    
        t=t->child[next];


    }
    return;

}


int n,m;

int main() {
    
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        insert(temp);
    }

    cout<<ans<<'\n';

	
}