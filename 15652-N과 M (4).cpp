#include <bits/stdc++.h>

using namespace std;

int N,M;

void backTracking(vector<int> vec){
    if(M == vec.size()){
        for(auto v : vec){
            cout << v << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = *(vec.end()-1); i <= N; i++){
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
    for(int i = 1; i <= N; i++){
        vector<int> vec;
        vec.push_back(i);
        backTracking(vec);
    }

	return 0;
}
