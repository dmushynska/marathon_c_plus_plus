#pragma once
#include <iostream>

struct Wallet {
    int septims;
};

Wallet* createWallet(int x);
void destroyWallet(Wallet* wallet);
Wallet* createWallets(int x);
void destroyWallets(Wallet* wallet);
