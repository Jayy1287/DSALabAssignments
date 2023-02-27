#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
/*
void Inorder (node T){
    if (T != NULL){
        Inorder(T->left);
        
        printf ("%d ", T->key);
        
        Inorder(T->right);
    }
}
*/
/*
void DFS (node root, int key, int *check, int nums[], int *index, int* count){
    if (root != NULL){
        if (root->key == key){
            *check = 1;
            return;
        }
        else {
       	    if (*check == 0){
            	nums[*index] = root->key;
            	*index = *index + 1;
            }
            DFS (root->left, key, check, nums, index, count);
            DFS (root->right, key, check, nums, index, count);
        }
    }
    if (*check == 0) {
    	*count = *index;
    }
    return;
}
*/
bool findAnc (node root, int key) {
	if (root == NULL) {
		return false;
	}
	if (root->key == key) {
		return true;
	}
	
	bool left = findAnc (root->left, key);
	
	bool right = false;
	if (!left) {
		right = findAnc(root->right, key);
	}
	
	if (left || right) {
		printf ("%d ", root->key); 
	}
	return left || right;
}

int main() {
    
    node x = NULL;
    
    int i, j;
    char arr[1000];
    int val = 0;
    char str[1000];
    int nums[1000];
    int key;
    int index = 0;
    int check = 0;
    int count = 0;
    
    scanf (" %[^\n]%*c" , arr);
    scanf ("%d" , &key);
    
    j = 0;
    for (i = 1; i<FindLength(arr)-1; ++i){
        if (arr[i] != ' '){
            str[j] = arr[i];
            ++j;
        }
    }
    str[j] = '\0';
    
    x = Insert(str, &val);
/*    Inorder(x);
    printf ("\n");
    DFS (x, key, &check, nums, &index, &count);
    if (check == 0) {
    	printf ("-1\n");
    	return -1;
    }
    
    for (i=0; i<count; ++i) {
    	printf ("%d " , nums[i]);
    }
    printf ("\n");
*/
    if (x->key == key){
        printf ("-1\n");
        return -1;
    }
    bool test = findAnc(x, key);
    if (test == false){
        printf ("-1");
    }
    printf ("\n");
    return 0;
    
}
