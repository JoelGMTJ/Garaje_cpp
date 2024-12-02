/*
Programa que maneja un almacen de autos
Creado por Joel Guadalupe Garcia Guzman A01713785
01/dic/24
*/

#include <iostream>

#include "obj_gas.h"
#include "obj_electric.h"
#include "obj_storage.h"

using namespace std;

//Objeto de almacen principal
Storage storage = Storage();


//-----Funciones-----

//Lista de opciones del programa
void instructions(){
    cout << endl << "Presione 1 para ver todos los autos en tu almacen" << endl;
    cout << "Presione 2 para ver todos los datos de un auto" << endl;
    cout << "Presione 3 para crear un auto" << endl;
    cout << "Presione 4 para eliminar un auto" << endl;
    cout << "Presione 5 para usar un auto" << endl;
    cout << "Presione 6 para recargar un auto" << endl;
    cout << "Presione 7 para repintar un auto" << endl;
    cout << "Presione 8 para salir del programa" << endl;
}


//Funcion que crea algunos autos en el almacen
void createExamples(){
    // ejemplos de autos de combustible
    Gas MX5 = Gas(60, 45, "Mazda", "Miata", 1989, 13800, "rojo", 115, 5,  2,  "japones", 30000);
    storage.addGas(MX5);
    Gas SF24 = Gas(145, 98, "Ferrari", "Formula 1 SF24", 2024, 16000000, "rojo", 1000, 4.8, 1, "italiano", 8900);
    storage.addGas(SF24);
    Gas GTI = Gas(55, 30, "Volkswagen", "Golf GTI", 2018, 28000, "azul", 220, 3.7, 5, "aleman", 45000);
    storage.addGas(GTI);
    Gas Camry = Gas(60, 45, "Toyota", "Camry", 2022, 30000, "negro", 203, 4.8, 3.5, "japones", 10000);
    storage.addGas(Camry);
    Gas Mustang = Gas(61, 40, "Ford", "Mustang GT", 2020, 55000, "amarillo", 450, 4, 4, "americano", 20000);
    storage.addGas(Mustang);
    Gas Accord = Gas(56, 35, "Honda", "Accord", 2021, 32000, "rojo", 192, 4.6, 5, "japones", 12000);
    storage.addGas(Accord);
    Gas Supra = Gas(70, 45, "Toyota", "Supra MK4", 1998, 60000, "rojo", 276, 4.3, 4, "japones", 120000);
    storage.addGas(Supra);
    Gas RX7 = Gas(61, 30, "Mazda", "RX-7", 1995, 45000, "blanco", 276, 5, 4, "japones", 90000);
    storage.addGas(RX7);
    Gas Tacoma = Gas(80, 50, "Toyota", "Tacoma", 2023, 40000, "negro", 278, 4.7, 5, "japones", 15000);
    storage.addGas(Tacoma);
    Gas F40 = Gas(120, 80, "Ferrari", "F40", 1992, 1500000, "rojo", 478, 5.0, 2, "italiano", 30000);
    storage.addGas(F40);
    Gas Skyline = Gas(65, 40, "Nissan", "Skyline GT-R R34", 1999, 90000, "azul", 276, 5, 4, "japones", 70000);
    storage.addGas(Skyline);
    Gas Hellcat = Gas(70, 55, "Dodge", "Challenger Hellcat", 2021, 65000, "negro", 717, 4, 5, "americano", 20000);
    storage.addGas(Hellcat);


    //Ejemplos de autos electricos
    Electricity Tes3 = Electricity(60000, 69, "Tesla", "Model 3", 2021, 400, "blanco", 400, 3, 5, "americano", 4000);
    storage.addElectricity(Tes3);
    Electricity Leaf = Electricity(40000, 70, "Nissan", "Leaf", 2021, 20000, "plateado", 150, 4.0, 5, "japones", 15000);
    storage.addElectricity(Leaf);
    Electricity i3 = Electricity(42000, 69, "BMW", "i3", 2020, 45000, "blanco", 170, 4.3, 4, "aleman", 8000);
    storage.addElectricity(i3);
    Electricity Taycan = Electricity(93000, 100, "Porsche", "Taycan", 2023, 80000, "gris", 500, 4.9, 4, "aleman", 0);
    storage.addElectricity(Taycan);
    Electricity Bolt = Electricity(60000, 55, "Chevrolet", "Bolt EV", 2022, 32000, "verde", 200, 4.4, 5, "americano", 10000);
    storage.addElectricity(Bolt);
    Electricity Cybertruck = Electricity(250000, 100, "Tesla", "Cybertruck", 2024, 39900, "plata", 1020, 3.2, 6, "americano", 0);
    storage.addElectricity(Cybertruck);
} 


//Sirve para pausar el programa y que continue cuando presiones un caracter
void pause(){
    string line;
    cout << "Presione algun caracter para continuar ";
    cin >> line;
}


