#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent a food item
struct FoodItem {
    int id;
    string name;
    double price;
};

// Structure to represent an order
struct Order {
    int orderId;
    vector<int> foodIds;
    string status;
    double total;
};

// Menu Module
class Menu {
private:
    vector<FoodItem> foodItems;
public:
    void addFoodItem(int id, string name, double price) {
        foodItems.push_back({id, name, price});
    }

    void displayMenu() {
        cout << "\nMenu:\n";
        for (const auto& item : foodItems) {
            cout << "ID: " << item.id << " | Name: " << item.name << " | Price: $" << item.price << endl;
        }
    }

    FoodItem getFoodItemById(int id) {
        for (const auto& item : foodItems) {
            if (item.id == id) return item;
        }
        throw invalid_argument("Invalid food ID");
    }
};

// Order Module
class OrderManager {
private:
    vector<Order> orders;
    int orderCounter = 1;
public:
    int placeOrder(const vector<int>& foodIds, Menu& menu) {
        double total = 0;
        for (int id : foodIds) {
            total += menu.getFoodItemById(id).price;
        }

        Order newOrder = {orderCounter++, foodIds, "Pending", total};
        orders.push_back(newOrder);
        return newOrder.orderId;
    }

    void updateOrderStatus(int orderId, const string& newStatus) {
        for (auto& order : orders) {
            if (order.orderId == orderId) {
                order.status = newStatus;
                return;
            }
        }
        cout << "Invalid order ID." << endl;
    }

    void displayOrder(int orderId) {
        for (const auto& order : orders) {
            if (order.orderId == orderId) {
                cout << "\nOrder ID: " << order.orderId << "\nStatus: " << order.status << "\nTotal: $" << order.total << endl;
                return;
            }
        }
        cout << "Order not found." << endl;
    }
};

int main() {
    Menu menu;
    OrderManager orderManager;

    // Adding some items to the menu
    menu.addFoodItem(1, "Burger", 5.99);
    menu.addFoodItem(2, "Pizza", 8.99);
    menu.addFoodItem(3, "Pasta", 7.49);

    int choice;
    do {
        cout << "\nWelcome to Food Delivery System:\n";
        cout << "1. View Menu\n2. Place Order\n3. Track Order\n4. Update Order Status\n5. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menu.displayMenu();
            break;
        case 2: {
            menu.displayMenu();
            vector<int> foodIds;
            int foodId;
            cout << "\nEnter food IDs to order (enter -1 to stop): ";
            while (cin >> foodId && foodId != -1) {
                foodIds.push_back(foodId);
            }

            try {
                int orderId = orderManager.placeOrder(foodIds, menu);
                cout << "\nOrder placed successfully! Your Order ID is: " << orderId << endl;
            } catch (const invalid_argument& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            int orderId;
            cout << "\nEnter Order ID to track: ";
            cin >> orderId;
            orderManager.displayOrder(orderId);
            break;
        }
        case 4: {
            int orderId;
            string newStatus;
            cout << "\nEnter Order ID to update: ";
            cin >> orderId;
            cout << "Enter new status: ";
            cin >> newStatus;
            orderManager.updateOrderStatus(orderId, newStatus);
            break;
        }
        case 5:
            cout << "\nThank you for using the Food Delivery System!\n";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
