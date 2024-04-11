#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "heap_sort.h"

int left(int index) {
    return index * 2 + 1;
}

int right(int index) {
    return index * 2 + 2;
}

int parent(int index) {
    return (index - 1) / 2;
}

int last(int size) {
    return size - 1;
}

bool hasLeft(int size, int index) {
    return left(index) < size;
}

bool hasRight(int size, int index) {
    return right(index) < size;
}

bool hasParent(int index) {
    return index > 0;
}

Element get(Element* data, int size, int index) {
    if (index >= size) {
        return ELEMENT_NULL;
    }

    return data[index];
}

void swapAt(Element* data, int i, int j) {
    Element temp = data[i];

    data[i] = data[j];
    data[j] = temp;
}

int maximumAt(Element* data, int size, int pos1, int pos2) {
    return get(data, size, pos1) > get(data, size, pos2) ? pos1 : pos2;
}

void siftDownAt(Element* data, int size, int i) {
    int cur = i;

    while (hasLeft(size, cur)) {
        int maxChild = maximumAt(data, size, left(cur), right(cur));

        if (get(data, size, cur) > get(data, size, maxChild)) {
            break;
        }

        swapAt(data, cur, maxChild);
        cur = maxChild;
    }
}

void heapify(Element* data, int size) {
    for (int i = parent(size - 1); i >= 0; i--) {
        siftDownAt(data, size, i);
    }
}

void heapSort(Element* data, int size) {
    int heapSize = size;

    heapify(data, heapSize);
    for (int i = 0; i < size; i++) {
        swapAt(data, 0, heapSize - 1); 
        heapSize--;
        siftDownAt(data, heapSize, 0);
    }
}

