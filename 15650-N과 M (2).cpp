#include <bits/stdc++.h>

using namespace std;

int N,M;

void DFS(vector<int> num){
    if(num.size() == M){
        for(auto n : num)
            cout << n << " ";
        cout << "\n";
        return;
    }
    for(int i = *(num.end()-1)+1; i <= N; i++){
        num.push_back(i);
        DFS(num);
        num.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    vector<int> num;
    for(int i = 1; i <= N; i++){
        num.push_back(i);
        DFS(num);
        num.pop_back();
    }


	return 0;
}
