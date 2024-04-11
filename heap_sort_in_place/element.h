#ifndef ELEMENT_H
#define ELEMENT_H

// Assumes element is a primitive type
// For complex types, you should implement a custom comparison function

#include <limits.h>

#define ELEMENT_NULL INT_MIN

typedef int Element;

void element_print(Element element);

#endif