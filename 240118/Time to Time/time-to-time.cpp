#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits.h>
#include<cassert>

using namespace std;

int a,b,c,d;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    cin>>a>>b>>c>>d;
    int atime=a*60+b;
    int btime=c*60+d;
    cout<<btime-atime<<'\n';

    return 0;
}