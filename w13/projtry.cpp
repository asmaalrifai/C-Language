#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

#define FILE_NAME "RestaurantBill.bin"
#define INVOICE_COUNTER_FILE "InvoiceCounter.bin"

class Item
{
public:
    std::string name;
    float price;
    int quantity;

    Item(std::string itemName, float itemPrice, int itemQuantity)
        : name(std::move(itemName)), price(itemPrice), quantity(itemQuantity) {}

    float calculateTotal() const
    {
        return quantity * price;
    }
};

class Customer
{
public:
    std::string name;
    std::string phone;

    Customer(std::string customerName, std::string customerPhone)
        : name(std::move(customerName)), phone(std::move(customerPhone)) {}
};

class Order
{
private:
    static int invoiceCounter;

public:
    int invoiceNumber;
    Customer customerInfo;
    std::string date;
    std::vector<Item> items;

    Order(const Customer &customer)
        : invoiceNumber(++invoiceCounter), customerInfo(customer), date(__DATE__) {}

    void addItem(const Item &item)
    {
        items.push_back(item);
    }

    void generateBill() const
    {
        float total = 0;

        generateBillHeader();

        for (const auto &item : items)
        {
            generateBillBody(item);
            total += item.calculateTotal();
        }

        generateBillFooter(total);
    }

    void saveToFile() const
    {
        std::ofstream outFile(FILE_NAME, std::ios::binary | std::ios::app);
        if (outFile.is_open())
        {
            outFile.write(reinterpret_cast<const char *>(this), sizeof(Order));
            std::cout << "Successfully saved" << std::endl;
            outFile.close();
        }
        else
        {
            std::cerr << "Error opening file " << FILE_NAME << " for writing" << std::endl;
        }
    }

    static void loadAndUpdateInvoiceCounter()
    {
        std::ifstream counterFile(INVOICE_COUNTER_FILE, std::ios::binary);
        if (counterFile.is_open())
        {
            counterFile.read(reinterpret_cast<char *>(&invoiceCounter), sizeof(int));
            counterFile.close();
        }

        // Update the counter for the next use
        std::ofstream updateCounterFile(INVOICE_COUNTER_FILE, std::ios::binary);
        if (updateCounterFile.is_open())
        {
            invoiceCounter++;
            updateCounterFile.write(reinterpret_cast<const char *>(&invoiceCounter), sizeof(int));
            updateCounterFile.close();
        }
        else
        {
            std::cerr << "Error opening file " << INVOICE_COUNTER_FILE << " for writing" << std::endl;
        }
    }

private:
    void generateBillHeader() const
    {
        std::cout << "\n\n";
        std::cout << "\t\tASOOM Restaurant";
        std::cout << "\n\t\t----------------";
        std::cout << "\nInvoice Number: " << invoiceNumber;
        std::cout << "\nDate: " << date;
        std::cout << "\nInvoice To: " << customerInfo.name;
        std::cout << "\nPhone: " << customerInfo.phone;
        std::cout << "\n--------------------------------------\n";
        std::cout << std::setw(15) << "Items" << std::setw(20) << "Price per one" << std::setw(15) << "Qty" << std::setw(20) << "Total";
        std::cout << "\n--------------------------------------\n";
    }

    void generateBillBody(const Item &item) const
    {
        std::cout << std::setw(15) << item.name << std::setw(20) << std::fixed << std::setprecision(2) << item.price;
        std::cout << std::setw(15) << item.quantity << std::setw(20) << item.calculateTotal() << std::endl;
    }

    void generateBillFooter(float total) const
    {
        std::cout << "\n";
        float discount = 0.1 * total;
        float netTotal = total - discount;
        float TAX = 0.09 * netTotal;
        float grandTotal = netTotal + TAX;
        std::cout << "\n--------------------------------------\n";
        std::cout << std::setw(50) << "Sub Total" << std::setw(20) << netTotal;
        std::cout << "\n"
                  << std::setw(50) << "Discount @10%" << std::setw(20) << discount;
        std::cout << "\n"
                  << std::setw(20) << " " << std::setw(50) << "-------";
        std::cout << "\n"
                  << std::setw(50) << "Net Total" << std::setw(20) << netTotal;
        std::cout << "\n"
                  << std::setw(50) << "TAX @9%" << std::setw(20) << TAX;
        std::cout << "\n--------------------------------------\n";
        std::cout << "\n"
                  << std::setw(50) << "Grand Total" << std::setw(20) << grandTotal;
        std::cout << "\n--------------------------------------\n";
    }
};

