#include <bits/stdc++.h>
#define INF 100000001
using namespace std;

void solve(){
    int cost[1001];
    int t[1001];
    int N, K, W;
    unordered_multimap<int,int> adj;
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> cost[i];

    for(int i = 0; i < K; i++){
        int a,b;
        cin >> a >> b;
        adj.insert({a,b});
        t[b] = INF;
    }
    cin >> W;
    queue<int> q;
    for(int i = 1; i <= N; i++){
        cout << t[i] << " ";
        if(!t[i]){
            t[i] = cost[i];
            q.push(i);
            return;
        }
    }
    cout << endl;

    while(!q.empty()){
        auto p = q.front();
        cout << p << endl;
        auto a = adj.equal_range(p);
        for(auto i = a.first; i != a.second; i++){
            t[i->second] = t[p] + cost[i->second];
            q.push(i->second);
        }
        if(p == W){
            cout << t[W] << "\n";
            return;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
        solve();
	}
	return 0;
}
