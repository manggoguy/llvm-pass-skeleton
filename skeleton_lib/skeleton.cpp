#include "skeleton.h"

char SkeletonPass::ID = 0;

static void registerSkeletonPass(const PassManagerBuilder&,
        legacy::PassManagerBase& PM){
    //you need to add other pass to use it in the your own pass.
    //For example,
    PM.add(new ScalarEvolutionWrapperPass());
    //You only need to add the above code when necessary.

    //You must write the below code
    PM.add(new SkeletonPass());
}

void SkeletonPass::getAnalysisUsage(AnalysisUsage& AU) const{
    //you need to add other pass to use it in the your own pass.
    //For example,  
    AU.addRequired<ScalarEvolutionWrapperPass>();
    //You only need to add the function when necessary.
}

bool SkeletonPass::runOnModule(Module& M) {
    for(auto& F: M) {
        if(F.hasName()){
            errs() << "The name of F " << F.getName() <<".\n";
        }
    }
}

static RegisterPass<SkeletonPass> SKELETONPASS("skeleton", "It is skeleton pass");
