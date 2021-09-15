#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <array>
#include <any>
#include <thread>
#include <chrono>
#include <exception>
#include <bit>
#include <bitset>
#include <memory>
#include <optional>
#include <unordered_map>
#include <map>
#include <fstream>
#include <functional>
#include <algorithm>
#include <atomic>
#include <cmath>
#include <cstdio>
#include <list>
#include <random>
#include <ranges>

#include <nlohmann/json.hpp>

#include "hwcppstddef.h"

std::string stdcfg = R"(
{
    "en" : "Hello World!"
}
)";

abstract_class HelloWorldCppException {
public:
    virtual void JustNone() = 0;
};


abstract_class IBaseConfigExceptionConfigLocaleNotFoundInConfigFile : public std::exception, public HelloWorldCppException {
public:
    const char * what() const override = 0;
    virtual const char* const WhatIsHappend() = 0;
    void JustNone() override = 0;
};

class ConfigExceptionConfigLocaleNotFoundInConfigFile : public IBaseConfigExceptionConfigLocaleNotFoundInConfigFile {
public:
    void JustNone() override {
        //nonoe
    }

    const char *const WhatIsHappend() override {
        return "Locale is invalide pleas contact with developers and решите this kvestion with his";
    }

    const char * what() const override {
        return "None";
    }
};

abstract_class IBaseHelloWorld {
public:
    virtual std::string GetString() = 0;
    virtual void SetString(lstring str) = 0;
};

class HelloWorld : public IBaseHelloWorld {
    char* data;
public:
    HelloWorld(lstring d) {
        SetString(d);
    }
    std::string GetString() override {
        return FROM_PTR(new std::string (data));
    }
    void SetString(const std::string_view &str) override {
        data = (char*)malloc(str.size());
        memset(data, 0, str.size());
        memcpy_s(data, str.size(), str.data(), str.size());
        data[str.size()] = '\0';
    }
};

abstract_class IBaseConfig {
public:
    virtual IBaseHelloWorld* GetHelloWorldForLang(lstring lang) = 0;
};

abstract_class IBaseConfigReader {
public:
    virtual IBaseConfig* ReadConfig() = 0;
    virtual void DoNone() = 0;
};

class Config : public IBaseConfig {
    nlohmann::json* json;
public:
    Config(lstring data) {
        auto j = nlohmann::json::parse(data);
        json = new nlohmann::json(j);
    }

    IBaseHelloWorld* GetHelloWorldForLang(lstring lang) override {
        auto j = nlohmann::json(FROM_PTR(json));
        if (j.is_null()) throw new ConfigExceptionConfigLocaleNotFoundInConfigFile();
        return new HelloWorld(FROM_PTR(new std::string(j[lang.data()].get<std::string>().data())));
    }
};

class ConfigReader : public IBaseConfigReader {
public:
    ConfigReader() {}

    IBaseConfig * ReadConfig() override {
        if (!std::filesystem::exists("HELLO_WORLD_CONFIG.JSON")) {
            std::ofstream o("HELLO_WORLD_CONFIG.JSON");
            o.clear();
            o << stdcfg;
        }

        std::ifstream t("HELLO_WORLD_CONFIG.JSON");
        std::string str((std::istreambuf_iterator<char>(t)),
                        std::istreambuf_iterator<char>());

        auto *j = new nlohmann::json(nlohmann::json::parse(str));
        return new Config(j->dump());
    }

    void DoNone() override {

    }
};

/*abstract_class IBaseHelloWorldPrinter {
public:
    virtual void Print()
};*/

int main() {
    IBaseConfigReader* c = new ConfigReader();

    IBaseHelloWorld* hello_world = c->ReadConfig()->GetHelloWorldForLang("en");

    std::cout << hello_world->GetString() << std::endl;
    hello_world->SetString("ASDASDAD");
    std::cout << hello_world->GetString() << std::endl;

    return 0;
}
