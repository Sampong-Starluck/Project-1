#include <stdio.h>
#include <stdlib.h>

struct date{
    int d,m,y;
}date;
struct employee{
    char firstname[100],lastname[100],email[100],status[50],position[50];
    int id,year,tel;
    struct date Sdate;
};
typedef struct employee info;

void Display_all_info();
void add_info();
void update_info();
void delete_id();
void display_id();
void display_retire();

int main()
{
    info em[100];
    FILE*fptr;
    int choise , i = 1 ,num ;
    fptr = fopen("employee_info.txt","w+");
    if(fptr == NULL);
    {
        printf("File could not be opened.\n");
        printf("Enter contents to store in file : \n");
        printf("Enter the number of employee:");
        scanf("%d",&num);//I don't understand this point
        for (int i = 0; i < num; i++)
        {
            /* code */
            printf("Enter employee %d's firstname and lastname: ",i+1);
            scanf("%s %s",&em[i].firstname,&em[i].lastname);
            printf("Employee's email and phone number: ");
            scanf("%s %d",&em[i].email,&em[i].tel);
            printf("Position and status: ");
            scanf("%s %s",&em[i].position,&em[i].status);
            printf("Employee's ID: ");
            scanf("%d",&em[i].id);
            printf("Birth's year: ");
            scanf("%d",&em[i].year);
            printf("Enter the employee start working date(Day,Month,Year): ");
            scanf("%d%d%d",&em[i].Sdate.d,&em[i].Sdate.m,&em[i].Sdate.y);
        }
    }
    if (fptr != NULL)
    {
        while (i > 0)
        {
            printf("\n1.Display all employee info.\n2.Add new employee.\n3.Update employee info via id.\n4.Delete ID.\n5.Display employee info via ID.\n6.display retire employee ");
            scanf("%d",&choise);
            switch (choise)
            {
            case /* constant-expression */1:
                /* code */
                Display_all_info();
                break;
            case 2:
                add_info();
                break;
            case 3:
                update_info();
                break;
            case 4:
                delete_id();
                break;
            case 5:
                display_id();
                break;
            case 6:
                display_retire();
                break;
            default:
                printf("Your choise is invalid !!!!");
                break;
            }
        }
        i++;
    }
    fclose(fptr);
}

void Display_all_info()
{

}
void add_info()
{

}
void update_info()
{

}
void delete_id()
{

}
void display_id()
{

}
void display_retire()
{

}
