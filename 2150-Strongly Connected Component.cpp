#include <bits/stdc++.h>

using namespace std;

int N, E;

vector<vector<int>> vec;
bool visited[10001] = {0,};
vector<vector<int>> ans;
vector<int> parent;
stack<int> s;
int cnt = 0;

int dfs(int x){
    parent[x] = ++cnt;
    s.push(x);
    int p = parent[x];
    for(auto v : vec[x]){
        if(parent[v] == 0){
            p = min(p,dfs(v));
        }
        else if(!visited[v]){
            p = min(p, parent[v]);
        }
    }
    if(p==parent[x]){
        vector<int> scc;
        while(1){
            int t = s.top();
            s.pop();
            scc.push_back(t);
            visited[t] = 1;
            if(t == x) break;
        }
        sort(scc.begin(), scc.end());
        ans.push_back(scc);
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> E;
    vec.resize(N+1);
    parent.resize(N+1);
    for(int i = 0; i < E; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
    }
    for(int i = 1; i <= N; i++){
        if(parent[i]==0) dfs(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto a : ans){
        for(auto b : a){
            cout << b << " ";
        }
        cout << "-1\n";
    }

    return 0;
}

