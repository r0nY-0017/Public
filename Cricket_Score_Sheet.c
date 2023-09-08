#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> //For Using Sleep Funtion.....

//Batsman information.........
struct batsman{
    int sl,run,ball;
    struct batsman *next;
};
//Bowler information........
struct bowler{
    int sl,over,run, wct;
    struct bowler *next;
};
//Function Declaration...........
void main();
void Choose(struct batsman *p1, struct bowler *p2);
void Create_Sheet(struct batsman *p1, struct bowler *p2);
void view_batsman_sheet(struct batsman *p1, struct bowler *p2);
void view_bowler_sheet(struct batsman *p1, struct bowler *p2);
void Show_Info(struct batsman *p1, struct bowler *p2);
void Add_Info(struct batsman *p1, struct bowler *p2);
void Del_Info(struct batsman **p1, struct bowler **p2);


/*---------------------------------------------------------------------Main Code---------------------------------------------------------*/
void Choose(struct batsman *p1, struct bowler *p2){
    int n,x;
    Sleep(300);
    printf("\n\n-------------------------------------------------------Menu----------------------------------------------------------\n\n");
    Sleep(300);
    printf("\t\t\t\t\t\t1.New Scoresheet\n");
    Sleep(300);
    printf("\t\t\t\t\t\t2.View Scoresheet\n");
    Sleep(300);
    printf("\t\t\t\t\t\t3.Special Features\n");
    Sleep(300);
    printf("\t\t\t\t\t\t4.Exit\n\n");
    Sleep(300);
    printf("\t\t\t\t\t\tChoose your choice : ");
    scanf("%d", &n);

    if(n==1) Create_Sheet(p1, p2);
    else if(n==2){
        x=-6996;
        while(x!=1 && x!=2 && x!=3){
            Sleep(300);
            if(x!=-6996) printf("\n\t\t*****Please Enter Correct one!!*****\n");
            Sleep(300);
            printf("\t\t--------View Sheet--------\n");
            Sleep(300);
            printf("\t\t1.Batsman Scoresheet\n");
            Sleep(300);
            printf("\t\t2.Bowling Sheet\n");
            Sleep(300);
            printf("\t\t3.Back\n");
            Sleep(300);
            printf("\n\t\tChoose One : ");
            scanf("%d", &x);
        }
        if(x==1) view_batsman_sheet(p1, p2);
        else if(x==2) view_bowler_sheet(p1,p2);
        else if(x==3) Choose(p1,p2);
    }

    else if(n==3){
        x=-6996;
        while(x!=1 && x!=2 && x!=3 && x!=4){
            Sleep(300);
            if(x!=-6996) printf("\n\t\t*****Please Enter Correct one!!*****\n");
            Sleep(300);
            printf("\t\t~~~~~~ Special Feature ~~~~~~~\n");
            Sleep(300);
            printf("\t\t1.Show Information\n");
            Sleep(300);
            printf("\t\t2.Add Information\n");
            Sleep(300);
            printf("\t\t3.Delete Information\n");
            Sleep(300);
            printf("\t\t4.Back\n");
            Sleep(300);
            printf("\n\t\tChoose One : ");
            scanf("%d", &x);
        }
        if(x==1) Show_Info(p1,p2);
        else if(x==2) Add_Info(p1,p2);
        else if(x==3) Del_Info(&p1,&p2);
        else Choose(p1,p2);
    }

    else if(n==4) exit(0);

    else{
        Sleep(300);
        printf("\n\t\t\t\t********** Please Choose Correct One! **********\n\n");
        Sleep(300);
        Choose(p1, p2);
    }
}

//Batsman View
void view_batsman_sheet(struct batsman *p1, struct bowler *p2){
    struct batsman *head_bat = p1;
    struct bowler *head_ball = p2;

    int n,x;
    if(p1->next==NULL && p1->run>10000){
        Sleep(300);
        printf("\n\t\t-----------No ScoreSheet Found! Please Create a Scoresheet First! Thank You-----------\n\n");
        Sleep(300);
        Choose(head_bat, head_ball);
        return;
    }

    Sleep(300);
    printf("\n\t\t----------------------------------------------------------------------------\n");
    Sleep(300);
    printf("\t\t|\tBatsman\t\t|\tRun\t|\tBall\t|   Strick Rate\t   |\n");
    Sleep(300);
    printf("\t\t----------------------------------------------------------------------------\n");
    while(p1 != NULL){
        float strick_rate = (((float)p1->run)/p1->ball) * 100.0 ;
        Sleep(300);
        printf("\t\t|\tBatsman-%d\t|\t%d\t|\t%d\t|   %.2f\t   |\n", p1->sl, p1->run, p1->ball, strick_rate);
        Sleep(300);
        printf("\t\t----------------------------------------------------------------------------\n");
        p1 = p1->next;
    }
    Sleep(300);
    Choose(head_bat, head_ball);
}

