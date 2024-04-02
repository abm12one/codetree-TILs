#include <iostream>
#include <vector>

using namespace std;
struct node{
    int data;
    node*prev;
    node*next;

    node(int data):data(data),prev(nullptr),next(nullptr){};
};

node* nodes[100001];
vector<int>arr;

void connect(node*s,node*e){
    if(s!=nullptr){
        s->next=e;
    }
    if(e!=nullptr){
        e->prev=s;
    }
}

void hap(node*a,node*b){
    node*na=a->next;
    node*pb=b->prev;
    connect(a,b);
    connect(pb,na);

}

void divide(node*a,node*b){
    node*pa=a->prev;
    node*pb=b->prev;

    connect(pa,b);
    connect(pb,a);
}

void pri(node*s){
    node*cur=s;
    int now=cur->data;
    cout<<now<<' ';

    cur=cur->prev;
    while(cur->data!=now){
        cout<<cur->data<<' ';
        cur=cur->prev;
    }



}

void pr(node*s){
    node*cur=s;
    int now= s->data;
    int mnum=now;
    while(cur->next->data!=now){
        mnum=min(mnum,cur->next->data);
        cur=cur->next;
    }

    pri(nodes[mnum]);


}



int main() {
    int n,m,q;
    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){
        nodes[i]=new node(i);
    }

    //setting
    for(int i=0;i<m;i++){
        
        int t;
        cin>>t;

        arr=vector<int>(t+1);

        for(int j=1;j<=t;j++){
            cin>>arr[j];
        
        }
         
        for(int j=1;j<t;j++){
            connect(nodes[arr[j]],nodes[arr[j+1]]);
        }
        connect(nodes[arr[t]],nodes[arr[1]]);
    }


    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;
            hap(nodes[a],nodes[b]);

        }
        else if(t==2){
            int a,b;
            cin>>a>>b;
            divide(nodes[a],nodes[b]);

        }
        else if(t==3){
            int a;
            cin>>a;
            pr(nodes[a]);
        }


    }

}