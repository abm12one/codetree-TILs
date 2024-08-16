#include <iostream>
#include <vector>
using namespace std;

struct node{

    int data;
    node*prev;
    node*next;
    node(int d){
        data=d;
        prev=nullptr;
        next=nullptr;
    }

};
int n;
vector<node*>narr;

void remove(node*ptr){
    node*pp=ptr->prev;
    node*pn=ptr->next;
    if(pp!=nullptr){
        pp->next=pn;
    }
    if(pn!=nullptr){
        pn->prev=pp;
    }
    ptr->prev=nullptr;
    ptr->next=nullptr;
    return;

}

void insertprev(node*i,node*j){
    node*ip=i->prev;
    j->prev=ip;
    j->next=i;

    if(j->next!=nullptr){
        j->next->prev=j;
    }
    if(j->prev!=nullptr){
        j->prev->next=j;
    }
    return;

}

void insertnext(node*i,node*j){
    node*inn=i->next;
    j->prev=i;
    j->next=inn;

    if(j->next!=nullptr){
        j->next->prev=j;
    }
    if(j->prev!=nullptr){
        j->prev->next=j;
    }
    return;

}

void pr(node*ptr){
    if(ptr->prev!=nullptr){
        cout<<ptr->prev->data<<" ";
    }
    else {
        cout<<0<<" ";
    }

    if(ptr->next!=nullptr){
        cout<<ptr->next->data<<" ";
    }
    else {
        cout<<0<<" ";
    }
    cout<<'\n';
    return;


}
void pullpr(){
    for(int i=1;i<=n;i++){
        if(narr[i]->next!=nullptr){
            cout<<narr[i]->next->data<<" ";
        }
        else{
            cout<<0<<" ";
        }
    }
    cout<<"\n";
}
int main() {
  
    cin>>n;
    narr=vector<node*>(n+1);
    for(int i=1;i<=n;i++){
        narr[i]=new node(i);
    }
    int r;
    cin>>r;
    for(int i=0;i<r;i++){
        int k;
        cin>>k;
        if(k==1){
            int temp;
            cin>>temp;
            remove(narr[temp]);
        }
        else if(k==2){
            int a,b;
            cin>>a>>b;
            insertprev(narr[a],narr[b]);
        }
        else if(k==3){
            int a,b;
            cin>>a>>b;
            insertnext(narr[a],narr[b]);

        }
        else if(k==4){
            int temp;
            cin>>temp;
            pr(narr[temp]);

        }
        
    }
    pullpr();
    
    return 0;


}