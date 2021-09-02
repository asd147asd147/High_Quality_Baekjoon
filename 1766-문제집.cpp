#include <bits/stdc++.h>

using namespace std;

int N, M;

int pre[32001] = {0,};
vector<vector<int>> vec;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> N >> M;
    vec.resize(N+1);
    for(int i = 0; i < M; i++){
        int start, dest;
        cin >> start >> dest;
        vec[start].push_back(dest);
        pre[dest]++;
    }
    priority_queue<int> pq;
    for(int i = 1; i <= N; i++){
        if(pre[i] == 0){
            pq.push(-i);
        }
    }

    while(!pq.empty()){
        auto p = -pq.top();
        pq.pop();
        for(auto t : vec[p]){
            pre[t]--;
            if(pre[t] == 0) pq.push(-t);
        }
        cout << p << " ";
    }

	return 0;
}
