#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
private:
    int id;
    string name;
    int quantity;
    double price;
public:
    static int nextID;
    Item(string n, int q, double p) {
        id = nextID++;
        name = n;
        quantity = q;
        price = p;
    }
    int getID() { return id; }
    string getName() { return name; }
    int getQuantity() { return quantity; }
    double getPrice() { return price; }
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }
    void display() {
        cout << id << "\t" << name << "\t" << quantity << "\t" << price << endl;
    }
};

int Item::nextID = 1;
vector<Item*> inventory;

void addItem() {
    string name; int quantity; double price;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Quantity: "; cin >> quantity;
    cout << "Enter Price: "; cin >> price;
    inventory.push_back(new Item(name, quantity, price));
    cout << "Item added successfully!" << endl;
}

void updateItem() {
    int id, newValue; char choice;
    cout << "Enter Product ID: "; cin >> id;
    for (auto &item : inventory) {
        if (item->getID() == id) {
            cout << "Update Quantity (Q) or Price (P)?: "; cin >> choice;
            if (choice == 'Q' || choice == 'q') {
                cout << "Enter new quantity: "; cin >> newValue;
                item->setQuantity(newValue);
            } else if (choice == 'P' || choice == 'p') {
                double newPrice;
                cout << "Enter new price: "; cin >> newPrice;
                item->setPrice(newPrice);
            }
            cout << "Item updated successfully!" << endl;
            return;
        }
    }
    cout << "Item not found!" << endl;
}

void removeItem() {
    int id;
    cout << "Enter Product ID: "; cin >> id;
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getID() == id) {
            delete *it;
            inventory.erase(it);
            cout << "Item removed successfully!" << endl;
            return;
        }
    }
    cout << "Item not found!" << endl;
}

void searchItem() {
    int id;
    cout << "Enter Product ID: "; cin >> id;
    for (const auto &item : inventory) {
        if (item->getID() == id) {
            item->display();
            return;
        }
    }
    cout << "Item not found!" << endl;
}

void displayAllItems() {
    cout << "ID\tName\tQuantity\tPrice" << endl;
    for (const auto &item : inventory) {
        item->display();
    }
}

void displayLowStock() {
    cout << "Low Stock Items (Quantity <= 5):" << endl;
    for (const auto &item : inventory) {
        if (item->getQuantity() <= 5) {
            item->display();
        }
    }
}

void cleanup() {
    for (auto &item : inventory) {
        delete item;
    }
    inventory.clear();
}

void menu() {
    int choice;
    do {
        cout << "\nMenu\n1 - Add Item\n2 - Update Item\n3 - Remove Item\n4 - Display All Items\n5 - Search Item\n6 - Display Low Stock Items\n7 - Exit" << endl;
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
            case 1: addItem(); break;
            case 2: updateItem(); break;
            case 3: removeItem(); break;
            case 4: displayAllItems(); break;
            case 5: searchItem(); break;
            case 6: displayLowStock(); break;
            case 7: cout << "Exiting program..." << endl; cleanup(); break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
