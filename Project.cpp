#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int id;
	char pName[20];
	int priority;
	float BT; 
}Process;
int count=0;
Process table[50];
void Add()
{
	printf("Enter process-&d details\n",count+1);
	printf("Enter Pid\n");
	scanf("%d",&table[count].id);
	printf("Enter process name\n");
	scanf("%s",table[count].pName);
	printf("Enter priority\n");
	scanf("%d",&table[count].priority);
	printf("Enter BT\n");
	scanf("%f",&table[count].BT);
	count++;
}
void Display()
{
	int i;
	for(i=0;i<=count;i++)
	{
	printf("\nprocess-%d\n",i+1);
	printf("\nPid=%d\tPname=%s\tpriority=%d\tBT=%f\n",table[i].id,table[i].pName,table[i].priority,table[i].BT);
	}
}
void BubbleSortByPriority()
{
	int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(table[j].priority>table[j+1].priority)
			{
				int temp=table[j].priority;
				table[j].priority=table[j+1].priority;
				table[j+1].priority=temp;
			}
		}
	}
}
void InsertionSortByPid()
{
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
    printf("\nTable sorted by PID using Insertion Sort.\n");
}

void ShellSortByBT()
{
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
    printf("\nTable sorted by BT using Shell Sort.\n");
}

void LinearSearchByPid()
{
    int searchId, found = 0;
    printf("Enter Pid to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (table[i].id == searchId) {
            printf("\nProcess Found at index %d:\nID: %d | Name: %s | BT: %.2f\n", 
                    i, table[i].id, table[i].pName, table[i].BT);
            found = 1;
            break;
        }
    }
    if (!found) printf("\nProcess with ID %d not found.\n", searchId);
}

void BinarySearchByPid()
{
    InsertionSortByPid(); 

    int low = 0, high = count - 1, searchId;
    printf("Enter Pid to search (Binary): ");
    scanf("%d", &searchId);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (table[mid].id == searchId) {
            printf("\nProcess Found:\nID: %d | Name: %s | BT: %.2f\n", 
                    table[mid].id, table[mid].pName, table[mid].BT);
            return;
        }
        if (table[mid].id < searchId)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\nProcess not found.\n");
}
main()
{
	while(1){
	printf("1.Add\n2.Display\n3.BubbleSortByPriority\n4.InsertionSortByPid\n5.ShellSortByBT\n6.LinearSearchByPid\n7.BinarySearchByPid\n");
	int choice;
	printf("Enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:Add();break;
		case 2:Display();break;
		case 3:BubbleSortByPriority();break;
		case 4:InsertionSortByPid();break;
		case 5:ShellSortByPid();break;
		case 6:LinearSearchByPid();break;
		case 7:printf("come here after sorting");
				BinarySearchByPid();break;
		case 8:exit(0);break;
	}
}
}

