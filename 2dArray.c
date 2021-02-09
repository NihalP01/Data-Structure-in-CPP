#include<stdio.h>

#define x 3
#define y 3

int main()
{
	  	int array[x][y], i, j;
	  	int EnterChoice;
	  	
	  	printf("Enter 9 elements into 2-D array(3x3 Matrix): \n");
	for(i=1;i<=x;i++)
		{
		for(j=1;j<=y;j++)
			{
			scanf("%d" , &array[i][j]);
			}
		}


	
	do
	{
		printf("Enter the CHOICE : \n");
		printf("1.INSERT\n");
		printf("2.DELETE\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		scanf("%d",&EnterChoice);
		
		
		switch(EnterChoice)
		{
			case 1:
				printf("OPERATION TO INSERT AT ARRAY....\n");
			//	printf("Enter the value to insert at any position\n");
					
			Insert(array);
		  	printf("New element is added successfully.... \n");
			break;

					
			case 2:
				printf("OPERATION TO DELETE ANY array element....\n");
				Delete(array);
				printf("\nSpecific element is deleted successfully : \n");
				break;

				
			case 3:
				printf("UPDATED ARRAY is : \n");
				Display(array );
				break;	
		
			case 4:
				printf("EXITING THE PROGRAM\n");
				break;    
				
			default:
				printf("INVALID OPTION\n");
				break;
				  	
		}
	}
	while(EnterChoice != 4);

}


void Insert(int array[x][y])
{
    int i,j;
    int num;
   	printf("Enter the value of row and coulmn number :");
	scanf("%d  %d", &i,&j);
	printf("Enter the number you want to update with: ");
	scanf("%d" , &num);
	
	array[i][j]=num;
}

void Delete(int array[x][y])
{
	int posRow, posCol;
	printf("Enter the Row index : ");
	scanf("%d",&posRow);
	printf("\n");
	printf("Enter the Column index : ");
	scanf("%d",&posCol);
		
	if(posRow == 0 || posCol == 0 || posRow > x || posCol > y)
	{
		printf("\nRow Indices start from 1 to %d and Column Indices start from 1 to %d. Please enter valid indices.", x, y);
		return;
	}
	else
	{
		int ele = array[posRow][posCol];
		array[posRow][posCol] = 0;
		printf("%d deleted from the position (%d, %d) of the Array.\n", ele, posRow, posCol);
	}
}

void Display(int array[x][y])
{
	int i,j;
    	for( i=1;i<=x;i++)
		{
		for( j=1;j<=y;j++)
			{
			printf("\t%d" , array[i][j]);
			}
		printf("\n");
		}
}