prog=$1
args=$2

# Frama-C
echo ">> Running FRAMA-C:"
echo "(ulimit -St 300; frama-c -eva -eva-slevel 100 -eva-plevel 256 -eva-precision 5 -eva-warn-undefined-pointer-comparison pointer -eva-no-alloc-returns-null -warn-signed-overflow -eva-no-show-progress -machdep x86_64 -cpp-extra-args=\"-I/usr/include -I/usr/include/x86_64-linux-gnu\" $prog)"
(ulimit -St 300; frama-c -eva -eva-slevel 100 -eva-plevel 256 -eva-precision 5 -eva-warn-undefined-pointer-comparison pointer -eva-no-alloc-returns-null -warn-signed-overflow -eva-no-show-progress -machdep x86_64 -cpp-extra-args="-I/usr/include -I/usr/include/x86_64-linux-gnu" $prog)

# ASAN
echo ">> Running ASAN:"
echo "(ulimit -St 300; clang-12 -fsanitize=address -O0 -w -fno-omit-frame-pointer -g $prog)"
(ulimit -St 300; clang-12 -fsanitize=address -O0 -w -fno-omit-frame-pointer -g $prog)
(ulimit -St 600; ASAN_OPTIONS=detect_stack_use_after_return=1 ./a.out $args)

# MSAN
echo ">> Running MSAN:"
echo "(ulimit -St 300; clang-12 -fsanitize=memory -fno-omit-frame-pointer -g -O0 -w $prog)"
(ulimit -St 300; clang-12 -fsanitize=memory -fno-omit-frame-pointer -g -O0 -w $prog)
(ulimit -St 600; ./a.out $args)

# UBSAN
echo ">> Running UBSAN:"
echo "(ulimit -St 300; clang-12 -fsanitize=undefined -g -O1 -lgcc_s --rtlib=compiler-rt -w $prog)"
(ulimit -St 300; clang-12 -fsanitize=undefined -g -O1 -lgcc_s --rtlib=compiler-rt -w $prog)
(ulimit -St 600; ./a.out $args)
