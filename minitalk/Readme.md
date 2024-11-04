# 📡 minitalk - Comunicación de procesos sin decir "¡Oye tú!" 🥷

**minitalk** es un proyecto de la escuela 42 que pone a prueba tus habilidades en la comunicación entre procesos usando señales en C. Este proyecto busca enseñarte cómo hacer que dos programas separados se comuniquen sin tener una línea directa de conversación (como un socket o un archivo compartido), utilizando solo señales de UNIX para enviar mensajes de texto entre un cliente y un servidor.

## Descripción del proyecto

En **minitalk**, tienes que crear dos programas: un **servidor** y un **cliente**. La idea es que el cliente envíe un mensaje de texto al servidor, que este reciba el mensaje y lo muestre en pantalla. El truco es que el único medio de comunicación entre ambos programas son **señales** (`SIGUSR1` y `SIGUSR2`).

### ¿Por qué señales? 🤔

Las señales son una forma muy básica de comunicación entre procesos en sistemas UNIX. Al aprender a usarlas en este proyecto, te sumerges en las entrañas del sistema operativo, experimentando cómo los procesos pueden "hablarse" entre sí sin depender de las herramientas de red o archivos. Así, `minitalk` es una pequeña joya en el arte de la comunicación inter-proceso (IPC) básica.

## Funcionalidades 🛠️

- **Servidor**:
  - Recibe señales desde el cliente.
  - Interpreta las señales para construir el mensaje.
  - Muestra el mensaje en pantalla.

- **Cliente**:
  - Envía un mensaje al servidor (carácter por carácter) usando señales.
  - Transforma cada bit de cada carácter en una secuencia de señales (`SIGUSR1` o `SIGUSR2`) y las envía al servidor.

## Instrucciones de Compilación 🚀


Para compilar el proyecto:
1. Clona el repositorio en tu máquina local:

```bash
git clone https://github.com/Gsoteldo/Cursus-42.git
```
 
2. Navega a la carpeta del proyecto:
```bash
cd minitalk
```

3. Usa el comando `make` en la carpeta del proyecto:
```bash
make
```
Esto generará dos ejecutables: `server` y `client`.

## Ejecución

- Para iniciar el **servidor**:
```bash
./server
```
El servidor imprimirá su PID en la pantalla. Guarda este PID, ya que será necesario para que el cliente sepa a dónde enviar las señales.

- Para ejecutar el **cliente** y enviar un mensaje, ejecuta:

```bash
./client <PID_del_servidor> "Tu mensaje aquí"
```
Ejemplo:
```bash
./client 12345 "Hello, minitalk!"
```
El servidor recibirá cada carácter del mensaje como una secuencia de señales y los interpretará para mostrar el mensaje completo.

## Explicación Técnica 🧠

### Comunicación por señales

Para que el servidor reciba el mensaje del cliente, cada bit de cada carácter del mensaje se envía como una señal:
- **SIGUSR1** representa un bit `0`.
- **SIGUSR2** representa un bit `1`.

Esto significa que el cliente toma el mensaje y lo transforma en una serie de bits, que luego se envían en forma de señales. El servidor reconstruye los bits y, por ende, los caracteres y el mensaje completo.

### ¿Qué es un PID?
Un PID (Process ID) es un número único que identifica un proceso en ejecución en un sistema UNIX. En este proyecto, el cliente usa el PID del servidor para saber a qué proceso debe enviar las señales.

### Ejemplo de flujo del mensaje
1. El servidor inicia y espera señales (escuchando en un bucle infinito).
2.  El cliente envía señales con el mensaje, caracter por caracter.
3.  El servidor recibe cada señal y reconstruye los bits en caracteres.
4.  Al final, el servidor imprime el mensaje completo en pantalla.

## Desafíos del proyecto 🧗‍♂️
- **Sincronización:** Dado que las señales son asíncronas, puede ser complicado asegurarse de que el servidor está recibiendo y procesando cada bit en el orden correcto y sin perder datos.
- **Latencia:** Las señales no son tan rápidas como otros métodos de IPC, y para grandes mensajes, puede haber una ligera demora en la transmisión.
- **Control de flujo:** Deberás asegurarte de que el servidor sabe cuándo termina un mensaje, por lo que el cliente necesita enviar un "fin de mensaje" para que el servidor sepa cuándo detenerse.

## Testing y Validación 🧪
Es importante probar el proyecto en diferentes situaciones para asegurarse de que funciona correctamente:

1. **Prueba básica:** Envía un mensaje simple como "Hola" y verifica que el servidor lo muestra correctamente.
2. **Prueba de mensaje largo:** Envía un mensaje más largo y asegúrate de que el servidor lo recibe completo.
3. **Prueba de múltiples mensajes:** Envía varios mensajes seguidos para verificar que el servidor puede recibirlos correctamente.

## Cosas que aprenderás 💡
- **Manejo de señales en UNIX:** Dominarás el uso de señales para comunicación básica entre procesos.
- **Transformación de datos binarios:** Aprenderás a trabajar con bits y a enviar datos en formato binario.
- **Sincronización básica entre procesos:** Cómo manejar datos asíncronos y coordinar dos procesos que se comunican indirectamente.








