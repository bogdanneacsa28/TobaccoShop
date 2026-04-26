#ifndef SHOP_H
#define SHOP_H
#include "Product.h"
#include "Customer.h"
#include <vector>

class Shop {
private:
    std::string shopName;
    std::vector<Product*> inventory;
    std::vector<Customer> customers;

    void clearInventory();

public:
    Shop();
    Shop(const Shop &other);
    Shop &operator=(const Shop &other);
    ~Shop();

    friend std::ostream &operator<<(std::ostream &os, const Shop &s);
    friend std::istream &operator>>(std::istream &is, Shop &s);

    void addProduct(Product* p);
    void sellProduct(std::string& productName, int quantity);
    void displayReport() const;

    void saveInventoryToFile(const std::string& filename) const;
    void loadInventoryFromFile(const std::string& filename);
};
#endif