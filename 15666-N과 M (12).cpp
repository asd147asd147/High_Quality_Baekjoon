#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> num;
set<vector<int>> s;

void backTracking(vector<int> vec){
    if(vec.size() == M){
        vector<int> ans;
        for(auto v : vec){
            ans.push_back(num[v]);
        }
        s.insert(ans);
        return;
    }
    for(int i = *(vec.end()-1); i < N; i++){
        vec.push_back(i);
        backTracking(vec);
        vec.pop_back();
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int t;
	for(int i = 0; i < N; i++){
        cin >> t;
        num.push_back(t);
	}
	sort(num.begin(), num.end());

	for(int i = 0; i < N; i++){
        vector<int> vec;
        vec.push_back(i);
        backTracking(vec);
	}

	for(auto ans : s){
        for(auto v : ans){
            cout << v << " ";
        }
        cout << "\n";
	}

	return 0;
}
