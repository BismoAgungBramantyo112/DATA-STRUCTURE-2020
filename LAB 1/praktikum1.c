#include <stdio.h>
#include <string.h>

struct product{
	char *name; 
	char *code; 
	int stock;
	int price;
	
}a[101];

int main()
{
	int menu;
	int total;
	char kode[100], kode2[101];
	int quantity, stock_quantity;
	int stck;
	int parameter = 1;
	
//definisi produk 1
a[0].code = "MB007";
a[0].name = "Charging Cable";
a[0].price = 50000;
a[0].stock = 21;

//definisi produk 2
a[1].code = "MB010";
a[1].name = "Foldable Stand";
a[1].price = 65000;
a[1].stock = 15;

//definisi produk 3
a[2].code = "MB014";
a[2].name = "Bluetooth Speaker";
a[2].price = 75000;
a[2].stock = 25;

//definisi produk 4
a[3].code = "MB019";
a[3].name = "Screen Protector";
a[3].price = 90000;
a[3].stock = 20;

//definisi produk 5
a[4].code = "MB025";
a[4].name = "Cyrstal Clear Case";
a[4].price = 125000;
a[4].stock = 17;

//definisi produk 6
a[5].code = "MB028";
a[5].name = "Power Bank";
a[5].price = 240000;
a[5].stock = 26;

//definisi produk 7
a[6].code = "MB031";
a[6].name = "Wireless Charging Stand";
a[6].price = 300000;
a[6].stock = 10;	
	
    printf("BLINK MOBILE PHONE ACCECORIES SHOP CASHIER\n");
	printf("=============================================\n\n");
	
	while (parameter == 1){
		

	printf("No. :  Code  : Product Name             :  Available :  Price\n");
	printf("-------------------------------------------------------------------\n");
	printf("1.  : MB007  : Charging Cable           :         %d : Rp. 50000,- \n", a[0].stock);
	printf("2.  : MB010  : Foldable stand           :         %d : Rp. 65000,- \n", a[1].stock);
	printf("3.  : MB014  : Bluetooth Speaker        :         %d : Rp. 75000,- \n", a[2].stock);
	printf("4.  : MB019  : Screen Protector         :         %d : Rp. 90000,- \n", a[3].stock);
	printf("5.  : MB025  : Crystal Clear Case       :         %d : Rp. 125000,- \n", a[4].stock);
	printf("6.  : MB028  : Power Bank               :         %d : Rp. 240000,- \n", a[5].stock);
	printf("7.  : MB031  : Wireless Charging Stand  :         %d : Rp. 300000,- \n", a[6].stock);
	printf("--------------------------------------------------------------------\n");
	printf("\n\nMenu : \n");
	printf("1. Sell\n");
	printf("2. Add Stock\n");
	printf("3. Exit\n");
	printf("\nInput Choice [1/2/3] : ");
	scanf("%d", &menu); fflush(stdin);
	
	switch(menu)
	{
		case 1: 
		printf("Input Product Code [5 chars]: ");
		scanf("%s", &kode); fflush(stdin);
		
		if (strcmp(kode, "MB007")==0){
			printf("Input Quantity [0....%d]: ", a[0].stock);
		    scanf("%d", &quantity);
		    if (quantity > a[0].stock || quantity < 0){
		    	printf("...The Quantity of Mobile Phone Accecories is Not Enough...\n\n");
			}  
		    else {
		    total = quantity * a[0].price;	
			a[0].stock = a[0].stock - quantity;   	
		    printf("\nTotal Price is : Rp. %d,- x %d = Rp %d,-", a[0].price , quantity, total);
		    printf("\n--Thank You--\n\n");
			}

		}
		else if (strcmp(kode, "MB010")==0){
			printf("Input Quantity [0....%d]: ", a[1].stock);
		    scanf("%d", &quantity);
		    if (quantity > a[1].stock || quantity < 0){
		    	printf("...The Quantity of Mobile Phone Accecories is Not Enough...\n\n");
			}  
		    else {
		    total = quantity * a[1].price;
			a[1].stock = a[1].stock - quantity;	 		    	
		    printf("\nTotal Price is : Rp. %d,- x %d = Rp %d,-", a[1].price , quantity, total);
		    printf("\n--Thank You--\n\n");
			}
		}
		else if (strcmp(kode, "MB014")==0){
			printf("Input Quantity [0....%d]: ", a[2].stock);
		    scanf("%d", &quantity);
		    if (quantity > a[2].stock || quantity < 0){
		    	printf("...The Quantity of Mobile Phone Accecories is Not Enough...\n\n");
			}  
		    else {
		    total = quantity * a[2].price;
			a[2].stock = a[2].stock - quantity;	 		    	
		    printf("\nTotal Price is : Rp. %d,- x %d = Rp %d,-", a[2].price , quantity, total);
		    printf("\n--Thank You--\n\n");
			}
		}		
		else if (strcmp(kode, "MB019")==0){
			printf("Input Quantity [0....%d]: ", a[3].stock);
		    scanf("%d", &quantity);
		    if (quantity > a[3].stock || quantity < 0){
		    	printf("...The Quantity of Mobile Phone Accecories is Not Enough...\n\n");
			}  
		    else {
		    total = quantity * a[3].price;
			a[3].stock = a[3].stock - quantity;	 		    	
		    printf("\nTotal Price is : Rp. %d,- x %d = Rp %d,-", a[3].price , quantity, total);
		    printf("\n--Thank You--\n\n");
			}
		}
		else if (strcmp(kode, "MB025")==0){
			printf("Input Quantity [0....%d]: ", a[4].stock);
		    scanf("%d", &quantity);
		    if (quantity > a[4].stock || quantity < 0){
		    	printf("...The Quantity of Mobile Phone Accecories is Not Enough...\n\n");
			}  
		    else {
		    total = quantity * a[4].price;
			a[4].stock = a[4].stock - quantity;	 		    	
		    printf("\nTotal Price is : Rp. %d,- x %d = Rp %d,-", a[4].price , quantity, total);
		    printf("\n--Thank You--\n\n");
			}
		}
		else if (strcmp(kode, "MB028")==0){
			printf("Input Quantity [0....%d]: ", a[5].stock);
		    scanf("%d", &quantity);
		    if (quantity > a[5].stock || quantity < 0){
		    	printf("...The Quantity of Mobile Phone Accecories is Not Enough...\n\n");
			}  
		    else {
		    total = quantity * a[5].price;
			a[5].stock = a[5].stock - quantity;	 		    	
		    printf("\nTotal Price is : Rp. %d,- x %d = Rp %d,-", a[5].price , quantity, total);
		    printf("\n--Thank You--\n\n");
			}
		}
		else if (strcmp(kode, "MB031")==0){
			printf("Input Quantity [0....%d]: ", a[6].stock);
		    scanf("%d", &quantity);
		    if (quantity > a[6].stock || quantity < 0){
		    	printf("...The Quantity of Mobile Phone Accecories is Not Enough...\n\n");
			}  
		    else {
		    total = quantity * a[6].price;
			a[6].stock = a[6].stock - quantity;	 		    	
		    printf("\nTotal Price is : Rp. %d,- x %d = Rp %d,-", a[6].price , quantity, total);
		    printf("\n--Thank You--\n\n");
			}
		}
		 else {
			printf("---The Mobile Phone Accecories Code doesn't Exist---\n\n");
		}
		break;
		
	    case 2:
	    	printf("Input Product Code: ");
	    	scanf("%s", &kode2); fflush(stdin);
	    	
	    	if (strcmp(kode2, "MB007")==0){
	    		
	    	printf("Input Quantity[1..100]: ");
	    	scanf("%d", &stock_quantity);
	    	
	    	if(stock_quantity <= 100 && stock_quantity > 0){
			a[0].stock = a[0].stock + stock_quantity;
	    	printf("---Adding Stock Success---\n\n");
			}
			else {
				printf("Only 1 until 100\n\n");
			}
	    	
			}
			
			else if(strcmp(kode2, "MB010")==0){
	    	printf("Input Quantity[1..100]: ");
	    	scanf("%d", &stock_quantity);
	    	
	    	if(stock_quantity <= 100 && stock_quantity > 0){
			a[1].stock = a[1].stock + stock_quantity;
	    	printf("---Adding Stock Success---\n\n");
			}
			else {
				printf("Only 1 until 100\n\n");
			}				
			}
			
			else if(strcmp(kode2, "MB014")==0){
	    	printf("Input Quantity[1..100]: ");
	    	scanf("%d", &stock_quantity);
	    	
	    	if(stock_quantity <= 100 && stock_quantity > 0){
			a[2].stock = a[2].stock + stock_quantity;
	    	printf("---Adding Stock Success---\n\n");
			}
			else {
				printf("Only 1 until 100\n\n");
			}
			}
			
			else if(strcmp(kode2, "MB019")==0){
	    	printf("Input Quantity[1..100]: ");
	    	scanf("%d", &stock_quantity);
	    	
	    	if(stock_quantity <= 100 && stock_quantity > 0){
			a[3].stock = a[3].stock + stock_quantity;
	    	printf("---Adding Stock Success---\n\n");
			}
			else {
				printf("Only 1 until 100\n\n");
			}
			}
			
			else if(strcmp(kode2, "MB025")==0){
	    	printf("Input Quantity[1..100]: ");
	    	scanf("%d", &stock_quantity);
	    	
	    	if(stock_quantity <= 100 && stock_quantity > 0){
			a[4].stock = a[4].stock + stock_quantity;
	    	printf("---Adding Stock Success---\n\n");
			}
			else {
				printf("Only 1 until 100\n\n");
			}
			}
	    	
	    	else if(strcmp(kode2,"MB028")==0){
	    	printf("Input Quantity[1..100]: ");
	    	scanf("%d", &stock_quantity);
	    	
	    	if(stock_quantity <= 100 && stock_quantity > 0){
			a[5].stock = a[5].stock + stock_quantity;
	    	printf("---Adding Stock Success---\n\n");
			}
			else {
				printf("Only 1 until 100\n\n");
			}
			}
			
			else if(strcmp(kode2,"MB031")==0){
	    	printf("Input Quantity[1..100]: ");
	    	scanf("%d", &stock_quantity);
	    	
	    	if(stock_quantity <= 100 && stock_quantity > 0){
			a[6].stock = a[6].stock + stock_quantity;
	    	printf("---Adding Stock Success---\n\n");
			}
			else {
				printf("Only 1 until 100\n\n");
			}
			}
			
		 else {
			printf("---The Mobile Phone Accecories Code doesn't Exist---\n\n");
		} 	
		break;	
		
		case 3:
			printf("Programm Clossed, Thank You\n");
			parameter = 0;		
		
	}
		
}
}
