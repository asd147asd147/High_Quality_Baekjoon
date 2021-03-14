#include <bits/stdc++.h>
#define INF 1000001

using namespace std;

int N,M,X;
vector<unordered_map<int,int>> graph(1001);
vector<int> party_dist(1001,INF);

vector<int> daijkstra(int src){
    vector<int> dist(1001,INF);
    bool visited[1001] = {false,};
    priority_queue<pair<int,int>> pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        auto pos = pq.top();
        pq.pop();
        dist[pos.second] = min(dist[pos.second], -pos.first);
        if(!visited[pos.second]){
            for(auto i : graph[pos.second]){
                if(-dist[i.first] < pos.first-i.second)
                    pq.push({pos.first-i.second, i.first});
            }
            visited[pos.second] = true;
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> X;

    int a,b,c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    party_dist = daijkstra(X);
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans,daijkstra(i)[X]+party_dist[i]);
    }
    cout << ans;

	return 0;
}
