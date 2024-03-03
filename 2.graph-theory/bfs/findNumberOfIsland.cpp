/******************************************************************************

Give the 2d matrix that has 0s and 1s, 1 is land and 0 is water

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int n = 10;

int arr[n][n];
bool visited[n][n];
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input() {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

void resetData() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

void findIsland(int startX, int startY) {
    visited[startX][startY] = true;
    q.push({startX, startY});

    while (!q.empty()) {
        pair<int, int> root = q.front(); q.pop();
        int posX = root.first, posY = root.second;
        for (int i = 0; i < 4; i++) {
            int newX = posX + dx[i], newY = posY + dy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (visited[newX][newY]) continue;
            visited[newX][newY] = true;
            q.push({newX, newY});
        }

    }
}

int32_t main() {
    int cnt = 0;
    resetData();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                findIsland(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}