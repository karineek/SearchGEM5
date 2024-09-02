// Modification timestamp: 2023-08-14 11:55:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001203-2.c
#include <stdio.h>
#include <stdlib.h>

struct obstack
{
  long chunk_size;
  struct _obstack_chunk *chunk;
  char *object_base;
  char *next_free;
  char *chunk_limit;
  int alignment_mask;
  unsigned maybe_empty_object;
};

struct objfile
{
  struct objfile *next;
  struct obstack type_obstack;
};

struct type
{
  unsigned length;
  struct objfile *objfile;
  short nfields;
  struct field
  {
    union field_location
    {
      int bitpos;
      unsigned long physaddr;
      char *physname;
    } loc;
    int bitsize;
    struct type *type;
    char *name;
  } *fields;
};

struct type *alloc_type(void);
void *xmalloc(unsigned int z);
void _obstack_newchunk(struct obstack *o, int i);
void get_discrete_bounds(long long *lowp, long long *highp);

extern void *memset(void *, int, __SIZE_TYPE__);

struct type *
create_array_type(struct type *result_type, struct type *element_type)
{
  long long low_bound, high_bound;
  if (result_type == ((void *)0))
  {
    result_type = alloc_type();
  }
  get_discrete_bounds(&low_bound, &high_bound);
  (result_type)->length =
      (element_type)->length * (high_bound - low_bound + 1);
  (result_type)->nfields = 1;
  (result_type)->fields =
      (struct field *)((result_type)->objfile != ((void *)0)
                           ? ({
                               struct obstack *__h = (&(result_type)->objfile->type_obstack);
                               struct obstack *__o = (__h);
                               int __len = ((sizeof(struct field)));
                               if (__o->chunk_limit - __o->next_free < __len)
                                 _obstack_newchunk(__o, __len);
                               __o->next_free += __len;
                               (void)0;
                               (void *)__o->next_free - __len;
                             })
                           : xmalloc(sizeof(struct field)));
  return (result_type);
}

struct type *
alloc_type(void)
{
  abort();
}

void *xmalloc(unsigned int z)
{
  return 0;
}

void _obstack_newchunk(struct obstack *o, int i)
{
  abort();
}

void get_discrete_bounds(long long *lowp, long long *highp)
{
  *lowp = 0;
  *highp = 2;
}

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  struct type element_type;
  struct type result_type;

  memset(&element_type, 0, sizeof(struct type));
  memset(&result_type, 0, sizeof(struct type));
  element_type.length = 4;
  create_array_type(&result_type, &element_type);
  if (result_type.length != 12)
    abort();
  exit(0);
}