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
void Product::currentInput(std::istream &is) {
    cout << "Product name: ";
    getline(is, name);
    cout << "Price: ";
    is >> price;
    cout << "Initial stock: ";
    is >> stock;
    is.ignore();
}

istream &operator>>(istream &is, Product &p) {
    p.currentInput(is);
    return is;
}
ostream &operator<<(ostream &os, const Product &p) {
    p.currentOutput(os);
    return os;
}
void Product::serialize(ostream &os) const {
    os << name << '\n';
    os << price << '\n';
    os << stock << '\n';
}
void Product::deserialize(istream &is) {
    getline(is, name);
    is >> price >> stock;
    is.ignore();
}
