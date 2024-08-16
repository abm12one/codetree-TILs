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
int n;
void connect(node*a,node*b){
    if(a!=nullptr){
        a->next=b;
    }
    if(b!=nullptr){
        b->prev=a;
    }
    return;
}
node*head;

void pr(){
    node*ptr=head;
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<'\n';
    return;
}
void pre(){
    for(int i=1;i<=n;i++){
        if(narr[i]->prev!=nullptr){
            cout<<narr[i]->prev->data<<" ";
        }
        else {
            cout<<"null ";
        }
        if(narr[i]!=nullptr){
            cout<<narr[i]->data<<" ";
        }
        else {
            cout<<"null ";
        }
        if(narr[i]->next!=nullptr){
            cout<<narr[i]->next->data<<" ";
        }
        else {
            cout<<"null ";
        }
        cout<<'\n';


    }
    
    cout<<'\n';
}

int main() {
    
    cin>>n;
    narr=vector<node*>(n+1);

    for(int i=1;i<=n;i++){
        narr[i]=new node(i);
    }
    head=narr[1];
    for(int i=1;i<n;i++){
        connect(narr[i],narr[i+1]);
    }

    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==1){
            head=narr[c];
            cout<<"ch "<<head->data<<"\n";
        }
        node*ap=narr[a]->prev;
        node*bn=narr[b]->next;
        node*cp=narr[c]->prev;
        node*dn=narr[d]->next;


        if(narr[b]->next==narr[c]){
            cp=narr[d];
            bn=narr[a];
        }

        if(narr[d]->next==narr[a]){
            ap=narr[b];
            dn=narr[c];
        }
      
       
        connect(ap,narr[c]);
        connect(cp,narr[a]);
        connect(narr[d],bn);
        connect(narr[b],dn);

    }
    pr();
}