# 🧵 Get Next Line - El arte de leer línea por línea... ¡sin perder la paciencia!

Bienvenidos a **get_next_line**, el proyecto donde aprenderás a leer un archivo **línea por línea** y a enfrentarte a las profundidades de la gestión de memoria en C. Sí, suena sencillo, pero pronto descubrirás que no lo es tanto. 💀

Este es otro desafío del curso de **42 Fundación Telefónica** y, aunque pueda parecer una función trivial, seguro que te hará rascarte la cabeza más de una vez.

## ¿Qué es get_next_line?

**get_next_line** es una función en C que, dado un **file descriptor**, devuelve la **próxima línea** que lees de ese archivo. No importa si es de un archivo, la entrada estándar o incluso una tubería: tu trabajo es hacer que todo esto funcione sin que el programa explote (con suerte).

### Funcionalidades:

- **Lectura línea por línea** de cualquier archivo o entrada estándar.
- Debes manejar archivos de cualquier tamaño sin quedarte sin memoria (buena suerte con eso).
- Soporte para cualquier tamaño de **BUFFER** (una constante que puedes definir tú mismo, porque ¿por qué conformarse con uno estándar?).

### Prototipo de la función:

```c
char  *get_next_line(int fd);
```

- `fd`: El file descriptor del archivo que quieres leer.

## ¿Qué es un File Descriptor (fd)? 🧐
Un File Descriptor (FD) es simplemente un número entero que el sistema operativo utiliza para referirse a archivos o 
recursos abiertos (como sockets, entradas o salidas estándar). Cada vez que abres un archivo en C, el sistema operativo 
te asigna un fd para identificar ese archivo en tus operaciones de lectura, escritura, etc.

### Los File Descriptors estándar:

`0`: Entrada estándar (stdin) – donde tu programa escucha, normalmente, el teclado.
`1`: Salida estándar (stdout) – donde tu programa escribe su salida, normalmente la consola.
`2`: Error estándar (stderr) – donde tu programa puede escribir mensajes de error.

Por ejemplo, cuando abres un archivo usando open(), obtienes un fd:

```c
int fd = open("archivo.txt", O_RDONLY);
```

Aquí, el fd será un número que representa el archivo archivo.txt. Luego puedes usar este fd con funciones como read(), write(), y, por supuesto, get_next_line(), para leer el contenido del archivo.

En el caso de get_next_line, el fd te indica qué archivo o recurso estás leyendo línea por línea. No importa si es un archivo de texto, la entrada estándar o un socket, siempre que puedas obtener un file descriptor, puedes usarlo con get_next_line para leerlo línea a línea.

Ejemplo de uso de fd en get_next_line:

## Cómo funciona (o cómo debería funcionar) 🤔

1. Lectura por bloques: La función utiliza un tamaño de buffer que defines tú mismo para leer el archivo en trozos, y con esos trozos vas montando las líneas.

2. Concatenación inteligente: Cada vez que lees un trozo, debes verificar si contiene un salto de línea (\n). Si es así, cortas y devuelves la línea; si no, sigues leyendo hasta que encuentres uno o llegues al final del archivo.

3. Control de memoria: Te enfrentarás al desafío de gestionar la memoria correctamente para no tener fugas (y el valgrind no te odiará tanto). Porque, sí, el peor enemigo aquí será el famoso heap y su mejor amigo, el malloc.

