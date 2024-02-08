//
// Created by XRDai on 12/21/23.
//

#ifndef ALGFLOW_ICOMMONALG_H
#define ALGFLOW_ICOMMONALG_H

class ICommonData{
public:
    ICommonData() = default;
    ~ICommonData() = default;

public:
    std::string m_sSourceInput = "Source";
    std::string m_sInfInput = "Inf input";
    std::string m_sPostInput = "Post input";
    std::string m_sPostOutput = "Post output";
};

using CCommonDataPtr = std::shared_ptr<ICommonData>;

class ICommonAlg{
public:
    virtual ~ICommonAlg() = default;
    virtual void init() = 0;
    virtual void execute() = 0;

    virtual void setCommonData(CCommonDataPtr p_commonData) = 0;
    virtual CCommonDataPtr getCommonData() = 0;

public:
    CCommonDataPtr m_CommonData;

};

using ICommonAlgPtr = std::shared_ptr<ICommonAlg>;

#endif //ALGFLOW_ICOMMONALG_H
