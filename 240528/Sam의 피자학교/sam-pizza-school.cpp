#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n,k;
vector<int>dough;
vector<vector<int>>map;
vector<vector<int>>tmap;
vector<pair<int,int>>roll;
vector<int>temp;

int range(int y,int x){
    if(y<0||y>map.size()-1)return 0;
    if(x<0||x>map[0].size()-1)return 0;
    return 1;
}

void plusone(){
    int mmin=987654321;
    for(int i=0;i<n;i++){
        if(mmin>dough[i]){
            mmin=dough[i];
        }
    }
    for(int i=0;i<n;i++){
        if(mmin==dough[i]){
            dough[i]++;
        }
    }
    return;
}

void rotate(int row,int col){

    for(int i=0;i<roll.size();i++){
        int y,x;
        tie(y,x)=roll[i];
        roll[i]=make_pair(x,row-y-1);
    }
    return;

}

void pr(){
    for(int i=0;i<roll.size();i++){
        int y,x;
        tie(y,x)=roll[i];
        cout<<"("<<y<<' '<<x<<")"<<" ";
    }
    cout<<"\n";
    return;
}

void pr2(){
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n";
    return;
}
void pr3(){
    for(int i=0;i<dough.size();i++){
       cout<<dough[i]<<' ';
    }
    cout<<"\n";
    cout<<"\n";
    return;
}

void setting(int row,int col){
    map=vector<vector<int>>(row,vector<int>(col+n-roll.size()));
    for(int i=0;i<roll.size();i++){
        int y,x;
        tie(y,x)=roll[i];
        map[y][x]=dough[i];
    }
    int s=col;
    for(int i=roll.size();i<n;i++){
        map[row-1][s++]=dough[i];
    }

    return;
}

void rollup(){
    roll=vector<pair<int,int>>();
    roll.push_back(make_pair(0,0));
    roll.push_back(make_pair(1,0));
    int row=2;
    int col=1;

    while(1){
        if(n-roll.size()<row){
            //cout<<row<<' '<<col<<'\n';
            setting(row,col);
            break;
        }
        rotate(row,col);
        //pr();
        
        int temp=row;
        row=col;
        col=temp;
        for(int i=0;i<col;i++){
            roll.push_back(make_pair(row,i));
        }
        row++;
    }
}

void halfandhalf(){
    //pr3();
    vector<int>first;
    vector<int>second;
    vector<int>third;
    vector<int>fourth;
    map=vector<vector<int>>(4,vector<int>(n/4,0));
    int s=0;
    for(int i=s;i<n/4;i++,s++){
        first.push_back(dough[i]);
        //cout<<dough[i]<<'\n';
        
    }
    
    reverse(first.begin(),first.end());
   
    for(int i=s;i<n/2;i++,s++){
        //cout<<dough[i]<<'\n';
        second.push_back(dough[i]);
    }
    for(int i=s;i<n/4*3;i++,s++){
        third.push_back(dough[i]);
        //cout<<dough[i]<<'\n';
        
    }
    reverse(third.begin(),third.end());
    for(int i=s;i<n;i++,s++){
        //cout<<dough[i]<<'\n';
        fourth.push_back(dough[i]);
    }
    for(int i=0;i<n/4;i++){
        map[2][i]=first[i];
        map[1][i]=second[i];
        map[0][i]=third[i];
        map[3][i]=fourth[i];
        
    }
    //pr2();
    return;
    
    

}


int dy[2]={1,0};
int dx[2]={0,1};

void push(){
    
    tmap=vector<vector<int>>(map.size(),vector<int>(map[0].size()));

    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            if(map[i][j]==0)continue;
            for(int k=0;k<2;k++){
                int ny=i+dy[k];
                int nx=j+dx[k];
                if(!range(ny,nx))continue;
                if(map[ny][nx]==0)continue;
                int now=map[i][j];
                int next=map[ny][nx];
                int dif=(now-next)/5;
                tmap[i][j]-=dif;
                tmap[ny][nx]+=dif;

            }
            
        }
    }

    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            map[i][j]+=tmap[i][j];     
        }
    }


    temp=vector<int>();
    
    for(int j=0;j<map[0].size();j++){
        for(int i=map.size()-1;i>=0;i--){
            if(map[i][j]==0){
                continue;
            }
            temp.push_back(map[i][j]);
        }
    }
    
    dough=temp;
    return;
}



