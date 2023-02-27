#include <stdio.h>
#include <stdlib.h>

struct node {
    char name[100];
    char roll[100];
    int value;
    struct node* next;
};
typedef struct node *node;

struct LL {
    node head;
    int count;
};
typedef struct LL *LL;

void LIST_INSERT_TAIL(LL L,node x)
{
    node selected=L->head;
    ++L->count;
    if(selected!=NULL){
        while(selected->next!=NULL)
            selected=selected->next;
        selected->next=x;
    }
    else
        L->head=x;
}

void PRINT_LIST(LL L)
{
    node selected=L->head;
    
    if(L->head == NULL){
        printf ("0\n");
        return;
    }
    printf ("%d " , L->count);
    while(selected!=NULL){
        printf("%s ",selected->name);
        selected=selected->next;
    }
    
    printf("\n");
}

void PRINT_CHECK(LL L , char *br)
{
    int check = 0;
    node selected=L->head;

    while(selected!=NULL){
        if ((br[0] == selected->roll[7] && br[1] == selected->roll[8])
        || ((int)(br[0]-32) == (int)(selected->roll[7]) && (int)(br[1]-32) == (int)(selected->roll[8]))
        || (br[0] == selected->roll[7] && (int)(br[1]-32) == (int)(selected->roll[8]))
        || ((int)(br[0]-32) == (int)(selected->roll[7]) && br[1] == selected->roll[8])
        ){
            printf("%s ",selected->name);
            check = 1;
        }
        selected=selected->next;
    }
    if (check == 0){
        printf ("-1");
    }
    printf("\n");
}



int main() {

    node temp;
    LL L[4];
    L[0] = (LL)malloc(sizeof(LL));
    L[1] = (LL)malloc(sizeof(LL));
    L[2] = (LL)malloc(sizeof(LL));
    L[3] = (LL)malloc(sizeof(LL));

    L[0]->head = NULL;
    L[0]->count = 0;
    L[1]->head = NULL;
    L[1]->count = 0;
    L[2]->head = NULL;
    L[2]->count = 0;
    L[3]->head = NULL;
    L[3]->count = 0;

    //0 CS
    //1 EC
    //2 EE
    //3 CE

    int n, i, j;
    int sum;
    char br[100];
    j = 0;
    int pos;
    scanf("%d" , &n);

    for (i = 0; i<n; ++i){
        sum = 0;
        temp = NULL;
        j = 0;
        // l = 4;
        temp = (node)malloc(sizeof(struct node));

        scanf ("%s" , temp->name);
        scanf ("%s" , temp->roll);
        scanf ("%d" , &temp->value);
        while (temp->name[j]){
            sum = sum + (int)(temp->name[j]);
            //printf ("%d " , (int)(temp->name[j])); 
            ++j;     
            // --l;     
        }
        sum = sum + temp->value;
        //printf ("%d " , (int)(temp->value)); 

        pos = sum % 4;
        LIST_INSERT_TAIL(L[pos] , temp);
    }

    char currChar;
    do {
        scanf (" %c", &currChar);

        switch (currChar) {

            case 'c':
                scanf ("%d" , &pos);
                PRINT_LIST(L[pos]);
                break;
            case 'e':
                break;

            case '0':
                scanf("%s" , br);
                PRINT_CHECK(L[0], br);
                break;
            case '1':
                scanf("%s" , br);   
                PRINT_CHECK(L[1], br);             
                break;
            case '2':
                scanf("%s" , br);
                PRINT_CHECK(L[2], br);
                break;
            case '3':
                scanf("%s" , br);
                PRINT_CHECK(L[3], br);
                break;
        }



    }while (currChar != 'e');




    return 0;
}