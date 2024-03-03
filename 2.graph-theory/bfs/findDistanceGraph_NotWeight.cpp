/******************************************************************************

Competitive Programmer’s Handbook.pdf Page 119, 120

Extremely attentive: Should check the path is one direction or two direction

one direction : 1->2: 5 but 5->1: cannot
two direction: 1->2: 5 and 2->1: 5 => Should push the value in vector (dataa[1].push_back(2) and dataa[2].push_back(1))

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
bool visited[105];
int dis[105];
vector<int> dataa[105];

void resetData() {
    for (int i = 1; i < n+1; i++) {
        visited[i] = false;
        dis[i] = 0;
    }
}

void findDistanceGraph(int start) {
    queue<int> q;
    
    resetData();
    visited[start] = true;
    dis[start] = 0;
    q.push(start);
    
    while(!q.empty()) {
        int root = q.front(); q.pop();
        
        for (auto i : dataa[root]) {
            if (visited[i]) continue;
            visited[i] = true;
            dis[i] = dis[root] + 1;            
            q.push(i);
        }
    }
}

void input() {
    n = 6;
    
    dataa[1].push_back(2);
    dataa[1].push_back(4);
    dataa[2].push_back(1);
    dataa[2].push_back(3);
    dataa[2].push_back(5);
    dataa[3].push_back(2);
    dataa[3].push_back(6);
    dataa[4].push_back(1);
    dataa[5].push_back(2);
    dataa[5].push_back(6);
    dataa[6].push_back(3);
    dataa[6].push_back(5);
}

void output() {
    for (int i = 1; i < n+1; i++) {
        cout << "dis[" << i << "]: " << dis[i] << endl;
    }
}

int32_t main()
{
    input();
    findDistanceGraph(1);
    output();

    return 0;
}