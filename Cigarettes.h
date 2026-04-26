#ifndef CIGARETTES_H
#define CIGARETTES_H
#include "Product.h"

class Cigarettes : public Product {
private:
  double tarMg;
  double nicotineMg;
public:
  Cigarettes();
  Cigarettes(std::string name,double price,int stock,double tarMg, double nicotineMg);
  Cigarettes(const Cigarettes &cs);
  Cigarettes &operator=(const Cigarettes &cs);
  ~Cigarettes();
  std::string getType() const override {return "Cigarettes";}
  void currentOutput(std::ostream& os) const override;
  void currentInput(std::istream& is) override;
  void serialize(std::ostream &os) const override;
  void deserialize(std::istream &is) override;
};


#endif
