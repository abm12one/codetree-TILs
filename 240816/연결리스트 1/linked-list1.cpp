#include <iostream>
using namespace std;

struct node{
    string data;
    node*prev;
    node*next;
    node(string s){
        data=s;
        prev=nullptr;
        next=nullptr;
    }
};


node*cur;
void insertprev(node*ptr,string newdata){

    node* nptr=new node(newdata);
    node* pprev=ptr->prev;

    nptr->next=ptr;
    nptr->prev=pprev;

    if(nptr->prev!=nullptr){
        nptr->prev->next=nptr;
    }
    if(nptr->next!=nullptr){
        nptr->next->prev=nptr;
    }
    return;


}

void insertnext(node*ptr,string newdata){

    node* nptr=new node(newdata);
    node* pnext=ptr->next;

    nptr->next=pnext;
    nptr->prev=ptr;

    if(nptr->prev!=nullptr){
        nptr->prev->next=nptr;
    }
    if(nptr->next!=nullptr){
        nptr->next->prev=nptr;
    }
    return;


}

void movep(){
    if(cur->prev==nullptr){
        return;
    }
    cur=cur->prev;
    return;
}
void moven(){
    if(cur->next==nullptr){
        return;
    }
    cur=cur->next;
    return;
}

void pr(){
    if(cur->prev!=nullptr){
        cout<<cur->prev->data<<" ";
    }
    else{
        cout<<"(Null)"<<' ';
    }

    if(cur!=nullptr){
        cout<<cur->data<<" ";
    }
    else{
        cout<<"(Null)"<<' ';
    }

    if(cur->next!=nullptr){
        cout<<cur->next->data<<" ";
    }
    else{
        cout<<"(Null)"<<' ';
    }
    cout<<'\n';
    return;




}
int main() {
    string str;
    cin>>str;

    cur=new node(str);
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        if(c==1){
            string temp;
            cin>>temp;
            insertprev(cur,temp);


        }
        else if(c==2){
            string temp;
            cin>>temp;
            insertnext(cur,temp);
        }
        else if(c==3){
            movep();
        }
        else if(c==4){
            moven();
        }
        pr();
    }
}