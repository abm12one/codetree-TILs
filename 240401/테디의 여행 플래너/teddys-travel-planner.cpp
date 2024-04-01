#include <iostream>

#define MAX_N 250000
#define MAX_K 100

using namespace std;

struct node{
    string data;
    node*prev;
    node*next;
    node(string data):data(data),prev(nullptr),next(nullptr){};
};

node* nodes[100001];
node*cur;

void connect(node *s,node*e){
    if(s!=nullptr){
        s->next=e;
    }
    if(e!=nullptr){
        e->prev=s;
    }

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
    if(now->prev->data==now->next->data){
        cout<<-1<<'\n';
        return;
    }
    cout<<now->prev->data<<' '<<now->next->data<<'\n';
    return;


}

int main() {
    
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        nodes[i]=new node(str);
    }


    for(int i=1;i<n;i++){
        connect(nodes[i],nodes[i+1]);
    }
    connect(nodes[n],nodes[1]);

    cur=nodes[1];

    for(int k=0;k<q;k++){
        int t;
        cin>>t;
        if(t==1){
            if(cur->next!=nullptr){
                cur=cur->next;
                pr(cur);
            }
            else{
                cout<<-1<<'\n';
            }
            
        }
        else if(t==2){
            if(cur->prev!=nullptr){
                cur=cur->prev;
                pr(cur);
            }
            else{
                cout<<-1<<'\n';
            }
        }
        else if(t==3){
            if(cur->next!=nullptr){
                cur->next=cur->next->next;
                if(cur->next!=nullptr){
                    cur->next->prev=cur;
                }
            }
            pr(cur);

        }
        else if(t==4){
            string temp;
            cin>>temp;
            node*s=new node(temp);
            s->next=cur->next;
            s->prev=cur;
            if(s->prev!=nullptr){
                s->prev->next=s;
            }
            if(s->next!=nullptr){
                s->next->prev=s;
            }
            pr(cur);
        }

    }


}