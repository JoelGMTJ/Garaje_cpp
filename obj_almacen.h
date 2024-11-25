#ifndef ALMACEN_H
#define ALMACEN_H

#include <iostream>
#include <vector>
#include "obj_cars.h"
#include "obj_gas.h"
#include "obj_electric.h"

using namespace std;

class Storage{
    private:
        vector<Electricity> electricityList;
        vector<Gas> gasList;
        vector<Car> allCarList; //voy a tener 2 listas de autos, para cuando solo quiera trabajar con las caracteristicas generales de los autos y cuando quiera usar solo los de fuels


    public:
        Storage(){
        }


        void add_gas(Gas nuevo, Car nuevoCar){
            gasList.push_back(nuevo);
            allCarList.push_back(nuevoCar);
        }
        void add_electricity(Electricity nuevo, Car nuevoCar){
            electricityList.push_back(nuevo);
            allCarList.push_back(nuevoCar);

        }

        void all_brand_cars (){

        }

        vector<Gas> get_gasList(){
            return gasList;
        }

        vector<Electricity> get_electricityList(){
            return electricityList;
        }

        vector<Car> get_AllCarList(){
            return allCarList;
        }
        
};

#endif