//Pregunta si quiere ver la lista de autos electricos o de gas
void showCars(){
    int carType;
    
    cout << "Escribe 1 si quieres seleccionar un auto de combustible, escribe 2 si quieres ver un auto electrico, escribe 3 si quieres ver todos los autos ";
    cin >> carType;
    cout << endl;
    if (carType == 1){
        storage.printGasList();
    }
    if (carType == 2){
        storage.printElectricityList();
    }
    if (carType == 3){
        storage.printGasList();
        cout << endl;
        storage.printElectricityList();
    }
    cout << endl;

}


//Imprime todos los datos de un auto
void viewCarInfo(){
    int carType;
    int selectedCar;
    cout << "Ahora dime, que tipo de carro quieres examinar, 1 si es de combustible y 2 si es electrico ";
    cin >> carType;
    if (carType == 1){
        storage.printGasList();
        cout << "Que auto quieres examinar? ";
        cin >> selectedCar;
        storage.printGasData(selectedCar-1);
    }
    if (carType == 2){
        storage.printElectricityList();
        cout << "Que auto quieres examinar? ";
        cin >> selectedCar;
        storage.printElectricityData(selectedCar-1);
    }
}


//Crea un auto, pregunta al usuario si quiere agregar un auto de combustible o electrico
void createCar(){
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
    int capacity; // cuanta capacidad tiene el auto, gas o elec
    float actualTanq; // cuanta gas/elec tiene el carro actualmente
    int carType; // Identificador para crear un electrico o de combustible

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
    cout << "Ahora dime, que tipo de carro es, 1 si es de combustible y 2 si es electrico ";
    cin >> carType;

    if (carType == 1){
        cout << "Cual es la capacidad del tanque de tu auto? " << endl;
        cin >> capacity;
        cout << "Cuantos litros de gasolina tiene actualmente tu auto? " << endl;
        cin >> actualTanq;
        if (actualTanq > capacity){
            cout << "Error, desbordado de gasolina" << endl;
        }
        else {
            Gas newCar = Gas (capacity, actualTanq, brand, model, year, cost, color, horsePower, starRating, seats, country, mileage);
            storage.addGas(newCar);
            cout << "Auto agregado con exito!" << endl;
        }
    }
    else if (carType == 2){
        cout << "Cual es la capacidad de la bateria de tu auto (en Wh)? " << endl;
        cin >> capacity;
        cout << "Cual es el porcentaje de carga de tu auto?" << endl;
        cin >> actualTanq;
        if (actualTanq>100){
            cout << "Error, sobrepasa el 100% de bateria" << endl;
        }
        else {
            Electricity newCar = Electricity (capacity, actualTanq, brand, model, year, cost, color, horsePower, starRating, seats, country, mileage);
            storage.addElectricity(newCar);
            cout << "Auto agregado con exito!" << endl;
        }
    }

}


//Le pide al usuario un indice de auto, y lo elimina de la lista
void deleteCar(){
    int carType;
    int selectedCar;
    cout << "Que tipo de carro quieres eliminar, 1 si es de combustible y 2 si es electrico ";
    cin >> carType;
    if (carType == 1){
        storage.printGasList();
        cout << "Que auto quieres eliminar? ";
        cin >> selectedCar;
        cout << "Se ha eliminado tu " << storage.getGasList()[selectedCar-1].getBrand() << " " << storage.getGasList()[selectedCar-1].getModel() << " con exito! " << endl;
        storage.removeGasCar(selectedCar-1);
    }
    if (carType == 2){
        storage.printElectricityList();
        cout << "Que auto quieres eliminar? ";
        cin >> selectedCar;
        cout << "Se ha eliminado tu " << storage.getElectricityList()[selectedCar-1].getBrand() << " " << storage.getElectricityList()[selectedCar-1].getModel() << " con exito! " << endl;
        storage.removeElectricityCar(selectedCar-1);
    }
}


//Funcion que le aniade km al millaje y le resta gas/energia al auto
void useCar(){
    int carType;
    int selectedCar;
    int kmTravelled; //Cuantos km se recorrieron 
    float chargeUsed; //Porgcentaje o cantidad de litros que se usaron
    cout << "Que tipo de carro quieres usar, 1 si es de combustible y 2 si es electrico ";
    cin >> carType;
    if (carType == 1){
        storage.printGasList();
        cout << "Que auto quieres usar? ";
        cin >> selectedCar;
        cout << endl << "Tu " << storage.getGasList()[selectedCar-1].getBrand() << " tiene "<< storage.getGasList()[selectedCar-1].getMileage() << "km de kilometraje y actualmente tiene " << storage.getGasList()[selectedCar-1].getGasInCar() << "L de gasolina" << endl;
        cout << "Cuantos kilometros recorriste en tu auto? ";
        cin >> kmTravelled;
        cout << "Cuanta gasolina usaste para el trayecto? ";
        cin >>  chargeUsed;
        cout << endl;
        storage.useGascar(selectedCar-1, kmTravelled, chargeUsed);
    }
    if (carType == 2){
        storage.printElectricityList();
        cout << "Que auto quieres usar? ";
        cin >> selectedCar;
        cout << endl << "Tu " << storage.getElectricityList()[selectedCar-1].getBrand() << " tiene "<< storage.getElectricityList()[selectedCar-1].getMileage() << "km de kilometraje y actualmente tiene " << storage.getElectricityList()[selectedCar-1].getElectricityPercentage() << "% de bateria" << endl;
        cout << "Cuantos kilometros recorriste en tu auto? ";
        cin >> kmTravelled;
        cout << "Cuanto porcentaje de bateria usaste? ";
        cin >>  chargeUsed;
        cout << endl;
        storage.useElectricityCar(selectedCar-1, kmTravelled, chargeUsed);
    }
}


