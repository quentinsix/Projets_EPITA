#include "heap.h"

int main()
{
    struct heap *h = create_heap();
    add(h, 1);
    add(h, 3);
    add(h, -9);
    add(h, 8);
    print_heap(h);
    return 1;
}
