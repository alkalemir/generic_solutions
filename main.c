#include <stdio.h>
#include <string.h>

void generic_swap(void * vp1, void * vp2, size_t typeSize)
{
    char * px = vp1;
    char * py = vp2;
    
    while (typeSize--) {
        char temp = *px;
        *px++ = *py;
        *py++ = temp;
    }
}

void generic_reverse(void * vp, size_t typeSize, size_t len)
{
    char * ps = (char *)vp;
    char * pe = ps + (typeSize * (len - 1));
    while (ps < pe)
    {
        for (size_t i = 0; i < typeSize; ++i)
        {
            char temp = *ps;
            *ps++ = *pe;
            *pe++ = temp;
        }
        pe = pe - typeSize * 2;
    }
}

void* generic_search(const void * vp, const void * val, size_t typeSize, size_t len)
{
    for (size_t i = 0; i < len; ++i) {
        if (!memcmp(vp, val, typeSize)) {
            return (void *)vp;
        }
        vp += typeSize;
    }
    return NULL;
}

void generic_bubble_sort(void * ps, size_t typeSize, size_t len, int (*fp)(const void *, const void *))
{
    for (size_t i = 0; i < len - 1; ++i) {
        for (size_t j = 0; j < len - 1 - i; ++j) {
            if (fp(ps + (typeSize * j), ps + (typeSize * (j + 1)))) {
                generic_swap(ps + (typeSize * j), ps + (typeSize * (j + 1)), typeSize);
            }
        }
    }
}

int foo(const void *p1, const void *p2)
{
    if (*(int*)p1 > *(int*)p2)
        return 1;
    else return 0;
}

int main(void)
{
    int arr[] = {3, 5, 2, 1, 9, 12, 8};
    
    generic_bubble_sort(arr, sizeof(int), 7, foo);
    
    for (size_t i = 0; i < 7; ++i)
        printf("%d ", arr[i]);
}


