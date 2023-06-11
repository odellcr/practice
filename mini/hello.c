#include <stdio.h>
#include "munit.h"

int main(int argc, char *argv[])
{
    if(argc > 2)
        munit_assert_int(argv[1][0], ==, argv[2][0]);

    printf("hello, world\n");

    return 0;
}
