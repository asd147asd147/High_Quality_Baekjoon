#include <bits/stdc++.h>

using namespace std;

typedef struct _point{
    long long x;
    long long y;
} Point;

typedef struct _line{
    Point p1, p2;
} Line;

long long CCW(Point &p1, Point &p2, Point &p3){
    long long temp = (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
    if(temp > 0) return 1;
    else if(temp == 0) return 0;
    else return -1;
}

bool same(Point &p1, Point &p2){
    if(p1.x == p2.x && p1.y == p2.y) return 1;
    return 0;
}

bool cross(Line &l1, Line &l2){
    if(same(l1.p1, l2.p1) || same(l1.p1, l2.p2) || same(l1.p2, l2.p1) || same(l1.p2, l2.p2)) return 1;
    else if(CCW(l1.p1,l1.p2,l2.p1) * CCW(l1.p1,l1.p2,l2.p2) == 0 &&
        CCW(l2.p1,l2.p2,l1.p1) * CCW(l2.p1,l2.p2,l1.p2) == 0){
        if(l1.p1.x == l1.p2.x){
            return min(l2.p1.y, l2.p2.y) <= max(l1.p1.y, l1.p2.y) && min(l1.p1.y, l1.p2.y) <= max(l2.p1.y, l2.p2.y);
        }
        else{
            return min(l2.p1.x, l2.p2.x) <= max(l1.p1.x, l1.p2.x) && min(l1.p1.x, l1.p2.x) <= max(l2.p1.x, l2.p2.x);
        }
    }
    return CCW(l1.p1,l1.p2,l2.p1) * CCW(l1.p1,l1.p2,l2.p2) <= 0 && CCW(l2.p1,l2.p2,l1.p1) * CCW(l2.p1,l2.p2,l1.p2) <= 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Line l1, l2;

	cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y;
	cin >> l2.p1.x >> l2.p1.y >> l2.p2.x >> l2.p2.y;
    cout <<cross(l1,l2);

	return 0;
}
