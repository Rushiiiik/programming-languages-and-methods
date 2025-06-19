#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

class Segment {
protected:
    double start_x;
    double start_y;
    double end_x;
    double end_y;

public:
    Segment() : start_x(0.0), start_y(0.0), end_x(0.0), end_y(0.0) {}
    Segment(double sx, double sy, double ex, double ey) : start_x(sx), start_y(sy), end_x(ex), end_y(ey) {
    }
    virtual ~Segment() {}

    void start(double x, double y) {
        start_x = x;
        start_y = y;
    }
    double get_x() const { return start_x; }
    double get_y() const { return start_y; }

    void end(double x, double y) {
        end_x = x;
        end_y = y;
    }
    double get_ex() const { return end_x; }
    double get_ey() const { return end_y; }

    virtual void printInfo() const {
        cout << "Начало отрезка: (" << start_x << ", " << start_y << ")" << endl;
        cout << "Конец отрезка: (" << end_x << ", " << end_y << ")" << endl;
    }

    double Length() const {
        return sqrt(pow(end_x - start_x, 2) + pow(end_y - start_y, 2));
    }
};

class Drawn_segment : public Segment {
private:
    double thickness;
    string color;

public:
    Drawn_segment() : Segment(), thickness(1.0), color("черный") {}
    Drawn_segment(double sx, double sy, double ex, double ey, double t, string c) : Segment(sx, sy, ex, ey), thickness(t), color(c) {}
    ~Drawn_segment() override {}

    void set_thickness(double t) { thickness = t; }
    double get_thickness() const { return thickness; }
    void set_color(string c) { color = c; }
    string get_color() const { return color; }

    void printInfo() const override {
        Segment::printInfo();
        cout << "Толщина: " << thickness << endl;
        cout << "Цвет: " << color << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    cout << fixed << setprecision(2);
    Segment seg1;
    seg1.start(1.0, 2.0);
    seg1.end(4.0, 6.0);

    cout << "Отрезок 1:" << endl;
    seg1.printInfo();
    cout << "Длина: " << seg1.Length() << endl;
    Segment seg2(0.0, 0.0, 3.0, 4.0);
    cout << "Отрезок 2:" << endl;
    seg2.printInfo();
    cout << "Длина: " << seg2.Length() << endl;

    Drawn_segment dseg1;
    dseg1.start(1.0, 1.0);
    dseg1.end(5.0, 5.0);
    dseg1.set_thickness(2.5);
    dseg1.set_color("красный");

    cout << "Нарисованный отрезок 1:" << endl;
    dseg1.printInfo();
    cout << "Длина: " << dseg1.Length() << endl;

    Drawn_segment dseg2(0.0, 0.0, 10.0, 10.0, 3.0, "синий");
    cout << "Нарисованный отрезок 2:" << endl;
    dseg2.printInfo();
    cout << "Длина: " << dseg2.Length() << endl;

    return 0;
}