#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Account {
private:
    string username;
    string password;
    double balance;
    double loanAmount;

public:
    Account(const string& user, const string& pass) : username(user), password(pass), balance(0.0), loanAmount(0.0) {}

    // Getter methods
    string getUsername() const { return username; }
    double getBalance() const { return balance; }
    double getLoanAmount() const { return loanAmount; }

    // Methods for account operations
    bool checkPassword(const string& pass) const { return password == pass; }
    void deposit(double amount) { balance += amount; }
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
    void applyLoan(double amount, int years, double interestRate) {
        loanAmount += amount * pow(1 + interestRate, years);
    }
};

class BankSystem {
private:
    unordered_map<string, Account> accounts;
    double interestRate;

public:
    BankSystem() : interestRate(0.05) {}  // Default interest rate: 5%

    void createAccount() {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (accounts.find(username) == accounts.end()) {
            accounts.emplace(username, Account(username, password));
            cout << "Account created successfully.\n";
        } else {
            cout << "Username already exists.\n";
        }
    }

    Account* login() {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        auto it = accounts.find(username);
        if (it != accounts.end() && it->second.checkPassword(password)) {
            cout << "Login successful.\n";
            return &it->second;
        } else {
            cout << "Invalid username or password.\n";
            return nullptr;
        }
    }

    void adminMenu() {
        int choice;
        do {
            cout << "1. Update Interest Rate\n";
            cout << "0. Exit\n";
            cout << "Your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    double newRate;
                    cout << "Enter new interest rate (e.g., 0.05 for 5%): ";
                    cin >> newRate;
                    setInterestRate(newRate);
                    break;
                }
                case 0:
                    cout << "Exiting admin menu...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 0);
    }

    void userMenu(Account& account) {
        int choice;
        do {
            cout << "1. Deposit\n";
            cout << "2. Withdraw\n";
            cout << "3. Apply for Loan\n";
            cout << "0. Exit\n";
            cout << "Your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account.deposit(amount);
                    cout << "Deposit successful. Current balance: " << account.getBalance() << "\n";
                    break;
                }
                case 2: {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    if (account.withdraw(amount))
                        cout << "Withdrawal successful. Current balance: " << account.getBalance() << "\n";
                    else
                        cout << "Insufficient funds.\n";
                    break;
                }
                case 3: {
                    double amount;
                    int years;
                    cout << "Enter loan amount: ";
                    cin >> amount;
                    cout << "Enter loan term in years: ";
                    cin >> years;
                    account.applyLoan(amount, years, interestRate);
                    cout << "Loan applied successfully.\n";
                    break;
                }
                case 0:
                    cout << "Exiting user menu...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 0);
    }

    void setInterestRate(double rate) {
        interestRate = rate;
        cout << "Interest rate updated: " << interestRate * 100 << "%\n";
    }
};

int main() {
    BankSystem bank;
    int choice;

    do {
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Admin Login\n";
        cout << "0. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2: {
                Account* account = bank.login();
                if (account)
                    bank.userMenu(*account);
                break;
            }
            case 3:
                bank.adminMenu();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}