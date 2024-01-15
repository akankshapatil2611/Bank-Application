
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
#include "bank_validations.h"
static int c=0;
void create(struct Bank b[], int size)
{
	//struct Bank b[MAX];
    int i;
    char date[20];
    int choice;
    //int size;
    char bal_accno[7];
    char accNumb[7];
    for(i=0; i<size; i++)
    {
    	printf("Enter Record Number: %d\n",(i+1));
    	int isvalid3=0;
    	while(!isvalid3)
    	{
    		printf("\nEnter First Name= ");
        	fgets(b[c].f_holder_name, MAX, stdin);
        	b[c].f_holder_name[strlen(b[c].f_holder_name)-1]='\0';
        
        	printf("Enter Middle Name= ");
        	fgets(b[c].m_holder_name, MAX, stdin);
        	b[c].m_holder_name[strlen(b[c].m_holder_name)-1]='\0';
        
        	printf("Enter Last Name= ");
        	fgets(b[c].l_holder_name, MAX, stdin);
        	b[c].l_holder_name[strlen(b[c].l_holder_name)-1]='\0';
        	
        	if(isAlphaString(b[c].f_holder_name) &&
            isAlphaString(b[c].m_holder_name) &&
            isAlphaString(b[c].l_holder_name)){
            	isvalid3=1;
			}
			else{
				printf("Please enter valid names with only alphabetic characters.\n");
			}
		}
    	
        
        
        char accno[7];
        strcpy(accno, generate_accNo(b[c]));
        strcpy(b[c].acc_Numb, accno);
        
        
        int isValid5 = 0;
        int age;
        while (!isValid5) {
            printf("\nEnter Age: ");
        	scanf("%d", &age);

            if (isAgeValid(age)) {
                isValid5 = 1;
                b[c].age = age;
            } else {
                printf("Below 18 is not allowed.\n");
            }
        }
        
        
        
        getchar();
        int gch;
        printf("\nEnter Gender: \n Press 1. Male \t 2. Female  : ");
        scanf("%d", & gch);
        if(gch==1)
        	strcpy(b[c].gender, "Male");
        else if(gch==2)
			strcpy(b[c].gender, "Female");
		else
			printf("Invalid Choice");
			
		getchar();	
		
		int isValid = 0;
        while (!isValid) {
            printf("\nEnter Date of Birth: ");
            fgets(date, MAX, stdin);
            date[strlen(date) - 1] = '\0';

            if (isvalidDate(date)) {
                isValid = 1;
                strcpy(b[c].dob, date);
            } else {
                printf("Invalid date format. Please enter a valid date (DD/MM/YYYY). And date of year beyond 2023 is not Acceptable.\n");
            }
        }
        
        printf("\nEnter Address: ");
        fgets(b[c].address, MAX, stdin);
        b[c].address[strlen(b[c].address)-1]='\0';
        
        printf("\nEnter City: ");
		fgets(b[c].city, MAX, stdin);
        b[c].city[strlen(b[c].city)-1]='\0';
		
		int ach;
		printf("\nEnter Account Type: \n 1. current Account\t 2. Saving Account \t 3. Salary Account  : ");
		scanf("%d", &ach);
		if(ach==1)
			strcpy(b[c].acc_type, "current");	
		else if(ach==2)
			strcpy(b[c].acc_type, "saving");
		else if(ach==3)
			strcpy(b[c].acc_type, "salary");
		else
			printf("Invalid Choice");
			
		b[c].balance = 0;
		
		getchar();
		char pan[20];
		int isValid1 = 0;
        while (!isValid1) {
            printf("\nEnter PanCard Number: ");
            fgets(pan, MAX, stdin);
            pan[strlen(pan) - 1] = '\0';

            if (validatePan(pan)) {
                isValid1 = 1;
                strcpy(b[c].pan_card, pan);
            } else {
                printf("Please enter PanCard number in correct format .\n");
            }
        }
		
		char adhar[20];    
		int isValid2 = 0;
		while (!isValid2) {
    		printf("\nEnter Adhar Number: ");
    		fgets(adhar, MAX, stdin);
    		adhar[strlen(adhar) - 1] = '\0';

    		if (isAdharValid(adhar)) {  
        		isValid2 = 1;
        		strcpy(b[c].adhar_card, adhar);
    		} else {
        		printf("Please enter Aadhar number in correct format.\n");
    		}
		}
					
		printf("-----------------------------------------------------------------\n");		
        c++;
    }
}


