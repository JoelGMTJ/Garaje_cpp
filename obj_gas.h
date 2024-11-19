#ifndef GAS_H
#define GAS_H

#include <iostream>
using namespace std;

class Gas {
    private:
        int gasCapacity; //capacidad maxima de almacenar litros de gasolina
        float gasInCar; //cuanta gasolina tiene el auto

    public:

        //----Builders----
        Gas(){
            gasCapacity = 0;
            gasInCar = 0;
        }
        Gas(int _gasCapacity, int _gasInCar){
            gasCapacity = _gasCapacity;
            gasInCar = _gasInCar;
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
        void print_gas(){
            cout << "El auto usa gasolina" << endl;;
            cout << "la capacidad del tanque es de " << gasCapacity << "L" << endl;
            cout << "El auto tiene " << gasInCar << "L de gasolina" << endl;
        }

        void gas_used(int gasUsed){
            gasInCar -= gasUsed;
        }
};

#endif 