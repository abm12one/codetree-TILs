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

vector<node*>narr;

void connect(node*a,node*b){
    if(a!=nullptr){
        a->next=b;
    }
    if(b!=nullptr){
        b->prev=a;
    }
    return;
}

int now=1;

int main() {
    
    int n;
    cin>>n;
    narr=vector<node*>(100000+1);
    for(int i=1;i<=100000;i++){
        narr[i]=new node(i);
    }

    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k==1){
            int a,b;
            cin>>a>>b;

            for(int i=now+1;i<now+b;i++){
                connect(narr[i],narr[i+1]);
            }
       

            node*an=narr[a]->next;
            connect(narr[a],narr[now+1]);
            connect(narr[now+b],an);

            now+=b;
        }
        else if(k==2){
            int a,b;
            cin>>a>>b;

            for(int i=now+1;i<now+b;i++){
                connect(narr[i],narr[i+1]);
            }

            node*ap=narr[a]->prev;
            connect(ap,narr[now+1]);
            connect(narr[now+b],narr[a]);
            now+=b;
        }
        else if(k==3){
            int a;
            cin>>a;
            if(narr[a]->prev==nullptr){
                cout<<-1<<'\n';
                continue;                
            } 
            if(narr[a]->next==nullptr){
                cout<<-1<<'\n';
                continue;                
            } 
            cout<<narr[a]->prev->data<<" "<<narr[a]->next->data<<'\n';
        }
    }

}