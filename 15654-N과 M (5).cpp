#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> I;
bool check[9] = {false,};

void DFS(vector<int> num, int idx){
    if(num.size() == M){
        for(auto n : num)
            cout << n << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < N; i++){
        if(check[i]) continue;
        num.push_back(I[i]);
        check[i] = true;
        DFS(num, i);
        check[i] = false;
        num.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        I.push_back(t);
    }
    sort(I.begin(),I.end());
    vector<int> num;
    for(int i = 0; i < N; i++){
        if(check[i]) continue;
        num.push_back(I[i]);
        check[i] = true;        DFS(num,i);
        check[i] = false;
        num.pop_back();
    }


	return 0;
}
