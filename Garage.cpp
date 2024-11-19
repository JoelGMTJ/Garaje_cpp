/*
Programa que maneja un almacen de autos
Creado por Joel Guadalupe Garcia Guzman A01713785
12/nov/24
*/

#include <iostream>
#include "obj_cars.h"
#include "obj_gas.h"
#include "obj_electric.h"
#include <vector>
#include <string>

using namespace std;

std::vector<Car> inventory = {};

//funcion para pausar el codigo
void pausar(){
    string linea;
    cout << "Presione algun caracter para continuar ";
    cin >> linea;
}

//funcion para agregar un objeto Car a una lista de inventario
void update_inventory(Car carToAdd){
        inventory.push_back(carToAdd);
    }

//funcion para crear un auto con todos los atributos INCOMPLETA ------------------------------------------------------------
void crear_auto(){
    cout << "Vamos a agregar un auto a al garaje" << endl;
    string brand; // marca del auto en Mayusculas
    string model; // modelo del auto en Mayusculas
    int year; // anio del modelo
    int cost; // costo en dolares
    string color; // color del auto
    int horsePower; // cantidad de caballos de fuerza
    float starRating; // estrellas sobre 5
    int seats; // cantidad de asientos
    string country; // japones - americano - aleman - britanico - italiano - coreano - chino - etc
    int mileage; // kilometros que ha recorrido el auto

    cout << "Que marca es tu auto? " << endl;
    cin >> brand;
    cout << "Que modelo es tu auto? " << endl;
    cin >> model;
    cout << "De que anio es tu auto? " << endl;
    cin >> year;
    cout << "Cual es el costo de tu auto? " << endl;
    cin >> cost;
    cout << "De que color es tu auto? " << endl;
    cin >> color;
    cout << "Cuantos caballos de fuerza tiene tu auto? " << endl;
    cin >> horsePower;
    cout << "Cuantas estrellas sobre 5 le darias de calificacion a tu auto? " << endl;
    cin >> starRating;
    cout << "Cuantos asientos tiene tu auto? " << endl;
    cin >> seats;
    cout << "De que nacionalidad es tu auto? " << endl;
    cin >> country;
    cout << "Cuantos kilometros ha recorrido tu auto? " << endl;
    cin >> mileage;

    //crear el objeto car
    //actulalizar el inventario con: update_inventory

    //terminar funcion
    //funcion para crear tu propio auto
    //Problema - no se como hacer para que se creeen autos con diferentes nombres

}

//funcion para imprimir los datos de un auto
void check_inventory(){
    cout << "Que espacio del garaje quieres ver? ";
    int index;
    cin >> index;
    inventory[index-1].print_datos();
}

//funcion que genera autos de ejemplo
void generar_ejemplos(){
    // auto generico, lo que pasa si creas un objeto sin parametros
    Car generico = Car();
    update_inventory(generico);

    // ejemplos de autos 
    Car MX5 = Car("Mazda", "Miata", 1989, 13800, "rojo", 115, 5,  2,  "japones", 30000);
    update_inventory(MX5);

    Car SF24 = Car("Ferrari", "Formula 1 SF24", 2024, 16000000, "rojo", 1000, 4.5, 1, "italiano", 8900);
    update_inventory(SF24);

    Car Tes3 = Car("Tesla", "Model 3", 2021, 400, "blanco", 400, 3, 5, "americano", 4000);
    update_inventory(Tes3);
}

//funcion que imprime todas las opciones que puedes hacer en el programa
void instrucciones(){
    cout << endl << "Presione 1 para agregar un auto" << endl;
    cout << "Presione 2 para sacar un auto a pasear" << endl;
    cout << "Presione 3 para repintar un auto" << endl;
    cout << "Presione 4 para llenar de gasolina a un auto" << endl;
    cout << "Presione 5 para ver todos los datos de un auto" << endl;
    cout << "Presione 6 para salir del programa" << endl;
    cout << "Presione 7 para revisar nuevos objetos agregados (TEMPORAL)" << endl;
}

//imprime la marca y modelo de todos los autos del inventario, regresa el Car seleccionado
Car seleccionarAuto(){
    for (int i = 0; i < inventory.size();i+=1){
        cout << "El auto " << i+1 << " es un " << inventory[i].get_brand() << " " << inventory[i].get_model() << endl;
    }
    int autoSeleccionado;
    cout << "Que auto quieres seleccionar? ";
    cin >> autoSeleccionado;
    return inventory[autoSeleccionado-1];
}

//funcion que le aumenta kilometraje a un auto y le resta gasolina
void usar_auto(){
    Car autoSeleccionado = seleccionarAuto();
    //linea que te diga cuanta gasolina tiene el auto
    int kmRecorridos;
    int litrosUsados;
    cout << "Cuantos kilometros recorriste en tu auto? ";
    cin >> kmRecorridos;
    autoSeleccionado.car_moved(kmRecorridos);
    cout << "Cuantos litros de gasolina usaste? ";
    cin >> litrosUsados;
    //hacer cuando juntes la gasolina con el auto con herencias
}

//funcion que cambia el color de un auto
void repintar_auto(){
    Car autoSeleccionado = seleccionarAuto();
    cout << "El actual color de tu auto es " << autoSeleccionado.get_color() << endl;
    cout << "Que color quieres pintar tu auto? ";
    string newPaint;
    cin >> newPaint;
    autoSeleccionado.set_color(newPaint);
    cout << "El nuevo color de tu " << autoSeleccionado.get_brand() << " " << autoSeleccionado.get_model() << " es " << autoSeleccionado.get_color();

}

//revisar los datos de algun auto
void ver_datos(){
    Car autoSeleccionado = seleccionarAuto();
    autoSeleccionado.print_datos();
}

//revisar los objetos nuevos, la gasolina y la electricidad
//ejemplos para ver algunos getters y algunos metodos
void revisar_obj_nuevos(){
    cout << "Ejemplo para el objeto de gasolina:" << endl << "-------------" << endl;
    Gas gasolinaAuto1 (60, 45);
    gasolinaAuto1.print_gas();
    cout << "El auto ha usado 15L de gasolina" << endl;
    gasolinaAuto1.gas_used(15);
    cout << "El auto ahora tiene " << gasolinaAuto1.get_gasInCar() << "L de gasolina" << endl;

    cout << "Ejemplo para el objeto de electricidad:" << endl << "-------------" << endl;
    Electricity electricidadAuto1 (60000, 50000);
    electricidadAuto1.print_electricity();
    cout << "El auto ha usado 13000Wh de electricidad" << endl;
    electricidadAuto1.electricity_used(13000);
    cout << "El auto ahora tiene " << electricidadAuto1.get_electricityInCar() << "Kw de electricidad" << endl;
}


//----Main----
int main(){ 
    cout << endl << "Bienvenido a tu almacen de autos" << endl;
    cout << "Aqui podras guardar tantos autos como quieras, revisar sus datos, tomar un auto para un paseo y muchas otras cosas";
    
    generar_ejemplos();

    int opcionPrincipal;
    do{
        cout << endl;
        switch (opcionPrincipal){
            case 1:
                cout << "Aun no tenemos esa funcion lista" << endl;
                break;
            case 2:
                usar_auto();
                break;
            case 3:
                repintar_auto();
                break;
            case 4:
                //codigo
                break;
            case 5:
                ver_datos();
                break;
            case 7:
                revisar_obj_nuevos();
                break;
        }
        pausar();

        instrucciones();
        cout << endl << "Que opcion deseas usar? ";
        cin >> opcionPrincipal;
        
    }
    while (opcionPrincipal != 6);
    return 0;   
}
