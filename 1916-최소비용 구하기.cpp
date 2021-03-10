#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int main(){
    int N, M, init, finish;
    cin >> N >> M;
    vector<multimap<int,int>> city(N+1);
    for(int i = 0; i < M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        city[a].insert({b,c});
    }
    cin >> init >> finish;

    long long dist[N+1];
    bool visited[N+1] = {false,};
    for(int i = 0; i < N+1; i++)
        dist[i] = INF;

    dist[init] = 0;
    priority_queue<pair<int,int>> pq;
    for(auto m : city[init]){
        pq.push({-m.second, m.first});
    }
    visited[init] = true;
    while(!pq.empty()){
        auto m = pq.top();
        pq.pop();
        if(dist[m.second] >= -m.first){
            dist[m.second] = -m.first;
            if(!visited[m.second]){
                visited[m.second] = true;
                for(auto c : city[m.second]){
                    pq.push({m.first-c.second, c.first});
                }
            }
        }
    }

    cout << dist[finish];


	return 0;
}
