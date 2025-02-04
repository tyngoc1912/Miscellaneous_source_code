#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

const double PI = 3.141519;

using std::vector;
using std::string;
using ll = long long;

class POINT  {
    private:
        double absscissa;
        double ordinate;

    public:
        POINT () {}
        POINT (double absscissa_, double ordinate_): absscissa (absscissa_), ordinate (ordinate_) {}
        POINT (POINT* p): absscissa (p -> absscissa), ordinate (p -> ordinate) {}

        friend std::ostream& operator<< (std::ostream& out, POINT& point) {
            out << "x: " << point.absscissa << " | y: "  << point.ordinate;
        }

        void set () {
            std::cin >> absscissa >> ordinate;
        }

        void set (double absscissa_, double ordinate_) {
            this -> absscissa = absscissa_;
            this -> ordinate = ordinate_;
        }

        vector <double> get () {
            return {absscissa, ordinate};
        }
        double getAbsscissa () {return absscissa;}
        double getOrdinate () {return ordinate;}

        void printInfor () {
            std::cout << std::setprecision (3)<< "x: " << absscissa << " | y: " << ordinate << '\n';
        }

        void move (double vectorX, double vectorY) {
            absscissa += vectorX;
            ordinate += vectorY;
        }

        void move (POINT vectorMoving) {
            absscissa += vectorMoving.absscissa;
            ordinate += vectorMoving.ordinate;
        }

        void rotate (double radian) {
            absscissa = absscissa * cos (radian) - ordinate * sin (radian);
            ordinate = absscissa * sin (radian) + ordinate * cos (radian);
        }

        ~POINT () {
            absscissa = 0;
            ordinate = 0;
        }


};

class POLYGON {
    private:
        int numberOfSide;
        POINT* point;
    public:
        POLYGON () {}
        POLYGON (int numSides): numberOfSide (numSides), point (new POINT [numSides]) {}
        POLYGON (POLYGON& anotherPolygon) {
            numberOfSide = anotherPolygon.numberOfSide;
            point = anotherPolygon.point;
        }

        void set () {
            std::cin >> numberOfSide;
            point = new POINT[numberOfSide];
            for (int i = 0; i < numberOfSide; ++i) {
                //std::cin.ignore ();
                (point + i) -> set ();
            }
        }

        void set (int numSides) {
            numberOfSide = numSides;
            point = new POINT [numberOfSide];
            for (int i = 0; i < numberOfSide; ++i) {
                (point + i) -> set ();
            }
        }

        void set (vector <POINT> point_) {
            numberOfSide = point_.size ();
            point = new POINT[numberOfSide];
            for (int current = 0; current < numberOfSide; ++current) {
                (point + current) -> set (point_[current].getAbsscissa(), point_[current].getOrdinate());
            }
        }

        void modifyPoint (int position, int pointX, int pointY) {
            if (position >= numberOfSide || numberOfSide < 0) return;
            else {
                (point + position) -> set (pointX, pointY);
            }
        }

        void showInforShape () {
            std::cout << "total sides: " << numberOfSide << '\n';
            std::cout << "Position in Cartesian coordinate system: " << '\n';
            for (int i = 0; i < numberOfSide; ++i) {
                (point + i) -> printInfor ();
            }
        }

        int getSide () {return numberOfSide;}

        void rotate (double radian) {
            for (int current = 0; current < numberOfSide; ++current) {
                (point + current) -> rotate(radian);
            }
        }

        POINT getGravity () {
            POINT *gravity = new POINT(0, 0);
            double totalAbssissa = 0;
            double totalOrdinate = 0;
            for (int current = 0; current < numberOfSide; ++current) {
                totalAbssissa += (point + current) -> getAbsscissa ();
                totalOrdinate += (point + current) -> getOrdinate ();
            }
            totalAbssissa /= (double) numberOfSide;
            totalOrdinate /= (double) numberOfSide;
            gravity -> set (totalAbssissa, totalOrdinate);
            return *gravity;
        }