//Bowler View
void view_bowler_sheet(struct batsman *p1,struct bowler *p2){
    struct batsman *head_bat = p1;
    struct bowler *head_ball = p2;

    int n,x;
    if(p2->next==NULL && p2->run>10000){
        Sleep(300);
        printf("\n\t\t-----------No Bowling Sheet Found! Please Create a Scoresheet First! Thank You-----------\n\n");
        Sleep(300);
        Choose(head_bat, head_ball);
        return;
    }

    Sleep(300);
    printf("\n\t\t---------------------------------------------------------------------------------\n");
    Sleep(300);
    printf("\t\t| Bowler\t|\tOver\t|\tRun\t|\tWicket\t|\tEconomy\t|\n");
    Sleep(300);
    printf("\t\t---------------------------------------------------------------------------------\n");

    while(p2 != NULL){
        float eco = ((float)p2->run) / p2->over;
        Sleep(300);
        printf("\t\t| Bowler-%d\t|\t%d\t|\t%d\t|\t%d\t|\t%.2f\t|\n", p2->sl, p2->over, p2->run, p2->wct, eco);
        Sleep(300);
        printf("\t\t---------------------------------------------------------------------------------\n");
        p2 = p2->next;
    }
    Sleep(300);
    Choose(head_bat, head_ball);
}



//For Create Score Sheet............
void Create_Sheet(struct batsman *p1, struct bowler *p2){
    struct batsman *head_bat = p1;
    struct bowler *head_ball = p2;

    //Omuk vs Tomuk Print
    char bat_team[25], bowl_team[25];
    Sleep(300);
    printf("\n\t\tEnter Batting Team Name: ");
    scanf("%s", bat_team);
    Sleep(300);
    printf("\t\tEnter Bowling Team Name: ");
    scanf("%s", bowl_team);
    Sleep(300);
    printf("\n\t\t----------------------------------------------------------------------------\n");
    Sleep(300);
    printf("\t\t|\t    %s", bat_team);
    int x = 35-strlen(bat_team)-12;
    for(int i=1; i<=x; i++) printf(" "); printf("| VS |");
    printf("\t    %s", bowl_team);
    x = 35-strlen(bowl_team)-12;
    for(int i=1; i<=x; i++) printf(" "); printf("|\n");
    Sleep(300);
    printf("\t\t----------------------------------------------------------------------------\n\n\n");


    //Btasman info Collect then Print
    int n,a,b, run=0, ball=0;
    Sleep(300);
    printf("\n\t\tEnter Number of Batsman (Min 2): ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        Sleep(300);
        printf("\t\tEnter Batsman-%d data(Run,Ball): ", i);
        scanf("%d %d", &a, &b);
        p1->sl = i;
        p1->run = a;
        p1->ball = b;

        if(i<n){
            struct batsman *temp1 = malloc(sizeof(struct batsman));
            p1->next = temp1;
            p1 = p1->next;
        }
    }
    p1->next = NULL;
    p1 = head_bat;
    Sleep(300);
    printf("\n\t\t----------------------------------------------------------------------------\n");
    Sleep(300);
    printf("\t\t|\tBatsman\t\t|\tRun\t|\tBall\t|   Strick Rate\t   |\n");
    Sleep(300);
    printf("\t\t----------------------------------------------------------------------------\n");
    while(p1 != NULL){
        run+= p1->run;
        ball+= p1->ball;
        float strick_rate = (((float)p1->run)/p1->ball) * 100.0 ;
        Sleep(300);
        printf("\t\t|\tBatsman-%d\t|\t%d\t|\t%d\t|   %.2f\t   |\n", p1->sl, p1->run, p1->ball, strick_rate);
        Sleep(300);
        printf("\t\t----------------------------------------------------------------------------\n");
        p1 = p1->next;
    }
    int over = ball/6;
    ball = ball%6;
    printf("\t\t%s: %d-%d(%d.%d)\n", bat_team, run, n-2, over, ball);


    //Bowler Infooo Collect then print.........
    int m,d,e,f;
    Sleep(300);
    printf("\n\n\n\t\tEnter Number of Bowler (Min 2): ");
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        Sleep(300);
        printf("\t\tEnter Bowler-%d data(Over,Run,Wct): ", i);
        scanf("%d %d %d", &d, &e, &f);
        p2->sl = i;
        p2->over = d;
        p2->run = e;
        p2->wct = f;

        if(i<m){
            struct bowler *temp2 = malloc(sizeof(struct bowler));
            p2->next = temp2;
            p2 = p2->next;
        }
    }
    p2->next = NULL;
    p2 = head_ball;
    Sleep(300);
    printf("\n\t\t---------------------------------------------------------------------------------\n");
    Sleep(300);
    printf("\t\t| Bowler\t|\tOver\t|\tRun\t|\tWicket\t|\tEconomy\t|\n");
    Sleep(300);
    printf("\t\t---------------------------------------------------------------------------------\n");

    while(p2 != NULL){
        float eco = ((float)p2->run) / p2->over;
        Sleep(300);
        printf("\t\t| Bowler-%d\t|\t%d\t|\t%d\t|\t%d\t|\t%.2f\t|\n", p2->sl, p2->over, p2->run, p2->wct, eco);
        Sleep(300);
        printf("\t\t---------------------------------------------------------------------------------\n");
        p2 = p2->next;
    }
    Sleep(300);
    printf("\n\n\t\t--------That's Look's Nice! Ahh? *-*---------\n");
    Choose(head_bat, head_ball);
}


