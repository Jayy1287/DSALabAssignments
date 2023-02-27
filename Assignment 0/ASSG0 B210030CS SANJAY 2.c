#include <stdio.h>


struct queue {
	int tail;
	int head;
	int A[10000];

};
typedef struct queue queue;

int queueFull (queue *Q, int n) {
	if (Q->tail - Q->head == n) {
		return 1;
	}
	else {
		return 0;
	}
}

int queueEmpty (queue *Q) {	
	if (Q->tail - Q->head == 0){
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue (queue *Q, int k) {
	Q->A[Q->tail] = k;
	++Q->tail;
}

void dequeue (queue *Q){
	printf ("%d " , Q->A[Q->head]);
	++Q->head;
}


int main() {
	queue Q;
    Q.head = 0;
    Q.tail = 0;
	int n, temp, k, num;
	char current;
	scanf ("%d", &n);
	do {
		scanf (" %c" , &current);
		switch (current) {
		
			case 'i':
				scanf ("%d" , &k);
				temp = queueFull (&Q, n);
				if (temp == 1){
					printf ("Full\n");
				}
				else {
					enqueue (&Q, k);
				}
				break;
			case 'd':
				// scanf ("%d", &num);
				for (int i=0; i<1; ++i) {
					temp = queueEmpty (&Q);
					if (temp == 1){
						printf ("1");
					}
					else {
						dequeue (&Q);
					}					
				}
				printf ("\n");
				break;
			case 'f':
				temp = queueFull (&Q, n);
				if (temp == 1) {
					printf ("1\n");
				}
				else {
					printf ("-1\n");
				}
				break;
			case 'e':
				temp = queueEmpty (&Q);
				if (temp == 1) {
					printf ("1\n");
				}
				else {
					printf ("-1\n");
				}
				break;
			case 't':
				break;
		}
	} while (current != 't');

	return 0;
}
