# 📦 push_swap - ¡La guerra de las pilas ha comenzado!

Bienvenidos a **push_swap**, el proyecto donde aprenderás a ordenar números... ¡pero con estilo y usando pilas! Sí, no estamos hablando de ordenar con simples bucles, aquí la diversión viene con dos pilas, un set limitado de operaciones, y un toque de caos bien calculado. ¿Estás listo para dominar el arte del sorting en C? 💥

## ¿Qué es push_swap?

**push_swap** es un proyecto del curso de **42 Fundación Telefónica** que te desafía a ordenar una secuencia de números utilizando únicamente un conjunto de operaciones predefinidas sobre dos pilas. El reto no solo es hacer que funcione, sino hacerlo **eficientemente**: ¡Cuantos menos movimientos, mejor!

### La misión:

1. **Recibir una lista de números enteros**.
2. **Ordenar los números** usando dos pilas: `A` (entrada) y `B` (auxiliar).
3. **Minimizar la cantidad de operaciones** para lograr la lista ordenada en la pila `A`.

¡Es simple en concepto pero brutal en ejecución! 😈

## Reglas del proyecto 📜

- Tienes **dos pilas** a tu disposición, llamadas `A` y `B`.
- Las operaciones que puedes usar son las siguientes:
  - `sa`: Intercambiar los dos primeros elementos de `A`.
  - `sb`: Intercambiar los dos primeros elementos de `B`.
  - `ss`: Intercambiar los dos primeros elementos de ambas pilas.
  - `pa`: Pasa el primer elemento de `B` a `A`.
  - `pb`: Pasa el primer elemento de `A` a `B`.
  - `ra`: Desplaza todos los elementos de `A` una posición hacia arriba.
  - `rb`: Desplaza todos los elementos de `B` una posición hacia arriba.
  - `rr`: Desplaza todos los elementos de ambas pilas una posición hacia arriba.
  - `rra`: Desplaza todos los elementos de `A` una posición hacia abajo.
  - `rrb`: Desplaza todos los elementos de `B` una posición hacia abajo.
  - `rrr`: Desplaza todos los elementos de ambas pilas una posición hacia abajo.

Tu objetivo es utilizar estas operaciones de la manera más eficiente posible para ordenar la pila `A` en orden ascendente. Y por "eficiente" no me refiero a un solo intento. Lo intentarás, fallarás, y lo intentarás de nuevo... ¡hasta que consigas la secuencia perfecta de movimientos!

## Compilación y ejecución 🚀

1. Clona el repositorio en tu máquina local:

```bash
git clone https://github.com/Gsoteldo/Cursus-42.git
```
2. Navega a la carpeta del proyecto:
```bash
cd push_swap
```

3. Compila  ejecutando:

```bash
make
```

Esto generará un archivo ejecutable llamado push_swap.

## Uso básico

Para ordenar una lista de números, simplemente ejecuta el programa pasando los números como argumentos:

```bash
./push_swap 4 67 3 87 23
```
El programa devolverá una lista de movimientos necesarios para ordenar esos números.

## Verificación del resultado

Puedes usar el programa checker (que también tendrás que implementar) para verificar si los movimientos generados por push_swap realmente ordenan la pila. Para usarlo:

1. Ejecuta push_swap con los números que quieras ordenar:

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```
2. **checker** te dirá si los movimientos fueron correctos (`OK`) o incorrectos (`KO`).

## Cosas a tener en cuenta 🔍
- **Optimización:** No basta con ordenar la lista, tienes que minimizar la cantidad de movimientos. ¡Menos es más! 
- **Límites:** Prueba tu programa con diferentes tamaños de pila. Los algoritmos que funcionan bien con pocas entradas podrían fallar estrepitosamente con entradas más grandes.
- **Gestión de memoria:** Cuidado con los malloc y free, ¡el valgrind estará vigilando!

## Cosas que aprenderás 🧠
- **Manejo avanzado de pilas:** Aprenderás a usar y manipular pilas con diversas operaciones.
- **Optimización de algoritmos:** Tu objetivo es que el programa sea rápido y eficiente en el número de movimientos.
- **Análisis de complejidad:** Descubrirás cómo el número de elementos afecta directamente al rendimiento y cómo elegir la estrategia de ordenación adecuada para cada tamaño de pila.
- **Pensamiento crítico:** Empieza a pensar en cómo dividir problemas grandes en pequeños pasos, ¡especialmente cuando tienes restricciones!

