#include <iostream>

using namespace std;

/* This is a preprocessor constant. It acts as simple text substitution. 

Preprocessor constants do not have a data type—it's simply text replacement.

There is no scope for these constants; they are available everywhere from the point of definition onward in the file.

They are not type-safe, unlike const or constexpr variables.

They can be undefined using #undef if needed. 

ALTERNATIVES - 
C++ prefers const or constexpr keywords for defining typed, scoped, and safer constants. However, #define is still widely used for certain compile-time configuration and conditional compilation scenarios.
*/
#define PI 3.14

int main () {

	

	return 0;

}