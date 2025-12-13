#include <iostream>
#include <string>
using namespace std;

// Clasa abstractă Animal
class Animal {
public:
    // Funcție virtuală pură
    virtual void makeSound() const = 0;

    // Funcție non-virtuală
    void eat() const {
        cout << "This animal is eating." << endl;
    }

    // Destructor virtual
    virtual ~Animal() {}
};

// Clasa derivată Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Dog says: Woof! Woof!" << endl;
    }
};

// Clasa derivată Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Cat says: Meow! Meow!" << endl;
    }
};

// Clasa derivată Cow
class Cow : public Animal {
public:
    void makeSound() const override {
        cout << "Cow says: Moo! Moo!" << endl;
    }
};

int main() {
    // Creăm obiecte derivate
    Dog dog;
    Cat cat;
    Cow cow;

    // Apelăm metodele
    cout << "Dog:" << endl;
    dog.makeSound();
    dog.eat();

    cout << "\nCat:" << endl;
    cat.makeSound();
    cat.eat();

    cout << "\nCow:" << endl;
    cow.makeSound();
    cow.eat();

    return 0;
}
