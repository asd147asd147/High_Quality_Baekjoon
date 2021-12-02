#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
int N,M,S,E;
vector<vector<pair<int,int>>> dist;
vector<int> visited;
vector<vector<int>> min_path;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

int dijkstra(){
    priority_queue<tuple<int,int,vector<int>>> pq;
    int min_dist = 0;
    pq.push({0,S,{S}});
    visited[S] = 1;
    while(!pq.empty()){
        auto p = pq.top();
        if(get<1>(p) == E){
            if(min_dist == 0){
                min_path.push_back(get<2>(p));
                min_dist = -get<0>(p);
            }
            else if(min_dist == -get<0>(p)){
                min_path.push_back(get<2>(p));
            }
            else{
                return -get<0>(p);
            }
        }
        pq.pop();
        visited[get<1>(p)] = 1;
        for(auto d : dist[get<1>(p)]){
            if(visited[d.first]) continue;
            if(d.second == INF) continue;
            get<2>(p).push_back(d.first);
            pq.push({get<0>(p)-d.second,d.first,get<2>(p)});
        }
    }
    if(pq.empty()) return 0;

    return 0;
}

void find_path(int x){
    if(x == S) return;
<<<<<<< HEAD
    auto idx = lower_bound(dist[min_path[x]].begin(), dist[min_path[x]].end(), make_pair(x,0), comp) - dist[min_path[x]].begin();
    dist[min_path[x]][idx] = INF;
=======
    int idx = lower_bound(dist[min_path[x]].begin(), dist[min_path[x]].end(), make_pair(x,0), comp) - dist[min_path[x]].begin();
    dist[min_path[x]][idx] = make_pair(x,INF);
>>>>>>> 34c833e26677b27656e8b7b31258f80b83e28450
    find_path(min_path[x]);
}

void solve(){
    min_path.clear();
    min_path.resize(N+1);
    visited.clear();
    visited.resize(N+1);
    int minDist = dijkstra();
    if(minDist == 0){
        cout << -1 << "\n";
        return;
    }
    find_path(E);
    while(1){
        for(int i = 0; i <= N; i++){
            visited[i] = 0;
=======
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
            if (g[now][i].second == -1)continue;// 두 번째 dijkstra에서 제거된 간선 제외!
            int next = g[now][i].first;
            int ww = g[now][i].second;
            if (dis[now] + ww < dis[next]) {
                dis[next] = dis[now] + ww;
                way[next].clear();
                way[next].push_back(now); // 최단 경로 갱신
                pq.push(make_pair(dis[next], next));
            }
            else if (dis[now] + ww == dis[next]) {
                way[next].push_back(now); // 반드시 이렇게 next와 now를 설정해야 함!
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
                if (g[nx][j].first == x) g[nx][j].second = -1; // 간선을 삭제
            }
            q.push(nx);
>>>>>>> 6a214bd23ab2f5f70c45339300e8153efeefd621
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
        init(); // 초기화 시켜주기
        cin >> N >> M;
        if(N+M == 0) return 0;
        cin >> S >> E;
        for (int i = 0; i < M; i++) {
            int U,V,P;
            cin >> U >> V >> P;
            g[U].push_back({V, P});
        }
        int INF = dis[0];
        dijkstra(S); // start부터 모든 정점까지의 최단 거리 구함
        bfs(E); // end부터 start까지 연결된 간선들을 제거
        memset(dis, 127, sizeof(dis)); // 최단 거리를 다시 구해야 하므로
        dijkstra(S); // 다시 최단 거리 구함
        if (dis[E] == INF) cout << -1 << "\n";
        else cout << dis[E] << "\n";
    }
    return 0;
}