void Show_Info(struct batsman *p1, struct bowler *p2){
    struct batsman *head_bat = p1;
    struct bowler *head_ball = p2;
    int x,n;
        x=-6996;
        while(x!=1 && x!=2){
            Sleep(300);
            if(x!=-6996) printf("\n\t\t*****Please Enter Correct one!!*****\n");
            Sleep(300);
            printf("\t\t--------Welcome to Information Portal--------\n");
            Sleep(300);
            printf("\t\tYou Want to See........\n");
            Sleep(300);
            printf("\t\t1.Batsman Information\n");
            Sleep(300);
            printf("\t\t2.Bowler Information\n");
            Sleep(300);
            printf("\n\t\tChoose One : ");
            scanf("%d", &x);
        }

        if(x==1){
            n=-6996;
            while(n<1 || n>11){
                if(n!=-6996){
                    Sleep(300);
                    printf("\t\t-----Please Enter Correct One(1-11)!-----\n");
                }
                Sleep(300);
                printf("\t\tWhich Batsman's Information You Want to see? : ");
                scanf("%d", &n);
            }

            Sleep(300);
            printf("\n\n\t\t%dth-Batsman Information: \n", n);
            int cnt=1;
            while(cnt!=n){
                if(p1->next==NULL) break;
                p1 = p1->next;
                cnt++;
            }

            if(cnt!=n || p1->run>3000){
                Sleep(300);
                printf("\t\t----Information Not Found!----\n");
                Sleep(300);
                Choose(head_bat, head_ball);
            }
            else{
                Sleep(300);
                printf("\t\tName            : Batsman-%d\n", n);
                Sleep(300);
                printf("\t\tRun             : %d\n", p1->run);
                Sleep(300);
                printf("\t\tBall            : %d\n", p1->ball);
                Sleep(300);
                printf("\t\tStrick Rate     : %.2f\n\n", (((float)p1->run)/p1->ball) * 100.0);
                Choose(head_bat, head_ball);
            }
        }


        if(x==2){
            n=-6996;
            while(n<1 || n>11){
                if(n!=-6996){
                    Sleep(300);
                    printf("\t\t-----Please Enter Correct One(1-11)!-----\n");
                }
                Sleep(300);
                printf("\t\tWhich Bowlers's Information You Want to see? : ");
                scanf("%d", &n);
            }

            Sleep(300);
            printf("\n\n\t\t%dth-Bowler's Information: \n", n);
            int cnt=1;
            while(cnt!=n){
                if(p2->next == NULL) break;
                p2 = p2->next;
                cnt++;
            }

            if(cnt!=n || p2->run >3000){
                Sleep(300);
                printf("\t\t----Information Not Found!----\n");
                Choose(head_bat, head_ball);
            }
            else{
                Sleep(300);
                printf("\t\tName            : Bowler-%d\n", n);
                Sleep(300);
                printf("\t\tOver            : %d\n", p2->over);
                Sleep(300);
                printf("\t\tRun             : %d\n", p2->run);
                Sleep(300);
                printf("\t\tWicket          : %d\n", p2->wct);
                Sleep(300);
                printf("\t\tEconomy         : %.2f\n\n", (((float)p2->run)/p2->over));
                Sleep(300);
                Choose(head_bat, head_ball);
            }
        }
}




