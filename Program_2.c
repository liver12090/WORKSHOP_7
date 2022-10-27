#include <stdio.h>
#include <windows.h>
#include <string.h>

int getUserChoice()
{
    int c;
    printf("1-Add a new employee\n");
    printf("2-Find data about employees using a name inputted\n");
    printf("3-Remove an employee based on a code inputted\n");
    printf("4-Print the list in descending order on salary + allwance\n");
    printf("5-Quit\n");
    printf("Choose an option: ");
    fflush(stdin);
    scanf("%d", &c);
    return c;
}

int isFull(double salary[100], int *pn) 
{
	return ((*pn) == 100);
}

int isEmpty(double salary[100], int *pn) 
{
	return ((*pn) == 0);
}

void add(char code[][9], char name[][21], double salary[],double allowance[], int *pn)
{
	char string[21]; double xxx;
	int check;
	do
	{
		check=0;
		printf("Enter code (8 characters): "); fflush(stdin);
		scanf("%8[^\n]",&string);
		for (int i=0; i < *pn; i++)
		if (strcmp(string,code[i]) == 0) 
			{
				printf("Code existed\n");
				check++;
			}
	} while (check!=0);
	strcpy(code[*pn],string);
	printf("Enter name: ");fflush(stdin);
	scanf("%20[^\n]",&string);
	strcpy(name[*pn],string);
	printf("Enter salary: ");
	scanf("%lf",&xxx);
	salary[*pn]=xxx;
	printf("Enter allowance: ");
	scanf("%lf",&xxx);
	allowance[*pn]=xxx;
	(*pn)++;
	printf("Added \n");
	system("pause");system("cls");
}
void find_data(char code[][9], char name[][21], double salary[],double allowance[], int *pn)
{
	char string[21];
	int check=0;
	printf("Enter name you want to find: ");fflush(stdin);
	scanf("%20[^\n]",&string);
	for(int i=0;i<(*pn);i++)
	{
		if (strcmp(name[i],string)==0)
		{
			printf("Data about %s\n",string);
			printf("Code: %s\n",code[i]);
			printf("Name: %s\n",name[i]);
			printf("Salary: %lf\n",salary[i]);
			printf("Allowance: %lf\n",allowance[i]);
			check ++;
		}
	}
	if(check==0) printf("No dada about %s\n",string);
	system("pause");system("cls");
}

void remove_data(char code[][9], char name[][21], double salary[],double allowance[], int *pn)
{
	char string[9];
	int check;
	printf("Enter code of employee you want to remove data: ");fflush(stdin);
	scanf("%8[^\n]",&string);
	for(int i=0;i<(*pn);i++)
	{
		if (strcmp(code[i],string)==0)
		{
			check=i;break;
		}else check =-1;
	}
	if (check !=-1)
	{
		for(int i=check; i<(*pn);i++)
			{
				strcpy(code[i],code[i+1]);
				strcpy(name[i],name[i+1]);
				salary[i]=salary[i+1];
				allowance[i]=allowance[i+1];
			}
		(*pn)--;
		printf("Removed data \n");
	}else printf("Invalid code:");
	system("pause");system("cls");
	
}
void print(char code[][9], char name[][21], double salary[],double allowance[], int *pn)
{
	for (int i = 0; i < (*pn); i++)
	{
		for (int j = i+1; j<(*pn); j++)
		{
			if ( (salary[j] + allowance[j]) > (salary[i] + allowance[i]) )
			{
				char s1[21];
	            strcpy(s1, name[i]);
	            strcpy(name[i], name[j]);
	            strcpy(name[j], s1);
	            
	            char s2[8];
	            strcpy(s2, code[i]);
	            strcpy(code[i], code[j]);
	            strcpy(code[j], s2);
	            
	            double num1 = salary[i];
	            salary[i]=salary[j];
	            salary[j]=num1;
	            
	            double num2 = allowance[i];
	            allowance[i]=allowance[j];
	            allowance[j]=num2;
			}
		}
	}
	for (int i = 0; i < (*pn); i++)
    	printf("Code:%8s | Name:%20s | salary:%3.3lf | allowance:%3.3lf \n", code[i], name[i], salary[i], allowance[i]);
    system("pause");system("cls");
}

int main()
{
	int userChoice;
    char code[100][9], name[100][21];
    double salary[100],allowance[100];
    int n = 0;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case 1:
				if (isFull(salary, &n)) printf("Full\n");
				else add(code,name,salary,allowance,&n);
				break;
            case 2:
				if (isEmpty(salary, &n)) printf("Empty!\n");
				else find_data(code,name,salary,allowance,&n);
				break;
            case 3:
				if (isEmpty(salary, &n)) printf("Empty!\n");
				else remove_data(code,name,salary,allowance,&n);
				break;
            case 4:
				if (isEmpty(salary, &n)) printf("Empty!\n");
				else print(code,name,salary,allowance,&n);
				break;
            case 5:
				break;
        }
    } while (userChoice > 0  && userChoice <5);
    return 0;
}