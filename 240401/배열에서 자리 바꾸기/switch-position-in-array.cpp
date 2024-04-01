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

node* nodes[250005]={};
node* head;

void connect(node *s,node *e){
    if(s!=nullptr){
        s->next=e;
    }
    if(e!=nullptr){
        e->prev=s;
    }
}

void swap(node* a,node* b,node* c,node* d){
    
    if(head->data==a->data){
        head=c;
    }
    
    
    node *after_prevA = c->prev;
	node *after_nextB = d->next;

	node *after_prevC = a->prev;
	node *after_nextD = b->next;

	// b와 c가 붙어있는 경우 예외 처리를 해줍니다.
	if (b->next == c) {
		after_prevA = d;
		after_nextD = a;
	}
	// d와 a가 붙어있는 경우 예외 처리를 해줍니다.
	if (d->next == a) {
		after_nextB = c;
		after_prevC = b;
	}

    // 각각의 노드를 연결합니다.
	connect(after_prevA, a);
	connect(b, after_nextB);

	connect(after_prevC, c);
	connect(d, after_nextD);

}

int main(){

    int n,q;
    cin>>n>>q;
    
    for(int i=1;i<=n;i++){
        nodes[i]=new node(i);
        
    }
    for(int i=1;i<n;i++){
        connect(nodes[i],nodes[i+1]); 
    }
    head=nodes[1];

    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        swap(nodes[a],nodes[b],nodes[c],nodes[d]);
    }
    
    node *cur=head;

    while(cur!=nullptr){
        cout<<cur->data<<' ';
        cur=cur->next;
    }
    
    
 
	
}