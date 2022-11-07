#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movie{
	char name[21];
	char genre[30];
	int no;
	int price;
	struct move *next;
	struct movie *prev;
}*current, *newnode;

struct movie *head = NULL;
struct movie *tail = NULL;
	struct movie *before = NULL;
	struct movie *after = NULL;
	struct movie *temp = NULL;
int number = 1;

void insert(){

	newnode = (struct movie*)malloc(sizeof(struct movie));
	newnode->next = NULL;
	newnode->prev = NULL;
    
	do{
	printf("\nInput Movie Name [3...21]: ");
	scanf("%[^\n]", &*newnode->name); getchar();
	}while(strlen(newnode->name)<3 || strlen(newnode->name)>21);

	do
	{
		printf("\nInput Movie Genre [3...30]: ");
		scanf("%[^\n]", &*newnode->genre); getchar();
	} while (strlen(newnode->genre)<3 || strlen(newnode->genre)>30);

	do
	{
		printf("Input Movie Price [$ 10...1000]: $ ");
		scanf("%d", &newnode->price); getchar();
	} while (newnode->price < 10 || newnode->price > 1000);

	newnode->no = number;

	if (head == NULL){

		head = tail = newnode;
		newnode->next = newnode;
		newnode->prev = newnode;
	}
	else{

		tail->next = newnode;
		newnode->prev = tail;
		tail = tail->next;
		tail->next = head;
		head->prev = tail;
	}
	
	printf("\n---Add New Movie Succes---\n");
	number = number + 1;
	getchar();
	system("cls");
	getchar();
}

void delete_begin(){

	if (head == NULL){
		printf("\nNo data can be deleted\n");
	}
	else if(head == tail){

		current = head;
		head = tail = NULL;
		free(current);
		number = 1;
	}
	else{
		
		current = head;
		temp = current;
		while (temp != head->prev){
			temp->no = temp->no - 1;
			temp = temp->next;
		} 
		
		tail->no = tail->no - 1;
		
		head = head->next;
		head->prev = tail;
		tail->next= head;


		number = number - 1;
		free(current);
	}

}

void delete_last(){

	if (head == NULL){
		printf("\nNo data can be deleted\n");
	}
	else if(head == tail){

		current = head;
		head = tail = NULL;
		free(current);
		number = 1;
	}
	else{
		current = tail;
		tail = tail->prev;
		head->prev = tail;
		tail->next= head;
		number = number - 1;
		free(current);
		
	}

}

void delete_position(int key){
    
	current = head;
	int found = 0;

	if (head == NULL){
		printf("\nNo data\n");
	}
	else{
		while (current != NULL){
		if(current->no == key){
			found = 1;
			break;
		 }
		 current = current->next;
		}

		}
	

	if (found == 1){
		if(current == head){
			delete_begin();
		}
		else if(current == tail){
			delete_last();
		}
		else{
			
		    temp = current;
	    	while (temp != head ){
			temp->no = temp->no - 1;
			temp = temp->next;
			} 
			
			before = current->prev;
			after = current->next;

			before->next = after;
			after->prev = before;


		
		    number = number - 1;
			free(current);

		}
		printf("\n---Success---\n");
	}
	else{
		printf("\nData Not Found\n");
	}
}

void display(){
	current = head;
	printf("\n\t---MOVIE LIST---\n\n");
	printf("-+-----+----------------------------+---------------------------+---------+-\n");
	printf(" : No. :     Name of Movie          :         Genre             :   Price : \n");
	printf("-+-----+----------------------------+---------------------------+---------+-\n");

	if(head == NULL){
	printf("-+-----+----------------------------+---------------------------+---------+-\n");
	}
	else{
		do{
		printf(" : %2d. :    %-20s    :   %-20s   :   %3d   :\n", current->no, current->name, current->genre, current->price);
		current = current ->next;
	}while(current != head );
    printf("-+-----+----------------------------+---------------------------+---------+-\n");
  }
}

void delete_all(){
	while(head != NULL){
		delete_begin();
	}
}

void main(){

	int menu;
	int key;
	int parameter = 1;

    while(parameter == 1){
	printf("\tEXTRAVAGANT MOVIE SHOP\n");
	printf("\t=======================\n\n");
	printf("1. View Movie List\n");
	printf("2. Add New Movie\n");
	printf("3. Take Movie\n");
	printf("4. Exit\n");
	printf("Input Menu [1/2/3/4]: ");
	scanf("%d", &menu); fflush(stdin);

	switch (menu)
	{
	case 1:
		display();
		getchar();
		system("cls");
		break;
	
	case 2:
	    insert();
		break;
	case 3:
	    if(head == NULL){
			printf("\nNo Data\n");
			getchar();
		    system("cls");
		}
		else{
		display();
		printf("\nInput the Number of the Movie[%d...%d]: ", head->no, tail->no);
		scanf("%d", &key);
	    delete_position(key);
		getchar();
		system("cls");
		}
	    break;

	case 4:
	    printf("\n----Program Closed---\n");
		getchar();
		system("cls");
		delete_all();
		parameter = 0;
	    break;
	default :
	    
	    printf("\n---Please Input The Correct Menu---\n");
        getchar();
		system("cls");
	}
  }
}
