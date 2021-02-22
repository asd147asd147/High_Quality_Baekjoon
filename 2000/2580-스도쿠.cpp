#include <bits/stdc++.h>

using namespace std;

int board[9][9];
int N;
vector<pair<int,int>> blank;
vector<vector<bool>> col;
vector<vector<bool>> row;
vector<vector<bool>> mat;

int backtracking(int n){
    if(n == N) return 1;

    vector<bool> check(9,false);
    int i,j;
    i = blank[n].first, j = blank[n].second;
    for(int k = 0; k < 9; k++){
        check[k] = col[j][k] | row[i][k] | mat[(i/3)*3+j/3][k];
    }

    for(int k = 0; k < 9; k++){
        if(!check[k]){
            col[j][k] = row[i][k] = mat[(i/3)*3+j/3][k] = true;
            board[i][j] = k+1;
            if(backtracking(n+1)) return 1;
            col[j][k] = row[i][k] = mat[(i/3)*3+j/3][k] = false;
        }
    }
    return 0;
}

int main(){
    for(int i = 0; i < 9; i++){
        vector<bool> check(9,false);
        col.push_back(check);
        row.push_back(check);
        mat.push_back(check);
    }

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(!board[i][j]){
                blank.push_back(make_pair(i,j));
            }
            else{
                col[j][board[i][j]-1] = true;
                row[i][board[i][j]-1] = true;
                mat[(i/3)*3+j/3][board[i][j]-1] = true;
            }
        }
    }
    N = blank.size();
    backtracking(0);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}
