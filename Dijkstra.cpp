#include <vector>
#include <queue>
using namespace std;
struct Dijkstra{
    struct Info{
        int v;
        int dist;
        Info() {v=dist=0;}
        Info(int v, int dist): v(v),dist(dist){}
    };
    struct customCompare{
        bool operator()(const Info& lhs, const Info& rhs){
            return lhs.dist > rhs.dist;
        }
    };
    int n;
    int DEF;
    vector<int> dis;
    vector<vector<Info>> edges;
    priority_queue<Info, vector<Info>, customCompare> pq;

    vector<int> process(int start){
        for (int i=1; i<=n;i++){
            dis[i] = DEF;
        }
        dis[start] = 0;
        pq.push(Info(start,0));
        while(!pq.empty()){
            Info cur = pq.top();
            pq.pop();
            if (dis[cur.v] != cur.dist) continue;
            for (Info& edge: edges[cur.v]){
                if (dis[edge.v] > dis[cur.v]+edge.dist){
                    dis[edge.v] = dis[cur.v]+edge.dist;
                    pq.push(Info(edge.v, dis[edge.v]));
                }
            }
        }
        return dis;
    }

    Dijkstra(): n(0),DEF(0){
        dis.clear();
        edges.clear();
    };
    Dijkstra(int n, int DEF): n(n),DEF(DEF){
        dis.resize(n+1);
        edges.resize(n+1);
        for (int i=1; i<=n; i++){
            edges[i].clear();
        }
    }
    void addEdge(int x, int y, int dist){
        edges[x].push_back(Info(y, dist));
    }
    vector<int> solve(int start){
        return process(start);
    }

};



#include <iostream>
#include <limits.h>
int V,E,K;      //v:정점의개수, E: 간선의 개수, K: 시작정점

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>V>>E>>K;
    Dijkstra ds(V, INT_MAX);
    for (int i=1; i<=E; i++){
        int u,v,dist;
        cin>>u>>v>>dist;
        ds.addEdge(u,v,dist);
    }
    vector<int> ans = ds.solve(K);
    for (int i=1; i<=V; i++){
        if (ans[i]==INT_MAX) cout<<"INF"<<"\n";
        else cout<<ans[i]<<"\n";
    }
    return 0;
}

