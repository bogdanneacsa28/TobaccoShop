#include <iostream>
#include <string>
#include "Product.h"

using namespace std;

Product::Product() {
    this->name = "";
    this->price = 0;
    this->stock = 0;
}

Product::Product(string name, double price, int stock) {
    this->name = name;
    this->price = price;
    this->stock = stock;
}
Product::Product(const Product &p) {
    this->name = p.name;
    this->price = p.price;
    this->stock = p.stock;
}
Product &Product::operator=(const Product &p) {
    if (this == &p)
        return *this;
    this->name = p.name;
    this->price = p.price;
    this->stock = p.stock;
    return *this;
}
Product::~Product() {}