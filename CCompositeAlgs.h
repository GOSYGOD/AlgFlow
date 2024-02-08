//
// Created by XRDai on 12/21/23.
//

#ifndef ALGFLOW_CCOMPOSITEALGS_H
#define ALGFLOW_CCOMPOSITEALGS_H

#include <iostream>
#include <memory>
#include <vector>

#include "ICommonAlg.h"
#include "IMakeAlg.h"
#include "AlgLib.h"
#include "CMakeAlgs.h"

class CCompositeAlgs final : public ICommonAlg{
public:
    CCompositeAlgs() = delete;
    explicit CCompositeAlgs(IMakeAlgPtr& p_makeAlgs){
        m_vecAlgs = p_makeAlgs->getAlgs();
    };

    void init () override
    {
        for (const auto& command : m_vecAlgs) {
            command->setCommonData(m_CommonData);
            command->init();
        }
    }

    void execute() override {
        for (const auto& command : m_vecAlgs) {
            command->execute();
        }
    }

    void setCommonData(CCommonDataPtr p_commonData) override
    {
        m_CommonData = p_commonData;
    }

    CCommonDataPtr getCommonData() override
    {
        return m_CommonData;
    }

private:
    std::vector<ICommonAlgPtr> m_vecAlgs;
};

#endif //ALGFLOW_CCOMPOSITEALGS_H
