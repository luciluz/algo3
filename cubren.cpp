void dfs(int v, int p = -1) { // DFS modificado para guardar back edges con extremo superio e inferior
    estado[v] = EMPECE_A_VER; 
    for (int u : aristas[v]) {
        if (estado[u] == NO_LO_VI) {
            tree_edges[v].push_back(u);
            padre[u]=v;
            dfs(u, v);
        }
        else if (u != padre[v]) {
            if (estado[u] == EMPECE_A_VER) {
                back_edges_con_extremo_superior_en[v]++;
            }
            else // estado[u] == TERMINE_DE_VER
                back_edges_con_extremo_inferior_en[v]++;
        }
    }
    estado[v] = TERMINE_DE_VER;
}

int cubren(int v, int p) { // algoritmo que dado una arista te dice cuántas backedge la cubren
    if (memo[v] != -1) return memo[v];
    int res = 0;
    for (int hijo : tree_edges[v]) {
        if (hijo != p) {
            res += cubren(hijo, v);
        }
    }
    res += back_edges_con_extremo_superior_en[v]; // esta las suma ya que son las que la cubren
    res -= back_edges_con_extremo_inferior_en[v]; // esta las resta porque no cubren, la arista está por sobre el ciclo
    memo[v] = res;
    return res;
}
