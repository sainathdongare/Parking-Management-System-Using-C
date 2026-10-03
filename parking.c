#include <stdio.h>
#include <string.h>
#include "parking.h"

static ParkingSlot parkingSlots[TOTAL_SLOTS];

void initializeParking() {
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        parkingSlots[i].slotNumber = i + 1;
        parkingSlots[i].isOccupied = 0;
        parkingSlots[i].vehicle.slotNumber = -1;
    }
}

int getAvailableSlot() {
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (!parkingSlots[i].isOccupied) {
            return i + 1;
        }
    }

    return -1;
}

int parkVehicle(Vehicle vehicle) {
    int slot = getAvailableSlot();

    if (slot == -1) {
        return -1;
    }

    parkingSlots[slot - 1].isOccupied = 1;
    parkingSlots[slot - 1].vehicle = vehicle;
    parkingSlots[slot - 1].vehicle.slotNumber = slot;

    return slot;
}

Vehicle removeVehicle(int slotNumber) {
    Vehicle vehicle;

    vehicle.slotNumber = -1;
    strcpy(vehicle.vehicleNumber, "");
    strcpy(vehicle.ownerName, "");
    strcpy(vehicle.vehicleType, "");

    if (slotNumber < 1 || slotNumber > TOTAL_SLOTS) {
        return vehicle;
    }

    if (!parkingSlots[slotNumber - 1].isOccupied) {
        return vehicle;
    }

    vehicle = parkingSlots[slotNumber - 1].vehicle;

    parkingSlots[slotNumber - 1].isOccupied = 0;
    parkingSlots[slotNumber - 1].vehicle.slotNumber = -1;

    return vehicle;
}

int findVehicleSlot(const char vehicleNumber[]) {
    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (parkingSlots[i].isOccupied &&
            strcmp(parkingSlots[i].vehicle.vehicleNumber, vehicleNumber) == 0) {
            return parkingSlots[i].slotNumber;
        }
    }

    return -1;
}

void displayParkingSlots() {
    printf("\n========== PARKING SLOTS ==========\n");

    for (int i = 0; i < TOTAL_SLOTS; i++) {
        printf("\nSlot %d : ", parkingSlots[i].slotNumber);

        if (parkingSlots[i].isOccupied) {
            printf("Occupied");
            printf(" | Vehicle: %s",
                   parkingSlots[i].vehicle.vehicleNumber);
        } else {
            printf("Available");
        }
    }

    printf("\n===================================\n");
}

void displayAvailableSlots() {
    printf("\n========== AVAILABLE SLOTS ==========\n");

    int found = 0;

    for (int i = 0; i < TOTAL_SLOTS; i++) {
        if (!parkingSlots[i].isOccupied) {
            printf("%d ", parkingSlots[i].slotNumber);
            found = 1;
        }
    }

    if (!found) {
        printf("No slots available.");
    }

    printf("\n=====================================\n");
}