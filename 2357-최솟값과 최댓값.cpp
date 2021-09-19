#include <bits/stdc++.h>
#define MAX 1'000'000'001;
using namespace std;

int N, M;
int tree[2][1 << 19];

int update(long long left, long long right, long long idx, int num, long long pos, int type){
    if(left == right){
        return tree[type][pos] = num;
    }
    long long mid = (left + right)/2LL;
    int ret;
    if(idx <= mid){
        ret = update(left, mid, idx, num, 2*pos, type);
    }
    else{
        ret = update(mid+1, right, idx, num, 2*pos+1, type);
    }
    if(type){
        tree[type][pos] = min(ret, tree[type][pos]);
    }
    else{
        tree[type][pos] = max(ret, tree[type][pos]);
    }
    return tree[type][pos];
}

int query(long long left, long long right, long long sub_left, long long sub_right, long long pos, int type){
    if(sub_left <= left && right <= sub_right){
        return tree[type][pos];
    }

    int mid = (left + right)/2LL;
    int ret1, ret2;
    if(type){
        ret1 = ret2 = MAX;
    }
    else{
        ret1 = ret2 = 0;
    }
    if(sub_left <= mid){
        ret1 = query(left, mid, sub_left, sub_right, 2*pos, type);
    }
    if(mid+1 <= sub_right){
        ret2 = query(mid+1, right, sub_left, sub_right, 2*pos+1, type);
    }
    if(type){
        return min(ret1, ret2);
    }
    else{
        return max(ret1, ret2);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
    long long leaf;
	for(int i = 0; i <= 19; i++){
        if(1LL << i >= N){
            leaf = 1LL << i;
            break;
        }
	}
    for(int i = 0; i <= leaf; i++){
        tree[0][i] = 0;
        tree[1][i] = MAX;
    }

	for(int i = 1; i <= N; i++){
        int n;
        cin >> n;
        update(1, leaf, i, n, 1LL, 0);
        update(1, leaf, i, n, 1LL, 1);
	}

	for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << query(1, leaf, a, b, 1LL, 1) << " " << query(1, leaf, a, b, 1LL, 0) << "\n";
	}

	return 0;
}
