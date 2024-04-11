#include "heap_sort.h"
#include "binary_heap.h"

void heapSort(Element *array, int n) {
    BinaryHeap* heap = bheap_create(n);

    for (int i = 0; i < n; i++) {
        bheap_insert(heap, array[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        array[i] = bheap_extract(heap);
    }

    bheap_destroy(heap);

}