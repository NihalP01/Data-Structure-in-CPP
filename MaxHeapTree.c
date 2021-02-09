#include<stdio.h>


int size = 0;

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("\nSingle element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

void insert(int array[], int newNum)
{
  int i;
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  heapify(array, size, i);
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}

void deleteRoot(int array[], int num)
{
  int i, count = 0;
  for (i = 0; i < size; i++)
  {
    if (num == array[i]){
      count += 1;
      break;
      }
  }
  if (count == 0)
  {
    printf("No data found to delete");
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}


int main()
{
    int select, val;
    int array[10];
    do
    {
        printf("Enter your choice: \n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert(array, val);
            break;
        case 2:
            printf("Enter the value you want to delete: ");
            scanf("%d", &val);
            deleteRoot(array, val);
            break;
        case 3: 
            printArray(array, size);
            break;
        default:
            printf("Invalid choice...");
            break;
        }
    } while (select != 4);
    
    return 0;
}
