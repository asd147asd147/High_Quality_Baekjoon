#include <bits/stdc++.h>

using namespace std;

typedef struct __NODE{
    int left = -19, right = -19;
} NODE;
NODE node[27];

void in(int idx){
    if(node[idx].left >= 0){
        in(node[idx].left);
    }
    cout << (char)('A'+idx);
    if(node[idx].right >= 0){
        in(node[idx].right);
    }
}

void post(int idx){
    if(node[idx].left >= 0){
        post(node[idx].left);
    }
    if(node[idx].right >= 0){
        post(node[idx].right);
    }
    cout << (char)('A'+idx);
}

void pre(int idx){
    cout << (char)('A'+idx);
    if(node[idx].left >= 0){
        pre(node[idx].left);
    }
    if(node[idx].right >= 0){
        pre(node[idx].right);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        char p,l,r;
        cin >> p >> l >> r;
        node[p-'A'].left = l - 'A';
        node[p-'A'].right = r- 'A';
    }
    pre(0);
    cout << "\n";
    in(0);
    cout << "\n";
    post(0);
    cout << "\n";

	return 0;
}
