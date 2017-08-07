#include "my_buffer.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){
	// Create a buffer 
	Buffer b;
	// Initialize the buffer with size of 80 bytes
	uint8_t data[80];
	initBuffer(&b, data, 80);
	// The random number generator
	srand(time(NULL));
	while (!b.isFull) {
		uint8_t number = rand();
		printf("Generated number: %d\n", number);
		usleep(100000);
		addToBuffer(&b, number);
	}
	int array[20];
	memcpy(array, b.data, 80);
	// Print the array
	printf("\nArray: ");
	for (int i = 0; i < 20; i++)
		printf("%d ", array[i]);
	printBuffer(&b);
	return 0;
}
