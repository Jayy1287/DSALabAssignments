#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};
typedef struct node* node;

struct tree {
    node head;
};
typedef struct tree* tree;

node Create_Node (int k){
    node x;
    x = (node) malloc (sizeof(struct node));
    x->left = NULL;
    x->right = NULL;
    x->key = k;
    return x;
}

int FindLength (char* exp){
    int i = 0;
    while (exp[i]){
        i++;
    }
    return i;
}

node Insert (char* s, int* val){
    int len = FindLength(s);
    if (len == 0){
        return NULL;
    }
    int num = 0;
    while (*val < FindLength(s) && s[*val] != '(' && s[*val] != ')'){
        int digit = (int)(s[*val] - '0');
        num = num * 10 + digit;
        *val += 1;
    }
    node head = NULL;
    if (num>0) head = Create_Node(num);
    
    if (*val < len && s[*val] == '('){
        *val = *val + 1;
        head->left = Insert(s, val);
    }
    if (*val < len && s[*val] == ')'){
        *val += 1;
        return head;
    }
    if (*val < len && s[*val] == '('){
        *val = *val + 1;
        head->right = Insert (s, val);
    }
    if (*val < len && s[*val] == ')'){
        *val += 1;
    }
    return head;
}

void Inorder (node T, int low, int high){
    if (T != NULL){
        Inorder(T->left, low, high);
        if (T->key >= low && T->key <= high){
        	printf ("%d ", T->key);
        }
        Inorder(T->right, low, high);
    }
}

void DFS (node root, int low, int high, int nums[], int *index){
    if (root != NULL){
        if (root->key >= low && root->key <= high){
            nums[*index] = root->key;
            *index = *index + 1;
        }
        else {
            DFS (root->left, low, high, nums, index);
            DFS (root->right, low, high, nums, index);
        }
    }
    return;
}

int main() {
    
    node x = NULL;
    
    int i, j;
    char arr[1000];
    int val = 0;
    char str[1000];
    int nums[1000];
    int high, low;
    int index = 0;
    
    scanf (" %[^\n]%*c" , arr);
    scanf ("%d" , &low);
    scanf ("%d" , &high);
    
    j = 0;
    for (i = 1; i<FindLength(arr)-1; ++i){
        if (arr[i] != ' '){
            str[j] = arr[i];
            ++j;
        }
    }
    str[j] = '\0';
    
    x = Insert(str, &val);
    Inorder(x, low, high);
    printf ("\n");
/*    DFS (x, low, high, nums, &index);
    
    for (i=0; i<index; ++i) {
    	printf ("%d " , nums[i]);
    }
    printf ("\n");
    */
}
