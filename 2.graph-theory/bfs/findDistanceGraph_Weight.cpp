/******************************************************************************

https://codepro.lge.com/exam/19/overseas-questions-for-previous-test/quiz/11

Extremely attentive: Should check the path is one direction or two direction

one direction : 1->2: 5 but 5->1: cannot
two direction: 1->2: 5 and 2->1: 5 => Should push the value in vector (dataa[1].push_back(2) and dataa[2].push_back(1))

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int dis[105];
vector<pair<int, int>> vec[105];

void input() {
    cin >> n >> m;
    int fW, sW, d;
    for (int i = 1; i < m+1; i++) {
        cin >> fW >> sW >> d;
        vec[fW].push_back({sW, d});
        vec[sW].push_back({fW, d});
    }
}

void resetData() {
    for (int i = 1; i < n+1; i++) {
        dis[i] = -1;
    }
}

int findMinDistance(int pos) {
    int maxDis = INT_MIN;
    queue<int> q;
    resetData();
    dis[pos] = 0;
    
    q.push(pos);
    
    while (!q.empty()) {
        int root = q.front(); q.pop();
        for (auto i : vec[root]) {
            int newPos = i.first, dPos = i.second;
            if (dis[root] + dPos >= dis[newPos] && dis[newPos] != -1) continue;
            dis[newPos] = dis[root] + dPos;
            q.push(newPos);
        }
    }
    
    for (int i = 1; i < n+1; i++) maxDis = max(maxDis, dis[i]);
    return maxDis;
}

int32_t main()
{
    int minRes = INT_MAX;
    input();
    for (int i = 1; i < n+1; i++) minRes = min(minRes, findMinDistance(i));
    cout << minRes;
    return 0;
}
