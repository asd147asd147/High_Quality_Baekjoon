#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[505];
int dis[505];
vector<int>way[505];
bool check[505];
int N, M, S, E;

void dijkstra(int x) {
    dis[x] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, x));
    while (!pq.empty()) {
        int now = pq.top().second;
        int wei = pq.top().first;
        pq.pop();
        if (dis[now] < wei) continue;
        for (int i = 0; i < g[now].size(); i++) {
            if (g[now][i].second == -1)continue;// �� ��° dijkstra���� ���ŵ� ���� ����!
            int next = g[now][i].first;
            int ww = g[now][i].second;
            if (dis[now] + ww < dis[next]) {
                dis[next] = dis[now] + ww;
                way[next].clear();
                way[next].push_back(now); // �ִ� ��� ����
                pq.push(make_pair(dis[next], next));
            }
            else if (dis[now] + ww == dis[next]) {
                way[next].push_back(now); // �ݵ�� �̷��� next�� now�� �����ؾ� ��!
            }
            else continue;
        }
    }
}

void bfs(int x) {
    queue<int>q;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        if (check[x] == true) continue;
        check[x] = true;
        for (int i = 0; i < way[x].size(); i++) {
            int nx = way[x][i];
            for (int j = 0; j < g[nx].size(); j++) {
                if (g[nx][j].first == x) g[nx][j].second = -1; // ������ ����
            }
            q.push(nx);
        }
    }
}

void init() {
    memset(g, 0, sizeof(g));
    memset(way, 0, sizeof(way));
    memset(dis, 127, sizeof(dis));
    memset(check, false, sizeof(check));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        int N, M, S, E;
        init(); // �ʱ�ȭ �����ֱ�
        cin >> N >> M;
        if(N+M == 0) return 0;
        cin >> S >> E;
        for (int i = 0; i < M; i++) {
            int U,V,P;
            cin >> U >> V >> P;
            g[U].push_back({V, P});
        }
        int INF = dis[0];
        dijkstra(S); // start���� ��� ���������� �ִ� �Ÿ� ����
        bfs(E); // end���� start���� ����� �������� ����
        memset(dis, 127, sizeof(dis)); // �ִ� �Ÿ��� �ٽ� ���ؾ� �ϹǷ�
        dijkstra(S); // �ٽ� �ִ� �Ÿ� ����
        if (dis[E] == INF) cout << -1 << "\n";
        else cout << dis[E] << "\n";
    }
    return 0;
}
