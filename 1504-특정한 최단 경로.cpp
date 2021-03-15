#include <bits/stdc++.h>
#define INF 200000000

using namespace std;

int V,E,M1,M2;
int p1=0, p2=0;

vector<unordered_map<int,int>> graph(801);

void daijkstra(int src, int check){
    int dist[801];
    int visited[801] = {0,};
    for(int i = 1; i <= V; i++)
        dist[i] = INF;
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto pos = pq.top();
        dist[pos.second] = min(dist[pos.second], -pos.first);
        pq.pop();
        if(!visited[pos.second]){
            for(auto g : graph[pos.second]){
                pq.push({pos.first-g.second, g.first});
            }
            visited[pos.second] = 1;
        }
    }
    if(check == 0){
        p1 += dist[M1];
        p2 += dist[M2];
    }
    else if(check == 1){
        p1 += dist[M2];
        p2 += dist[M1];
    }
    else{
        p1 += dist[M2];
        p2 += dist[M2];
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> V >> E;

    int a,b,c;
    for(int k = 0; k < E; k++){
        cin >> a >> b >> c;
        if(!graph[a][b]) graph[a][b] = c;
        else graph[a][b] = min(graph[a][b],c);

        if(!graph[b][a]) graph[b][a] = c;
        else graph[b][a] = min(graph[b][a],c);
    }
    cin >> M1 >> M2;
    daijkstra(1,0);
    daijkstra(V,1);
    daijkstra(M1,2);
    int ans = min(p1,p2);
    if(ans >= 200000000) cout << -1;
    else cout << ans;

	return 0;
}
