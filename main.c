#include "src/so_long.h"

int main(int argc, char const *argv[])
{
    printf("%*.*s \n", -10, 100);

    int fd = open((const char *)argv[1], O_RDWR);
    printf("%d\n", fd);
    return 0;
}
