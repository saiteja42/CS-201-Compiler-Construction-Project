../../LLVM/install/bin/opt -S -load ../../build/ReachingDef/libReachingDef.so -ReachingDef < $1 > $1.out
