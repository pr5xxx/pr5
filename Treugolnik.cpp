#include <iostream>
#include <cmath>
#include <algorithm>

//���� � ���������� ���������� �������� ��������� nan �� ����� �� ���������� - ������ ���������� �������� �������������� ��������� (������������� ��� ������� �� 0)
class Triangle {
private:
    double sideA, sideB, sideC;
public:
    Triangle(double a, double b, double c);
    double getSideA() const;
    double getSideB() const;
    double getSideC() const;
    double getPerimeter() const;
    double getArea() const;
    double getAngleA() const;
    double getAngleB() const;
    double getAngleC() const;
    bool isRight() const; // Right - �������������
    bool isAcute() const; // Acute - �������������
    bool isObtuse() const; // Obtuse - ������������
    bool isIsosceles() const; // Isosceles - ��������������
    bool isEquilateral() const; // Equilateral - ��������������
};

Triangle::Triangle(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

double Triangle::getSideA() const {
    return sideA;
}

double Triangle::getSideB() const {
    return sideB;
}

double Triangle::getSideC() const {
    return sideC;
}

double Triangle::getPerimeter() const {
    return sideA + sideB + sideC;
}

double Triangle::getArea() const {
    double p = (sideA + sideB + sideC) / 2;
    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}

double Triangle::getAngleA() const {
    return acos((sideB * sideB + sideC * sideC - sideA * sideA) / (2 * sideB * sideC));
}

double Triangle::getAngleB() const {
    return acos((sideA * sideA + sideC * sideC - sideB * sideB) / (2 * sideA * sideC));
}

double Triangle::getAngleC() const {
    return acos((sideA * sideA + sideB * sideB - sideC * sideC) / (2 * sideA * sideB));
}

bool Triangle::isRight() const {
    double sides[3] = {sideA, sideB, sideC};
    std::sort(sides, sides + 3);
    return std::abs(sides[2] * sides[2] - (sides[0] * sides[0] + sides[1] * sides[1])) < 1e-10;
}

bool Triangle::isAcute() const {
    double sides[3] = {sideA, sideB, sideC};
    std::sort(sides, sides + 3);
    return sides[2] * sides[2] < sides[0] * sides[0] + sides[1] * sides[1];
}

bool Triangle::isObtuse() const {
    double sides[3] = {sideA, sideB, sideC};
    std::sort(sides, sides + 3);
    return sides[2] * sides[2] > sides[0] * sides[0] + sides[1] * sides[1];
}

bool Triangle::isIsosceles() const {
    return sideA == sideB || sideB == sideC || sideC == sideA;
}

bool Triangle::isEquilateral() const {
    return sideA == sideB && sideB == sideC;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c;
    std::cout << "������� ����� ������ ������������: ";
    std::cin >> a >> b >> c;

    Triangle t(a, b, c);

    std::cout << "������� a: " << t.getSideA() << std::endl;
    std::cout << "������� b: " << t.getSideB() << std::endl;
    std::cout << "������� c: " << t.getSideC() << std::endl;
    std::cout << "��������: " << t.getPerimeter() << std::endl;
    std::cout << "�������: " << t.getArea() << std::endl;

    if (t.isEquilateral()) {
    std::cout << "����������� ��������������" << std::endl;
    } else if (t.isIsosceles()) {
    std::cout << "����������� ��������������" << std::endl;
    } else {
    std::cout << "����������� ��������������" << std::endl;
    }

    if (t.isRight()) {
        std::cout << "����������� �������������" << std::endl;
    } else if (t.isAcute()) {
        std::cout << "����������� �������������" << std::endl;
    } else if (t.isObtuse()) {
        std::cout << "����������� ������������" << std::endl;
    }

    std::cout << "���� A: " << t.getAngleA() * 180 / M_PI << " ��������" << std::endl;
    std::cout << "���� B: " << t.getAngleB() * 180 / M_PI << " ��������" << std::endl;
    std::cout << "���� C: " << t.getAngleC() * 180 / M_PI << " ��������" << std::endl;

    return 0;
}
