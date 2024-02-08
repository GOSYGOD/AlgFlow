//
// Created by XRDai on 12/21/23.
//

#include <iostream>
#include <memory>
#include <vector>
#include <map>

#include "ICommonAlg.h"
#include "IMakeAlg.h"
#include "AlgLib.h"
#include "CMakeAlgs.h"
#include "CCompositeAlgs.h"

int main() {

//    // template for make algs
//    IMakeAlgPtr p_makeAlgs = std::make_shared<CmakeAlgs>();
//    IMakeAlgPtr p_makeAlgs = std::make_shared<CmakeAlgs_strategy>();

    std::string s_fileName = "./test.txt";
    IMakeAlgPtr p_makeAlgs = std::make_shared<CmakeAlgs_strategy>(s_fileName);
//    IMakeAlgPtr p_makeAlgs = std::make_shared<CmakeAlgs_strategy_switch>(s_fileName);
    p_makeAlgs->makeAlgs();

    //
    auto p_CompositeAlgs = std::make_shared<CCompositeAlgs>(p_makeAlgs);

    // input
    CCommonDataPtr data = std::make_shared<ICommonData>();
    data->m_sSourceInput = "HAHHAHAH";

    // set data
    p_CompositeAlgs->setCommonData(data);

    // init and associate data ptr
    p_CompositeAlgs->init();

    // run
    p_CompositeAlgs->execute();

    std::cout << "Finish! The final output is: " << data->m_sPostOutput << std::endl;

    return 0;
}


