SISTEMA CONTROL DE RELÉS

Jaiver Alexis Balanta Gonzalez

**_Resumen_—El objetivo de este proyecto es diseñar un sistema que permita comunicar el computador con una tarjeta de relés la cual servirá para poder controlar aparatos eléctricos que funcionen con alto voltaje se podrá conectar luces o electrodomésticos que funcionen con 110 voltios o maquinaria industrial que opere con voltajes de hasta 220 voltios.**

**Se usara una interfaz gráfica diseñada en HTML que junto al protocolo CGI transmitirá los datos ingresados por el usuario a un programa desarrollado en el lenguaje de programación C este lenguaje al ser un lenguaje de nivel medio permite el envió datos a través del puerto paralelo LPT.**

**Para que esto sea posible se aplicaran todos los conocimientos adquiridos en el curso de sistemas operativos (Seguridad, Hilos, Manejo de archivos, Dispositivos E/S).**

![](RackMultipart20200506-4-6wkfui_html_20ef0752b101c265.png)**Indice de terminos— Common Gateway Interface. (CGI), Hypertext Markup Language (HTML), MultiHilos, Relé, Common Gateway Interface. (CGI), Interfaz grafica, Manejo de Archivos, Line Print Terminal. (LPT), Dynamic Link Library (DLL)**

1.
# INTRODUCCION

# E
STE proyecto tiene como objetivo principal desarrollar un sistema de control demótico el cual podrá tener múltiples usos puede ser utilizado para controlar la iluminación de una vivienda o hasta para controlar la máquinas de una fábrica.

Este sistema está divido en 3 partes la primera es la aplicación web desarrollada con HTML, JavaScript, CSS que es la interfaz gráfica o GUI que se muestra al usuario y donde este interactúa con el resto del sistema.

_Ilustración 1. Diagrama general del Proyecto_

Luego está el controlador que recibe datos del usuario a través de CGI el controlador esta desarrollado en lenguaje C y actúa como el núcleo del sistema donde se encuentra toda las funciones fundamentales del sistema como son el manejo de archivos, y el envió de datos al dispositivo de E/S en este caso es un puerto paralelo LPT.

El software estará alojado en un servidor web el cual se podrá acceder desde cualquier lugar con acceso a internet este sistema deberá ser protegido para evitar daños al sistemas o el uso indebido permitiendo el acceso a la aplicación solo a las personas autorizadas.

Por último el hardware que se compone del puerto LPT y la tarjeta de relés de 4 canales que a su vez esta subdividida en relés, opto acopladores, diodos de germanio, resistencias, transistores

1.
# DESARROLLO

# E
L sistema se divide en tres partes principales que a su vez se subdividen en partes mas pequeñas.

  1.
## GUI

Comenzando por la GUI la cual es una página web desarrollado con HTML, CSS y JavaScript consiste en una pequeña interfaz protegida con una contraseña que se almacena en un archivo binario una vez ingrese la contraseña correcta permitirá al usuario seleccionar los relés que desea activar o desactivar, también permite hacer el cambio de contraseña y ver el historial de envió de datos al puerto paralelo.

  1.
## Servidor

![](RackMultipart20200506-4-6wkfui_html_ca53356fdafb0428.png)Luego la parte principal del sistema que se comunica con la GUI cuando el usuario envía una petición hacia el servidor esta es recibida por el Hypertext Transfer Protocol Daemon (HTTPD) es un proceso del servidor que se ejecuta en segundo plano el cual ejecuta un script creado en Lenguaje C el cual procesa los datos enviados por el usuario Estos datos son almacenados en el disco duro del servidor y se envía al dispositivo E/S.

  1.
## Dispositivo E/S

En la parte hardware se compone de el puerto LPT, relés, diodos de germanio, optoacopladores, transistores, resistencias…

Pero los componentes más importantes son el relé, el puerto paralelo y los optoacopladores

    1.
### Puerto LPT

