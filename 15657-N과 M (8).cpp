#include <bits/stdc++.h>

using namespace std;

int N,M;
set<int> num;
void backTracking(vector<int> vec){
    if(M == vec.size()){
        for(auto v : vec){
            cout << v << " ";
        }
        cout << "\n";
        return;
    }
    for(auto i = num.find(*(vec.end()-1)); i != num.end(); i++){
        vec.push_back(*i);
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
        num.insert(t);
    }

    for(auto i = num.begin(); i != num.end(); i++){
        vector<int> vec;
        vec.push_back(*i);
        backTracking(vec);
    }

	return 0;
}
