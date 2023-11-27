# Editor De Texto con Formato en Qt
Este repositorio aloja un editor de texto creado con Qt Creator que facilita la edición de texto con formato. Incluye características como negrita, tachado, cursiva, y más. Además, proporciona funciones de gestión de archivos que permiten guardar el texto editado en formatos HTML, TXT u ODT. Los usuarios también tienen la opción de imprimir el texto directamente desde la aplicación.

# Descripcion de su Arquitectura
Este proyecto está desarrollado en Qt Creator y utiliza CMake como sistema de construcción. La arquitectura del proyecto sigue una estructura modular que facilita el mantenimiento y la extensibilidad. A continuación, se describen los principales componentes y su interacción:
### CMake y Estructura Base del Proyecto
El archivo CMakeLists.txt en el directorio raíz define la estructura del proyecto y las dependencias. CMake facilita la construcción del proyecto en plataformas diversas.
### Logica de la Aplicacion
Agrupa y define las clases y funciones que implementan la lógica central de la aplicación mainwindow.h. las cuales luego se utilizan en el flujo de ejecucion 
### Flujo de Ejecucion
La ejecución comienza en la clase principal main.cpp, que inicializa la aplicación y carga la interfaz de usuario.
La interacción del usuario activa eventos que son manejados por las clases en el módulo de lógica de aplicación mainwindow.cpp, provocando actualizaciones en la interfaz y operaciones en el texto. Aquí se manejan las operaciones de edición de texto, el formato, y otras funcionalidades principales.
