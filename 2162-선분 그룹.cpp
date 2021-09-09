#include <bits/stdc++.h>

using namespace std;

typedef struct _point{
    long long x, y;
} Point;

typedef struct _line{
    Point p1, p2;
} Line;

int parent[3001];
int find_parent(int x){
    if(x == parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}
void make_union(int x, int y){
    x = find_parent(x);
    y = find_parent(y);
    parent[y] = x;
}

int CCW(Point &p1, Point &p2, Point &p3){
    long long temp = (p2.x-p1.x) * (p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
    if(temp > 0) return 1;
    else if(temp == 0) return 0;
    return -1;
}
int same(Point &p1, Point &p2){
    if(p1.x == p2.x && p1.y == p2.y) return 1;
    return 0;
}
int cross(Line &l1, Line &l2){
    if(same(l1.p1, l2.p1) || same(l1.p1, l2.p2) || same(l1.p2, l2.p1) || same(l1.p2, l2.p2)){
        return 1;
    }

    int ccw1, ccw2;
    ccw1 = CCW(l1.p1,l1.p2,l2.p1) * CCW(l1.p1,l1.p2,l2.p2);
    ccw2 = CCW(l2.p1,l2.p2,l1.p1) * CCW(l2.p1,l2.p2,l1.p2);
    if(ccw1 == 0 && ccw2 == 0){
        if(l1.p1.x == l1.p2.x){
            return min(l2.p1.y, l2.p2.y) <= max(l1.p1.y, l1.p2.y) && min(l1.p1.y, l1.p2.y) <= max(l2.p1.y, l2.p2.y);
        }
        else{
            return min(l2.p1.x, l2.p2.x) <= max(l1.p1.x, l1.p2.x) && min(l1.p1.x, l1.p2.x) <= max(l2.p1.x, l2.p2.x);
        }
    }
    return ccw1 <= 0 && ccw2 <= 0;
}
vector<Line> LINE;
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        parent[i] = i;
    }

    for(int i = 0; i < N; i++){
        Line l;
        cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
        LINE.push_back(l);
    }
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(find_parent(i) != find_parent(j)){
                if(cross(LINE[i], LINE[j])){
                    make_union(i,j);
                }
            }
        }
    }
    map<int,int> m;
    for(int i = 0; i < N; i++){
        m[find_parent(i)] += 1;
    }
    cout << m.size() << "\n";
    int ans = 0;
    for(auto t : m){
        ans = max(ans, t.second);
    }
    cout << ans;
    return 0;
}

