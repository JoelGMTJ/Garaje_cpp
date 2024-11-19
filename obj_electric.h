#ifndef ELECTRIC_H
#define ELECTRIC_H

#include <iostream>
using namespace std;

class Electricity {
    private:
        int electricityCapacity; //capacidad maxima de la bateria del auto em Wh
        float electricityInCar; //cuanta electricidad tiene el auto en Wh

    public:

        //----Builders----
        Electricity(){
            electricityCapacity = 0;
            electricityInCar = 0;
        }
        Electricity(int _electricityCapacity, int _electricityInCar){
            electricityCapacity = _electricityCapacity;
            electricityInCar = _electricityInCar;
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
            cout << "la capacidad la batería es de " << electricityCapacity << "Wh" << endl;
            cout << "El auto tiene " << electricityInCar << "Wh de electricidad" << endl;
        }

        void electricity_used(int electricityUsed){
            electricityInCar -= electricityUsed;
        }
};

#endif 