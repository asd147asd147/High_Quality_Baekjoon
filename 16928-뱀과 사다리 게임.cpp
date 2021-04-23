#include <bits/stdc++.h>

using namespace std;

vector<int> skills(101);
vector<int> visited(101,100);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 1; i <= 100; i++){
        skills[i] = i;
	}
	int ladder, snake;
	cin >> ladder >> snake;
	for(int i = 0; i < ladder+snake; i++){
        int a, b;
        cin >> a >> b;
        skills[a] = b;
	}

	queue<pair<int,int>> q;

	q.push({1,0});
	visited[1] = 0;
	while(!q.empty()){
        auto p = q.front();
        q.pop();
        if(p.first == 100){
            cout << p.second;
            break;
        }
        for(int i = 1; i <= 6; i++){
            if(p.first + i > 100) break;
            if(visited[skills[p.first + i]] < p.second+1) continue;
            q.push({skills[p.first + i], p.second+1});
            visited[skills[p.first + i]] = p.second+1;
        }
	}
	return 0;
}
