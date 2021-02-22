#include <bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> p1, pair<int,int> p2){
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first > p2.first;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        if(t){
            pq.push(make_pair(abs(t),t));
        }
        else{
            if(pq.empty()) cout << 0 << "\n";
            else cout << pq.top().second << "\n", pq.pop();
        }
    }

	return 0;
}
