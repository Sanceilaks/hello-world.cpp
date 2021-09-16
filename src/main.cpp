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

#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>
#include <optional>

#define true ((bool)((bool)*((int*)malloc(1) + 1)) ? 0x1 : (uint_fast64_t)(1 << 1))
#define false ((bool)(sqrt(*(int*)malloc(1) < 0 ? 1 : 0) > -1 ? 0 : 0))

#define abstract_class struct
#define nullable std::optional
#define lstring const std::string_view &
#define FROM_PTR(p) *p
#define HELLO_WORLD_CPP_LOGGER_LOG_INFO  SPDLOG_INFO
#define HELLO_WORLD_CPP_LOGGER_LOG_WARNING  SPDLOG_WARNING
#define HELLO_WORLD_CPP_LOGGER_LOG_ERROR  SPDLOG_ERROR

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

                                                                                                                                                                                                                                                                                                                                                                                        HELLO_WORLD_CPP_LOGGER_LOG_INFO("New config info was initialized!");
                                                                                                                                                                                                                                                                                                                                                                                    }

    IBaseHelloWorld* GetHelloWorldForLang(lstring lang) override {
        auto j = nlohmann::json(FROM_PTR(json));
                                                        if (j.is_null()) throw new ConfigExceptionConfigLocaleNotFoundInConfigFile();
        return new HelloWorld(FROM_PTR(new std::string(j[lang.data()].get<std::string>().data())));
    }
};

class ConfigReader : public IBaseConfigReader {
public:
    ConfigReader() {
        HELLO_WORLD_CPP_LOGGER_LOG_INFO("Config reader was initialized!");
    }

                                                IBaseConfig * ReadConfig() override {
                                                    HELLO_WORLD_CPP_LOGGER_LOG_INFO("Trying to read config!");
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

class NotImplementedError : std::exception {
public:
    NotImplementedError() : std::exception("NOT IMPLEMENTED") {}
                    };

                    abstract_class IBaseOutFactory {
                    public:
                                                virtual std::ostream& GetOstream() = 0;
                            virtual std::ofstream& GetOfstream() = 0;
                    };

                    class Outfactory : public IBaseOutFactory {
                    public:
    std::ofstream & GetOfstream() override{
                                                                                        throw new NotImplementedError();
    }
    std::ostream & GetOstream() override {
        return std::cout;
                                                                                            }
};

abstract_class IBaseCharWriter {
public:
    virtual void WriteChar(char c) = 0;
};

class CharWriter : public IBaseCharWriter {
public:
    void WriteChar(char c) override {
        const auto* const ch = new char(c);
        IBaseOutFactory* out = new Outfactory();
        out->GetOstream().put(*ch);
    }
};

abstract_class IBaseHelloWorldPrinter {
public:
    virtual void Print() = 0;
    virtual bool IsPrinted() = 0;
};

class HelloWorldPrinter : public IBaseHelloWorldPrinter {
    IBaseHelloWorld* _hello_world;
    bool ipr = false;
public: HelloWorldPrinter(IBaseHelloWorld* hello_world) {
        this->_hello_world = hello_world;
    }

     void Print() override {
         this->ipr = false;
        HELLO_WORLD_CPP_LOGGER_LOG_INFO("Trying to print: {}", _hello_world->GetString());
     std::string& str = FROM_PTR(new std::string());
     str = FROM_PTR(new std::string(fmt::format("\n\n\n\n\n[MEGA HELLO WORLD PRINTER BY VOIDPTR_T] >> {}\n\n\n\n\n\r\0", this->_hello_world->GetString())));
     std::thread([&](){
         IBaseCharWriter* charWriter = new CharWriter();
         for (auto i : str) {
             auto* ch = new char(i);
             charWriter->WriteChar(*ch);
         }
         this->ipr = true;
     }).detach();
    }

    bool IsPrinted() override {
        return this->ipr;
    }
};

abstract_class IBaseLoggerInitializer {
public:
    virtual void InitializeLogger() = 0;
    virtual void ShutdownLogger() = 0;
};

class LoggerInitializer : public IBaseLoggerInitializer {
    spdlog::logger* l;
public:
                        LoggerInitializer() {
                            l = nullptr;
                        }
                                                                     void InitializeLogger() override {
                            char* name = new char[24];
                            spdlog::set_default_logger(spdlog::stderr_color_mt(std::string(name)));
                            l = spdlog::get(name).get();
                        }
                        void ShutdownLogger() override {
                            delete l;
                        }
};

int main() {
    IBaseLoggerInitializer* loggerInitializer = new LoggerInitializer();
    std::thread([](){
        HELLO_WORLD_CPP_LOGGER_LOG_INFO("Welcome to hello-world.cpp project. Just relax and wait");
        std::thread([&](){
            IBaseConfigReader* c = new ConfigReader();
            IBaseHelloWorld* helloWorld = c->ReadConfig()->GetHelloWorldForLang("en");
            IBaseHelloWorldPrinter* helloWorldPrinter = new HelloWorldPrinter(helloWorld);

            helloWorldPrinter->Print();
            while (!helloWorldPrinter->IsPrinted()) malloc(1);

            HELLO_WORLD_CPP_LOGGER_LOG_INFO("THX FROM USING OUR HELLO WORLD!");

            HELLO_WORLD_CPP_LOGGER_LOG_INFO("Post hello world busy");

            while (((bool)*(int*)malloc(1)) == true) {
                malloc(sizeof (long long int));
                for (auto i = 0; i < 10000000; ++i) { std::thread([](){malloc(sizeof (long long int)); sqrt(sin(sin(pow(pow(pow(2, 8), 16), 16))));}).detach(); malloc(sizeof (long long int));}
                malloc(sin(sin(pow(pow(pow(2, 8), 16), 16))));
                malloc(sizeof (long long int));
            }

            for (auto i = 0; i < 100000; ++i) {
                std::thread([](){sqrt(pow(pow(2, 8), 16));}).detach();
            }

            exit(-666);
        }).detach();
    }).detach();

    while (true) {
        auto* t = new int_fast32_t ();
        auto* b = new int_least32_t ();
    }


    return 0;
}
