#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
    // struct node* p;
    int no_of_elements;
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

int number (node root){
    int lh, rh;

    if (root == NULL){
        return 0;
    }
    if (root->left == NULL){
        lh = 0;
    }
    else {
        lh =  root->left->no_of_elements;
    }
    if (root->right == NULL){
        rh = 0;
    }
    else {
        rh =  root->right->no_of_elements;
    }

    return rh + lh + 1;
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
    root->no_of_elements = number(root);
    rchild->h = height(rchild);
    rchild->no_of_elements = number(rchild);

    return rchild;
}

node RightRotate (node root){
    node lchild = root->left;
    root->left = lchild->right;
    lchild->right = root;

    root->h = height(root);
    root->no_of_elements = number(root);
    lchild->h = height(lchild);
    lchild->no_of_elements = number(lchild);

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
    root->no_of_elements = number(root);
    return root;
}

void strinsert (int* nums, int k){
    int count = 0;
    while (nums[count]){
        ++count;
    }
    nums[count] = k;
}

void Inorder(node T, int*nums){
	if(T!=NULL)
	{
		// printf ("(");
        Inorder(T->left, nums);
		// printf("%d ",T->key);
        strinsert(nums, T->key);
		Inorder(T->right, nums);
        // printf (")");
	}
    printf("\n");

}

void GetMedian (node root){
    int n = (root->no_of_elements-1)/2;
    int nums[1000];
    int index= 0;
    if (root != NULL){
        Inorder(root, nums);
    }

    int count = 0;
    while (nums[count]>0 && nums[count]<1000){
        ++count;
    }
    // for (int i = 0; i<count; ++i){
    //     printf ("%d ", nums[i]);
    // }
    printf ("%d\n" , nums[n]);

}



int main() {
    tree T;
    T = (tree) malloc(sizeof(struct tree));
    T->root = NULL;

    char current;
    int k;
    node temp;
    int count  = 0;

    do {
        scanf (" %c" ,&current);

        switch (current) {

            case 'i': // insert
                scanf ("%d" , &k);
                ++count;
                T->root = insert(T->root, k);
                break;

            case 'p': //print values greater than input
                // scanf ("%d" , &k);
                // count = 0;
                // DFS(T->root, k, &count);
                // printf("%d\n" , count);
                // k = (count+1)/2;
                //Inorder(T->root, (count%2)+1);
                printf("\n");

                
                break;

            case 'g':
                GetMedian(T->root);
                printf ("\n");
                break;
        }


    } while(current != 't');


    return 0;
}