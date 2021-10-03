#include <llvm/Analysis/ScalarEvolution.h>
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

class SkeletonPass: public ModulePass{
    public:
        static char ID;
        SkeletonPass() : ModulePass(ID) {}

        virtual void getAnalysisUsage(AnalysisUsage& AU) const override;
        virtual bool runOnModule(Module &M) override;
};
