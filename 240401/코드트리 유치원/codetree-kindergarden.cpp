#include <iostream>

using namespace std;

struct node{
    int data;
    node*prev;
    node*next;

    node(int data):data(data),prev(nullptr),next(nullptr){};

};

int sum=1;
node* nodes[100001]={};

void connect(node *s,node*e){
    if(s!=nullptr){
        s->next=e;
    }
    if(e!=nullptr){
        e->prev=s;
    }

}

void insertnext(node *t,node *a,node*b){
    if(t->next->data==a->data){
        return;
    }
    node*nt=t->next;
    node*pa=a->prev;
    node*nb=b->next;
    connect(b,nt);
    connect(t,a);
    connect(pa,nb);


}

void insertprev(node *t,node *a,node*b){
    
    node*pt=t->prev;
    node*pa=a->prev;
    node*nb=b->next;

    if(pt!=nullptr){
        connect(pt,a);
    }
    else{
        a->prev=nullptr;
    }
    connect(b,t);
    connect(pa,nb);

}

void pr(node*now){
    
    if(now->prev==nullptr){
        cout<<-1<<'\n';

        return;
    }
    if(now->next==nullptr){
        cout<<-1<<'\n';
        return;
    }
    if(now->next->data>sum){
        cout<<-1<<'\n';
        return;
    }
    cout<<now->prev->data<<" "<<now->next->data<<'\n';


}
void pri(node*now){
    
    if(now->prev==nullptr){
        cout<<"null"<<' ';
    }
    else{
        cout<<now->prev->data<<" ";
    }
    
    cout<<now->next->data<<"\n";


}

int main() {
    int q;
    cin>>q;

    for(int i=1;i<=100000;i++){
        nodes[i]=new node(i);
    }

    for(int i=1;i<100000;i++){
        connect(nodes[i],nodes[i+1]);
    }


    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;

            insertnext(nodes[a],nodes[sum+1],nodes[sum+b]);
            sum+=b;


        }
        else if(t==2){
            int a,b;
            cin>>a>>b;

            insertprev(nodes[a],nodes[sum+1],nodes[sum+b]);
            sum+=b;
        }
        else if(t==3){
            int a;
            cin>>a;
            pr(nodes[a]);
        }


    }




}