#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char name[21];
	int code;
	struct data *left;
	struct data *right;
	
}*current, *newnode;

struct data *root = NULL;
int check = 0;

struct code_list{
	int numb;
	struct code_list *next;
}*curr , *new_node;

struct code_list *head = NULL;
struct code_list *tail= NULL;

int level = 1;

void input_code(int code){

	new_node = (struct code_list*)malloc(sizeof(struct code_list));

	curr = head;

	if (head == NULL){
       head = tail = new_node;
	   new_node->numb = code;
	   tail->next = NULL;
	}
	else{
		
		tail->next = new_node;
		tail = new_node;
		new_node->numb = code;
		tail->next = NULL;

	}

}

int check_code(int key){
     
	 int found = 0;
	 curr = head;

	 while(head != NULL){

		  if (curr->numb == key){
			  found = 1;
			  break;
		  }
		  curr = curr->next; 
	 }

	 if (found == 1){
        printf("\n* Tourism Object’s Code Cannot be the Same, Please Input Other Code *\n"); getchar();
		check = 1;
	 }
	 else{
		 printf("\n");
		 check = 0;
	 }
}

void input(){
	
	newnode = (struct data*)malloc(sizeof(struct data));
	newnode->left = NULL;
	newnode->right = NULL;

	
	current = root;
	if (root == NULL){
		
		do{
			printf("\n Input Tourism object's name[3..20]: ");
			scanf("%[^\n]", &*newnode->name); getchar(); fflush(stdin);
		} while(strlen(newnode->name)<3 || strlen(newnode->name)>20);
		
		do{
			printf("\n Input Tourism object's code[1..100]: ");
			scanf("%d", &newnode->code); getchar();
		}while(newnode->code < 1 || newnode->code > 100);

		input_code(newnode->code);
		
		printf("\n\n--- Add Tourism Object's Success ---\n");
		
		getchar();
		system("cls");
	}

	else if(root->left == NULL || root->right == NULL){

		char choice[10];

		do{
			printf("\n Input Tourism object's name[3..20]: ");
			scanf("%[^\n]", newnode->name); getchar();
		} while(strlen(&*newnode->name)<3 || strlen(newnode->name)>20);
 
	    do{
			printf("\n Input Tourism object's code[1..100]: ");
			scanf("%d", &newnode->code); check_code(newnode->code); getchar();
		}while(check == 1);

		input_code(newnode->code);
        
		do{
		printf("\n\nWill he be on 'left' or 'right' %s? : ", root->name);
		scanf("%s", &*choice);
		}while(strcmp(choice,"right") != 0 && strcmp(choice,"left") != 0);

		if (strcmp(choice,"right")==0){
			root->right = newnode;
		}
		else{
			root->left = newnode;
		}
		
		
		printf("\n\n--- Add Tourism Object's Success ---\n");
		
		getchar();
		system("cls");				
	}

	else{

		current = root;
		char choice[10];

		do{
			printf("\n Input Tourism object's name[3..20]: ");
			scanf("%[^\n]", &*newnode->name); getchar();
		} while(strlen(newnode->name)<3 || strlen(newnode->name)>20);

	    do{
			
			printf("\n Input Tourism object's code[1..100]: ");
			scanf("%d", &newnode->code); check_code(newnode->code); getchar();
		}while(check == 1 && (newnode->code < 1 || newnode->code > 100));

		input_code(newnode->code);

		while(current != NULL){

		do{
		printf("\n\nWill he be on 'left' or 'right' %s? : ", current->name);
		scanf("%s", &*choice);
		}while(strcmp(choice,"right") != 0 && strcmp(choice,"left") != 0);
        
        while(level < 4){

		if (strcmp(choice,"right")==0){
			current = current->right;
			level = level + 1;

			if(current == NULL){
				newnode = current;
			}

		}
		else{
			current = current->left;
            level = level + 1;
			if(current==NULL){
				newnode = current;
			}
		}
	  }

	  if(level >= 4){
		  printf("\n---Maximum Tree Level is 4---\n");
	  }

	  level = 1;
	  check = 0;
	}
		
	}	
	
}

