// Modification timestamp: 2023-08-14 13:33:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930408-1.c
typedef enum foo E;
enum foo { e0, e1 };

struct {
  E eval;
} s;

p()
{
  abort();
}

f()
{
  switch (s.eval)
    {
    case e0:
      p();
    }
}

main()
{
  s.eval = e1;
  f();
  exit(0);
}
