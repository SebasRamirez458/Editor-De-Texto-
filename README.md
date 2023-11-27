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
### Interfaz de Usuario (UI)
Contiene las clases y archivos relacionados con la interfaz gráfica de usuario. Las ventanas, widgets y elementos visuales se gestionan en este módulo.

## Explicacion de funciones de Edicion
### on_Negrita_clicked()
esta funcion aplica formato bold o negrilla al texto que seleccione el usuario dentro del cuadro de texto de la aplicación la cual no mamneja parametros de entrada pero si realiza proceso de seleccion de texto 
### on_Cursiva_clicked()
Alterna el estado de cursiva en el texto seleccionado dentro del QTextEdit al hacer clic en el botón correspondiente, cambiando el formato y estableciendo el foco en el QTextEdit.
### on_Subrrayada_clicked()
Similar a la función de cursiva, activa o desactiva el subrayado en el texto seleccionado del QTextEdit al hacer clic en el botón correspondiente, aplicando el formato y estableciendo el foco.
### on_Tachado_clicked()
Cambia el estado de tachado del texto seleccionado en el QTextEdit al hacer clic en el botón correspondiente, actualizando el formato y estableciendo el foco en el QTextEdit.
### on_Size_valueChanged(int arg1)
ajusta dinámicamente el tamaño de la fuente en el área de edición de texto (textEdit). Al recibir un nuevo valor (arg1), actualiza el formato de carácter para reflejar el tamaño de fuente seleccionado. Esta función permite a los usuarios cambiar el tamaño de la fuente en tiempo real, mejorando la experiencia de edición.
### on_Centro_clicked()
Centra el texto seleccionado en el QTextEdit al hacer clic en el botón correspondiente, ajustando el formato de bloque y estableciendo el foco.
### on_Izquierda_clicked()
Alinea a la izquierda el texto seleccionado en el QTextEdit al hacer clic en el botón correspondiente, configurando el formato de bloque y estableciendo el foco.
### on_Derecha_clicked()
Alinea a la derecha el texto seleccionado en el QTextEdit al hacer clic en el botón correspondiente, aplicando el formato de bloque y estableciendo el foco.
### on_fontComboBox_currentFontChanged(const QFont &f)
Cambia la fuente del texto seleccionado en el QTextEdit según la selección en un QComboBox, actualizando el formato y estableciendo el foco.
### on_CambiarColor_clicked()
permite cambiar el color de la fuente del texto seleccionado en el QTextEdit. Al hacer clic en el botón correspondiente, se abre un cuadro de diálogo de selección de color, permitiendo al usuario elegir un nuevo color. Si se selecciona un color válido, la función actualiza el formato de carácter del texto, establece el nuevo color y coloca el foco en el QTextEdit.
### on_ColorDeFondo_clicked()
permite cambiar el color de fondo del texto seleccionado en el QTextEdit. Al hacer clic en el botón correspondiente, se abre un cuadro de diálogo de selección de color, lo que permite al usuario elegir un nuevo color de fondo. Si se selecciona un color válido, la función actualiza el formato de carácter del texto, establece el nuevo color de fondo y coloca el foco en el QTextEdit.

## Explicacion de Funciones de Manejo de Archivos (Menu)
### on_actionAbrir_triggered()
permite al usuario abrir un archivo de texto(txt), un archivo de hipertexto(HTML) o un archivo OpenDocument(ODT). Al activar esta acción desde la interfaz, se muestra un cuadro de diálogo para seleccionar el archivo deseado. Después de seleccionar y confirmar el archivo, la función carga su contenido en el QTextEdit y actualiza la información del archivo actual, incluyendo la ruta en la interfaz.
### on_actionGuardar_triggered()
permite al usuario guardar el contenido actual del editor de texto en un archivo. Se utiliza un cuadro de diálogo para especificar la ubicación y nombre del archivo. La función guarda el texto en el formato correspondiente según la extensión del archivo seleccionado (PDF, HTML, TXT, ODT).
### on_actionEliminar_triggered()
elimina el archivo actualmente abierto. Al activar esta acción desde la interfaz, la función intenta abrir el archivo y, si tiene éxito, lo elimina. Si hay algún problema al intentar eliminar el archivo, se muestra una advertencia correspondiente.
### on_actionCerrar_triggered()
cierra la ventana de ejecucion del programa 
### on_actionImprimir_triggered()
abre un cuadro de diálogo de impresión, permitiendo al usuario seleccionar una impresora y ajustar las configuraciones de impresión. Si se confirma la impresión, la función imprime el contenido del QTextEdit en la impresora seleccionada.
### on_ArchivoPDF_triggered()
permite al usuario exportar el contenido actual del editor de texto como un archivo PDF. Al activar esta acción desde la interfaz, se muestra un cuadro de diálogo para especificar la ubicación y el nombre del archivo PDF. La función guarda el texto en formato PDF utilizando la configuración proporcionada.
### on_ArchivoHTML_triggered()
permite al usuario exportar el contenido actual del editor de texto como un archivo HTML. Al activar esta acción desde la interfaz, se muestra un cuadro de diálogo para especificar la ubicación y el nombre del archivo HTML. La función guarda el texto en formato HTML utilizando la configuración proporcionada.
### on_ArchivoTXT_triggered()
permite al usuario exportar el contenido actual del editor de texto como un archivo de texto (.txt). Al activar esta acción desde la interfaz, se muestra un cuadro de diálogo para especificar la ubicación y el nombre del archivo de texto. La función guarda el texto en formato de texto plano utilizando la configuración proporcionada.
### on_ArchivoODT_triggered()
permite al usuario exportar el contenido actual del editor de texto como un archivo ODT (Open Document Text). Al activar esta acción desde la interfaz, se muestra un cuadro de diálogo para especificar la ubicación y el nombre del archivo ODT. La función guarda el texto en formato HTML, adecuado para documentos ODT, utilizando la configuración proporcionada.

## Manual Tecnico
Una vez compilada y teniendo la aplicacion abierta podemos ver un menu en la parte superior izquierda el cual se despliega y podermos ver las opciones de manejo de archivos como "guardar como" el cual permite guardar el documento que el usuario edito como (TXT,ODT,HTML,PDF) al igual que las opciones de abrir, guardar cambios, Imprimir, eliminar y cerrar, todas las anteriores siendo funciones relacionadas con el manejo de el archivo del usuario.
En el centro de la aplicacion tenemos un cuadro de texto en el cual el usuario podra ingresar  el texto de desee teniendo las opciones de edicion en los botones superiores al cuadro de texto los cuales son: Negrilla, Cursiva, Tachado, Color de Fondo, subrrayado, Color, tamaño, fuente, alinear centro, alinear izquierda y alinear derecha, todas estas funciones o botones de la aplicacion son las que permiten la edicion del texto para aplicar dicha edicion se tiene que seleccionar con el cursor el fragmento de texto al cual se le va a aplicar el cambio o en caso de que quiera que el cambio se aplique para texto posterior solo es necesario dar click en el respectivo boton que desee

# Hecho Por
UNIVERSIDAD TECNOLOGICA DE PEREIRA\n
Ingenieria en Sistemas y Computacion
Facultad de Ingenierias
Programacion II
ing(c):Sebastian Ramirez Valencia 
ing(c):Andres Camilo Ulloa

# Contacto
correo: sebastian.ramirez5@utp.edu.co
correo: andres.ulloa@utp.Edu.co



