#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int id;
    char pName[20];
    int priority;
    float BT; 
} Process;

int count = 0;
Process table[50];

void Add() {
    printf("Enter process-%d details\n", count + 1);
    printf("Enter Pid: ");
    scanf("%d", &table[count].id);
    printf("Enter process name: ");
    scanf("%s", table[count].pName);
    printf("Enter priority: ");
    scanf("%d", &table[count].priority);
    printf("Enter BT: ");
    scanf("%f", &table[count].BT);
    count++;
}

void Display() {
    int i;
    // Fixed: changed <= to <
    for(i = 0; i < count; i++) {
        printf("\nProcess-%d\n", i + 1);
        printf("Pid=%d\tPname=%s\tPriority=%d\tBT=%.2f\n", 
               table[i].id, table[i].pName, table[i].priority, table[i].BT);
    }
}

void BubbleSortByPriority() {
    int i, j;
    for(i = 0; i < count - 1; i++) {
        for(j = 0; j < count - i - 1; j++) {
            if(table[j].priority > table[j+1].priority) {
                // FIXED: Swap the entire structure
                Process temp = table[j];
                table[j] = table[j+1];
                table[j+1] = temp;
            }
        }
    }
    printf("\nSorted by Priority using Bubble Sort.\n");
}

void InsertionSortByPid() {
    int i, j;
    Process key;
    for (i = 1; i < count; i++) {
        key = table[i];
        j = i - 1;
        while (j >= 0 && table[j].id > key.id) {
            table[j + 1] = table[j];
            j = j - 1;
        }
        table[j + 1] = key;
    }
    printf("\nSorted by PID using Insertion Sort.\n");
}


void ShellSortByBT() {
    for (int gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; i++) {
            Process temp = table[i];
            int j;
            for (j = i; j >= gap && table[j - gap].BT > temp.BT; j -= gap) {
                table[j] = table[j - gap];
            }
            table[j] = temp;
        }
    }
    printf("\nSorted by BT using Shell Sort.\n");
}

void LinearSearchByPid() {
    int searchId, found = 0;
    printf("Enter Pid to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < count; i++) {
        if (table[i].id == searchId) {
            printf("\nFound: %s (ID: %d)\n", table[i].pName, table[i].id);
            found = 1;
            break;
        }
    }
    if (!found) printf("Not found.\n");
}


void BinarySearchByPid() {
    InsertionSortByPid(); // Must be sorted first
    int low = 0, high = count - 1, searchId;
    printf("Enter Pid to search: ");
    scanf("%d", &searchId);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (table[mid].id == searchId) {
            printf("\nFound: %s (ID: %d)\n", table[mid].pName, table[mid].id);
            return;
        }
        if (table[mid].id < searchId) low = mid + 1;
        else high = mid - 1;
    }
    printf("Not found.\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n1.Add\n2.Display\n3.BubbleSortByPriority\n4.InsertionSortByPid\n5.ShellSortByBT\n6.LinearSearchByPid\n7.BinarySearchByPid\n8.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: Add(); break;
            case 2: Display(); break;
            case 3: BubbleSortByPriority(); break;
            case 4: InsertionSortByPid(); break;
            case 5: ShellSortByBT(); break;
            case 6: LinearSearchByPid(); break;
            case 7: BinarySearchByPid(); break;
            case 8: exit(0);
        }
    }
    return 0;
}
