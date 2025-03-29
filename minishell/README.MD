# 🐚 Minishell - Tu Propia Terminal desde Cero

**Minishell** es un proyecto de la escuela 42 que consiste en crear un shell minimalista similar a Bash. Este desafío pondrá a prueba tus conocimientos sobre procesos, señales, pipes y gestión de memoria en C.

## Descripción del Proyecto

Tu objetivo es implementar un intérprete de comandos que permita ejecutar programas, gestionar la entrada y salida estándar y manejar señales como un shell real.

### Características Principales

- Mostrar un **prompt interactivo**.
- **Ejecutar comandos** y manejar argumentos.
- Implementar **pipes (**`|`**)** para conectar la salida de un comando con la entrada de otro.
- Gestionar la **redirección de entrada (**`<`, `<<`**) y salida (**`>`**, **`>>`**)**.
- Manejar **variables de entorno** (`$PATH`, `$HOME`, etc).
- Implementar algunos **built-ins** (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`).
- Capturar y manejar **señales** (`CTRL+C`, `CTRL+D`, `CTRL+\`).

## Cómo Compilar 🚀

Compila el proyecto con:

```bash
# Clonar el repositorio
git clone https://github.com/tu-usuario/tu-repo.git
cd minishell

# Compilar el proyecto
make

# Ejecutar
./minishell
```

Ejemplo de uso dentro del shell:

```sh
$ echo "Hola, mundo"
Hola, mundo
$ ls -la | grep minishell
$ cat archivo.txt > salida.txt
$ exit
```

## Built-ins Implementados 📜

| Comando  | Descripción                           |
| -------- | ------------------------------------- |
| `echo`   | Imprime texto en la salida estándar.  |
| `cd`     | Cambia de directorio.                 |
| `pwd`    | Muestra el directorio actual.         |
| `export` | Define variables de entorno.          |
| `unset`  | Elimina variables de entorno.         |
| `env`    | Muestra variables de entorno activas. |
| `exit`   | Cierra la terminal.                   |

## Funcionalidades Avanzadas ⚡

- **Manejo de pipes (**`|`**)**: Permite encadenar comandos como en Bash.
- **Redirección de Entrada y Salida**:
  - `>` para redirigir salida a un archivo (sobreescribe).
  - `>>` para redirigir salida a un archivo (añade).
  - `<` para redirigir entrada desde un archivo.
  - `<<` para hacer un here doc
- **Señales**:
  - `CTRL+C` para interrumpir un proceso en ejecución.
  - `CTRL+D` para cerrar el shell.
  - `CTRL+\` para finalizar un proceso en ejecución.

## Pruebas y Debugging 🧪

Verifica memoria con `valgrind`:

Hay que ignorar los leaks de readline
```bash
@valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full ./minishell
```


## Recursos Adicionales 📚

- [Documentación de ](https://man7.org/linux/man-pages/man2/execve.2.html)[`execve`](https://man7.org/linux/man-pages/man2/execve.2.html)
- [Pipes en C](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [Señales en C](https://man7.org/linux/man-pages/man7/signal.7.html)

## Agradecimientos 🙌
Este proyecto no hubiera sido posible sin el incansable trabajo en equipo con **[pauss12](https://github.com/pauss12)**, quien soportó largas horas de debugging, SIGSEGV inesperados y noches de café infinito. ¡Gracias por la paciencia y la locura compartida! 🎉

## Autores ✒️
- **Gsoteldo** - [GitHub](https://github.com/Gsoteldo)
- **Pauss12** - [GitHub](https://github.com/pauss12)



## Contribuciones 🛠️

¡Siéntete libre de mejorar Minishell! Puedes hacer un **fork** y enviar un **pull request** con mejoras en la funcionalidad o la estructura del código.