int Order::invoiceCounter = 0;

// Function to flush input buffer
void flushInputBuffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to generate an item menu
Item generateItemMenu(const std::string &itemType, const std::string &itemName, float itemPrice)
{
    std::cout << "Enter quantity for " << itemName << " (" << itemType << ") : ";
    int itemQuantity;
    std::cin >> itemQuantity;
    flushInputBuffer(); // Flush input buffer

    return Item(itemName, itemPrice, itemQuantity);
}

// Function to add a new item to the menu
void addItemToMenu(std::vector<Item> &menu, const std::string &itemType)
{
    std::string itemName;
    float itemPrice;

    std::cout << "Enter item name for " << itemType << ": ";
    std::getline(std::cin, itemName);

    std::cout << "Enter item price for " << itemType << ": ";
    std::cin >> itemPrice;

    menu.push_back(Item(itemName, itemPrice, 0));
    std::cout << "Item added successfully to the " << itemType << " menu!" << std::endl;
    flushInputBuffer(); // Flush input buffer
}

// Function to delete an item from the menu
void deleteItemFromMenu(std::vector<Item> &menu)
{
    std::string itemName;
    std::cout << "Enter item name to delete: ";
    std::getline(std::cin, itemName);

    auto it = std::remove_if(menu.begin(), menu.end(), [&itemName](const Item &item)
                             { return item.name == itemName; });

    if (it != menu.end())
    {
        menu.erase(it, menu.end());
        std::cout << "Item deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Item not found in the menu." << std::endl;
    }
}

// Function to update an item in the menu
void updateItemInMenu(std::vector<Item> &menu)
{
    std::string itemName;
    std::cout << "Enter item name to update: ";
    std::getline(std::cin, itemName);

    auto it = std::find_if(menu.begin(), menu.end(), [&itemName](const Item &item)
                           { return item.name == itemName; });

    if (it != menu.end())
    {
        int choice;
        std::cout << "Select what you want to update:\n";
        std::cout << "1. Update name\n";
        std::cout << "2. Update price\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string newName;
            std::cout << "Enter new name: ";
            flushInputBuffer();
            std::getline(std::cin, newName);
            it->name = newName;
            std::cout << "Item name updated successfully!" << std::endl;
            break;
        }
        case 2:
        {
            float newPrice;
            std::cout << "Enter new price: ";
            std::cin >> newPrice;
            it->price = newPrice;
            std::cout << "Item price updated successfully!" << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    }
    else
    {
        std::cout << "Item not found in the menu." << std::endl;
    }
}

// Function to show all items in the menu
void showAllMenu(const std::vector<Item> &mainDishes, const std::vector<Item> &desserts, const std::vector<Item> &drinks)
{
    std::cout << "\nMain Dishes:\n";
    for (const auto &item : mainDishes)
    {
        std::cout << item.name << "\t\t" << item.price << std::endl;
    }

    std::cout << "\nDesserts:\n";
    for (const auto &item : desserts)
    {
        std::cout << item.name << "\t\t" << item.price << std::endl;
    }

    std::cout << "\nDrinks:\n";
    for (const auto &item : drinks)
    {
        std::cout << item.name << "\t\t" << item.price << std::endl;
    }
}

