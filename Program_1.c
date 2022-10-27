#include <stdio.h>
#include <windows.h>
#include <string.h>

int getUserChoice()
{
    int c;
    printf("1-Add a student\n");
    printf("2-Remove a student\n");
    printf("3-Search a student\n");
    printf("4-Print the list in ascending order\n");
    printf("5-Quit\n");
    printf("Choose an option: ");
    fflush(stdin);
    scanf("%d", &c);
    return c;
}

int isFull(char list[100][31], int *pn) 
{
	return ((*pn) == 100);
}

int isEmpty(char list[100][31], int *pn) 
{
	return ((*pn) == 0);
}
void add_student(char list[100][31], int *pn)
{
	char student[31];
	printf("Enter student's name: ");fflush(stdin);
	scanf("%[^\n]",student);
	strcpy(list[*pn],student);
    (*pn)++;
    printf("The name is added.\n");
    system("pause");system("cls");
}

void remove_student(char list[100][31],int *pn)
{
    int serial;
    printf("Enter the student's serial number you want to remove: ");
    scanf("%d",&serial);
    if(serial<=(*pn)&&serial>=0)      
	{
	for(int i=serial;i<=(*pn);i++)
        {
            strcpy(list[i],list[i+1]);
        }
        printf("Removed\n");
        (*pn)--;
    }
    else printf("Un removed, invalid number\n");    
    system("pause");system("cls");
}
void search(char list[100][31],int*pn)
{
    char student[31];
    printf("Enter name you are searching for: ");fflush(stdin);
    scanf("%[^\n]",&student);
    int check=0;
    for(int i=0;i<(*pn);i++)
    {
        if(strcmp(list[i],student)==0)
        {
            printf("Number %d. %s\n",i,list[i]);
            check++;
        }
    }    
    if (check==0) printf("Name does not exist in this list\n");
    system("pause");system("cls");    
}
void print(char list[100][31],int *pn)
{
    for(int i=0;i<(*pn);i++)
    {
        printf("%d. %s\n",i,list[i]);
    }
    system("pause");
}

int main()
{
    int userChoice;
    char list[100][31];
    int n = 0;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case 1:
				if (isFull(list, &n)) printf("List is full\n");
				else add_student(list, &n);
				break;
            case 2:
				if (isEmpty(list, &n)) printf("List is empty!\n");
				else remove_student(list, &n);break;
            case 3:
				if (isEmpty(list, &n)) printf("List is empty!\n");
				else search(list, &n);
				break;
            case 4:
				if (isEmpty(list, &n)) printf("List is empty!\n");
				else print(list, &n);
				break;
            case 5:
				break;
        }
    } while (userChoice > 0  && userChoice <5);
    return 0;
}