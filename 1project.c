#include <stdio.h>
#include <stdlib.h>

struct student
{   char name[50];
    char surname[50];
    int id_no;
    float grades;
    };
FILE *file;

int main()
{
     int choice;
    do {
        printf("\tMain menu\n\n");
        printf("1. Add student data\n");
        printf("2. Display all students data\n");
        printf("3. Search of student data\n");
        printf("4. Delete student\n");
        printf("5. Modify student data\n");
        printf("6. Class results\n");
        printf("0. Exit program!\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: add_student();
                break;
            case 2: display_all();
                break;
            case 3: search_students();
                break;
            case 4: delete_student();
                break;
            case 5: modify_student();
                break;
            case 6: class_result();
                break;
            case 7: printf("Quitting program!\n");
                exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
        }
    } while (choice != 0);
   return 0;
}

void add_student (){
    struct student data;
    file = fopen("stud_data.dat", "ab");
    printf("\n\nPlease enter the details of student \n");
    input(&data);
    fwrite(&data, sizeof(data), 1, file);
    fclose(file);
    printf("\nStudent Record Has Been Created \n");

}
void search_students(){
    int num;
    printf("\n\nPlease enter the id number: ");
    scanf("%d", &num);
    display_sp(num);
    }

void input(struct student *s)
{
    printf("\nEnter the id number of student: ");
    scanf("%d", &s->id_no);
    printf("\nEnter the Name of student: ");
    scanf("\n%s", s->name);
    printf("\nEnter the Surname of student: ");
    scanf("\n%s", s->surname);
    printf("\nEnter the grades: ");
    scanf("%f", &s->grades);
}
void display(struct student st)
{
    printf("\nId number of student : %d", st.id_no);
    printf("\nName of student : %s", st.name);
    printf("\nSurname of student : %s", st.surname);
    printf("\nGrade : %f\n", st.grades);
}
void display_all()
{
    struct student data;
    printf("\n\nDISPLAY ALL RECORDS !!!\n\n");
    file = fopen("stud_data.dat", "rb");
    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        display(data);
        printf("\n====================================\n");
    } fclose(file);
}
void delete_student()
{
    int no;
    struct student data;
    FILE *file2;
    printf("\n\nDelete Record");
    printf("\nPlease Enter The id number you want to delete: ");
    scanf("%d", &no);
    file = fopen("stud_data.dat", "rb");
    file2 = fopen("temp.dat", "wb");
    rewind(file);
    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        if (data.id_no != no)
        {
            fwrite(&data, sizeof(data), 1, file2);
        }
    }
    fclose(file2);
    fclose(file);
    remove("stud_data.dat");
    rename("temp.dat", "stud_data.dat");
    printf("\nRecord deleted.\n\n");
}
void display_sp(int n)
{
    struct student data;
    int flag = 0;
    file = fopen("stud_data.dat", "rb");
    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        if (data.id_no == n)
        {
            display(data);
            flag = 1;
        }
    }
    fclose(file);
    if (flag == 0)
        printf("\nRecord not exist\n\n");
}
void modify_student()
{
    struct student data;
    int no, found = 0;

    printf("\nTo Modify ");
    printf("\nPlease enter the id number of student: ");
    scanf("%d", &no);
    file = fopen("stud_data.dat", "rb+");
    while ((fread(&data, sizeof(data), 1, file)) > 0 && found == 0)
    {
        if (data.id_no == no)
        {
            display(data);
            printf("\nPlease enter the new details of student \n");
            input(&data);
            fseek(file,  - (long)sizeof(data), 1);
            fwrite(&data, sizeof(data), 1, file);
            printf("\n Record Updated");
            found = 1;
        }
    }
    fclose(file);
    if (found == 0)
        printf("\nRecord Not Found\n");
}
void class_result()
{
    struct student data;
    file = fopen("stud_data.dat", "rb");
    if (file == NULL)
    {
        printf(
            "ERROR!!! FILE COULD NOT BE OPEN\n\nGo To Entry Menu to create File\n");
        return;
    }

    printf("\nCLASS RESULTS! \n");
    printf("===========================================================================\n");
    printf("Id.Num.\tName\t\tSurname\tGrade\n");
    printf("===========================================================================\n");

    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        printf("%-7d %-15s %-15s %-1f \n", data.id_no, data.name, data.surname, data.grades);
    }
    fclose(file);
}
