#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};
typedef struct node *node;

struct LL {
    node head;
};
typedef struct LL *LL;

node CREATE_NODE (int k) {
    node temp;
    temp = (node)malloc(sizeof(struct node));
    if (temp == NULL){
        exit(0);
    }
    temp->key = k;
    temp->next = NULL;
    return temp;
}

void LIST_INSERT_FRONT (LL L, node x){
    x->next = L->head;
    L->head = x;
}


int main() {

    char str[100];
    int k;
    node currentNode;
    LL L;
    L = (LL) malloc(sizeof(LL));
    L->head = NULL;
    int j = 0;
    int num;
    int digit;
    scanf (" %[^\n]s" , &str);
    // printf ("%s", str);

    while (str[j]!= '\0'){
        if (str[j] == ' '){
            ++j;
            continue;
        }
        // if (str[j] != ' '){
            num = (int)(str[j] - '0');
            while (str[j+1]!= ' ' && str[j+1] != '\0'){
                digit = (int)(str[j+1] - '0');
                num = num*10 + digit;
                ++j;
            }
            currentNode = CREATE_NODE(num);
            LIST_INSERT_FRONT(L, currentNode);
        // }
        ++j;

    }
    scanf("%d" , &k);

    currentNode = L->head;
    for (int i = k-1; i>0; --i){
        // printf ("%d " , currentNode->key);

        currentNode = currentNode->next;
        if (currentNode == NULL){
            printf ("-1\n");
            return -1;
        }
    }
    printf ("%d\n" , currentNode->key );


    return 0;
}