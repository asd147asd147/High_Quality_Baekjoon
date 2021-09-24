#include <bits/stdc++.h>

using namespace std;

int N;

vector< pair<int,int> > X,Y,Z;

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

long long ans = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for(int i = 0; i < N; i++){
        int x, y, z;
        cin >> x >> y >> z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    
    priority_queue< tuple<int,int,int> > pq;
    for(int i = 0; i < N-1; i++){
        pq.push({-abs(X[i].first-X[i+1].first),X[i].second, X[i+1].second});
        pq.push({-abs(Y[i].first-Y[i+1].first),Y[i].second, Y[i+1].second});
        pq.push({-abs(Z[i].first-Z[i+1].first),Z[i].second, Z[i+1].second});
    }

    for(int i = 0; i < N; i++){
        parent[i] = i;
    }
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if(find_parent(get<1>(p)) != find_parent(get<2>(p))){
            union_parent(get<1>(p), get<2>(p));
            ans += get<0>(p);
        }
    }
    cout << -ans;

    return 0;
}

