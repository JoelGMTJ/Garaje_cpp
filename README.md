Proyecto en C++ para la clase Pensamiento computacional orientado a objetos
Profesor Erik Sánchez 
Estudiante Joel García Guzmán

# Garaje de autos

El proyecto trata sobre un almacén de autos los cuales están catalogados con varias categorías
tales como su marca y modelo, su año de producción, su precio inicial, color, millaje recorrido
entre otras cosas.
En el programa puedes ver todos los carros que tienes, ver los detalles de cada uno, usarlo y aumentarle 
el millaje y modificarle la gasolina o la bateria segun sea el caso

### Uso de objetos 

Tiene los objetos:
Car - Nos sirve para crear las caracteristicas de un auto, es el padre de 2 clases hijos

Gas - Hereda las caracteristicas de Car y le agrega la capacidad del tanque del auto y la cantidad de gasolina que tiene actualmente

Electricity - Clase para los autos electricos, hereda de Car y agrega capacidad de la bateria y el porcentaje de carga

Storage - Almacena una lista de todos los autos electricos y de combustible, de aqui accedes a todas las opciones del programa
Todos los autos Gas y Electricity se le agregan a storage por medio de los vectores

