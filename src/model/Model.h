#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
class Resources{
public:    
    int numberh = 50;
    int numberc = 50;
    int territory = 2000, moves = 0; 
    float food = territory * 10;
    float fnr;
    int territoryh = 500; 
    int poth = 500;
    int territoryc = 500; 
    int potc = 500;
    
    
    void food_per_move(){
        fnr = (rand() / (float)RAND_MAX * 2)+1;
        food -= fnr * numberh;
        if(moves % 30 == 0 && food<(territory*10)){
            food += food * 0.15;
        }
        else{
            food = food;
        }
    }
    
    void deer_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryh += 5*nr;
                poth += 5*nr;
                numberh+=nr;
        }
        else{
                numberh+=nr;
                poth += 5*nr;
        }
    }
    
    void squir_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryh += 1*nr;
                poth += 1*nr;
                numberh+=nr;
        }
        else{
                numberh+=nr;
                poth += 1*nr;
        }
    }
    
    void rabb_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryh += 3*nr;
                poth += 3*nr;
                numberh+=nr;
        }
        else{
                numberh+=nr;
                poth += 3*nr;
        }
    }
    
    void wolf_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryc += 5*nr;
                potc += 5*nr;
                numberc+=nr;
        }
        else{
                numberc+=nr;
                potc += 5*nr;
        }
    }
    
    void liza_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryc += 1*nr;
                potc += 1*nr;
                numberc+=nr;
        }
        else{
                numberc+=nr;
                potc += 1*nr;
        }
    }
    
    void fox_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryc += 3*nr;
                potc += 3*nr;
                numberc+=nr;
        }
        else{
                numberc+=nr;
                potc += 3*nr;
        }
    }
    
    void bear_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryc += 8*nr;
                potc += 8*nr;
                numberc+=nr;
        }
        else{
                numberc+=nr;
                potc += 8*nr;
        }
    }
    
    void mar_add(int nr){
        if((territoryh + territoryc) < territory){
                territoryc += 3*nr;
                potc += 3*nr;
                numberc+=nr;
        }
        else{
                numberc+=nr;
                potc += 3*nr;
        }
    }
    
    void deer_minus(){
        if((territoryc + territoryh) < territory){
                numberh--;
                territoryh -= 5;
                poth -= 5;
        }
        else {
                numberh--;
                poth -= 5;
        }
    }
    
    void squir_minus(){
        if((territoryc + territoryh) < territory){
                numberh--;
                territoryh -= 1;
                poth -= 1;
        }
        else {
                numberh--;
                poth -= 1;
        }
    }
    
    void rabb_minus(){
        if((territoryc + territoryh) < territory){
                numberh--;
                territoryh -= 3;
                poth -= 3;
        }
        else {
                numberh--;
                poth -= 3;
        }
    }
    
    void wolf_minus(){
       if((territoryc + territoryh) < territory){
                numberc--;
                territoryc -= 5;
                potc -= 5;
        }
        else {
                numberc--;
                potc -= 5;
        }
    }
    
    void liza_minus(){
        if((territoryc + territoryh) < territory){
                numberc--;
                territoryc -= 1;
                potc -= 1;
        }
        else {
                numberc--;
                potc -= 1;
        }
    }
    
    void fox_minus(){
        if((territoryc + territoryh) < territory){
                numberc--;
                territoryc -= 3;
                potc -= 3;
        }
        else {
                numberc--;
                potc -= 3;
        }
    }
    
    void bear_minus(){
        if((territoryc + territoryh) < territory){
                numberc--;
                territoryc -= 8;
                potc -= 8;
        }
        else {
                numberc--;
                potc -= 8;
        }
    }
    
    void mar_minus(){
        if((territoryc + territoryh) < territory){
                numberc--;
                territoryc -= 3;
                potc -= 3;
        }
        else {
                numberc--;
                potc -= 3;
        }
    }
    
    void squir_consume(){
        fnr = (rand() / (float)RAND_MAX * 1)+0.25;
        if((territoryh + territoryc) >= territory){
                food -= fnr;
        }
        else{
                food -= fnr + fnr * (numberh  / 100);
        }
    }
    
    void liza_consume(){
        fnr = (rand() / (float)RAND_MAX * 2)+1;
        if((territoryh + territoryc) >= territory){
                food += fnr;
        }
        else{
                food += fnr + fnr * (numberc  / 100);
        }
    }
    
    void deer_consume(){
        fnr = (rand() / (float)RAND_MAX * 10)+5;
        if((territoryh + territoryc) >= territory){
                food -= fnr;
        }
        else{
                food -= fnr + fnr * (numberh  / 100);
        }
    }
    
    void rabb_consume(){
        fnr = (rand() / (float)RAND_MAX * 5)+2;
        if((territoryh + territoryc) >= territory){
                food -= fnr;
        }
        else{
                food -= fnr + fnr * (numberh  / 100);
        }
    }
    
    void bear_consume(){
        fnr = (rand() / (float)RAND_MAX * 10)+2;
        if((territoryh + territoryc) >= territory){
                food -= fnr;
        }
        else{
                food -= fnr + fnr * (numberc  / 100);
        }  
    }
};
