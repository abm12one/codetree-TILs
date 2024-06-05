#include <iostream>
#include <vector>
using namespace std;

int n,m,k,c;
vector<vector<int>>map;
vector<vector<int>>temp;
vector<vector<int>>fkill;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ddy[4]={-1,-1,1,1};
int ddx[4]={-1,1,-1,1};
int ans=0;
int range(int y,int x){

    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;

}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void pr2(){
    cout<<"kill"<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<fkill[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void grow(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(map[i][j]<=0)continue;
            int cnt=0;
            
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]>0&&fkill[ny][nx]==0){
                    cnt++;
                }
            }

            map[i][j]+=cnt;
            
        }
    }
    
    
    return;

}

void growchild(){

    temp=vector<vector<int>>(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(map[i][j]<=0)continue;
            int cnt=0;
            
            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]==0&&fkill[ny][nx]==0){
                    cnt++;
                }
            }

            for(int k=0;k<4;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]==0&&fkill[ny][nx]==0){
                    temp[ny][nx]+=map[i][j]/cnt;
                }
            }
        }
    }
    
    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]+=temp[i][j];
        }
        
    }
    
    return;

}


int check(int y,int x,int k){
    int ret=0;
    //cout<<y<<"    "<<x<<'\n';
    for(int d=0;d<4;d++){
        for(int i=1;i<=k;i++){
            int ny=y+ddy[d]*i;
            int nx=x+ddx[d]*i;
            if(!range(ny,nx))continue;
            if(map[ny][nx]<=0)break;
            //cout<<"  "<<ny<<" "<<nx<<'\n';
            ret+=map[ny][nx];
        }
    }
    ret+=map[y][x];
    return ret;

}

int kill(int y,int x,int k){
    fkill[y][x]=c;
    
    map[y][x]=0;
    
    //cout<<y<<' '<<x<<"\n";
    int ret=0;
    for(int d=0;d<4;d++){
        for(int i=1;i<=k;i++){
            int ny=y+ddy[d]*i;
            int nx=x+ddx[d]*i;
            if(!range(ny,nx))continue;
            if(map[ny][nx]<=0){
                fkill[ny][nx]=c;
                
                break;
            }
            fkill[ny][nx]=c;
            
            map[ny][nx]=0;
            
            
        }
    }
    
    return ret;

}

void findbug(){
    int my=-1;
    int mx=-1;
    int mcnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]<=0)continue;
            int cnt=check(i,j,k);
            //cout<<i<<' '<<j<<' '<<cnt<<"\n";
            if(cnt>mcnt){
                mcnt=cnt;
                my=i;
                mx=j;
            }

        }
    }
    if(my==-1&&mx==-1)return;

    ans+=mcnt;
    kill(my,mx,k);
    
    return;
}

void blow(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(fkill[i][j]==0)continue;
            fkill[i][j]--;
        }
    }
    return;
}

void sol(){
    
    //pr2();
    grow();
    
    growchild();
    blow();
    //pr();
    //pr2();
    findbug();
    //pr();
    //pr2();
}

int main() {
    
    cin>>n>>m>>k>>c;
    map=vector<vector<int>>(n,vector<int>(n));
    fkill=vector<vector<int>>(n,vector<int>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        sol();
    }
    cout<<ans<<'\n';

}

