#include <malloc.h>
#include "Sort.h"
#include "String.h"
// #include "B_Tree.h"
// #include "Search.h"

int *buffer;
void Hello()
{
    int age = 10;
    buffer = &age;
}
int main(int argc, char *argv[])
{
    Hello();
    printf("%d\n", *buffer);
    return 0;
}
