#include <stdio.h>
#include <stdlib.h>

struct node {
    long int key;
    struct node* left;
    struct node* right;
};
typedef struct node* node;

struct tree {
    node head;
};
typedef struct tree* tree;

node Create_Node (long int k){
    node x;
    x = (node) malloc (sizeof(struct node));
    x->left  = NULL;
    x->right = NULL;
    x->key = k;
    return x;
}


int FindLength(char* exp){
    int i = 0;
    while(exp[i]){
        i++;
    }
    return i;
}

node Insert(char* s, int *val){

    if(FindLength(s) == 0){
        return NULL;
    }

    int num = 0;
    while(*val < FindLength(s) && s[*val] != '(' && s[*val] != ')'){
        int digit = (int)(s[*val] - '0');
        num = num * 10 + digit;
        *val += 1;
    }

    node head = NULL;
    if(num > 0) head = Create_Node(num);

    if(*val < FindLength(s) && s[*val] == '('){
        *val = *val + 1;
        head->left = Insert(s, val);
    }
    if(*val < FindLength(s) && s[*val] == ')'){
        *val += 1;
        return head;
    }

    if(*val < FindLength(s) && s[*val] == '('){
        *val = *val + 1;
        head->right = Insert(s, val);
    }
    if(*val < FindLength(s) && s[*val] == ')'){
        *val += 1;
    }
    return head;
}



void Inorder(node T){
	// printf ("( ");
    if(T!=NULL)
	{
		Inorder(T->left);
		printf("%ld ",T->key);
		Inorder(T->right);
	}
    // printf (") ");

}

void Preorder(node T)
{
    // printf ("( ");
	if(T!=NULL)
	{
		printf("%ld ",T->key);
		Preorder(T->left);
		Preorder(T->right);
	}
    // printf (") ");
}

void Postorder(node T) {
	if(T!=NULL)
	{
		Postorder(T->left);
		Postorder(T->right);
		printf("%ld ",T->key);
	}

}

void findDesc (node root, int k, int descendants[] , int *index){
    if (root == NULL){
        return;
    }
    if (k==0){
        descendants[*index] = root->key;  
        *index = *index + 1;
    }
    else {     
        
        findDesc(root->left, k-1, descendants, index);
        findDesc(root->right, k-1, descendants, index);
        
    }
}

void DFS (node root, int val, int k, int descendants[], int* index){
    if (root != NULL){
        if (root->key == val){
            findDesc (root, k, descendants, index);
        }
        else {
            DFS (root->left, val, k, descendants, index);
            DFS (root->right, val, k, descendants, index);
        }
    }
    // return descendants;
    return;
}

int main() {


    node x;
    x = NULL;

    int k, i, j;



    char arr[1000];
    int val= 0;
    char str[1000];
    int descendants[1000];
    int dist, len;
    int index=0;

    scanf (" %[^\n]%*c" , arr);
    scanf (" %d" , &dist);
    scanf (" %d" , &len);
    i = 0;
    j = 0;


    for (i=1; i<FindLength(arr)-1; ++i){
        if (arr[i] != ' '){
            str[j] = arr[i];
            ++j;
        }
    }
    str[j] = '\0';



    x = Insert(str, &val);
    // Postorder(x);
    // Inorder(x);
    DFS (x, dist, len, descendants, &index);

    if (index == 0) {
        printf ("-1\n");
        return -1;
    }

    
    for (i=0; i<index; ++i){
        printf ("%d " ,descendants[i]);
    }
    printf ("\n"); ////////check pls

}

