#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_N 200000

using namespace std;

// 변수 선언
int n, m, k;
vector<pair<int, int> > graph[MAX_N + 1];
priority_queue<pair<int, int> > pq;

int dist[MAX_N + 1];
bool visited[MAX_N + 1];

// 간선이 연결되어있는지 아닌지를 배열을 통해 관리합니다.
bool is_blocked[MAX_N + 1];

int main() {
    // 입력
    cin >> n >> m >> k;

    // 그래프를 인접리스트로 표현합니다.
    // 더미 노드(0번 노드)를 만들어서 1번부터 n번까지 노드를 통행증의 비용으로 연결합니다.
    for(int i = 1; i <= n; i++) {
        int cost;
        cin >> cost;
        graph[0].push_back(make_pair(i, cost));
        graph[i].push_back(make_pair(0, cost));
    }

    // m개의 간선이 연결되어있는지 없는지 정보를 저장합니다.
    while(m--) {
        int x, y;
        cin >> x >> y;

        if(x > y) swap(x, y);

        // x번 노드와 x+1번 노드 사이의 간선이 막혔음을 표시해줍니다.
        if(x == 1 && y == n)
            is_blocked[n] = true;
        else
            is_blocked[x] = true;
    }

    // 인접한 막히지 않은 간선들을 연결해둡니다.
    for(int i = 1; i <= n; i++) {
        if(is_blocked[i]) 
            continue;

        int x = i;
        int y = i + 1;
        if (x == n) 
            y = 1;

        graph[x].push_back(make_pair(y, 0));
        graph[y].push_back(make_pair(x, 0));
    }
    
    // 그래프에 있는 모든 노드들에 대해
    // 초기값을 전부 아주 큰 값으로 설정
    // INT_MAX 그 자체로 설정하면
    // 후에 덧셈 진행시 overflow가 발생할 수도 있으므로
    // 적당히 큰 숫자로 적어줘야함에 유의!
    for(int i = 0; i <= n; i++)
        dist[i] = (int)(1e9) + 5;

    // 시작위치에는 dist값을 0으로 설정
    dist[0] = 0;

    // 우선순위 큐에 시작점을 넣어줍니다.
    // 거리가 가까운 곳이 먼저 나와야 하며
    // 해당 지점이 어디인지에 대한 정보도 필요하므로
    // (거리, 정점 번호) 형태로 넣어줘야 합니다.
    // 단, c++에서는 우선순위 큐가 큰 값을 기본으로 뽑아주기 때문에
    // -를 붙여서 넣어줘야 함에 유의합니다.
    pq.push(make_pair(-0, 0));

    // O(|E|log|V|) 프림 코드
    // 우선순위 큐에
    // 원소가 남아있다면 계속 진행해줍니다.
    long long int ans = 0;
    while(!pq.empty()) {
        // 가장 거리가 가까운 정보를 받아온 뒤, 원소를 제거해줍니다.
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();

        // -를 다시 붙여줍니다.
        min_dist = -min_dist;

        // 우선순위 큐를 이용하면
        // 같은 정점의 원소가 
        // 여러 번 들어가는 문제가 발생할 수 있어
        // 이미 계산해본 적이 있는 경우라면
        // 바로 패스해줍니다.
        if(visited[min_index])
            continue;

        // visited 값을 true로 바꿔주고
        // 답을 갱신해줍니다. 
        visited[min_index] = true;
        ans += min_dist;

        // 최솟값에 해당하는 정점에 연결된 간선들을 보며
        // 최솟값을 갱신해줍니다.
        for(int j = 0; j < (int) graph[min_index].size(); j++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][j];
            
            // 현재 위치에서 연결된 간선으로 가는 것이 더 작다면
            int new_dist = target_dist;
            if(dist[target_index] > new_dist) {
                // 값을 갱신해주고, 우선순위 큐에 해당 정보를 넣어줍니다.
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }

    // k원을 넘기지 않고 모든 지점을 이동할 수 있다면 1을, 없다면 0을 출력합니다.
    if(ans <= k) 
        cout << 1;
    else 
        cout << 0;
    return 0;
}