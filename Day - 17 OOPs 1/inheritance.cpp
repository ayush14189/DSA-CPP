#include <iostream>
using namespace std;

class Animal {
public:
    string color;
    void eat() {
        cout << "Eating..." << endl;
    }
    void breathe() {
        cout << "Breathing..." << endl;
    }
};

// Modes of Inheritance
class Fish : public Animal{
public:
    int fins;
    void swim() {
        cout << "Swimming..." << endl;
    }
};

class Fish2 : protected Animal{
public:
    int fins;
    void swim() {
        eat(); // Possible as Animal is protected
        cout << "Swimming..." << endl;
    }
};

class Fish3 : private Animal{
public:
    int fins;
    void swim() {
        eat(); // Possible as Animal is private
        cout << "Swimming..." << endl;
    }
};

class Fish4 : public Animal{ // public/private/protected Animal
private:    // Not accessible (Hidden) for all types of inheritance
    int fins;
    void swim() {
        eat(); // Possible as Animal is private
        cout << "Swimming..." << endl;
    }
};

// Types of Inheritance
// Multi-level Inheritance
class Mammal : public Animal{
public:
    string bloodType = "warm";
};
class Dog : public Mammal{
public:
    void tailwag(){
        cout << "A dog wags its tail" << endl;
    }
};

// Multiple Inheritance
class Teacher {
public: 
    int salary;
    string subject;
};
class Student {
public:
    int rollno;
    float cgpa;
};
class TA : public Teacher, public Student {
public:
    string name;
};

// Hierarchical & Hybrid Inheritance
class Bird0: public Animal {
public: 
    void fly() {
        cout << "It can fly" << endl;
    }
};
class Fish0: public Animal {
public: 
    void swim() {
        cout << "It can swim" << endl;
    }
};
class Mammal0: public Animal {
public: 
    void walk() {
        cout << "It can walk" << endl;
    }
};
class Shark : public Fish0{
public:
    void eatFish() {
        cout << "It eats fish" << endl;
    }
};

int main() {
    // Modes of Inheritance
    Fish f1;
    f1.fins = 2;
    cout << f1.fins << endl;
    f1.swim();
    f1.eat();
    f1.breathe();

    Fish2 f2;
    f2.fins = 2;
    cout << f2.fins << endl;
    f2.swim();
    // Not Possible as Animal is protected
    // f2.eat();
    // f2.breathe();

    Fish3 f3;
    f3.fins = 2;
    cout << f3.fins << endl;
    f3.swim();
    // Not Possible as Animal is private
    // f3.eat();
    // f3.breathe();

    // Types of Inheritance
    // Single Inheritance
    Fish f0;
    f0.fins = 2;
    cout << f0.fins << endl;
    f0.swim();
    f0.eat();
    f0.breathe();

    // Multi-level Inheritance
    Dog d1;
    d1.eat();
    d1.breathe();
    d1.tailwag();
    cout << d1.bloodType << endl;

    // Multiple Inheritance
    TA t1;
    t1.name = "David";
    t1.salary = 50000;
    t1.subject = "Maths";
    t1.rollno = 10;
    t1.cgpa = 9.0;
    cout << "Name: " << t1.name << endl;
    cout << "Salary: " << t1.salary << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Roll No: " << t1.rollno << endl;
    cout << "CGPA: " << t1.cgpa << endl;
    
    // Hierarchical Inheritance


    // Hybrid Inheritance

    return 0;
}