#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stdbool.h>

#include "element.h"

typedef struct BinaryHeap BinaryHeap;

BinaryHeap* bheap_create(int capacity);
void bheap_destroy(BinaryHeap* heap);
void bheap_insert(BinaryHeap *heap, Element element);
Element bheap_extract(BinaryHeap *heap);
Element bheap_peek(BinaryHeap *heap);
int bheap_size(BinaryHeap* heap);
bool bheap_isEmpty(BinaryHeap* heap);
bool bheap_isFull(BinaryHeap* heap);
void bheap_print(BinaryHeap* heap);

#endif