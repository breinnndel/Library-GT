#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Item {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    Item(int id, const string& name, int quantity, double price)
        : id(id), name(name), quantity(quantity), price(price) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    void setQuantity(int quantity) { this->quantity = quantity; }
    void setPrice(double price) { this->price = price; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity << ", Price: " << price << endl;
        }
    }
;

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(const Item& item) {
        items.push_back(item);
    }

    const vector<Item>& getItems() const {
        return items;
    }

    void updateItem(int id, int quantity, double price) {
        for (auto& item : items) {
            if (item.getId() == id) {
                item.setQuantity(quantity);
                item.setPrice(price);
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    void removeItem(int id) {
        items.erase(remove_if(items.begin(), items.end(),
                              [id](const Item& item) { return item.getId() == id; }),
                    items.end());
    }

    void displayItemsByCategory(const string& category) const {
        for (const auto& item : items) {
            if (item.getName() == category) {
                item.display();
            }
        }
    }

    void displayAllItems() const {
        for (const auto& item : items) {
            item.display();
        }
    }

    void searchItem(int id) const {
        for (const auto& item : items) {
            if (item.getId() == id) {
                item.display();
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    void sortItems(bool byQuantity, bool ascending) {
        sort(items.begin(), items.end(), [byQuantity, ascending](const Item& a, const Item& b) {
            if (byQuantity) {
                return ascending ? a.getQuantity() < b.getQuantity() : a.getQuantity() > b.getQuantity();
            } else {
                return ascending ? a.getPrice() < b.getPrice() : a.getPrice() > b.getPrice();
            }
        });
    }

    void displayLowStockItems(int threshold) const {
        for (const auto& item : items) {
            if (item.getQuantity() < threshold) {
                item.display();
            }
        }
    }
};

int main() {
    Inventory inventory;
    int choice, id = 0, quantity, threshold;
    double price;
    string name;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1 - Add item\n";
        cout << "2 - Update item\n";
        cout << "3 - Remove item\n";
        cout << "4 - Display all items\n";
        cout << "5 - Search item\n";
        cout << "6 - Sort items\n";
        cout << "7 - Display low stock items\n";
        cout << "8 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                id++; // Auto increment ID
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter item quantity: ";
                cin >> quantity;
                cout << "Enter item price: ";
                cin >> price;
                inventory.addItem(Item(id, name, quantity, price));
                cout << "Item added successfully!" << endl;
                break;
            case 2:
                cout << "Enter item ID to update: ";
                cin >> id;
                {
                    bool found = false;
                    for (const auto& item : inventory.getItems()) {
                        if (item.getId() == id) {
                            found = true;
                            int updateChoice;
                            cout << "Update:\n";
                            cout << "1 - Quantity\n";
                            cout << "2 - Price\n";
                            cout << "Enter your choice: ";
                            cin >> updateChoice;
                            if (updateChoice == 1) {
                                int oldQuantity = item.getQuantity();
                                cout << "Enter new quantity: ";
                                cin >> quantity;
                                inventory.updateItem(id, quantity, item.getPrice());
                                cout << "Quantity of Item " << item.getName() << " is updated from " << oldQuantity << " to " << quantity << endl;
                            } else if (updateChoice == 2) {
                                double oldPrice = item.getPrice();
                                cout << "Enter new price: ";
                                cin >> price;
                                inventory.updateItem(id, item.getQuantity(), price);
                                cout << "Price of Item " << item.getName() << " is updated from " << oldPrice << " to " << price << endl;
                            } else {
                                cout << "Invalid choice." << endl;
                            }
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Item not found!" << endl;
                    }
                }
                break;
            case 3:
                cout << "Enter item ID to remove: ";
                {
                    bool found = false;
                    for (const auto& item : inventory.getItems()) {
                        if (item.getId() == id) {
                            found = true;
                            cout << "Item " << item.getName() << " has been removed from the inventory." << endl;
                            inventory.removeItem(id);
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Item not found!" << endl;
                    }
                }
                }
                break;
            case 4:
                inventory.displayAllItems();
                break;
            case 5:
                cout << "Enter item ID to search: ";
                cin >> id;
                inventory.searchItem(id);
                break;
            case 6:
                int sortChoice;
                cout << "Sort by:\n";
                cout << "1 - Quantity\n";
                cout << "2 - Price\n";
                cout << "Enter your choice: ";
                cin >> sortChoice;
                cout << "Sort order:\n";
                cout << "1 - Ascending\n";
                cout << "2 - Descending\n";
                cout << "Enter your choice: ";
                cin >> choice;
                inventory.sortItems(sortChoice == 1, choice == 1);
                break;
            case 7:
                cout << "Enter low stock threshold: ";
                cin >> threshold;
                inventory.displayLowStockItems(threshold);
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}