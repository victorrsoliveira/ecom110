#ifndef __MY_BUFFER__
#define __MY_BUFFER__

#include <stdint.h>

/* This struct represents a circular buffer.
   Data holds the array of data added to the buffer.
   Head points to the first available position in the buffer.
   Everytime addToBuffer is called, it adds a new element to the
   position the head points to. Then, head is incremented.
   Tail points to the oldest element added to the buffer.
   nelem holds the number of elements in the buffer. When a new
   element is added to the buffer, nelem is incremented.
   Size holds the size of buffer in bytes.
   IsFull holds 0 or 1. IsFull is 1 if the buffer is full. Otherwise,
   it is 0.
*/
typedef struct buffer_ {
	uint8_t *data;
	uint8_t head;
	uint8_t tail;
	uint8_t nelem;
	uint8_t size;
	uint8_t isFull;
} Buffer;

void initBuffer(Buffer *q, uint8_t *data, uint8_t size);
void addToBuffer(Buffer *q, uint8_t element);
void printBuffer(Buffer *q);
#endif
