#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct visitor{
	
	char name[20];
	char address[10];
	int age;
	int number;
	struct visitor *next;
	
} *head, *current, *index, *newnode, *pPre;


int regist = 0;


void insert();
void delete_node();
void sort_ascending_age();
void sort_descending_numb();
void sort_descending_age();
void sort_ascending_numb();
void display();


void insert(){
	
	int A;
	char N[20], AD[20];
	newnode = (struct visitor*)malloc(sizeof(struct visitor));
	
	printf("Total Registration in this day : %d \n", regist);
	printf("Input Name   : ");
	scanf("%[^\n]", &N); fflush(stdin);
	printf("Input Address: ");
	scanf("%[^\n]", &AD);
	printf("Input Age    : ");
	scanf("%d", &A);
	
	newnode->age = A;
	strcpy(newnode->name, N);
	strcpy(newnode->address, AD);
	newnode->number = regist + 1;
	
	if(head == NULL){
		head = newnode;
		newnode->next = head;
	}
	else{
		
		current = head;
		while(current->next != head){
			current = current->next;
		}
		
		current->next = newnode;
		newnode->next = head;
	}
	getchar();
	regist = regist + 1;


	printf("\n-----Success-----\n");
	getchar();
	system("cls");
}

void delete_node(int a){
	
    current = head;
	while(current->number != a){
		
		if (current->next == head){
			printf("Sorry Data Not Found\n");
			getchar();
			system("cls");
			break;
		}
		
		pPre = current;
		current = current->next;
		
	}
	if (current->next == head){
		head = NULL;
		free(current);
		printf("\nSuccess\n");
		return;
	}
	
	if (current == head){

		pPre = head;
		while (pPre->next != head)
			pPre = pPre->next;
			head = current->next;
			pPre->next = head;
			free(current);
			printf("\nSuccess\n");
		
	
	}
    else if (current->next == head && current == head){
		pPre->next = head;
		free(current);
		printf("\nSuccess\n");
	}
	else{
		pPre->next = current->next;
		free(current);
		printf("\nSuccess\n");
	}
	
	
}

void sort_ascending_age(){
	
	
	index = NULL;
	current = head;
	index = current->next;
	int temp;
	char temp1[100];

	if(head == NULL){
		getchar();
		printf("\nThere is No List Available\n");
		getchar();
		system("cls");
	}
	else{
	     
		 do{
			while (index->next != head){
				if (current->age < index->age){
					
					temp = current->age;
					current->age = index->age;
					index->age = temp;
					
					temp = current->number;
					current->number = index->number;
					index->number = temp;
					
					strcpy(temp1, current->name);
					strcpy(current->name, index->name);
					strcpy(index->name, temp1);

					strcpy(temp1, current->address);
					strcpy(current->address, index->address);
					strcpy(index->address, temp1);
										
					
				}
				index = index->next;
			}
			current = current->next;
		}
		while(current!= head);
	}
}


void sort_descending_age(){
	
	index = NULL;
	current = head;index = current->next;
	int temp;
	char temp1[100];
	
	if(head == NULL){
		
		getchar();
		printf("\nThere is No List Available\n");
		getchar();
		system("cls");
	}
	else{
		 do{
			
			while (index != head){
				if (current->age > index->age){
					
					temp = current->age;
					current->age = index->age;
					index->age = temp;
					
					temp = current->number;
					current->number = index->number;
					index->number = temp;
					
					strcpy(temp1, current->name);
					strcpy(current->name, index->name);
					strcpy(index->name, temp1);

					strcpy(temp1, current->address);
					strcpy(current->address, index->address);
					strcpy(index->address, temp1);					
					
				}
				index = index->next;
			}
			current = current->next;
		}
		while(current->next != head);
	}
}

void sort_ascending_numb(){
	
	index = NULL;
	current = head;
	index = current->next;
	int temp;
	char temp1[100];
	
	if(head == NULL){
		
		getchar();
		printf("\nThere is No List Available\n");
		getchar();
		system("cls");
	}
	else{
		 do{
			while (index != head){
				if (current->number < index->number){
					
					temp = current->age;
					current->age = index->age;
					index->age = temp;
					
					temp = current->number;
					current->number = index->number;
					index->number = temp;
					
					strcpy(temp1, current->name);
					strcpy(current->name, index->name);
					strcpy(index->name, temp1);

					strcpy(temp1, current->address);
					strcpy(current->address, index->address);
					strcpy(index->address, temp1);					
					
				}
				index = index->next;
			}
			current = current->next;
		}
		while(current->next != head);
	}
}

