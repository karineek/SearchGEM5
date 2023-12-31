// Modification timestamp: 2023-08-14 12:14:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020404-1.c

#include <stdio.h>
#include <stdlib.h>

typedef long long bfd_signed_vma;
typedef bfd_signed_vma file_ptr;

typedef enum bfd_boolean { false, true } boolean;

typedef unsigned long long bfd_size_type;

typedef unsigned int flagword;

typedef unsigned long long CORE_ADDR;
typedef unsigned long long bfd_vma;

struct bfd_struct {
    int x;
};

struct asection_struct {
    unsigned int user_set_vma : 1;
    bfd_vma vma;
    bfd_vma lma;
    unsigned int alignment_power;
    unsigned int entsize;
};

typedef struct bfd_struct bfd;
typedef struct asection_struct asection;

static bfd *bfd_openw_with_cleanup(char *filename, const char *target, char *mode);

static asection *bfd_make_section_anyway(bfd *abfd, const char *name);

static boolean bfd_set_section_size(bfd *abfd, asection *sec, bfd_size_type val);

static boolean bfd_set_section_flags(bfd *abfd, asection *sec, flagword flags);

static boolean bfd_set_section_contents(bfd *abfd, asection *section, void *data, file_ptr offset, bfd_size_type count);

static void dump_bfd_file(char *filename, char *mode,
                          char *target, CORE_ADDR vaddr,
                          char *buf, int len) {
    bfd *obfd;
    asection *osection;

    obfd = bfd_openw_with_cleanup(filename, target, mode);
    osection = bfd_make_section_anyway(obfd, ".newsec");
    bfd_set_section_size(obfd, osection, len);
    (((osection)->vma = (osection)->lma = (vaddr)), ((osection)->user_set_vma = (boolean)true), true);
    (((osection)->alignment_power = (0)), true);
    bfd_set_section_flags(obfd, osection, 0x203);
    osection->entsize = 0;
    bfd_set_section_contents(obfd, osection, buf, 0, len);
}

static bfd *bfd_openw_with_cleanup(char *filename, const char *target, char *mode) {
    static bfd foo_bfd = {0};
    return &foo_bfd;
}

static asection *bfd_make_section_anyway(bfd *abfd, const char *name) {
    static asection foo_section = {false, 0x0, 0x0, 0};

    return &foo_section;
}

static boolean bfd_set_section_size(bfd *abfd, asection *sec, bfd_size_type val) {
    return true;
}

static boolean bfd_set_section_flags(bfd *abfd, asection *sec, flagword flags) {
    return true;
}

static boolean bfd_set_section_contents(bfd *abfd, asection *section, void *data, file_ptr offset, bfd_size_type count) {
    if (count != (bfd_size_type) 0x1eadbeef)
        abort();
    return true;
}

static char hello[] = "hello";

int main(int argc, char *argv[]) {
    dump_bfd_file(argv[1], argv[2], argv[3], (CORE_ADDR) atoll(argv[4]), hello, atoi(argv[5]));
    exit(0);
}
