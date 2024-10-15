#include <bits/stdc++.h>
 
using namespace std;
 
const int inf = 1e9+1;
 
void dfs(vector<vector<int>>& g, vector<bool>& visitado, int v){
    visitado[v] = true;
    for(int u = 0; u < g.size(); u++)
        if(g[v][u] != inf and !visitado[u]) dfs(g,visitado,u);
}
 
bool es_conexo(vector<vector<int>>& g){
    vector<bool> visitado(g.size());
    dfs(g,visitado,0);
    for(auto b : visitado) if(!b) return false;
    return true;
}
 
long long costo_agm(vector<vector<int>>& g){
    int n = g.size();
    long long res = 0;
    //Inicializar con un arbol de un solo vertice
    vector<bool> es_rojo(g.size());
    es_rojo[0] = true;
    vector<int> rojo_mas_cercano(n,0);
 
    for(int it = 0; it < n-1; it++){
        //Agregar la arista violeta mas barata
        int w = 0;
        while(es_rojo[w]) w++;
 
        for(int u = w; u < n; u++){
            if(!es_rojo[u] and g[u][rojo_mas_cercano[u]] < g[w][rojo_mas_cercano[w]]) {
                //ver si u tiene una violeta mas barata que w
                w = u;
            }    
        }
 
        res += g[w][rojo_mas_cercano[w]];
        es_rojo[w] = true;
        for(int v = 0; v < n; v++){
            //ver si w esta mas cerca de v que rojo mas cercano[v]
            if(!es_rojo[v] and g[w][v] < g[v][rojo_mas_cercano[v]])
                rojo_mas_cercano[v] = w;
        }
 
    }
    
    return res;
}
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n,vector<int>(n,inf));
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--, v--;
        g[u][v] = g[v][u] = w;
    }
    if(!es_conexo(g)){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    
    cout<<costo_agm(g)<<'\n';
    
    return 0;
}
