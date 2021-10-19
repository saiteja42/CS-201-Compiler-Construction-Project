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

struct ReachingDef : public FunctionPass
{
  static char ID;
  ReachingDef() : FunctionPass(ID) {}

  bool runOnFunction(Function &F) override
  {
    errs() << "ReachingDefinition: ";
    errs() << F.getName() << "\n";

    return true;
  }
}; // end of struct CSElimination
} // end of anonymous namespace

char ReachingDef::ID = 0;
static RegisterPass<ReachingDef> X("ReachingDef", "Reaching Definition Pass",
                                      false /* Only looks at CFG */,
                                      true /* Analysis Pass */);
