//
// Created by wolfa on 2017/7/18.
//

#ifndef STRATEGY_TEXTSTRATEGY_H
#define STRATEGY_TEXTSTRATEGY_H

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
using namespace std;

enum class OutputFormat {
    MarkDown,
    Html
};

struct ListStrategy {
    virtual ~ListStrategy() = default;
    virtual void add_list_item(ostringstream& oss, const string& item) = 0;
    virtual void start(ostringstream& oss) = 0;
    virtual void end(ostringstream& oss) = 0;
};

struct MarkDownListStrategy :ListStrategy {
    void add_list_item(ostringstream& oss, const string& item) override {
        oss << " * " << item << "\n";
    };
    void start(ostringstream& oss) override {};
    void end(ostringstream& oss) override {};
};

struct HtmlListStrategy :ListStrategy {
    void add_list_item(ostringstream& oss, const string& item) override {
        oss << "<li>" << item << "</li>"  << "\n";
    };
    void start(ostringstream& oss) override {
        oss << "<ul>" << endl;
    };
    void end(ostringstream& oss) override {
        oss << "</ul>" << endl;
    };
};

struct TextProcessorDynamic {
    void clear() {
        oss.str("");
        oss.clear();
    }
    string str() const { return oss.str();}

    void append_list(const vector<string> items) {
        list_strategy->start(oss);
        for(auto& item: items)
            list_strategy->add_list_item(oss, item);
        list_strategy->end(oss);
    }

    void set_output_format(OutputFormat format) {
        switch(format)
        {
            case OutputFormat::MarkDown:
                list_strategy = std::make_unique<MarkDownListStrategy>();
                break;
            case OutputFormat::Html:
                list_strategy = std::make_unique<HtmlListStrategy>();
                break;
            default:
                throw runtime_error("Unsupported strategy.");
        }
    }
private:
    ostringstream oss;
    unique_ptr<ListStrategy> list_strategy;
};

template <typename LS>
struct TextProcessorStatic {
    TextProcessorStatic():list_strategy(make_unique<LS>()) {}
    void clear() {
        oss.str("");
        oss.clear();
    }
    string str() const { return oss.str();}

    void append_list(const vector<string> items) {
        list_strategy->start(oss);
        for(auto& item: items)
            list_strategy->add_list_item(oss, item);
        list_strategy->end(oss);
    }
private:
    ostringstream oss;
    unique_ptr<LS> list_strategy;
};

void test_processor_dynamic() {
    TextProcessorDynamic tpd;
    tpd.set_output_format(OutputFormat::MarkDown);
    tpd.append_list({"foo", "bar", "baz"});
    cout <<tpd.str() << endl;

    tpd.clear();
    tpd.set_output_format(OutputFormat::Html);
    tpd.append_list({"foo", "bar", "baz"});
    cout <<tpd.str() << endl;
}

void test_processor_static() {
    TextProcessorStatic<MarkDownListStrategy> tpm;
    tpm.append_list({"foo", "bar", "baz"});
    cout <<tpm.str() << endl;

    TextProcessorStatic<HtmlListStrategy> tph;
    tph.append_list({"foo", "bar", "baz"});
    cout <<tph.str() << endl;
}

#endif //STRATEGY_TEXTSTRATEGY_H
