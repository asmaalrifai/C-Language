#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
public:
    int productID;
    string productName;
    double price;
    int quantity;
    string category;

    static int nextProductID;

    Product(string name, double price, int quantity, string category)
        : productName(name), price(price), quantity(quantity), category(category) {
        productID = nextProductID++;
    }

    static void resetProductID() {
        nextProductID = 1;
    }

    virtual void displayInfo() const {
        cout << "Product ID: " << productID << "\n"
             << "Name: " << productName << "\n"
             << "Price: $" << price << "\n"
             << "Quantity: " << quantity << "\n"
             << "Category: " << category << "\n";
    }

    virtual ~Product() {}
};

int Product::nextProductID = 1;

class Electronics : public Product {
public:
    string brand;

    Electronics(string name, double price, int quantity, string category, string brand)
        : Product(name, price, quantity, category), brand(brand) {}

    void displayInfo() const override {
        Product::displayInfo();
        cout << "Brand: " << brand << "\n";
    }
};

class Clothing : public Product {
public:
    string size;

    Clothing(string name, double price, int quantity, string category, string size)
        : Product(name, price, quantity, category), size(size) {}

    void displayInfo() const override {
        Product::displayInfo();
        cout << "Size: " << size << "\n";
    }
};

class User {
public:
    int userID;
    string username;
    string password;
    string email;

    static int nextUserID;

    User(string username, string password, string email)
        : username(username), password(password), email(email) {
        userID = nextUserID++;
    }

    static void resetUserID() {
        nextUserID = 1;
    }
};

int User::nextUserID = 1;

class ShoppingCart {
public:
    vector<Product*> products;

    void addToCart(Product* product) {
        products.push_back(product);
    }

    void removeFromCart(int productID) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if ((*it)->productID == productID) {
                products.erase(it);
                break;
            }
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product->price;
        }
        return total;
    }

    ~ShoppingCart() {
        for (auto& product : products) {
            delete product;
        }
    }
};

class Order {
public:
    int orderID;
    User user;
    vector<Product*> products;
    string orderDate;
    string status;

    static int nextOrderID;

    Order(const User& user, const vector<Product*>& products, string orderDate, string status = "Pending")
        : user(user), products(products), orderDate(orderDate), status(status) {
        orderID = nextOrderID++;
    }

    static void resetOrderID() {
        nextOrderID = 1;
    }

    ~Order() {
        for (auto& product : products) {
            delete product;
        }
    }
};

int Order::nextOrderID = 1;

class Payment {
public:
    int paymentID;
    Order order;
    string paymentDate;
    double amount;
    string paymentStatus;
    string paymentMethod;

    static int nextPaymentID;

    Payment(const Order& order, string paymentDate, double amount, string paymentMethod)
        : order(order), paymentDate(paymentDate), amount(amount), paymentMethod(paymentMethod) {
        paymentID = nextPaymentID++;
        paymentStatus = "Paid";
    }

    static void resetPaymentID() {
        nextPaymentID = 1;
    }
};

int Payment::nextPaymentID = 1;

class Category {
public:
    int categoryID;
    string categoryName;
    vector<Product*> products;

    static int nextCategoryID;

    Category(string categoryName)
        : categoryName(categoryName) {
        categoryID = nextCategoryID++;
    }

    static void resetCategoryID() {
        nextCategoryID = 1;
    }
};

int Category::nextCategoryID = 1;

class OnlineShoppingSystem {
private:
    vector<Product*> products;
    vector<User> users;
    vector<Order> orders;
    vector<Payment> payments;
    vector<Category> categories;
    ShoppingCart userCart;

public:
    OnlineShoppingSystem() {
        loadInitialData();
    }

    ~OnlineShoppingSystem() {
        saveData();
        clearData();
    }

    void loadInitialData() {
        loadProducts();
        loadUsers();
        loadOrders();
        loadPayments();
        loadCategories();
    }

    void loadProducts() {
        ifstream file("products.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open products file.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int productID;
            string productName;
            double price;
            int quantity;
            string category;
            string brand;
            string size;

            ss >> productID >> productName >> price >> quantity >> category;

            if (category == "Electronics") {
                ss >> brand;
                products.push_back(new Electronics(productName, price, quantity, category, brand));
            } else if (category == "Clothing") {
                ss >> size;
                products.push_back(new Clothing(productName, price, quantity, category, size));
            }
        }

        file.close();
    }

    void loadUsers() {
        ifstream file("users.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open users file.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int userID;
            string username;
            string password;
            string email;

            ss >> userID >> username >> password >> email;

            users.push_back(User(username, password, email));
        }

        file.close();
    }

    void loadOrders() {
        ifstream file("orders.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open orders file.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int orderID;
            int userID;
            string orderDate;
            string status;

            ss >> orderID >> userID >> orderDate >> status;

            // Find the user based on userID
            auto userIt = find_if(users.begin(), users.end(), [userID](const User& u) {
                return u.userID == userID;
            });

            if (userIt != users.end()) {
                User user = *userIt;
                vector<Product*> productsInOrder;

                int productID;
                while (ss >> productID) {
                    // Find the product based on productID
                    auto productIt = find_if(products.begin(), products.end(), [productID](const Product* p) {
                        return p->productID == productID;
                    });

                    if (productIt != products.end()) {
                        productsInOrder.push_back(*productIt);
                    }
                }

                orders.push_back(Order(user, productsInOrder, orderDate, status));
            }
        }

        file.close();
    }

