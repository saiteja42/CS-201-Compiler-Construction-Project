#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <set>
#include <queue>

using namespace llvm;
using namespace std;

#define DEBUG_TYPE "AvailExpression"

namespace
{

struct AvailExpression : public FunctionPass
{
  static char ID;
  AvailExpression() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override
  {
    errs() << "AvailExpression: ";
    errs() << F.getName() << "\n";

    return true;
  }
};
} // end of anonymous namespace

char AvailExpression::ID = 0;
static RegisterPass<AvailExpression> X("AvailExpression", "AvailExpression Pass",
                                      false /* Only looks at CFG */,
                                      true /* Analysis Pass */);
