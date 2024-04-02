#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int>ston;

struct node{
    int data;
    node*prev;
    node*next;

    node(int data):data(data),prev(nullptr),next(nullptr){};
};

node* nodes[100001];

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

    pri(nodes[ston[mnum]]);


}



int main() {
    int n,m,q;
    cin>>n>>m>>q;

    int sum=1;
    //setting
    for(int i=0;i<m;i++){
        
        int t;
        cin>>t;

        int ntemp=sum;


        for(int j=0;j<t;j++){
            int temp;
            cin>>temp;

            ston[temp]=sum;
            nodes[sum]=new node(temp);
            sum++;

        }

        for(int j=0;j<t-1;j++){
            connect(nodes[ntemp+j],nodes[ntemp+j+1]);
        }
        connect(nodes[ntemp+t-1],nodes[ntemp]);
        
    }


    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;
            int na=ston[a];
            int nb=ston[b];
            hap(nodes[na],nodes[nb]);

        }
        else if(t==2){
            int a,b;
            cin>>a>>b;
            int na=ston[a];
            int nb=ston[b];
            divide(nodes[na],nodes[nb]);

        }
        else if(t==3){
            int a;
            cin>>a;
            int na=ston[a];
            pr(nodes[na]);
        }


    }

}