//
// Created by claudia on 2017/7/11.
//

#ifndef SINGLETON_SINGLETONDATABASE_H
#define SINGLETON_SINGLETONDATABASE_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;


class Database {
public:
    virtual int get_population(string name) = 0;
};

class SingletonDatabase : Database {
    SingletonDatabase() {
        cout << "Initializing database" << std::endl;
        fstream ifs{"/Users/claudia/Documents/workspace/design_pattern/singleton/capital.txt"};
        string s, s2;
        while (getline(ifs, s)) {
            getline(ifs, s2);
            int pop = boost::lexical_cast<int>(s2);
            capitals[s] = pop;
        }
        instance_count++;
    }
    map<string, int> capitals;

public:
    SingletonDatabase(const SingletonDatabase&) = delete;
    void operator = (const SingletonDatabase&) = delete;
    static SingletonDatabase& get() {
        static SingletonDatabase db;
        return db;
    }
    static int instance_count;
    int get_population(string name) override {
        return capitals[name];
    }
};
int SingletonDatabase::instance_count = 0;


class DummyDatabase : public Database {
    map<string, int> capitals;
public:
    DummyDatabase() {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }

    int get_population(string name) override {
        return capitals[name];
    }
};

struct SingletonRecordFinder {
    int total_population(vector<string> names) {
        int result = 0;
        for(auto& name : names) {
            result += SingletonDatabase::get().get_population(name);
        }
        return result;
    }
};

struct ConfigurableRecordFinder {
    Database& db;

    ConfigurableRecordFinder(Database &db) : db(db) {}

    int total_population(vector<string> names) {
        int result = 0;
        for(auto& name : names) {
            result += db.get_population(name);
        }
        return result;
    }
};
#endif //SINGLETON_SINGLETONDATABASE_H
