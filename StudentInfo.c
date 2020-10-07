#include<iostream>
#include <string.h>

struct Student
{
    char fname[10];
    char lname[10];
    char branch[10];
    char semester[10];
    float CGPA;
    char emailID[20];
    char phNo[12];
};

int main(){
  
    int totalStudent = 2;
   struct Student s[totalStudent]; 
   char sName[20];
   int pos;  
   for (int i = 0; i < totalStudent; i++)
   {   
       printf("\nEnter details of Student %d \n", i+1);
       printf("Enter First name of the Student: ");
       scanf("%s", &s[i].fname);
       printf("Enter Last name of the Student: ");
       scanf("%s", &s[i].lname);
       printf("Enter branch name of the Student: ");
       scanf("%s", &s[i].branch);
       printf("Enter Semester of the Student: ");
       scanf("%s", &s[i].semester);
       printf("Enter the CGPA of the Student: ");
       scanf("%f", &s[i].CGPA);
       printf("Enter the email of the Student: ");
       scanf("%s", &s[i].emailID);
       printf("Enter the Phone number of the Student: ");
       scanf("%s", &s[i].phNo);
   }

    printf("\n\nEnter first name of the Student you want to get details: ");
    scanf("%s", &sName);

    for (int i = 0; i < sizeof s; i++)
    {
        if (strcmp(s[i].fname, sName) == 0) 
        {
            pos = i;
            printf("\nInformation of student %d", pos+1);
            printf("\nName of the Student: %s %s", s[pos].fname, s[pos].lname);
            printf("\nBranch name of the Student: %s", s[pos].branch);
            printf("\nSemester of the Student: %s", s[pos].semester);
            printf("\nCGPA of the Student: %0.1f", s[pos].CGPA);
            printf("\nEmail id of the Student: %s", s[pos].emailID);
            printf("\nPhone no of the student: %s\n", s[pos].phNo);
        }
    }   
}
