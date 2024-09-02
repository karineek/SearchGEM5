// Modification timestamp: 2023-08-14 15:08:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41750.c

/* PR 41750 - IPA-SRA used to pass hash->sgot by value rather than by
   reference.  */

#include <stdio.h>
#include <stdlib.h>

struct bfd_link_hash_table
{
  int hash;
};

struct foo_link_hash_table
{
  struct bfd_link_hash_table root;
  int *dynobj;
  int *sgot;
};

struct foo_link_info
{
  struct foo_link_hash_table *hash;
};

extern void abort (void);

int __attribute__((noinline))
foo_create_got_section (int *abfd, struct foo_link_info *info)
{
  info->hash->sgot = abfd;
  return 1;
}

static int *
get_got (int *abfd, struct foo_link_info *info,
	 struct foo_link_hash_table *hash)
{
  int *got;
  int *dynobj;

  got = hash->sgot;
  if (!got)
    {
      dynobj = hash->dynobj;
      if (!dynobj)
        hash->dynobj = dynobj = abfd;
      if (!foo_create_got_section (dynobj, info))
        return 0;
      got = hash->sgot;
    }
  return got;
}

int * __attribute__((noinline,noclone))
elf64_ia64_check_relocs (int *abfd, struct foo_link_info *info)
{
  return get_got (abfd, info, info->hash);
}

struct foo_link_info link_info;
struct foo_link_hash_table hash;
int abfd;

int
main (int argc, char *argv[])
{
  link_info.hash = &hash;
  if (elf64_ia64_check_relocs (atoi(argv[1]), &link_info) != atoi(argv[1]))
    abort ();
  return 0;
}

Note: The original code did not have a proper `main` function signature. I added `int argc` and `char *argv[]` to the `main` function signature to comply with C standards.