#include <bits/stdc++.h>

using namespace std;

#define INF 600000000

struct cmp{
    bool operator()(tuple<int,int,int> &a, tuple<int,int,int> &b){
        return get<2>(a) >= get<2>(b);
    }
};

int main(){

    int N, M;
    int init, finish;
    cin >> N;
    cin >> M;

    vector<vector<tuple<int,int,int>>> v(M+1);
    int visited[M+1] = {0,};
    unsigned long long dist[M+1];
    for(auto &s : dist){
        s = INF;
    }
    for(int i = 0; i < M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_tuple(a,b,c));
    }

    cin >> init >> finish;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, cmp> pq;
    dist[init] = 0;

    for(auto s : v[init]){
        pq.push(s);
    }
    visited[init] = 1;
    while(!pq.empty()){
        tuple<int,int,int> temp = pq.top();
        if(dist[get<1>(temp)] > dist[get<0>(temp)] + get<2>(temp)){
            dist[get<1>(temp)] = dist[get<0>(temp)] + get<2>(temp);
        }
        pq.pop();
        if(visited[get<1>(temp)] == 0){
            visited[get<1>(temp)] = 1;
            for(auto s : v[get<1>(temp)]){
                pq.push(s);
            }
        }
    }
    cout << dist[finish];
	return 0;
}