void balanceEnquiry(struct Bank b[], char bal_accno[], int size)
{
	int i;
	int flag=0;
	for(i=0; i<c; i++)
	{
		if(strcmp(b[i].acc_Numb, bal_accno)==0)
		{
			flag=1;
			printf("Balance: %d\n", b[i].balance);
			break;
		}
	}
	if(flag==0)
	{
		printf("No such account Number is present\n");
	}
}

void display(struct Bank b[], int size)
{
	int i;
    for(i=0; i<c; i++)
    {
        //printf("%s\t %s\t %s\t %s\t %d\t %s\t %s\t %s\t %d\t \n", b[i].acc_Numb, b[i].f_holder_name, b[i].gender, b[i].dob, b[i].age, b[i].pan_card, b[i].adhar_card, b[i].acc_type, b[i].balance);
    	
    	printf("**************************************\n");
    	printf("Account Number: %s\n",b[i].acc_Numb);
    	printf("Account Holder Name: %s  %s  %s\n",b[i].f_holder_name, b[i].m_holder_name, b[i].l_holder_name);
    	printf("Gender: %s\n", b[i].gender);
    	printf("Date of Birth: %s\n", b[i].dob);
    	printf("Address: %s\n", b[i].address);
    	printf("City: %s\n", b[i].city);
    	printf("Account_Type:  %s\n", b[i].acc_type);
    	printf("Balance: %d\n", b[i].balance);
    	printf("Pan Card: %s\n", b[i].pan_card);
    	printf("Adhar Card: %s\n", b[i].adhar_card);
    	
	}
}

void deposite(struct Bank b[],char accNo[], int d_amt, int size)
{
	int i;
	int flag=0;
	for(i=0; i<c; i++)
	{
		if(strcmp(b[i].acc_Numb, accNo)==0)
		{
			b[i].balance += d_amt;
			flag=1;
			printf("Amount Deposited your current balance is %d\n", b[i].balance);
			break;
		}
	}
	if(flag==0)
	{
		printf("No such account Number is present\n");
	}
}

void withdraw(struct Bank b[],char accNo[], int w_amt, int size)
{
	int i;
	int flag=0;
	for(i=0; i<c; i++)
	{
		if(strcmp(b[i].acc_Numb, accNo)==0)
		{
			b[i].balance -= w_amt;
			flag=1;
			printf("Amount withdraw your current balance is %d\n", b[i].balance);
			break;
		}
	}
	if(flag==0)
	{
		printf("No such account Number is present\n");
	}
}

void searchByAccNo(struct Bank b[], char accNo[], int size)
{
	int i;
	int flag=0;
	for(i=0; i<c; i++)
	{
		if(strcmp(b[i].acc_Numb, accNo)==0)
		{
			printf("**************************************\n");
    		printf("Account Number: %s\n",b[i].acc_Numb);
    		printf("Account Holder Name: %s %s %s\n",b[i].f_holder_name, b[i].m_holder_name, b[i].l_holder_name);
    		printf("Gender: %s\n", b[i].gender);
    		printf("Date of Birth: %s\n", b[i].dob);
    		printf("Address: %s\n", b[i].address);
    		printf("City: %s\n", b[i].city);
    		printf("Account_Type:  %s\n", b[i].acc_type);
    		printf("Account_Type:  %s\n", b[i].acc_type);
    		printf("Balance: %d\n", b[i].balance);
    		printf("Pan Card: %s\n", b[i].pan_card);
    		printf("Adhar Card: %s\n", b[i].adhar_card);
    		flag=1;
		}
	}
	if(flag==0){
		printf("No such account Number is present\n");
	}
}

