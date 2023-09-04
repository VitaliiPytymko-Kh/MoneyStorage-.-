// MoneyStorage Питимко В.Л.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
class MoneyStorage {
public:
    // Конструктор по умолчанию и деструктор
    MoneyStorage() = default;
    virtual ~MoneyStorage() = default;

    // Метод для получения текущего баланса
    virtual double getBalance() const = 0;

    // Метод для пополнения счета
    virtual void deposit(double amount) = 0;

    // Метод для снятия средств
    virtual void withdraw(double amount) = 0;

    // Метод для отображения информации о счете
    virtual void display() const = 0;
};
class Card : public MoneyStorage {
private:
    double balance;
    std::string cardName;

public:
    Card(const std::string& name) : balance(0.0), cardName(name) {}

    double getBalance() const override {
        return balance;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            std::cout << "Недостаточно средств на карте." << std::endl;
        }
    }

    void display() const override {
        std::cout << "Карта " << cardName << " (Баланс: " << balance << ")" << std::endl;
    }
};

class Wallet : public MoneyStorage {
private:
    double balance;
    std::string walletName;

public:
    Wallet(const std::string& name) : balance(0.0), walletName(name) {}

    double getBalance() const override {
        return balance;
    }

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            std::cout << "Недостаточно средств в кошельке." << std::endl;
        }
    }

    void display() const override {
        std::cout << "Кошелек '" << walletName << "' (Баланс: " << balance << ")" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL,"");
    Card card("Privat");
    Wallet wallet("Check");
    card.deposit(1000);
    wallet.deposit(500);
    card.display();
    wallet.display();
  
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
