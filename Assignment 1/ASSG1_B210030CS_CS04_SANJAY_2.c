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




void DFS (node root, int* index){
    if (root == NULL){
        return;
    }
    // if (root->right != NULL) {
    //         if ((root->right->right != NULL && root->left->left == NULL && root->left->right == NULL)
    //         || (root->right->left != NULL && root->left->left == NULL && root->left->right == NULL)) {
    //             ++*index;
    //         }

    // }
    // if (root->left != NULL) {
    //     if ((root->left->right != NULL && root->right->left == NULL && root->right->right == NULL)
    //         || (root->left->left != NULL && root->right->left == NULL && root->right->right == NULL)) {
    //             ++*index;
    //         }
    // }

    if (root->right != NULL && root->left != NULL){
        if ((root->right->right != NULL && root->left->left == NULL && root->left->right == NULL)) {
            *index = *index + 1;
        }

        if ((root->right->left != NULL && root->left->left == NULL && root->left->right == NULL)) {
            *index = *index + 1;
        }
        if ((root->left->right != NULL && root->right->left == NULL && root->right->right == NULL)) {
            *index = *index + 1;
        }
        if ((root->left->left != NULL && root->right->left == NULL && root->right->right == NULL)){
            *index = *index + 1;
        }
    }
    // ++*index;

    DFS (root->left, index);
    DFS(root->right, index);
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
    DFS (x, &index);
    
    printf ("%d\n" , index);

}