void display(struct data *root){
     

	if(root == NULL){
      printf("\n-- There is No Tourism Object in The Tree --\n");
	} 
	else{
		printf("\nTourism Object List: \n");
		while (root != NULL)
		{
			printf("%-20s    %d\n", root->name, root->code);
		}
		display(root->left);
		display(root->right);
		
	}

}

void delete_all(struct data* root) {

    if(root){
        delete_all(root->left);
        delete_all(root->right);
        free(root);
    }
}

void deleteall(struct data *root){
	if(root != NULL){
		deleteall(root->left);
		deleteall(root->right);
		free(root);
	}
}

void delete_node(struct data **root, int code){
	if((*root) != NULL && code == (*root)->code){
        printf("--- The Tourism Object Has Been Removed ---\n\n");
   		deleteall(*root);
		(*root) = NULL;
	} else if((*root) != NULL){
		delete_node(&(*root)->left, code);
  		delete_node(&(*root)->right, code);
	} 
}

struct data *search(struct data *root, int code){
    if(root != NULL){
        if(root->code == code) {
            return root;
        } else {
            struct data *temp;
            temp = search(root->left, code);
            if(temp == NULL){
                temp = search(root->right, code);
            }

            return temp;
        }
    } else {
        return 0;
    }
}

struct data *delete_data(struct data *root, int code){
    struct data *temp = search(root, code);
    if(temp == 0){
        printf("\n--- The Tourism Object's Doesn`t Exist ---\n\n");
        return root;
    } else {
        if(temp == root){
            delete_node(&root, code);
            return NULL;
        } else {
            delete_node(&root, code);
            return root;
        }
    }
}

void preorder(struct data *root) {
    if(root) {
        printf(" %d", root->code);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct data *root) {
    if(root) {
        inorder(root->left);
        printf(" %d", root->code);
        inorder(root->right);
    }
}

void postorder(struct data *root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf(" %d", root->code);
    }
}

int main()
{


    int parameter = 1;
    char object_name[50];   
	int code;
    while(parameter == 1){
        printf("EAST JAVA TOURISM OBJECT CODE");
        printf("\n******************************\n");
        printf("1. View All Tourism Object\n");
        printf("2. Add Tourism Object\n");
        printf("3. Remove Tourism Object\n");
        printf("4. Indorder, Preorder, Postorder\n");
        printf("5. Exit\n");
        printf("\n>> Input choice : ");
        int menu;
        scanf("%d", &menu); fflush(stdin);
        switch(menu){
        	
        	case 1:
        		
        	if(root==NULL){
                printf("\n--- There is No Tourism Object in The Tree ---\n\n");
            } else {
                printf("\nTourism Object's' List :\n");
                display(root);
                printf("\n");
            }
             getchar();
             system("cls");
             getchar();
        		break;
        	
        	case 2: 
        	   input();
        	   getchar();
        	   system("cls");
        	   break;
        	   
        	case 3:
        		
        	if(root==NULL){
                printf("\n-- There is No Tourism Object in The Tree --”\n\n");
            } 
			else{
                int code = 0;
                do{
                    printf("Input Tourism Object's Code That You Want to Be Removed [1..100] : ");
                    scanf("%d", &code); getchar();
            }while (code < 1 || code > 100);
                root = delete_data(root, code);
            }
        	getchar();
        	system("cls");
        		break;
        		
        	case 4:
			 
        	if(root==NULL){
                printf("\n--- There is No Tourism Object in The Tree ---\n\n");
            } else {
                printf("\nPre-order: ");
                preorder(root);
                printf("\nIn-order: ");
                inorder(root);
                printf("\nPost-order: ");
                postorder(root);
                printf("\n\n");
            }
            getchar();
            system("cls");
            break;
            
            case 5:
            	printf("\nProgramm Closed , Thank you !\n");
            	parameter = 0;
            	break;
            	
            default: 
            
            printf("\nPlease Input The right menu\n");
            getchar();
            system("cls");
            break;
		}
    }

    return 0;
}
