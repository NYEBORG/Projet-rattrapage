#include <stdio.h>
#include "menu.h"
#include "voitures.h"

int main() {

    voiture voitures[4];
    initVoiture(&voitures[0], "CB-159-RX", "Lamborghini","Aventador");
    initVoiture(&voitures[1], "BX-422-PM", "Bugatti", "Veyron" );
    initVoiture(&voitures[2], "EK-018-MP", "Ferrari", "458 Spider GT");
    initVoiture(&voitures[3], "DS-389-EA","Maserati", "Granturismo");

    return 0;
}