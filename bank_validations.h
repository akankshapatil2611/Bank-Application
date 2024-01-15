#ifndef BANK_VALIDATIONS_H
#define BANK_VALIDATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct Bank{
    char acc_Numb[7];
    char f_holder_name[MAX];
    char m_holder_name[MAX];
    char l_holder_name[MAX];
    int age;
    char gender[10];
    char dob[20];
    char address[20];
    char city[20];
    char acc_type[10];
    int balance;
    char pan_card[20];
    char adhar_card[20];
}b[MAX];



int isAgeValid(int age)
{
	if(age<18)
	{
		return 0;
	}
	return 1;
}

int isAlphaString(char str[]) 
{
	int i; 
    for (i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

char * generate_accNo(struct Bank b)
{
    char accNo[7];
    char f=b.f_holder_name[0];
    char fst[2] = {f , '\0'};
    char m=b.m_holder_name[0];
    char mst[2]= {m , '\0'};
    char l=b.l_holder_name[0];
    char lst[2] = {l , '\0'};
    strcat(accNo,fst);
    strcat(accNo,mst);
    strcat(accNo,lst);
    int set = rand() % 900 + 100;
    char random[5];
    sprintf(random, "%d", set);
    return strcat(accNo, random);;
}

/*char * generate_accNo(struct Bank b, char fname[], char mname[], char lname[])
{
		
}*/


int isvalidDate(char date[])
{
	int i, j, k;
    if(strlen(date)==10){
        
    for(i=0; i<=1; i++){
        if(!isdigit(date[i])){
            return 0;
        }
    }
    if(date[2]!='/'){
        return 0;
    }
    for(j=3; j<=4; j++){
        if(!isdigit(date[j])){
            return 0;
        }
    }
    if(date[5]!='/'){
        return 0;
    }
    for(k=6; k<=9; k++){
        if(!isdigit(date[k])){
            return 0;
        }
    }
    int year = atoi(date + 6);
        if (year > 2023) {
            return 0;
        }
    return 1;
    }
    return 0;
}

int validatePan(char pan[])
{
	int i,j;
    if(strlen(pan)!=10){
        return 0;
    }
    else {
        for(i=0; i<=4; i++)
        {
            if(! isupper(pan[i])){
                return 0;
            }
        }
        for(j=5; j<=8; j++){
            if(!isdigit(pan[j])){
                return 0;
            }
        }
        if(! isupper(pan[9]))
            return 0;
        
    }
    return 1;
}

int isAdharValid(char adhar[])
{
	int i;
    if(strlen(adhar)==12)
    {
        for(i=0; i<12; i++)
        {
            if(!isdigit(adhar[i])){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

#endif // BANK_VALIDATIONS_H
