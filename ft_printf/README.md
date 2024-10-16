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

## ¿Cómo usarlo? 🚀

1. Clona el repositorio en tu máquina local:

```bash
git clone https://github.com/tu-usuario/ft_printf.git
```

