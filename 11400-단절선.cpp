#include <bits/stdc++.h>

using namespace std;

int V,E;
int num[100010];
int visited[1000010] = {0,};
vector<vector<int>> vec;
set<pair<int,int>> ans;
int cnt = 0;

int dfs(int x, int p){
    num[x] = ++cnt;
    int min_num = num[x];

    for(auto v : vec[x]){
        if(v == p) continue;
        if(visited[v]){
            min_num = min(min_num, num[v]);
            continue;
        }
        visited[v] = 1;
        int child_min_num = dfs(v,x);
        if(child_min_num > num[x]){
            ans.insert({min(x,v), max(x,v)});
        }
        min_num = min(child_min_num, min_num);
    }
    return min_num;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	vec.resize(V+1);
	for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
	}
	visited[1] = 1;
	dfs(1,1);
	cout << ans.size() << "\n";
	for(auto a : ans){
        cout << a.first << " " << a.second << "\n";
	}
	return 0;
}
