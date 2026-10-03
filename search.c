#include <string.h>
#include "search.h"

int searchVehicle(Vehicle vehicles[], int count, const char vehicleNumber[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(vehicles[i].vehicleNumber, vehicleNumber) == 0) {
            return i;
        }
    }

    return -1;
}