#include <iostream>

using namespace std;

struct node{
    string data;
    node *prev;
    node *next;

    node(string data):data(data),prev(nullptr),next(nullptr){};

};

void connect(node *s,node *e){
    if(s!=nullptr){
        s->next=e;
    }
    if(e!=nullptr){
        e->prev=s;
    }
    return;
}

void insertnext(node*target,node*s){
    connect(s,target->next);
    connect(target,s);
}

void insertprev(node*s,node*target){
    connect(target->prev,s);
    connect(s,target);
}

void printcur(node*cur){
    if(cur->prev==nullptr){
        cout<<"(Null)"<<"\n";
    }
    else{
        cout<<cur->prev->data<<" ";
    }

    cout<<cur->data<<" ";

    if(cur->next==nullptr){
        cout<<"(Null)"<<"\n";
    }
    else{
        cout<<cur->next->data<<"\n";
    }

    return;
}

int main() {
    string init;
    cin>>init;

    node*cur=new node(init);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int t;
        string str;
        cin>>t;
        if(t==1){
            cin>>str;
            node*now=new node(str);
            insertprev(now,cur);
        }
        else if(t==2){
            cin>>str;
            node*now=new node(str);
            insertnext(cur,now);
        }
        else if(t==3){
            if(cur->prev!=nullptr){
                cur=cur->prev;
            }
        }
        else if(t==4){
            if(cur->next!=nullptr){
                cur=cur->next;
            }
        }

        printcur(cur);


    }
    
}