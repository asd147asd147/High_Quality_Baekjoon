#include <bits/stdc++.h>

using namespace std;

typedef struct __food{
    int mp=0,mf=0,ms=0,mv=0,c=0;
} food;

int N, cost = 10000;
vector<food> foods;
vector<int> ans;

int compare(vector<int> m){
    food sum;
    for(auto i : m){
        sum.mp += foods[i].mp;
        sum.mf += foods[i].mf;
        sum.ms += foods[i].ms;
        sum.mv += foods[i].mv;
        sum.c += foods[i].c;
    }
    if(foods[0].mp <= sum.mp && foods[0].mf <= sum.mf && foods[0].ms <= sum.ms && foods[0].mv <= sum.mv){
        if(cost > sum.c) cost = sum.c, ans = m;
        else if(cost == sum.c) ans > m ? ans = m : ans = ans;
        return 1;
    }
    return 0;
}

void backTracking(int t, vector<int> m){
    if(compare(m)) return;
    if(t==N) return;
    for(int i = t+1; i <= N; i++){
        m.push_back(i);
        backTracking(i,m);
        m.pop_back();
    }
}

int main(){
    cin >> N;
    food tmp;
    cin >> tmp.mp >> tmp.mf >> tmp.ms >> tmp.mv;
    foods.push_back(tmp);
    for(int i = 1; i <= N; i++){
        cin >> tmp.mp >> tmp.mf >> tmp.ms >> tmp.mv >> tmp.c;
        foods.push_back(tmp);
    }

    for(int i = 1; i <= N; i++){
        vector<int> m;
        m.push_back(i);
        backTracking(i,m);
    }

    if(cost == 10000){
        cout << -1;
        return 0;
    }
    cout << cost << "\n";
    for(auto a : ans)
        cout << a << " ";
	return 0;
}
