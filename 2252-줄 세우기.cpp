#include <bits/stdc++.h>

using namespace std;

int N, M;
int pre[32001] = {0,};
vector<vector<int>> vec(32001);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        pre[b]++;
        vec[a].push_back(b);
    }
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(!pre[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        cout << p << " ";
        for(auto t : vec[p]){
            pre[t]--;
            if(!pre[t]){
                q.push(t);
            }
        }
    }
	return 0;
}