// Function to search for an invoice by different criteria
void searchInvoice(const std::vector<Order> &orders)
{
    int choice;
    std::cout << "\nSelect criteria to search for invoice:\n";
    std::cout << "1. Invoice ID\n";
    std::cout << "2. Customer Name\n";
    std::cout << "3. Customer Phone Number\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int invoiceId;
        std::cout << "Enter Invoice ID: ";
        std::cin >> invoiceId;

        auto it = std::find_if(orders.begin(), orders.end(), [&invoiceId](const Order &order)
                               { return order.invoiceNumber == invoiceId; });

        if (it != orders.end())
        {
            it->generateBill();
        }
        else
        {
            std::cout << "Invoice not found." << std::endl;
        }
        break;
    }
    case 2:
    {
        flushInputBuffer();
        std::string customerName;
        std::cout << "Enter Customer Name: ";
        std::getline(std::cin, customerName);

        auto it = std::find_if(orders.begin(), orders.end(), [&customerName](const Order &order)
                               { return order.customerInfo.name == customerName; });

        if (it != orders.end())
        {
            it->generateBill();
        }
        else
        {
            std::cout << "Invoice not found." << std::endl;
        }
        break;
    }
    case 3:
    {
        flushInputBuffer();
        std::string customerPhone;
        std::cout << "Enter Customer Phone Number: ";
        std::getline(std::cin, customerPhone);

        auto it = std::find_if(orders.begin(), orders.end(), [&customerPhone](const Order &order)
                               { return order.customerInfo.phone == customerPhone; });

        if (it != orders.end())
        {
            it->generateBill();
        }
        else
        {
            std::cout << "Invoice not found." << std::endl;
        }
        break;
    }
    default:
        std::cout << "Invalid choice." << std::endl;
        break;
    }
}

// Function to modify an existing invoice
void modifyInvoice(std::vector<Order> &orders)
{
    int invoiceId;
    std::cout << "Enter Invoice ID to modify: ";
    std::cin >> invoiceId;

    auto it = std::find_if(orders.begin(), orders.end(), [&invoiceId](const Order &order)
                           { return order.invoiceNumber == invoiceId; });

    if (it != orders.end())
    {
        char modifyFlag = 'y';
        do
        {
            it->generateBill(); // Display current invoice
            std::cout << "Select modification option:\n";
            std::cout << "1. Update quantity of items\n";
            std::cout << "2. Add items\n";
            std::cout << "3. Remove items\n";
            std::cout << "4. Update customer information\n";
            std::cout << "Enter your choice: ";
            int choice;
            std::cin >> choice;

            switch (choice)
            {
            case 1:
            { // Update quantity of items
                std::string itemName;
                std::cout << "Enter item name to update quantity: ";
                flushInputBuffer();
                std::getline(std::cin, itemName);

                auto itemIt = std::find_if(it->items.begin(), it->items.end(), [&itemName](const Item &item)
                                           { return item.name == itemName; });

                if (itemIt != it->items.end())
                {
                    std::cout << "Enter new quantity: ";
                    std::cin >> itemIt->quantity;
                }
                else
                {
                    std::cout << "Item not found in the invoice." << std::endl;
                }
                break;
            }
            case 2:
            { // Add items
                it->addItem(generateItemMenu());
                break;
            }
            case 3:
            { // Remove items
                std::string itemName;
                std::cout << "Enter item name to remove: ";
                flushInputBuffer();
                std::getline(std::cin, itemName);

                it->items.erase(
                    std::remove_if(it->items.begin(), it->items.end(), [&itemName](const Item &item)
                                   { return item.name == itemName; }),
                    it->items.end());
                std::cout << "Item removed successfully!" << std::endl;
                break;
            }
            case 4:
            { // Update customer information
                std::string newName, newPhone;
                std::cout << "Enter new customer name: ";
                flushInputBuffer();
                std::getline(std::cin, newName);
                std::cout << "Enter new customer phone: ";
                std::getline(std::cin, newPhone);
                it->customerInfo.name = newName;
                it->customerInfo.phone = newPhone;
                std::cout << "Customer information updated successfully!" << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
            }

            std::cout << "Do you want to perform another modification? [y/n]: ";
            std::cin >> modifyFlag;
            flushInputBuffer();
        } while (modifyFlag == 'y');
    }
    else
    {
        std::cout << "Invoice not found." << std::endl;
    }
}

// Function to delete an invoice
void deleteInvoice(std::vector<Order> &orders)
{
    int choice;
    std::cout << "\nSelect criteria to delete an invoice:\n";
    std::cout << "1. Invoice ID\n";
    std::cout << "2. Customer Name\n";
    std::cout << "3. Customer Phone Number\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int invoiceId;
        std::cout << "Enter Invoice ID to delete: ";
        std::cin >> invoiceId;

        auto it = std::remove_if(orders.begin(), orders.end(), [&invoiceId](const Order &order)
                                 { return order.invoiceNumber == invoiceId; });

        if (it != orders.end())
        {
            orders.erase(it, orders.end());
            std::cout << "Invoice deleted successfully!" << std::endl;
        }
        else
        {
            std::cout << "Invoice not found." << std::endl;
        }
        break;
    }
    case 2:
    {
        flushInputBuffer();
        std::string customerName;
        std::cout << "Enter Customer Name to delete: ";
        std::getline(std::cin, customerName);

        auto it = std::remove_if(orders.begin(), orders.end(), [&customerName](const Order &order)
                                 { return order.customerInfo.name == customerName; });

        if (it != orders.end())
        {
            orders.erase(it, orders.end());
            std::cout << "Invoice deleted successfully!" << std::endl;
        }
        else
        {
            std::cout << "Invoice not found." << std::endl;
        }
        break;
    }
    case 3:
    {
        flushInputBuffer();
        std::string customerPhone;
        std::cout << "Enter Customer Phone Number to delete: ";
        std::getline(std::cin, customerPhone);

        auto it = std::remove_if(orders.begin(), orders.end(), [&customerPhone](const Order &order)
                                 { return order.customerInfo.phone == customerPhone; });

        if (it != orders.end())
        {
            orders.erase(it, orders.end());
            std::cout << "Invoice deleted successfully!" << std.endl;
        }
        else
        {
            std::cout << "Invoice not found." << std::endl;
        }
        break;
    }
    default:
        std::cout << "Invalid choice." << std::endl;
        break;
    }
}