    void loadPayments() {
        ifstream file("payments.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open payments file.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int paymentID;
            int orderID;
            string paymentDate;
            double amount;
            string paymentStatus;
            string paymentMethod;

            ss >> paymentID >> orderID >> paymentDate >> amount >> paymentStatus >> paymentMethod;

            // Find the order based on orderID
            auto orderIt = find_if(orders.begin(), orders.end(), [orderID](const Order& o) {
                return o.orderID == orderID;
            });

            if (orderIt != orders.end()) {
                Order order = *orderIt;
                payments.push_back(Payment(order, paymentDate, amount, paymentMethod));
            }
        }

        file.close();
    }

    void loadCategories() {
        ifstream file("categories.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open categories file.\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            int categoryID;
            string categoryName;

            ss >> categoryID >> categoryName;

            categories.push_back(Category(categoryName));
        }

        file.close();
    }

    void saveData() {
        saveProducts();
        saveUsers();
        saveOrders();
        savePayments();
        saveCategories();
    }

    void saveProducts() {
        ofstream file("products.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open products file for writing.\n";
            return;
        }

        for (const auto& product : products) {
            if (dynamic_cast<Electronics*>(product)) {
                const Electronics* electronicsProduct = dynamic_cast<Electronics*>(product);
                file << electronicsProduct->productID << " "
                     << electronicsProduct->productName << " "
                     << electronicsProduct->price << " "
                     << electronicsProduct->quantity << " "
                     << electronicsProduct->category << " "
                     << electronicsProduct->brand << "\n";
            } else if (dynamic_cast<Clothing*>(product)) {
                const Clothing* clothingProduct = dynamic_cast<Clothing*>(product);
                file << clothingProduct->productID << " "
                     << clothingProduct->productName << " "
                     << clothingProduct->price << " "
                     << clothingProduct->quantity << " "
                     << clothingProduct->category << " "
                     << clothingProduct->size << "\n";
            }
        }

        file.close();
    }

    void saveUsers() {
        ofstream file("users.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open users file for writing.\n";
            return;
        }

        for (const auto& user : users) {
            file << user.userID << " "
                 << user.username << " "
                 << user.password << " "
                 << user.email << "\n";
        }

        file.close();
    }

    void saveOrders() {
        ofstream file("orders.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open orders file for writing.\n";
            return;
        }

        for (const auto& order : orders) {
            file << order.orderID << " "
                 << order.user.userID << " "
                 << order.orderDate << " "
                 << order.status << " ";

            for (const auto& product : order.products) {
                file << product->productID << " ";
            }

            file << "\n";
        }

        file.close();
    }

    void savePayments() {
        ofstream file("payments.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open payments file for writing.\n";
            return;
        }

        for (const auto& payment : payments) {
            file << payment.paymentID << " "
                 << payment.order.orderID << " "
                 << payment.paymentDate << " "
                 << payment.amount << " "
                 << payment.paymentStatus << " "
                 << payment.paymentMethod << "\n";
        }

        file.close();
    }

    void saveCategories() {
        ofstream file("categories.txt");

        if (!file.is_open()) {
            cerr << "Error: Unable to open categories file for writing.\n";
            return;
        }

        for (const auto& category : categories) {
            file << category.categoryID << " "
                 << category.categoryName << "\n";
        }

        file.close();
    }

    void clearData() {
        clearProducts();
        clearUsers();
        clearOrders();
        clearPayments();
        clearCategories();
    }

    void clearProducts() {
        for (auto& product : products) {
            delete product;
        }

        products.clear();
        Product::resetProductID();
    }

    void clearUsers() {
        users.clear();
        User::resetUserID();
    }

    void clearOrders() {
        orders.clear();
        Order::resetOrderID();
    }

    void clearPayments() {
        payments.clear();
        Payment::resetPaymentID();
    }

    void clearCategories() {
        categories.clear();
        Category::resetCategoryID();
    }

    void browseProducts() {
        // Implement as per previous suggestions
    }

    void viewShoppingCart() {
        // Implement as per previous suggestions
    }

    void manageAccount() {
        // Implement as per previous suggestions
    }

    void placeOrder() {
        // Implement as per previous suggestions
    }

    void viewOrderHistory() {
        // Implement as per previous suggestions
    }

    void administrativeTasks() {
        // Implement as per previous suggestions
    }

    void displayMainMenu() {
        // Implement as per previous suggestions
    }

    void displayAdminMenu() {
        // Implement as per previous suggestions
    }

    void run() {
        // Implement as per previous suggestions
    }
};

int main() {
    OnlineShoppingSystem onlineShop;
    onlineShop.run();
    //system("pause");
    return 0;
}

