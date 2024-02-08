//
// Created by XRDai on 12/21/23.
//

#ifndef ALGFLOW_ALGLIB_H
#define ALGFLOW_ALGLIB_H

#include <iostream>
#include "ICommonAlg.h"

class CPre:public ICommonAlg{
private:
    void init () override
    {
        std::cout << "pre init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Pre is run: ";
        std::cout << m_CommonData->m_sSourceInput << " is being process!" << std::endl;
        m_CommonData->m_sInfInput = "Pre output";
    }

    void setCommonData(CCommonDataPtr p_commonData) override
    {
        m_CommonData = p_commonData;
    }

    CCommonDataPtr getCommonData() override
    {
        return m_CommonData;
    }

public:
    CPre()=default;
    ~CPre() override =default;
};

class CInf:public ICommonAlg{
private:
    void init () override
    {
        std::cout << "Inf init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Inf is run: ";
        std::cout << m_CommonData->m_sInfInput << " is being process!" << std::endl;
        m_CommonData->m_sPostInput = "Inf output";
//        m_output = m_input;
    }

    void setCommonData(CCommonDataPtr p_commonData) override
    {
        m_CommonData = p_commonData;
    }

    CCommonDataPtr getCommonData() override
    {
        return m_CommonData;
    }

public:
    CInf()=default;
    ~CInf() override =default;
};

class CPost:public ICommonAlg{
private:
    void init () override
    {
        std::cout << "post init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Post is run: ";
        std::cout << m_CommonData->m_sPostInput << " is being process!" << std::endl;
        m_CommonData->m_sPostOutput = "Post output";
    }

    void setCommonData(CCommonDataPtr p_commonData) override
    {
        m_CommonData = p_commonData;
    }

    CCommonDataPtr getCommonData() override
    {
        return m_CommonData;
    }

public:
    CPost()=default;
    ~CPost() override =default;
};

//
class CPre_2:public ICommonAlg{
private:
    void init () override
    {
        std::cout << "pre2 init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Pre2 is run: ";
        std::cout << m_CommonData->m_sSourceInput << " is being process!" << std::endl;
        m_CommonData->m_sInfInput = "Pre2 output";
    }

    void setCommonData(CCommonDataPtr p_commonData) override
    {
        m_CommonData = p_commonData;
    }

    CCommonDataPtr getCommonData() override
    {
        return m_CommonData;
    }

public:
    CPre_2()=default;
    ~CPre_2() override =default;
};

class CInf_2:public ICommonAlg{
private:
    void init () override
    {
        std::cout << "Inf2 init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Inf2" << std::endl;
        std::cout << m_CommonData->m_sInfInput << std::endl;
        m_CommonData->m_sPostInput = "Inf2 output";
    }

    void setCommonData(CCommonDataPtr p_commonData) override
    {
        m_CommonData = p_commonData;
    }

    CCommonDataPtr getCommonData() override
    {
        return m_CommonData;
    }

public:
    CInf_2()=default;
    ~CInf_2() override =default;
};

class CPost_2:public ICommonAlg{
private:
    void init () override
    {
        std::cout << "post2 init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Post2 is run: ";
        std::cout << m_CommonData->m_sPostInput << " is being process!" << std::endl;
        m_CommonData->m_sPostOutput = "Post2 output";
    }

    void setCommonData(CCommonDataPtr p_commonData) override
    {
        m_CommonData = p_commonData;
    }

    CCommonDataPtr getCommonData() override
    {
        return m_CommonData;
    }

public:
    CPost_2()=default;
    ~CPost_2() override =default;
};

#endif //ALGFLOW_ALGLIB_H
