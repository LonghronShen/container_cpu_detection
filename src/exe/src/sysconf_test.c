//
// Created by agile6v on 6/10/18.
//

#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("%ld\n", sysconf(_SC_NPROCESSORS_ONLN));

    return 0;
}