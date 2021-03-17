#include <bits/stdc++.h>
#define INF 3000000001

using namespace std;

int N;
vector<long long> solution;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int num;
	for(int i = 0; i < N; i++){
        cin >> num;
        solution.emplace_back(num);
	}
	sort(solution.begin(), solution.end());
	vector<int> pos = {0,1,2};
	long long m = INF;
    int i = 0;
	while(i < N-2){
        int start = i+1,finish = N-1;
        while(start < finish){
            long long a = solution[finish] + solution[start] + solution[i];
            if(m > abs(a)){
                m = abs(a);
                pos[0] = i, pos[1] = start, pos[2] = finish;
            }

            if(solution[finish] + solution[start] + solution[i] < 0)  start++;
            else finish--;
        }
        i++;
	}

	for(auto p : pos)
        cout << solution[p] << " ";
	return 0;
}
