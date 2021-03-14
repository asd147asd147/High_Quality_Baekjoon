#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int main(){
    int N, M, init, finish;
    cin >> N >> M;
    vector<multimap<int,int>> city(N+1);
    vector<vector<int>> path(N+1);
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

    priority_queue<pair<int,vector<int>>> pq;
    pq.push({0, vector<int>(1,init)});
    while(!pq.empty()){
        auto m = pq.top();
        pq.pop();
        if(dist[m.second[m.second.size()-1]] > -m.first){
            dist[m.second[m.second.size()-1]] = -m.first;
            path[m.second[m.second.size()-1]] = m.second;
            if(!visited[m.second[m.second.size()-1]]){
                visited[m.second[m.second.size()-1]] = true;
                for(auto c : city[m.second[m.second.size()-1]]){
                    if(-dist[c.first] < m.first-c.second){
                        m.second.push_back(c.first);
                        pq.push({m.first-c.second, m.second});
                        m.second.pop_back();
                    }
                }
            }
        }
    }

    cout << dist[finish] << "\n" << path[finish].size() << "\n";
    for(auto p : path[finish])
        cout << p << " ";


	return 0;
}
