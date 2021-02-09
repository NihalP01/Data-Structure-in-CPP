/* Submitted By: Nihal Buragohain, CSE-27/19 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define Size 20

struct Student
{
    int rollNo;
    char Name[30], branch[10];
    float CGPA;
} s[20];

void insertData()
{
    for (int i = 0; i < Size; ++i)
    {
        printf("\n\nData of the student %d: \n", i + 1);
        printf("Enter the roll number: ");
        scanf("%d", &s[i].rollNo);
        printf("Enter name of the student: ");
        scanf("%s", &s[i].Name);
        printf("Enter the Branch of the student: ");
        scanf("%s", &s[i].branch);
        printf("Enter the CGPA of the student: ");
        scanf("%f", &s[i].CGPA);
    }
}

// void display()
// {
//     for (int i = 0; i < 5; ++i)
//     {
//         printf("\n\nData of the student %d\n", i + 1);
//         printf("Roll No: %d\n", s[i].rollNo);
//         printf("Name of the student: %s\n", s[i].Name);
//         printf("CGPA of the student: %0.2f\n", s[i].CGPA);
//         printf("\n");
//     }
    
// }

int LinearSearch(struct Student n[], int Roll)
{
    int temp = -1;
    for (int i = 0; i < Size; i++)
    {
        if (n[i].rollNo == Roll)
        {
            printf("\n\nThe student data is found at position %d \n", i + 1);
            printf("Roll No of the Student: %d\n", n[i].rollNo);
            printf("Name of the student: %s\n", n[i].Name);
            printf("Branch of the Student: %s\n", n[i].branch);
            printf("CGPA of the student: %0.2f\n", n[i].CGPA);
            temp = 0;
            break;
        }
    }
    if (temp == -1)
    {
        printf("\n\nDetails not found\n");
    }
    return 0;
}

void bubbleSort(struct Student data[])
{
    clock_t start, end;
    double cpuTimeUsed;
    start = clock();
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size - i - 1; j++)
        {
            if (data[j].rollNo > data[j + 1].rollNo)
            {
                int temp = data[j].rollNo;
                data[j].rollNo = data[j + 1].rollNo;
                data[j + 1].rollNo = temp;
                
            }
        }
    }
    for (int i = 0; i < Size; i++)
    {
        printf("\n\nRoll No of the Student: %d\n", s[i].rollNo);
        printf("Name of the student: %s\n", s[i].Name);
        printf("Branch of the Student: %s\n", s[i].branch);
        printf("CGPA of the student: %0.2f\n", s[i].CGPA);
    }
    end = clock();
    cpuTimeUsed = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n\nTime taken for sorting: %lf", cpuTimeUsed);
}

void insertionSort(struct Student data[]){
    float key;
    int j;
    clock_t start, end;
    double cpuTimeUsed;
    start = clock();
    for (int i = 1; i < Size; i++)
    {
        key = data[i].CGPA;
        j = i-1;

        while (j >= 0 && data[j].CGPA < key)
        {
            data[j + 1].CGPA = data[j].CGPA;
            j--;
        }
        data[j + 1].CGPA = key;
    }
    for (int i = 0; i < Size; i++)
    {
        printf("\n\nRoll No of the Student: %d\n", s[i].rollNo);
        printf("Name of the student: %s\n", s[i].Name);
        printf("Branch of the Student: %s\n", s[i].branch);
        printf("CGPA of the student: %0.2f\n", s[i].CGPA);
    } 
    end = clock();
    cpuTimeUsed = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("\n\nTime taken for sorting: %lf", cpuTimeUsed); 
}

int binarySearch(struct Student data[], int size, int rollNo){
    int low, mid, high;
    low = 0;
    high = size-1;
 while (low <= high)
 {
    mid = (low+high)/2;
    if (data[mid].rollNo == rollNo)
    {
        printf("\nStudent data is found at position %d\n", mid+1);
        printf("\nRoll No of the Student: %d\n", s[mid].rollNo);
        printf("Name of the student: %s\n", s[mid].Name);
        printf("Branch of the Student: %s\n", s[mid].branch);
        printf("CGPA of the student: %0.2f\n", s[mid].CGPA);
        return 0;
    }
    if (data[mid].rollNo < rollNo)
    {
        low = mid+1;
    }else
    {
        high = mid-1;
    }     
 }
    printf("No data found !");
}

int main()
{
    int select, rollNo;
    do
    {
        printf("\n\n----Student Database----\n");
        printf("1. Insert students data.\n");
        printf("2. Search a student by Roll No.(Linear Search)\n");
        printf("3. Sort the list according to Roll No.\n");
        printf("4. Search a student by Roll No (Binary Search)\n");
        printf("5. Sort the list in descending order by CGPA\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            insertData();
            break;
        case 2:
            printf("Enter the roll no of the Student: ");
            scanf("%d", &rollNo);
            LinearSearch(s, rollNo);
            break;
        case 3:
            printf("Sorted list accroding to Roll No. : \n");
            bubbleSort(s);
            break;
         case 4:
            printf("Enter the Roll No of the student: ");
            scanf("%d", &rollNo);
            binarySearch(s, Size, rollNo);
            break;
        case 5: 
            printf("Sorted list in decsending order accroding to CGPA:\n");
            insertionSort(s);
            break;
        case 6: 
            printf("Program exited...");
            break;
        default:
            printf("Invalid choice !");
            break;
        }
    } while (select != 6);
    return 0;
}
