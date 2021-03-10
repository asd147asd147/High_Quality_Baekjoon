#include <bits/stdc++.h>

using namespace std;

typedef struct __Node{
    int key;
    __Node* left = nullptr;
    __Node* right = nullptr;
    __Node(int k){key = k;}
} Node;

void add(Node* p, int k){
    if(p->key < k){
        if(p->right == nullptr){
            p->right = new Node(k);
        }
        else{
            add(p->right,k);
        }
    }
    else{
        if(p->left == nullptr){
            p->left = new Node(k);
        }
        else{
            add(p->left,k);
        }
    }
}

void post(Node* p){
    if(p->left == nullptr && p->right == nullptr){
        cout << p->key <<"\n";
        return;
    }
    if(p->left != nullptr){
        post(p->left);
    }
    if(p->right != nullptr){
        post(p->right);
    }
    cout << p->key << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    Node root(n);
    while(cin >> n){
        if(n != EOF) add(&root,n);
    }
    post(&root);

	return 0;
}
