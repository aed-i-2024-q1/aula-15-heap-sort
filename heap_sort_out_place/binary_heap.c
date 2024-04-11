#include "binary_heap.h"

#include <stdio.h>
#include <stdlib.h>

struct BinaryHeap {
    Element* data;
    int capacity;
    int size;
};

BinaryHeap* bheap_create(int capacity) {
    BinaryHeap* bheap = malloc(sizeof(BinaryHeap));

    bheap->data = malloc(capacity * sizeof(Element));
    bheap->capacity = capacity;
    bheap->size = 0;

    return bheap;
}

void bheap_destroy(BinaryHeap* bheap) {
    free(bheap->data);
    free(bheap);
}

int left(int index) {
    return index * 2 + 1;
}

int right(int index) {
    return index * 2 + 2;
}

int parent(int index) {
    return (index - 1) / 2;
}

bool hasLeft(BinaryHeap* bheap, int index) {
    return left(index) < bheap->size;
}

bool hasRight(BinaryHeap* bheap, int index) {
    return right(index) < bheap->size;
}

bool hasParent(BinaryHeap* bheap, int index) {
    return index > 0;
}

Element getLeft(BinaryHeap* bheap, int index) {
    if (!hasLeft(bheap, index)) {
        return ELEMENT_NULL;
    }

    return bheap->data[left(index)];
}

Element getRight(BinaryHeap* bheap, int index) {
    if (!hasRight(bheap, index)) {
        return ELEMENT_NULL;
    }

    return bheap->data[right(index)];
}

Element getParent(BinaryHeap* bheap, int index) {
    if (!hasParent(bheap, index)) {
        return ELEMENT_NULL;
    }

    return bheap->data[parent(index)];
}

Element get(BinaryHeap* bheap, int index) {
    if (index >= bheap->size) {
        return ELEMENT_NULL;
    }

    return bheap->data[index];
}

void swapAt(BinaryHeap* bheap, int i, int j) {
    Element temp = bheap->data[i];
    bheap->data[i] = bheap->data[j];
    bheap->data[j] = temp;
}

void siftUp(BinaryHeap* bheap) {
    int cur = bheap->size - 1;

    while (hasParent(bheap, cur) && get(bheap, cur) > getParent(bheap, cur)) {
        swapAt(bheap, cur, parent(cur));
        cur = parent(cur);
    }
}

int maximumAt(BinaryHeap* bheap, int pos1, int pos2) {
    return get(bheap, pos1) > get(bheap, pos2) ? pos1 : pos2;
}

void siftDownAt(BinaryHeap* bheap) {
    int cur = 0;

    while (hasLeft(bheap, cur)) {
        int maxChild = maximumAt(bheap, left(cur), right(cur));

        if (get(bheap, cur) > get(bheap, maxChild)) {
            break;
        }

        swapAt(bheap, cur, maxChild);
        cur = maxChild;
    }
}

void bheap_insert(BinaryHeap* bheap, Element element) {
    if (bheap_isFull(bheap)) {
        return;
    }

    bheap->data[bheap->size] = element;
    bheap->size++;
    siftUp(bheap);
}

Element bheap_extract(BinaryHeap* bheap) {
    if (bheap->size == 0) {
        return ELEMENT_NULL;
    }

    Element result = bheap->data[0];

    bheap->data[0] = bheap->data[bheap->size - 1];
    bheap->size--;
    siftDownAt(bheap);

    return result;
}

Element bheap_peek(BinaryHeap *heap) {
    if (heap->size == 0) {
        return ELEMENT_NULL;
    }

    return heap->data[0];
}

int bheap_size(BinaryHeap* bheap) {
    return bheap->size;
}

bool bheap_isEmpty(BinaryHeap* bheap) {
    return bheap->size == 0;
}

bool bheap_isFull(BinaryHeap* heap) {
    return heap->size == heap->capacity;
}

void bheap_print(BinaryHeap* bheap) {
    for (int i = 0; i < bheap->size; i++) {
        element_print(bheap->data[i]);
        printf(" ");
    }
    printf("\n");
}

// Path: binary_heap/main.c