void searchByAccType(struct Bank b[], char acctype[], int size)
{
	int i;
	int flag=0;
	for(i=0; i<c; i++)
	{
		if(strcmp(b[i].acc_type, acctype)==0)
		{
			printf("**************************************\n");
    		printf("Account Number: %s\n",b[i].acc_Numb);
    		printf("Account Holder Name: %s  %s  %s\n",b[i].f_holder_name, b[i].m_holder_name, b[i].l_holder_name);
    		printf("Gender: %s\n", b[i].gender);
    		printf("Date of Birth: %s\n", b[i].dob);
    		printf("Address: %s\n", b[i].address);
    		printf("City: %s\n", b[i].city);
    		printf("Account_Type:  %s\n", b[i].acc_type);
    		printf("Balance: %d\n", b[i].balance);
    		printf("Pan Card: %s\n", b[i].pan_card);
    		printf("Adhar Card: %s\n", b[i].adhar_card);
    		flag=1;
		}
	}
	if(flag==0){
		printf("No such account type is present\n");
	}
}

void searchByName(struct Bank b[], char fname[], char lname[], int size)
{
	int i;
	int flag=0;
	for(i=0; i<c; i++)
	{
		if((strcmp(b[i].f_holder_name, fname)==0 )&& (strcmp(b[i].l_holder_name, lname)==0))
		{
			printf("**************************************\n");
    		printf("Account Number: %s\n",b[i].acc_Numb);
    		printf("Account Holder Name: %s  %s  %s\n",b[i].f_holder_name, b[i].m_holder_name, b[i].l_holder_name);
    		printf("Gender: %s\n", b[i].gender);
    		printf("Date of Birth: %s\n", b[i].dob);
    		printf("Address: %s\n", b[i].address);
    		printf("City: %s\n", b[i].city);
    		printf("Account_Type:  %s\n", b[i].acc_type);
    		printf("Balance: %d\n", b[i].balance);
    		printf("Pan Card: %s\n", b[i].pan_card);
    		printf("Adhar Card: %s\n", b[i].adhar_card);
    		flag=1;
		}
	}
	if(flag==0){
		printf("No such Account holder name is present\n");
	}
}

void updateData(struct Bank b[], char acc_no[], int size)
{
	int flag=0;
	int i;
	int isValid4 = 0;
	char date[20];
	for(i=0; i<c; i++)
	{
		if(strcmp(b[i].acc_Numb, acc_no)==0)
		{
			flag=1;
			int ch;
			do{
			printf("1) Update Account Holder Name: \n");
			printf("2) Update Address of Account Holder: \n");
			printf("3) Update DOB of Account Holder: \n");
			printf("4) Exit\n");
			getchar();
			printf("Enter Your Choice: ");
			scanf("%d", &ch);
			getchar();
			switch(ch){
				case 1:
					printf("\nEnter First Name to update= ");
        			fgets(b[i].f_holder_name, MAX, stdin);
        			b[i].f_holder_name[strlen(b[i].f_holder_name)-1]='\0';
        
        			printf("Enter Middle Name to update= ");
        			fgets(b[i].m_holder_name, MAX, stdin);
        			b[i].m_holder_name[strlen(b[i].m_holder_name)-1]='\0';
        
        			printf("Enter Last Name to update= ");
        			fgets(b[i].l_holder_name, MAX, stdin);
        			b[i].l_holder_name[strlen(b[i].l_holder_name)-1]='\0';
        			break;
        		
				case 2:
					printf("\nEnter Address: ");
        			fgets(b[i].address, MAX, stdin);
        			b[i].address[strlen(b[i].address)-1]='\0';	
        			break;
        			
        		case 3:
        			while (!isValid4) {
            			printf("\nEnter Date of Birth: ");
            			fgets(date, MAX, stdin);
            			date[strlen(date) - 1] = '\0';

            			if (isvalidDate(date)) {
                			isValid4 = 1;
                			strcpy(b[i].dob, date);
            			} else {
                			printf("Invalid date format. Please enter a valid date (DD/MM/YYYY). And date of year beyond 2023 is not Acceptable.\n");
            			}
        			}	
        			break;
        			
        		case 4:
					break;	
					
				default:
					printf("\n Invalid Choice\n");
					break; 	
			}
		}while(ch!=4);
			 
		}
	}
	if(flag==0){
		printf("No such account Number is present\n");
	}
}


