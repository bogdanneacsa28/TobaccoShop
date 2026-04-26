#include "Customer.h"

using namespace std;

Customer::Customer() {
    this->name = "";
    this->loyaltyPoints = 0;
}
Customer::Customer(std::string name, int loyaltyPoints) {
    this->name = name;
    this->loyaltyPoints = loyaltyPoints;
}

Customer::Customer(const Customer &customer) {
    this->name = customer.name;
    this->loyaltyPoints = customer.loyaltyPoints;
}
Customer& Customer::operator=(const Customer &customer) {
    if (this != &customer) {
        this->name = customer.name;
        this->loyaltyPoints = customer.loyaltyPoints;
    }
    return *this;
}
Customer::~Customer() {}

ostream &operator<<(ostream &os, const Customer &customer) {
    os << "Customer: " << customer.name << " | Loyalty Points: " << customer.loyaltyPoints;
    return os;
}
istream &operator>>(istream &is, Customer &customer) {
    cout << "Customer name: ";
    getline(is, customer.name);
    cout << "Initial loyalty points: ";
    is >> customer.loyaltyPoints;
    is.ignore();
    return is;
}
