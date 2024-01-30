#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

// 변수 선언:
int n, s, d;
vector<int> edges[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

int ans;

// DFS를 통해 연결된 모든 정점을 순회합니다.
// 동시에 dp값을 계산해줍니다.
void DFS(int x) {
    // 노드 x에 연결된 간선을 살펴보며 전부 방문해줍니다.
    for(int i = 0; i < (int) edges[x].size(); i++) {
        int y = edges[x][i];

        // 만약 y번 정점을 이미 방문했다면 스킵합니다.
        if(visited[y]) 
            continue;

        visited[y] = true;
        DFS(y);

        // 가장 멀리 있는 리프노드까지의 거리를 저장합니다.
        dist[x] = max(dist[x], 1 + dist[y]);
    }
}

int main() {
    // 입력:
    cin >> n >> s >> d;

    // n - 1개의 간선 정보를 입력받습니다.
    for(int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        
        // 간선 정보를 인접리스트에 넣어줍니다.
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    // 루트를 시작으로 DFS를 진행하며 값을 갱신합니다.
    visited[s] = true;
    DFS(s);

    // s번 정점을 제외한 리프까지의 거리가 d 이상인 정점의 개수를 구합니다.
    for(int i = 1; i <= n; i++) {
        if(i == s) continue;
        if(dist[i] >= d) 
            ans++;
    }

    // s번 정점을 제외한 정답은 거리가 d이상인 정점의 개수 * 2가 됩니다.
    cout << ans * 2;
    return 0;
}