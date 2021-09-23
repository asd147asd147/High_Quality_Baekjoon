#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<long long, long long>> points;

bool comp(pair<long long, long long> &a, pair<long long, long long> &b){
    if(a.second * b.first != a.first * b.second){
        return a.second * b.first < a.first * b.second;
    }

    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

long long ccw(pair<long long, long long> &a, pair<long long, long long> &b, pair<long long, long long> &c){
    return (a.first * b.second + b.first * c.second + c.first * a.second - b.first * a.second - c.first * b.second - a.first * c.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
    points.resize(N);

	for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
	}
    sort(points.begin(), points.end(), [](pair<long long, long long> a, pair<long long, long long> b){if(a.second != b.second){return a.second < b.second;} return a.first < b.first;});
    for(int i = 1; i < N; i++){
        points[i].first -= points[0].first;
        points[i].second -= points[0].second;
    }
    sort(points.begin()+1, points.end(), comp);
    points[0].first = points[0].second = 0;

    stack<int> s;
    s.push(0);
    s.push(1);
    int next = 2;

    while (next < N) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();
            if (ccw(points[first], points[second], points[next]) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }
    cout << s.size();

	return 0;
}
