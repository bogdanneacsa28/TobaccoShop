#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

class Customer {
  private:
  std::string name;
  int loyaltyPoints;
  public:
  Customer();
  Customer(std::string name, int loyaltyPoints);
  Customer(const Customer &customer);
  Customer &operator=(const Customer &customer);
  ~Customer();

  friend std::ostream &operator<<(std::ostream &os, const Customer &customer);
  friend std::istream &operator>>(std::istream &is, Customer &customer);

  std::string getName() const{return name;}
  void addLoyaltyPoints(int p){loyaltyPoints += p;}
};

#endif