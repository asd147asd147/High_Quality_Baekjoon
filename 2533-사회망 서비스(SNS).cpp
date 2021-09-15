#include <bits/stdc++.h>

using namespace std;

int N;

vector<vector<int>> vec;

int early(int idx, int flag){
    vector<int> visited(N+1, 0);
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({idx,flag});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        visited[p.first] = 1;
        if(p.second == 1){
            cnt++;
        }
        for(auto t : vec[p.first]){
            if(!visited[t]){
                q.push({t, !p.second});
            }
        }
    }
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vec.resize(N+1);
	for(int i = 0; i < N-1; i++){
        int start, finish;
        cin >> start >> finish;
        vec[start].push_back(finish);
        vec[finish].push_back(start);
	}

	int ans = min(early(1,0), early(1,1));
	cout << ans;

	return 0;
}