El puerto LPT es un [paralelo](http://www.informaticamoderna.com/Electricidad_y_computadoras.htm#circ), se llama puerto paralelo porque permite el envío de datos, en conjuntos simultáneos de 8 [bits](http://www.informaticamoderna.com/Unidades_de_medida.htm), mientras que un [serial](http://www.informaticamoderna.com/Electricidad_y_computadoras.htm#circ) se dedica a enviar los datos uno detrás de otro.

El puerto de comunicación LPT se puede acceder en 3 direcciones la dirección usada en este proyecto es el registro de datos que sirve para enviar datos al puerto se comunica a esta dirección usando el numero decimal 888 o 0x378 en su forma hexadecimal.

_Tabla 1 Tipos de Registro_

| **Registro** | **LPT1** |
| --- | --- |
| Registro de Datos | 0x378 |
| Registro de Estado | 0x379 |
| Registro de Control | 0x37a |


Los pines usados para enviar datos van desde el pin 2 al pin 9 que son los pines de salida de datos

| Pines | Función |
| --- | --- |
| 1 | Strobe |
| 2 al 9 | Datos |
| 10 | Reconocimiento |
| 11 | Ocupado |
| 12 | Falta de Papel |
| 13 | Seleccionar |
| 14 | Auto Alimentación |
| 15 | Error |
| 16 | Iniciar |
| 17 | Select In |
| 18 al 25 | Conexión de tierra (GND) |

_T

Ilustración 2 Esquema del Servidor


abla 2 Pines LPT_

Para este proyecto se necesitan 4 canales por lo cual se utilizan solo 4 pines del pin 2 al pin número 5 que envían 4 bits 0 – 15 al puerto de manera simultánea.

Si se desea encender el primer relé se envía al puerto el número 1.

Si se desea encender el segundo relé se envía el número 2.

Si se desea encender el tercer relé se envía el número 4.

Si se desea encender el cuarto relé se envía el número 8.

    1.
### Relés

Otros componentes son los relés que es un dispositivo electromagnético. Funciona como un interruptor controlado por un circuito eléctrico en el que, por medio de una bobina y un electroimán, se acciona un juego de uno o varios contactos que permiten abrir o cerrar otros circuitos eléctricos independientes

![](RackMultipart20200506-4-6wkfui_html_2283c001f3b5d115.gif)

_Ilustración 3 Ejemplo de un Relé_

![](RackMultipart20200506-4-6wkfui_html_45097deaeb2bf7d5.png)

_Ilustración 4 Circuito interno del rele_

El relé se activa con la señal mandada del puerto LPT y activa el circuito de alto voltaje.

    1.
### Optoacopladores

Por último el Optoacoplador también llamado optoaislador o aislador acoplado ópticamente, es un dispositivo de emisión y recepción que funciona como un interruptor activado mediante la luz emitida por un diodo LED que satura un componente optoelectrónico, normalmente en forma de fototransistor De este modo se combinan en un solo dispositivo semiconductor, un foto emisor y un foto receptor cuya conexión entre ambos es óptica. Estos elementos se encuentran dentro de un encapsulado. Se suelen utilizar para aislar eléctricamente a dispositivos muy sensibles.

![](RackMultipart20200506-4-6wkfui_html_ddb5154b5e5bf85.gif)

_Ilustración 5 Ejemplo de un Optoacoplador_

#


1.
# CONCLUSION

El sistema realizado cumple con los objetivos propuestos ya que se aplican gran parte de los temas vistos en el curso de sistemas operativos por ejemplo permite controlar dispositivos eléctricos de alto voltaje a través de la comunicación del computador con un dispositivo E/S y almacenar datos en archivos binarios dentro del servidor estos 2 procesos se hacen de manera simultanea haciendo uso del concepto de multihilos también permite hacer conexiones al servidor aplicando técnicas de protección del sistema para reducir el riesgo de daños internos y evitar la manipulación por personas no autorizadas.

1.
# REFERENCIAS

[1] J.Pavon,&quot;CGI Aplicaciones web UCM&quot;

Disponible en internet en [https://www.fdi.ucm.es/profesor/jpavon/web/32-CGI.pdf](https://www.fdi.ucm.es/profesor/jpavon/web/32-CGI.pdf)

[2]Electrosofts,&quot; Parallel Port Programming (PART 1): with C&quot;

Disponible en internet en [http://electrosofts.com/parallel/](http://electrosofts.com/parallel/)