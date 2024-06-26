/*
#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_N 20
#define MAX_M 400
#define DIR_NUM 4
#define EMPTY make_pair(401, 401)
#define EMPTY_NUM 401

using namespace std;

int n, m, k;
int given_map[MAX_N][MAX_N];
int next_dir[MAX_M + 1][DIR_NUM][DIR_NUM];

pair<int, int> player[MAX_N][MAX_N];
pair<int, int> next_player[MAX_N][MAX_N];

pair<int, int> contract[MAX_N][MAX_N];

int elapsed_time;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int target_num) {
    if(!InRange(x, y))
        return false;
    
    // target 번호와 contract 번호가 일치한 
    // 경우에만 이동이 가능합니다.
    int contract_num;
    tie(contract_num, ignore) = contract[x][y];
    
    return contract_num == target_num;
}

tuple<int, int, int> NextPos(int x, int y, int curr_dir) {
	int dx[DIR_NUM] = {-1, 1, 0, 0};
	int dy[DIR_NUM] = {0, 0, -1, 1};
    
    int num;
    tie(num, ignore) = player[x][y];

    // Case 1.
    // 먼저 독점계약을 맺지 않은 공간이 있다면 
    // 우선순위에 따라 그곳으로 이동합니다.
    for(int i = 0; i < 4; i++) {
        int move_dir = next_dir[num][curr_dir][i];
        int nx = x + dx[move_dir], ny = y + dy[move_dir];
        
        if(CanGo(nx, ny, EMPTY_NUM))
            return make_tuple(nx, ny, move_dir);
    }
    
    // Case 2.
    // 인접한 곳이 모두 독점계약을 맺은 곳이라면
    // 우선순위에 따라 그 중 본인이 독점계약한 땅으로 이동합니다.
    for(int i = 0; i < 4; i++) {
        int move_dir = next_dir[num][curr_dir][i];
        int nx = x + dx[move_dir], ny = y + dy[move_dir];
        
        if(CanGo(nx, ny, num))
            return make_tuple(nx, ny, move_dir);
    }
}

// (x, y) 위치에 새로운 플레이어가 들어왔을 때 갱신을 진행합니다.
void Update(int x, int y, pair<int, int> new_player) {
    // 새로 들어온 플레이어가 더 우선순위가 높을 경우에만
    // (x, y)위치에 해당 플레이어가 위치하게 됩니다.
    // Tip.
    // Empty인 위치에서는 항상 update가 되게끔
    // 미리 Empty의 num 값에 401를 셋팅해놨습니다.
    if(next_player[x][y] > new_player) 
        next_player[x][y] = new_player;
}

void Move(int x, int y) {
    int num, curr_dir;
    tie(num, curr_dir) = player[x][y];
    
    // Step1. 현재 플레이어의 다음 위치와 방향을 구합니다.
    int nx, ny, move_dir; 
    tie(nx, ny, move_dir) = NextPos(x, y, curr_dir);
    
    // Step2. 플레이어를 옮겨줍니다.
    Update(nx, ny, make_pair(num, move_dir));
}

void DecContract(int x, int y) {
    int num, remaining_period;
    tie(num, remaining_period) = contract[x][y];
    
    // 남은 기간이 1이면 다시 Empty가 됩니다.
    if(remaining_period == 1)
        contract[x][y] = EMPTY;
    // 그렇지 않다면 기간이 1 줄어듭니다.
    else
        contract[x][y] = make_pair(num, remaining_period - 1);
}

void AddContract(int x, int y) {
    int num;
    tie(num, ignore) = player[x][y];
    contract[x][y] = make_pair(num, k);
}

void Simulate() {
    // Step1. next_player를 초기화합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            next_player[i][j] = EMPTY;
    
    // Step2. 각 플레이어들을 한 칸씩 움직여줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(player[i][j] != EMPTY)
                Move(i, j);

    // Step3. next_grid 값을 grid로 옮겨줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            player[i][j] = next_player[i][j];
    
    // Step4. 남은 contract기간을 1씩 감소시킵니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(contract[i][j] != EMPTY)
                DecContract(i, j);
    
    // Step5. 새로운 contract를 갱신해줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(player[i][j] != EMPTY)
                AddContract(i, j);
}

bool End() {
    if(elapsed_time >= 1000)
        return true;
    
    for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
            if(player[i][j] == EMPTY)
                continue;
            
            int num;
            tie(num, ignore) = player[i][j];
            
            if(num != 1)
                return false;
        }
    
    return true;
}
void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p,d;
            
            tie(p,d)=contract[i][j];
            if(p==401)cout<<0<<","<<0<<' ';
            else{
                cout<<p<<","<<d<<' ';
            }
            
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
int main() {
	cin >> n >> m >> k;
    
    // 초기 상태를 입력받습니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> given_map[i][j];
            if(given_map[i][j] == 0) {
                player[i][j] = EMPTY;
                contract[i][j] = EMPTY;
            }
        }
    
    // 플레이어 마다 초기 방향을 입력받아 설정해줍니다.
    for(int num = 1; num <= m; num++) {
        int move_dir;
        cin >> move_dir;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(given_map[i][j] == num) {
                    player[i][j] = make_pair(num, move_dir - 1);
                    contract[i][j] = make_pair(num, k);
                }
    }
    
    // 플레이어 마다 방향 우선순위를 설정합니다.
    for(int num = 1; num <= m; num++)
        for(int curr_dir = 0; curr_dir < 4; curr_dir++)
            for(int i = 0; i < 4; i++) {
                cin >> next_dir[num][curr_dir][i];
                next_dir[num][curr_dir][i]--;
            }
	
    // 시간이 1000이 넘지 않고
    // 1번이 아닌 플레이어가 남아 있다면
    // 계속 시뮬레이션을 반복합니다.
	while(!End()) {
		Simulate();
        cout<<elapsed_time+1<<"\n";
        
        pr();
        
        
        
        elapsed_time++;
    }
	
    if(elapsed_time >= 1000)
        elapsed_time = -1;
    
	cout << elapsed_time;
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
vector<int>dir;
vector<int>pos;
vector<vector<int>>pre;
vector<vector<pair<int,int>>>map;
vector<pair<int,int>>player;
vector<vector<vector<int>>>priordir;
int ntime;
int n,m,k;
int isrange(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}


pair<int,int> getnext(int p,int d){
    int y,x;
    tie(y,x)=player[p];
    for(int i=0;i<4;i++){
        int ny=y+dy[priordir[p][d][i]];
        int nx=x+dx[priordir[p][d][i]];
        if(!isrange(ny,nx))continue;

        int nextp,nextt;
        tie(nextp,nextt)=map[ny][nx];

        if(nextp==0){
            dir[p]=priordir[p][d][i];
            return make_pair(ny,nx);
        }
        
        else if(nextt==ntime&&pre[ny][nx]+k<ntime){
            pos[p]=0;
            return make_pair(-1,-1);
        }
        else if(ntime>k+nextt){
            dir[p]=priordir[p][d][i];
            return make_pair(ny,nx);
        }
        else if(ntime<=k+nextt){
            continue;
        }
    }

    for(int i=0;i<4;i++){
        int ny=y+dy[priordir[p][d][i]];
        int nx=x+dx[priordir[p][d][i]];
        if(!isrange(ny,nx))continue;

        int nextp,nextt;
        tie(nextp,nextt)=map[ny][nx];

        if(nextp==p&&ntime<=k+nextt){
            dir[p]=priordir[p][d][i];
            return make_pair(ny,nx);
        }
        
    }

    
}

void sol(){

    for(int i=1;i<=m;i++){
        if(pos[i]==0)continue;
        int nowd=dir[i];
        int ny,nx;
        tie(ny,nx)=getnext(i,nowd);
        if(ny==-1)continue;
        map[ny][nx]=make_pair(i,ntime);
        player[i]=make_pair(ny,nx);

    }
    return;




}

int isok(){
    for(int i=2;i<=m;i++){
        if(pos[i]!=0)
        return 0;
    }
    if(pos[1]==0)return 0;
    return 1;
}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p,t;
            tie(p,t)=map[i][j];
            cout<<p<<","<<t<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
void pr2(){
    for(int i=1;i<=m;i++){
        cout<<dir[i]<<' ';
    }
    cout<<'\n';
}

void setting(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p,t;
            tie(p,t)=map[i][j];
            pre[i][j]=t;
        }
    }
    return;
}

int main(){
    
    cin>>n>>m>>k;
    dir=vector<int>(m+1);
    pos=vector<int>(m+1,1);
    player=vector<pair<int,int>>(m+1);
    pre=vector<vector<int>>(n,vector<int>(n));
    map=vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(n));
    priordir=vector<vector<vector<int>>>(m+1,vector<vector<int>>(4,vector<int>(4)));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p;
            cin>>p;
            if(p!=0){
                map[i][j]=make_pair(p,0);
                player[p]=make_pair(i,j);
            }
            else{
                map[i][j]=make_pair(0,-k);
            }
        }
        
    }
    
    for(int i=1;i<=m;i++){
        int d;
        cin>>d;
        dir[i]=d-1;
    }

    for(int i=1;i<=m;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int d;
                cin>>d;
                priordir[i][j][k]=d-1;
            }
        }
    }


    
    for(ntime=1;ntime<=1000;ntime++){
        //cout<<"#"<<ntime<<'\n';
        setting();
        sol();
        
        //pr();
        
        
        if(isok()){
            cout<<ntime;
            return 0;
        }
    }
    cout<<-1;
    return 0;
    

}