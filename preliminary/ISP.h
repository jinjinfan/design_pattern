//
// Created by claudia on 2017/7/4.
//

#ifndef SPECIFICATION_ISP_H
#define SPECIFICATION_ISP_H

#include <vector>
using namespace std;

struct Document;

struct IPrint {
    virtual void print(vector<Document*> docs) = 0;
};

struct IScan {
    virtual void scan(vector<Document*> docs) = 0;
};

struct IFax {
    virtual void fax(vector<Document*> docs) = 0;
};

struct Print : IPrint {
    void print(vector<Document *> docs) override {

    }
};

struct IMachine : IPrint, IScan {};

struct Machine: IMachine {
    IPrint& iPrint;
    IScan& iScan;

    Machine(IPrint &iPrint, IScan &iScan) : iPrint(iPrint), iScan(iScan) {}

    void print(vector<Document *> docs) override {
        iPrint.print(docs);
    }

    void scan(vector<Document *> docs) override {
        iScan.scan(docs);
    }
};

#endif //SPECIFICATION_ISP_H
