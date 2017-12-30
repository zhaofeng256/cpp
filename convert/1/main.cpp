#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char **argv)
{
    const char *str = "hello";
    char *str2 = const_cast<char *>(str);
    int *p = reinterpret_cast<int *>(str2);

    printf("int *p = 0x%x\n", reinterpret_cast<unsigned int>(p));


    return 0;
}