        void zoomIN (double rate) {
            // get the fomualar
            /*
            rate * (x1 - xo) = x2 - xo;
            rate * (y1 - yo) = y2 - yo;
            */
           POINT*  gravity = new POINT;
           *gravity = getGravity ();
            for (int current = 0; current < numberOfSide; ++current) {
                double newAbsscissa = rate * (point + current) -> getAbsscissa () - (rate - 1) * gravity->getAbsscissa();
                double newOrdinate = rate * (point + current) -> getOrdinate () - (rate - 1) * gravity->getOrdinate();
                (point + current) -> set (newAbsscissa, newOrdinate);
            }
        }

        void zoomOut (double rate) {
            /*
            rate (x2 - xo) = x1 - xo
            rate (y2 - yo) = y2 - yo
            */
           POINT gravity = getGravity () ;
           for (int current = 0; current < numberOfSide; ++current) {
                double newAbsscissa = ((point + current) -> getAbsscissa() - (rate - 1) * gravity.getAbsscissa()) / rate;
                double newOrdinate = ((point + current) -> getOrdinate() - (rate -1) * gravity.getOrdinate()) / rate;
                (point + current) -> set (newAbsscissa, newOrdinate);
           }
        }

        void moving (vector <POINT> vec) {
            POINT* vectorMoving = new POINT (0, 0);
            if (vec.size () ==  1) {
                vectorMoving -> set (vec[0].getAbsscissa(), vec[0].getOrdinate());
            }else{
                double absscissa_ = vec[vec.size() - 1].getAbsscissa () - vec[0].getAbsscissa();
                double ordinate_ = vec[vec.size() - 1].getOrdinate () - vec[0].getOrdinate ();
                vectorMoving -> set (absscissa_, ordinate_);
            }

            for (int current = 0; current < numberOfSide; ++current) {
                (point + current) -> move (*vectorMoving);
            }
        }

        ~POLYGON () {
            delete[] point;
            numberOfSide = 0;
        }

};

class TRIANGLE :public POLYGON {
    public:
        TRIANGLE (): POLYGON(3) {};
        TRIANGLE (std::vector <POINT> point_): POLYGON (3) {
            POLYGON::set (point_);
        }
        TRIANGLE (TRIANGLE& anotherTriangle): POLYGON (anotherTriangle) {}

        

        ~TRIANGLE () {
            // to do nothing;
        }
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);

    // test the coordinate;
    std::cout << "test the point class" << '\n';
    POINT* point = new POINT;
    // input and ouput
    point -> set (); // input the details of one point
    point -> printInfor (); std::cout << '\n';
    std::cout << "x = " << point -> getAbsscissa () << "\n";
    std::cout << "y = " << point -> getOrdinate () << '\n';

    // modify the point
    point -> set (5, 6) ;// new point is (5, 6);
    point -> printInfor ();
    // moving follow vector (3, 4);
    point -> move (3, 4);
    point -> printInfor ();

    delete point;

    // test the polygon
    // the polygon has 5 point: (1, 2), (2, 5), (6, 7), (8, 4), (10, 11)
    std::cout << '\n' << "test the polygon class" << '\n';
    POLYGON* poly = new POLYGON;
    vector <POINT> v = {{1, 2}, {2, 5}, {6, 7}, {8, 4}, {10, 11}};
    poly -> set (v);
    poly -> showInforShape ();
    std::cout << '\n';

    poly -> moving ({{3, 4}}); // moving follow vector (3, 4)
    poly -> showInforShape (); std::cout << '\n';

    // roate the shape
    poly -> rotate (PI/2); 
    poly -> showInforShape ();
    std::cout << '\n';

    // zoom in the shape
    poly -> zoomIN (2);
    poly -> showInforShape ();
    std::cout << '\n';

    poly -> zoomOut (2);
    poly -> showInforShape ();
    std::cout << '\n';

    // test the triangle
    std::cout << "test the triangle class" << '\n';

    TRIANGLE* triangle = new TRIANGLE;
    triangle -> set ({{1, 2}, {5, 6}, {9, 10}});
    triangle -> showInforShape ();
    std::cout << '\n';
    triangle -> moving ({{3, 5}});
    triangle -> showInforShape ();
    std::cout << '\n';
    triangle -> rotate (PI/3);
    triangle -> showInforShape ();
    std::cout << '\n';
    triangle -> zoomIN (3);
    triangle -> showInforShape ();
    std::cout << '\n';
    triangle -> zoomOut (5);
    triangle -> showInforShape  ();   
  
    return 0;
}
