#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int M,N;
char c;
int map[105][105], dist[105][105];
bool visited[105][105];
int dir[4][2]{{1,0},{0,1},{-1,0},{0,-1}};

void input(){
    cin>>M>>N;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            cin>>c;
            if (c=='1') map[i][j] = 1;
            else map[i][j] = 0;
            dist[i][j] = INT_MAX;
        }
    }
}
void Dijkstra(){
    queue<pair<int,int>> pq;
    pq.push(make_pair(1,1));
    dist[1][1] = 0;
    while (!pq.empty()){
        int cur_x = pq.front().first;
        int cur_y = pq.front().second;
        pq.pop();
        for (int i=0; i<4; i++){
            int new_x = cur_x + dir[i][0];
            int new_y = cur_y + dir[i][1];
            if (new_x>0 && new_y>0 && new_x<=N && new_y<=M){
                if (dist[new_x][new_y]>dist[cur_x][cur_y]+map[new_x][new_y]){
                    dist[new_x][new_y] = dist[cur_x][cur_y]+map[new_x][new_y];
                    pq.push(make_pair(new_x,new_y));
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    Dijkstra();
    cout<<dist[N][M];
}


