#include <stdio.h>
#include <string.h>

#include "vehicle.h"
#include "parking.h"
#include "queue.h"
#include "stack.h"

#define DATA_FILE "data/parking_data.txt"

Queue waitingQueue;
Stack parkingHistory;

void clearInputBuffer() {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF);
}

void inputVehicle(Vehicle *vehicle) {
    printf("\nEnter Vehicle Number: ");
    scanf("%19s", vehicle->vehicleNumber);

    clearInputBuffer();

    printf("Enter Owner Name: ");
    fgets(vehicle->ownerName, OWNER_NAME_LENGTH, stdin);
    vehicle->ownerName[strcspn(vehicle->ownerName, "\n")] = '\0';

    printf("Enter Vehicle Type: ");
    fgets(vehicle->vehicleType, VEHICLE_TYPE_LENGTH, stdin);
    vehicle->vehicleType[strcspn(vehicle->vehicleType, "\n")] = '\0';

    vehicle->slotNumber = -1;
}

void saveVehicleToFile(Vehicle vehicle) {
    FILE *file = fopen(DATA_FILE, "a");

    if (file == NULL) {
        return;
    }

    fprintf(file, "%s|%s|%s|%d\n",
            vehicle.vehicleNumber,
            vehicle.ownerName,
            vehicle.vehicleType,
            vehicle.slotNumber);

    fclose(file);
}

void parkVehicleMenu() {
    Vehicle vehicle;

    inputVehicle(&vehicle);

    if (findVehicleSlot(vehicle.vehicleNumber) != -1) {
        printf("\nVehicle is already parked.\n");
        return;
    }

    int slot = parkVehicle(vehicle);

    if (slot != -1) {
        vehicle.slotNumber = slot;

        push(&parkingHistory, vehicle);
        saveVehicleToFile(vehicle);

        printf("\nVehicle parked successfully!");
        printf("\nAssigned Slot: %d\n", slot);
    } else {
        if (enqueue(&waitingQueue, vehicle)) {
            printf("\nParking is full.");
            printf("\nVehicle added to waiting queue.\n");
        } else {
            printf("\nParking and waiting queue are both full.\n");
        }
    }
}

void removeVehicleMenu() {
    int slotNumber;

    printf("\nEnter Slot Number to remove vehicle: ");
    scanf("%d", &slotNumber);

    Vehicle vehicle = removeVehicle(slotNumber);

    if (vehicle.slotNumber == -1) {
        printf("\nInvalid slot or slot is already empty.\n");
        return;
    }

    printf("\nVehicle removed successfully.");
    printf("\nVehicle Number: %s", vehicle.vehicleNumber);
    printf("\nOwner Name: %s\n", vehicle.ownerName);

    if (!isQueueEmpty(&waitingQueue)) {
        Vehicle waitingVehicle = dequeue(&waitingQueue);

        int newSlot = parkVehicle(waitingVehicle);

        if (newSlot != -1) {
            waitingVehicle.slotNumber = newSlot;

            push(&parkingHistory, waitingVehicle);
            saveVehicleToFile(waitingVehicle);

            printf("\nWaiting vehicle automatically assigned.");
            printf("\nVehicle: %s", waitingVehicle.vehicleNumber);
            printf("\nNew Slot: %d\n", newSlot);
        }
    }
}

void searchVehicleMenu() {
    char vehicleNumber[VEHICLE_NUMBER_LENGTH];

    printf("\nEnter Vehicle Number: ");
    scanf("%19s", vehicleNumber);

    int slot = findVehicleSlot(vehicleNumber);

    if (slot != -1) {
        printf("\nVehicle Found!");
        printf("\nVehicle Number: %s", vehicleNumber);
        printf("\nParking Slot: %d\n", slot);
    } else {
        printf("\nVehicle not found in parking area.\n");
    }
}

void showMenu() {
    printf("\n\n========================================");
    printf("\n       SMART PARKING SLOT MANAGER");
    printf("\n========================================");
    printf("\n1. Park Vehicle");
    printf("\n2. Remove Vehicle");
    printf("\n3. Display Parking Slots");
    printf("\n4. Search Vehicle");
    printf("\n5. Show Waiting Queue");
    printf("\n6. Show Parking History");
    printf("\n7. Show Available Slots");
    printf("\n8. Exit");
    printf("\n========================================");
    printf("\nEnter your choice: ");
}

int main() {
    int choice;

    initializeParking();
    initializeQueue(&waitingQueue);
    initializeStack(&parkingHistory);

    printf("\n========================================");
    printf("\n   SMART PARKING SLOT MANAGEMENT SYSTEM");
    printf("\n========================================\n");

    do {
        showMenu();

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                parkVehicleMenu();
                break;

            case 2:
                removeVehicleMenu();
                break;

            case 3:
                displayParkingSlots();
                break;

            case 4:
                searchVehicleMenu();
                break;

            case 5:
                displayQueue(&waitingQueue);
                break;

            case 6:
                displayHistory(&parkingHistory);
                break;

            case 7:
                displayAvailableSlots();
                break;

            case 8:
                printf("\nThank you for using Smart Parking System!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}