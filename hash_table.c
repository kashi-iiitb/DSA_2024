/*****************************************************************************************
AUTHOR:	KASHINATH CHILLAL
DATE:	29th Feb 2024 
AIM:	Write a Program to demonstrate Hash table implementation in C
DESCRIPTION:
	1. Store employee details like "Name, age, sex, division" in hash table
    2. Use Name as key to store in hash table
    3. Use Linear probing for handling collision
INPUT:
    Employee Name
OUTPUT: 
    Employee details "Name, age, sex, division"
*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define HASH_TABLE_SIZE 10
#define DELETED_NODE (employee *)(0xFFFFFFFFFFFFFFFFUL)

typedef struct employee{
    char *name;
    int age;
    char sex;
    char *division;
} employee;

employee *emp_hash_tbl[HASH_TABLE_SIZE];

employee *create_new_emp(char* name, int age, char sex, char *division){
    employee *new_emp = malloc(sizeof(employee));
    if(!new_emp){
        printf("Error allocating memory for new employee\n");
        return NULL;
    }
    new_emp->name = malloc(strlen(name)+1);
    strcpy(new_emp->name, name);
    new_emp->age = age;
    new_emp->sex = sex;
    new_emp->division = malloc(strlen(division)+1);
    strcpy(new_emp->division, division);
    return new_emp;
}

int hash_func(char *name){
    char *ptr = name;
    unsigned int sum = 0;
    while(*ptr){
        sum += *ptr;
        //printf("%c",*ptr);
        ptr++;
    }
    return sum%10;
}
bool insert( char* name, int age, char sex, char *division){
    printf("inserting %s\n", name);
    int index = hash_func(name);
    printf("index is %d\n", index);

    employee *new_emp = create_new_emp(name, age, sex, division);
    
    for(int i=0; i<HASH_TABLE_SIZE; i++){
        int temp_index = (index + i) % HASH_TABLE_SIZE;
        if(emp_hash_tbl[temp_index]==NULL || emp_hash_tbl[temp_index]==DELETED_NODE){
            emp_hash_tbl[temp_index] = new_emp;
            printf("Inserted %s in emplyee database\n", name);
            return true;
        }
    }
    return false;    
}

void delete(char *name){
    printf("Deleting %s\n", name);
    int index = hash_func(name);
    printf("index is %d\n", index);
    for(int i=0; i<HASH_TABLE_SIZE; i++){
        int temp_index = (index + i) % HASH_TABLE_SIZE;
        if(!emp_hash_tbl[temp_index]){
            break;
        }
        if(!strcmp(emp_hash_tbl[temp_index]->name, name)){
            emp_hash_tbl[temp_index] = DELETED_NODE;
            printf("Deleted %s in emplyee database\n", name);
            return;
        }
    }
    printf("Unable to delete. Employee details of %s were not found\n",name);
}

void display_emp_details (employee *emp){
    printf("Name = %s\t age=%d\t sex=%c\t division=%s\n",
            emp->name, emp->age, emp->sex, emp->division);
}

void search(char *name){
    printf("searching %s\n", name);
    int index = hash_func(name);
    printf("index is %d\n", index);
    for(int i=0; i<HASH_TABLE_SIZE; i++){
        int temp_index = (index + i) % HASH_TABLE_SIZE;
        if(!emp_hash_tbl[temp_index]){
            break;
        }
        if(emp_hash_tbl[temp_index] == DELETED_NODE){
            continue;
        }
        if(!strcmp(emp_hash_tbl[temp_index]->name, name)){
            display_emp_details(emp_hash_tbl[temp_index]);
            return;
        }
    }
    printf("employee details of %s were not found\n",name);
}

void initialize_hash_tbl(){
    for(int i=0; i<HASH_TABLE_SIZE; i++){
        emp_hash_tbl[i] = NULL;
    }
}

int main(){

    initialize_hash_tbl();
    insert("Kashinath", 39, 'M', "Software Engineering");
    insert("Sunil", 45, 'M', "Data science");
    insert("Mahesh", 50, 'M', "Embedded systems");
    insert("Anil", 30, 'M', "Management");
    //insert("Kashinath", 39, 'M', "Software Engineering");
    //insert("Kashinath", 39, 'M', "Software Engineering");
    delete("Kashinath");
    search("Kashinath");
    search("Sunil");
    search("Anil");
    search("Mahesh");
    search("Sneha");
}