void fundTransfer(struct Bank b[] , int n)
{
int i;
  getchar();
  char accNo[10];
  char accNo1[10];
  int s_found=0, r_found=0;
  do{
  printf("\nEnter the account number from which to transfer funds: ");
  fgets(accNo,10,stdin);
  accNo[strlen(accNo)-1] = '\0';
  for(i=0; i<c; i++)
	{
		if((strcmp(b[i].acc_Numb, accNo)==0))
		{
			s_found=1;
		}
	}
	if(s_found==0){
		printf("Sender Account Number Not Found! Please enter Again\n");
	}
  }while(s_found==0);
  
  do{
  printf("\nEnter the account number to which to transfer funds: ");
  fgets(accNo1,10,stdin);
  accNo1[strlen(accNo1)-1] = '\0';
  	for(i=0; i<c; i++)
	{
		if((strcmp(b[i].acc_Numb, accNo1)==0))
		{
			r_found=1;
		}
	}
	if(r_found==0){
		printf("receiver Account Number Not Found! Please enter Again\n");
	}
	}while(r_found==0);
	
	
	if(r_found==1 && s_found==1)
	{
		printf("Enter the amount to transfer: ");
  		int amount;
  		scanf("%d",&amount);
  		getchar();
  
  		if(amount == 0 || amount < 0){
    		printf("Invalid amount\n");
    		return;
  		}
  		
  		int flag = 0;
  		for(i=0;i<c;i++){
    		if(strcmp(b[i].acc_Numb,accNo) == 0)
    		{
      			if(b[i].balance >= amount)
      			{
        			b[i].balance -= amount;
        			flag=1;
      			}
    		}    
  		}
  		if(flag == 1)
  		{
    		for(i=0;i<c;i++)
      		{
        		if(strcmp(b[i].acc_Numb,accNo1) == 0)
        		{
          			b[i].balance += amount;
          			printf("Amount transfered from %s account to %s account",accNo,accNo1);
        		}
      		}
  		}
  		else{
    		printf("Insufficient balance");
  		}
	}
	else
  	{
  		printf("\nNo such Account Found\n");
  	}
  
}

void search(struct Bank b[], int size)
{
	int ch;
	int acc_ch;
	char accNos[6];
	char fname[MAX], mname[MAX], lname[MAX];
	char acctype[10];
	do{
		printf("\n1. Search By Account Number\n");
		printf("2. Search By Account Type\n");
		printf("3. Search By Account holder name\n");
		printf("4. Exit\n");
		getchar();
		printf("Enter Your Choice: ");
		scanf("%d", &ch);
		getchar();
		switch(ch)
		{
			case 1:	
    			printf("Enter Account Number to search Record: ");
    			fgets(accNos, MAX, stdin);
    			accNos[strlen(accNos) - 1] = '\0';
    			searchByAccNo(b, accNos, size);
    			break;
    			
    		case 2:
    			printf("\nEnter Account type to search records: \n 1. current Account\t 2. Saving Account \t 3. Salary Account  : ");
    			scanf("%d", &acc_ch);
    			if(acc_ch==1){
    				searchByAccType(b, "current", size);
				}
				else if(acc_ch==2){
					searchByAccType(b, "saving", size);
				}
				else if(acc_ch==3){
					searchByAccType(b, "salary", size);
				}
				else{
					printf("Invalid Type of data");
				}
				break;
			
			case 3:
				getchar();
				printf("\nEnter First Name to Search Data: ");
				fgets(fname, MAX, stdin);
    			fname[strlen(fname) - 1] = '\0';
    			printf("\nEnter Last Name to Search Data: ");
				fgets(lname, MAX, stdin);
    			lname[strlen(lname) - 1] = '\0';
    			searchByName(b, fname, lname, size);	
    			break;
    		
			case 4:
				break;	
			
			default:
					printf("\n Invalid Choice\n");
					break;	
		}
	}while(ch!=4);	
}

