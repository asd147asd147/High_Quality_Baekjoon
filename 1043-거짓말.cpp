#include <bits/stdc++.h>

using namespace std;

int relation[51][51];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M,T;
    set<int> truth;
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            relation[i][j] = 0;
        }
    }
    int t;
    for(int i = 0; i < T; i++){
        cin >> t;
        truth.insert(t);
    }
    vector<vector<int>> p;
    for(int i = 0; i < M; i++){
        cin >> T;
        vector<int> party(T,0);
        for(int j = 0; j < T; j++){
            cin >> party[j];
        }
        for(int j = 0; j < T; j++){
            relation[party[0]][party[j]] = 1;
            relation[party[j]][party[0]] = 1;
        }
        p.push_back(party);
    }
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(relation[i][k] && relation[k][j]) relation[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(relation[i][j] && truth.find(j) != truth.end()){
                for(int k = 1; k <= N; k++){
                    if(relation[i][k]) truth.insert(k);
                }
                break;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < p.size(); i++){
        bool check = false;
        for(int j = 0; j < p[i].size(); j++){
            if(truth.find(p[i][j]) != truth.end()){
                check = true;
                break;
            }
        }
        if(!check) cnt++;
    }

    cout << cnt;

	return 0;
}
