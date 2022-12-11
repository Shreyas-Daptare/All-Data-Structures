#include <stdio.h>
#include <conio.h>

int main()
{
printf("-----------------------------------------------------------------------------------------------------------------\n");
printf("-----------------------------------------------------------------------------------------------------------------\n\n");
printf("                                   Implement all types of Data Structure\n\n");
printf("                                              Made by NEXUS\n");
printf("-----------------------------------------------------------------------------------------------------------------\n");
printf("-----------------------------------------------------------------------------------------------------------------\n\n");
int main_choice;
printf("1] Searching Techniques\n");
printf("2] Sorting Techniques\n");
printf("3] Linear Data Structures\n");
printf("4] Non-Linear Data Structures\n\n");
printf("-----------------------------------------------------------------------------------------------------------------\n");
printf("Choice: ");
scanf("%d",&main_choice);
system("cls");
switch (main_choice)
{
case 1:
    printf("0: Linear Search Implementation\n");
    printf("1: Binary Search Implementation\n");
    break;
case 2:
    printf("1: Bubble Sort\n");
    printf("2: Insertion Sort\n");
    printf("3: Selection Sort\n");
    printf("4: Radix Sort\n");
    printf("5: Quick Sort\n");
    break;
case 3:
    printf("1: Array\n");
    printf("2: Stack\n");
    printf("3: Queue\n");
    printf("4: Linked List\n");
    printf("5: Quick Sort\n");
    break;
case 4:
    printf("1: Tree\n");
    printf("2: Graph\n");
    break;
}
return 0;
}

