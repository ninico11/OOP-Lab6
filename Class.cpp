#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "src/model/Model.h"
#include "src/View.h"
#include "src/model/Bear.h"
#include "src/model/Bacteries.h"
#include "src/model/Butterfly.h"
#include "src/model/Deer.h"
#include "src/model/Fox.h"
#include "src/model/Lizard.h"
#include "src/model/Marten.h"
#include "src/model/Rabbit.h"
#include "src/model/Squirrel.h"
#include "src/model/Wolf.h"
#include "src/model/Grandparent and parents.h"

using namespace std;

int main(){
    srand(time(0));
    Bacteries bact;
    Squirrel squir;
    Deer deer;
    Marten mar;
    Lizard  liza;
    Butterfly bfly;
    Rabbit rabb;
    Wolf auf;
    Fox fire;
    Bear griz;
    Resources trigger;
    cout<<"\n Play!\n";
    while(1){
        system("clear");
        int nr=rand()%6+1;
        trigger.moves++;
        display_nr_moves(trigger.moves);
        display_food_quantity(trigger.food);
        display_nr_herbivorus(trigger.numberh);
        display_territry_herbivorus(trigger.territoryh);
        display_nr_carnivorus(trigger.numberc);
        display_territry_carnivorus(trigger.territoryc);
        trigger.food_per_move();
        if(nr==1){
            nr=rand()%8+1;
            if(nr==1){
                nr = rand()%4+1;
                squir.Reproduce(nr);
                trigger.squir_add(nr);
            }
            else if(nr==2){
                nr = rand()%4+1;
                deer.Reproduce(nr);
                trigger.deer_add(nr);
            }
            else if(nr==3){
                nr = rand()%4+1;
                mar.Reproduce(nr);
                trigger.mar_add(nr);
            }
            else if(nr==4){
                nr = rand()%4+1;
                liza.Reproduce(nr);
                trigger.liza_add(nr);
            }
            else if(nr==5){
                nr = rand()%4+1;
                rabb.Reproduce(nr);
                trigger.rabb_add(nr);
            }
            else if(nr==6){
                nr = rand()%4+1;
                auf.Reproduce(nr);
                trigger.wolf_add(nr);
            }
            else if(nr==7){
                nr = rand()%4+1;
                fire.Reproduce(nr);
                trigger.fox_add(nr);
            }
            else{
                nr = rand()%4+1;
                griz.Reproduce(nr);
                trigger.bear_add(nr);
            }
        }
        else if(nr==2){
            nr=rand()%8+1;
            int dnr = 0;
            if(nr==1){
                if((trigger.territoryh * 2) >= trigger.food){
                    dnr = rand()%3;
                }
                else{
                    dnr = rand()%2;
                }
                squir.Die(dnr);
                trigger.squir_minus();
                
            }
            else if(nr==2){
                if((trigger.territoryh * 2) >= trigger.food){
                    dnr = rand()%3;
                }
                else{
                    dnr = rand()%2;
                }
                deer.Die(dnr);
                trigger.deer_minus();
            }
            else if(nr==3){
                if(trigger.numberc > trigger.numberh){
                    dnr = rand()%3;
                }
                else{
                    dnr = rand()%2;
                }            
                mar.Die(dnr);
                trigger.mar_minus();
            }
            else if(nr==4){
                dnr = rand()%2;
                liza.Die(dnr);
                trigger.liza_minus();
            }
            else if(nr==5){
                if((trigger.territoryh * 2) >= trigger.food){
                    dnr = rand()%3;
                }
                else{
                    dnr = rand()%2;
                }
                rabb.Die(dnr);
                trigger.rabb_minus();
            }
            else if(nr==6){
                if(trigger.numberc > trigger.numberh){
                    dnr = rand()%3;
                }
                else{
                    dnr = rand()%2;
                }                    
                auf.Die(dnr);
                trigger.wolf_minus();
            }
            else if(nr==7){
                if(trigger.numberc > trigger.numberh){
                    dnr = rand()%3;
                }
                else{
                    dnr = rand()%2;
                }                    
                fire.Die(dnr);
                trigger.fox_minus();
            }
            else{
                if(trigger.numberc > trigger.numberh){
                    dnr = rand()%3;
                }
                else{
                    dnr = rand()%2;
                }                    
                griz.Die(dnr);
                trigger.bear_minus();
            }
        }
        else if(nr==3){
            nr=rand()%6+1;
            if(nr==1){
                squir.Eat();
                trigger.squir_consume();
            }
            else if(nr==2){
                deer.Eat();
                trigger.deer_consume();
            }
            else if(nr==3){
                bfly.Pollinate();
            }
            else if(nr==4){
                griz.Eat();
                trigger.bear_consume();
            }
            else if(nr==5){
                rabb.Eat();
                trigger.rabb_consume();
            }
            else{
                rabb.Home();
            }
        }
        else if(nr==4){
            nr=rand()%5+1;
            if(nr==1){
                mar.Hunt();
                sleep(1);
                squir.Run();
                sleep(1);
                mar.age=rand()%10+1;
                squir.age=rand()%10+1;
                if((mar.age>=squir.age and mar.age>=8) or (mar.age<=squir.age and mar.age<=3)){
                    squirrel_good_end();
                }
                else if((mar.age>=squir.age and mar.age<8) or (mar.age<=squir.age and mar.age>3)) {
                    squirrel_bad_end();
                    trigger.squir_minus();
                }
            }
            else if(nr==2){
                liza.Hunt();
                trigger.liza_consume();
            }
            else if(nr==3){
                auf.Hunt();
                sleep(1);
                deer.Run();
                sleep(2);
                auf.age=rand()%10+1;
                deer.age=rand()%10+1;
                if((auf.age>=deer.age and auf.age>=8) or (auf.age<=deer.age and auf.age<=3)){
                    deer_good_end();
                }
                else if((auf.age>=deer.age and auf.age<8) or (auf.age<=deer.age and auf.age>3)) {
                    deer_bad_end(0);
                    trigger.deer_minus();
                }
            }
            else if(nr==4){
                fire.Hunt();
                sleep(1);
                rabb.Run();
                sleep(1);
                fire.age=rand()%10+1;
                rabb.age=rand()%10+1;
                if((fire.age>=rabb.age and fire.age>=8) or (fire.age<=rabb.age and fire.age<=3)){
                    rabbit_good_end();
                }
                else if((fire.age>=rabb.age and fire.age<8) or (fire.age<=rabb.age and fire.age>3)){
                    rabbit_bad_end();
                    trigger.rabb_minus();
                }
            }
            else{
                griz.Hunt();
                sleep(1);
                deer.Run();
                sleep(1);
                nr=rand()%2+1;
                griz.age=rand()%10+1;
                deer.age=rand()%10+1;
                if((griz.age>=deer.age and griz.age>=8) or (griz.age<=deer.age and griz.age<=3)){
                    deer_good_end();
                }
                else if((griz.age>=deer.age and griz.age<8) or (griz.age<=deer.age and griz.age>3)) {
                    deer_bad_end(1);
                    trigger.deer_minus();
                }
            }
        }
        else if(nr==5){
            nr=rand()%5+1;
            if(nr==1){
                mar.Protect();
            }
            else if(nr==2){
                auf.Protect();
            }
            else if(nr==3){
                fire.Protect();
            }
            else if(nr==4){
                griz.Protect();
            }
            else{
                liza.Protect();
            }
        }
        else{
            bact.Decompose();
        }
        sleep(1);
        if(trigger.numberh==0 or trigger.numberc == 0 or trigger.food == 0 ){
            if(trigger.numberh == 0){
                herbovorus_end(trigger.moves);
            }
            else if(trigger.numberc == 0){
                carnivorus_end(trigger.moves);
            }
            else{
                food_end(trigger.moves);
            }
            break;
        }    
    }
}

