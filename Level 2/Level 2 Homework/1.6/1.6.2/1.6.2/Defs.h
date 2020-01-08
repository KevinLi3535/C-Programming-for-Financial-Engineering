// Defs.h
// Author: Minghan 
// This header file contains two Macros that will be used in 1.6.2
// MAX2 and MAX3 return the maximum value of the given arguments. 
// Macro MAX3 make use of the macro MAX2.

// preprocessor directives to avoid multiple definition
#ifndef Def_s
#define Def_s

// Macro definitions

// return the bigger value between x and y.
#define MAX2(x,y) (x>y)? x:y  
// evaluate the bigger value between y and z first, and then compare that value with x.
#define MAX3(x,y,z) MAX2(MAX2(y,z), x) 

#endif
