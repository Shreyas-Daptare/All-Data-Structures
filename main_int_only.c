#include <stdio.h>
//#define linux
void clear()
{
	#ifdef linux
    system("clear");
    #else
    system("cls");
    #endif
}
void linear_search()
{
	printf("Linear Search \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int n[100], size, ele, i, flag=0;
	
	printf("Enter the size of the array:");
	scanf("%d", &size);
	
	printf("\nEnter the %d elements:\n", size);
	for(i=0;i<size;i++)
	{
		printf("Enter element %d:", i+1);
		scanf("%d", &n[i]);	
	}
	
	printf("\nEntered elements are:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
	
	printf("\n\nEnter the element you want to search:");
	scanf("%d", &ele);
	
	for(i=0;i<size;i++)
	{
		if(n[i]==ele)
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

void binary_search()
{
	printf("Binary Search \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int n[100], size, ele, i, j, mid, lowr, highr, flag=0, temp;
	
	printf("Enter the size of the array:");
	scanf("%d", &size);
	
	printf("\nEnter the %d elements:\n", size);
	for(i=0;i<size;i++)
	{
		printf("Enter element %d:", i+1);
		scanf("%d", &n[i]);	
	}
	
	for(i=size-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(n[j]>n[j+1])
			{
				temp=n[j];
				n[j]=n[j+1];
				n[j+1]=temp;
			}
		}
	}
	
	printf("\nEntered elements after sorting are:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
	
	printf("\n\nEnter the element you want to search:");
	scanf("%d", &ele);
	
	lowr=0;
	highr=size-1;
	while(lowr<=highr)
	{
		mid=(lowr+highr)/2;
		
		if(ele==n[mid])
		{
			printf("Element found at position %d\n", mid+1);
			flag++;
			break;
		}
		else if(ele>n[mid])
		{
			lowr=mid+1;
		}
		else if(ele<n[mid])
		{
			highr=mid-1;
		}
	}
	if(flag==0)
		printf("Element not found\n");
}

void bubble_sort()
{
	printf("Bubble Sort \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int n[100], size, i, j, temp;
	
	printf("Enter the size of the array:");
	scanf("%d", &size);
	
	printf("\nEnter the %d elements:\n", size);
	for(i=0;i<size;i++)
	{
		printf("Enter element %d:", i+1);
		scanf("%d", &n[i]);	
	}
	
	printf("\nEntered elements before sorting:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
	
	for(i=size-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(n[j]>n[j+1])
			{
				temp=n[j];
				n[j]=n[j+1];
				n[j+1]=temp;
			}
		}
	}
	
	printf("\n\nEntered elements after bubble sort:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
}

void insertion_sort()
{
	printf("Insertion Sort \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int n[100], i, j, key, size;
	
	printf("Enter the size of the array:");
	scanf("%d", &size);
	
	printf("\nEnter the %d elements:\n", size);
	for(i=0;i<size;i++)
	{
		printf("Enter element %d:", i+1);
		scanf("%d", &n[i]);	
	}
	
	printf("\nEntered elements before sorting:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
	
	for(i=1;i<size;i++)
	{
		key=n[i];
		j=i-1;
		
		while(j>=0 && n[j]>key)
		{
			n[j+1]=n[j];
			j--;
		}
		
		n[j+1]=key;
	}
	
	printf("\nEntered elements after insertion sort:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
}
void selection_sort()
{
	
	printf("Selection Sort \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int n[100], size, i, j, temp;
	
	printf("Enter the size of the array:");
	scanf("%d", &size);
	
	printf("\nEnter the %d elements:\n", size);
	for(i=0;i<size;i++)
	{
		printf("Enter element %d:", i+1);
		scanf("%d", &n[i]);	
	}
	
	printf("\nEntered elements before sorting:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
	
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(n[i]>n[j])
			{
				temp=n[i];
				n[i]=n[j];
				n[j]=temp;
			}
		}
	}
	
	printf("\n\nEntered elements after selection sort:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t", n[i]);
	}
}

void radix_sort()
{
	printf("Radix Sort \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
   int get_max (int a[], int n)
   {
   int i;
   int max = a[0];
   for (i = 1; i < n; i++)
      if (a[i] > max)
         max = a[i];
   return max;
	}
   int i, n, a[10];
   printf ("Enter the number of items to be sorted: ");
   scanf ("%d", &n);
   printf ("Enter items: ");
   for (i = 0; i < n; i++){
      scanf ("%d", &a[i]);
   }
   int bucket[10][10], bucket_cnt[10];
   int j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (a, n);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < n; i++){
         r = (a[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = a[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            a[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
      printf ("After pass %d : ", pass + 1);
      for (i = 0; i < n; i++)
         printf ("%d ", a[i]);
      printf ("\n");
   }
   printf ("Sorted items : ");
   for (i = 0; i < n; i++)
      printf ("%d ", a[i]);
   printf ("\n");	
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
    printf("1: Searching Techniques\n");
    printf("2: Sorting Techniques\n");
    printf("3: Linear Data Structures\n");
    printf("4: Non-Linear Data Structures\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("Choice: ");
    scanf("%d",&main_choice);
    clear();
    switch (main_choice)
    {
        case 1:
            printf("  Searching Techniques\n\n");
            printf("1: Linear Search Implementation\n");
            printf("2: Binary Search Implementation\n");
            printf("3: Return to main menu\n\n");
            printf("Choice: ");
            scanf("%d",&sub_choice);
    		switch(sub_choice)
    			{
    				case 1:
							//linear search code;
							clear();
							linear_search();
							break;
					case 2:
							//binary search code;
							clear();
							binary_search();
							break;
					case 3:
						printf("Exiting to Main Menu...");
						break;
				}
            break;
        case 2:
            printf("  Sorting Techniques\n\n");
            printf("1: Bubble Sort\n");
            printf("2: Insertion Sort\n");
            printf("3: Selection Sort\n");
            printf("4: Radix Sort\n");
            printf("5: Quick Sort\n");
            printf("6: Return to Main Menu\n\n");
            printf("Choice: ");
            scanf("%d",&sub_choice);
    		switch(sub_choice)
    			{
    				case 1:
							//Bubble sort;
							clear();
							bubble_sort();
							break;
					case 2:
							//Insertion sort;
							clear();
							insertion_sort();
							break;
					case 3:
							//Selection sort;
							clear();
							selection_sort();
							break;
					case 4:
							//Radix sort
							clear();
							radix_sort();
							break;
					case 5: 
							//Quick sort
							clear();
							break;
					case 6:
						printf("Exiting to Main Menu...");
						break;
				}
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
