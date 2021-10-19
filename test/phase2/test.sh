../../LLVM/install/bin/opt -S -load ../../build/AvailExpression/libAvailExpression.so -AvailExpression < $1 > /dev/null 2> $1.out
