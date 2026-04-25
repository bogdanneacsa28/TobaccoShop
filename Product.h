#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
class Product {
private:
    std::string name;
    double price;
    int stock;
public:
    Product();
    Product(std::string name, double price, int stock);
    Product(const Product &p);
    Product &operator=(const Product &p);
    virtual ~Product();
};

#endif
