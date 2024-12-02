#ifndef ELECTRIC_H
#define ELECTRIC_H

//Objeto que hereda de Car, contiene los datos del Car + los de la bateria del auto electrico

#include <iostream>

#include "obj_cars.h"

using namespace std;

class Electricity: public Car {
    private:
        int electricityCapacity; //capacidad maxima de la bateria del auto em Wh
        float electricityPercentage; //cuanto porcentaje de electricidad tiene el auto

    public:

        //----Builders----
        Electricity(){
            electricityCapacity = 0;
            electricityPercentage = 0;
            Car();
        }
        Electricity(int _electricityCapacity, float _electricityPercentage, string _brand, string _model, int _year, int _cost, string _color, int _horsePower, float _starRating, int _seats, string _country, int _mileage) : Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage){
            electricityCapacity = _electricityCapacity;
            electricityPercentage = _electricityPercentage;
            Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage);
            }
        
        //----Getters----
        int getElectricityCapacity(){
            return electricityCapacity;
        }
        float getElectricityPercentage(){
            return electricityPercentage;
        }

        //----setters----
        void setElectricityCapacity(int _electricityCapacity){
            electricityCapacity = _electricityCapacity;
        }
        void setElectricityPercentage(float _electricityPercentage){
            electricityPercentage = _electricityPercentage;
        }

        //----Metodos----

        //Imprime los datos del objeto Car + los de la electricidad
        void printElectricity(){
            Car::printInfoCar();
            cout << "El auto es electrico" << endl;
            cout << "la capacidad la bateria es de " << electricityCapacity << "Wh" << endl;
            cout << "El auto tiene " << electricityPercentage << "% de bateria" << endl;
            cout << "------------------------------------------------------------------------" << endl;
        }

        //Recibe cuanto porcentaje de carga uso y se lo resta al medidor
        void electricityUsed(float percentageUsed, int kmTravelled){
            electricityPercentage -= percentageUsed;
            Car::carMoved(kmTravelled);
            cout << "El nuevo kilometraje del auto es de " << mileage << "Km recorridos" << endl;
            if (electricityPercentage <= 0){
                electricityPercentage = 0;
                cout << "El auto se ha quedado sin carga" << endl;
            }
            cout << "El carro ahora tiene " << electricityPercentage << "% de bateria" << endl;
        }
    

        //Calcula cuanto tiempo va a tomar en cargar el auto tomando en cuenta que carga a 100kwh
        //Regresa el tiempo en H que va a tardar en cargar
        float timeToFullyCharged(){
            float actualBattery = electricityCapacity*electricityPercentage/100;
            float timeRemaining = electricityCapacity - actualBattery;
            timeRemaining = timeRemaining/6000;
            return timeRemaining;
        }

        //Funcion que recibe las horas que se cargo el auto
        //Asume que cada hora carga 6000 wh de bateria
        void carRecharged(float hoursOfCharge){
            float whCharged = hoursOfCharge*6000;
            float actualBattery = electricityCapacity*electricityPercentage/100;
            actualBattery += whCharged;
            electricityPercentage = 100*actualBattery/electricityCapacity;
            if (electricityPercentage >= 100){
                electricityPercentage = 100;
                cout << "El auto se ha cargado al 100%" << endl;
            }
        }
        
};

#endif 