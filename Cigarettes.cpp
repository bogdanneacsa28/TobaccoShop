#include "Cigarettes.h"

using namespace std;

Cigarettes::Cigarettes():Product(){
    this->tarMg = 0;
    this->nicotineMg = 0;
}

Cigarettes::Cigarettes(std::string name, double price, int stock, double tarMg, double nicotineMg):Product(name, price, stock) {
    this->tarMg = tarMg;
    this->nicotineMg = nicotineMg;
}

Cigarettes::Cigarettes(const Cigarettes &cs) :Product(cs) {
    this->tarMg = cs.tarMg;
    this->nicotineMg = cs.nicotineMg;
}
Cigarettes &Cigarettes::operator=(const Cigarettes &cs) {
    if (this != &cs) {
        Product ::operator=(cs);
        this->tarMg = cs.tarMg;
        this->nicotineMg = cs.nicotineMg;
    }
    return *this;
}
Cigarettes::~Cigarettes(){}

void Cigarettes::currentInput(std::istream &is) {
    Product::currentInput(is);
    cout << "Tar (mg): ";
    is >> tarMg;
    cout << "Nicotine (mg): ";
    is >> nicotineMg;
    is.ignore();
}

void Cigarettes::serialize(std::ostream &os) const {
    os << getType() <<"\n";
    Product ::serialize(os);
    os << tarMg << '\n';
    os << nicotineMg << '\n';
}
void Cigarettes::deserialize(std::istream &is) {
    Product ::deserialize(is);
    is >> tarMg >> nicotineMg;
    is.ignore();
}
void Cigarettes::currentOutput(std::ostream &os) const {
    os << "[CIGARETTES] " << getName() << " | Price: " << getPrice() << " RON | Stock: " << getStock() << '\n'
       << "        -> Tar: " << tarMg << "mg | Nicotine: " << nicotineMg << "mg\n";
}
