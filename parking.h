#ifndef PARKING_H
#define PARKING_H

#include "vehicle.h"

#define TOTAL_SLOTS 10

typedef struct {
    int slotNumber;
    int isOccupied;
    Vehicle vehicle;
} ParkingSlot;

void initializeParking();
int parkVehicle(Vehicle vehicle);
Vehicle removeVehicle(int slotNumber);
void displayParkingSlots();
void displayAvailableSlots();
int findVehicleSlot(const char vehicleNumber[]);
int getAvailableSlot();

#endif