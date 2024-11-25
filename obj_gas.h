#ifndef GAS_H
#define GAS_H

#include <iostream>
#include "obj_cars.h"
using namespace std;

class Gas: public Car {
    private:
        int gasCapacity; //capacidad maxima de almacenar litros de gasolina
        float gasInCar; //cuanta gasolina tiene el auto

    public:

        //----Builders----
        Gas(){
            gasCapacity = 0;
            gasInCar = 0;
            Car();
        }
        Gas(int _gasCapacity, int _gasInCar, string _brand, string _model, int _year, int _cost, string _color, int _horsePower, float _starRating, int _seats, string _country, int _mileage): Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage){
            gasCapacity = _gasCapacity;
            gasInCar = _gasInCar;
            Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage);
            }
        
        //----Getters----
        int get_gasCapacity(){
            return gasCapacity;
        }
        int get_gasInCar(){
            return gasInCar;
        }

        //----setters----
        void set_gasCapacity(int _gasCapacity){
            gasCapacity = _gasCapacity;
        }
        void set_gasInCar(int _gasInCar){
            gasInCar = _gasInCar;
        }

        //----Metodos----
        void print_info(){
            Car::print_info_car();
            cout << "El auto usa gasolina" << endl;;
            cout << "la capacidad del tanque es de " << gasCapacity << "L" << endl;
            cout << "El auto tiene " << gasInCar << "L de gasolina" << endl;
            cout << "------------------------------------------------------------------------" << endl;
        }

        void gas_used(int gasUsed){
            gasInCar -= gasUsed;
        }

        
};

#endif 