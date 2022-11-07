#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tenant{
	char name[20];
	char car[20];
	int queue;
	struct tenant *next;
}*head , *tail , *current, *temp;

void tambah(int queue, char name[], char car[]){
	
	current = (struct tenant*)malloc(sizeof(struct tenant));
	
	strcpy(current->name, name);
	strcpy(current->car, car);
	current->queue = queue;
	
	if(head == NULL){
		
		head = tail = current;
	}
	else{
		tail->next = current;
		tail = current;
	}
	
	tail->next = NULL;
}

void service(){ 
	
	current = head;
	
	if (head == NULL){
		printf("---There Are No List Available---\n\n");
	}
	else if(head == tail){
		head = tail = NULL;
		free(current);
	}
	else
	{
		head = head->next;
		free(current);
	}

}


void pop_tail()
{

		
	if (head == NULL){
		printf("---There Are No List Available---\n\n");
	}	
	else if(head == tail){
		head = tail = NULL;
	    free(current);
	}
	else
	{
		struct tenant *temp = head;
		while (temp->next != tail){
			temp = temp->next;
		}
		
		current = tail;
		tail = temp;
		free(current);
		tail->next = NULL;
		
	}

}
	
	
void hapus(int queue){
	
	int bantu;
	bantu = 0;
	
	if (head == NULL){
		printf("---There Are No List Available---\n\n");
	}
	else
	{
		current = head;
		while(current != NULL){
			if(current->queue == queue){
				bantu=1;
				break;
			}
			current = current->next;
	}
		
	}
	if(bantu==1){
		if(current == head){
			service();
		}
		else if(current == tail){
			pop_tail();
		}
		else{
			current = temp->next;
			temp->next=temp->next->next;
			free(current);
		}
	} 
}

void print()
{
	
	current = head;
	
	if (head == NULL){
		printf("---There Are No List Available---\n");
	}
	else {
	
	while (current != NULL){
		printf("Number of List : %d\n", current->queue);
		printf("Name           : %s\n", current->name);
		printf("Brand of Car   : %s\n\n", current->car);
		current = current->next;
	}	
 }	
}

int main()
{
	int menu;
	int q;
	char n[20];
	char c[20]; 
	int del;
	int parameter = 1;
	
	
    while (parameter==1){
	
	
	printf("\t---Alamo Rental Car---\n");
	printf("\t======================\n\n");
	printf("Menu:\n");
	printf("1. View Tenant's List\n");
	printf("2. New Tenant\n");
	printf("3. Service\n");
	printf("4. Delete Tenant\n");
	printf("5. Exit\n");
	printf("Select Menu [1/2/3/4/5]: ");
	scanf("%d", &menu); fflush(stdin);
	printf("\n");
	switch(menu){
		
		case 1:
			system("cls");
			print();
			printf("\n\n");
			break;
		
		case 2:
			printf("Input Number of List: ");
			scanf("%d", &q); fflush(stdin);
			printf("Input Name: ");
			scanf("%[^\n]", &n); fflush(stdin);
			printf("Input Brand of Car: ");
			scanf("%[^\n]", &c);
			tambah(q,n,c);
			
			system("cls");
			break;
			
		case 3:
			
			system("cls");
		    if(head != 0){
		    printf("----The Rental Service Has Been Successful----\n\n");
		    }
			 
		    service();
		    
		    
		    break;
		
		case 4: 
		    system("cls"); 
		    print();
		    if (head != 0){
			
		    printf("\nInput The Number you want to Delete: ");
		    scanf("%d", &del);
		    hapus(del);
		    printf("\n---Success---\n\n");
		}
		    
		    break;
		    
		case 5:
			system("cls");
			printf("\n---Programm closed, Thank You---\n");
			parameter = 0;
			break;
	}
  }
  
}
