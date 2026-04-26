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

    virtual void currentOutput(std::ostream &os) const = 0;
    virtual void currentInput(std::istream &is);

    friend std::ostream &operator<<(std::ostream &os, const Product &p);
    friend std::istream &operator>>(std::istream &is, Product &p);

    std::string getName() const{return name;}
    double getPrice() const{return price;}
    int getStock() const{return stock;}
    void setStock(int stock){this->stock = stock;}

    virtual std::string getType() const = 0;
    virtual void serialize(std::ostream &os) const;
    virtual void deserialize(std::istream &is);
};

#endif
