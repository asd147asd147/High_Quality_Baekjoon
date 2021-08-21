#include <bits/stdc++.h>

using namespace std;

int N,M;
int ans = 0, Max = 0;
vector<int> parent;

int find_parent(int x){
    if(parent[x] == x){
        return x;
    }
    else{
        return parent[x] = find_parent(parent[x]);
    }
}

void Union(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    parent[y] = x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	vector<tuple<int,int,int>> road;

	parent.resize(N);
	for(int i = 0; i < N; i++)
        parent[i] = i;
	for(int i = 0; i < M; i++){
        int init, dest, cost;
        cin >> init >> dest >> cost;
        road.push_back({cost, init, dest});
	}
	sort(road.begin(), road.end());

	for(auto r : road){
        if(find_parent( get<1>(r) ) != find_parent( get<2>(r) )){
            Union(get<1>(r), get<2>(r));
            ans += get<0>(r);
            Max = max(Max, get<0>(r));
        }
	}
	cout << ans-Max;


	return 0;
}
