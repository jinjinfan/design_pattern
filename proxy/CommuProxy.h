//
// Created by claudia on 2017/7/3.
//

#ifndef PROXY_COMMUPROXY_H
#define PROXY_COMMUPROXY_H

#include <string>
using namespace std;

struct Pingable {
public:
    virtual ~Pingable() {}
    virtual wstring ping(const wstring& message) = 0;

};

struct Pong : Pingable {
    wstring ping(const wstring &message) override {
        return message + L" pong";
    }

};

#include <cpptest/http_client.h>
using namespace web;
using namespace http;
using namespace client;

struct RemotePong : Pingable {
    wstring ping(const wstring &message) override {
        http_client client(U("http://localhost:9149"));
        uri_builder builder(U("/api/pingpong"));
        builder.append(message);
        pplx::task<wstring> task = client.request(methods::GET,
            builder.to_string())
            .then([=](http_response r)
                  {
                      return r.extract_string();
                  });
        task.wait();
        return task.get();
    }
};

#endif //PROXY_COMMUPROXY_H
