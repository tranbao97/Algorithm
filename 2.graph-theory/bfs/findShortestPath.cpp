/**
 * 
-: biểu diễn một ô trống
+: biểu diễn một vật cản
S: là điểm xuất phát, chỉ tồn tại duy nhất một điểm xuất phát trong ma trận
D: là điểm đích, chỉ tồn tại duy nhất một điểm đích trong ma trận
3 5
+++++
+S+D+
+---+
 * 
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long

int n, m;
char arr[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dis[101][101];
pair<int, int> posStart, posEnd;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') posStart = {i, j};
            if (arr[i][j] == 'D') posEnd = {i, j};
        }
    }
}

void resetData() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dis[i][j] = 0;
        }
    }
}

int findTheShortestPath(int startX, int startY) {
    int ans = -1;
    resetData();
    queue<pair<int, int>> q;
    q.push({startX, startY});
    
    while(!q.empty()) {
        pair<int, int> root;
        root = q.front(); q.pop();
        int posX = root.first, posY = root.second;
        
        for (int i = 0; i < 4; i++) {
            int newX = posX + dx[i], newY = posY + dy[i];
            
            if (newX < 0 || newY < 0 || newX >= n || newY >= m) continue;
            if ( (dis[newX][newY] + dis[posX][posY] >= dis[newX][newY] && dis[newX][newY] != 0) || arr[newX][newY] == '+') continue;
            
            dis[newX][newY] = dis[posX][posY] + 1;
            q.push({newX, newY});
        }
    }
    
    ans = dis[posEnd.first][posEnd.second] == 0 ? -1 : dis[posEnd.first][posEnd.second];
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    input();
    
    cout << findTheShortestPath(posStart.first, posStart.second);

    return 0;
}