void swap(struct Bank *a, struct Bank *b) {
    struct Bank temp = *a;
    *a = *b;
    *b = temp;
}

int alphanumericCompare(char *str1, char *str2) {
    return strcmp(str1, str2);
}

void sortDataByAccNo(struct Bank b[], int size) {
    int i, j;

    for (i = 0; i < c - 1; i++) {
        for (j = 0; j < c - i - 1; j++) {
            if (alphanumericCompare(b[j].acc_Numb, b[j + 1].acc_Numb) > 0) {
                swap(&b[j], &b[j + 1]);
            }
        }
    }
}

int main()
{
	printf("\n*************************Welcome to Indian Bank*************************\n");
    struct Bank b[MAX];
    int i;
    char date[20];
    int choice;
    int size;
    char bal_accno[7];
    char accNumb[7];
   	do{
   		printf("\n\n***********************\n");
   		printf("1. Create Account\n");
   		printf("2. Deposite Amount\n");
   		printf("3. Withdraw Amount\n");
   		printf("4. Search Records\n");
   		printf("5. Update Records\n");
   		printf("6. Funds Transfer\n");
   		printf("7. Display Records\n");
   		printf("8. Sort Records\n");
   		printf("9. Balance Enquiry\n");
   		printf("10. Exit");
   		
   		printf("\nEnter Your Choice: ");
   		scanf("%d", &choice);
   		getchar();
   		
   		switch(choice)
   		{
   			case 1:
   				printf("\nHow Many Records Do you want to Enter: ");
    			scanf("%d", &size);
    			getchar();
    			create(b,size);
				break;
   				
   			case 2:
   				printf("\n*******Deposite Amount*******");
   				// deposite
    			int damt;
    			char accNo[6];
    			printf("\nEnter Account Number to Deposite Amount: ");
    			fgets(accNo, MAX, stdin);
    			accNo[strlen(accNo) - 1] = '\0';
   				printf("\nEnter Deposite Amount: ");
    			scanf("%d", &damt);
    			deposite(b,accNo, damt,size);
				break;	
				
			case 3:
				printf("\n*******Withdraw Amount*******");
				getchar();
    			// withdraw
    			int wamt;
    			char accNo1[6];
    			printf("\nEnter Account Number to Withdraw Amount: ");
    			fgets(accNo1, MAX, stdin);
    			accNo1[strlen(accNo1) - 1] = '\0';
    			printf("\nEnter Withdraw Amount: ");
    			scanf("%d", &wamt);
    			withdraw(b,accNo1, wamt,size);
				break;
				
			case 4:
				printf("\n*******Search Records*******");
				search(b,size);
				break;
				
			case 5:
				printf("\n*******Update Records*******");
				printf("\nEnter Account Number to update data: ");
				fgets(accNumb, MAX, stdin);
    			accNumb[strlen(accNumb) - 1] = '\0';
				updateData(b, accNumb, size);
				break;
				
			case 6:
				printf("\n*******Fund Transfer*******");
				fundTransfer(b,size);
				break;
				
			case 7: 
				printf("\n*******Display Records*******\n");
				display(b,size);	
				break;	
				
				
			case 8:
				printf("\n*******Sort Records According to Account Number*******\n");	
				sortDataByAccNo(b, size);
				display(b,size);
				break;
				
			case 9:
				printf("\n*******Balance Enquiry*******");
				printf("\nEnter Account Number: ");
				fgets(bal_accno, MAX, stdin);
    			bal_accno[strlen(bal_accno) - 1] = '\0';
				balanceEnquiry(b, bal_accno, size);
				break;
			
			case 10:
				break;
			
			default:
				printf("\n Invalid Choice\n");
				break;						
		}
		   	
	}while(choice!=10);
	
    return 0;
}

