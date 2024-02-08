//
// Created by root on 12/20/23.
//

#include <iostream>
#include <memory>
#include <vector>
#include <map>

class ICommand{
public:
    virtual ~ICommand() = default;
    virtual void init() = 0;
    virtual void execute() = 0;
};

using ICommandPtr = std::shared_ptr<ICommand>;

class CPre:public ICommand{
private:
    void init () override
    {
        std::cout << "pre init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Pre" << std::endl;
    }

public:
    CPre()=default;
};

class CInf:public ICommand{
private:
    void init () override
    {
        std::cout << "Inf init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Inf" << std::endl;
    }

public:
    CInf()=default;
};

class CPost:public ICommand{
private:
    void init () override
    {
        std::cout << "post init " << std::endl;
    }

    void execute () override
    {
        std::cout << "Post" << std::endl;
    }

public:
    CPost()=default;
};

//

class IModules{
public:
    virtual void makePre() = 0;
    virtual void makeInf() = 0;
    virtual void makePost() = 0;
    virtual void make() = 0;

public:
    ICommandPtr preCommand;
    ICommandPtr infCommand;
    ICommandPtr postCommand;
    std::vector<ICommandPtr> commands;

};

using IModulesPtr = std::shared_ptr<IModules>;

class makeModules final : public IModules {
public:
    void makePre() override {
        preCommand = std::make_shared<CPre>();
        commands.push_back(preCommand);
    }

    void makeInf() override {
        infCommand = std::make_shared<CInf>();
        commands.push_back(infCommand);
    }

    void makePost() override {
        postCommand = std::make_shared<CPost>();
        commands.push_back(postCommand);
    }

public:
    void make() override {
        makePre();
        makeInf();
        makePost();
    }

};

class CCompositeCommand final : public ICommand{
public:
    CCompositeCommand() = delete;
    explicit CCompositeCommand(IModulesPtr& receiver) noexcept: makeModules{ receiver}{
        commands = makeModules->commands;
    };

//    void addCommand(ICommandPtr& command) {
//        commands.push_back(command);
//    }

    void addCommand(ICommandPtr& command) {
        commands.push_back(command);
    }

    void init () override
    {
        for (const auto& command : commands) {
            command->init();
        }
    }

    void execute() override {
        for (const auto& command : commands) {
            command->execute();
        }
    }

private:
    std::vector<ICommandPtr> commands;
    IModulesPtr makeModules;
};

int main() {

    IModulesPtr p_makeModules = std::make_shared<makeModules>();
    p_makeModules->make();

    auto macroRecorder = std::make_shared<CCompositeCommand>(p_makeModules);

    macroRecorder->init();

    macroRecorder->execute();

    std::cout << "Hello" << std::endl;

    return 0;
}


