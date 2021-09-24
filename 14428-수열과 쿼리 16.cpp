#include <bits/stdc++.h>
#define MAX 1e+10

using namespace std;

typedef struct _node{
    int idx = 1 << 19;
    long long num = MAX;
} NODE;

NODE tree[1 << 19] = {0,};

int N;

NODE compare(NODE left, NODE right){
    if(left.num <= right.num){
        return left;
    }
    else{
        return right;
    }
}

void update(int left, int right, int idx, long long num, int pos){
    if(left == right){
        tree[pos].idx = idx;
        tree[pos].num = num;
        return;
    }

    int mid = (left + right)/2;
    if(idx <= mid){
        update(left, mid, idx, num, 2*pos);
    }
    else{
        update(mid+1, right, idx, num, 2*pos+1);
    }
    tree[pos] = compare(tree[2*pos], tree[2*pos+1]);
}

NODE query(int left, int right, int sub_left, int sub_right, int pos){
    if(sub_left <= left && right <= sub_right){
        return tree[pos];
    }

    int mid = (left + right)/2;
    NODE temp;
    if(sub_left <= mid){
        temp = compare(temp, query(left, mid, sub_left, sub_right, 2*pos));
    }
    if(mid+1 <= sub_right){
        temp = compare(temp, query(mid+1, right, sub_left, sub_right, 2*pos+1));
    }
    return temp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int leaf;
	for(int i = 0; i <= 19; i++){
        if(1 << i >= N){
            leaf = 1 << i;
            break;
        }
	}

	for(int i = 1; i <= N; i++){
        long long A;
        cin >> A;
        update(1,leaf,i,A,1);
	}

	int M;
	cin >> M;

    for(int i = 0; i < M; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1,leaf,b,c,1);
        }
        else{
            cout << query(1, leaf, b, c, 1).idx << "\n";
        }
    }

	return 0;
}
