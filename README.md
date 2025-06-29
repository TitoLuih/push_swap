# push_swap

## 📄 Descripción

**push_swap** es un proyecto del campus 42 cuyo objetivo es ordenar una pila de enteros usando un conjunto limitado de operaciones, implementando y optimizando un algoritmo de ordenación. El proyecto consiste en dos programas:

- **checker**: lee una secuencia de operaciones y comprueba si la pila queda ordenada correctamente.
- **push_swap**: genera la secuencia de operaciones para ordenar la pila.

## 🚀 Objetivo

Ordenar la pila **A** con el menor número posible de operaciones, usando exclusivamente un conjunto restringido de instrucciones:

- **sa**: intercambia los dos primeros elementos de A.
- **sb**: intercambia los dos primeros elementos de B.
- **ss**: sa y sb al mismo tiempo.
- **pa**: mueve el primer elemento de B a A.
- **pb**: mueve el primer elemento de A a B.
- **ra**: rota A hacia arriba.
- **rb**: rota B hacia arriba.
- **rr**: ra y rb al mismo tiempo.
- **rra**: rota A hacia abajo.
- **rrb**: rota B hacia abajo.
- **rrr**: rra y rrb al mismo tiempo.

## 💡 Estrategia

El reto está en diseñar un algoritmo eficiente que genere la menor cantidad de movimientos posibles. Algunas aproximaciones incluyen:

- Ordenación por inserción para números pequeños.
- Algoritmos tipo quicksort adaptados para el conjunto limitado de instrucciones.
- Chunking (dividir la pila en grupos o bloques).

## ⚙️ Compilación

```bash
make
```

Esto generará el ejecutable `push_swap`.

## 🏃‍♂️ Ejecución

```bash
./push_swap [números]
```

Ejemplo:

```bash
./push_swap 3 2 1
```

Esto imprimirá en stdout la secuencia de operaciones necesarias para ordenar la pila.

### Checker (opcional)

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG
```

El checker imprimirá `OK` si la pila queda ordenada o `KO` en caso contrario.

## 🧪 Tests

Puedes probar la eficiencia contando el número de operaciones:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```
