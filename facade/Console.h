#include <vector>
#include "Window.h"
#include "TextBuffer.h"
using namespace std;

class Console {
public:
    static Console& instance() {
        static Console console;
        return console;
    }
    vector<shared_ptr<Window>> windows;

    shared_ptr<Window> single(const string& title, uint8_t charsWide,
                              uint8_t charsHigh) {
        auto w = make_shared<Window>(title, charsWide * charWidth,
        charsHigh * charHeight);
        auto buffer = make_shared<TextBuffer>(charsWide, charsHigh);
        w->buffers.push_back(buffer);
        auto viewport = make_shared<Viewport>(buffer);
        w->viewports.push_back(viewport);
        windows.push_back(w);
        return w;
    }

    shared_ptr<Window> multicolumn(const string& title, uint8_t columnCount,
                                   uint8_t charsWide, uint8_t charsHigh) {
        auto w = make_shared<Window>(title, columnCount * charsWide * charWidth,
                                     columnCount * charsHigh * charHeight);
        for (int j = 0; j < columnCount; ++j) {
            auto buffer = make_shared<TextBuffer>(charsWide, charsHigh);
            w->buffers.push_back(buffer);
            auto viewport = make_shared<Viewport>(buffer, buffer->get_size(),
            Point{}, Point{charsWide * j, 0});
            w->viewports.push_back(viewport);
            windows.push_back(w);
        }
        return w;
    }

private:
    const int charWidth = 10, charHeight = 14;
    Console() {}
    Console(const Console&) = delete;
    void operator =(const Console&) = delete;
};