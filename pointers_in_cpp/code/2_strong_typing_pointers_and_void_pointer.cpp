/* This code explains why pointer variables need to be strongly typed. They may often be mistakenly seen as just storing addresses and hence maybe a char* pointer could be seen as capable of storing an int value. But this is not the case. */

#include <iostream>
#include <string>

using namespace std;

int main(){

	/* 1025 in binary = 
	00000000 00000000 00000100 00000001 */
	int a = 1025;
	
	/* 32 bit int pointer */
	int *p_int; 
	p_int = &a;

	cout << "Address of p_int = " << p_int << "; Value *p_int = " << *p_int << endl;

	cout << "Size of int = " << sizeof(int) << endl;

	cout << "Address of p_int + 1 = " << p_int + 1 << "; Value *(p_int + 1) = " << *(p_int + 1) << endl;

	/* 8 bit pointer */
	int8_t *p_int8_t;
	
	// p_int8_t = p_int; --> Raises error. Hence, needs to be typecast. 

	p_int8_t = (int8_t*) p_int;

	cout << "Address p_int8_t = " << static_cast<void*>(p_int8_t) << "; Value *p_int8_t = " << static_cast<int>(*p_int8_t) << endl;

	cout << "Size of p_int8_t = " << sizeof(int8_t) << endl;

	cout << "Address (p_int8_t + 1) = " << static_cast<void*>((p_int8_t + 1)) << "; Value *(p_int8_t + 1) = " << static_cast<int>(*(p_int8_t + 1)) << endl;

	return 0;
}

/* TODO:

	1. Explain why above static_cast to void* and int was required. (because int8_t seen by cout and it tries to print c-type string).
	1. Add code for next part in video where void* pointer is shown. 
*/