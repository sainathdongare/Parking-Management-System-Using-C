#ifndef VEHICLE_H
#define VEHICLE_H

#define VEHICLE_NUMBER_LENGTH 20
#define OWNER_NAME_LENGTH 50
#define VEHICLE_TYPE_LENGTH 20

typedef struct {
    char vehicleNumber[VEHICLE_NUMBER_LENGTH];
    char ownerName[OWNER_NAME_LENGTH];
    char vehicleType[VEHICLE_TYPE_LENGTH];
    int slotNumber;
} Vehicle;

#endif