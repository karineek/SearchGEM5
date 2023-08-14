
// Modification timestamp: 2023-08-10 15:54:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C++/2003-06-16-InvalidInitializer.c

typedef struct {
    char *auth_pwfile;
    int x;
} auth_config_rec;

void *Ptr = &((auth_config_rec*)0)->x;

int main(int argc, char *argv[]) { return 0; }
