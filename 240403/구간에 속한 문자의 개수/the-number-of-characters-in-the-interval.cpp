#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>aarr;
vector<vector<int>>barr;
vector<vector<int>>carr;
vector<vector<int>>pa;
vector<vector<int>>pb;
vector<vector<int>>pc;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    aarr=vector<vector<int>>(n+1,vector<int>(m+1));
    barr=vector<vector<int>>(n+1,vector<int>(m+1));
    carr=vector<vector<int>>(n+1,vector<int>(m+1));

    pa=vector<vector<int>>(n+1,vector<int>(m+1));
    pb=vector<vector<int>>(n+1,vector<int>(m+1));
    pc=vector<vector<int>>(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=1;j<=m;j++){
            if(str[j-1]=='a'){
                aarr[i][j]=1;
            }
            else if(str[j-1]=='b'){
                barr[i][j]=1;
            }
            else if(str[j-1]=='c'){
                carr[i][j]=1;
            }

            pa[i][j]=pa[i-1][j]+pa[i][j-1]-pa[i-1][j-1]+aarr[i][j];
            pb[i][j]=pb[i-1][j]+pb[i][j-1]-pb[i-1][j-1]+barr[i][j];
            pc[i][j]=pc[i-1][j]+pc[i][j-1]-pc[i-1][j-1]+carr[i][j];


        }
    }
    
    for(int i=0;i<k;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        cout<<pa[c][d]-pa[c][b-1]-pa[a-1][d]+pa[a-1][b-1]<<' ';
        cout<<pb[c][d]-pb[c][b-1]-pb[a-1][d]+pb[a-1][b-1]<<' ';
        cout<<pc[c][d]-pc[c][b-1]-pc[a-1][d]+pc[a-1][b-1]<<'\n';

    }
    

}