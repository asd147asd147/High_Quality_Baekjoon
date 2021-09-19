#include <bits/stdc++.h>

using namespace std;

int N,M,K;
long long tree[(1 << 21)+ 10] = {0,};
int leaf;

long long update(int left, int right, int idx, long long num, int pos){
    int gap = 0;
    if(left == right){
        gap = num - tree[pos];
        tree[pos] = num;
        return gap;
    }
    int mid = (left+right)/2;
    if(idx <= mid){
        gap = update(left, mid, idx, num, 2*pos);
        tree[pos] += gap;
    }
    else{
        gap = update(mid+1, right, idx, num, 2*pos+1);
        tree[pos] += gap;
    }
    return gap;
}

long long query(int left, int right, int sub_left, int sub_right, int pos){
    if(sub_left <= left && right <= sub_right){
        return tree[pos];
    }
    int mid = (left+right)/2;
    long long sub_sum = 0;
    if(sub_left <= mid){
        sub_sum += query(left, mid, sub_left, sub_right, 2*pos);
    }
    if(mid+1 <= sub_right){
        sub_sum += query(mid+1, right, sub_left, sub_right, 2*pos+1);
    }
    return sub_sum;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 0; i <= 21; i++){
        if(1 << i >= N){
            leaf = 1 << i;
            break;
        }
	}

	for(int i = 1; i <= N; i++){
	    long long n;
        cin >> n;
        update(1,leaf,i,n,1);
	}

	for(int i = 0; i < M+K; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a==1){
            update(1,leaf,b,c,1);
        }
        else{
            cout << query(1,leaf,b,c,1) << "\n";
        }
	}

	return 0;
}
