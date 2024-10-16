# 🖨️ ft_printf - Porque imprimir nunca fue tan difícil

¡Bienvenidos al maravilloso (y a veces exasperante) mundo de **ft_printf**! 🎉

En este proyecto, el objetivo es crear tu propia versión de la función `printf` de C, porque usar la ya existente era demasiado fácil, ¿verdad? Aquí, te enfrentarás al desafío de manejar cadenas, enteros, caracteres, y todo tipo de conversiones, mientras intentas no perder la cordura en el proceso.

## ¿Qué es ft_printf?

**ft_printf** es una réplica (con algunas limitaciones) de la función `printf` de la biblioteca estándar de C. Vas a manejar diferentes tipos de datos y aprenderás a tratar con los temidos **va_list** para gestionar argumentos variables.

### Funcionalidades soportadas 🎯

El proyecto **ft_printf** te permite imprimir lo siguiente:

- **%c**: Imprime un único carácter.
- **%s**: Imprime una cadena de caracteres (o "(null)" si la cadena es `NULL`).
- **%p**: Imprime una dirección de memoria (punteros) en formato hexadecimal.
- **%d** o **%i**: Imprime números enteros con signo en base 10.
- **%u**: Imprime números enteros sin signo en base 10.
- **%x**: Imprime números en hexadecimal en minúsculas.
- **%X**: Imprime números en hexadecimal en mayúsculas.
- **%%**: Imprime el símbolo de porcentaje `%`.

<br>

## ¿Cómo usarlo? 🚀

1. Clona el repositorio en tu máquina local:

```bash
git clone https://github.com/Gsoteldo/Cursus-42.git
```
2. Navega a la carpeta del proyecto:
```bash
cd ft_printf
```

3. Compila la librería ejecutando:

```bash
make
```
Esto generaría un archivo `libftprintf.a`, que podrás incluir en tus proyectos.

4. En tu proyecto de C, incluye la librería y el archivo de cabecera de ft_printf:

```C
#include "ft_printf.h"
```
Y ahora, puedes usar `ft_printf` como si fuera el original (pero con más sufrimiento en el proceso, claro).

### Ejemplo de uso:

```C
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola, %s!\n", "mundo");
    ft_printf("Mira este número: %d\n", 42);
    ft_printf("Dirección de memoria: %p\n", &main);
    return (0);
}
```
<br>

## Instalación para usarlo en otros proyectos 🛠️

1. Compila ft_printf como una librería estática:

```bash
make
```

2. Incluye la librería en tu proyecto al compilar:

```bash
gcc -Wall -Werror -Wextra main.c -L. -lftprintf
```

<br>

## ¡OJO!⚠️

Recuerda que ft_printf no soporta algunas funcionalidades avanzadas del printf original, como:

- Precisión y anchura con el símbolo `*`.
- Los modificadores de longitud (`hh`, `h`, `l`, `ll`, etc.).

¡Pero hey! Esto no es un proyecto de la NASA (aunque se sienta igual de complicado a veces). 😅

<br>

## ¿Por qué hacer esto? 🤔

- **Paciencia**: Dominarás el arte de la paciencia (y la frustración) mientras lidias con las cadenas de formato y los tipos de datos.

- **va_arg**: Aprenderás a usar va_list para manejar argumentos variables. No te preocupes si al principio parece magia negra... lo es.

- **Impresión personalizada**: Sabrás cómo funcionan internamente las funciones de impresión y quizás, en algún universo paralelo, termines creando una versión de printf aún más poderosa (¿por qué no?).


