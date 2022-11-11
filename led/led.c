#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "stdlib.h"
#include "string.h"

#define LED_OFF     0
#define LED_ON      1

int main(int argc, char *argv[])
{
    int fd = -1;
    int ret_value = 0;
    char *file_name = NULL;
    unsigned char data_buf = 0;

    if (argc != 3)  {
        printf("Error Usage!\r\n");
        return -1;
    }

    file_name = argv[1];
    fd = open(file_name, O_RDWR);
    if (fd < 0) {
        printf("file %s open failed!\r\n", file_name);
            return -1;
    }

    data_buf = atoi(argv[2]);
    ret_value = write(fd, &data_buf, sizeof(data_buf));
    if (ret_value < 0) {
        printf("LED Control Failed!\r\n");
        close(fd);
        return -1;
    }

    ret_value = close(fd);
    if (ret_value < 0) {
        printf("file %s close failed!\r\n", argv[1]);
        return -1;
    }

    return 0;
}