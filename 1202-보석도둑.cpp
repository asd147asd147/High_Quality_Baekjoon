#include <bits/stdc++.h>

using namespace std;

int N,K,C;
long long ans = 0LL;
vector<pair<int,int>> vec;
vector<int> bag;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int M,V;
        cin >> M >> V;
        vec.push_back({M,V});
    }
    for(int i = 0; i < K; i++){
        int C;
        cin >> C;
        bag.push_back(C);
    }
    sort(vec.begin(),vec.end());
    sort(bag.begin(),bag.end());

    priority_queue<int> pq;

    int v_i = 0;
    for(int i = 0; i < K; i++){
        while(v_i < vec.size() && vec[v_i].first <= bag[i])
            pq.push(vec[v_i++].second);

        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout << ans;

	return 0;
}
