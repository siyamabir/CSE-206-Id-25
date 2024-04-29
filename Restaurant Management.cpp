#include<bits/stdc++.h>
using namespace std;

class MenuItem
{
private:
    string name;
    double price;
    string category;

public:
    MenuItem(string name, double price, string category) : name(name), price(price), category(category) {}

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    string getCategory() const
    {
        return category;
    }
};

class Order
{
private:
    vector<MenuItem> items;
    int tableNumber;
    double total;

public:
    Order(int tableNumber) : tableNumber(tableNumber), total(0) {}

    void addItem(MenuItem item)
    {
        items.push_back(item);
        total += item.getPrice();
    }

    void display() const
    {
        cout << "Table Number: " << tableNumber << "\n\n";
        cout << "Items:" << "\n";
        int i=1;
        for (const auto& item : items)
        {
            cout << i << " : " << item.getName() << " (" << item.getCategory() << "): " << item.getPrice() << "tk" << endl;
            i++;
        }
        cout << "\n" << "Total: " << fixed << setprecision(2) << total <<"tk"<< endl;
    }

    double getTotal() const
    {
        return total;
    }
};

class Restaurant
{
private:
    vector<MenuItem> menu;
    vector<Order> orders;
    vector<string> reservations;
    vector<string> staff;

public:
    void addMenuItem(string name, double price, string category)
    {
        MenuItem newItem(name, price, category);
        menu.push_back(newItem);
    }

    void displayMenu() const
    {
        cout << "Menu:" << endl;
        int i=1;
        for (const auto& item : menu)
        {
            cout << i << " : " << item.getName() << " (" << item.getCategory() << "): " << item.getPrice() << "tk" << endl;
            i++;
        }
        cout<<"\n";
    }

    void placeOrder(int tableNumber, const vector<string>& itemNames)
    {
        Order newOrder(tableNumber);
        for (const auto& name : itemNames)
        {
            for (const auto& item : menu)
            {
                if (item.getName() == name)
                {
                    newOrder.addItem(item);
                    break;
                }
            }
        }
        orders.push_back(newOrder);
    }

    void displayOrders() const
    {
        cout << "Orders:" << "\n";
        for (const auto& order : orders)
        {
            order.display();
            cout << endl;
        }
    }

    void addReservation(string name)
    {
        reservations.push_back(name);
        cout << "Reservation for " << name << " added successfully." << "\n\n";
    }

    void displayReservations() const
    {
        cout << "Reservations:" << endl;
        int i=1;
        for (const auto& reservation : reservations)
        {
            cout << i << " : " << reservation << endl;
            i++;
        }
        cout<<"\n";
    }

    void addStaff(string name)
    {
        staff.push_back(name);
        cout << "Staff member " << name << " added successfully." << "\n\n";
    }

    void displayStaff() const
    {
        cout << "Staff Members:" << endl;
        int i=1;
        for (const auto& member : staff)
        {
            cout << i << " : " << member << endl;
            i++;
        }
        cout<<"\n";
    }

    void generateBill(int tableNumber)
    {
        double totalBill = 0;
        cout << "Bill for Table " << tableNumber << ":" << endl;
        for (const auto& order : orders)
        {
            if (order.getTotal() > 0 )
            {
                totalBill += order.getTotal();
                order.display();
            }
        }
        cout << "\n" << "Total Bill: " << fixed << setprecision(2) << totalBill << "tk" << endl;
    }
};

int main()
{
    Restaurant res;

    res.addMenuItem("Burger", 100, "Main");
    res.addMenuItem("Pidza", 499, "Main");
    res.addMenuItem("Shup", 99, "Starter");

    res.displayMenu();

    vector<string>order1{"Pidza", "Burger"};
    res.placeOrder(1, order1);

    res.displayOrders();

    res.addStaff("Siyam");

    res.displayStaff();

    res.addReservation("Abir");

    res.displayReservations();

    res.generateBill(1);

    return 0;
}
