#ifndef GAS_H
#define GAS_H

//Objeto que hereda de Car, contiene todos los datos del Car + los del tanque de gasolina

#include <iostream>

#include "obj_cars.h"

using namespace std;

class Gas: public Car {
    private:
        int gasCapacity; //capacidad maxima de almacenar litros de gasolina
        float gasInCar; //cuanta gasolina tiene el auto actualmente

    public:

        //----Builders----
        Gas(){
            gasCapacity = 0;
            gasInCar = 0.0;
            Car();
        }
        Gas(int _gasCapacity, float _gasInCar, string _brand, string _model, int _year, int _cost, string _color, int _horsePower, float _starRating, int _seats, string _country, int _mileage): Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage){
            gasCapacity = _gasCapacity;
            gasInCar = _gasInCar;
            Car( _brand,  _model,  _year,  _cost,  _color,  _horsePower,  _starRating,  _seats,  _country,  _mileage);
            }
        
        //----Getters----
        int getGasCapacity(){
            return gasCapacity;
        }
        float getGasInCar(){
            return gasInCar;
        }

        //----setters----
        void setGasCapacity(int _gasCapacity){
            gasCapacity = _gasCapacity;
        }
        void setGasInCar(float _gasInCar){
            gasInCar = _gasInCar;
        }

        //----Metodos----

        //Imprime los datos del obtjeto Car + los del combustible
        void printGas(){
            Car::printInfoCar();
            cout << "El auto es de combustion" << endl;;
            cout << "la capacidad del tanque es de " << gasCapacity << "L" << endl;
            cout << "El auto tiene " << gasInCar << "L de gasolina" << endl;
            cout << "------------------------------------------------------------------------" << endl;
        }

        //Recibe una cantidad de litros de gasolina usados y los resta a la cantidad actual
        void gasUsed(float gasUsed, int kmTravelled){
            gasInCar -= gasUsed;
            Car::carMoved(kmTravelled);
            cout << "El nuevo kilometraje del auto es de " << mileage << "Km recorridos" << endl;
            if (gasInCar < 0){
                gasInCar = 0;
                cout << "El auto se ha quedado sin gasolina" << endl;
            }
            cout << "El carro ahora tiene " << gasInCar << "L de gasolina" << endl;
        }

        //Le agrega la cantidad de gasolina que recibe a su tanque
        void gasRefilled(float addedGas){
            gasInCar += addedGas;
            if (gasInCar >= gasCapacity){
                cout << "Tu auto se ha llenado de gasolina" << endl;
                gasInCar = gasCapacity;
            }
        }
        
};

#endif 