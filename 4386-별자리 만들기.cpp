#include <bits/stdc++.h>

using namespace std;

int N;
typedef struct _point{
    double x, y;
} Point;

vector<Point> group;
vector<tuple<double,int,int>> graph;
vector<int> parent;

int find_parent(int x){
    if(parent[x] == x) return x;
    else{
        return parent[x] = find_parent(parent[x]);
    }
}

void Union(int x, int y){
    y = find_parent(y);
    x = find_parent(x);

    parent[y] = x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N;
    group.resize(N);
    for(int i = 0; i < N; i++){
        Point p;
        cin >> p.x >> p.y;
        group[i] = p;
    }

    for(int i = 0; i < N-1; i++){
        int idx = i+1;
        for(int j = i+1; j < N; j++){
            double dist = sqrt((group[i].x - group[j].x)*(group[i].x - group[j].x) + (group[i].y - group[j].y)*(group[i].y - group[j].y));
            graph.push_back({dist, i, j});
        }
    }
    sort(graph.begin(), graph.end());
    parent.resize(N);
    for(int i = 0; i < N; i++) parent[i] = i;
    double ans = 0;
    for(auto g : graph){
        if(find_parent(get<1>(g)) != find_parent(get<2>(g))){
            Union(get<1>(g), get<2>(g));
            ans += get<0>(g);
        }
    }
    cout << ((double)(int)(ans*100))/100;

	return 0;
}
