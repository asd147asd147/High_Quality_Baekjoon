#include <bits/stdc++.h>

using namespace std;

bool check[100001] = {false,};
int parent[100001] = {0,};
vector<set<int>> vec(100001);

void DFS(int p, int c){
    for(auto i = vec[c].begin(); i!=vec[c].end(); i++){
        if(check[*i]){
            parent[c] = *i;
        }
        else{
            check[*i] = true;
            DFS(c,*i);
            check[*i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    for(int i = 0; i < N-1; i++){
        int a,b;
        cin >> a >> b;
        vec[a].insert(b);
        vec[b].insert(a);
    }

    check[1] = true;
    for(auto i = vec[1].begin(); i!=vec[1].end(); i++){
        check[*i] = true;
        DFS(1,*i);
        check[*i] = false;
    }

    for(int i = 2; i <= N; i++)
        cout << parent[i] << "\n";

	return 0;
}
