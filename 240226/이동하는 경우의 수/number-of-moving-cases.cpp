#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, m;

vector<pair<int, int> > edges[MAX_N + 1];

// 진입차수를 관리합니다.
int indegree[MAX_N + 1];

// dist[i] : 1번 노드에서 i번 노드까지의 최대 거리
int dist[MAX_N + 1];

// before[i] : 1번 노드에서 i번 노드까지 최대 거리로 이동하기 위해
// i번 노드 바로 직전에 방문할 수 있는 노드 번호 리스트
vector<int> before[MAX_N + 1];

// 위상정렬을 위한 큐를 관리합니다.
queue<int> q;

// 마지막에 경로를 역순으로 돌아 정점을 방문하기 위해
// 방문 여부를 저장합니다.
bool visited[MAX_N + 1];

int main() {
    // 입력:
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        // 인접리스트로 관리합니다.
        int x, y, d;
        cin >> x >> y >> d;

        edges[x].push_back(make_pair(y, d));
        indegree[y]++; // 진입차수를 갱신합니다.  
    }

    // 모든 거리를 매우 작은 값으로 초기화합니다.
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MIN;
    // 1번 노드만 거리를 0으로 해줍니다.
    dist[1] = 0;

    // 처음 indegree 값이 0인 곳이 시작점이 됩니다.
    // 이 노드들을 queue에 넣어줍니다.
    for(int i = 1; i <= n; i++)
        if(!indegree[i]) {
            q.push(i);
        }
    
    // 위상정렬을 진행합니다.
    // queue에 원소가 남아있다면 계속 진행합니다.
    while(!q.empty()) {
        // 가장 앞에 있는 원소를 뽑아줍니다.
        int x = q.front();
        q.pop();
        
        // x에서 갈 수 있는 모든 곳을 탐색합니다.
        for(int i = 0; i < (int) edges[x].size(); i++) {
            int y, d;
            tie(y, d) = edges[x][i];

            // dist 정보를 갱신합니다.
            if(dist[x] != INT_MIN) {
                if(dist[y] < dist[x] + d) {
                    dist[y] = dist[x] + d;
                    before[y].clear();
                    before[y].push_back(x);
                }
                // 최적의 경로를 만들어 내기 위해
                // 직전에 방문할 수 있는 위치가 여러 개라면 전부 관리합니다.
                else if(dist[y] == dist[x] + d) {
                    before[y].push_back(x);
                }
            }

            // 해당 노드의 indegree를 1만큼 감소시켜줍니다.
            indegree[y]--;

            // 비로소 indegree가 0이 되었다면
            // queue에 새로 넣어줍니다.
            if(!indegree[y]) {
                q.push(y);
            }
        }
    }

    // n번 노드에서부터 before을 타고 가
    // 경로에 해당하는 모든 간선의 수를 구합니다.
    // 최장 경로를 만들어 내면서 방문할 수 있는 모든 정점을
    // 전부 큐에 넣으며 순회합니다. 
    int cur = n;
    int cnt = 0;

    q.push(n);
    visited[n] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < before[x].size(); i++) {
            int y = before[x][i];

            // x번 - y번 노드 간의 간선은 정답에 해당하므로
            // 답을 갱신해줍니다.
            cnt++;

            // 가능한 노드가 겹치지 않게 해줍니다.
            if(visited[y]) 
                continue;

            visited[y] = true;
            q.push(y);
        }
    }

    cout << dist[n] << " " << cnt;
    return 0;
}