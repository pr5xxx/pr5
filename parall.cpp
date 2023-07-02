#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

class parallelogram {
private:
    double base;
    double side;
    double angle;
    double max_base;
    double max_side;
    double max_angle;

public:
    parallelogram (double b, double s, double angl, double max_b, double max_s, double max_angl) {
        base = b;
        side = s;
        angle = angl;
        max_base = max_b;
        max_side = max_s;
        max_angle = max_angl;
    }

    double getperimeter() {
        return 2 * (base + side);
    }
    
    double getploshad() {
        double angleInRadians = angle * M_PI / 180.0; // Перевод угла из градусов в радианы

        return base * side * sin(angleInRadians);
    }
   
    double getangle() {
        double angle2 = angle;
        return 180 - angle2;
    }

    double getdiagonal1() {
        double angleInRadians = angle * M_PI / 180.0; // Перевод угла из градусов в радианы
        return sqrt(pow(base, 2) + pow(side, 2) + 2 * base * side * cos(angleInRadians));
    
    }
    double getdiagonal2() {
        double angleInRadians = angle * M_PI / 180.0; // Перевод угла из градусов в радианы
        return sqrt(pow(base, 2) + pow(side, 2) - 2 * base * side * cos(angleInRadians));
    }
    
   
    bool isValid() {
       
        return ( (base > 0 && base <= max_base) && (side > 0 && side <= max_side) && (angle > 0 && angle <= max_angle) );
    }
};

int main() {
    double base, side, angle;
    int choice;
    const double MAX_BASE = 50.0;
    const double MAX_SIDE = 50.0;
    const double MAX_ANGLE = 90.0;

    setlocale(LC_ALL, "Russian");

    cout << "Введите основание параллелограмма: ";
    cin >> base;

    cout << "Введите боковую сторону параллелограмма: ";
    cin >> side;

    cout << "Введите угол между основанием и боковой стороной (в градусах): ";
    cin >> angle; 
  
    parallelogram parallelogram(base, side, angle, MAX_BASE, MAX_SIDE, MAX_ANGLE);

    if (!parallelogram.isValid()) {
        cout << "Размеры основания и/или боковой стороны и/или угла некорректны." << endl;
        return 0;
    }

    cout << "Выберите, что нужно посчитать:\n";
    cout << "1. Периметр\n";
    cout << "2. Площадь\n";
    cout << "3. Диагональ\n";
    cout << "4. Углы\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        double perimeter = parallelogram.getperimeter();
        cout << "Периметр паралелограмма: " << perimeter << endl;
        break;
    }
    case 2: {
        double ploshad = parallelogram.getploshad();
        cout << "Площадь паралелограмма: " << ploshad << endl;
        break;
    }
    case 3: {
        double diagonal1 = parallelogram.getdiagonal1();
        double diagonal2 = parallelogram.getdiagonal2();
        cout << "Диагональ паралелограмма 1: " << diagonal1 << "\n" << "Диагональ паралелограмма 2: " << diagonal2 << endl;
        break;
    }
    case 4: {
        double angle2 = parallelogram.getangle();
        cout << "Углы прилежащие к одной стороне" << endl;
        cout << "Угол 1: " << angle << "\n" << "Угол 2: " << angle2;
        break;
    }
    default:
        cout << "Неправильный выбор." << endl;
    }

    return 0;
}
