#include <bits/stdc++.h>

using namespace std;

int N;
bool visited[1000001] = {false,};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	queue<vector<int>> q;
	q.push(vector<int>(1,N));
	while(!q.empty()){
        vector<int> t = q.front();
        visited[t.back()] = true;
        q.pop();
        if(t.back() == 1){
            cout << t.size()-1 << "\n";
            for(auto s : t)
                cout << s << " ";
            break;
        }
        if(t.back()%3 == 0 && !visited[t.back()/3]){
            t.push_back(t.back()/3);
            q.push(t);
            t.pop_back();
        }
        if(t.back()%2 == 0 && !visited[t.back()/2]){
            t.push_back(t.back()/2);
            q.push(t);
            t.pop_back();
        }
        if(!visited[t.back()-1]){
            t.push_back(t.back()-1);
            q.push(t);
            t.pop_back();
        }
	}

	return 0;
}
