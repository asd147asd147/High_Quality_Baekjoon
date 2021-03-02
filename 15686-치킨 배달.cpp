#include <bits/stdc++.h>
#define INF 9999999

using namespace std;

int N,M;
int ans = INF;
bool check[14] = {false,};
vector<pair<int,int>> chicken, house;

int gap(pair<int,int> p1, pair<int,int> p2){
    return abs(p2.first - p1.first) + abs(p2.second - p1.second);
}

void DFS(int idx, int select){
    if(select == M){
        int min_dist = 0;
        for(int i = 0; i < house.size(); i++){
            int dist = INF;
            for(int j = 0; j < chicken.size(); j++){
                if(check[j]){
                    dist = min(dist, gap(house[i],chicken[j]));
                }
            }
            min_dist += dist;
        }
        ans = min(ans, min_dist);
        return;
    }
    if(idx == chicken.size()) return;

    check[idx] = 1;
    DFS(idx+1, select+1);
    check[idx] = 0;
    DFS(idx+1, select);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int temp;
            cin >> temp;
            if(temp == 2){
                chicken.push_back(make_pair(i,j));
            }
            else if(temp == 1){
                house.push_back(make_pair(i,j));
            }
        }
	}

	DFS(0,0);
    cout << ans;

	return 0;
}
