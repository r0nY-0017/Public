#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct EmployeeNode{
    int EmployeeID,age;
    char EmployeeName[20];
    float salary;
    struct EmployeeNode *back;
    struct EmployeeNode *next;
};

void print(struct EmployeeNode *p){
    while (p != NULL){
        printf("%d %s %d %.2f\n", p->EmployeeID, p->EmployeeName, p->age, p->salary);
        p = p->back;
    }
}

void create_List(struct EmployeeNode *p){
    p->back = NULL;
    int n, id, age;
    char nm[20];
    float sal;
    printf("Enter Number of Employee : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        printf("Enter Employee-%d data: ", i);
        scanf("%d %s %d %f", &id, nm, &age, &sal);
        p->EmployeeID = id;
        strcpy(p->EmployeeName, nm);
        p->age = age;
        p->salary = sal;
        
        if (i < n){
            struct EmployeeNode *temp = malloc(sizeof(struct EmployeeNode));
            p->next = temp;
            temp->back = p;
            p = p->next;
        }
    }
    p->next = NULL;
    print(p);
}

int main(){
    struct EmployeeNode *head = malloc(sizeof(struct EmployeeNode));
    create_List(head);
return 0;
}
