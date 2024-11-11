//Por hacer: agregar una tercera clase. Econtrar una forma de relacionar la gasolina con el objeto del auto
//separar correctamente todas las funciones que quiero implemetar
//comentar mejor el codigo

#include <iostream>
#include "obj_cars.h"
#include "obj_fuel.h"

using namespace std;


int main(){

    // DATOS: marca, modelo, año, precio, color, caballos de fuerza, motor, estrellas, asientos, nacionalidad, videojuego, millaje

    // auto generico, lo que pasa si creas un objeto sin parametros
    Car generico = Car();
    Fuel genericoF = Fuel();

    // ejemplos de autos 
    Fuel MX5F = Fuel("gasolina", 45, 45);
    Car MX5 = Car("Mazda", "Miata", 1989, 13800, "rojo", 115, "1", 5,  2,  "japones", "Need for Speed Underground 2", 30000);
    Fuel SF24F = Fuel("mezcla de combustible", 145, 145);
    Car SF24 = Car("Ferrari", "Formula 1 SF24", 2024, 16000000, "rojo", 1000, "2", 4.5, 1, "italiano", "F1 24", 8900);
    Fuel Tes3F = Fuel("electricidad", 57, 45);
    Car Tes3 = Car("Tesla", "Model 3", 2021, 400, "blanco", 400, "3", 3, 5, "americano", "N/A", 4000);

    // impresiones de los datos de los autos
    generico.print_datos();
    genericoF.print_fuel();

    MX5.print_datos();
    MX5F.print_fuel();
    
    SF24.print_datos();
    SF24F.print_fuel();

    Tes3.print_datos();
    Tes3F.print_fuel();

    //uso de algunos metodos
    cout << "El auto inicialmente tiene " << MX5.get_mileage() << "km recorridos" << endl;
    cout << "El auto inicialmente tiene " << MX5F.get_fuelInCar() << "L de gasolina" << endl;

    int trayecto;
    cout << "Cuantos kilometros recorrio el auto? ";
    cin >> trayecto;
    MX5.car_moved(trayecto);

    int litrosUsados;
    cout << "Cuantos litros de gasolina uso el auto? ";
    cin >> litrosUsados;
    MX5F.gas_used(litrosUsados);

    cout << "Despues del trayecto, el auto recorrio " << MX5.get_mileage() << "km" << endl;
    cout << "Despues del trayecto, el auto tiene " << MX5F.get_fuelInCar() << "L de gasolina" << endl;

    int opcion;
    cout << "Quieres pintar tu " << MX5.get_brand() << MX5.get_model() << " ? (1 para pintarlo) ";
    cin >> opcion;
    if (opcion == 1){
        cout << "El actual color de tu auto es " << MX5.get_color() << endl;
        cout << "Que color quieres pintar tu auto? ";
        string newPaint;
        cin >> newPaint;
        MX5.car_repainted(newPaint);
        cout << "El nuevo color de tu " << MX5.get_brand() << " " << MX5.get_model() << " es " << MX5.get_color();
    }

    return 0;   
}