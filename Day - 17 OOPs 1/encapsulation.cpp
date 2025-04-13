#include <iostream>
using namespace std;

// Class
class Student {
    // Properties

private: // Access Modifier
    string name;

public: // Access Modifier
    float cgpa;
    // Methods
    void getPercentage() {
        cout << "Percentage: " << (cgpa*10) << endl;
    }

    // Setters
    void setName(string nameVal) {
        name = nameVal;
    }
    void setCgpa(float cgpaVal) {
        cgpa = cgpaVal;
    }

    // Getters
    string getName() {
        return name;
    }
    float getCgpa() {
        return cgpa;
    }
};

class User1 {
    // Properties
    int id;
    string username, password, bio;

    // Methods
    void deactivate() {
        cout << "Deactivating Account!" << endl;
    }
    void editBio(string newBio) {
        bio = newBio;
    }
};

class Car {
    string name;
    string color;
public:
    // Constructor
    Car() {
        // Non Parameterized Constructor - Default
        cout << "Constructor without parameters" << endl;
    }

    Car(string name, string color) {
        // Parameterized Constructor - Initialization
        cout << "Constructor with parameters" << endl;
        cout << "Constructor Called! Object being created..." << endl;
        this -> name = name;   // *(this).name
        this -> color = color; // *(this).color
    }
    void start() {
        cout << "Car is starting!" << endl;
    }
    void stop() {
        cout << "Car is stopping!" << endl;
    }
    // Getters
    string getName() {
        return name;
    }
    string getColor() {
        return color;
    }
};

/* Ques - Create a User class with properties: id (private), username (public) & password (private)
Its id should be initialized in parameterized constructor.
It should have Getter & Setter for password
*/
class User {
private:
    int id;
    string password;

public:
    string username;
    User(int id) {
        this -> id = id;
    }
    // Getter
    string getPassword() {
        return password;
    }
    // Setter
    void setPassword(string password) {
        this -> password = password;
    }
};

class Car1 {
public:
    string name;
    string color;
    int *mileage;
    Car1(string name, string color) {
        this -> name = name;
        this -> color = color;
        mileage = new int; // Dynamic Memory Allocation
        *mileage = 10;     // Initialization
    }
    // Copy Constructor
    Car1(Car1 &original) {
        cout << "Copying origineal to new..." << endl;
        name = original.name;
        color = original.color;
        // mileage = original.mileage; // Shallow Copy
        mileage = new int;             // Deep Copy
        *mileage = *(original.mileage);
    } 
    ~Car1() {
        // Custom Destructor - Free Dynamic Memory
        cout << "Object deletion..." << endl;
        if(mileage != NULL) {
            delete mileage; // Garbage Memory Collection
            mileage = NULL; // Dangling Pointer
        }
        }
};

int main() {
    Student s1; // Object
    cout << sizeof(s1) << endl;
    Student s2; // Another Object

    s1.cgpa = 9.0;
    cout << "CGPA: " << s1.cgpa << endl;
    s1.getPercentage();

    // Getters and Setters
    s1.setName("Ayush Jain");
    s1.setCgpa(9.0);
    cout << "Name: " << s1.getName() << endl;
    cout << "CGPA: " << s1.getCgpa() << endl;

    // Constructor
    Car c0;                  // Non Parameterized Constructor
    Car c1("Audi", "Black"); // Parameterized Constructor
    cout << "Car Name: " << c1.getName() << endl;

    // Practice Question
    User u1(1001);
    u1.username = "John Doe";
    cout << "Username: " << u1.username << endl;
    u1.setPassword("password123");
    cout << "Password: " << u1.getPassword() << endl;

    // Copy Constructor
    Car1 car1("Audi", "Black"); // Parameterized Constructor - Initialization
    Car1 car2(car1);            // Custom Copy Constructor
    cout << car2.name << endl;  // Audi
    cout << car2.color << endl; // Black
    
    // Shallow Copy
    // cout << *car2.mileage << endl; // 10
    // *car2.mileage = 20;
    // cout << *car1.mileage << endl; // 20 - Change in Original Object

    // Deep Copy
    cout << *car2.mileage << endl; // 10
    *car2.mileage = 20;
    cout << *car1.mileage << endl; // 10 - No Change in Original Object

    return 0;
}