void Add_Info(struct batsman *p1, struct bowler *p2){
    struct batsman *head_bat = p1;
    struct bowler *head_ball = p2;
    int x,n,cnt;
    x=-6996;
    while(x!=1 && x!=2){
        Sleep(300);
        if(x!=-6996) printf("\n\t\t*****Please Enter Correct one!!*****\n");
        Sleep(300);
        printf("\t\t--------Welcome to Adding Portal--------\n");
        Sleep(300);
        printf("\t\tYou Want to Add........\n");
        Sleep(300);
        printf("\t\t1.Batsman Information\n");
        Sleep(300);
        printf("\t\t2.Bowler Information\n");
        Sleep(300);
        printf("\n\t\tChoose One : ");
        scanf("%d", &x);
    }

    if(x==1){
        int a,b;
        Sleep(300);
        printf("\n\t\tEnter New Batsman Information(Run,Ball) : ");
        scanf("%d %d", &a, &b);
        if(p1->next==NULL){
            p1->sl = 1;
            p1->run = a;
            p1->ball = b;
        }
        else{
            struct batsman *temp = malloc(sizeof(struct batsman));
            temp->run = a;
            temp->ball = b;
            temp->next = NULL;

            cnt=1;
            while(p1->next != NULL){
                p1 = p1->next;
                cnt++;
            }
            temp->sl = cnt+1;
            p1->next = temp;
        }
        Sleep(300);
        printf("\t\t-----Adding New Batsman Information Succesfully!-----");
        Choose(head_bat, head_ball);
    }

    if(x==2){
        int d,e,f;
        Sleep(300);
        printf("\n\t\tEnter New Bowler Information(Over,Run,Wct) : ");
        scanf("%d %d %d", &d, &e, &f);
        if(p2->next==NULL){
            p2->sl = 1;
            p2->over = d;
            p2->run = e;
            p2->wct = f;
        }
        else{
            struct bowler *temp = malloc(sizeof(struct bowler));
            temp->over = d;
            temp->run = e;
            temp->wct = f;
            temp->next = NULL;

            cnt=1;
            while(p2->next != NULL){
                p2 = p2->next;
                cnt++;
            }
            temp->sl = cnt+1;
            p2->next = temp;
        }
        Sleep(300);
        printf("\t\t-----Adding New Bowler Information Succesfully!-----");
        Choose(head_bat, head_ball);
    }
}

void Del_Info(struct batsman **p1, struct bowler **p2){
    struct batsman *head_bat = *p1;
    struct bowler *head_ball = *p2;
    struct batsman *temp1 = *p1;
    struct bowler *temp2 = *p2;
    int x,n;
    x=-6996;
    while(x!=1 && x!=2){
        Sleep(300);
        if(x!=-6996) printf("\n\t\t*****Please Enter Correct one!!*****\n");
        Sleep(300);
        printf("\t\t--------Welcome to Delete Portal--------\n");
        Sleep(300);
        printf("\t\tYou Want to Delete........\n");
        Sleep(300);
        printf("\t\t1.Batsman Information\n");
        Sleep(300);
        printf("\t\t2.Bowler Information\n");
        Sleep(300);
        printf("\n\t\tChoose One : ");
        scanf("%d", &x);
    }

    if(x==1){
        int cnt=1;
        while(temp1->next != NULL){
            cnt++;
            temp1 = temp1->next;
        }
        temp1 = head_bat;
        n=-6996;
        while(n<1 || n>cnt){
            if(n!=-6996){
                Sleep(300);
                printf("\t\t-----Please Enter Correct One!-----\n");
            }
            Sleep(300);
            printf("\t\tWhich Batsman's Information You Want to Delete? : ");
            scanf("%d", &n);
        }

        if(n==1){
            struct batsman *temp = *p1;
           *p1 = temp->next;
            free(temp);
        }
        else{
            cnt=1;
            while(cnt!=n-1){
                temp1 = temp1->next;
                cnt++;
            }
            if(temp1->next->next==NULL) temp1->next = NULL;
            else temp1->next = temp1->next->next;
        }
        Sleep(300);
        printf("\n\t\t*****%d.th Batsman Information Deleted Succesfully!!*****\n", n);
        Sleep(300);
        Choose(head_bat, head_ball);
    }


    if(x==2){
        int cnt=1;
        while(temp2->next != NULL){
            cnt++;
            temp2 = temp2->next;
        }
        temp2 = head_ball;
        n=-6996;
        while(n<1 || n>cnt){
            if(n!=-6996){
                Sleep(300);
                printf("\t\t-----Please Enter Correct One!-----\n");
            }
            Sleep(300);
            printf("\t\tWhich Batsman's Information You Want to Delete? : ");
            scanf("%d", &n);
        }

        if(n==1){
            struct bowler *temp = *p2;
            *p2 = temp->next;
            free(temp);
        }
        else{
            cnt=1;
            while(cnt!=n-1){
                temp2 = temp2->next;
                cnt++;
            }
            if(temp2->next->next==NULL) temp2->next = NULL;
            else temp2->next = temp2->next->next;
        }
        Sleep(300);
        printf("\n\t\t*****%d.th Bowler's Information Deleted Succesfully!!*****\n", n);
        Sleep(300);
        Choose(head_bat, head_ball);
    }
}






