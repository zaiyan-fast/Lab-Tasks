#include <stdio.h>
#include <string.h>

typedef struct {
    char flightNumber[10];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[10];
    char arrivalTime[10];
    int availableSeats;
} Flight;

Flight flights[10];
int flightCount = 0;

void addFlight(char flightNumber[], char departureCity[], char arrivalCity[],
               char departureTime[], char arrivalTime[], int availableSeats) {
    if (flightCount < 10) {
        strcpy(flights[flightCount].flightNumber, flightNumber);
        strcpy(flights[flightCount].departureCity, departureCity);
        strcpy(flights[flightCount].arrivalCity, arrivalCity);
        strcpy(flights[flightCount].departureTime, departureTime);
        strcpy(flights[flightCount].arrivalTime, arrivalTime);
        flights[flightCount].availableSeats = availableSeats;
        flightCount++;
    } else {
        printf("Flight list is full");
    }
}

void bookSeat(char flightNumber[]) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked on flight %s. Remaining seats: %d\n",
                       flightNumber, flights[i].availableSeats);
            } else {
                printf("No seats available on flight %s.\n", flightNumber);
            }
            return;
        }
    }
    printf("Flight %s not found.\n", flightNumber);
}

void displayAvailableFlights(char departureCity[], char arrivalCity[]) {
    printf("Available flights from %s to %s:\n", departureCity, arrivalCity);
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, departureCity) == 0 &&
            strcmp(flights[i].arrivalCity, arrivalCity) == 0) {
            printf("Flight Number: %s, Departure Time: %s, Arrival Time: %s, Available Seats: %d\n",
                   flights[i].flightNumber, flights[i].departureTime,
                   flights[i].arrivalTime, flights[i].availableSeats);
            found = 1;
        }
    }
    if (!found) {
        printf("No flights found");
    }
}

void updateFlightDetails(char flightNumber[], char newDepartureTime[],
                         char newArrivalTime[]) {
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNumber) == 0) {
            strcpy(flights[i].departureTime, newDepartureTime);
            strcpy(flights[i].arrivalTime, newArrivalTime);
            printf("Flight %s updated. New Departure Time: %s, New Arrival Time: %s\n",
                   flightNumber, newDepartureTime, newArrivalTime);
            return;
        }
    }
    printf("Flight %s not found", flightNumber);
}

int main() {
    addFlight("PK101", "Karachi", "Lahore", "09:00", "11:00", 50);
    addFlight("PK102", "Karachi", "Islamabad", "10:00", "12:30", 40);
    addFlight("PK103", "Lahore", "Karachi", "15:00", "17:00", 30);

    displayAvailableFlights("Karachi", "Lahore");

    bookSeat("PK101");

    updateFlightDetails("PK101", "09:30", "11:30");

    displayAvailableFlights("Karachi", "Lahore");

    return 0;
}
