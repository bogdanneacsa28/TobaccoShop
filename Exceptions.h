#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>

class OutOfStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Product is currently out of stock!";
    }
};

class ProductNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Product could not be found in the system!";
    }
};
#endif