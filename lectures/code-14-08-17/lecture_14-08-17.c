#include<stdio.h>

// content of a is constant, i.e. it cannot be changed or assigned to another value
// can only be assigned once
const int * a;
int const * b;
// the pointer cannot be changed
int * const c;

typedef int (*Func)(int, int);

int soma(int a, int b) {
	return a + b;
}

typedef struct {
	int val1;
	int val2;
} Device;

Device initDevice(int val1, int val2) {
	Device d;
	d.val1 = val1;
	d.val2 = val2;
	return d;
}

int main() {
	int x = 10;
	const int * a = &x;
	int const * b =  &x;
	//*a = 11;	this cannot be done since the
	//*b = 11;  content of a and b are constant
	
	int y = 100;
	int * const c = &y;
	//c = &x; this cannot be done since the pointer of c is constant
	(*c)++;
	printf("%d\n", *c);
	
	Func f;
	
	f = soma;
	printf("Function pointer: soma = %d\n", (*f)(2,5));
	
	Device d = initDevice(1,2);
	printf("Device.val1 = %d\nDevice.val2 = %d\n", d.val1, d.val2);
	
	return 0;
}
