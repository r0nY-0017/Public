#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct hotel{
    char name[20];
    int room_no;
    char arrival_date[10];
    char departure_date[10];
    struct hotel *next;
};

void Create_List(struct hotel *p){
    int n,room;
    char name[20], d1[10], d2[10];
    printf("Enter Number of Customer : ");
    scanf("%d", &n); //number of customer
    for(int i=1; i<=n; i++){
        printf("Enter Customer-%d data: ", i);
        scanf("%s %d %s %s", name, &room, d1, d2);
        strcpy(p->name, name);
        p->room_no = room;
        strcpy(p->arrival_date ,d1);
        strcpy(p->departure_date, d2);

        if(i<n){
            struct hotel *temp = malloc(sizeof(struct hotel));
            p->next = temp;
            p = p->next;
        }
    }
    p->next = NULL;
}

void print_List(struct hotel *p){
    printf("\nYour Linked List are :\n");
    while(p != NULL){
        printf("%s %d %s %s\n", p->name, p->room_no, p->arrival_date, p->departure_date);
        p = p->next;
    }
}

int main(){
    struct hotel *head = malloc(sizeof(struct hotel));
    Create_List(head);
    print_List(head);
}
