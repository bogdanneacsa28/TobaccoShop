#include "Snus.h"

using namespace std;

Snus::Snus() : Product() {
    flavor = "";
    nicotineMg = 0;
}
Snus::Snus(std::string name, double price, int stock, std::string flavor, int nicotineMg) : Product(name,price,stock){
    this->flavor = flavor;
    this->nicotineMg = nicotineMg;
}

Snus::Snus(const Snus &s) :Product(s) {
    this->flavor = s.flavor;
    this->nicotineMg = s.nicotineMg;
}
Snus &Snus::operator=(const Snus &s) {
    if (this != &s) {
        Product ::operator=(s);
        this->flavor = s.flavor;
        this->nicotineMg = s.nicotineMg;
    }
    return *this;
}
Snus::~Snus(){}

void Snus::currentInput(std::istream &is) {
    Product::currentInput(is);
    cout << "Flavor: ";
    is >> flavor;
    cout << "Nicotine (mg): ";
    is >> nicotineMg;
    is.ignore();
}

void Snus::serialize(std::ostream &os) const {
    os << getType() <<"\n";
    Product ::serialize(os);
    os << flavor << '\n';
    os << nicotineMg << '\n';
}
void Snus::deserialize(std::istream &is) {
    Product ::deserialize(is);
    is >> flavor >> nicotineMg;
    is.ignore();
}
void Snus::currentOutput(std::ostream &os) const {
    os << "[SNUS] " << getName() << " | Price: " << getPrice() << " RON | Stock: " << getStock() << '\n'
       << "        -> Flavor: " << flavor << "mg | Nicotine: " << nicotineMg << "mg\n";
}
