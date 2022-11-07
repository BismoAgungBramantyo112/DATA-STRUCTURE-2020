#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct customer{
    int age;
    char name[20];
    char type[10];
    int cost;
    struct customer *next;
}*current, *newnode;

struct customer *front = NULL;
struct customer *rear = NULL;

int number = 1;
char message_non_available[]=("\nThere is no Customer to Serve\n");

void insert(){

    
     newnode = (struct customer*)malloc(sizeof(struct customer));

        printf("\nInput Customer's Name: ");
        scanf("%[^\n]", &*newnode->name); fflush(stdin);
        
        do{
        printf("\nInput Age of Customer [1..100]: ");
        scanf("%d", &newnode->age); getchar();
        }while(newnode->age <= 1 || newnode->age >= 100);
        
        do
        {
        printf("\nInput Type of Service [Hair Spa / Hair Cut / Massage]: ");
        scanf("%[^\n]", &*newnode->type); getchar();
        } while (strcmp(newnode->type,"Hair Spa") != 0 && strcmp(newnode->type,"Hair Cut") != 0 && strcmp(newnode->type,"Massage")!=0);

        do
        {
        printf("\nInput Cost [10000...500000]: ");
        scanf("%d", &newnode->cost); getchar();
        } while (newnode->cost <= 10000 || newnode->cost >= 500000);    


     if (front == NULL){
         front = rear = newnode;
     }
     else{
         rear->next = newnode;
         rear = newnode;
     }
     rear->next = NULL;
     getchar();
     printf("\n---Add New Customer Success---\n");
     getchar();
     system("cls");
}

void service(){
	
    current = front;
    
    if (front == NULL){
        printf("%s", message_non_available);
        getchar();
        system("cls");
    }
    else if (front == rear){
        front = rear = NULL;
        printf("\n%s has been served.\n", current->name);
        getchar();
        system("cls");
        free(current);
    }
    else{
    	
    	front = front->next;
        printf("\n%s has been served.\n", current->name); 
        getchar();
        system("cls");
        free(current);

        
      }
      

}




void display(){
	
	current = front;
	
	printf("\n\t-----INFORMATION LIST-----\n\n\n");
	printf("------+----------------------+----------+----------------------+--------------\n");
	printf("| No. | Customer Name        | Age      |   Type of Service    |   Cost       |\n");
	printf("------+----------------------+----------+----------------------+--------------\n");
	
	if(front==NULL){

    printf("------+----------------------+----------+----------------------+--------------\n\n");	 
	getchar();
	system("cls");	
	}
	
	else{
   do{
	printf("| %2d. | %-20s | %8d | %-20s | %12d |\n", number, current->name, current->age, current->type, current->cost);
	current = current->next;
	number ++;
    } while(current != NULL);
	printf("------+----------------------+----------+---------------------+---------------\n\n");	
	getchar();
	number = 1;
	system("cls");
 }
}


void main(){

    int menu;


    while(menu != 4){

    printf("\tHAIR AND SPA\n");
    printf("+++++++++++++++++++++++++++++\n\n");
    printf("1. Customer List\n");
    printf("2. Add Customer\n");
    printf("3. Take Service\n");
    printf("4. Exit\n");
    printf("\n\n>>Input your choice [1/2/3/4]: ");
    scanf("%d", &menu); fflush(stdin);
    
    switch (menu)
    {
    	
    case 1:
        display();
        break;
    
    case 2:
    	
    	insert();

        break;
    
    case 3:
       service();
       number = 1;
       break;
    
    case 4:
    	printf("\n--------Thank you, Program Closed-----------\n");
    	break;
    }
    
getchar();    
system("cls");

 }
 
}
