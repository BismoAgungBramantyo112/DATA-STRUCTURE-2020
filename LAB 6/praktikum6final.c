#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct family
{
    char name[20];
    char choice[20];
    struct family *next;
    struct family *prev;
} *current, *newnode;

struct family *head = NULL;
struct family *tail = NULL;

int cake_counter = 0;
int money_counter = 0;
int holiday_counter = 0;


char message_cake[]=("we will give a fancy yummy cake as a gift on a family member's birthday");
char message_money[]=("we will give amount of money as a gift on a family member's birthday");
char message_holiday[]=("we will give a holiday trip as a gift on a family member's birthday");

int number = 1;

void add_first(char name[20], int choice){
    
    newnode=(struct family*)malloc(sizeof(struct family));
    newnode->next = NULL;
    newnode->prev = NULL;

    strcpy(newnode->name, name);
    if (choice == 1){
    	strcpy(newnode->choice,"Fancy yummy cake");
	}
	else if(choice == 2){
		strcpy(newnode->choice,"Holiday trip");
	}
	else if(choice == 3){
		strcpy(newnode->choice, "Money");
	}
    

    if(head == NULL){
        
        head = tail = newnode;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    getchar();
    system("cls");
}

void add_last(char name[20], int choice){
    
    newnode=(struct family*)malloc(sizeof(struct family));
    newnode->next = NULL;
    newnode->prev = NULL;

    strcpy(newnode->name, name);
    if (choice == 1){
    	strcpy(newnode->choice,"Fancy yummy cake");
	}
	else if(choice == 2){
		strcpy(newnode->choice,"Holiday trip");
	}
	else if(choice == 3){
		strcpy(newnode->choice, "Money");
	}

    if(head == NULL){
        
        head = tail = newnode;
    }
    else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    getchar();
    system("cls");
}

void input(){
    
    int choice;
    int type;
    char name[20];

    printf("1. Add before the first data\n");
    printf("2. Add after the last data\n");
    printf("Input Your Choice [1/2]: ");
    scanf("%d", &choice); fflush(stdin);

    switch(choice){
        case 1: 
        printf("Input family member's name: ");
        scanf("%[^\n]", &name); fflush(stdin);

        do{
        printf("\n 1 = Fancy yummy cake    2 = Holiday trip    3 = Money\n");
        printf("Select the birthday gift [1/2/3]: ");
        scanf("%d", &type); getchar();
        }while(type != 1 && type != 2 && type != 3);

        if(type == 1){
            cake_counter = cake_counter + 1;
            
        }
        else if(type == 2 ){
            holiday_counter = holiday_counter + 1;
            
        }
        else if (type == 3)
        {
            money_counter = money_counter + 1;
            
        }
        

        add_first(name, type);

        break;

        case 2:

        printf("Input family member's name: ");
        scanf("%[^\n]", &name); fflush(stdin);

        do{
        printf("\n 1 = Fancy yummy cake    2 = Holiday trip    3 = Money\n");
		printf("Select the birthday gift [1/2/3]: ");
        scanf("%d", &type); getchar();
        
        }while(type != 1 && type != 2 && type != 3);

        if(type == 1){
            cake_counter = cake_counter + 1;
            
        }
        else if(type == 2){
            holiday_counter = holiday_counter + 1;
            
        }
        else if (type == 3)
        {
            money_counter = money_counter + 1;
            
        }
        

        add_last(name, type);
    }


}

void delete_first(){
    if (head == NULL){
        printf("\n---no data can be deleted---\n");
        getchar();
        system("cls");
    }
    else if(head == tail){

        current = head;

        if(strcmp(current->choice,"Fancy yummy cake")==0){
            cake_counter = cake_counter - 1;
            
        }
        else if(strcmp(current->choice,"Holiday trip")==0){
            holiday_counter = holiday_counter - 1;
            
        }
        else if (strcmp(current->choice,"Money")==0)
        {
            money_counter = money_counter - 1;
            
        }

        head = tail = NULL;
        printf("\n\n---- %s's opinion has been deleted----", current->name);
        getchar();
        system("cls");
        free(current);
    }
    else{
        current = head;

        if(strcmp(current->choice,"Fancy yummy cake")==0){
            cake_counter = cake_counter - 1;
            
        }
        else if(strcmp(current->choice,"Holiday trip")==0){
            holiday_counter = holiday_counter - 1;
            
        }
        else if (strcmp(current->choice,"Money")==0)
        {
            money_counter = money_counter - 1;
            
        }

        head = head -> next;
        current->next = NULL;
        head->prev = NULL;
        printf("\n\n---- %s's opinion has been deleted----", current->name);
        free(current);
        getchar();
        system("cls");
    }
}

void delete_last(){
    if (head == NULL){
        printf("\n---no data can be deleted---\n");
        getchar();
        system("cls");
    }
    else if(head == tail){

        current = tail;
        
        if(strcmp(current->choice,"Fancy yummy cake")==0){
            cake_counter = cake_counter - 1;
            
        }
        else if(strcmp(current->choice,"Holiday trip")==0){
            holiday_counter = holiday_counter - 1;
            
        }
        else if (strcmp(current->choice,"Money")==0)
        {
            money_counter = money_counter - 1;
            
        }

        head = tail = NULL;
        
        printf("\n\n---- %s's opinion has been deleted----", current->name);
        getchar();
        system("cls");
        free(current);
    }
    else{
        current = tail;

        if(strcmp(current->choice,"Fancy yummy cake")==0){
            cake_counter = cake_counter - 1;
            
        }
        else if(strcmp(current->choice,"Holiday trip")==0){
            holiday_counter = holiday_counter - 1;
            
        }
        else if (strcmp(current->choice,"Money")==0)
        {
            money_counter = money_counter - 1;
            
        }

        tail = tail->prev;
        current->prev = NULL;
        tail->next = NULL;
        printf("\n\n---- %s's opinion has been deleted----", current->name);
        free(current);
        getchar();
        system("cls");
    }
}

void delete_data(){
    int choice;
    printf("\n1= Remove the first data\n");
    printf("2= Remove the last data\n");
    do{
    printf("\nInput your choice [1/2]: ");
    scanf("%d", &choice); getchar();
    }while(choice != 1 && choice != 2);
    switch(choice){

        case 1:
        delete_first();
        break;

        case 2:
        delete_last();
        break;
    }
}

void delete_all(){
	
    while(head != NULL){
        current = head;
        head = head->next;
        free(current);
    }
 cake_counter = 0;
 money_counter = 0;
 holiday_counter = 0;
 
 printf("\n---Success---\n");
 getchar();
 system("cls");
}

void display(){

    current = head;

    if (head == NULL){
        printf("\t--- Determining a birthday gift ---\n\n");
		printf("==============================================================\n");
		printf("| No.  | Family member's name   |       Birthday gift        |\n");
		printf("==============================================================\n");
		printf(":                                                            :\n");
		printf(":                     --- no data here ---                   :\n");
		printf(":                                                            :\n");
		printf("==============================================================\n\n\n");
    }
    else{
        printf("\t--- Determining a birthday gift ---\n\n");
		printf("==============================================================\n");
		printf("| No.  | Family member's name   |       Birthday gift        |\n");
		printf("==============================================================");

        do{
            printf("\n: %2d. : %-12s            : %-20s       :", number, current->name, current->choice);
            
            if(current==head){
				printf("<-- Head ");
			}
			if(current==tail){
				printf("<-- Tail\n");
			}
            current = current->next;
            number++;
        }while(current != NULL);
        printf("==============================================================\n\n\n");
        number = 1;

    }
}

int main(){

    int menu;
    int parameter = 1;
    while(parameter == 1){
    
    display();
    printf("1. Add Polling Data\n");
    printf("2. Delete a Polling Data\n");
    printf("3. Show the Polling Result\n");
    printf("4. Delete list\n");
    printf("5. Exit\n\n");
    do{
    printf(">> Input Your Choice [1/2/3/4/5]: ");
    scanf("%d", &menu); getchar();
    }while(menu != 1 && menu != 2 && menu != 3 && menu != 4 && menu != 5);
    switch(menu){
        
        case 1: 
            input();
        break;

        case 2:
			delete_data();
        break;

        case 3:
        	printf("\nThe Polling Result so far are, \n");
        	printf("Fancy yummy cake : %d , Holiday trip: %d , Money = %d \n", cake_counter, holiday_counter, money_counter);
        	
        	if (cake_counter > holiday_counter && cake_counter > money_counter){
        		printf("\nBased on this polling, \n%s\n", message_cake);
			}
			else if (holiday_counter > cake_counter && holiday_counter > money_counter){
				printf("\nBased on this polling, \n%s\n", message_holiday);
			}
			else if (money_counter > holiday_counter && money_counter > cake_counter){
				printf("\nBased on this polling, \n%s\n", message_money);
			}
			else{
				printf("\ninsert or remove a polling data.\n");
			}
			getchar();
			system("cls");
        break;
        
        case 4:
        	if (head == NULL){
        		printf("\n---no data can be deleted---\n");
        		getchar();
        		system("cls");
			}
			else{
				delete_all();
			}
        	
        break;
        
        case 5:
        	printf("\n-----Thank You , Program closed----\n");
        	parameter = 0;
        break;

    }

    }
}
