/*
Programa que maneja un almacen de autos
Creado por Joel Guadalupe Garcia Guzman A01713785
24/nov/24
*/

#include <iostream>
#include "obj_cars.h"
#include "obj_gas.h"
#include "obj_electric.h"
#include "obj_almacen.h"
#include <string>

using namespace std;

Storage storage;

//funcion para pausar el codigo
void pause(){
    string linea;
    cout << "Presione algun caracter para continuar ";
    cin >> linea;
}

//funcion para crear un auto con todos los atributos INCOMPLETA ------------------------------------------------------------
void create_car(){
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

//fff
Car select_car(){
    vector<Car> inventory = storage.get_AllCarList();
    for (int i = 0; i < inventory.size();i+=1){
        cout << "El auto " << i+1 << " es un " << inventory[i].get_brand() << " " << inventory[i].get_model() << endl;
    }
    int autoSeleccionado;
    cout << "Que auto quieres seleccionar? ";
    cin >> autoSeleccionado;
    return inventory[autoSeleccionado-1];
}
//funcion para imprimir los datos de un auto
void check_inventory(){
    //carros de combustible
    vector<Gas> gas_cars = storage.get_gasList();

    //carros electricos
    vector<Electricity> electricity_cars = storage.get_electricityList();

    for (int i = 0; i < gas_cars.size();i+=1){
        cout << "El auto de combustible " << i+1 << " es un " << gas_cars[i].get_brand() << " " << gas_cars[i].get_model() << endl;
    }
    for (int i = 0; i < electricity_cars.size();i+=1){
        cout << "El auto electrico " << i+1 << " es un " << electricity_cars[i].get_brand() << " " << electricity_cars[i].get_model() << endl;
    }
}

//funcion que genera autos de ejemplo
void create_examples(){
    // auto generico, lo que pasa si creas un objeto sin parametros
    Gas generico = Gas();
    storage.add_gas(generico, generico);

    // ejemplos de autos 
    Gas MX5 = Gas(60, 45, "Mazda", "Miata", 1989, 13800, "rojo", 115, 5,  2,  "japones", 30000);
    storage.add_gas(MX5, MX5);

    Gas SF24 = Gas(145, 98, "Ferrari", "Formula 1 SF24", 2024, 16000000, "rojo", 1000, 4.5, 1, "italiano", 8900);
    storage.add_gas(SF24, SF24);

    Electricity Tes3 = Electricity(60000, 50000, "Tesla", "Model 3", 2021, 400, "blanco", 400, 3, 5, "americano", 4000);
    storage.add_electricity(Tes3, Tes3);
}

//funcion que imprime todas las opciones que puedes hacer en el programa
void instructions(){
    cout << endl << "Presione 1 para agregar un auto" << endl;
    cout << "Presione 2 para sacar un auto a pasear" << endl;
    cout << "Presione 3 para repintar un auto" << endl;
    cout << "Presione 4 para llenar de gasolina a un auto" << endl;
    cout << "Presione 5 para ver todos los datos de un auto" << endl;
    cout << "Presione 6 para salir del programa" << endl;
}

Electricity select_electricity(){

}

//funcion que le aumenta kilometraje a un auto y le resta gasolina
void use_car(){
    Car selectedCar = select_car();
    //linea que te diga cuanta gasolina tiene el auto
    int kmRecorridos;
    int litrosUsados;
    cout << "Cuantos kilometros recorriste en tu auto? ";
    cin >> kmRecorridos;
    selectedCar.car_moved(kmRecorridos);
}

//funcion que cambia el color de un auto
void repaint_car(){
    Car selectedCar = select_car();
    cout << "El actual color de tu auto es " << selectedCar.get_color() << endl;
    cout << "Que color quieres pintar tu auto? ";
    string newPaint;
    cin >> newPaint;
    selectedCar.set_color(newPaint);
    cout << "El nuevo color de tu " << selectedCar.get_brand() << " " << selectedCar.get_model() << " es " << selectedCar.get_color() << endl;

}

//revisar los datos de algun auto
void check_info(){
    Car selectedCar = select_car();
    selectedCar.print_info();
}


//----Main----
int main(){ 
    cout << endl << "Bienvenido a tu almacen de autos" << endl;
    cout << "Aqui podras guardar tantos autos como quieras, revisar sus datos, tomar un auto para un paseo y muchas otras cosas";
    
    create_examples();

    int mainOption;
    do{
        cout << endl;
        switch (mainOption){
            case 1:
                cout << "Aun no tenemos esa funcion lista" << endl;
                break;
            case 2:
                use_car();
                break;
            case 3:
                repaint_car();
                break;
            case 4:
                check_inventory();
                break;
            case 5:
                check_info();
                break;
        }
        pause();

        instructions();
        cout << endl << "Que opcion deseas usar? ";
        cin >> mainOption;
        
    }
    while (mainOption != 6);
    return 0;   
}
