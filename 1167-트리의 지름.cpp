#include <bits/stdc++.h>

using namespace std;

int N;
vector<map<int,int>> tree(100001);
bool visited[100001] = {false,};
int max_node = 1, max_len = 0;

void half(int dist, int child){
    bool check = false;
    for(auto t : tree[child]){
        if(!visited[t.first]){
            check = true;
            visited[t.first] = true;
            half(dist+t.second, t.first);
        }
    }
    if(!check){
        if(max_len < dist){
            max_len = dist;
            max_node = child;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        int v,u,w;
        cin >> v;
        while(1){
            cin >> u;
            if(u==-1) break;
            cin >> w;
            tree[v][u] = w;
        }
    }
    visited[1] = true;
    half(0,1);
    for(int i = 0; i <= N; i++)
        visited[i] = false;
    visited[max_node] = true;
    half(0,max_node);
    cout << max_len;

	return 0;
}
