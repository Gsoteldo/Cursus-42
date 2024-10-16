# 📚 Libft - Reinventando la rueda

¡Bienvenidos a **Libft**, el proyecto donde escribirás desde cero esas funciones que ya existen... pero porque sí! 🚀

Este es el primero de muchos proyectos en **42 Fundación Telefónica**, donde se supone que el dolor es el camino a la iluminación (o a aprender C). Aquí creamos nuestra propia librería con funciones estándar de C. ¿Por qué? Porque ser programador significa hacer las cosas de la forma más difícil posible. 😅

<br>

## ¿Qué es Libft?

**Libft** es una librería que recrea varias funciones estándar de la biblioteca de C. Además, te permitirá entender cómo funcionan esas funciones a nivel interno y te hará cuestionarte por qué decidiste estudiar programación. Las funciones cubren:

- Manipulación de cadenas
- Manipulación de memoria
- Listas enlazadas
- Y otros "juguetes" que hacen más divertida la vida del programador.

<br>

## Funciones incluidas 🛠️

La librería **Libft** contiene las siguientes funciones implementadas desde cero:

### Parte 1 - Funciones Libc
Estas funciones reproducen comportamientos de funciones de la biblioteca estándar de C.

- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`
- `ft_strlen`, `ft_strdup`, `ft_strcpy`, `ft_strncpy`
- `ft_strcat`, `ft_strncat`, `ft_strlcat`
- `ft_strchr`, `ft_strrchr`
- `ft_strstr`, `ft_strnstr`, `ft_strcmp`, `ft_strncmp`
- `ft_atoi`, `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_toupper`, `ft_tolower`

<br>

### Parte 2 - Funciones adicionales
Funciones que podrían no estar en la biblioteca estándar de C, pero que son útiles para nuestros proyectos.

- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

<br>

### Parte 3 - Funciones Bonus (Listas Enlazadas)
Porque no hay nada más emocionante que trabajar con punteros.

- `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`
- `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

<br>

## Instalación y uso 🛠️

1. Clona el repositorio de **Cursus-42**:

```bash
git clone https://github.com/Gsoteldo/Cursus-42.git
```

<br>

2. Navega a la carpeta del proyecto

```bash
cd libft
```

<br>

3. Compila la librería

```bash
 make
```
Esto generará un archivo `libft.a` que podrás incluir en tus futuros proyectos.

<br>

4. Incluye la librería en tus proyectos:

```C
#include "libft.h"
```

<br>

5. Para limpiar los archivos objetos:
```bash
make clean
```
Y si quieres un make super limpio (borrando también la librería compilada):
```bash
make fclean
```
<br>

## ¿Cómo usarlo?
Digamos que necesitas usar ft_strlen (porque escribir strlen no es suficiente). Una vez que hayas incluido la librería en tu proyecto, simplemente puedes usarla así:

```C
#include "libft.h"

int main(void)
{
    char *str = "42 Madrid es increíble";
    int len = ft_strlen(str);
    printf("La longitud de la cadena es: %d\n", len);
    return (0);
}
```
<br>

## ¿Por qué hacer esto?
Además de cuestionarte tus decisiones de vida, este proyecto te ayuda a:

- Profundizar en el funcionamiento interno de las funciones estándar de C.

- Mejorar tu comprensión de la gestión de la memoria y los punteros.

- Ganar más habilidades de depuración y paciencia (la paciencia es clave aquí).
