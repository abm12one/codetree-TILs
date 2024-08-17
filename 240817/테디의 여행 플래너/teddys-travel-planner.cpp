#include <iostream>
#include <vector>
using namespace std;

struct node{
    string data;
    node*prev;
    node*next;
    node(string d){
        data=d;
        prev=nullptr;
        next=nullptr;
    }
};

int n,k;
vector<node*>narr;
node*cur;
int s=0;
void connect(node*a,node*b){
    if(a!=nullptr){
        a->next=b;
    }
    if(b!=nullptr){
        b->prev=a;
    }
    return;
}

void remove(){
    
    s--;
    node*cnn=cur->next->next;
    connect(cur,cnn);

    
    return;
}

void add(string str){
    s++;
    node *now=new node(str);

    node*cn=cur->next;
    now->prev=cur;
    now->next=cn;

    connect(cur,now);
    connect(now,cn);
    
    return;

}

void pr(){
    if(s==1){
        cout<<-1<<'\n';
        return;
    }
    node*p=cur->prev;
    node*n=cur->next;
    if(p->data==n->data){
        cout<<-1<<'\n';
        return;
    }
    cout<<p->data<<" "<<n->data<<'\n';
    return;

}

int main() {

    cin>>n>>k;
    narr=vector<node*>(n+1);
    s=n;
    for(int i=1;i<=n;i++){
        string temp;
        cin>>temp;
        narr[i]=new node(temp);
    }

    cur=narr[1];

    for(int i=1;i<n;i++){
        connect(narr[i],narr[i+1]);
    }
    connect(narr[n],narr[1]);

    for(int i=0;i<k;i++){
        int com;
        cin>>com;
        if(com==1){
            if(s!=1){
                cur=cur->next;
            } 

        }
        else if(com==2){
            if(s!=1){
                cur=cur->prev;
            }
            
        }
        else if(com==3){
            if(s!=1){
                remove();
            }

        }
        else if(com==4){
            string temp;
            cin>>temp;
            add(temp);
        }
        pr();
    }
}