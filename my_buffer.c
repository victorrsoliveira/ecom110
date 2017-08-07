#include "my_buffer.h"
#include <stdlib.h>
#include <stdio.h>

void initBuffer(Buffer *q, uint8_t *data, uint8_t size) {
	q->data = data;
	q->head = 0;
	q->tail = 0;
	q->nelem = 0;
	q->size = size;
	q->isFull = 0;
}

void addToBuffer(Buffer *q, uint8_t element) {
	if (q->nelem < q->size) { // buffer has available space
		q->data[(int) q->head] = element;
		q->head = (q->head + 1) % q->size;
		q->nelem++;
	} else { // buffer is full
		q->isFull = 1;
		#ifdef DEBUG
		printf("Buffer is FULL!\n");
		#endif
	}
}

void printBuffer(Buffer *q) {
	printf("\n--- Buffer Information ---\nData: ");
	for (int i = 0; i < q->nelem; i++)
		printf("%x ", q->data[i]);
	printf("\n");
	printf("Head = %x\n", q->head);
	printf("Tail = %x\n", q->tail);
	printf("# elements = %d\n", q->nelem);
	printf("Size = %d\n", q->size);
	printf("Is Full? = %s\n", (q->isFull == 0) ? "False" : "True" );
	printf("--------------------------\n\n");
}
