#ifndef STORAGE_H
#define STORAGE_H

//Objeto que contiene 2 listas de autos electricos y de combustible, se le agregan todos los autos

#include <iostream>
#include <vector>

#include "obj_gas.h"
#include "obj_electric.h"

using namespace std;

class Storage{
    private:
        vector<Electricity> electricityList; //Lista de todos los autos electircos
        vector<Gas> gasList; //Lista de todos los autos de combustion

    public:
        //Constructor sin parametros
        Storage(){
        }

        //Aniade un auto de combustible a la lista de caros de combistible
        void addGas(Gas nuevo){
            gasList.push_back(nuevo);
        }

        //Aniade un auto electrico a la lista de caros electricos
        void addElectricity(Electricity nuevo){
            electricityList.push_back(nuevo);
        }

        //Obtiene la lista de autos de combustible
        vector<Gas> getGasList(){
            return gasList;
        }

        //Obtiene la lista de autos electricos
        vector<Electricity> getElectricityList(){
            return electricityList;
        }

        //Imprime los datos de un auto de gasolina
        void printGasList(){
            for (int i=0 ; i < gasList.size() ; i++) {
                cout << "El auto " << i+1 << " es un " << gasList[i].getBrand() << " " << gasList[i].getModel() << endl;
            }
        }
        
        //Imprime los datos de un auto electrico
        void printElectricityList(){
            for (int i=0 ; i < electricityList.size() ; i++) {
                cout << "El auto " << i+1 << " es un " << electricityList[i].getBrand() << " " << electricityList[i].getModel() << endl;
            }
        }

        //Recibe la posicion de un auto de combustible y lo elimina
        void removeGasCar(int index){
            gasList.erase(gasList.begin() + index);
        }

        //Recibe la posicion de un auto electrico y lo elimina
        void removeElectricityCar(int index){
            electricityList.erase(electricityList.begin() + index);
        }

        //Recibe el indice de un auto de gas e imprime todos sus datos
        void printGasData(int index){
            gasList[index].printGas();
        }

        //Recibe el indice de un auto electrico e imprime todos sus datos
        void printElectricityData(int index){
            electricityList[index].printElectricity();
        }

        //Usa el auto y le resta la gasolina usada y aumento los km del millaje
        void useGascar(int index, int kmTravelled, float fuelUsed){
            gasList[index].gasUsed(fuelUsed, kmTravelled);
        }

        //Usa el auto y le resta el porcentaje usado y aumenta los km del millaje
        void useElectricityCar(int index, int kmTravelled, float chargeUsed){
            electricityList[index].electricityUsed(chargeUsed, kmTravelled); 
        }

        //Funcion que pinta el carro de cierto indice, elecOrGas sirve para saber si es electricco o de combustible
        void repaintCar(int elecOrGas, int index, string newColor){
            switch (elecOrGas){
                case 1:
                    gasList[index-1].setColor(newColor);
                    break;
                case 2:
                    electricityList[index-1].setColor(newColor);
                    break;
            }
        }
        
        //Funcion que rellena de gasolina o carga un auto, elecOrGas sirve para saber si es electrico o de combustible
        void carRefilled(int elecOrGas, int selectedCar, float newCharge){
            switch (elecOrGas){
                case 1:
                    gasList[selectedCar].gasRefilled(newCharge);
                    break;
                case 2:
                    electricityList[selectedCar].carRecharged(newCharge);
                    break;
            }  
        }
};

#endif