#include "walletManager.h"

Wallet* createWallet(int x) {
    Wallet* w = new Wallet();
    w->septims = x;
    return w;
}
void destroyWallet(Wallet* wallet) {
    delete wallet;
    wallet = nullptr;
}

Wallet* createWallets(int x) {
    Wallet* w = new Wallet[x];
    return w;
}

void destroyWallets(Wallet* wallet) {
    delete[] wallet;
    wallet = nullptr;
}