#include <iostream>
#include <vector>

using namespace std;
class maxheap{

    int s=0;
    int arr[100001];
    public:
        maxheap()=default;
        void swap(int &a,int &b){
            int temp=a;
            a=b;
            b=temp;
        }
        void push(int x){
            //cout<<"push"<<"\n";
            arr[++s]=x;
            int ptr=s;
            int p=ptr/2;

            while(p!=0&&arr[ptr]>arr[p]){
                
                swap(arr[p],arr[ptr]);
                
                ptr=ptr/2;
                p=ptr/2;
            }
            return;
        }

        int top(){
            if(s==0)return -1;
            return arr[1];
        }

        void pop(){
            if(s==0){
                //cout<<"-1"<<"\n";
                return;
            }
            arr[1]=arr[s--];
            
            int ptr=1;
            while(ptr<=s){
                int l=ptr*2;
                int r=ptr*2+1;
                int next=ptr;
                if(l<=s&&arr[ptr]<arr[l]){
                    next=l;
                }
                if(r<=s&&arr[ptr]<arr[r]){
                    next=r;
                }
                if(next==ptr){
                    break;
                }
                swap(arr[ptr],arr[next]);
                ptr=next;
            }
            return ;



        }
        void pr(){
            cout<<"pr"<<'\n';
            for(int i=1;i<=s;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
            return;
        }


};

int main(){
    int tc;
    cin>>tc;
    for(int q=1;q<=tc;q++){
        cout<<"#"<<q<<" ";
        maxheap mh;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int com;
            cin>>com;
            if(com==1){
                int k;
                cin>>k;
                mh.push(k);
            }
            else if(com==2){
                cout<<mh.top()<<" ";
                mh.pop();
                
            }
            //mh.pr();
            
        }
        cout<<"\n";

    }
}