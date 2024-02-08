//
// Created by XRDai on 12/21/23.
//

#ifndef ALGFLOW_CMAKEALGS_H
#define ALGFLOW_CMAKEALGS_H

#include <iostream>
#include <memory>
#include "IMakeAlg.h"
#include "AlgLib.h"

class CmakeAlgs final : public IMakeAlg {
public:
    CmakeAlgs() = default;
    ~CmakeAlgs() = default;

    void makePre() override {
        m_pPreAlg = std::make_shared<CPre>();
        m_vecAlgs.push_back(m_pPreAlg);
    }

    void makeInf() override {
        m_pInfAlg = std::make_shared<CInf>();
        m_vecAlgs.push_back(m_pInfAlg);
    }

    void makePost() override {
        m_pPostAlg = std::make_shared<CPost>();
        m_vecAlgs.push_back(m_pPostAlg);
    }

public:
    void makeAlgs() override {
        makePre();
        makeInf();
        makePost();
    }
};

class CmakeAlgs_strategy final : public IMakeAlg {
public:
    CmakeAlgs_strategy() = default;
    explicit CmakeAlgs_strategy(std::string & p_sfileName)
    {
        // set flag
        b_preIsValid = true;
        b_infIsValid = true;
        b_postIsValid = true;

        // select alg
        m_preName = "pre_2";
        m_infName = "inf";
        m_postName = "post_2";
    };

    ~CmakeAlgs_strategy() = default;

    void makePre() override {
        if(b_preIsValid)
        {
            m_pPreAlg = m_mapPreAlgsLibs[m_preName];
            m_vecAlgs.push_back(m_pPreAlg);
        }
    }

    void makeInf() override {
        if(b_infIsValid)
        {
            m_pInfAlg = m_mapInfAlgsLibs[m_infName];
            m_vecAlgs.push_back(m_pInfAlg);
        }
    }

    void makePost() override {
        if(b_postIsValid)
        {
            m_pPostAlg = m_mapPostAlgsLibs[m_postName];
            m_vecAlgs.push_back(m_pPostAlg);
        }
    }

public:
    void makeAlgs() override {
        makePre();
        makeInf();
        makePost();
    }

private:
    std::string m_preName = "pre";
    std::string m_infName = "inf";
    std::string m_postName = "post";

    // bool
    bool b_preIsValid = true;
    bool b_infIsValid = true;
    bool b_postIsValid = true;

    //
    std::map<std::string, ICommonAlgPtr> m_mapPreAlgsLibs = {{"pre", std::make_shared<CPre>()}, {"pre_2", std::make_shared<CPre_2>()}};
    std::map<std::string, ICommonAlgPtr> m_mapInfAlgsLibs = {{"inf", std::make_shared<CInf>()}, {"inf_2", std::make_shared<CInf_2>()}};
    std::map<std::string, ICommonAlgPtr> m_mapPostAlgsLibs = {{"post", std::make_shared<CPost>()}, {"post_2", std::make_shared<CPost_2>()}};

};

class CmakeAlgs_strategy_switch final : public IMakeAlg {
public:
    CmakeAlgs_strategy_switch() = default;
    explicit CmakeAlgs_strategy_switch(std::string & p_sfileName)
    {
        // set flag
        b_preIsValid = true;
        b_infIsValid = false;
        b_postIsValid = false;

        // select alg
        m_preName = "pre_2";
        m_infName = "inf";
        m_postName = "post_2";
    };

    ~CmakeAlgs_strategy_switch() = default;

    void makePre() override {
        if(b_preIsValid)
        {
            if (m_preName == "pre")
                m_pPreAlg = std::make_shared<CPre>();
            else if(m_preName == "pre_2")
                m_pPreAlg = std::make_shared<CPre_2>();
            else
                m_pPreAlg = std::make_shared<CPre>();

            m_vecAlgs.push_back(m_pPreAlg);
        }
    }

    void makeInf() override {
        if(b_infIsValid)
        {
            if (m_infName == "inf")
                m_pInfAlg = std::make_shared<CInf>();
            else if(m_infName == "inf_2")
                m_pInfAlg = std::make_shared<CInf_2>();
            else
                m_pInfAlg = std::make_shared<CPre>();

            m_vecAlgs.push_back(m_pInfAlg);
        }
    }

    void makePost() override {
        if(b_postIsValid)
        {
            if (m_postName == "post")
                m_pPostAlg = std::make_shared<CInf>();
            else if(m_postName == "post_2")
                m_pPostAlg = std::make_shared<CInf_2>();
            else
                m_pPostAlg = std::make_shared<CPre>();

            m_vecAlgs.push_back(m_pPostAlg);
        }
    }

public:
    void makeAlgs() override {
        makePre();
        makeInf();
        makePost();
    }

private:
    std::string m_preName = "pre";
    std::string m_infName = "inf";
    std::string m_postName = "post";

    // bool
    bool b_preIsValid = true;
    bool b_infIsValid = true;
    bool b_postIsValid = true;

};

#endif //ALGFLOW_CMAKEALGS_H
