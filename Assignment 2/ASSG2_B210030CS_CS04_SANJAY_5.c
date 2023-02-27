#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
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
    x->h = 1;
    return x;
}

// int GetBalance (node root){
//     //node root = A->head;
//     int lh, rh;

//     if(root == NULL){
//         return 0;
//     }
//     if (root->left == NULL){
//         lh = 0;
//     }
//     else {
//         lh = 1 + root->left->h;
//     }
//     if (root->right == NULL){
//         rh = 0;
//     }
//     else {
//         rh = 1 + root->right->h;
//     }
//     return lh - rh;
// }

// int height (node root){
//     int lh, rh;

//     if (root == NULL){
//         return 0;
//     }
//     if (root->left == NULL){
//         lh = 1;
//     }
//     else {
//         lh = 1 + root->left->h;
//     }
//     if (root->right == NULL){
//         rh = 1;
//     }
//     else {
//         rh = 1 + root->right->h;
//     }
//     if (lh > rh){
//         return lh;
//     }
//     return rh;
// }

int height (node root){
    if ( root == NULL){
        return 0;
    }
    return root->h;
}
int findMax(int x, int y){
    if (x>y){
        return x;
    }
    return y;

}
int GetBalance (node root){
    if (root == NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
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

// node LeftRotate (node root){
//     node rchild = root->right;
//     root->right = rchild->left;
//     rchild->left = root;

//     root->h = height(root);
//     rchild->h = height(rchild);

//     return rchild;
// }

// node RightRotate (node root){
//     node lchild = root->left;
//     root->left = lchild->right;
//     lchild->right = root;

//     root->h = height(root);
//     lchild->h = height(lchild);

//     return lchild;
// }

node RightRotate(node root){
    node lchild = root->left;
    node T = lchild->right;

    lchild->right = root;
    root->left = T;

    // root->h = height(root);
    // lchild->h = height(lchild);
    root->h = findMax( height(root->left), height(root->right)) + 1;
    lchild->h = findMax( height(lchild->left), height(lchild->right)) + 1;

    return lchild;

}

node LeftRotate(node root){
    node rchild = root->right;
    node T = rchild->left;

    rchild->left = root;
    root->right = T;

    // root->h = height(root);
    // rchild->h = height(rchild);
    root->h = findMax( height(root->left), height(root->right)) + 1;
    rchild->h = findMax( height(rchild->left), height(rchild->right)) + 1;

    return rchild;

}

// node insert (node root, int k){

//     if (root == NULL)
//     {
//         node new = CreateNode(k);
//         if (new  == NULL){
//             return NULL;
//         }
//         root = new;
//     }
//     else if (k > root->key){
//         root->right = insert(root->right, k);

//         if (GetBalance(root) == -2){
//             if (k > root->right->key){
//                 root = LeftRotate(root);
//             }
//             else {
//                 root->right = RightRotate(root->right);
//                 root = LeftRotate(root);
//             }
//         }
//     }
//     else {
//         root->left = insert(root->left, k);

//         if (GetBalance(root) == 2){
//             if (k < root->left->key){
//                 root = RightRotate(root);
//             }
//             else {
//                 root->left = LeftRotate(root->left);
//                 root = RightRotate(root);
//             }
//         }
//     }
//     root->h = height(root);
//     return root;
// }

node insert (node root, int key){
    if (root == NULL){
        return (CreateNode(key));
    }
    if (key < root->key){
        root->left = insert(root->left, key);
    }
    else if (key > root->key){
        root->right = insert(root->right, key);
    }
    else {
        return root;
    }

    // root->h = height(root);
    root->h = findMax( height(root->left), height(root->right)) + 1;
    int balance = GetBalance(root);

    if (balance > 1 && key < root->left->key){
        return RightRotate(root);
    }
    if (balance < -1 && key > root->right->key){
        return LeftRotate(root);
    }

    if (balance > 1 && key > root->left->key){
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if (balance < -1 && key < root->right->key){
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
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


void Preorder(node T)
{
	if(T!=NULL)
	{
		
        printf ("( ");
        printf("%d ",T->key);
		Preorder(T->left);
		Preorder(T->right);
        printf (") ");
	}
    else {
        printf ("( ) ");
    }
    
}
void Inorder(node T){
	if(T!=NULL)
	{
		// printf ("(");
        Inorder(T->left);
		printf("%d ",T->key);
		Inorder(T->right);
        // printf (")");
	}
    printf("\n");

}
void Postorder(node T) {
	if(T!=NULL)
	{
		Postorder(T->left);
		Postorder(T->right);
		printf("%d ",T->key);
	}
    else {
        printf ("()");
    }

}

node delete (node root, int x){
    // printf("Helllooo\n");
    node temp = NULL;

    if (root == NULL){
        return NULL;
    }
    if (x > root->key){
        root->right = delete(root->right, x);
        if (GetBalance(root) == 2){
            if (GetBalance(root->left) >= 0){
                root = RightRotate(root);
            }
            else {
                root->left = LeftRotate(root->left);
                root = RightRotate(root);
            }
        }
    }
    else if (x < root->key){
        root->left = delete(root->left, x);
        if (GetBalance(root) == -2){
            if (GetBalance(root->right) <= 0){
                root = LeftRotate(root);
            }
            else {
                root->right = RightRotate(root->right);
                root = LeftRotate(root);
            }
        }
    }
    else {
        if (root->right != NULL){
            temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
            if (GetBalance(root) == 2){
                if (GetBalance(root->left) >= 0){
                    root = RightRotate(root);
                }
                else {
                    root->left = LeftRotate(root->left);
                    root = RightRotate(root);
                }
            }
            
        }
        else {
                return (root->left);
        }
    }
    // root->h = height(root);
    root->h = findMax( height(root->left), height(root->right)) + 1;
    return root;
}

node minValue (node root){
    node current = root;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}


node deleteNode (node root, int key){
    if (root == NULL){
        return root;
    }
    if (key < root->key){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key){
        root->right = deleteNode(root->right, key);
    }
    else {
        if ((root->left == NULL) || (root->right == NULL)){
            node temp = root->left? root->left:root->right;

            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            free(temp);
        }
        else {
            node temp = minValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL){
        return root;
    }
    // root->h = 1 + findMax(height(root->left), height(root->right));
    // root->h = height(root);
    root->h = findMax( height(root->left), height(root->right)) + 1;

    int balance = GetBalance(root);

    if (balance > 1 && GetBalance(root->left) >= 0){
        return RightRotate(root);
    }

    if (balance > 1 && GetBalance(root->left) < 0){
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if (balance < -1 && GetBalance(root->right) <= 0){
        return LeftRotate(root);
    }

    if (balance < -1 && GetBalance(root->right) > 0){
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }
    return root;
}

int main() {
    tree T;
    T = (tree) malloc(sizeof(struct tree));
    T->root = NULL;

    char current;
    int k;
    node temp;

    do {
        scanf (" %c" ,&current);

        switch (current) {

            case 'i': // insert
                scanf ("%d" , &k);
                T->root = insert(T->root, k);
                break;
            case 's': //search for node with given int
                scanf ("%d" , &k);
                temp = Search(T->root, k);
                if (temp == NULL){
                    printf("FALSE\n");
                }
                else {
                    printf("TRUE\n");
                }
                break;
            case 'p': //print parenthesis rep
                Preorder(T->root);
                printf("\n");
                break;
            case 'b': //find blf of node with givern key
                scanf ("%d" , &k);
                temp = Search(T->root, k);
                k = GetBalance(temp);
                printf ("%d\n" , k);
                break;
            case 'd': //delete node with given value
                scanf ("%d" , &k);
                // delete(T->root, k);
                temp = Search(T->root, k);
                if (temp == NULL){
                    printf ("-1\n");
                }
                else {
                    
                    printf ("%d\n" , k);
                    T->root = delete(T->root, k);
                }
                // delete(T->root, k);
                break;
        }


    } while(current != 'e');


    return 0;
}