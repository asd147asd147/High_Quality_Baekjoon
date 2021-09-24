#include <bits/stdc++.h>

using namespace std;
unsigned int N,M,K;
vector<unsigned int> minsu;

int parent[4000002];

int find_parent(unsigned int x){
    if(x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}

void make_union(unsigned int x, unsigned int y){
    x = find_parent(x);
    y = find_parent(y);
    parent[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    minsu.resize(M);
    for(unsigned int i = 0; i < M; i++){
        cin >> minsu[i];
    }
    for(unsigned int i = 0; i < M; i++){
        parent[i] = i;
    }
    sort(minsu.begin(), minsu.end());

    for(int i = 0; i < K; i++){
        unsigned int c;
        cin >> c;
        unsigned int pos = lower_bound(minsu.begin(), minsu.end(), c+1) - minsu.begin();
        pos = find_parent(pos);
        cout << minsu[pos] << "\n";
        make_union(find_parent(pos), find_parent(pos+1));
    }

    return 0;
}

