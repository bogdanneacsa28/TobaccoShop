#include "Vape.h"
using namespace std;

Vape::Vape() : Product(){
    this->flavor = "";
    this->puffs = 0;
}
Vape::Vape(string name,double price,int stock, string flavor, int puffs) : Product(name,price,stock) {
    this->flavor = flavor;
    this->puffs = puffs;
}

Vape::Vape(const Vape &p):Product(p),puffs(p.puffs) ,flavor(p.flavor) {
}

Vape &Vape::operator=(const Vape &p) {
    if (this != &p) {
        Product ::operator=(p);
        flavor = p.flavor;
        puffs = p.puffs;
    }
    return *this;
}
Vape::~Vape() {
}

void Vape::currentOutput(std::ostream &os) const {
    os << "[VAPE] " << getName()
        << " | Price: " << getPrice() << " RON"
        << " | Stock: " << getStock() << '\n';
    os << "        -> Flavour : " << flavor << " | Puffs : " << puffs << '\n';
}

void Vape::serialize(std::ostream &os) const {
    os << getType() << '\n';
    Product :: serialize(os);
    os << puffs<<'\n';
    os << flavor<<'\n';
}
void Vape::deserialize(std::istream &is) {
    Product :: deserialize(is);
    is >>puffs;
    is.ignore();
    getline(is,flavor);
}
void Vape::currentInput(std::istream &is) {
    Product :: currentInput(is);
    cout<< "Flavor : ";
    getline(is,flavor);
    cout<< "Puffs : ";
    is >> puffs;
    is.ignore();
}
