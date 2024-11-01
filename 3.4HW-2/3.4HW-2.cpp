#include <iostream>

class Figure {
public:
    virtual void print_info() const = 0;
};

// Треугольники
class Triangle : public Figure {
protected:
    double a, b, c;
    double A, B, C;

public:
    Triangle(double a, double b, double c, double A, double B, double C) :
        a(a), b(b), c(c), A(A), B(B), C(C) {}

    double get_side_a() const { return a; }
    double get_side_b() const { return b; }
    double get_side_c() const { return c; }

    double get_angle_A() const { return A; }
    double get_angle_B() const { return B; }
    double get_angle_C() const { return C; }

    void print_info() const override {
        std::cout << "Треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

// Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(double a, double b, double c) :
        Triangle(a, b, c, 0, 0, 90) {}
};

// Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double a, double b, double A, double B) :
        Triangle(a, b, a, A, B, A) {}
};

// Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double a) :
        Triangle(a, a, a, 60, 60, 60) {}
};

// Класс для четырёхугольников
class Quadrangle : public Figure {
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double a, double b, double c, double d,
        double A, double B, double C, double D) :
        a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    double get_side_a() const { return a; }
    double get_side_b() const { return b; }
    double get_side_c() const { return c; }
    double get_side_d() const { return d; }

    double get_angle_A() const { return A; }
    double get_angle_B() const { return B; }
    double get_angle_C() const { return C; }
    double get_angle_D() const { return D; }

    void print_info() const override {
        std::cout << "Четырёхугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

// Параллелограмм
class Parallelogram : public Quadrangle {
public:
    Parallelogram(double a, double b, double A, double B) :
        Quadrangle(a, b, a, b, A, B, A, B) {}
};

// Прямоугольник
class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double b) :
        Parallelogram(a, b, 90, 90) {}
};

// Ромб
class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double A, double B) :
        Parallelogram(a, a, A, B) {}
};

// Квадрат
class Square : public Rectangle {
public:
    Square(double a) :
        Rectangle(a, a) {}
};

int main() {
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rectangle rectangle(10, 20);
    Rhombus rhombus(30, 30, 40);
    Square square(20);

    triangle.print_info();
    std::cout << std::endl;
    right_triangle.print_info();
    std::cout << std::endl;
    isosceles_triangle.print_info();
    std::cout << std::endl;
    equilateral_triangle.print_info();
    std::cout << std::endl;

    quadrangle.print_info();
    std::cout << std::endl;
    parallelogram.print_info();
    std::cout << std::endl;
    rectangle.print_info();
    std::cout << std::endl;
    rhombus.print_info();
    std::cout << std::endl;
    square.print_info();

    return 0;
}
