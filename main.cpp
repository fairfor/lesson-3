#include <iostream>

// ======================================

class Figure {
public:
    virtual void area() = 0;
};

class Parallelogram : public Figure {
public:
    unsigned int S{};
    Parallelogram() {}
    ~Parallelogram() {}
    void area(int a, int h) {
        S = a * h;
        std::cout << "Area Parallelogram: " << S;
    }
};

class Rectangle : public Parallelogram {
public:
    unsigned int S{};
    Rectangle() {}
    ~Rectangle() {}
    void area(int a, int b) {
        S = a * b;
        std::cout << "Area Rectangle: " << S;
    }
};

class Square : Parallelogram {
public:
    unsigned int S{};
    Square() {}
    ~Square() {}
    void area(int a) {
        S = a * a;
        std::cout << "Area Square: " << S;
    }
};

class Circle : public Figure {
public:
    double S{};
    const double PI = 3.141592653589793;
    Circle() {}
    ~Circle() {}
    void area(int r) {
        S = PI * pow(r, 2);
        std::cout << "Area Circle: " << S;
    }
};

void task1() {
    /*
    Circle circle;
    Square square;
    Parallelogram parallelogram;
    Rectangle rectangle;

    Figure* firgure1 = &circle;
    Figure* firgure2 = &square;
    Figure* firgure3 = &parallelogram;
    Figure* firgure4 = &rectangle;

    firgure1->area();
    firgure2->area();
    firgure3->area();
    firgure4->area();
    */
}

// ======================================

class Car {
public:
    std::string company{};
    std::string model{};
};

class PassengerCar : public virtual Car {
public:
    PassengerCar() {
        company = "BMW";
        model = "m8 competition";
        std::cout << "PassangerCar::PassangerCar() { Company = BMW, Model = m8 competition }\n";
    }
    ~PassengerCar() {
        std::cout << "PassangerCar::~PassangerCar()\n";
    }
};

class Bus : public virtual Car {
public:
    Bus() {
        company = "Mercedec";
        model = "Conecto";
        std::cout << "Bus::Bus() { Company = Mercedec, Model = Conecto }\n";
    }
    ~Bus() {
        std::cout << "Bus::~Bus()\n";
    }
};

class Minivan : public Bus, public PassengerCar {
public:
    Minivan() {
        company = "Peugeot";
        model = "Partner Crossway";
        std::cout << "Minivan::Minivan() { company = Peugeot, model = Partner Crossway }\n";
    }
    ~Minivan() {
        std::cout << "Minivan::~Minivan()\n";
    }
};

void task2() {
    {
        std::cout << "-----\n";
        Minivan* m = new Minivan{};
        delete m;
    }
    {
        std::cout << "-----\n";
        Bus* b = new Minivan{};
        delete b;
    }
    {
        std::cout << "-----\n";
        PassengerCar* c = new Minivan{};
        delete c;
    }
}

// ======================================

class Fraction
{
    int numerator;
    int denominator;
public:
    Fraction(int numerator, int znamdenominator)
    {
        if (denominator == 0)
        this->numerator = numerator;
        this->denominator = denominator;
    }
    int get_numerator() const
    {
        return numerator;
    }

    int get_denominator() const
    {
        return denominator;
    }

    //+
    friend Fraction& operator + (const Fraction& f1, const Fraction& f2);

    // -
    friend  Fraction operator-(const Fraction& i);


    friend Fraction& operator + (const Fraction& f1, const Fraction& f2)
    {
        return Fraction(f1.numerator * f2.denominator + f2.numerator * f1.denominator, f1.denominator * f2.denominator);
    }
};

void task3() {
    Fraction f1(2, 3);
    Fraction f2(1, 3);
    Fraction f_result = f1 + f2;
}

// ======================================

class card {
    enum suit {
        worms = 'w',
        baptize = 'b',
        peaks = 'p',
        tambourine = 't'
    };
    enum Number {
        two = '2',
        three = '3',
        four = '4',
        five = '5',
        six = '6',
        seven = '7',
        eight = '8',
        nine = '9',
        ten = '10',
        jack = '10',
        queen = '10',
        king = '10',
        ace = '11',
        ace_1 = '1'
    };

    bool map_position{}; // вверх лицом - false, рубашкой - true

    void flip() {
        if (map_position) {
            map_position = false;
        }
        else if (map_position == false) {
            map_position = true;
        }
    }
    int getValue(Number n, int cursor) {
        if (cursor <= 21) {
            return n;
        }
        else {
            return -1;
        }
    }
};

// ======================================

int main()
{
//    task1();
//    task2();
//    task3();
    return 0;
}
