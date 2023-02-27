#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    // struct node* p;
    int h;
};
typedef struct node* node;

struct tree {
    node root;
};
typedef struct tree* tree;

node CreateNode (int k){
    node x;
    x = (node) malloc (sizeof(struct node));
    x->left = NULL;
    x->right = NULL;
    x->key = k;
    return x;
}

int GetBalance (node root){
    //node root = A->head;
    int lh, rh;

    if(root == NULL){
        return 0;
    }
    if (root->left == NULL){
        lh = 0;
    }
    else {
        lh = 1 + root->left->h;
    }
    if (root->right == NULL){
        rh = 0;
    }
    else {
        rh = 1 + root->right->h;
    }
    return lh - rh;
}

int height (node root){
    int lh, rh;

    if (root == NULL){
        return 0;
    }
    if (root->left == NULL){
        lh = 0;
    }
    else {
        lh = 1 + root->left->h;
    }
    if (root->right == NULL){
        rh = 0;
    }
    else {
        rh = 1 + root->right->h;
    }
    if (lh > rh){
        return lh;
    }
    return rh;
}


// node Search (tree A, int k){
//     node x = A->head;
//     if (x==NULL || x->key==k){
//         return x;
//     }
//     if (x->key<k){
//         return Search(x->right, k);
//     }
//     else {
//         return Search(x->left, k);
//     }
// }

node LeftRotate (node root){
    node rchild = root->right;
    root->right = rchild->left;
    rchild->left = root;

    root->h = height(root);
    rchild->h = height(root);

    return rchild;
}

node RightRotate (node root){
    node lchild = root->left;
    root->left = lchild->right;
    lchild->right = root;

    root->h = height(root);
    lchild->h = height(lchild);

    return lchild;
}

node insert (node root, int k){

    if (root == NULL)
    {
        node new = CreateNode(k);
        if (new  == NULL){
            return NULL;
        }
        root = new;
    }
    else if (k > root->key){
        root->right = insert(root->right, k);

        if (GetBalance(root) == -2){
            if (k > root->right->key){
                root = LeftRotate(root);
            }
            else {
                root->right = RightRotate(root->right);
                root = LeftRotate(root);
            }
        }
    }
    else {
        root->left = insert(root->left, k);

        if (GetBalance(root) == 2){
            if (k < root->left->key){
                root = RightRotate(root);
            }
            else {
                root->left = LeftRotate(root->left);
                root = RightRotate(root);
            }
        }
    }
    root->h = height(root);
    return root;
}

void Inorder(node T, int k){
	if(T!=NULL)
	{
		// printf ("(");
        Inorder(T->left, k);
        if (T->key > k){
		    printf("%d ",T->key);
        }
		Inorder(T->right, k);
        // printf (")");
	}
    // printf("\n");

}
void DFS(node T, int k, int *count){
	if(T!=NULL)
	{
		// printf ("(");
        DFS(T->left, k, count);
        if (T->key > k){
		    ++*count;
        }
		DFS(T->right, k, count);
        // printf (")");
	}
    // printf("\n");

}


int main() {
    tree T;
    T = (tree) malloc(sizeof(struct tree));
    T->root = NULL;

    char current;
    int k;
    node temp;
    int count;

    do {
        scanf (" %c" ,&current);

        switch (current) {

            case 'i': // insert
                scanf ("%d" , &k);
                T->root = insert(T->root, k);
                break;

            case 'c': //print values greater than input
                scanf ("%d" , &k);
                count = 0;
                DFS(T->root, k, &count);
                printf("%d\n" , count);
                Inorder(T->root, k);
                printf("\n");

                
                break;
        }


    } while(current != 'e');


    return 0;
}