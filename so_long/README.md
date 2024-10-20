# 🕹️ so_long - Un pequeño juego para un gran desafío

¡Bienvenidos a **so_long**! 🌍 Un proyecto donde podrás crear tu propio juego en 2D usando gráficos mínimos pero con una jugabilidad muy entretenida. Tu objetivo es mover a tu personaje por un mapa, recoger objetos y llegar a la salida, todo mientras navegas por las complejidades de la programación en C. ¿Fácil? Puede que no tanto... 😅

## ¿Qué es so_long?

**so_long** es un proyecto de **42 Fundación Telefónica** donde debes crear un juego sencillo en el que controlas a un personaje a través de un laberinto. El objetivo es recolectar todos los objetos y llegar a la salida evitando posibles obstáculos.

### ¿Qué debes implementar?

- **Movimiento del personaje**: Tu jugador debe poder moverse arriba, abajo, izquierda y derecha con las teclas de dirección.
- **Objetos coleccionables**: Coloca objetos por el mapa que el jugador deberá recoger antes de poder escapar.
- **Una salida**: Después de recoger todos los objetos, el jugador debe poder llegar a una salida que lo llevará a la victoria (¡o a otro nivel, si te animas a implementarlo!).
- **Mapas**: El juego debe leer el mapa desde un archivo `.ber` en formato específico y utilizar una ventana gráfica mínima.
- **Gráficos básicos**: Utilizarás la biblioteca **MiniLibX** para crear gráficos 2D simples.

## Requisitos del proyecto
### Funcionalidades mínimas:
1. **Movimiento**: El jugador debe moverse con las teclas de dirección. Cada movimiento debe actualizar la ventana del juego.
2. **Coleccionables**: El jugador no podrá llegar a la salida hasta que recoja todos los objetos.
3. **Mapa válido**: El mapa debe estar completamente rodeado por paredes (`1`) y ser rectangular. El archivo debe ser un mapa válido en formato `.ber`.
4. **Gráficos con MiniLibX**: Debes utilizar la librería MiniLibX para manejar la ventana gráfica.
5. **Contador de movimientos**: El número de movimientos debe mostrarse en la ventana o la consola.

### Archivos y elementos básicos del mapa:
El mapa se cargará desde un archivo .ber y debe seguir el siguiente formato:

- **1**: Representa una pared.
- **0**: Representa un espacio vacío.
- **C**: Un coleccionable.
- **E**: La salida.
- **P**: El punto de inicio del jugador.

Ejemplo de archivo de mapa `.ber`:

```
111111
1000C1
10P0E1
111111
```

Este mapa tiene un personaje (`P`), un coleccionable (`C`), y una salida (`E`), rodeado por paredes (`1`).

## ¿Qué es MiniLibX? 🖼️

**MiniLibX** es una pequeña biblioteca gráfica desarrollada por 42 para facilitar la creación de ventanas, manejar imágenes y captar eventos del teclado y ratón. Te permite crear gráficos 2D de manera sencilla en tus proyectos.

Para instalar MiniLibX en tu entorno local:

```bash
git clone https://github.com/42Paris/minilibx-linux.git
```
Compila la biblioteca con make y luego inclúyela en tu programa usando las opciones adecuadas de gcc:

```bash
gcc -Wall -Werror -Wextra -Lmlx -lmlx -lXext -lX11 -lm -lbsd (archivos .c) -o so_long
```

## Cómo funciona el juego 🎮

1. **Movimiento del personaje**: El jugador debe poder moverse usando las teclas de dirección (`WASD` o las flechas) y debe poder interactuar con el mapa. Cada movimiento debe actualizarse en la ventana y contar el número de pasos realizados. 

2. **Recolección de objetos**: Los objetos coleccionables (`C`) deben desaparecer cuando el jugador pase por encima de ellos.
 
3. **Salida**: La salida del nivel (`E`) solo estará disponible una vez que el jugador haya recolectado todos los objetos.
  
4. **Fin del juego**: Cuando el jugador llega a la salida, ¡el juego termina! Puedes imprimir un mensaje de victoria o cerrar la ventana.

### Controles del juego:
- **W** o ↑: Mover hacia arriba.
- **A** o ←: Mover hacia la izquierda.
- **S** o ↓: Mover hacia abajo.
- **D** o →: Mover hacia la derecha.

### Cómo validar tu mapa 📏
Es importante que el mapa sea rectangular, esté rodeado de paredes y que contenga al menos un jugador (`P`), una salida (`E`), y algún coleccionable (`C`). Puedes hacer esto manualmente o crear un script para validar la estructura del archivo `.ber`.

## Errores comunes y cómo evitarlos 💥

- **Segfaults**: Asegúrate de que estás controlando bien el acceso a memoria, especialmente cuando manipules las matrices que representan el mapa.
- **Mapas inválidos**: Valida siempre que el archivo `.ber` sea correcto antes de cargarlo en tu juego.
- **Movimiento incorrecto**: Revisa bien las condiciones para moverte solo en espacios vacíos (`0`), y no atravesar paredes (`1`).

## ¿Qué he aprendido con este proyecto? 📚

- **Gestión de gráficos en 2D** usando MiniLibX.
- **Interacción con el teclado** y manejo de eventos en tiempo real.
- **Manipulación de archivos y mapas**, gestionando diferentes formatos de datos.
- **Optimización de código en C**, evitando fugas de memoria y mejorando el rendimiento gráfico.
- ¡Y cómo crear un pequeño juego divertido desde cero!