/*
#include <iostream>

#define MAX_N 20
#define DIR_NUM 4

using namespace std;

int n, m, k, c;
int tree[MAX_N + 1][MAX_N + 1];
int add_tree[MAX_N + 1][MAX_N + 1];
int herb[MAX_N + 1][MAX_N + 1];

int ans;

bool IsOutRange(int x, int y) {
    return !(1 <= x && x <= n && 1 <= y && y <= n);
}

// 입력을 받는 등 초기 작업을 합니다.
void Init() {
    cin >> n >> m >> k >> c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
    		cin >> tree[i][j];
}

// 1단계 : 인접한 네 개의 칸 중 나무가 있는 칸의 수만큼 나무가 성장합니다.
void StepOne() {
    int dx[DIR_NUM] = {-1,  0, 1, 0};
    int dy[DIR_NUM] = { 0, -1, 0, 1};

    for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
            if(tree[i][j] <= 0) continue;

            // 나무가 있는 칸의 수(cnt)만큼 나무가 성장합니다.
            int cnt = 0;
			for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(IsOutRange(nx, ny)) continue;
                if(tree[nx][ny] > 0) cnt++;
            }
            tree[i][j] += cnt;
        }
}

// 2단계 : 기존에 있었던 나무들은 아무것도 없는 칸에 번식을 진행합니다.
void StepTwo() {
    int dx[DIR_NUM] = {-1,  0, 1, 0};
    int dy[DIR_NUM] = { 0, -1, 0, 1};

    // 모든 나무에서 동시에 일어나는 것을 구현하기 위해 하나의 배열을 더 이용합니다.
    // add_tree를 초기화해줍니다.
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) 
            add_tree[i][j] = 0;

    for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
            if(tree[i][j] <= 0) continue;

            // 해당 나무와 인접한 나무 중 아무도 없는 칸의 개수를 찾습니다.
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(IsOutRange(nx, ny)) continue;
                if(herb[nx][ny]) continue;
                if(tree[nx][ny] == 0) cnt++;
            }

            // 인접한 나무 중 아무도 없는 칸은 cnt로 나눠준 만큼 번식합니다.
            for(int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(IsOutRange(nx, ny)) continue;
                if(herb[nx][ny]) continue;
                if(tree[nx][ny] == 0) add_tree[nx][ny] += tree[i][j] / cnt;
            }
        }
    
    // add_tree를 더해 번식을 동시에 진행시킵니다.
    for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) tree[i][j] += add_tree[i][j];
}

// 3단계 : 가장 많이 박멸되는 칸에 제초제를 뿌립니다.
void StepThree() {
    int dx[DIR_NUM] = {-1,  1, 1, -1};
    int dy[DIR_NUM] = {-1, -1, 1,  1};

    int max_del = 0;
    int max_x = 1;
    int max_y = 1;

    for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
            // 모든 칸에 대해 제초제를 뿌려봅니다. 각 칸에서 제초제를 뿌릴 시 박멸되는 나무의 그루 수를 계산하고,
            // 이 값이 최대가 되는 지점을 찾아줍니다.
            if(tree[i][j] <= 0) continue;
            int cnt = tree[i][j];
            for(int dir = 0; dir < 4; dir++) {
                int nx = i;
                int ny = j;
				for(int x = 1; x <= k; x++) {
                    nx = nx + dx[dir];
                    ny = ny + dy[dir];
                    if(IsOutRange(nx, ny)) break;
                    if(tree[nx][ny] <= 0) break;
                    cnt += tree[nx][ny];
                }
            }
            if(max_del < cnt) {
                max_del = cnt;
                max_x = i;
                max_y = j;
            }
        }

    ans += max_del;

    // 찾은 칸에 제초제를 뿌립니다.
    if(tree[max_x][max_y] > 0) {
        tree[max_x][max_y] = 0;
        herb[max_x][max_y] = c;
        for(int dir = 0; dir < 4; dir++) {
            int nx = max_x;
            int ny = max_y;
            for(int x = 1; x <= k; x++) {
                nx = nx + dx[dir];
                ny = ny + dy[dir];
                if(IsOutRange(nx, ny)) break;
                if(tree[nx][ny] < 0) break;
                if(tree[nx][ny] == 0) {
                    herb[nx][ny] = c;
                    break;
                }
                tree[nx][ny] = 0;
                herb[nx][ny] = c;
            }
        }
    }
}

// 제초제의 기간을 1년 감소시킵니다.
void DeleteHerb() {
    for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) 
            if(herb[i][j] > 0) 
                herb[i][j] -= 1;
}
void pr() {
    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
            cout<<tree[i][j]<<' ';
        }
        cout<<'\n';
    } 
    cout<<'\n';
    return;
}

void pr2() {
    for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) {
            cout<<herb[i][j]<<' ';
        }
        cout<<'\n';
    } 
    cout<<'\n';
    return;
}

int main() {
    // 입력을 받는 등 초기 작업을 합니다.
    Init();

    for(int i = 1; i <= m; i++) {
        // 1단계 : 인접한 네 개의 칸 중 나무가 있는 칸의 수만큼 나무가 성장합니다.
        StepOne();

        // 2단계 : 기존에 있었던 나무들은 아무것도 없는 칸에 번식을 진행합니다.
        StepTwo();

        // 제초제의 기간을 1년 감소시킵니다.
        DeleteHerb();
        pr();
        pr2();
        // 3단계 : 가장 많이 박멸되는 칸에 제초제를 뿌립니다.
        StepThree();
        pr();
        pr2();
    }

    cout << ans;
    return 0;
}










6 0 1 0 4 
0 1 0 3 0 
0 1 0 0 4 
2 0 -1 0 2 
0 0 0 0 0 

0 0 0 1 0 
0 0 0 0 1 
0 0 0 1 0 
0 0 0 0 0 
0 0 0 0 0 

6 3 1 0 4 
3 2 3 3 0 
0 2 0 0 5 
2 0 -1 1 3 
0 0 0 0 1 

0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 

6 3 0 0 0 
3 2 3 0 0 
0 2 0 0 0 
2 0 -1 1 3 
0 0 0 0 1 

0 0 1 0 1 
0 0 0 1 0 
0 0 1 0 1 
0 0 0 0 0 
0 0 0 0 0 

8 5 0 0 0 
5 6 4 0 0 
6 3 0 1 0 
2 1 -1 2 5 
0 0 0 3 2 

0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 

8 0 0 0 0 
0 6 0 0 0 
6 3 0 0 0 
2 1 -1 2 0 
0 0 0 3 2 

0 1 0 0 0 
1 0 1 0 0 
0 0 0 1 0 
0 0 0 0 1 
0 0 0 0 0 

8 0 0 0 0 
0 7 0 0 0 
8 6 6 0 0 
4 3 -1 3 0 
4 3 5 5 3 

0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 

*/