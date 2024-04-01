#include <iostream>
#include <vector>

#define MAX_N 250000
#define MAX_K 100

using namespace std;
vector<int>arr;

struct node{
    int data;
    node*prev;
    node*next;
    node(int data):data(data),prev(nullptr),next(nullptr){};
};

node* nodes[100000001];

void connect(node *s,node*e){
    if(s!=nullptr){
        s->next=e;
    }
    if(e!=nullptr){
        e->prev=s;
    }

}

void pr(node* now){
    cout<<now->next->data<<" ";
    cout<<now->prev->data<<'\n';
}

void pop(node *s){
    connect(s->prev,s->next);
    s->prev=nullptr;
    s->next=nullptr;

}

int main() {

    int n,q;
    cin>>n>>q;

    arr=vector<int>(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        nodes[arr[i]]=new node(arr[i]);
    }

    for(int i=1;i<n;i++){
        connect(nodes[arr[i]],nodes[arr[i+1]]);
    }

    connect(nodes[arr[n]],nodes[arr[1]]);

    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        pr(nodes[t]);
        pop(nodes[t]);
    }

    

    
    

}