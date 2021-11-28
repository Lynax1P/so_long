#include "so_long.h"

int main(int argc, char const *argv[])
{
    printf("%lu %lu %lu %lu\n", sizeof(char **), sizeof(double *), sizeof(char), sizeof(char *));

    int fd = open((const char *)argv[1], O_RDWR);
    printf("%d\n", fd);
    return 0;
}