// Function to calculate total revenue
float calculateTotalRevenue(const std::vector<Order> &orders)
{
    float totalRevenue = 0;
    for (const auto &order : orders)
    {
        for (const auto &item : order.items)
        {
            totalRevenue += item.calculateTotal();
        }
    }
    return totalRevenue;
}

int main()
{
    Order::loadAndUpdateInvoiceCounter();
    std::vector<Order> orders;
    std::vector<Item> mainDishes, desserts, drinks;

    // Adding some initial items to the menu
    mainDishes.push_back(Item("Burger", 10.99, 0));
    mainDishes.push_back(Item("Pizza", 15.99, 0));
    desserts.push_back(Item("Ice Cream", 5.99, 0));
    drinks.push_back(Item("Coke", 1.99, 0));

    char contFlag = 'y';

    while (contFlag == 'y')
    {
        std::cout << "\t==========ASOOM Restaurant==========";
        std::cout << "\n\nPlease select your preferred operation:\t";
        std::cout << "\n\n1. Generate Invoice";
        std::cout << "\n2. Menu";
        std::cout << "\n3. Search Invoice";
        std::cout << "\n4. Modify Invoice";
        std::cout << "\n5. Delete Invoice";
        std::cout << "\n6. Show all Invoices";
        std::cout << "\n7. Calculate Total Revenue";
        std::cout << "\n8. Exit";

        int opt;
        std::cout << "\n\nYour choice: ";
        std::cin >> opt;

        switch (opt)
        {
        case 1:
        { // Generate Invoice
            std::string customerName, customerPhone;
            std::cout << "Enter customer name: ";
            flushInputBuffer();
            std::getline(std::cin, customerName);
            std::cout << "Enter customer phone: ";
            std::getline(std::cin, customerPhone);

            Customer customer(customerName, customerPhone);
            Order currentOrder(customer);

            char addAnotherItem = 'y';
            do
            {
                std::cout << "\t==========ASOOM Restaurant Menu==========";
                std::cout << "\n\nMain Dishes:\n";
                for (const auto &item : mainDishes)
                {
                    std::cout << item.name << "\t\t" << item.price << std::endl;
                }

                std::cout << "\nDesserts:\n";
                for (const auto &item : desserts)
                {
                    std::cout << item.name << "\t\t" << item.price << std::endl;
                }

                std::cout << "\nDrinks:\n";
                for (const auto &item : drinks)
                {
                    std::cout << item.name << "\t\t" << item.price << std::endl;
                }

                std::string itemType, itemName;
                float itemPrice;
                std::cout << "Enter the name of the item you want to order: ";
                flushInputBuffer();
                std::getline(std::cin, itemName);

                auto it = std::find_if(mainDishes.begin(), mainDishes.end(), [&itemName](const Item &item)
                                       { return item.name == itemName; });

                if (it != mainDishes.end())
                {
                    itemType = "Main Dish";
                    itemPrice = it->price;
                }
                else
                {
                    auto it = std::find_if(desserts.begin(), desserts.end(), [&itemName](const Item &item)
                                           { return item.name == itemName; });

                    if (it != desserts.end())
                    {
                        itemType = "Dessert";
                        itemPrice = it->price;
                    }
                    else
                    {
                        auto it = std::find_if(drinks.begin(), drinks.end(), [&itemName](const Item &item)
                                               { return item.name == itemName; });

                        if (it != drinks.end())
                        {
                            itemType = "Drink";
                            itemPrice = it->price;
                        }
                        else
                        {
                            std::cout << "Item not found in the menu. Please choose a valid item." << std::endl;
                            continue;
                        }
                    }
                }

                currentOrder.addItem(generateItemMenu(itemType, itemName, itemPrice));
                std::cout << "Do you want to order anything else? [y/n]: ";
                std::cin >> addAnotherItem;
                flushInputBuffer();
            } while (addAnotherItem == 'y');

            currentOrder.generateBill();
            currentOrder.saveToFile();
            orders.push_back(currentOrder);
            break;
        }
        case 2:
        { // Menu
            int menuChoice;
            std::cout << "\n1. Add item";
            std::cout << "\n2. Delete item";
            std::cout << "\n3. Update item";
            std::cout << "\n4. Show all menu";
            std::cout << "\nEnter your choice: ";
            std::cin >> menuChoice;

            switch (menuChoice)
            {
            case 1: // Add item
                int itemTypeChoice;
                std::cout << "\nSelect item type to add:\n";
                std::cout << "1. Main Dish\n";
                std::cout << "2. Dessert\n";
                std::cout << "3. Drink\n";
                std::cout << "Enter your choice: ";
                std::cin >> itemTypeChoice;
                switch (itemTypeChoice)
                {
                case 1:
                    addItemToMenu(mainDishes, "Main Dish");
                    break;
                case 2:
                    addItemToMenu(desserts, "Dessert");
                    break;
                case 3:
                    addItemToMenu(drinks, "Drink");
                    break;
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
                }
                break;
            case 2: // Delete item
                int itemTypeChoice;
                std::cout << "\nSelect item type to delete:\n";
                std::cout << "1. Main Dish\n";
                std::cout << "2. Dessert\n";
                std::cout << "3. Drink\n";
                std::cout << "Enter your choice: ";
                std::cin >> itemTypeChoice;

                switch (itemTypeChoice)
                {
                case 1:
                    deleteItemFromMenu(mainDishes);
                    break;
                case 2:
                    deleteItemFromMenu(desserts);
                    break;
                case 3:
                    deleteItemFromMenu(drinks);
                    break;
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
                }
                break;
            case 3: // Update item
                int itemTypeChoice;
                std::cout << "\nSelect item type to update:\n";
                std::cout << "1. Main Dish\n";
                std::cout << "2. Dessert\n";
                std::cout << "3. Drink\n";
                std::cout << "Enter your choice: ";
                std::cin >> itemTypeChoice;

                switch (itemTypeChoice)
                {
                case 1:
                    updateItemInMenu(mainDishes);
                    break;
                case 2:
                    updateItemInMenu(desserts);
                    break;
                case 3:
                    updateItemInMenu(drinks);
                    break;
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
                }
                break;
            case 4: // Show all menu
                showAllMenu(mainDishes, desserts, drinks);
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
            }
            break;
        }
        case 3: // Search Invoice
            searchInvoice(orders);
            break;
        case 4: // Modify Invoice
            modifyInvoice(orders);
            break;
        case 5: // Delete Invoice
            deleteInvoice(orders);
            break;
        case 6: // Show all Invoices
            for (const auto &order : orders)
            {
                order.generateBill();
            }
            break;
        case 7: // Calculate Total Revenue
            std::cout << "Total Revenue: $" << calculateTotalRevenue(orders) << std::endl;
            break;
        case 8: // Exit
            contFlag = 'n';
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
            break;
        }

        std::cout << "\nDo you want to perform another operation? [y/n]: ";
        std::cin >> contFlag;
    }

    return 0;
}
