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

    cout << "Ââĺäčňĺ řčđčíó ďđ˙ěîóăîëüíčęŕ: ";
    cin >> width;

    cout << "Ââĺäčňĺ âűńîňó ďđ˙ěîóăîëüíčęŕ: ";
    cin >> height;

    pramougolnik pramougolnik(width, height, MAX_WIDTH, MAX_HEIGHT);

    if (!pramougolnik.isValid()) {
        cout << "Đŕçěĺđű âűńîňű č/čëč řčđčíű íĺęîđđĺęňíű." << endl;
        return 0;
    }

    cout << "Âűáĺđčňĺ, ÷ňî íóćíî ďîń÷čňŕňü:\n";
    cout << "1. Ďĺđčěĺňđ\n";
    cout << "2. Ďëîůŕäü\n";
    cout << "3. Äčŕăîíŕëü\n";
    cout << "Âŕř âűáîđ: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double perimeter = pramougolnik.getPerimeter();
            cout << "Ďĺđčěĺňđ ďđ˙ěîóăîëüíčęŕ: " << perimeter << endl;
            break;
        }
        case 2: {
            double ploshad = pramougolnik.getploshad();
            cout << "Ďëîůŕäü ďđ˙ěîóăîëüíčęŕ: " << ploshad << endl;
            break;
        }
        case 3: {
            double diagonal = pramougolnik.getdiagonal();
            cout << "Äčŕăîíŕëü ďđ˙ěîóăîëüíčęŕ: " << diagonal << endl;
            break;
        }
        default:
            cout << "Íĺďđŕâčëüíűé âűáîđ." << endl;
    }

    return 0;
}
