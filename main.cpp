#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>

using namespace std;

ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

class graf
{
    int n,curent, distanta[50001];
    bool vizitate[50001];
    priority_queue <pair<int, int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;

public:
    graf(int n);
    void dijkstra(int nod, vector <pair<int, int>>G[50001]);
    void afiseaza_dijkstra();
    void init_dijkstra(int n);
    void dijkstraa(int n, int m);
};

graf::graf(int n)
{
    this->n = n;
}
void graf::init_dijkstra(int n){
    for(int i=1;i<=n;i++)
        {distanta[i] = INT_MAX;
        vizitate[i]=false;}
}
void graf::dijkstra(int s, vector <pair<int, int>>G[50001])
{
    init_dijkstra(n);
    distanta[s] = 0;
    pq.push(make_pair(distanta[s], s));
    vizitate[s] = true;

    while(!pq.empty()){
        curent=pq.top().second;
        vizitate[curent]=false;
        pq.pop();

    for(size_t i = 0; i < G[curent].size(); i++)
    {
        int vecin = G[curent][i].first;
        int cost = G[curent][i].second;

        if(distanta[curent] + cost < distanta[vecin])
        {
            distanta[vecin] = distanta[curent] + cost;
            if(!vizitate[vecin])
            {
                pq.push(make_pair(distanta[vecin], vecin));
                vizitate[vecin] = true;
            }


        }
    }

}}
void graf::afiseaza_dijkstra(){
    for(int i = 2; i <= n; i++)
        if(distanta[i] !=INT_MAX)
            g << distanta[i] << " ";
        else
            g <<" 0 "<<" ";
}
void graf::dijkstraa(int n, int m){
    int start_edge, end_edge, cost;
    vector <pair<int, int>>G[50001];
    for(int i = 0; i < m; i++)
    {
        f >> start_edge >> end_edge >> cost;
        G[start_edge].push_back(make_pair(end_edge, cost));
    }
    dijkstra(1, G);
    afiseaza_dijkstra();
}
int main()
{
    int n,m;
    f >> n >> m;
    graf g(n);
    g.dijkstraa(n, m);
    return 0;
}
