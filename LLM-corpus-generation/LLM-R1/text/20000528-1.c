
// Modification timestamp: 2023-08-10 16:33:58
// Original Source: https://github.com/llvm/llvm-test-suite

unsigned long l = (unsigned long)-2;
unsigned short s;

int main() {
    long t = l;
    s = t;
    if (s != (unsigned short)-2)
        abort();
    exit(0);
}
