#include <bits/stdc++.h>

using namespace std;

int N, K;
int max_point = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> arr(8,vector<int>(8,0)), extra1(8,vector<int>(8,0)), extra2(8,vector<int>(8,0)), refer(8,vector<int>(8,0));
vector<int> bullet;

void shoot(int k, int point){
//    if(point == 18 || point == 26){
//
//    for(auto a : arr){
//        for(auto b : a){
//            cout << b << " ";
//        }
//        cout << "\n";
//	}
//	cout << point << "\n";
//	cout << "\n";
//
//    }
    if(k == K){
        max_point = max(max_point, point);
        return;
    }
    for(int i = 0; i < N; i++){
        int add_point = 0;
        int orin_point;
        int col = 0;
        bool flag = false;
//        cout << k << " " << i << "\n";
        vector<pair<int,int>> extra1_target, extra2_target;
        for(int j = 0; j < N; j++){
            if(arr[i][j] > 0){
                orin_point = arr[i][j];
                if(arr[i][j] >= 10){
                    add_point = arr[i][j];
                    arr[i][j] = 0;
                }
                else{
                    arr[i][j] -= bullet[k];
                    if(arr[i][j] <= 0){
                        arr[i][j] = 0;
                        for(int t = 0; t < 4; t++){
                            if(0 <= i+dy[t] && i+dy[t] < N && 0 <= j+dx[t] && j+dx[t] < N && arr[i+dy[t]][j+dx[t]] == 0){
                                arr[i+dy[t]][j+dx[t]] = (int)(refer[i][j]/4);
                                if((int)(refer[i][j]/4) == 1){
                                    extra1[i+dy[t]][j+dx[t]]++;
                                    extra1_target.emplace_back(i+dy[t], j+dx[t]);
                                }
                                else{
                                    extra2[i+dy[t]][j+dx[t]]++;
                                    extra2_target.emplace_back(i+dy[t], j+dx[t]);
                                }
                            }
                        }
                        if(extra1[i][j] > 0){
                            add_point += 1;
                        }
                        else if(extra2[i][j] > 0){
                            add_point += 2;
                        }
                        else{
                            add_point = refer[i][j];
                        }
                    }
                }
                col = j;
                flag = true;
                break;
            }
        }
        shoot(k+1, point+add_point);
        if(flag){
            arr[i][col] = orin_point;
            if(extra1_target.size() > 0){
                for(auto e : extra1_target){
                    arr[e.first][e.second] = 0;
                    extra1[e.first][e.second]--;
                }
            }
            if(extra2_target.size() > 0){
                for(auto e : extra2_target){
                    arr[e.first][e.second] = 0;
                    extra2[e.first][e.second]--;
                }
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            refer[i][j] = arr[i][j];
        }
    }
	for(int i = 0; i < K; i++){
        int t;
        cin >> t;
        bullet.emplace_back(t);
	}

	shoot(0, 0);
	cout << max_point;

	return 0;
}
