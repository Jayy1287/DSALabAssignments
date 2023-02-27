#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    struct node* p;
};
typedef struct node* node;

struct tree {
    node root;
};
typedef struct tree* tree;

node CreateNode (int k){
    node x;
    x = (node) malloc (sizeof(struct node));
    x->left  = NULL;
    x->right = NULL;
    x->key = k;
    x->p = NULL;
    return x;
}

node Search (node x, int k){
    if (x==NULL || x->key==k){
        return x;
    }
    if (x->key<k){
        return Search(x->right, k);
    }
    else {
        return Search(x->left, k);
    }
}

// int DFS (node root, int val, int* lev){
//     if (root == NULL){
//         return -1;
//     }

//     if (root->key == val){
//         return *lev;
//     }
//     ++*lev;
//     return DFS (root->left, val, lev);
//     return DFS (root->right, val, lev);
// }

int Level (tree T, int k){
    node root = T->root;
    // int lev = -1;
    
    // return DFS (root, k, &lev);
    node find = Search(root, k);
    if (find == NULL){
        return -1;
    }
    int counter = 1;
    while (find->p != NULL){
        ++counter;
        find = find->p;
    }
    return counter;

}

node Insert (tree T, node x){
    int k;
    scanf ("%d", &k);

    x = CreateNode(k);
    node b = NULL;
    node a = T->root;
    while (a!=NULL){
        b = a;
        if (x->key <= a->key){   //check =
            a=a->left;
        }
        else {
            a = a->right;
        }
    }
    x->p = b;
    if (b==NULL){
        T->root = x;
    }
    else if (x->key<b->key){
        b->left = x;
    }
    else {
        b->right = x;
    }
}


node MinValue(node x)
{
	while(x->left!=NULL)
		x=x->left;
	return x;
}

node MaxValue(node x)
{
	while(x->right!=NULL)
		x=x->right;
	return x;
}


void Preorder(node T)
{
	if(T!=NULL)
	{
		printf("%d ",T->key);
		Preorder(T->left);
		Preorder(T->right);
	}
}
void Inorder(node T){
	if(T!=NULL)
	{
		Inorder(T->left);
		printf("%d ",T->key);
		Inorder(T->right);
	}

}
void Postorder(node T) {
	if(T!=NULL)
	{
		Postorder(T->left);
		Postorder(T->right);
		printf("%d ",T->key);
	}

}

node Successor(node T, int k){
    node n;
    n = Search (T, k);
    if (n==NULL){
        return NULL;
    }

    if(n->right != NULL){
        return MinValue(n->right);
    }
    node p;
    p = n->p;
    while (p!=NULL && n==p->right){
        n = p;
        p = p->p;
    }
    return p;

}

node Predecessor (node T, int k){
    node n;
    n = Search (T, k);

    if(n->left != NULL){
        return MaxValue(n->left);
    }
    node p;
    p = n->p;
    while (p!=NULL && n==p->left){
        n = p;
        p = p->p;
    }
    return p;

}

void Change(tree T, node x, node y)
{
	if(x->p==NULL)
		T->root=y;
	else if(x==x->p->left)
		x->p->left=y;
	else 
		x->p->right=y;
	if(y!=NULL)
		y->p=x->p;
}

void DELETE(tree T, node x)
{
	x=T->root;
	int k;
	scanf("%d",&k);
	x=Search(x,k);
	if(x==NULL)
		printf ("-1\n");
	else{
	if(x->left==NULL)
		Change(T,x,x->right);
	else if(x->right==NULL)
		Change(T,x,x->left);
	else 
		{
		struct node* y=MinValue(x->right);
		if(y->p!=x)
			{
			Change(T,y,y->right);
			y->right=x->right;
			y->right->p=y;
			}
		Change(T,x,y);
		y->left=x->left;
		y->left->p=y;
		}
	// printf ("%d\n" , k);
	}
		
}

int main() {

    tree T;
    node x;
    node a;
    node b;
    int k;
    int find;

    T=(tree) malloc (sizeof(struct tree));
    T->root = NULL;

    char current;
    do {
        scanf (" %c" ,&current);
        switch (current) {
            case 'a': //insert node
                Insert(T, x);
                break;
            case 'd': //delete node
                DELETE (T, x);
                break;
            case 's': //search
                scanf("%d" , &find);
                a = Search(T->root, find);
                if (a==NULL){
                    printf ("-1\n");
                }
                else {
                    printf ("1\n");
                }
                break;
            case 'l': //find level
                scanf("%d" , &find);
                printf ("%d\n" , Level(T, find));

                break;
            case 'm': //find min
                printf ("%d\n" , (MinValue(T->root))->key);
                break;
            case 'x': //find max
                printf ("%d\n" , (MaxValue(T->root))->key);
                break;

            case 'r': //predecessor
                scanf("%d",&k);
                a = Predecessor(T->root, k);

		 	    if(a != NULL) {
		 	   	     printf("%d\n"  , a->key);
                }
		 	    else{
		 	   	    printf("-1\n");
                }
                break;
            
            case 'u': //successor
                scanf("%d",&k);
                a = Successor(T->root, k);

		 	    if(a != NULL) {
		 	   	     printf("%d\n"  , a->key);
                }
		 	    else{
		 	   	    printf("-1\n");
                }
                break;
            
            case 'i': //inorder
                if (T->root == NULL){
                    printf ("NIL\n");
                }
                else {
                    Inorder(T->root);
                    printf("\n");
                }
                break;
            case 'p': //preorder
                if (T->root == NULL){
                    printf ("NIL\n");
                }
                else {
                    Preorder(T->root);
                    printf("\n");
                }
                break;
            case 't': //postorder
                if (T->root == NULL){
                    printf ("NIL\n");
                }
                else {
                    Postorder(T->root);
                    printf("\n");
                }
                break;
            case 'e': //exit
                break;
        }
    }  while (current != 'e');
}