/*-----------------------Main Function---------------------------*/
void main(){
    struct batsman *batsmans_head = malloc(sizeof(struct batsman));
    batsmans_head->next = NULL;
    struct bowler  *bowlers_head  = malloc(sizeof(struct bowler));
    bowlers_head->next = NULL;
    
    int n,x;
    Sleep(300);
    printf("\n\n-------------------------------------------------------Menu----------------------------------------------------------\n\n");
    Sleep(300);
    printf("\t\t\t\t\t\t1.New Scoresheet\n");
    Sleep(300);
    printf("\t\t\t\t\t\t2.View Scoresheet\n");
    Sleep(300);
    printf("\t\t\t\t\t\t3.Special Features\n");
    Sleep(300);
    printf("\t\t\t\t\t\t4.Exit\n\n");
    Sleep(300);
    printf("\t\t\t\t\t\tChoose your choice : ");
    scanf("%d", &n);

    if(n==1) Create_Sheet(batsmans_head, bowlers_head);


    else if(n==2){
        x=-6996;
        while(x!=1 && x!=2 && x!=3){
            Sleep(300);
            if(x!=-6996) printf("\n\t\t*****Please Enter Correct one!!*****\n");
            Sleep(300);
            printf("\t\t--------View Sheet--------\n");
            Sleep(300);
            printf("\t\t1.Batsman Scoresheet\n");
            Sleep(300);
            printf("\t\t2.Bowling Sheet\n");
            Sleep(300);
            printf("\t\t3.Back\n");
            Sleep(300);
            printf("\n\t\tChoose One : ");
            scanf("%d", &x);
        }
        if(x==1) view_batsman_sheet(batsmans_head, bowlers_head);
        else if(x==2) view_bowler_sheet(batsmans_head,bowlers_head);
        else main();
    }

    else if(n==3){
        x=-6996;
        while(x!=1 && x!=2 && x!=3 && x!=4){
            Sleep(300);
            if(x!=-6996) printf("\n\t\t*****Please Enter Correct one!!*****\n");
            Sleep(300);
            printf("\t\t~~~~~~ Special Feature ~~~~~~\n");
            Sleep(300);
            printf("\t\t1.Show Information\n");
            Sleep(300);
            printf("\t\t2.Add Information\n");
            Sleep(300);
            printf("\t\t3.Delete Information\n");
            Sleep(300);
            printf("\t\t4.Back\n");
            Sleep(300);
            printf("\n\t\tChoose One : ");
            scanf("%d", &x);
        }
        if(x==1) Show_Info(batsmans_head, bowlers_head);
        else if(x==2) Add_Info(batsmans_head, bowlers_head);
        else if(x==3) Del_Info(&batsmans_head, &bowlers_head);
        else main();
    }


    else if(n==4) exit(0);
    else{
        Sleep(300);
        printf("\n\t\t\t\t********** Please Choose Correct One! **********\n\n");
        Sleep(300);
        main();
    }
}
/* Ah Finally Finish :3 */
