#include "Shop.h"
#include "Vape.h"
#include "Cigarettes.h"
#include "Snus.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>

using namespace std;

void Shop::clearInventory() {
    for (Product* p : inventory) {
        delete p;
    }
    inventory.clear();
}

Shop::Shop() {
    ifstream fin("config.txt");
    if (fin.is_open()) {
        getline(fin, shopName);
        fin.close();
    } else {
        shopName = "Tobacco Shop";
    }
}

Shop::Shop(const Shop &other) : shopName(other.shopName), customers(other.customers) {
    for (Product* p : other.inventory) {
        if (p->getType() == "VAPE") {
            inventory.push_back(new Vape(*dynamic_cast<Vape*>(p)));
        } else if (p->getType() == "CIGARETTES") {
            inventory.push_back(new Cigarettes(*dynamic_cast<Cigarettes*>(p)));
        } else if (p->getType() == "SNUS") {
            inventory.push_back(new Snus(*dynamic_cast<Snus*>(p)));
        }
    }
}

Shop &Shop::operator=(const Shop &other) {
    if (this != &other) {
        clearInventory();
        shopName = other.shopName;
        customers = other.customers;
        for (Product* p : other.inventory) {
            if (p->getType() == "VAPE") {
                inventory.push_back(new Vape(*dynamic_cast<Vape*>(p)));
            } else if (p->getType() == "CIGARETTES") {
                inventory.push_back(new Cigarettes(*dynamic_cast<Cigarettes*>(p)));
            } else if (p->getType() == "SNUS") {
                inventory.push_back(new Snus(*dynamic_cast<Snus*>(p)));
            }
        }
    }
    return *this;
}

Shop::~Shop() {
    clearInventory();
}

void Shop::addProduct(Product* p) {
    inventory.push_back(p);
}

void Shop::sellProduct(string& productName, int quantity) {
    for (Product* p : inventory) {
        if (p->getName() == productName) {
            if (p->getStock() < quantity) {
                throw OutOfStockException();
            }
            p->setStock(p->getStock() - quantity);
            cout << ">> Successfully sold " << quantity << " " << productName << "!\n";
            return;
        }
    }
    throw ProductNotFoundException();
}

void Shop::displayReport() const {
    cout << "\n=== INVENTORY REPORT: " << shopName << " ===\n";
    double totalValue = 0;
    for (const Product* p : inventory) {
        cout << *p;
        totalValue += (p->getPrice() * p->getStock());
    }
    cout << "---------------------------------\n";
    cout << "Total inventory value: " << totalValue << " RON\n\n";
}

void Shop::saveInventoryToFile(const string& filename) const {
    ofstream fout(filename);
    for (const Product* p : inventory) {
        p->serialize(fout);
    }
    fout.close();
}

void Shop::loadInventoryFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin.is_open()) return;

    clearInventory();
    string type;
    while (getline(fin, type)) {
        Product* p = nullptr;
        if (type == "Vape") {
            p = new Vape();
        } else if (type == "Cigarettes") {
            p = new Cigarettes();
        } else if (type == "Snus") {
            p = new Snus();
        }

        if (p) {
            p->deserialize(fin);
            inventory.push_back(p);
        }
    }
    fin.close();
}

ostream &operator<<(ostream &os, const Shop &s) {
    os << "Shop: " << s.shopName << " | Products in inventory: " << s.inventory.size();
    return os;
}

istream &operator>>(istream &is, Shop &s) {
    cout << "Enter new shop name: ";
    getline(is, s.shopName);
    return is;
}