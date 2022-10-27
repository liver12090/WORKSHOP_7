#include <stdio.h>
#include <windows.h>
#include <string.h>

int getUserChoice()
{
    int c;
    printf("1-Add a new soft drink\n");
    printf("2-Printing out items which belong to a known make\n");
    printf("3-Printing out items whose volumes are between v1 and v2 \n");
    printf("4-Printing the list in ascending order based on volume then prices.\n");
    printf("5-Quit\n");
    printf("Choose an option: ");
    fflush(stdin);
    scanf("%d", &c);
    return c;
}

int isFull(int volume[100], int *pn) 
{
	return ((*pn) == 100);
}

int isEmpty(int volume[100], int *pn) 
{
	return ((*pn) == 0);
}
void add(char name[][21],char make[][21],int volume[],int price[],int duration[],int *pn)
{
	char string[21];int xxx;
	printf("Enter name: ");fflush(stdin);
	scanf("%20[^\n]",&string);
	strcpy(name[*pn],string);
	printf("Enter make: ");fflush(stdin);
	scanf("%20[^\n]",&string);
	strcpy(make[*pn],string);	
	printf("Enter volume: ");
	scanf("%d",&xxx);
	volume[*pn]=xxx;
	printf("Enter price: ");
	scanf("%d",&xxx);
	price[*pn]=xxx;
	printf("Enter duration: ");
	scanf("%d",&xxx);
	duration[*pn]=xxx;
	(*pn)++;
	printf("Added \n");
	system("pause");system("cls");
 } 
 void print_make(char name[][21],char make[][21],int volume[],int price[],int duration[],int *pn)
 {
 	char string[20];int check=0;
 	printf("Enter make you want to print: ");fflush(stdin);
 	scanf("%20[^\n]",&string);
 	for(int i=0;i<(*pn);i++)
 	{
 		if(strcmp(make[i],string)==0)
 		{
 			printf("Name: %20s | Make: %20s | Volume: %3d | Price: %3d | Duration: %3d day.\n",name[i],make[i],volume[i],price[i],duration[i]);
			check++;
		}
	}
	if(check==0) printf("There is no product satisfied\n");
	system("pause");system("cls");
 }
 
 void print_volume(char name[][21],char make[][21],int volume[],int price[],int duration[],int *pn)
 {
 	int v1,v2,check=0;
 	printf("Enter volume (lower): ");scanf("%d",&v1);
 	printf("Enter volume (higher): ");scanf("%d",&v2);
 	for(int i=0;i<(*pn);i++)
 	{
 		if((volume[i]>=v1)&&(volume[i]<=v2))
 		{
		 	printf("Name: %20s | Make: %20s | Volume: %3d | Price: %3d | Duration: %3d day.\n",name[i],make[i],volume[i],price[i],duration[i]);	
			check++;
		}
	}
	if(check==0) printf("There is no product satisfies\n");
	system("pause");system("cls");
 }
 void swap(char name[][21],char make[][21],int volume[],int price[],int duration[],int i, int j)
 {
 	char s1[21];
	strcpy(s1, name[i]);
	strcpy(name[i], name[j]);
	strcpy(name[j], s1);
	            
	char s2[8];
	strcpy(s2, make[i]);
	strcpy(make[i], make[j]);
	strcpy(make[j], s2);
	            
	int num1 = volume[i];
	volume[i]=volume[j];
	volume[j]=num1;
	            
	int num2 = price[i];
	price[i]=price[j];
	price[j]=num2;
	
	int num3=duration[i];
	duration[i]=duration[j];
	duration[j]=num3;
 }
 void print_ascending(char name[][21],char make[][21],int volume[],int price[],int duration[],int *pn)
 {
 	for (int i = 0; i < (*pn); i++)
	{
		for (int j = i+1; j<(*pn); j++)
		{
			if (volume[i]>volume[j])
			{
				swap(name,make,volume,price,duration,i,j);
			}
		}
	}
	for (int i = 0; i < (*pn); i++)
	{
		for (int j = i+1; j<(*pn); j++)
		{
			if ((price[i]>price[j])&&(volume[i]==volume[j]))
			{
				swap(name,make,volume,price,duration,i,j);
			}
		}
	}
	for(int i=0;i<(*pn);i++)
	{
		printf("Name: %20s | Make: %20s | Volume: %3d | Price: %3d | Duration: %3d day.\n",name[i],make[i],volume[i],price[i],duration[i]);
	}
	system("pause"),system("cls");
 }
 
 int main()
 {
 	int userChoice;
    char name[100][21], make[100][21];
    int volume[100],price[100],duration[100];
    int n = 0;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case 1:
				if (isFull(volume, &n)) printf("Full\n");
				else add(name,make,volume,price,duration,&n);
				break;
            case 2:
				if (isEmpty(volume, &n)) printf("Empty!\n");
				else print_make(name,make,volume,price,duration,&n);
				break;
            case 3:
				if (isEmpty(volume, &n)) printf("Empty!\n");
				else print_volume(name,make,volume,price,duration,&n);
				break;
            case 4:
				if (isEmpty(volume, &n)) printf("Empty!\n");
				else print_ascending(name,make,volume,price,duration,&n);
				break;
            case 5:
				break;
        }
    } while (userChoice > 0  && userChoice <5);
    return 0;
 }