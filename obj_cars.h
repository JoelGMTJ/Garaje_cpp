#ifndef CARS_H
#define CARS_H

#include <iostream>
#include "obj_gas.h"
#include "obj_electric.h"
using namespace std;

class Car {
    private:
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

    public:

        //----Builders----
        Car(){
            brand = "Desconocido"; 
            model = "Desconocido"; 
            year = 2000; 
            cost = 0; 
            color = "blanco"; 
            horsePower = 50; 
            starRating = 0; 
            seats = 5;
            country = "internacional"; 
            mileage = 0;
        }
        Car(string _brand, string _model, int _year, int _cost, string _color, int _horsePower, float _starRating, int _seats, string _country, int _mileage){
            brand = _brand;
            model = _model;
            year = _year;
            cost = _cost;
            color = _color;
            horsePower = _horsePower;
            starRating = _starRating;
            seats = _seats;
            country = _country;
            mileage = _mileage;
        }
        
        //----Getters----
        string get_brand(){
            return brand;
        }
        string get_model(){
            return model;
        }
        int get_year(){
            return year;
        }
        int get_cost(){
            return cost;
        }
        string get_color(){
            return color;
        }
        int get_horsePower(){
            return horsePower;
        }
        float get_starRating(){
            return starRating;
        }
        int get_seats(){
            return seats;
        }
        string get_country(){
            return country;
        }
        int get_mileage(){
            return mileage;
        }
        

        //----setters----
        void set_brand(string _brand){
            brand = _brand;
        }
        void set_model(string _model){
            model = _model;
        }
        void set_year(int _year){
            year = _year;
        }
        void set_cost(int _cost){
            cost = _cost;
        }
        void set_color(string _color){
            color = _color;
        }
        void set_horsePower(int _horsePower){
            horsePower = _horsePower;
        }
        void set_starRating(float _starRating){
            starRating = _starRating;
        }
        void set_seats(int _seats){
            seats = _seats;
        }
        void set_country(string _country){
            country = _country;
        }
        void set_mileage(int _mileage){
            mileage = _mileage;
        }

        //----metodos----

        void print_datos(){
            cout << "------------------------------------------------------------------------" << endl;
            cout << "El auto es un " << brand << " " << model << endl;
            cout << "El auto es del anio " << year << endl;
            cout << "El precio original del auto es de $" << cost << " dolares" << endl;
            cout << "El auto es de color " << color << endl;
            cout << "El auto cuenta con " << horsePower << " caballos de fuerza" << endl;
            cout << "La calificacion del auto es de " << starRating << "/5 estrellas" << endl;
            cout << "El auto tiene " << seats << " asientos" << endl;
            cout << "El auto es de origen " << country << endl;
            cout << "El auto ha recorrido " << mileage << "km" << endl;
            cout << "------------------------------------------------------------------------" << endl;
        }

        void car_moved(int travelled){
            mileage += travelled;
        }
};

#endif 