/* Write a program to Create ticket booking system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SEATS 50
#define PRICE_PER_TICKET 12.50

struct Booking {
    int bookingId;
    char passengerName[50];
    int seatNumber;
};

int seats[TOTAL_SEATS] = {0};
struct Booking bookings[TOTAL_SEATS];
int totalBookings = 0;
int nextBookingId = 101;

void displayMenu();
void viewSeats();
void bookTicket();
void cancelTicket();
void viewBookings();

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting program.\n");
            break;
        }
        switch (choice) {
            case 1:
                viewSeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                viewBookings();
                break;
            case 5:
                printf("\nThank you for using the Ticket Booking System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please choose a option between 1 and 5.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=================================");
    printf("\n     TICKET BOOKING SYSTEM       ");
    printf("\n=================================");
    printf("\n1. View Seating Chart");
    printf("\n2. Book a Ticket");
    printf("\n3. Cancel a Ticket");
    printf("\n4. View Active Bookings");
    printf("\n5. Exit System");
    printf("\n=================================\n");
}

void viewSeats() {
    printf("\n----- SEATING CHART (Total: %d) -----\n", TOTAL_SEATS);
    printf("[X] = Booked   [Seat No.] = Available\n\n");

    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0) {
            printf("%02d\t", i + 1); 
        } else {
            printf("[X]\t"); 
        }
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("-------------------------------------\n");
}

void bookTicket() {
    int seatNo;
    printf("\n--- BOOK A TICKET ---");
    printf("\nEnter preferred seat number (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);
    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("\nError: Seat number %d does not exist.\n", seatNo);
        return;
    }
    if (seats[seatNo - 1] == 1) {
        printf("\nError: Seat %d is already taken!\n", seatNo);
        return;
    }
    struct Booking newBooking;
    newBooking.bookingId = nextBookingId++;
    newBooking.seatNumber = seatNo;

    printf("Enter passenger name: ");
    getchar(); 
    fgets(newBooking.passengerName, sizeof(newBooking.passengerName), stdin);
    newBooking.passengerName[strcspn(newBooking.passengerName, "\n")] = 0; 
    seats[seatNo - 1] = 1;
    bookings[totalBookings++] = newBooking;
    printf("\n=================================");
    printf("\n      BOOKING CONFIRMED          ");
    printf("\n=================================");
    printf("\nBooking ID    : %d", newBooking.bookingId);
    printf("\nPassenger Name: %s", newBooking.passengerName);
    printf("\nSeat Assigned : %d", newBooking.seatNumber);
    printf("\nTotal Cost    : $%.2f", PRICE_PER_TICKET);
    printf("\n=================================\n");
}

void cancelTicket() {
    int id, foundIndex = -1;
    printf("\n--- CANCEL A TICKET ---");
    printf("\nEnter your Booking ID to cancel: ");
    scanf("%d", &id);
    for (int i = 0; i < totalBookings; i++) {
        if (bookings[i].bookingId == id) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        printf("\nError: Booking ID %d not found.\n", id);
        return;
    }
    int targetedSeat = bookings[foundIndex].seatNumber;
    seats[targetedSeat - 1] = 0;
    for (int i = foundIndex; i < totalBookings - 1; i++) {
        bookings[i] = bookings[i + 1];
    }
    totalBookings--;
    printf("\nSuccess: Ticket for Booking ID %d (Seat %d) has been canceled.\n", id, targetedSeat);
}

void viewBookings() {
    printf("\n--- ACTIVE BOOKINGS REGISTRY ---\n");
    if (totalBookings == 0) {
        printf("No active reservations found at the moment.\n");
        return;
    }
    printf("ID\t\tSeat\t\tPassenger Name\n");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < totalBookings; i++) {
        printf("%d\t\t%d\t\t%s\n", bookings[i].bookingId, bookings[i].seatNumber, bookings[i].passengerName);
    }
}
