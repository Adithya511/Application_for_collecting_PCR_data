#include<stdio.h>//Use for standard I/O Operation
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc

int menu();
int header();
int add();
int list();
int search();
int incorrect();


struct patient{
        char fname[20], lname[20], city[20], d1[5], d2[5];
        int age,tele,idnum;
        float bdtemp;
 };
struct patient ptdt[10];
int count=0;

int main(){
	menu();
return 0;
}

int menu(){
int a;

header();
printf("\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t*************************\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t********MAIN MENU********\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t*************************\n");
printf("\n\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t 1. Add More Suspects\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t 2. List of Suspects\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t 3. Search a Suspect\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t 4. Exit  :\n\n");
printf("\t\t\t\t\t\t\t\t\t\t\t\t Choose from 1 to 4  :");

scanf("%d",&a);
	if(a==1){
		system("cls");
		add();
	}
	else if (a==2){
		system("cls");
		list();
	}
    else if (a==3){
		system("cls");
		search();

	} else if (a==4){
		system("cls");
		system("exit");
	} else{
		incorrect();	
	}

	return 0;
}

int add(){
int i,j;

for(i=count;i<10;i++){
    header();
    printf("\n");
	printf("\t\t\t\t\t\t\t\t\t Add Patient Number %d Details Here........ \n\n",i+1);
	printf("\t\t\t\t\t\t\t\t\t First Name : ");
	scanf("%s",&ptdt[i].fname);
	printf("\t\t\t\t\t\t\t\t\t Last Name : ");
	scanf("%s",&ptdt[i].lname);
	printf("\t\t\t\t\t\t\t\t\t Age  (Please enter digits only) : ");
	scanf("%d",&ptdt[i].age);
	printf("\t\t\t\t\t\t\t\t\t City : ");
	scanf("%s",&ptdt[i].city);
	printf("\t\t\t\t\t\t\t\t\t Telephone Number (Please enter digits only) : ");
	scanf("%d",&ptdt[i].tele);
	printf("\t\t\t\t\t\t\t\t\t ID Number (Please enter digits only) : ");
	scanf("%d",&ptdt[i].idnum);
	printf("\t\t\t\t\t\t\t\t\t Body Temperature : ");
	scanf("%f",&ptdt[i].bdtemp);
	printf("\t\t\t\t\t\t\t\t\t Have Cough?(yes/no): ");
	scanf("%s",&ptdt[i].d1);
	printf("\t\t\t\t\t\t\t\t\t Have Sour Throat?(yes/no): ");
	scanf("%s",&ptdt[i].d2);


    if(ptdt[i].bdtemp>37){
    	printf("\t\t\t\t\t\t\t\t\t Quaranitine Center : A\n\n");
	}
    else {
		printf("\t\t\t\t\t\t\t\t\t Quaranitine Center : B\n\n");
		}
	
	count++;

    printf("\t\t\t\t\t\t\t\t\t Enter 1 to Add Next Suspect, Enter 2 to Go to Main Menu... : ");
	scanf("%d",&j);
	if(j==1) {
		system("cls");
		add();
		break;
	}
    if(j==2) {
	    system("cls");
	    menu();
	    break;
    } 
	else {
    	incorrect();
	}
}
return 0;
}

int list(){
header();
printf("\n\n");
char details[9][25]={"First Name","Last Name", "Age", "City", "ID Num", "Tele", "Body Temp", "Cough", "Sore throat"};
int x,y;
printf("\t\t\t\t");
for(x=0;x<9;x++){
	printf("%-8s\t", details[x]);
}
printf("\n\n");

for(y=0;y<10;y++){
printf("\t\t\t\t");
printf("%-8s\t",ptdt[y].fname);
printf("%-8s\t",ptdt[y].lname);
printf("%-8d\t",ptdt[y].age);
printf("%-8s\t",ptdt[y].city);
printf("%-8d\t",ptdt[y].idnum);
printf("%-8d\t",ptdt[y].tele);
printf("%-8.2f\t",ptdt[y].bdtemp);
printf("%-8s\t",ptdt[y].d1);
printf("%-8s\t",ptdt[y].d2);

printf("\n\n");
}
printf("\n\n\t\t\t\t\t\t\t\t\t Enter 1 to Add More Suspect, Enter 2 to Go to Main Menu... : ");
	scanf("%d",&x);
	if(x==1)
    {
	system("cls");
	add();
	}
    else if(x==2){
    system("cls");
    menu();
    }
    else{
    	incorrect();
	}
return 0;
}

int search()
{
	header();
	char name[20];
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t Enter Patient First Name Correctly: ");
	scanf("%s",name);
	printf("\n\n");

char details[9][25]={"First Name","Last Name", "Age", "City", "ID Num", "Tele", "Body Temp", "Cough", "Sore throat"};
int x,y;
printf("\t\t\t\t");
for(x=0;x<9;x++){
	printf("%-8s\t", details[x]);
}
printf("\n\n");

for(y=0;y<10;y++){
		if (strcmp(ptdt[y].fname,name)==0){	
			printf("\t\t\t\t");	
			printf("%-8s\t",ptdt[y].fname);
			printf("%-8s\t",ptdt[y].lname);
			printf("%-8d\t",ptdt[y].age);
			printf("%-8s\t",ptdt[y].city);
			printf("%-8d\t",ptdt[y].idnum);
			printf("%-8d\t",ptdt[y].tele);
			printf("%-8.2f\t",ptdt[y].bdtemp);
			printf("%-8s\t",ptdt[y].d1);
			printf("%-8s\t",ptdt[y].d2);
			printf("\n\n");
			printf("\t\t\t\t\t\t\t\t\t Press any key to Go to Main Menu... : ");
			getch();
			system("cls");
			menu();					
		}
		else
			system("cls");
			header();
			printf("\n\t\t\t\t\t\t\t\t\t Please Enter Patient First Name Correctly !\n\n");
			printf("\t\t\t\t\t\t\t\t\t Press any key to Search Name Again  !");
			getch();
			system("cls");
			search();
}

	return 0;
}

int header(){
printf("\n\n\n\n\n");
printf("\t\t\t\t\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("\t\t\t\t\t\t\tXXX                                                                                                 XXX\n");
printf("\t\t\t\t\t\t\tXXX                                 Mobile PCR Data Collector                                       XXX\n");
printf("\t\t\t\t\t\t\tXXX                                                                                                 XXX\n");
printf("\t\t\t\t\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");

return 0 ;
}

int incorrect(){
		system("cls");
		header();
		printf("\n\n\t\t\t\t\t\t\t\t\t\t\tPlease Enter a correct option..  \n\n");
		printf("\t\t\t\t\t\t\t\t\t\t\tPress any key to go to Meain Menu....  \n");
		getch();
		system("cls");
		menu();
}









