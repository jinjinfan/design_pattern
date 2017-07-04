#include <memory>
#include "BankAccount.h"
#include "VirtualProxy.h"
#include "CommuProxy.h"

void smart_pointers() {
    std::shared_ptr<CurrentBankAccount> b = std::make_shared<CurrentBankAccount>(123);
    b->deposit(321);
    CurrentBankAccount* underlying = b.get();
    std::cout << *b << std::endl;
}

void draw_image(Image& img) {
    cout << "About to draw the image" << endl;
    img.draw();
    cout << "Done drawing the image" << endl;
}

void virtual_proxy() {
    std::cout << "Virtual proxy: bitmap!" << std::endl;
    Bitmap bitmap{"Pokemon.png"};
    draw_image(bitmap);
    std::cout << "Virtual proxy: lazybitmap!" << std::endl;
    LazyBitmap lazyBitmap{"Pokemon.png"};
    draw_image(lazyBitmap);
    draw_image(lazyBitmap);
}

void tryit(Pingable& p) {
    wcout << p.ping(L"ping") << "\t";
}

int main() {
    std::cout << "Smart pointers!" << std::endl;
    smart_pointers();
    std::cout << "Virtual proxy!" << std::endl;
    virtual_proxy();
    std::cout << "Communication proxy----local pong!" << std::endl;
    Pong pp;
    for (int size = 0; size < 10; ++size) {
        tryit(pp);
    }
    std::cout << "Communication proxy-----remote pong!" << std::endl;
    RemotePong remotePong;
    for (int size = 0; size < 10; ++size) {
        tryit(remotePong);
    }
    return 0;
}