void sort_descending_numb(){
	
	index = NULL;
	current = head;
	int temp;
	char temp1[100];
	
	if(head == NULL){
		
		getchar();
		printf("\nThere is No List Available\n");
		getchar();
		system("cls");
	}
	else{
		 do{
			index = current->next;
			while (index != head){
				if (current->number > index->number){
					
					temp = current->age;
					current->age = index->age;
					index->age = temp;
					
					temp = current->number;
					current->number = index->number;
					index->number = temp;
					
					strcpy(temp1, current->name);
					strcpy(current->name, index->name);
					strcpy(index->name, temp1);

					strcpy(temp1, current->address);
					strcpy(current->address, index->address);
					strcpy(index->address, temp1);					
					
				}
				index = index->next;
			}
			current = current->next;
		}
		while(current->next != head);
	}
}

void display(){
	
	int sort, choice, choice2;
	
	current = head;
	
	if (head == NULL){
		getchar();
		printf("\n------There is no List Available------\n");
		getchar();
		system("cls");
	}
	
	else
	{
		printf("Choose The sorting menu : \n");
		printf("1. Ascending\n");
		printf("2. Descending\n");
		printf("\n\nInput choice: ");
		scanf("%d", &sort);
		printf("-------------------------\n\n");
		if (sort == 1){
			printf("\nChoose the Ascending by: ");
			printf("\n1. Age");
			printf("\n2. Registration Number\n");
			printf("\nInput Choice : ");
			scanf("%d", &choice);
			if (choice == 1){
			    sort_ascending_age();
				getchar();
				system("cls");
					do{	
					current = current->next;
					printf("-------------------------\n");
					printf("Name   :  %s\n", current->name);
					printf("Address:  %s\n", current->address);
					printf("Age    :  %d\n", current->age);
					printf("Registration Number: %d", current->number);
					printf("\n-------------------------\n");
					
				} while(current->next != head); 
				getchar();
				system("cls");
				}
				
			
			
			else if(choice == 2){
				
				 if(current != NULL){
				 sort_ascending_numb();
				 	getchar();
				    system("cls");
				    
					do{
					printf("-------------------------\n");
					printf("Name   :  %s\n", current->name);
					printf("Address:  %s\n", current->address);
					printf("Age    :  %d\n", current->age);
					printf("Registration Number: %d", current->number);
					current = current->next;
					printf("\n-------------------------\n");
					
			
					 
				} while(current->next != head);
				getchar();
				system("cls");
				}
			
		}
	}
		
		else if (sort == 2){
			printf("\nChoose the Descending by: ");
			printf("\n1. Age");
			printf("\n2. Registration Number\n");
			printf("\nInput Choice : ");
			scanf("%d", &choice);
			if (choice == 1){
				if(current != NULL){
				sort_descending_age();
					getchar();
				system("cls");
					do{
					
					
					printf("-------------------------\n");
					printf("Name   :  %s\n", current->name);
					printf("Address:  %s\n", current->address);
					printf("Age    :  %d\n", current->age);
					printf("Registration Number: %d", current->number);
					current = current->next;
					printf("\n-------------------------\n");
					
					 ;
				} while(current->next != head);
				getchar();
				system("cls");
				}
				
			}
			else if(choice == 2){
				sort_descending_numb();
				    if (current != NULL){
					
				getchar();
				system("cls");
					do{	
					
					printf("-------------------------\n");
					printf("Name   :  %s\n", current->name);
					printf("Address:  %s\n", current->address);
					printf("Age    :  %d\n", current->age);
					printf("Registration Number: %d", current->number);
					current = current->next;
					printf("\n-------------------------\n");
					
				} while(current->next != head);
				getchar();
				system("cls");
				}			
			}
		}		

}
}

		


void main()
{
	int menu;
	int numb;

	while(menu != 4 && menu < 4){
	printf("\t-----Governance Library-----\n");
	printf("\t=============================\n");
	printf("\n\n");
	printf("Visitor Registration Menu:\n\n");
	printf("1. Add the Data\n");
	printf("2. Delete the Data\n");
	printf("3. Show the Data\n");
	printf("4. Exit\n");
	printf("\nInput Menu[1/2/3/4]: ");
	scanf("%d", &menu); fflush(stdin);
	printf("\n");

	switch (menu)
	{
	case 1:
		insert();
		break;
	
	case 2:
	    
		if (head != NULL){
		    printf("--------------------------\n");
			printf("Input the Registration Number to Delete from the list: ");
			scanf("%d", &numb);
			delete_node(numb);
			getchar();
			system("cls");
		}
		else{
			printf("\n------There is no List Available------\n");
			getchar();
			system("cls");
		}
		break;
	
	case 3:
	    display();
		break;
	
	case 4:
	    printf("\nThankyou Programm Closed\n");
        break;
	}

}
}


