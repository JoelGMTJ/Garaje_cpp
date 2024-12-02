#ifndef CARS_H
#define CARS_H

//Clase Car, contiene los datos generales de un auto, padre de las clases electrico y gas

#include <iostream>

using namespace std;

class Car {
    protected:
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
        string getBrand(){
            return brand;
        }
        string getModel(){
            return model;
        }
        int getYear(){
            return year;
        }
        int getCost(){
            return cost;
        }
        string getColor(){
            return color;
        }
        int getHorsePower(){
            return horsePower;
        }
        float getStarRating(){
            return starRating;
        }
        int getSeats(){
            return seats;
        }
        string getCountry(){
            return country;
        }
        int getMileage(){
            return mileage;
        }
        

        //----setters----
        void setBrand(string _brand){
            brand = _brand;
        }
        void setModel(string _model){
            model = _model;
        }
        void setYear(int _year){
            year = _year;
        }
        void setCost(int _cost){
            cost = _cost;
        }
        void setColor(string _color){
            color = _color;
        }
        void setHorsePower(int _horsePower){
            horsePower = _horsePower;
        }
        void setStarRating(float _starRating){
            starRating = _starRating;
        }
        void setSeats(int _seats){
            seats = _seats;
        }
        void setCountry(string _country){
            country = _country;
        }
        void setMileage(int _mileage){
            mileage = _mileage;
        }

        //----metodos----

        //Imprime todos los datos del auto
        void printInfoCar(){
            cout << endl << "------------------------------------------------------------------------" << endl;
            cout << "El auto es un " << brand << " " << model << endl;
            cout << "El auto es del anio " << year << endl;
            cout << "El precio original del auto es de $" << cost << " dolares" << endl;
            cout << "El auto es de color " << color << endl;
            cout << "El auto cuenta con " << horsePower << " caballos de fuerza" << endl;
            cout << "La calificacion del auto es de " << starRating << "/5 estrellas" << endl;
            cout << "El auto tiene " << seats << " asientos" << endl;
            cout << "El auto es de origen " << country << endl;
            cout << "El auto ha recorrido " << mileage << "km" << endl;
        }

        //Obtiene los km que se recorrieron y se los aumenta al millaje del auto
        void carMoved(int travelled){
            mileage += travelled;
        }
};

#endif 