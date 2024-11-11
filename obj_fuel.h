#ifndef FUEL_H
#define FUEL_H

#include <iostream>
using namespace std;

class Fuel {
    private:
        string fuelType; //puede ser gasolina o electricidad
        int fuelCapacity; //capacidad maxima de almacenar litros de gasolina o kwh de electricidad
        float fuelInCar; //cuanta gasolina tiene el auto

    public:

        //----Builders----
        Fuel(){
            fuelType = "gasolina";
            fuelCapacity = 0;
            fuelInCar = 0;
        }
        Fuel(string _fuelType, int _fuelCapacity, int _fuelInCar){
            fuelType = _fuelType;
            fuelCapacity = _fuelCapacity;
            fuelInCar = _fuelInCar;
            }
        
        //----Getters----
        string get_fuelType(){
            return fuelType;
        }
        int get_fuelCapacity(){
            return fuelCapacity;
        }
        int get_fuelInCar(){
            return fuelInCar;
        }

        //----setters----
        void set_fuelType(string _fuelType){
            fuelType = _fuelType;
        }
        void set_fuelCapacity(int _fuelCapacity){
            fuelCapacity = _fuelCapacity;
        }
        void set_fuelInCar(int _fuelInCar){
            fuelInCar = _fuelInCar;
        }

        //----Metodos----
        void print_fuel(){
            cout << "El auto usa " << fuelType << endl;
            cout << "la capacidad del tanque es de " << fuelCapacity << "L" << endl;
            cout << "El auto tiene " << fuelInCar << "L de gasolina" << endl;
        }

        void gas_used(int fuelUsed){
            fuelInCar -= fuelUsed;
        }
};

#endif 