#ifndef SNUS_H
#define SNUS_H
#include "Product.h"

class Snus : public Product {
private:
    std::string flavor;
    int nicotineMg;
    public:
    Snus();
    Snus(std::string name, double price, int stock, std::string flavor, int nicotineMg);
    Snus(const Snus &s);
    Snus &operator=(const Snus &s);
    ~Snus();
    std::string getType() const override {return "Snus";}
    void currentOutput(std::ostream& os) const override;
    void currentInput(std::istream& is) override;
    void serialize(std::ostream &os) const override;
    void deserialize(std::istream &is) override;
};

#endif