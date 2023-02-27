#include <stdio.h>

struct stackElem {
	int A[100];
	int top;
	int n;
};

typedef struct stackElem stack;

int stackEmpty (stack *S) {
	
	if (S->top == -1){
		return 1;
	}
	return 0;
}

int stackFull (stack *S) {

	if (S->top == (S->n)-2) {
		return 1;
	}
	return 0;
	
}

void stackPush (stack *S, int a) {
	if (stackFull(S) != 1) {
		++S->top;
		S->A[S->top] = a;
	}
	else {
		printf ("1\n");
		S->n = 2 * S->n;
		++S->top;
		S->A[S->top] = a;			
	}
	
}

int stackDelete (stack *S) {
	--S->top;
	return S->A[S->top+1];
}

int main() {
	stack S;
	int n;
	scanf ("%d" , &n);
	
	S.n = n;
	S.top = -1;
	char current;
	int inp;
	do {
		scanf (" %c" , &current);
		switch (current) {
		
			case 'i' :
				scanf ("%d" , &inp);
				stackPush (&S, inp);
				break;
			case 'd':
				if (S.top == -1) {
					printf ("-1\n");
					break;
				}
				printf ("%d\n" ,stackDelete(&S));
				break;
			case 't':
				break;
		}
	} while (current != 't');



	return 0;
}
