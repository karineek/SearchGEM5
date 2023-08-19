// Modification timestamp: 2023-08-14 13:55:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990628-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    long sqlcode;
} sqlca;


struct data_record {
    int dummy;
    int a[100];
} *data_ptr, data_tmp;


int num_records(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return 1;
    }

    return atoi(argv[1]);
}


void fetch() {
    static int fetch_count;

    memset(&data_tmp, 0x55, sizeof(data_tmp));
    sqlca.sqlcode = (++fetch_count > 1 ? 100 : 0);
}


void load_data(int argc, char *argv[]) {
    struct data_record *p;
    int num = num_records(argc, argv);

    data_ptr = malloc(num * sizeof(struct data_record));
    memset(data_ptr, 0xaa, num * sizeof(struct data_record));

    fetch();
    p = data_ptr;
    while (sqlca.sqlcode == 0) {
        *p++ = data_tmp;
        fetch();
    }
}


int main(int argc, char *argv[]) {
    load_data(argc, argv);
    if (sizeof(int) == 2 && data_ptr[0].dummy != 0x5555)
        abort();
    else if (sizeof(int) > 2 && data_ptr[0].dummy != 0x55555555)
        abort();
    exit(0);
}
