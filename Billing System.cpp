#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Item
{
private:
    string name;
    double price;
    int quantity;

public:
    Item(const string &name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    int getQuantity() const
    {
        return quantity;
    }

    double getTotal() const
    {
        return price * quantity;
    }

    void print() const
    {
        cout << left << setw(20) << name
             << setw(10) << price
             << setw(10) << quantity
             << setw(10) << getTotal()
             << endl;
    }
};
class Bill
{
private:
    vector<Item> items;

public:
    void addItem(const Item &item)
    {
        items.push_back(item);
    }

    void printBill() const
    {
        double total = 0.0;
        cout << left << setw(20) << "Item"
             << setw(10) << "Price"
             << setw(10) << "Quantity"
             << setw(10) << "Total"
             << endl;

        for (const auto &item : items)
        {
            item.print();
            total += item.getTotal();
        }

        cout << string(50, '-') << endl;
        cout << left << setw(40) << "Grand Total" << total << endl;
    }
};
class BillingSystem
{
private:
    Bill bill;

public:
    void addItem()
    {
        string name;
        double price;
        int quantity;

        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter item price: ";
        cin >> price;
        cout << "Enter item quantity: ";
        cin >> quantity;

        Item item(name, price, quantity);
        bill.addItem(item);
        cout << "Item added successfully!" << endl;
    }

    void printBill() const
    {
        bill.printBill();
    }
};
int main()
{
    BillingSystem system;
    int choice;

    do
    {
        cout << "1. Add Item" << endl;
        cout << "2. Print Bill" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addItem();
            break;
        case 2:
            system.printBill();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
