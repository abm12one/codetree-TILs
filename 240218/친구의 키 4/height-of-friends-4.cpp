#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, m;

vector<int> edges[MAX_N + 1];

// 진입차수를 관리합니다.
int indegree[MAX_N + 1];

// 각 정점을 방문했는지 판단합니다.
bool visited[MAX_N + 1];

// 위상정렬을 위한 큐를 관리합니다.
queue<int> q;

pair<int, int> query[MAX_N + 1];

int ans;

bool CycleExist(int limit) {
    // 변수를 초기화합니다.
    for(int i = 1; i <= n; i++) {
        indegree[i] = 0;
        edges[i].clear();
        visited[i] = false;
    }

    // limit번까지의 간선이 존재할 때 모순이 있는지 없는지를 판단합니다.
    // 그래프를 인접 리스트로 관리합니다.
    for(int i = 1; i <= limit; i++) {
        int a, b;
        tie(a, b) = query[i];

        edges[a].push_back(b); 
        indegree[b]++; // 진입차수를 갱신합니다.  
    }

    // 처음 indegree 값이 0인 곳이 루트가 됩니다.
    // 이 노드들을 queue에 넣어주고, 정답으로 미리 저장해 놓습니다.
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

        visited[x] = true;

        // x에서 갈 수 있는 모든 곳을 탐색합니다.
        for(int i = 0; i < (int) edges[x].size(); i++) {
            int y = edges[x][i];

            // 해당 노드의 indegree를 1만큼 감소시켜줍니다.
            indegree[y]--;

            // indegree가 0이 되었다면
            // queue에 새로 넣어줍니다.
            if(!indegree[y]) {
                q.push(y);
            }
        }
    }

    // 모든 노드를 방문했다면 그래프 내에 사이클이 존재하지 않는다는 뜻입니다.
    bool is_cycle = false;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) 
            is_cycle = true;
    }

    return is_cycle;
}

int main() {
    // 입력:
    cin >> n >> m;

    // 각 입력을 순서대로 관리합니다.
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        query[i] = make_pair(x, y);
    }

    // 답을 결정하고 이분 탐색을 진행합니다.
    int lo = 0, hi = m+1;
	int flag=0;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
	
        // 1번부터 mid번 정보까지 사용했을 때
        // 사이클이 존재한다면 입력에서 모순이 존재합니다.
        // 정답을 갱신하고 더 작은 답이 있는지 탐색합니다.
        if(CycleExist(mid)) {
            hi = mid;
			flag=1;
			
        }
        else {
            lo = mid + 1;
        }
    }
	
    if(flag==0)
        cout << "Consistent";
    else
        cout << hi;
    return 0;
}