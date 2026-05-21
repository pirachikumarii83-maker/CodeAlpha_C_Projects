#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int id;
    char name[50];
    float marks;
};
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n");
        printf("\n STUDENT MANAGEMENT SYSTEM");
        printf("\n");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Delete Student");
        printf("\n5. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("\nProgram Closed Successfully.\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }
    }
    return 0;
}

void addStudent()
{
    FILE *file;

    struct Student s;

    file = fopen("students.txt", "a");

    if (file == NULL)
    {
        printf("\nError Opening File!\n");
        return;
    }
    printf("\nEnter Student ID: ");
    scanf("%d", &s.id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Student Marks: ");
    scanf("%f", &s.marks);

    fprintf(file, "%d %s %.2f\n", s.id, s.name, s.marks);

    fclose(file);

    printf("\nStudent Record Added Successfully!\n");
}

void displayStudents()
{
    FILE *file;

    struct Student s;

    file = fopen("students.txt", "r");

    if (file == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }
    printf("\n STUDENT RECORDS \n");

    while (fscanf(file, "%d %s %f",
                  &s.id,
                  s.name,
                  &s.marks) != EOF)
    {
        printf("\nStudent ID    : %d", s.id);
        printf("\nStudent Name  : %s", s.name);
        printf("\nStudent Marks : %.2f", s.marks);

        printf("\n");
    }
    fclose(file);
}
void searchStudent()
{
    FILE *file;
    struct Student s;
    int id;
    int found = 0;
    file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }
    printf("\nEnter Student ID to Search: ");
    scanf("%d", &id);
    while (fscanf(file, "%d %s %f",
                  &s.id,
                  s.name,
                  &s.marks) != EOF)
    {
        if (s.id == id)
        {
            printf("\n\nStudent Found Successfully!\n");

            printf("\nStudent ID    : %d", s.id);
            printf("\nStudent Name  : %s", s.name);
            printf("\nStudent Marks : %.2f\n", s.marks);

            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\nStudent Record Not Found!\n");
    }
    fclose(file);
}
void deleteStudent()
{
    FILE *file, *tempFile;
    struct Student s;
    int id;
    int found = 0;
    file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }
    tempFile = fopen("temp.txt", "w");
    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %f",
                  &s.id,
                  s.name,
                  &s.marks) != EOF)
    {
        if (s.id == id)
        {
            found = 1;
        }
        else
        {
            fprintf(tempFile,
                    "%d %s %.2f\n",
                    s.id,
                    s.name,
                    s.marks);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found == 1)
    {
        printf("\nStudent Record Deleted Successfully!\n");
    }
    else
    {
        printf("\nStudent Record Not Found!\n");
    }
}