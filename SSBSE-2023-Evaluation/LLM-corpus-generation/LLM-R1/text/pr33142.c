// Modification timestamp: 2023-08-14 14:54:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33142.c
int abs(int j);
extern void abort(void);

__attribute__((noinline)) int lisp_atan2(long dy, long dx) {
    if (dx <= 0)
        if (dy > 0)
            return abs(dx) <= abs(dy);
    return 0;
}

int main() {
    volatile long dy = 63, dx = -77;
    if (lisp_atan2(dy, dx))
        abort();
    return 0;
}
