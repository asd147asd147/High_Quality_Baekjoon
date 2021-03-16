#include <bits/stdc++.h>

using namespace std;

int V,E;
int parent[10001];

int findParent(int x){
    if(parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]);
}

bool sameParent(int x, int y){
    x = findParent(x);
    y = findParent(y);
    if(x == y) return true;
    return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	priority_queue<tuple<int,int,int>> pq;
	for(int i = 1; i <= V; i++)
        parent[i] = i;
	int a,b,c;
	int ans = 0;
	for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        pq.push({-c, a, b});
	}
	while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if(!sameParent(get<1>(p), get<2>(p))){
            ans += -get<0>(p);
            parent[findParent(get<1>(p))] = get<2>(p);
        }

	}
	cout << ans;

	return 0;
}
