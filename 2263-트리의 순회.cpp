#include <bits/stdc++.h>

using namespace std;

int N;
int in[100001],post[100001],idx[100001];

void pre(int in_begin, int in_end, int post_begin, int post_end){
    if(in_begin > in_end || post_begin > post_end) return;
    cout << post[post_end] << " ";
    int i = idx[post[post_end]];
    pre(in_begin,i-1,post_begin,post_begin+(i-in_begin)-1);
    pre(i+1,in_end,post_begin+(i-in_begin),post_end-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> in[i];
        idx[in[i]] = i;
    }
    for(int i = 0; i < N; i++){
        cin >> post[i];
    }
    pre(0,N-1,0,N-1);

	return 0;
}
