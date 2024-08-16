#include <iostream>
#include <vector>
using namespace std;
int n,k;
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
struct list{
    int s;
    node*head;
    node*tail;
    list(){
        s=0;
        head=nullptr;
        tail=nullptr;
    }
};

vector<list>shelf;
vector<node*>book;

void connect(node*a,node*b){
    if(a!=nullptr){
        a->next=b;
    }
    if(b!=nullptr){
        b->prev=a;
    }
    return;
}
void pr(){
    //cout<<"pr"<<"\n";
    for(int i=1;i<=k;i++){
        int siz=shelf[i].s;
        if(siz==0){
            cout<<"0"<<"\n";
            continue;
        }
        //cout<<siz<<" "<<shelf[i].head->data<<" "<<shelf[i].tail->data<<'\n';
        cout<<siz<<" ";
        node*ptr=shelf[i].head;
        while(1){
            cout<<ptr->data<<" ";
            if(ptr==shelf[i].tail){
                break;
            }
            ptr=ptr->next;
        }
        cout<<'\n';

    }
}


int main() {
    
    cin>>n>>k;
    book=vector<node*>(n+1);
    shelf=vector<list>(k+1);

    for(int i=1;i<=n;i++){
        book[i]=new node(i);
    }
    for(int i=1;i<n;i++){
        connect(book[i],book[i+1]);
    }
    shelf[1].s=n;
    shelf[1].head=book[1];
    shelf[1].tail=book[n];

    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int c,a,b;
        cin>>c>>a>>b;
        //cout<<i+1<<"번째 "<<c<<" "<<a<<" "<<b<<"\n";
        if(c==1){
            int shelfsiz=shelf[a].s;
            if(shelfsiz==0){
                continue;
            }
            else if(shelfsiz==1){
                node *ptr=shelf[a].head;
                shelf[a].s=0;
                shelf[a].head=shelf[a].tail=nullptr;

                if(shelf[b].s==0){
                    shelf[b].head=shelf[b].tail=ptr;
                    shelf[b].s++;
                }
                else{
                    connect(shelf[b].tail,ptr);
                    shelf[b].s++;
                    shelf[b].tail=ptr;
                }

            }
            else{
                node *ptr=shelf[a].head;
                shelf[a].s--;
                shelf[a].head=ptr->next;

                if(shelf[b].s==0){
                    shelf[b].head=shelf[b].tail=ptr;
                    shelf[b].s++;
                }
                else{
                    connect(shelf[b].tail,ptr);
                    shelf[b].s++;
                    shelf[b].tail=ptr;
                }
            }
        }
        else if(c==2){
            int shelfsiz=shelf[a].s;
            if(shelfsiz==0){
                continue;
            }
            else if(shelfsiz==1){
                node *ptr=shelf[a].tail;
                shelf[a].s=0;
                shelf[a].head=shelf[a].tail=nullptr;

                if(shelf[b].s==0){
                    shelf[b].head=shelf[b].tail=ptr;
                    shelf[b].s++;
                }
                else{
                    connect(ptr,shelf[b].head);
                    shelf[b].s++;
                    shelf[b].head=ptr;
                }

            }
            else{
                node *ptr=shelf[a].tail;
                shelf[a].s--;
                shelf[a].tail=ptr->prev;

                if(shelf[b].s==0){
                    shelf[b].head=shelf[b].tail=ptr;
                    shelf[b].s++;
                }
                else{
                    connect(ptr,shelf[b].head);
                    shelf[b].s++;
                    shelf[b].tail=ptr;
                }
            }

        }
        else if(c==3){
            if(a==b)continue;
            node *ptr=shelf[a].tail;
            connect(ptr,shelf[b].head);
            shelf[b].s+=shelf[a].s;
            shelf[b].head=shelf[a].head;
            shelf[a].s=0;
            shelf[a].head=shelf[a].tail=nullptr;
            
        }
        else if(c==4){
            if(a==b)continue;
            node *ptr=shelf[a].head;
            connect(shelf[b].tail,ptr);
            shelf[b].s+=shelf[a].s;
            shelf[b].tail=shelf[a].tail;
            shelf[a].s=0;
            shelf[a].head=shelf[a].tail=nullptr;
        }
        
        
    }
    pr(); 

}