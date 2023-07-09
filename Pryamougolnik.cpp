#include <iostream>
#include <cmath>

using namespace std;


class pramougolnik {
	
private:

    double width;
    double height;
    double maxWidth;
    double maxHeight;

public:
    pramougolnik(double w, double h, double maxW, double maxH) {
        width = w;
        height = h;
        maxWidth = maxW;
        maxHeight = maxH;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    double getploshad() {
        return width * height;
    }

    double getdiagonal() {
        return sqrt(pow(width, 2) + pow(height, 2));
    }

    bool isValid() {
        return (width > 0 && width <= maxWidth) && (height > 0 && height <= maxHeight);
    }
};

int main() {
    double width, height;
    int choice;
    const double MAX_WIDTH = 1000.0;
    const double MAX_HEIGHT = 1000.0;

    setlocale(LC_ALL, "Russian");

    cout << "Введите ширину прямоугольника: ";
    cin >> width;

    cout << "Введите высоту прямоугольника: ";
    cin >> height;

    pramougolnik pramougolnik(width, height, MAX_WIDTH, MAX_HEIGHT);

    if (!pramougolnik.isValid()) {
        cout << "Размеры высоты и/или ширины некорректны." << endl;
        return 0;
    }

    cout << "Выберите, что нужно посчитать:\n";
    cout << "1. Периметр\n";
    cout << "2. Площадь\n";
    cout << "3. Диагональ\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double perimeter = pramougolnik.getPerimeter();
            cout << "Периметр прямоугольника: " << perimeter << endl;
            break;
        }
        case 2: {
            double ploshad = pramougolnik.getploshad();
            cout << "Площадь прямоугольника: " << ploshad << endl;
            break;
        }
        case 3: {
            double diagonal = pramougolnik.getdiagonal();
            cout << "Диагональ прямоугольника: " << diagonal << endl;
            break;
        }
        default:
            cout << "Неправильный выбор." << endl;
    }

    return 0;
}
