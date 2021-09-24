#include <bits/stdc++.h>

using namespace std;

int N, d;
vector<pair<int,int>> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({max(a,b), min(a,b)});
	}
	cin >> d;
	sort(vec.begin(), vec.end());

	priority_queue<int> pq;
    int ans = 0;
	for(int i = 0; i < N; i++){
        if(vec[i].first - vec[i].second > d) continue;
        int start = vec[i].first - d;
        if(start <= vec[i].second){
            pq.push(-vec[i].second);
        }
        while(!pq.empty()){

            if(-pq.top() < start){
                pq.pop();
            }
            else break;
        }
        ans = max(ans,(int)pq.size());
	}
	cout << ans;

	return 0;
}
