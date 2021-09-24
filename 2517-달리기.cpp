#include <bits/stdc++.h>

using namespace std;

int N;
int tree[1500001] = {0,};
vector<pair<int,int>> person;
vector<int> ans;

int query(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, node*2, left, right) + query(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int idx){
    if(idx < start || idx > end) return;
    tree[node] += 1;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node*2, idx);
    update(mid+1, end, node*2+1, idx);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for(int i = 1; i <= N; i++){
        int skill;
        cin >> skill;
        person.push_back({skill,i});
    }
    sort(person.begin(), person.end(), greater<pair<int,int>>());
    ans.resize(N);
    for(auto p = person.rbegin(); p != person.rend(); p++){
        int q = query(1, N, 1, 1, p->second);
        ans[p->second - 1] = p->second-q;
        update(1, N, 1, p->second);
    }

    for(auto a : ans){
        cout << a << "\n";
    }

    return 0;
}

