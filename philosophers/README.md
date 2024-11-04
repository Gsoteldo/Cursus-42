# 🍝 Philosopher - El banquete que pone a prueba tu paciencia

**Philosopher** es un proyecto de la escuela 42 donde debes lidiar con un problema clásico de la informática: **el problema de los filósofos comensales**. Este proyecto explora conceptos fundamentales en concurrencia y sincronización de hilos (threads), desafiándote a evitar condiciones de carrera y evitar que los filósofos mueran de hambre. 

## Descripción del Proyecto

Imagina a cinco filósofos sentados en una mesa redonda con un plato de espaguetis en el centro. Cada filósofo pasa el tiempo **pensando**, **comiendo** o **durmiendo**. Para comer, cada filósofo necesita dos tenedores (uno a la izquierda y otro a la derecha). Dado que hay solo cinco tenedores y cinco filósofos, esto puede llevar a problemas de **bloqueo** y **interbloqueo** (deadlock). Tu misión es crear un programa que permita que los filósofos coman sin entrar en un bloqueo eterno o morir de hambre. 

### Reglas del Proyecto 📜

1. **Filósofos**:
   - Cada filósofo tiene tres estados: pensando, comiendo y durmiendo.
   - Para comer, un filósofo debe tomar los dos tenedores a su lado (simulados con recursos compartidos en el código).

2. **Objetivos**:
   - Evitar que los filósofos se mueran de hambre.
   - Evitar condiciones de carrera y bloqueos entre los filósofos.

## Implementación en C 🧵

Este proyecto debe ser desarrollado en **C** y se centra en la creación y sincronización de **hilos (threads)** y el uso de **mutexes** para manejar el acceso a los tenedores.

### Filosofía (nunca mejor dicho) del código

- Los filósofos y los tenedores serán modelados como hilos y recursos compartidos.
- Cada filósofo representa un hilo separado que intentará realizar sus tres acciones principales (pensar, comer, dormir) en un ciclo infinito.
- Para manejar los tenedores y evitar conflictos, usaremos **mutexes** que controlarán el acceso de los filósofos a los recursos.

## Compilación y Ejecución 🚀

1. Clona el repositorio en tu máquina local:

```bash
git clone https://github.com/Gsoteldo/Cursus-42.git
```
 
2. Navega a la carpeta del proyecto:
```bash
cd philosophers/philo
```

3. Usa el comando `make` en la carpeta del proyecto:
```bash
make
```

Esto generará un ejecutable llamado `philo`.

## Uso del ejecutable
Ejecuta el programa con los siguientes argumentos:
```bash
./philo <num_filosofos> <tiempo_para_morir> <tiempo_para_comer> <tiempo_para_dormir> [<num_de_comidas>]
```

- `<num_filosofos>`: Número de filósofos y tenedores en la mesa.
- `<tiempo_para_morir>`: Tiempo máximo (en milisegundos) que un filósofo puede pasar sin comer antes de morir.
- `<tiempo_para_comer>`: Tiempo que un filósofo tarda en comer.
- `<tiempo_para_dormir>`: Tiempo que un filósofo tarda en dormir.
- `[<num_de_comidas>]` (opcional): Número de veces que cada filósofo debe comer antes de finalizar la simulación.

Ejemplo:
```bash
./philo 5 800 200 200
```
Este comando lanza una simulación con cinco filósofos y sus respectivos tiempos para cada acción.

## Cuidado con el interbloqueo 🔒
El problema de los filósofos cenando es conocido por su tendencia a crear deadlocks. Para evitarlos, puedes implementar varias estrategias, como:

- Evitar que todos los filósofos intenten comer al mismo tiempo.
- Permitir que un filósofo tome solo un tenedor si ambos están disponibles.
- Utilizar una jerarquía para la toma de recursos, por ejemplo, ordenando los tenedores o dejando que solo los filósofos pares tomen primero el tenedor izquierdo, mientras que los impares toman el derecho.

## Sincronización de Hilos 🧵
### Creación de Hilos
Cada filósofo se implementa como un hilo separado, creado con la función `pthread_create()`. Estos hilos ejecutan el ciclo de vida de cada filósofo (pensar, comer, dormir) hasta que alcanzan el número de comidas especificado o hasta que un filósofo muere.

### Mutexes para evitar condiciones de carrera
Para evitar que dos filósofos tomen el mismo tenedor a la vez, usamos mutexes en cada tenedor. Antes de comer, un filósofo debe adquirir el mutex de ambos tenedores, liberándolos una vez ha terminado de comer. Esta estrategia ayuda a evitar conflictos y a sincronizar el acceso a los recursos.

### Ejemplo de Ciclo de Vida del Filósofo
1. **Pensar:** El filósofo reflexiona sobre el sentido de la vida (¡y sobre espaguetis!).
2. **Intentar comer:**
Toma el tenedor izquierdo (bloquea el mutex).
Toma el tenedor derecho (bloquea el mutex).
3. **Comer:** Una vez que tiene ambos tenedores, el filósofo come por un tiempo determinado.
4. **Dormir:** Tras comer, el filósofo suelta ambos tenedores y duerme un rato antes de repetir el ciclo.

## Cosas que aprenderás 🧠
- **Programación concurrente:** La implementación de hilos y la sincronización con mutexes es esencial para trabajar con recursos compartidos.
- **Resolución de problemas de sincronización:** Aprenderás a evitar el deadlock y el starvation, problemas comunes en concurrencia.
- **Control de tiempo y ciclos de vida:** La gestión de tiempos en ciclos de vida de hilos te enseñará a manejar temporizadores y delays.
- **Manejo de errores y depuración:** Al trabajar con hilos y mutexes, las fugas de memoria y errores de sincronización son comunes, y aprenderás a detectarlos y corregirlos.

## Estrategias de Optimización 🔧
- **Revisión constante de condiciones de muerte:** Configura el código para que revise constantemente si un filósofo ha pasado su límite de tiempo sin comer.
- **Reasignación de tenedores de manera ordenada:** Evita que todos los filósofos tomen los tenedores al mismo tiempo y organiza el orden en el que toman los recursos para minimizar conflictos.




