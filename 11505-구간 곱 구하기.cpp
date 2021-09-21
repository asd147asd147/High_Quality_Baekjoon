#include <bits/stdc++.h>
#define MOD 1'000'000'007LL

using namespace std;
int N, M, K;
long long tree[1 << 23];

void update(int left, int right, int idx, long long num, int pos){
    if(left == right){
        tree[pos] = num % MOD;
        return;
    }
    int mid = (left + right)/2;
    if(idx <= mid){
        update(left, mid, idx, num, 2*pos);
    }
    else{
        update(mid+1, right, idx, num, 2*pos+1);
    }
    tree[pos] = ((tree[2*pos+1] % MOD) * (tree[2*pos] % MOD)) % MOD;
    return;
}

long long query(int left, int right, int sub_left, int sub_right, int pos){
    if(sub_left <= left && right <= sub_right){
        return tree[pos] % MOD;
    }
    int mid = (left + right)/2;
    long long temp = 1;
    if(sub_left <= mid){
        temp = (temp * query(left, mid, sub_left, sub_right, 2*pos)) % MOD;
    }
    if(mid+1 <= sub_right){
        temp = (temp * query(mid+1, right, sub_left, sub_right, 2*pos+1)) % MOD;
    }
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int leaf;
    cin >> N >> M >> K;
    for(int i = 0; i <= 23; i++){
        if((1 << i) >= N){
            leaf = 1 << i;
            break;
        }
    }

    for(int i = 1; i < (1 << 23); i++){
        tree[i] = 1;
    }

    for(int i = 1; i <= N; i++){
        long long n;
        cin >> n;
        update(1,leaf,i,n,1);    
    }

    for(int i = 0; i < M+K; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1,leaf,b,c,1);
        }
        else{
            cout << query(1,leaf,b,c,1) << "\n";
        }
    }

    return 0;
}

