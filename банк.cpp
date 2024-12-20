#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string number;
    string name;
    double balance;

public:
    BankAccount(string num, string owner, double bal): number(num), name(owner), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнено успешно: " << amount << ". Текущий баланс: " << balance << endl;
        }
        else {
            cout << "Сумма пополнения должна быть положительной." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято успешно: " << amount << ". Текущий баланс: " << balance << endl;
        }
        else {
            cout << "На счёте недостаточно средств для снятия." << endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void displayAccountInfo() const {
        cout << "Номер счёта: " << number << ", Владельцы: " << name << ", Баланс: " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double rate;
public:
    SavingsAccount(string num, string owner, double balance, double rate): BankAccount(num, owner, balance), rate(rate) {}

    void app() {
        double interest = getBalance() * (rate / 100);
        deposit(interest);
        cout << "Начислены проценты: " << interest << ". Текущий баланс: " << getBalance() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    BankAccount acc("111111111", "Огурец Помидоров", 2000.0);
    acc.displayAccountInfo();

    acc.deposit(900.0);
    acc.withdraw(500.0);
    acc.withdraw(1700.0);

    SavingsAccount sacc("222222222", "Си ПлясПлясов", 4000.0, 9.0);
    sacc.displayAccountInfo();

    sacc.deposit(8000.0);
    sacc.withdraw(400.0);
    sacc.app();

    return 0;
}
