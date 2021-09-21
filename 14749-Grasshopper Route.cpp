#include <bits/stdc++.h>

using namespace std;

int N, s, e;

vector<vector<int>> vec;
vector<int> visited;
typedef struct _node{
    struct _node* parent;
    int num;
    set<struct _node*> child;
} NODE;

NODE* root;
NODE* leaf;

void make_tree(NODE* node){
    for(auto n : vec[node->num]){
        if(visited[n]) continue;
        visited[n] = 1;
        NODE* temp = new NODE();
        temp->num = n;
        temp->parent = node;
        node->child.insert(temp);
        make_tree(temp);
        if(n == e){
            leaf = temp;
        }
    }
}

void make_leaf(NODE* node){
    for(auto c : node->child){
        c->parent = node->parent;
        c->parent->child.insert(c);
    }
    node->child.clear();
}

NODE* find_new_parent(NODE* node, NODE* check){
    for(auto c : node->child){
        if(c == check) continue;
        if(c->child.size() != 0){
            for(auto cc : c->child){
                return cc;
            }
        }
        return c;
    }
    return 0;
}

NODE* join_sibling(NODE* node){
    if(node->parent->child.size()!=1){
        NODE* new_parent = find_new_parent(node->parent, node);
        node->parent->child.erase(node->parent->child.find(node));
        node->parent = new_parent;
        new_parent->child.insert(node);
        return node;
    }
    else{
        return node->parent;
    }
}

int main(){
    cin >> N;
    vec.resize(N+1);
    visited.resize(N+1);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    cin >> s >> e;
    root = new NODE();
    root->num = s;
    root->parent = 0;
    visited[s] = 1;
    
    make_tree(root);
    make_leaf(leaf);
    while(leaf->parent != 0){
        leaf = join_sibling(leaf);
    }
    while(leaf->child.size()){
        cout << leaf->num << "\n";
        for(auto c : leaf->child){
            leaf = c;
        }
    } 
    cout << leaf->num;

    return 0;
}
