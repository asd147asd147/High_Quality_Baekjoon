#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int D;
    cin >> D;
    vector<vector<int>> vec(8);
    vec[0].push_back(1);
    vec[0].push_back(2);

    vec[1].push_back(0);
    vec[1].push_back(2);
    vec[1].push_back(3);

    vec[2].push_back(0);
    vec[2].push_back(1);
    vec[2].push_back(3);
    vec[2].push_back(4);

    vec[3].push_back(1);
    vec[3].push_back(2);
    vec[3].push_back(4);
    vec[3].push_back(5);

    vec[4].push_back(2);
    vec[4].push_back(3);
    vec[4].push_back(5);
    vec[4].push_back(6);

    vec[5].push_back(3);
    vec[5].push_back(4);
    vec[5].push_back(7);

    vec[6].push_back(4);
    vec[6].push_back(7);

    vec[7].push_back(5);
    vec[7].push_back(6);

    vector<int> num(8,0);
    num[0] = 1;

    for(int k = 0; k < D; k++){
        vector<int> temp(8,0);
        for(int i = 0; i < 8; i++){
            for(auto v : vec[i]){
                temp[v] += num[i];
                temp[v] %= 1000000007;
            }
        }
        num = temp;
    }
    cout << num[0];

	return 0;
}
