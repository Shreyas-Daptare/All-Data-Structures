#include <stdio.h>
#define linux

void 
void **create_array(int ele_size, int size)
{
    void **ptr=calloc(size, ele_size);
    return ptr;
}

void linear_search(const char *format, void **arrayptr, int size, void *search_ptr)
{
    if(strcmp(format, "int"))
    {
        int **array=(int **)arrayptr;
        int search=*((int*)search_ptr);
    }
    else if(strcmp(format, "float"))
    {
        float **array=(float **)arrayptr;
        float search=*((float*)search_ptr);
    }
    else if(strcmp(format, "char"))
    {
        char **array=(char **)arrayptr;
        char search=*((char*)search_ptr);
    }

    int flag=0;

    for(int i=0;i<size;i++)
	{
		if(array[i]==search)
		{
			printf("Element found at position %d\n", i+1);
			flag++;
		}
	}
	if(flag==0)
	{
		printf("Element not found\n");
	}
}

void binary_search(const char *format, void **arrayptr, int size, void *search_ptr)
{
    if(strcmp(format, "int"))
    {
        int **array=(int **)arrayptr;
        int search=*((int*)search_ptr);
    }
    else if(strcmp(format, "float"))
    {
        float **array=(float **)arrayptr;
        float search=*((float*)search_ptr);
    }
    else if(strcmp(format, "char"))
    {
        char **array=(char **)arrayptr;
        char search=*((char*)search_ptr);
    }

    int mid, lowr, highr, flag=0;

    lowr=0;
    highr=size-1;

    while(lowr<=highr)
	{
		mid=(lowr+highr)/2;
		
		if(search==array[mid])
		{
			printf("Element found at position %d\n", mid+1);
			flag++;
			break;
		}
		else if(search>array[mid])
		{
			lowr=mid+1;
		}
		else if(search<array[mid])
		{
			highr=mid-1;
		}
	}
	if(flag==0)
		printf("Element not found\n");
}

int main()
{
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                   Implement all types of Data Structures\n\n");
    printf("                                              Made by NEXUS\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n\n");
    int main_choice, sub_choice;
    char datatyp[5];
    printf("1] Searching Techniques\n");
    printf("2] Sorting Techniques\n");
    printf("3] Linear Data Structures\n");
    printf("4] Non-Linear Data Structures\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("Choice: ");
    scanf("%d",&main_choice);
    #ifdef linux
    system("clear");
    #else
    system("cls");
    #endif
    switch (main_choice)
    {
        case 1:
            printf("  Searching Techniques\n\n");
            printf("0: Linear Search Implementation\n");
            printf("1: Binary Search Implementation\n");
            printf("2: Return to main menu");
            printf("Choice: ");
            scanf("%d",&sub_choice);
               scanf()
                    printf("Enter datatype of Array");
                    scanf("%c",&temp);
                    if(strcmp(temp,"int")==0)
                    {
                        
                    }
                    else(strcmp(temp,"float")==0)
                    {
                        
                    }
                    printf("Enter Element");
                    linear  
            switch(sub_choice)
            {
                case 0: 
                 
            }

            break;
        case 2:
            printf("  Sorting Techniques\n");
            printf("1: Bubble Sort\n");
            printf("2: Insertion Sort\n");
            printf("3: Selection Sort\n");
            printf("4: Radix Sort\n");
            printf("5: Quick Sort\n");
            break;
        case 3:
            printf("  Linear Data Structures\n");
            printf("1: Array\n");
            printf("2: Stack\n");
            printf("3: Queue\n");
            printf("4: Linked List\n");
            printf("5: Quick Sort\n");
            break;
        case 4:
            printf("  Non-Linear Data Structures\n");
            printf("1: Tree\n");
            printf("2: Graph\n");
            break;
    }
    return 0;
}
