#pragma once
#include <iostream>
#include <string>
#include "src/model/Model.h"
using namespace std;


void display_nr_moves(int moves){
    cout<< "Move: " << moves << endl;
}

void display_food_quantity(float food){
    cout<< "Food: " << food <<endl;
}

void display_nr_herbivorus(int numberh){
    cout<< "Number of herbivorus animals: " << numberh << endl;
}

void display_territry_herbivorus(int territoryh){
    cout<< "The territory occupied by herbivorous animals: " << territoryh << endl;
}

void display_nr_carnivorus(int numberc){
    cout<< "Number of carnivorus animals: " << numberc << endl;
}

void display_territry_carnivorus(int territoryc){
    cout<< "The territory occupied by carnivorous animals: " << territoryc << endl;
}

void squirrel_good_end(){
    cout<<"The squirrel escaped\n";
}

void squirrel_bad_end(){
    cout<<"The marten caught the squirrel\n";
}

void deer_good_end(){
    cout<<"The deer escaped\n";
}

void deer_bad_end(int n){
    string predator[2] = {"wolf", "bear"};
    cout<<"The " << predator[n] << " caught the deer\n";
}

void rabbit_good_end(){
    cout<<"The rabbit escaped\n";
}

void rabbit_bad_end(){
    cout<<"The fox caught the rabbit\n";
}

void herbovorus_end(int moves){
    cout<<"The habitat was destroyed because all herbivores died\n";
    cout<<"The habitat existed "<< moves << endl;
}

void carnivorus_end(int moves){
    cout<<"The habitat was destroyed because all carnivores died\n";
    cout<<"The habitat existed "<< moves << endl;
}

void food_end(int moves){
    cout<<"The food ran out and all the animals died of hunger\n";
    cout<<"The habitat existed "<< moves << endl;
}