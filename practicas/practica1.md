# Práctica 1: Técnicas Algorítmicas

## Backtracking

### Ejercicio 1

**a)** Soluciones candidatas para C = {6, 12, 6}, k = 12: 

{0,0,0},{1,0,0},{1,1,0},{1,1,1},{1,0,1},{0,1,0},{0,1,1},{0,0,1}

**b)** Soluciones válidas para C = {6, 12, 6}, k = 12: 

{1,0,1},{0,1,0}

**c)** Soluciones parciales para C = {6, 12, 6} y k = 12:

{},{0},{1},{0,0},{0,1},{1,0},{1,1},{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1}

**d)**
![im1](images/backtraking_tree.png)

**g)**
![im1](images/subset_sum.png)

**h)**
![im1](images/ej1_tree_regla_factibilidad.png)

**i)** otra regla de factibilidad sería que el algoritmo te de true cuando j = 0.

Posible implementación en C++:
```cpp
bool subset_sum(vector<int> C, int i, int j){
    if(j<0) return false; // regla de factibilidad
    if(j==0) return true; // existe sub_set que cumple
    if (i == 0) {
        return j == 0;
    } else {
        return subset_sum(C, i-1, j) or subset_sum(C, i-1, j-C[i-1]);
    }
}
```

**j)** Posible implementación en C++

```cpp
bool subset_suma_aux(const vector<int>& C, int i, int j, vector<int>& p) {
    if (j < 0) return false; // Regla de factibilidad
    if (j == 0) {
        // Imprime el subconjunto actual almacenado en el vector p
        for (int num : p) {
            cout << num << " ";
        }
        cout << endl;
        return true;
    }
    if (i == 0) return false;

    // Prueba incluir el elemento actual en el subconjunto
    p.push_back(C[i - 1]);
    bool incluido = subset_suma_aux(C, i - 1, j - C[i - 1], p);
    p.pop_back(); // Elimina el último elemento del vector p

    // Prueba no incluir el elemento actual en el subconjunto
    bool no_incluido = subset_suma_aux(C, i - 1, j, p);

    return incluido || no_incluido;
}

void subset_suma(const vector<int>& C, int k) {
    vector<int> p; // Vector para mantener el subconjunto actual
    bool result = subset_suma_aux(C, C.size(), k, p);

    if (!result) {
        cout << "No se encontró ningún subconjunto que sume " << k << endl;
    }
}
```

Se puede probar con el siguiente main:

```cpp
int main() {
    std::vector<int> C = {6, 12, 6};
    int targetSum = 12;

    subset_suma(C, targetSum);

    return 0;
}
```

### Ejercicio 2

**a)** Al ser cuadrados mágicos de orden n quiere decir que se tienen n² casillas, entonces al usar fuerza bruta se tendrían que generar (n²)! cuadrados mágicos.

**b)**
  
