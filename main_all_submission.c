/* Developers: Tanmay Bora, Shreyas Daptare, Jeevan Gharate, Durgesh Ghoderao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lx

#define INT 1
#define FLOAT 2 
#define CHAR 3
#define LIMIT 200
#define ASC 123
#define DESC 321
#define VERBOSE 1
#define NVERBOSE 0
#define BUBBLE 100
#define SELECTION 101
#define INSERTION 102

/* Base format for functions
int function(int format, void *array_ptr, int *top_ptr, void *val)
{
	switch(format)
	{
		case INT:
		{
			int *array=(int *)array_ptr;
			int val=*((int *)val);
		}
		case FLOAT:
		{
			float *array=(float *)array_ptr;
			float val=*((float *)val);
		}
		case CHAR:
		{
			char *array=(char *)array_ptr;
		 	char val=*((char *)val);
		}
	}
} */

void clean_stdin(void)
{
    int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen()
{
    #ifdef lx
	system("clear");
    #else
	system("cls");
    #endif
}

void pause_screen()
{
	clean_stdin();
	printf("\nPress enter to continue\n");
	getchar();
}

void *create_array(int format, int size)
{
	int ele_size;
	switch(format)
	{
		case INT:
			ele_size=4;
			break;
		case FLOAT:
			ele_size=4;
			break;
		case CHAR:
			ele_size=1;
			break;
	}
    void *ptr=calloc(size, ele_size);
    return ptr;
}

int read_array(int format, void *arrayptr, int size)
{
	int i;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arrayptr;
			for(i=0;i<size;i++)
			{
				scanf("%d", &array[i]);
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arrayptr;
			for(i=0;i<size;i++)
			{
				scanf("%f", &array[i]);
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arrayptr;
			for(i=0;i<size;i++)
			{
				scanf(" %c", &array[i]);
			}
			break;
		}
	}
	return i;
}

int display_array(int format, void *arrayptr, int size)
{
	int i;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arrayptr;
			for(i=0;i<size;i++)
			{
				printf("%d\t", array[i]);
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arrayptr;
			for(i=0;i<size;i++)
			{
				printf("%f\t", array[i]);
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arrayptr;
			for(i=0;i<size;i++)
			{
				printf("%c\t", array[i]);
			}
			break;
		}
	}
	return i;
}

int get_datatype()
{
    char datatype[6];
	do
	{
		printf("Enter the type of data you want to store(int or float or char):");
    	scanf(" %s", datatype);
    	if(strcmp(datatype, "int")==0)
			return INT;
    	else if(strcmp(datatype, "float")==0)
			return FLOAT;
		else if(strcmp(datatype, "char")==0)
			return CHAR;
		else 
			printf("Enter a valid datatype!\n");
	} while(1);
}

int get_array_size()
{
	int size;
	do
	{
		printf("Enter array size(valid size:1-200):");
		scanf("%d", &size);
		if(size<=LIMIT && size>0)
			printf("\nSetting array size=%d", size);
		else
			printf("\nSize beyond Limit(1-200), please enter a valid size!\n");
	} while(size>200 || size<1);

	return size;
}

int get_stack_size()
{
	int size;
	do
	{
		printf("Enter Stack size(valid size:1-200):");
		scanf("%d", &size);
		if(size<=LIMIT && size>0)
			printf("\nSetting Stack size=%d", size);
		else
			printf("\nSize beyond Limit(1-200), please enter a valid size!\n");
	} while(size>200 || size<1);

	return size;
}

int get_queue_size()
{
	int size;
	do
	{
		printf("Enter Queue size(valid size:1-200):");
		scanf("%d", &size);
		if(size<=LIMIT && size>0)
			printf("\nSetting Queue size=%d", size);
		else
			printf("\nSize beyond Limit(1-200), please enter a valid size!\n");
	} while(size>200 || size<1);

	return size;
}

int get_order()
{
	char ch;
	do
	{
		printf("Enter Order for Sort(a - Ascending Order/d - Descending Order)? ");
		scanf(" %c", &ch);
		if(ch=='a' || ch=='A')
		{
			printf("Selected Ascending Order");
			return ASC;
		}
		else if(ch=='d' || ch=='D')
		{
			printf("Selected Descending Order");
			return DESC;
		}
		else
		{
			printf("Please a enter valid choice(A/D)!\n");
		}
	} while(ch!='a' || ch!='A' || ch!='d' || ch!='D');
}

int get_verbose()
{
	char ch;
	do
	{
		printf("Do you want to see the output after every iteration(y/n)? ");
		scanf(" %c", &ch);
		if(ch=='y')
		{
			printf("Verbose ON");
			return VERBOSE;
		}
		else if(ch=='n')
		{
			printf("Verbose OFF");
			return NVERBOSE;
		}
		else
		{
			printf("Please a enter valid choice(y/n)!\n");
		}
	} while (ch!='y' || ch!='n');		
}

void *push(int format, void *stack_ptr, int size, int *top_ptr, void *val_ptr)
{
	switch(format)
	{
		case INT:
		{
			int *stack=(int *)stack_ptr;
			int val=*((int *)val_ptr);
			if(*top_ptr==size-1)
			{
				return &stack[*top_ptr];
			}
			else
			{
				(*top_ptr)++;
				stack[*top_ptr]=val;
				return &stack[*top_ptr];
			}
			break;
		}
		case FLOAT:
		{
			float *stack=(float *)stack_ptr;
			float val=*((float *)val_ptr);
			if(*top_ptr==size-1)
			{
				return &stack[*top_ptr];
			}
			else
			{
				(*top_ptr)++;
				stack[*top_ptr]=val;
				return &stack[*top_ptr];
			}
			break;
		}
		case CHAR:
		{
			char *stack=(char *)stack_ptr;
		 	char val=*((char *)val_ptr);
			if(*top_ptr==size-1)
			{
				return &stack[*top_ptr];
			}
			else
			{
				(*top_ptr)++;
				stack[*top_ptr]=val;
				return &stack[*top_ptr];
			}
			break;
		}
	}
}

void *pop(int format, void *stack_ptr, int size, int *top_ptr, void *val_ptr)
{
	switch(format)
	{
		case INT:
		{
			int *stack=(int *)stack_ptr;
			if(*top_ptr==-1)
			{
				return &stack[*top_ptr];
			}
			else
			{
				*((int *)val_ptr)=stack[*top_ptr];
				(*top_ptr)--;
				return val_ptr;
			}
			break;
		}
		case FLOAT:
		{
			float *stack=(float *)stack_ptr;
			if(*top_ptr==-1)
			{
				return &stack[*top_ptr];
			}
			else
			{
				*((float *)val_ptr)=stack[*top_ptr];
				(*top_ptr)--;
				return val_ptr;
			}
			break;
		}
		case CHAR:
		{
			char *stack=(char *)stack_ptr;
			if(*top_ptr==-1)
			{
				return &stack[*top_ptr];
			}
			else
			{
				*((char *)val_ptr)=stack[*top_ptr];
				(*top_ptr)--;
				return val_ptr;
			}
			break;
		}
	}
}

int display_stack(int format, void *stack_ptr, int size, int *top_ptr)
{
	int i;
	switch(format)
	{
		case INT:
		{
			int *stack=(int *)stack_ptr;
			if(*top_ptr==-1)
			{
				return 0;
			}
			else
			{
				for(i=*top_ptr;i>=0;i--)
					printf("%d\n", stack[i]);
			}
			break;
		}
		case FLOAT:
		{
			float *stack=(float *)stack_ptr;
			if(*top_ptr==-1)
			{
				return 0;
			}
			else
			{
				for(i=*top_ptr;i>=0;i--)
					printf("%f\n", stack[i]);
			}
		}
		case CHAR:
		{
			char *stack=(char *)stack_ptr;
			if(*top_ptr==-1)
			{
				return 0;
			}
			else
			{
				for(i=*top_ptr;i>=0;i--)
					printf("%c\n", stack[i]);
			}
		}
	}
	return i;	
}

void *l_enqueue(int format, void *queue_ptr, int size, int *f_ptr, int *r_ptr, void *val_ptr)
{
	switch(format)
	{
		case INT:
		{
			int *queue=(int *)queue_ptr;
			int val=*((int *)val_ptr);
			if(*r_ptr==size-1)
			{
				return &queue[*r_ptr];
			}
			else if(*f_ptr==-1 && *r_ptr==-1)
			{
				*f_ptr=0;
				*r_ptr=0;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			else
			{
				(*r_ptr)++;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			break;
		}
		case FLOAT:
		{
			float *queue=(float *)queue_ptr;
			float val=*((float *)val_ptr);
			if(*r_ptr==size-1)
			{
				return &queue[*r_ptr];
			}
			else if(*f_ptr==-1 && *r_ptr==-1)
			{
				*f_ptr=0;
				*r_ptr=0;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			else
			{
				(*r_ptr)++;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			break;		
		}
		case CHAR:
		{
			char *queue=(char *)queue_ptr;
		 	char val=*((char *)val_ptr);
			if(*r_ptr==size-1)
			{
				return &queue[*r_ptr];
			}
			else if(*f_ptr==-1 && *r_ptr==-1)
			{
				*f_ptr=0;
				*r_ptr=0;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			else
			{
				(*r_ptr)++;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			break;
		}
	}
}

void *l_dequeue(int format, void *queue_ptr, int size, int *f_ptr, int *r_ptr, void *val_ptr)
{
	switch(format)
	{
		case INT:
		{
			int *queue=(int *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return &queue[*f_ptr];
			}
			else if(*f_ptr==*r_ptr)
			{
				*((int *)val_ptr)=queue[*f_ptr];
				*f_ptr=-1;
				*r_ptr=-1;
				return val_ptr;
			}
			else
			{
				*((int *)val_ptr)=queue[*f_ptr];
				(*f_ptr)++;
				return val_ptr;
			}
			break;
		}
		case FLOAT:
		{
			float *queue=(float *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return &queue[*f_ptr];
			}
			else if(*f_ptr==*r_ptr)
			{
				*((float *)val_ptr)=queue[*f_ptr];
				*f_ptr=-1;
				*r_ptr=-1;
				return val_ptr;
			}
			else
			{
				*((float *)val_ptr)=queue[*f_ptr];
				(*f_ptr)++;
				return val_ptr;
			}
			break;
		}
		case CHAR:
		{
			char *queue=(char *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return &queue[*f_ptr];
			}
			else if(*f_ptr==*r_ptr)
			{
				*((char *)val_ptr)=queue[*f_ptr];
				*f_ptr=-1;
				*r_ptr=-1;
				return val_ptr;
			}
			else
			{
				*((char *)val_ptr)=queue[*f_ptr];
				(*f_ptr)++;
				return val_ptr;
			}
			break;
		}
	}
}

void *c_enqueue(int format, void *queue_ptr, int size, int *f_ptr, int *r_ptr, void *val_ptr)
{
	switch(format)
	{
		case INT:
		{
			int *queue=(int *)queue_ptr;
			int val=*((int *)val_ptr);
			if((*r_ptr+1)%size==*f_ptr)
			{
				return &queue[*r_ptr];
			}
			else if(*f_ptr==-1 && *r_ptr==-1)
			{
				*f_ptr=0;
				*r_ptr=(*r_ptr+1)%size;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			else
			{
				*r_ptr=(*r_ptr+1)%size;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			break;
		}
		case FLOAT:
		{
			float *queue=(float *)queue_ptr;
			float val=*((float *)val_ptr);
			if((*r_ptr+1)%size==*f_ptr)
			{
				return &queue[*r_ptr];
			}
			else if(*f_ptr==-1 && *r_ptr==-1)
			{
				*f_ptr=0;
				*r_ptr=(*r_ptr+1)%size;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			else
			{
				*r_ptr=(*r_ptr+1)%size;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			break;
		}
		case CHAR:
		{
			char *queue=(char *)queue_ptr;
		 	char val=*((char *)val_ptr);
			if((*r_ptr+1)%size==*f_ptr)
			{
				return &queue[*r_ptr];
			}
			else if(*f_ptr==-1 && *r_ptr==-1)
			{
				*f_ptr=0;
				*r_ptr=(*r_ptr+1)%size;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			else
			{
				*r_ptr=(*r_ptr+1)%size;
				queue[*r_ptr]=val;
				return &queue[*r_ptr];
			}
			break;
		}
	}
}

void *c_dequeue(int format, void *queue_ptr, int size, int *f_ptr, int *r_ptr, void *val_ptr)
{
	switch(format)
	{
		case INT:
		{
			int *queue=(int *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return &queue[*f_ptr];
			}	
			else if(*f_ptr==*r_ptr)
			{
				*((int *)val_ptr)=queue[*f_ptr];
				*f_ptr=-1;
				*r_ptr=-1;
				return val_ptr;
			}
			else
			{
				*((int *)val_ptr)=queue[*f_ptr];
				*f_ptr=(*f_ptr+1)%size;
				return val_ptr;
			}
			break;
		}
		case FLOAT:
		{
			float *queue=(float *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return &queue[*f_ptr];
			}	
			else if(*f_ptr==*r_ptr)
			{
				*((float *)val_ptr)=queue[*f_ptr];
				*f_ptr=-1;
				*r_ptr=-1;
				return val_ptr;
			}
			else
			{
				*((float *)val_ptr)=queue[*f_ptr];
				*f_ptr=(*f_ptr+1)%size;
				return val_ptr;
			}
			break;
		}
		case CHAR:
		{
			char *queue=(char *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return &queue[*f_ptr];
			}	
			else if(*f_ptr==*r_ptr)
			{
				*((char *)val_ptr)=queue[*f_ptr];
				*f_ptr=-1;
				*r_ptr=-1;
				return val_ptr;
			}
			else
			{
				*((char *)val_ptr)=queue[*f_ptr];
				*f_ptr=(*f_ptr+1)%size;
				return val_ptr;
			}
			break;
		}
	}
}

int l_display_queue(int format, void *queue_ptr, int size, int *f_ptr, int *r_ptr)
{
	int i;
	switch(format)
	{
		case INT:
		{
			int *queue=(int *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return 0;
			}
			else
			{
				for(i=*f_ptr;i<=*r_ptr;i++)
					printf("%d\t", queue[i]);
			}
			break;
		}
		case FLOAT:
		{
			float *queue=(float *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return 0;
			}
			else
			{
				for(i=*f_ptr;i<=*r_ptr;i++)
					printf("%f\t", queue[i]);
			}
			break;
		}
		case CHAR:
		{
			char *queue=(char *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return 0;
			}
			else
			{
				for(i=*f_ptr;i<=*r_ptr;i++)
					printf("%c\t", queue[i]);
			}			
			break;
		}
	}
	return i;
}

int c_display_queue(int format, void *queue_ptr, int size, int *f_ptr, int *r_ptr)
{
	int i;
	switch(format)
	{
		case INT:
		{
			int *queue=(int *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return 0;
			}
			else
			{
				if(*f_ptr<*r_ptr)
				{
					for(i=*f_ptr;i<=*r_ptr;i++)
						printf("%d\t", queue[i]);
				}
				else
				{
					for(i=*f_ptr;i!=*r_ptr;i=(i+1)%size)
						printf("%d\t", queue[i]);

					printf("%d", queue[i]);
				}
			}
			break;
		}
		case FLOAT:
		{
			float *queue=(float *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return 0;
			}
			else
			{
				if(*f_ptr<*r_ptr)
				{
					for(i=*f_ptr;i<=*r_ptr;i++)
						printf("%f\t", queue[i]);
				}
				else
				{
					for(i=*f_ptr;i!=*r_ptr;i=(i+1)%size)
						printf("%f\t", queue[i]);

					printf("%f", queue[i]);
				}
			}
			break;
		}
		case CHAR:
		{
			char *queue=(char *)queue_ptr;
			if(*f_ptr==-1 && *r_ptr==-1)
			{
				return 0;
			}
			else
			{
				if(*f_ptr<*r_ptr)
				{
					for(i=*f_ptr;i<=*r_ptr;i++)
						printf("%c\t", queue[i]);
				}
				else
				{
					for(i=*f_ptr;i!=*r_ptr;i=(i+1)%size)
						printf("%c\t", queue[i]);

					printf("%c", queue[i]);
				}
			}
			break;
		}
	}
	return i;
}

void bubble_sort(int format, int size, void *arr_ptr, int order, int verbose)
{
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int i, j, k;
			int temp;
			if(order==ASC)
			{	
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]>array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]<array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			int i, j, k;
			float temp;
			if(order==ASC)
			{	
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]>array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]<array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			int i, j, k;
			char temp;
			if(order==ASC)
			{	
				for(i=size-1, k=1;i>0;i--, k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]>array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=size-1,k=1;i>0;i--,k++)
				{
					for(j=0;j<i;j++)
					{
						if(array[j]<array[j+1])
						{
							temp=array[j];
							array[j]=array[j+1];
							array[j+1]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", k);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
	}
}

void insertion_sort(int format, int size, void *arr_ptr, int order, int verbose)
{
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int i, j;
			int key;
			if(order==ASC)
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]>key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]<key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			int i,j;
			float key;
			if(order==ASC)
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]>key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]<key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			int i, j;
			char key;
			if(order==ASC)
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]>key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=1;i<size;i++)
				{
					key=array[i];
					j=i-1;
			
					while(j>=0 && array[j]<key)
					{
						array[j+1]=array[j];
						j--;
					}
					array[j+1]=key;
					if(verbose)
					{
						printf("Iteration %d: ", i);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
	}
}

void selection_sort(int format, int size, void *arr_ptr, int order, int verbose)
{
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int i, j;
			int temp;
			if(order==ASC)
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]>array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]<array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
					
				}
			}
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			int i,j;
			float temp;
			if(order==ASC)
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]>array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]<array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
					
				}
			}
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			int i,j;
			char temp;
			if(order==ASC)
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]>array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			else
			{
				for(i=0;i<size;i++)
				{
					for(j=i+1;j<size;j++)
					{
						if(array[i]<array[j])
						{
							temp=array[i];
							array[i]=array[j];
							array[j]=temp;
						}
					}
					if(verbose)
					{
						printf("Iteration %d: ", i+1);
						display_array(format, array, size);
						printf("\n");
					}
				}
			}
			break;
		}
	}
}

