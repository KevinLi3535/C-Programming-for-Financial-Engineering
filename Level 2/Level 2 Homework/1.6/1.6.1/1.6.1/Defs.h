// Defs.h
// Author: Minghan Li
// This header file contains Macro definitions for PRINT1 and PRINT2
// ifndef & endif are used to avoid multiple inclusions

#ifndef Defs_h
#define Defs_h

// Because a and b don't have given variable types, we assume that they are characters for now
// This is one of the caveat for using proprocessors, as they can take any variable type
#define PRINT1(a) printf("%c", a) 
#define PRINT2(a, b) printf("%c, %c", a,b)

#endif