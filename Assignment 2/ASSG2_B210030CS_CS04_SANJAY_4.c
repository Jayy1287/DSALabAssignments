#include <stdio.h>
#include <stdlib.h>


int hash1 (int key, int tsize) {
	return key%tsize;
}

int is_prime(int n){
	if (n <= 1){
		return 0;
	}
	for (int i=2; i<n; i++){
		if(n%i == 0){
			return 0;
		}
	}
	return 1;
}

int get_largest_prime (int n){
	for (int i = n-1; i>=2; i--){
		if (is_prime(i) == 1){
			return i;
		}
	}
	return 2;
}


void double_hash (int *keys, int n, int tsize) {

	int table[100];
	
	int collisions = 0;
	int totalColl = 0;
	int h1, h2;
	int temp;
	
	int i;
	for (i=0; i<tsize; ++i) {
		table[i] = 0;
	}
	int key, h, j;
	for (i=0; i<n ; ++i) {
		key = keys[i];
		h = hash1(key, tsize);
		
		// printf ("h is %d\n" , h);
		
		if (table[h] == 0) {
			table[h] = key;	
			printf ("%d " , h);	
		}
		else {
			++collisions;
			j = 1;
			temp = get_largest_prime(tsize);
			//printf ("\nkt %d %d\n" ,key, temp);
			h1 = hash1(key, tsize);
			h2 = temp - (key % temp);
			h = (h1+(j*h2))%tsize;

			while (table[h] != 0) {
				
				++j;
				++collisions;
				h = (h1+(j*h2))%tsize;
				if (collisions == tsize){
					break;
				}
			}
			totalColl = totalColl + collisions;
			table[h] = key;
			if (collisions < tsize){
				printf ("%d " , h);

			}
			else {
				printf ("E ");
			}
			collisions = 0;

		}
			
	}
	printf ("\n%d\n" , totalColl);	
	

}

void linear (int *keys, int n, int tsize) {

	int table[100];
	
	int collisions = 0;
	
	int i;
	for (i=0; i<tsize; ++i) {
		table[i] = 0;
	}
	int key, h, j;
	for (i=0; i<n ; ++i) {
		key = keys[i];
		h = hash1(key, tsize);
		// printf ("h is %d\n" , h);
		
		if (table[h] == 0) {
			table[h] = key;	
			printf ("%d " , h);	
		}
		else {
			++collisions;
			j = 1;
			while (table[(h+j)%tsize] != 0) {
				++j;
				++collisions;			
			}
			table[(h+j)%tsize] = key;
			
			printf ("%d " , (h+j)%tsize);		
		}
			
	}
	printf ("\n%d\n" , collisions);	
	

}
void quadratic (int *keys, int n, int tsize) {

	int table[100];	
	int collisions = 0;	
	int totalColl = 0;
	int i;
	for (i=0; i<tsize; ++i) {
		table[i] = 0;
	}
	int key, h, j;
	for (i=0; i<n ; ++i) {
		collisions = 0;
		key = keys[i];
		h = hash1(key, tsize);
		// printf ("h is %d\n" , h);
		
		if (table[h] == 0) {
			table[h] = key;	
			printf ("%d " , h);	
		}
		else {
			++collisions;
			j = 1;
			while (table[(h+(j*j))%tsize] != 0) {
				++j;
				++collisions; 
				if (collisions == tsize){
					break;
				}			
			}
			table[(h+(j*j))%tsize] = key;
			if (collisions < tsize){
				printf ("%d " , (h+(j*j))%tsize);
			}
			else  {
				printf("E ");
			}
					
		}
		totalColl = totalColl + collisions;
			
	}
	printf ("\n%d\n" , totalColl);	
	

}

int main() {
	int tsize, i ;
	int a[1000] = {0};
	int check;
	
	
	scanf ("%d" , &tsize);
	for (i = 0; i<tsize ; ++i) {
		// check = scanf ("%d", &a[i]);
		if (scanf ("%d", &a[i]) != 1 ){
			// ++i;
			break;
		}
		// if (a[i] == (int)('\n')){
		// 	break;
		// }
	}
	// for (i = 0; i<tsize-1 ; ++i) {
	// 	printf ("%d  ", a[i]);	
	// }
	// printf ("i is %d " , i);
	linear (a, i, tsize); 
	// linear_probing (a, tsize-1, tsize); 
	quadratic(a, i, tsize);
	double_hash(a, i, tsize);
	


	return 0;
}