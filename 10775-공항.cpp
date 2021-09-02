#include <bits/stdc++.h>

using namespace std;

int G,P;

int parent[100001];

int find_parent(int x){
    if(x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    parent[y] = x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> G >> P;

	for(int i = 0; i <= G; i++){
        parent[i] = i;
	}
    int ans = 0;
	for(int i = 0; i < P; i++){
        int temp;
        cin >> temp;
        temp = find_parent(temp);
        if(!temp) break;
        union_parent(temp-1,temp);
        ans++;
	}
    cout << ans;

	return 0;
}
