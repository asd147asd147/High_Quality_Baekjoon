#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> node(51);
int leaf = 0;
int n,root;

void dfs(int p){
    if(p==n) return;
    if(node[p].size()==0){
        leaf++;
        return;
    }
    for(auto s : node[p]){
        dfs(s);
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
        if(n==-1){
            root = i;
            continue;
        }
        node[n].push_back(i);
    }
    cin >> n;
    for(int i = 0; i < N; i++){
        for(auto j = node[i].begin(); j < node[i].end(); j++){
            if(*j == n) node[i].erase(j);
        }
    }

    dfs(root);
    cout << leaf;
	return 0;
}
