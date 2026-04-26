#ifndef VAPE_H
#define VAPE_H
#include "Product.h"
class Vape : public Product {
    private:
    int puffs;
    std::string flavor;

public:
    Vape();
    Vape(std::string name,double price,int stock,std::string flavor, int puffs);
    Vape(const Vape &p);
    Vape &operator=(const Vape &p);
    ~Vape();
    std::string getType() const override {return "Vape";}
    void currentOutput(std::ostream& os) const override;
    void currentInput(std::istream& is) override;
    void serialize(std::ostream &os) const override;
    void deserialize(std::istream &is) override;
};

#endif