#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct admin
{
    int no;
    char name[20];
    char type[20];
    char address[30];
    char phone[12];
    struct admin *next;
}*current, *newnode;

struct admin *head = NULL;
struct admin *top = NULL;

int number = 0;
char message_non_available[]=("\nThere are no Information Available\n");

void insert(){

    
    char name[20], address[30], phone[12], type[20];
    
     newnode = (struct admin*)malloc(sizeof(struct admin));

        do{
        printf("\nInput name of person/company/society[3...20]: ");
        scanf("%[^\n]", &*name); getchar();
        }while(strlen(name) < 3 || strlen(name) > 20);
        
        do{
        printf("\nInput the Type of New Entry Name [person/company/society]: ");
        scanf("%[^\n]", &*type);  getchar();
        }while(strcmp(type,"person") != 0 && strcmp(type,"company")!=0 && strcmp(type,"society")!=0);
        
        do
        {
        printf("\nInput Address of New Entry[6...20]: ");
        scanf("%[^\n]", &*address); getchar();
        } while (strlen(address)<6 || strlen(address)>20);

        do
        {
        printf("\nInput Phone of New Entry Name [9...12]: ");
        scanf("%[^\n]", &*phone); getchar();
        } while (strlen(phone)<9 || strlen(phone)> 12);    

     strcpy(newnode->name, name);
     strcpy(newnode->type,type);
     strcpy(newnode->address, address);
     strcpy(newnode->phone, phone);
     newnode->no = number + 1;


     if (head == NULL){
         head = top = newnode;
     }
     else{
         top->next = newnode;
         top = newnode;
     }
     top->next = NULL;
     number = number +1;
     getchar();
     printf("\nAdd New Information Success\n");
     getchar();
     system("cls");
}

void delete_node(){
	
    current = head;
    
    if (head == NULL){
        printf("%s", message_non_available);
        getchar();
        system("cls");
    }
    else if (head == top){
        head = top = NULL;
        printf("The information about %s(%s) is being delete\n", current->name, current->type);
        getchar();
        system("cls");
        free(current);
    }
    else{
        struct admin *bantu = NULL;
        bantu = head;

        while(bantu->next != top){
            bantu = bantu->next;
        }

        current = top;
        top = bantu;
        printf("The information about %s(%s) is being delete\n", current->name, current->type);
        getchar();
        system("cls");
		top->next = NULL;
        free(current);

        
      }
      

}

void pop(){
    current=top;

    if(top== NULL){
        printf("\n");
    }
    else if(top==head){
        head = top = NULL;
        free(current);
    }
    else{
    struct admin *bantu = NULL;
    bantu = head;

    while(bantu->next != top){
        bantu = bantu->next;
    }
    top = bantu;    
    free(current);
    top->next = NULL;
    }
    
}

void delete_all(){

    current = head;
    
    if (head == NULL){
        printf("%s", message_non_available);
        getchar();
        system("cls");
    }
    else{
    while (head != NULL){
    	pop();
	}
    printf("\nAll information has been deleted\n");
    getchar();
    system("cls");
	}

    }



void display(){
	
	current = head;
	
	printf("\n\t-----INFORMATION LIST-----\n\n\n");
	printf("------+----------------------+----------+----------------------+----------------\n");
	printf("| No. | Name                 | Type     |   Address            |   Phone      |\n");
	printf("------+----------------------+----------+----------------------+----------------\n");
	
	if(head==NULL){

    printf("------+----------------------+----------+----------------------+----------------\n\n");	 
	getchar();
	system("cls");	
	}
	
	else{
   do{
	printf("| %2d. | %-20s | %-8s | %-20s | %-12s |\n", current->no, current->name, current->type, current->address, current->phone);
	current = current->next;
    } while(current != NULL);
	printf("------+-----------------------+----------+---------------------+---------------\n\n");	
	getchar();
	system("cls");
 }
}


void main(){

    int menu;


    while(menu != 5){

    printf("INFROMATION ADMISNISTRATOR\n");
    printf("===========================\n\n");
    printf("1. Information List\n");
    printf("2. Add (PUSH) New Information\n");
    printf("3. Delete (POP) Lastest Information\n");
    printf("4. Delete All (POP ALL) Information\n");
    printf("5. Exit\n");
    printf("\n\nInput Menu[1/2/3/4/5]: ");
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
       delete_node();
       number = number - 1;
       break;
    
    case 4:
       delete_all();
       number = 0;
       break;
       
    case 5:
    	printf("\n--------Thank you, Program Closed-----------\n");
    	break;
    }
    
getchar();    
system("cls");

 }
 
}


