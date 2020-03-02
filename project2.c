#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Structure*/
struct date{
    int d,m,y;
}date;
struct employee{
    char firstname[100],lastname[100],email[100],status[50],position[50];
    int id,year,tel;
    struct date Sdate;
};
typedef struct employee info;
//Function prototype
void save_info(FILE *read);
void Display_all_info(FILE*read);
void add_info(FILE*fptr);
void update_info(FILE*fptr);
void delete_id(FILE*fptr);
void display_id(FILE*fptr);
void display_retire(FILE*fptr);
//Global variable
int num;
//Main Function
int main()
{
    info em[100];
    FILE*fptr;
    int choise , i = 1 ;
    fptr = fopen("employee_info.txt","w+");
    if(fptr == NULL);
    {
        printf("File could not be opened.\n");
        printf("Enter contents to store in file: \n");
        printf("Enter the number of employee: ");
        scanf("%d",&num);
        for (int i = 0; i < num; i++)
        {
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
        save_info(fptr);
    }
    if (fptr != NULL)
    {
        while (i > 0)
        {
            printf("%s""\n1.Display all employee info."
            "\n2.Add new employee."
            "\n3.Update employee info via id."
            "\n4.Delete ID."
            "\n5.Display employee info via ID."
            "\n6.display retire employee ");
            scanf("%d",&choise);
            switch (choise)
            {
            case /* constant-expression */1:
                /* code */
                Display_all_info(fptr);
                break;
            case 2:
                add_info(fptr);
                break;
            case 3:
                update_info(fptr);
                break;
            case 4:
                delete_id(fptr);
                break;
            case 5:
                display_id(fptr);
                break;
            case 6:
                display_retire(fptr);
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
//Sub program(Procedure)
void save_info(FILE*read)
{
    FILE *write; 
    rewind(read);
    fprintf(write,"%s \t %s \t %s \t %s \t %s \t %s \t %s \t %s \t %s","ID","Last Name","First Name","Email","Position","Status","Birth's year","Tel","Started date");
    while (!feof(read))
    {
        info em ;//= {0,"","","","","","",0,0,0,0,0};
        int result = fread(&em, sizeof(em), 1, read);
        for (int i = 0; i < num; i++)
        {     
            if (result != 0 && em.id != 0)
            {
               fprintf(write,"%d| \t%s| \t%s| \t%s| \t%s| \t%s| \t%d| \t%d| \t%d| \t%d| \t%d|\n",em.id,em.lastname,em.firstname,em.email,em.position,em.status,em.year,em.tel,em.Sdate.d,em.Sdate.m,em.Sdate.y);
            }
        }
    }
    fclose(write);
}
void Display_all_info(FILE*read)
{
    FILE*fptr;
    info em;
    fptr = fopen("employee_info.txt","r");
    char buffer[100];
    int totalRead = 0;
    while(fgets(buffer,100, fptr) != NULL) 
    {
        totalRead = strlen(buffer);
        
        buffer[totalRead - 1] = buffer[totalRead - 1] == '\n' ? '\0': buffer[totalRead - 1];

        printf("%d| \t%s| \t%s| \t%s| \t%s| \t%s| \t%d| \t%d| \t%d| \t%d| \t%d|\n",em.id,em.lastname,em.firstname,em.email,em.position,em.status,em.year,em.tel,em.Sdate.d,em.Sdate.m,em.Sdate.y);
    } 
    fclose(fptr);
}
void add_info(FILE*fptr)
{

}
void update_info(FILE*fptr)
{

}
void delete_id(FILE*fptr)
{

}
void display_id(FILE*fptr)
{

}
void display_retire(FILE*fptr)
{

}
