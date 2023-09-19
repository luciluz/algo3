# Práctica 3: Recorridos y Árboles

## Recorridos en profundidad

### Ejercicio 1

**a)**

**b)**

**c)** Aquí la idea es usar dfs pero con un vector de distancias, donde se guarde la distancia de cada nodo hasta la raíz del árbol. Para saber si es bipartito, se inicia una variable booleana en 'true' y en caso de encontrar un *backedge*
fijarse si la distancia de ambos nodos es par o ambos impar entonces no es bipartito (significa que dos nodos v o w están conectados entre sí). Entonces en caso de que ocurra lo anterior armo el ciclo de longitud impar. Una posible
implementación sería la siguiente:

Aquí solo hice un código que se queda con el primer ciclo que encuentra, siempre y cuando para todo v<sub>i</sub>, d<sub>out</sub>(v<sub>i</sub>) > 0.

```cpp
vector<vector<int>> aristas;
vector<int> padre;
vector<int> distancia;
vector<int> ciclo;

bool esBipartito = true;

int comienzo_ciclo = -1;
int fin_ciclo = -1;


void armarCiclo(){
    if (comienzo_ciclo >= 0) {
        int v = comienzo_ciclo;
        ciclo.push_back(v);
        while (v != fin_ciclo) {
            v = padre[v];
            ciclo.push_back(v);
        }
    }
}

void dfs(int v, int distRaiz) {
    distancia[v] = distRaiz; // guardo distancia hasta la raíz

    for (int u: aristas[v]) {
        if (padre[u] == -1) {
            padre[u] = v;
            dfs(u, distRaiz+1);
        } else if (padre[v] != u) {
            if(distancia[v]%2 == distancia[u]%2){ // si las distancias son ambas pares o impares entonces no es bipartito
                comienzo_ciclo = v;
                fin_ciclo = u;
                armarCiclo();
                esBipartito = false;
            }
        }
    }
}
```

**d)**

### Ejercicio 2