int linear_search(int format, int size, void *arr_ptr, void *search_ele)
{
	int flag=0;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int search=*((int *)search_ele);
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
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			float search=*((float *)search_ele);
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
			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			char search=*((char *)search_ele);
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
			break;
		}
	}
	return flag;
}

int binary_search(int format, int size, void *arr_ptr, void *search_ele)
{
	int flag=0;
	switch(format)
	{
		case INT:
		{
			int *array=(int *)arr_ptr;
			int search=*((int *)search_ele);
			int mid, lowr, highr, flag=0;
			//sorting the array before binary search
			insertion_sort(format, size, array, ASC, NVERBOSE);

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
			
			break;
		}
		case FLOAT:
		{
			float *array=(float *)arr_ptr;
			float search=*((float *)search_ele);
			int mid, lowr, highr, flag=0;
			//sorting the array before binary search
			insertion_sort(format, size, array, ASC, NVERBOSE);

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

			break;
		}
		case CHAR:
		{
			char *array=(char *)arr_ptr;
			char search=*((char *)search_ele);
			int mid, lowr, highr, flag=0;
			//sorting the array before binary search
			insertion_sort(format, size, array, ASC, NVERBOSE);

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
				
			break;
		}
	}
	return flag;
}

void create_and_LS()
{
	printf("Linear Search \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int arr_datatype=get_datatype();
	int arr_size=get_array_size();
	void *arr_ptr=create_array(arr_datatype, arr_size);
	printf("\nEnter the %d elements:\n", arr_size);
	clean_stdin();
	int ele_read=read_array(arr_datatype, arr_ptr, arr_size);
	printf("\n%d Elements read\n\n", ele_read);
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n\nEnter the element you want to search:");
	switch(arr_datatype)
	{
		case INT:
		{
			int search_ele;
			clean_stdin();
			scanf("%d", &search_ele);
			linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case FLOAT:
		{
			float search_ele;
			clean_stdin();
			scanf("%f", &search_ele);
			linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case CHAR:
		{
			char search_ele;
			clean_stdin();
			scanf("%c", &search_ele);
			linear_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
	}
}

void create_and_BS()
{
	printf("Binary Search \n\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	int arr_datatype=get_datatype();
	int arr_size=get_array_size();
	void *arr_ptr=create_array(arr_datatype, arr_size);
	printf("\nEnter the %d elements:\n", arr_size);
	clean_stdin();
	int ele_read=read_array(arr_datatype, arr_ptr, arr_size);
	printf("\n%d Elements read\n", ele_read);
	//sorting the array before binary search
	insertion_sort(arr_datatype, arr_size, arr_ptr, ASC, NVERBOSE);
	printf("\nArray Elements: (Note: The array elements are Sorted before Binary Search)\n");
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n\nEnter the element you want to search:");
	switch(arr_datatype)
	{
		case INT:
		{
			int search_ele;
			clean_stdin();
			scanf("%d", &search_ele);
			binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case FLOAT:
		{
			float search_ele;
			clean_stdin();
			scanf("%f", &search_ele);
			binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
		case CHAR:
		{
			char search_ele;
			clean_stdin();
			scanf("%c", &search_ele);
			binary_search(arr_datatype, arr_size, arr_ptr, &search_ele);
			break;
		}
	}
}

void create_and_sort(int sortmethod)
{
	int arr_datatype=get_datatype();
	int arr_size=get_array_size();
	void *arr_ptr=create_array(arr_datatype, arr_size);
	printf("\nEnter the %d elements:\n", arr_size);
	clean_stdin();
	int ele_read=read_array(arr_datatype, arr_ptr, arr_size);
	printf("\n%d Elements read\n\n", ele_read);
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n\n");
	int order=get_order();
	printf("\n");
	int verbose=get_verbose();
	printf("\n\n");
	switch(sortmethod)
	{
		case BUBBLE:
			bubble_sort(arr_datatype, arr_size, arr_ptr, order, verbose);
			printf("\nArray after Bubble Sort:\n");
			break;
		case SELECTION:
			selection_sort(arr_datatype, arr_size, arr_ptr, order, verbose);
			printf("\nArray after Selection Sort:\n");
			break;
		case INSERTION:
			insertion_sort(arr_datatype, arr_size, arr_ptr, order, verbose);
			printf("\nArray after Insertion Sort:\n");
			break;
	}
	display_array(arr_datatype, arr_ptr, arr_size);
	printf("\n");
}

void stack_operations()
{
	int stk_datatype=get_datatype();
	int stk_size=get_stack_size();
	void *stk_ptr=create_array(stk_datatype, stk_size);
	int top=-1;
	int choice;
	do
	{
		clean_stdin();
		printf("\nEnter the Stack operation you want to perform(1-push, 2-pop, 3-view, 4-exit):");
		scanf("%d", &choice);
		switch(stk_datatype)
		{
			case INT:
			{
				int val;
				switch(choice)
				{
					case 1:
						if(top==stk_size-1)
						{
							printf("Cannot perform push operation, stack is full\n");
						}
						else
						{
							printf("Enter the value you want to push:");
							scanf("%d", &val);
							val=*((int *)push(stk_datatype, stk_ptr, stk_size, &top, &val));
							printf("%d pushed to the stack\n", val);
						}
						break;
					case 2:
						if(top==-1)
						{
							printf("Cannot perform pop operation, stack is empty\n");
						}
						else
						{
							val=*((int *)pop(stk_datatype, stk_ptr, stk_size, &top, &val));
							printf("%d popped from the stack\n", val);
						}
						break;
					case 3:
						if(top==-1)
						{
							printf("The stack is empty\n");
						}
						else
						{
							printf("The elements in the stack are:\n");
							display_stack(stk_datatype, stk_ptr, stk_size, &top);
							printf("\n");
						}
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
			case FLOAT:
			{
				float val;
				switch(choice)
				{
					case 1:
						if(top==stk_size-1)
						{
							printf("Cannot perform push operation, stack is full\n");
						}
						else
						{
							printf("Enter the value you want to push:");
							scanf("%f", &val);
							val=*((float *)push(stk_datatype, stk_ptr, stk_size, &top, &val));
							printf("%f pushed to the stack\n", val);
						}
						break;
					case 2:
						if(top==-1)
						{
							printf("Cannot perform pop operation, stack is empty\n");
						}
						else
						{
							val=*((float *)pop(stk_datatype, stk_ptr, stk_size, &top, &val));
							printf("%f popped from the stack\n", val);
						}
						break;
					case 3:
						if(top==-1)
						{
							printf("The stack is empty\n");
						}
						else
						{
							printf("The elements in the stack are:\n");
							display_stack(stk_datatype, stk_ptr, stk_size, &top);
							printf("\n");
						}
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
			case CHAR:
			{
				char val;
				switch(choice)
				{
					case 1:
						if(top==stk_size-1)
						{
							printf("Cannot perform push operation, stack is full\n");
						}
						else
						{
							printf("Enter the value you want to push:");
							scanf(" %c", &val);
							val=*((char *)push(stk_datatype, stk_ptr, stk_size, &top, &val));
							printf("%c pushed to the stack\n", val);
						}
						break;
					case 2:
						if(top==-1)
						{
							printf("Cannot perform pop operation, stack is empty\n");
						}
						else
						{
							val=*((char *)pop(stk_datatype, stk_ptr, stk_size, &top, &val));
							printf("%c popped from the stack\n", val);
						}
						break;
					case 3:
						if(top==-1)
						{
							printf("The stack is empty\n");
						}
						else
						{
							printf("The Elements in the Stack are:\n");
							display_stack(stk_datatype, stk_ptr, stk_size, &top);
							printf("\n");
						}
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, Enter a valid choice\n");
				}
				break;
			}
		} 
	} while(choice!=4);
}

void l_queue_operations()
{
	int q_datatype=get_datatype();
	int q_size=get_queue_size();
	void *q_ptr=create_array(q_datatype, q_size);
	int front=-1;
	int rear=-1;
	int choice;
	do
	{
		clean_stdin();
		printf("\nEnter the operation you want to perform(1-enqueue, 2-dequeue, 3-display queue, 4-exit):");
		scanf("%d", &choice);
		switch(q_datatype)
		{
			case INT:
			{
				int val;
				switch(choice)
				{
					case 1:
						if(rear==q_size-1)
						{
							printf("Queue is full, cannot perform insertion\n");
						}
						else
						{
							printf("Enter the element you want to insert:");
							scanf("%d", &val);
							val=*((int *)l_enqueue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%d inserted in the queue\n", val);
						}
						break;
					case 2:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot perform deletion\n");
						}
						else
						{
							val=*((int *)l_dequeue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%d deleted\n", val);
						}
						break;
					case 3:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot display\n");
						}
						else
						{
							printf("The Elements in the Queue are:\n");
							l_display_queue(q_datatype, q_ptr, q_size, &front, &rear);
							printf("\n");
						}
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
			case FLOAT:
			{
				float val;
				switch(choice)
				{
					case 1:
						if(rear==q_size-1)
						{
							printf("Queue is full, cannot perform insertion\n");
						}
						else
						{
							printf("Enter the element you want to insert:");
							scanf("%f", &val);
							val=*((float *)l_enqueue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%f inserted in the queue\n", val);
						}
						break;
					case 2:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot perform deletion\n");
						}
						else
						{
							val=*((float *)l_dequeue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%f deleted\n", val);
						}
						break;
					case 3:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot display\n");
						}
						else
						{
							printf("The Elements in the Queue are:\n");
							l_display_queue(q_datatype, q_ptr, q_size, &front, &rear);
							printf("\n");
						}
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
			case CHAR:
			{
				char val;
				switch(choice)
				{
					case 1:
						if(rear==q_size-1)
						{
							printf("Queue is full, cannot perform insertion\n");
						}
						else
						{
							printf("Enter the element you want to insert:");
							scanf(" %c", &val);
							val=*((int *)l_enqueue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%c inserted in the queue\n", val);
						}
						break;
					case 2:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot perform deletion\n");
						}
						else
						{
							val=*((char *)l_dequeue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%c deleted\n", val);
						}
						break;
					case 3:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot display\n");
						}
						else
						{
							printf("The Elements in the Queue are:\n");
							l_display_queue(q_datatype, q_ptr, q_size, &front, &rear);
							printf("\n");
						}
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
		}
	} while(choice!=4);
}

void c_queue_operations()
{
	int q_datatype=get_datatype();
	int q_size=get_queue_size();
	void *q_ptr=create_array(q_datatype, q_size);
	int front=-1;
	int rear=-1;
	int choice;
	do
	{
		clean_stdin();
		printf("\nEnter the operation you want to perform(1-enqueue, 2-dequeue, 3-display queue, 4-exit):");
		scanf("%d", &choice);
		switch(q_datatype)
		{
			case INT:
			{
				int val;
				switch(choice)
				{
					case 1:
						if((rear+1)%q_size==front)
						{
							printf("Queue is full, cannot perform insertion\n");
						}
						else
						{
							printf("Enter the element you want to insert:");
							scanf("%d", &val);
							val=*((int *)c_enqueue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%d inserted in the queue\n", val);	
						}
						break;
					case 2:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot perform deletion\n");
						}
						else
						{
							val=*((int *)c_dequeue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%d deleted\n", val);
						}
						break;	
					case 3:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot display\n");
						}
						else
						{
							printf("The Elements in the Queue are:\n");
							c_display_queue(q_datatype, q_ptr, q_size, &front, &rear);
							printf("\n");
						}	
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
			case FLOAT:
			{
				float val;
				switch(choice)
				{
					case 1:
						if((rear+1)%q_size==front)
						{
							printf("Queue is full, cannot perform insertion\n");
						}
						else
						{
							printf("Enter the element you want to insert:");
							scanf("%f", &val);
							val=*((float *)c_enqueue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%f inserted in the queue\n", val);	
						}
						break;
					case 2:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot perform deletion\n");
						}
						else
						{
							val=*((float *)c_dequeue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%f deleted\n", val);
						}
						break;	
					case 3:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot display\n");
						}
						else
						{
							printf("The Elements in the Queue are:\n");
							c_display_queue(q_datatype, q_ptr, q_size, &front, &rear);
							printf("\n");
						}	
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
			case CHAR:
			{
				char val;
				switch(choice)
				{
					case 1:
						if((rear+1)%q_size==front)
						{
							printf("Queue is full, cannot perform insertion\n");
						}
						else
						{
							printf("Enter the element you want to insert:");
							scanf(" %c", &val);
							val=*((char *)c_enqueue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%c inserted in the queue\n", val);	
						}
						break;
					case 2:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot perform deletion\n");
						}
						else
						{
							val=*((char *)c_dequeue(q_datatype, q_ptr, q_size, &front, &rear, &val));
							printf("%c deleted\n", val);
						}
						break;	
					case 3:
						if(front==-1 && rear==-1)
						{
							printf("Queue is empty, cannot display\n");
						}
						else
						{
							printf("The Elements in the Queue are:\n");
							c_display_queue(q_datatype, q_ptr, q_size, &front, &rear);
							printf("\n");
						}	
						break;
					case 4:
						printf("Exitting...\n");
						break;
					default:
						printf("Invalid choice, enter a valid choice\n");
				}
				break;
			}
		}
	} while(choice!=4);
}

void queue_operations()
{
	int sub_choice;
	do
	{
		clear_screen();
		printf("  Queue Operations\n\n");
		printf("1: Linear Queue\n");
		printf("2: Circular Queue\n");
		printf("3: Return to main menu\n\n");
		printf("Choice: ");
		scanf("%d",&sub_choice);
		switch(sub_choice)
		{
			case 1:
				clear_screen();
				l_queue_operations();
				break;
			case 2:
				clear_screen();
				c_queue_operations();
				break;
			case 3:
				printf("\nReturning to Main Menu\n\n");
				break;
		}
	} while (sub_choice!=3);
}
int main()
{
	int main_choice, sub_choice;
	do
	{
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n\n");
		printf("                                   Implement all types of Data Structures\n\n");
		printf("                                  Made by Tanmay, Shreyas, Jeevan & Durgesh\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n\n");
		printf("1] Searching Techniques\n");
		printf("2] Sorting Techniques\n");
		printf("3] Linear Data Structures\n");
		printf("4] Exit\n\n");
		printf("-----------------------------------------------------------------------------------------------------------------\n");
		printf("Choice: ");
		scanf("%d",&main_choice);
		clear_screen();
		switch (main_choice)
		{
			case 1:
				do
				{	
					clear_screen();
					printf("  Searching Techniques\n\n");
					printf("1: Linear Search Implementation\n");
					printf("2: Binary Search Implementation\n");
					printf("3: Return to main menu\n\n");
					printf("Choice: ");
					scanf("%d",&sub_choice);
					switch(sub_choice)
					{
						case 1:
							//Linear Search
							clear_screen();
							create_and_LS();
							pause_screen();
							break;
						case 2:
							//Binary Search
							clear_screen();
							create_and_BS();
							pause_screen();
							break;
						case 3:
							printf("\nReturning to Main Menu\n\n");
							break;
						default:
							printf("\nInvalid choice!, please enter a valid choice\n");
					}
				} while(sub_choice!=3);
				clear_screen();
				break;
			case 2:
				do
				{	
					clear_screen();
					printf("  Sorting Techniques\n");
					printf("1: Bubble Sort\n");
					printf("2: Selection Sort\n");
					printf("3: Insertion Sort\n");
					printf("4: Return to main menu\n\n");
					printf("Choice: ");
					scanf("%d",&sub_choice);
					switch(sub_choice)
					{
						case 1:
							//Bubble sort
							clear_screen();
							create_and_sort(BUBBLE);
							pause_screen();
							break;
						case 2:
							//Selection Search
							clear_screen();
							create_and_sort(SELECTION);
							pause_screen();
							break;
						case 3:
							//Insertion Search
							clear_screen();
							create_and_sort(INSERTION);
							pause_screen();
							break;
						case 4:
							printf("\nReturning to Main Menu\n\n");
							break;
						default:
							printf("\nInvalid choice!, please enter a valid choice\n");
					}
				} while(sub_choice!=4);
				clear_screen();
				break;
			case 3:
				do
				{
					clear_screen();
					printf("  Linear Data Structures\n");
					printf("1: Stack\n");
					printf("2: Queue\n");
					printf("3: Return to main menu\n\n");
					printf("Choice: ");
					scanf("%d", &sub_choice);
					switch(sub_choice)
					{
						case 1:
							//Stack
							clear_screen();
							stack_operations();
							pause_screen();
							break;
						case 2:
							//Queue
							clear_screen();
							queue_operations();
							break;
						case 3:
							printf("\nReturning to Main Menu\n\n");
							break;
						default:
							printf("\nInvalid choice!, please enter a valid choice\n");
					}
				} while(sub_choice!=3);
				clear_screen();
				break;
			case 4:
				printf("  Exiting\n");
				break;
		}
	} while(main_choice!=4);
    return 0;
}