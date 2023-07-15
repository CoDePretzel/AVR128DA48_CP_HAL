# HAL de periféricos para el AVR128DA48

Platformio package conteniendo un HAL de periféricos para el AVR128DA48 usando el soporte de avr-libc provisto por dxcore SpenceKonde, listo para usarse con lib_deps en platformio.ini

## Estructura del proyecto
Basada en la estructura sugerida para las [Custom Libraries](https://docs.platformio.org/en/latest/librarymanager/creating.html#manifest) de Platformio

```
├── ejemplos
│   └── simple_loopback
├── include
│   └── UART.h
├── library.json

```
Los archivos dentro de `include` son todos publicos para incluirse desde la aplicación.
Aquellos con extensión `.h` y `.c` son C puro, así como los  `.hpp` y `.cpp` son basados en C++.

NOTA: Si incluyen cabeceras C en un programa en C++ es importante poner la guarda
```
ºextern "C"
{
#include ...
}
```

## Pre-requisitos

- Platformio IDE / Home (3.4.4+) o Platformio CLI / Core (6.1.9+)

## Configuración y ejecución
### Crear un proyecto nuevo
#### Platformio IDE / Home
1. Abrir Platformio IDE
1. Crear un nuevo proyecto para el board AVR128DA48 con arduino framework (No se usa la API de arduino, pero si el toolchain que provee soporte a AVR-GCC y avr-libc)
#### Platformio CLI / Core
1. Crear un directorio que contendrá el proyecto
1. Moverse a la raiz de dicho directorio
1. Crear un nuevo proyecto vacio
```shell
pio init .
```
### Configurar el proyecto

1. Abrir el archivo `platformio.ini` y agregar
    1. `framework = arduino`
    1. `board = curiosity_nano_da`
    1. `lib_deps=https://github.com/CoDePretzel/AVR128DA48_CP_HAL`
1. Asegurarse que la plataforma sea `platform = atmelmegaavr`

 
## Ejecutar los ejemplos
Los ejemplos provistos son una forma de probar ciertas funciones disponibles en el HAL desde una aplicación que incluya este `library`.

1. Moverse al directorio del ejemplo en cuestión
1. Compilar el proyecto con  `pio run` o con la opción de compilar en el IDE
1. Programar el proyecto en el dispositivo con `pio run --target upload` o con la opción upload en el IDE

La descripción del objetivo de ese pequeño programa, está escrita en los comentarios del archivo `main.cpp` de cada ejemplo