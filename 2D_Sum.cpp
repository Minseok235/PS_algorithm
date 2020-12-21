// 두 점이 주어졌을 때2차원 배열의 합: (i,j)부터 (x,y)까지 지정되어 있는 수들의 합
#include<iostream>
#include<algorithm>
#include <limits.h>
#include <vector>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std;
int N,M,K;
int D[305][305];
void input(){
    cin>>N>>M;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            cin>>D[i][j];
        }
    }
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            D[i][j]+=(D[i-1][j]+D[i][j-1]-D[i-1][j-1]);
        }
    }
    cin>>K;

}

void pro(){
    for (int i=1; i<=K; i++){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        cout<<(D[x2][y2]-D[x2][y1-1]-D[x1-1][y2]+D[x1-1][y1-1])<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    pro();
}


