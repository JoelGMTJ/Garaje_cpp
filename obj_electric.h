#ifndef ELECTRIC_H
#define ELECTRIC_H

#include <iostream>
using namespace std;

class Electricity: public Car {
    private:
        int electricityCapacity; //capacidad maxima de la bateria del auto em Wh
        float electricityInCar; //cuanta electricidad tiene el auto en Wh

    public:

        //----Builders----
        Electricity(){
            electricityCapacity = 0;
            electricityInCar = 0;
            Car();
        }
        Electricity(int _electricityCapacity, int _electricityInCar, string _brand, string _model, int _year, int _cost, string _color, int _horsePower, float _starRating, int _seats, string _country, int _mileage) : Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage){
            electricityCapacity = _electricityCapacity;
            electricityInCar = _electricityInCar;
            Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage);
            }
        
        //----Getters----
        int get_electricityCapacity(){
            return electricityCapacity;
        }
        int get_electricityInCar(){
            return electricityInCar;
        }

        //----setters----
        void set_electricityCapacity(int _electricityCapacity){
            electricityCapacity = _electricityCapacity;
        }
        void set_electricityInCar(int _electricityInCar){
            electricityInCar = _electricityInCar;
        }

        //----Metodos----
        void print_electricity(){
            cout << "El auto usa electricidad" << endl;
            cout << "la capacidad la bateria es de " << electricityCapacity << "Wh" << endl;
            cout << "El auto tiene " << electricityInCar << "Wh de electricidad" << endl;
        }

        void electricity_used(int electricityUsed){
            electricityInCar -= electricityUsed;
        }

        float time_to_fully_charged(){
            float elecMissing = electricityCapacity-electricityInCar;
            //asumiendo que se cargen a 100kwh
            //lo va a regresar en horas
            return (elecMissing/100)/60;

        }
};

#endif 