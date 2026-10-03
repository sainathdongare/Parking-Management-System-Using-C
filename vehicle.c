#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void displayVehicle(Vehicle vehicle) {
    printf("\nVehicle Number : %s", vehicle.vehicleNumber);
    printf("\nOwner Name     : %s", vehicle.ownerName);
    printf("\nVehicle Type   : %s", vehicle.vehicleType);
    printf("\nSlot Number    : %d\n", vehicle.slotNumber);
}