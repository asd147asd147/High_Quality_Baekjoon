#include <bits/stdc++.h>
#define INF 1000000

using namespace std;

vector<map<int,int>> graph(20001);
int dist[20001];
bool visited[20001] = {false,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V,E,src;
    cin >> V >> E >> src;
    for(int i = 0; i < V; i++){
        dist[i] = INF;
    }

    for(int i = 0; i < E; i++){
        int u,v,w;
        cin >> u >> v >> w;
        if(graph[u-1][v-1] != 0)
            graph[u-1][v-1] = min(graph[u-1][v-1],w);
        else
            graph[u-1][v-1] = w;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto g : graph[src-1]){
        pq.push(make_pair(graph[src-1][g.first],g.first));
    }
    visited[src-1] = 1;
    dist[src-1] = 0;
    while(!pq.empty()){
        pair<int,int> node = pq.top();
        pq.pop();
        if(dist[node.second] > node.first){
            dist[node.second] = node.first;
            if(!visited[node.second]){
                for(auto g : graph[node.second]){
                    pq.push(make_pair(dist[node.second]+graph[node.second][g.first],g.first));
                }
                visited[node.second] = 1;
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dist[i] != INF)
            cout << dist[i] << "\n";
        else
            cout << "INF\n";
    }

	return 0;
}
