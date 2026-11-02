#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define MAX_ORDER_LENGTH 100

char queue[MAX_SIZE][MAX_ORDER_LENGTH];
int front = -1;
int rear = -1;

void displayMainMenu();
void addOrder();
void removeOrder();
void listOrders();
void totalOrders();
int isEmpty();
int isFull();
void clearScreen();
void pauseScreen();

int main() {
    char option;

    printf("\n========================================\n");
    printf("  RESTAURANT ORDER MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    pauseScreen();

    // Main program loop - matches flowchart
    while(1) {
        displayMainMenu();

        printf("Enter your option: ");
        scanf(" %c", &option);
        getchar(); // Clear newline from buffer

        option = toupper(option);

        if(option == 'A') {
            addOrder();
        }
        else if(option == 'B') {
            removeOrder();
        }
        else if(option == 'C') {
            listOrders();
        }
        else if(option == 'D') {
            totalOrders();
        }
        else if(option == 'E') {
            clearScreen();
            printf("\n========================================\n");
            printf("       Exiting program...\n");
            printf("   Thank you for using the system!\n");
            printf("========================================\n\n");
            exit(0);
        }
        else {
            printf("\nInvalid option. Please try again.\n");
            pauseScreen();
        }
    }

    return 0;
}

void displayMainMenu() {
    clearScreen();
    printf("\n******************************************\n");
    printf("***************** WELCOME TO *****************\n");
    printf("***************** THE FLAVORFUL FORK *****************\n");
    printf("******************************************\n");
    printf("A: Add Order\n");
    printf("B: Remove Order\n");
    printf("C: List of Orders\n");
    printf("D: Total Number of Orders\n");
    printf("E: Quit or Logout\n");
    printf("******************************************\n\n");
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

void addOrder() {
    clearScreen();
    printf("\n==========================================\n");
    printf("           ADD ORDER                    \n");
    printf("==========================================\n\n");

    char orderName[MAX_ORDER_LENGTH];

    printf("Enter order name: ");
    fgets(orderName, MAX_ORDER_LENGTH, stdin);
    orderName[strcspn(orderName, "\n")] = 0;

    if(strlen(orderName) == 0) {
        printf("\nOrder name cannot be empty!\n");
        pauseScreen();
        return;
    }

    if(isFull()) {
        printf("\nQueue is full! Cannot add more orders.\n");
        pauseScreen();
        return;
    }

    if(front == -1) {
        front = 0;
    }
    rear++;
    strcpy(queue[rear], orderName);

    printf("\nOrder added successfully!\n");
    printf("Order: %s\n", orderName);
    printf("Position in queue: %d\n", rear - front + 1);
    pauseScreen();
}

void removeOrder() {
    clearScreen();
    printf("\n==========================================\n");
    printf("         REMOVE ORDER                   \n");
    printf("==========================================\n\n");

    if(isEmpty()) {
        printf("No orders to remove.\n");
        printf("Queue is empty!\n");
        pauseScreen();
        return;
    }

    printf("Removing order: %s\n", queue[front]);
    front++;

    if(front > rear) {
        front = -1;
        rear = -1;
        printf("\nFirst order removed successfully!\n");
        printf("Queue is now empty.\n");
    }
    else {
        printf("\nFirst order removed successfully!\n");
        printf("Orders remaining: %d\n", rear - front + 1);
    }

    pauseScreen();
}

void listOrders() {
    clearScreen();
    printf("\n==========================================\n");
    printf("        LIST OF ORDERS                  \n");
    printf("==========================================\n\n");

    if(isEmpty()) {
        printf("No orders in queue.\n");
        printf("Queue is empty!\n");
        pauseScreen();
        return;
    }

    printf("Current Orders in Queue:\n");
    printf("------------------------------------------\n");
    printf("%-5s %-35s\n", "No.", "Order Name");
    printf("------------------------------------------\n");

    for(int i = front; i <= rear; i++) {
        printf("%-5d %-35s\n", i - front + 1, queue[i]);
    }

    printf("------------------------------------------\n");
    printf("Total: %d order(s) in queue\n", rear - front + 1);
    pauseScreen();
}

void totalOrders() {
    clearScreen();
    printf("\n==========================================\n");
    printf("     TOTAL NUMBER OF ORDERS             \n");
    printf("==========================================\n\n");

    if(isEmpty()) {
        printf("Total orders: 0\n");
        printf("Queue is currently empty.\n");
    }
    else {
        int total = rear - front + 1;
        printf("Total orders in queue: %d\n", total);
        printf("\nQueue Status:\n");
        printf("First order (Front): %s\n", queue[front]);
        printf("Last order (Rear):   %s\n", queue[rear]);
    }

    pauseScreen();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
}