//Le pide al usuario cuanto va a cargar su auto y lo aumenta a su nivel de bateria
void chargeCar(){
    int carType;
    int selectedCar;
    float chargeFillled; //cantidad de litros que se lleno el auto or horas que duro cargandose el auto
    cout << "Que tipo de carro quieres recargar, 1 si es de combustible y 2 si es electrico ";
    cin >> carType;
    if (carType == 1){
        storage.printGasList();
        cout << "Que auto quieres ponerle gasolina? ";
        cin >> selectedCar;
        cout << "Seleccionaste tu " << storage.getGasList()[selectedCar-1].getBrand() << " " << storage.getGasList()[selectedCar-1].getModel() << endl;
        cout << "Tu auto actualmente tiene " << storage.getGasList()[selectedCar-1].getGasInCar() << "L de gasolina" << endl;
        cout << "Cuanta gasolina le recargaste? ";
        cin >>  chargeFillled;
        storage.carRefilled(1, selectedCar-1, chargeFillled);
        cout << "Ahora tu auto tiene " << storage.getGasList()[selectedCar-1].getGasInCar() << "L de gasolina" << endl;
    }
    if (carType == 2){
        storage.printElectricityList();
        cout << "Que auto quieres recargar? ";
        cin >> selectedCar;
        cout << "Seleccionaste tu " << storage.getElectricityList()[selectedCar-1].getBrand() << " " << storage.getElectricityList()[selectedCar-1].getModel() << endl;
        cout << "Tu auto actualmente tiene " << storage.getElectricityList()[selectedCar-1].getElectricityPercentage() << "% de gasolina" << endl;
        cout << "Tu auto se va cargar al 100% en " << storage.getElectricityList()[selectedCar-1].timeToFullyCharged() << " horas" << endl;
        cout << "Cuantas horas dejaste cargando tu auto? ";
        cin >>  chargeFillled;
        storage.carRefilled(2, selectedCar-1, chargeFillled);
        cout << "Ahora tu auto tiene " << storage.getElectricityList()[selectedCar-1].getElectricityPercentage() << "% de bateria" << endl;
    }
}


//Le cambia el color a un auto
void repaintCar(){
    int carType;
    int selectedCar;
    string newPaint;
    cout << "Que tipo de carro quieres repintar, 1 si es de combustible y 2 si es electrico ";
    cin >> carType;
    if (carType == 1){
        storage.printGasList();
        cout << "Que auto quieres repintar? ";
        cin >> selectedCar;
        cout << "El color actual de tu auto es " << storage.getGasList()[selectedCar-1].getColor() << endl;
        cout << "De que color quieres pintar tu auto? ";
        cin >> newPaint;
        storage.repaintCar(1, selectedCar, newPaint);
        cout << "Tu auto ahora es " << storage.getGasList()[selectedCar-1].getColor() << endl;
    }
    if (carType == 2){
        storage.printElectricityList();
        cout << "Que auto quieres repintar? ";
        cin >> selectedCar;
        cout << "El color actual de tu auto es " << storage.getElectricityList()[selectedCar-1].getColor() << endl;
        cout << "De que color quieres pintar tu auto? ";
        cin >> newPaint;
        storage.repaintCar(2, selectedCar, newPaint);
        cout << "Tu auto ahora es " << storage.getElectricityList()[selectedCar-1].getColor() << endl;   
    }
}





//--------------------Main--------------------
int main(){ 
    cout << endl << "Bienvenido a tu almacen de autos" << endl;
    cout << "Aqui podras guardar tantos autos como quieras, revisar sus datos, tomar un auto para un paseo y muchas otras cosas";

    createExamples();

    int mainOption;
    do{
        cout << endl;
        switch (mainOption){
            case 1:
                showCars(); 
                break; 
            case 2:
                viewCarInfo();
                break; 
            case 3:
                createCar();
                break; 
            case 4:
                deleteCar();
                break; 
            case 5:
                useCar();
                break; 
            case 6:
                chargeCar();
                break; 
            case 7:
                repaintCar();
                break; 
        }

        pause();
        instructions();
        cout << endl << "Que opcion deseas usar? ";
        cin >> mainOption;
        
    }
    while (mainOption != 8);
    cout << endl << "Gracias por usar el programa" << endl << "Hasta pronto" << endl << " " << endl;
    return 0;   
}
