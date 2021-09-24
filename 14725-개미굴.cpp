#include <bits/stdc++.h>

using namespace std;

int N;

typedef struct _tri{
    string s = "";
    map<string, struct _tri*> child;
} TRI;

TRI* insert(TRI* node, string s){
    if(node->child[s] != 0){
        return node->child[s];
    }
    TRI* temp = new TRI();
    temp->s = s;
    node->child[s] = temp;
    return temp;
}

TRI* root = new TRI();

void dfs(TRI* node, int idx){
    for(auto r : node->child){
        if(r.second == 0) continue;
        for(int i = 0; i < idx*2; i++){
            cout << '-';
        }
        cout << r.first << endl;
        dfs(r.second, idx+1);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;

	for(int i = 0; i < N; i++){
        int K;
        cin >> K;
        TRI* prev = root;
        for(int j = 0; j < K; j++){
            string s;
            cin >> s;
            prev = insert(prev, s);
        }
	}
    dfs(root, 0);


	return 0;
}
