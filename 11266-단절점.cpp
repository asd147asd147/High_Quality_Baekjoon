#include <bits/stdc++.h>

using namespace std;

int V, E;
int cnt = 1;
vector<vector<int>> vec(10001);
int num[10001] = {0,};
bool visited[10001] = {0,};
set<int> ans;

int dfs(int x, int p){
    num[x] = cnt++;
    int min_num = num[x];
    int c = 0;
    for(auto v : vec[x]){
        c++;
        if(v == p) continue;
        if(visited[v]){
            min_num = min(min_num, num[v]);
            continue;
        }
        visited[v] = 1;
        int child_min_num = dfs(v, x);
        if(child_min_num >= num[x]){
            if(x == p && c < 2) continue;
            ans.insert(x);
        }
        min_num = min(min_num, child_min_num);
    }
    return min_num;
}

void cut_node(int root){
    visited[root] = 1;
    dfs(root, root);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	for(int i = 0; i < E; i++){
        int a,b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
	}

	for(int i = 1; i <= V; i++){
        if(visited[i]) continue;
        cut_node(i);
	}
	cout << ans.size() << "\n";
	for(auto a : ans)
        cout << a << " ";

	return 0;
}
