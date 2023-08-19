
// Modification timestamp: 2023-08-10 16:31:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Applications/oggenc/20000419-1.c

struct foo { int a, b, c; };

void brother(int a, int b, int c) {
    if (a)
        abort();
}

void sister(struct foo f, int b, int c) {
    brother((f.b == b), b, c);
}

int main() {
    struct foo f = { 7, 8, 9 };
    sister(f, 1, 2);
    exit(0);
}
