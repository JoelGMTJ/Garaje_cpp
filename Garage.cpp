/*
Programa que maneja un almacen de autos
Creado por Joel Guadalupe Garcia Guzman A01713785
12/nov/24
*/

#include <iostream>
#include "obj_cars.h"
#include "obj_fuel.h"
#include <vector>

using namespace std;

std::vector<Car> inventory = {};

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
    string motor; // 1 - combustible, 2 - hibrido, 3 - electrico
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
    cout << "Que tipo de motor tiene tu auto? " << endl << "(escribe 1 si tiene de gasolina, 2 si tiene hibrido, y 3 si tiene electrico)";
    cin >> motor;
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
    Fuel genericoF = Fuel();
    update_inventory(generico);

    // ejemplos de autos 
    Fuel MX5F = Fuel("gasolina", 45, 45);
    Car MX5 = Car("Mazda", "Miata", 1989, 13800, "rojo", 115, "1", 5,  2,  "japones", 30000);
    update_inventory(MX5);

    Fuel SF24F = Fuel("mezcla de combustible", 145, 145);
    Car SF24 = Car("Ferrari", "Formula 1 SF24", 2024, 16000000, "rojo", 1000, "2", 4.5, 1, "italiano", 8900);
    update_inventory(SF24);

    Fuel Tes3F = Fuel("electricidad", 57, 45);
    Car Tes3 = Car("Tesla", "Model 3", 2021, 400, "blanco", 400, "3", 3, 5, "americano", 4000);
    update_inventory(Tes3);
}

//funcion que imprime todas las opciones que puedes hacer en el programa
void instrucciones(){
    cout << endl << "Presione 1 para ver las instrucciones" << endl;
    cout << "Presione 2 para agregar un auto" << endl;
    cout << "Presione 3 para sacar un auto a pasear" << endl;
    cout << "Presione 4 para repintar un auto" << endl;
    cout << "Presione 5 para llenar de gasolina a un auto" << endl;
    cout << "Presione 6 para revisar algun dato de uno de los autos" << endl;
    cout << "Presione 7 para salir del programa" << endl;
}

//imprime la marca y modelo de todos los autos del inventario
void imprimirInventario(){
    for (int i = 0; inventory.size();i+=1){
        cout << "El auto " << i+1 << " es un " << inventory[i].get_brand() << " " << inventory[i].get_model() << endl;
    }
}

//funcion que le aumenta kilometraje a un auto y le resta gasolina
void usar_auto(){
    imprimirInventario();
    int numDeAuto;
    cout << "Que numero de auto quieres usar? " << endl;
    //por que esto no funciona ------------------------------------------------------------------------------------------------
    cin >> numDeAuto;
    cout << "Seleccionaste tu " << inventory[numDeAuto+1].get_brand() << " " << inventory[numDeAuto+1].get_model() << endl;
}

//----Main----
int main(){ 
    cout << endl << "Bienvenido a tu almacén de autos" << endl;
    cout << "Aqui podras guardar tantos autos como quieras, revisar sus datos, tomar un auto para un paseo y muchas otras cosas" << endl;
    
    generar_ejemplos();

    int opcionPrincipal = 1;
    while (opcionPrincipal != 7){
        cout << endl;
        if (opcionPrincipal ==1){
            instrucciones();
        }
        else if (opcionPrincipal == 2){
            cout << "Aun no tenemos esa funcion lista" << endl;
        }
        else if (opcionPrincipal == 3){
            usar_auto();
        }

        cout << endl << "Que opcion deseas usar? ";
        cin >> opcionPrincipal;
    }
    return 0;   
}
