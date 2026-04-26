#include <iostream>
#include "Shop.h"
#include "Vape.h"
#include "Cigarettes.h"
#include "Snus.h"
#include "Exceptions.h"
using namespace std;
void displayMenu() {
 cout<<R"(
  _______ ____  ____          _____ _____ ____
 |__   __/ __ \|  _ \   /\   / ____/ ____/ __ \
    | | | |  | | |_) | /  \ | |   | |   | |  | |
    | | | |  | |  _ < / /\ \| |   | |   | |  | |
    | | | |__| | |_) / ____ \ |___| |___| |__| |
    |_|  \____/|____/_/    \_\_____\_____\____/

   _____ _    _  ____  _____
  / ____| |  | |/ __ \|  __ \
 | (___ | |__| | |  | | |__) |
  \___ \|  __  | |  | |  ___/
  ____) | |  | | |__| | |
 |_____/|_|  |_|\____/|_|

================================================)"<<"\n";
  cout << "\n=== TOBACCO SHOP MENU ===\n";
  cout << "1. Add a new Vape\n";
  cout << "2. Add new Cigarettes\n";
  cout << "3. Add new Snus\n";
  cout << "4. Display inventory report\n";
  cout << "5. Sell a product\n";
  cout << "6. Save inventory to file\n";
  cout << "7. Load inventory from file\n";
  cout << "0. Exit\n";
  cout << "Your choice: ";
}
int main() {
 Shop myShop;
 int choice;

 do {
  displayMenu();
  if (!(cin >> choice)) {
   cin.clear();
   cin.ignore(10000, '\n');
   continue;
  }
  cin.ignore();

  try {
   switch (choice) {
    case 1: {
     Vape* v = new Vape();
     cin >> *v;
     myShop.addProduct(v);
     break;
    }
    case 2: {
     Cigarettes* c = new Cigarettes();
     cin >> *c;
     myShop.addProduct(c);
     break;
    }
    case 3: {
     Snus* s = new Snus();
     cin >> *s;
     myShop.addProduct(s);
     break;
    }
    case 4:
     myShop.displayReport();
     break;
    case 5: {
     string name;
     int qty;
     cout << "Name of the product to sell: ";
     getline(cin, name);
     cout << "Quantity: ";
     cin >> qty;
     myShop.sellProduct(name, qty);
     break;
    }
    case 6:
     myShop.saveInventoryToFile("inventory.txt");
     cout << "Inventory saved successfully!\n";
     break;
    case 7:
     myShop.loadInventoryFromFile("inventory.txt");
     cout << "Inventory loaded successfully!\n";
     break;
    case 0:
     cout << "Exiting program...\n";
     break;
    default:
     cout << "Invalid option!\n";
   }
  } catch (const exception& e) {
   cout << "\n[EXCEPTION CAUGHT]: " << e.what() << "\n";
  }

 } while (choice != 0);

 return 0;
}