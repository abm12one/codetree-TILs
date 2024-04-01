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
//#include<unordered_map>
//#include<map>
//#include<unordered_set>
//#include<set>

using namespace std;

struct node{
    int data;
    node*prev;
    node*next;

    node(int data):data(data),prev(nullptr),next(nullptr){};  
};

node* nodes[10005]={};

void connect(node*s,node*e){
    if(s!=nullptr){
        s->next=e;
    }
    if(e!=nullptr){
        e->prev=s;
    }
}

void insertprev(node*t,node*now){
    now->prev=t->prev;
    now->next=t;

    if(now->prev!=nullptr){
        now->prev->next=now;
    }
    if(now->next!=nullptr){
        now->next->prev=now;
    }
    
}
void insertnext(node*t,node*now){
    now->next=t->next;
    now->prev=t;

    if(now->prev!=nullptr){
        now->prev->next=now;
    }
    if(now->next!=nullptr){
        now->next->prev=now;
    }
    
}

void pop(node *s){

    if(s->prev!=nullptr){
        s->prev->next=s->next;
    }
    
    if(s->next!=nullptr){
        s->next->prev=s->prev;
    }
    s->prev=nullptr;
    s->next=nullptr;
    return;

}


int main(){
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        nodes[i]=new node(i);
    }

    for(int k=0;k<q;k++){
        int t,i,j;
        cin>>t>>i;
        if(t==1){
            
            pop(nodes[i]);

        }
        else if(t==2){
            cin>>j;
            insertprev(nodes[i],nodes[j]);
        }
        else if(t==3){
            cin>>j;
            insertnext(nodes[i],nodes[j]);
        }
        else if(t==4){
            cout<<((nodes[i]->prev == nullptr) ? 0 : nodes[i]->prev->data)<<' ';
            cout<<((nodes[i]->next == nullptr) ? 0 : nodes[i]->next->data)<<'\n';

        }

    }
    for(int i=1;i<=n;i++){
        cout << ((nodes[i]->next == nullptr) ? 0 : nodes[i]->next->data) << ' ';
    }


	
}