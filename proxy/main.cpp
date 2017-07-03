#include <memory>
#include "BankAccount.h"
#include "VirtualProxy.h"

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

int main() {
    std::cout << "Smart pointers!" << std::endl;
    smart_pointers();
    std::cout << "Virtual proxy!" << std::endl;
    virtual_proxy();
    return 0;
}