void sol(){
    plusone();
    rollup();
    
    push();
    //pr3();
    halfandhalf();
    //pr2();
    push();
    
}

int check(){
    int mmin=987654321;
    int mmax=0;
    for(int i=0;i<n;i++){
        if(mmin>dough[i]){
            mmin=dough[i];
        }
        if(mmax<dough[i]){
            mmax=dough[i];
        }
    }
    if(mmax-mmin<=k)return 1;
    return 0;
}


int main() {
    
    cin>>n>>k;
    dough=vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>dough[i];
    }
    if(check()){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=3000;i++){
        sol();
        if(check()){
            cout<<i<<'\n';
            break;
        }
    }
    return 0;



}

/*
1919 1291 1084 632 1804 1472 1671 1596 2192 1621 1788 1557 
1919 1291 1084 632 1804 1472 1671 1596 2192 1621 1788 1557 
1547 1142 1268 1761 1610 1576 1361 1771 1675 1633 1666 1617 
1547 1268 1268 1776 1735 1578 1501 1786 1550 1505 1526 1587 
1647 1580 1626 1486 1547 1458 1558 1534 1557 1410 1591 1634 

1489 1546 1540 1539 1561 1598 1522 1544 1628 1595 1532 1534 

1589 1590 1546 1541 1546 1548 1541 1555 1535 1540 1534 1564 

1540 1552 1542 1540 1552 1563 1554 1548 1563 1576 1555 1544 

1570 1560 1551 1554 1557 1550 1548 1556 1546 1544 1543 1552 

1545 1551 1553 1549 1547 1558 1556 1553 1554 1561 1555 1549 

1559 1555 1552 1556 1555 1550 1550 1554 1550 1553 1549 1549 

1553 1552 1555 1551 1550 1554 1554 1554 1551 1556 1552 1550 

1555 1552 1554 1554 1552 1552 1553 1554 1551 1555 1551 1551 

1555 1554 1554 1551 1551 1552 1552 1554 1551 1555 1552 1553 

1555 1552 1554 1552 1552 1554 1555 1552 1553 1554 1552 1552 

1554 1554 1552 1553 1552 1552 1552 1552 1552 1555 1554 1555 

1555 1553 1553 1553 1554 1554 1554 1553 1555 1553 1553 1553 

1553 1553 1553 1555 1553 1553 1554 1553 1553 1555 1554 1554 
*/
/*
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdlib>

#define MAX_N 100

using namespace std;

int n, k;

// 밀가루 양을 관리합니다.
int arr[MAX_N];

// 동시에 일어나는 처리를 깔끔하게 하기 위해 사용되는 배열입니다.
int temp[MAX_N];

int elapsed_time;

void AddOne() {
    // 최솟값을 찾아 전부 1씩 더해줍니다.
    int min_val = INT_MAX;
    for(int i = 0; i < n; i++)
        min_val = min(min_val, arr[i]);
    
    for(int i = 0; i < n; i++)
        if(arr[i] == min_val)
            arr[i]++;
}

// (row_num, col_num)판을 기준으로 
// 시계방향으로 90' 회전한 이후의 위치를 구합니다.
void Rotate(vector<pair<int, int> > &flours, int row_num, int col_num) {
    for(int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = flours[i];
        flours[i] = make_pair(y, row_num - x + 1);
    }
}

// 도우를 말아줍니다.
vector<pair<int, int> > RollUp() {
    // 말아올려진 후, 각 숫자들의 위치를 구해줍니다.
    vector<pair<int, int> > flours(n);

    // 처음 2개를 놓고 시작합니다.
    flours[0] = make_pair(1, 1);
    flours[1] = make_pair(2, 1);
    int row_num = 2, col_num = 1;
    
    int s_index = 2;
    // 계속 말아 올려질때까지 반복합니다.
    while(s_index + row_num <= n) {
        // 기존 숫자들은 90' 회전시켜줍니다.
        Rotate(flours, row_num, col_num);
        
        // 새롭게 추가되는 숫자들의 위치를 잡아줍니다.
        for(int i = 1; i <= row_num; i++)
            flours[s_index++] = make_pair(col_num + 1, i);

        // 말아 올려진 이후의 row, col 개수를 갱신합니다.
        if(row_num == col_num + 1)
            col_num++;
        else
            row_num++;
    }

    // 남아있는 부분의 위치를 계산합니다.
    int delta = 1;
    while(s_index < n) {
        flours[s_index++] = make_pair(row_num, col_num + delta);
        delta++;
    }

    return flours;
}

void ReArrange(vector<pair<int, int> > flours) {
    // temp를 초기화해줍니다.
    for(int i = 0; i < n; i++)
        temp[i] = 0;

    // 열은 오름차순, 행은 내림차순이 되도록 정렬한 뒤, temp에 넣어줍니다.
    vector<tuple<int, int, int> > extended_flours;
    for(int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = flours[i];
        extended_flours.push_back(make_tuple(y, -x, i));
    }
    sort(extended_flours.begin(), extended_flours.end());

    for(int i = 0; i < n; i++) {
        int prev_index;
        tie(ignore, ignore, prev_index) = extended_flours[i];
        temp[i] = arr[prev_index];
    }

    // temp 값을 다시 arr에 옮겨줍니다.
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// 두 위치가 인접한 곳인지를 판단합니다.
bool Adjacency(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2) == 1;
}

void Press(vector<pair<int, int> > flours) {
    // temp를 초기화해줍니다.
    for(int i = 0; i < n; i++)
        temp[i] = arr[i];

    // 인접한 쌍끼리 밀가루 양을 서로 옮겨줍니다.
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int x1, y1, x2, y2;
            tie(x1, y1) = flours[i];
            tie(x2, y2) = flours[j];
            if(Adjacency(x1, y1, x2, y2)) {
                if(arr[i] > arr[j]) {
                    temp[i] -= (arr[i] - arr[j]) / 5;
                    temp[j] += (arr[i] - arr[j]) / 5;
                }
                else {
                    temp[i] += (arr[j] - arr[i]) / 5;
                    temp[j] -= (arr[j] - arr[i]) / 5;
                }
            }
        }
    }

    // temp 값을 다시 arr에 옮겨줍니다.
    for(int i = 0; i < n; i++)
        arr[i] = temp[i];

    // 이제 행이 높은 순서대로 다시 펴주는 작업을 합니다.
    ReArrange(flours);
}

void pr(){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    cout<<'\n';
    return;

}

vector<pair<int, int> > Fold() {
    vector<pair<int, int> > flours(n);
    // 한번 접은 후의 위치 구하기
    for(int i = 0; i < n / 2; i++)
        flours[i] = make_pair(1, n / 2 - i);
    for(int i = n / 2; i < n; i++)
        flours[i] = make_pair(2, i - (n / 2) + 1);

    // 두번 접은 후의 위치 구하기
    for(int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = flours[i];

        // 접었을 때 위로 올라가는 부분
        if(y <= n / 4)
            flours[i] = make_pair(3 - x, n / 4 - y + 1);
        // 접었을 때 아래에 남아있는 부분
        else
            flours[i] = make_pair(x + 2, y - n / 4);
    }

    return flours;
}

void Simulate() {
    // Step 1. 가장 작은 숫자를 찾아 전부 1을 증가시켜줍니다.
    AddOne();

    // Step 2. 도우를 말아줍니다.
    vector<pair<int, int> > flours = RollUp();

    // Step 3. 도우를 꾹 눌러줍니다.
    Press(flours);
    pr();

    // Step 4. 도우를 두 번 반으로 접어줍니다.
    flours = Fold();

    // Step 5. 도우를 한번 더 꾹 눌러줍니다.
    Press(flours);
    pr();
    // 횟수를 증가시켜줍니다.
    elapsed_time++;
}

bool End() {
    // 전부 차이가 k 이내인지 판단합니다.
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    for(int i = 0; i < n; i++) {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    return max_val - min_val <= k;
}

int main() {
    // 입력:
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 차이가 k보다 크다면 계속 반복합니다.
    while(!End())
        Simulate();
    
    cout << elapsed_time;
    return 0;
}
*/