#include <bits/stdc++.h>

using namespace std;

int N,ans = 0;
int student[100001];
bool visited[100001], check[100001];

void cycle(int index){
    int next_num = student[index];
	visited[index] = true;

	if (!visited[next_num])
		cycle(next_num);
	else {
		if (!check[next_num]) {
			for (int i = next_num; i != index; i = student[i]) ans++;
			ans++;
		}
	}
	check[index] = true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
        cin >> N;
        ans = 0;
        for(int i = 1; i <= N; i++){
            cin >> student[i];
            visited[i] = false;
            check[i] = false;
        }

        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                cycle(i);
            }
        }
        cout << N - ans << "\n";
	}
	return 0;
}
