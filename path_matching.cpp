#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    vector<int> *nodes;    
public:
    string S;
    string p;
    int u;
    int v;
    bool f = false;
    Graph(int V);
    void addEdge(int v, int w);
    int dfs(vector<bool> &V, int u, string &sub);
    void subString(string &sub);
};
 
Graph::Graph(int V)
{
    this->V = V;
    nodes = new vector<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    nodes[u].push_back(v);
    nodes[v].push_back(u);
}

int Graph::dfs(vector<bool> &V, int u, string &sub){
    V[u] = true;
    sub += S[u-1];
    for(int n = 0; n < nodes[u].size(); n++){
        if(f)
            return 0;
        if(!V[nodes[u][n]]){
            if(nodes[u][n] == v){                
                sub += S[v-1];                
                f = true;
                return 0;
            }
            dfs(V, nodes[u][n], sub);
        }
    }
    if(!f)
        sub.pop_back();
    return 0;
}
void Graph::subString(string &sub){
    int count = 0;
        size_t nPos = sub.find(p, 0);
        while(nPos != string::npos)
        {
            count++;
            nPos = sub.find(p, nPos+1);
        }
        cout<<count<<endl;
}

int main() {
    int n;
    int q;
    cin >> n >> q;
    Graph g(n+1);    
    cin >> g.S;
    cin >> g.p;
    
    for(int a0 = 0; a0 < n-1; a0++){ 
        int u;
        int v;
        cin >> u >> v;
        g.addEdge(u,v);        
    }
    map<pair<int, int>,string> mymap;
    for(int a0 = 0; a0 < q; a0++){        
        cin >> g.u >> g.v;        
        string sub;
        if(g.u == g.v){
            sub += g.S[g.u-1];            
        }else{
            map<pair<int, int>,string>::iterator it
                = mymap.find(make_pair(g.u,g.v));
            if(it != mymap.end()){
                sub += it->second;
            }else{
                vector<bool> visit(n+1,false);
                g.f = false;
                g.dfs(visit, g.u, sub);
                mymap.insert(make_pair(make_pair(g.u,g.v),sub));
                g.subString(sub);
                reverse(sub.begin(),sub.end());
                mymap.insert(make_pair(make_pair(g.v,g.u),sub));
                continue;
            }
        }
        g.subString(sub);
    }
    return 0;
}
