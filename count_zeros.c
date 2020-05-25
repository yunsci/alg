#include <stdio.h>

// count leading zeros
unsigned clz(unsigned x)
{
    unsigned n;
    if(x)
    {
        n = 0;
        if(x <= 0x0000ffff) n |= 16, x <<= 16;
        if(x <= 0x00ffffff) n |=  8, x <<= 8;
        if(x <= 0x0fffffff) n |=  4, x <<= 4;
        if(x <= 0x3fffffff) n |=  2, x <<= 2;
        if(x <= 0x7fffffff) n |=  1;
    }
    else
    {
        n = 32;
    }

    return n;
}

// count trailing zeros
unsigned ctz(unsigned x)
{
    unsigned n;
    if(x)
    {
        x &= -x;
        n = 0;
        if(x & 0xFFFF0000) n |= 16;
        if(x & 0xFF00FF00) n |= 8;
        if(x & 0xF0F0F0F0) n |= 4;
        if(x & 0xCCCCCCCC) n |= 2;
        if(x & 0xAAAAAAAA) n |= 1;
    }
    else
    {
        n = 32;
    }

    return n;
}

// test
typedef unsigned ptr(unsigned x);

void test(ptr f)
{
    for(unsigned x = 1; x; x <<= 1)
    {
        printf("x = 0x%08x: f = %2u\n", x, f(x));
    }
}

int main(int argc, char* argv[])
{
    printf("test clz ...\n");
    test(clz);

    printf("test ctz ...\n");
    test(ctz);

    return 0;
}
