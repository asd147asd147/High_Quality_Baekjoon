#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> parent;

int find_parent(int x){
    if(parent[x] == x) return x;
    else{
        return parent[x] = find_parent(parent[x]);
    }
}

void Union(int x, int y){
    x = find_parent(x);
    y = find_parent(y);

    parent[y] = x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	parent.resize(N);
	for(int i = 0; i < N; i++){
        parent[i] = i;
	}

	for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        if(find_parent(a) != find_parent(b)){
            Union(a,b);
        }
        else{
            cout << i+1;
            return 0;
        }
	}

	cout << 0;

	return 0;
}
