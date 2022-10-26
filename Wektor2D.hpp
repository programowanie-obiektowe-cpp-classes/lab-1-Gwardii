class Informer{
    public:
        Informer(){
            std::cout << "Wywołano konstruktor" << std::endl;
        }
        ~Informer(){
            std::cout << "Wywołano destruktor" << std::endl;
        }
};

class Wektor2D{
    double x;
    double y;
    Informer informer;

    public:
        static int num_wek;
        Wektor2D(){
            x = 0;
            y = 0;
        }
        Wektor2D(double x, double y){
            this->x = x;
            this->y = y;
            std::cout << ++num_wek << std::endl;
        }
        Wektor2D(const Wektor2D& source) : Wektor2D{source.x, source.y}{}
        ~Wektor2D(){
            this->print();
        }
        double norm(){
            return std::sqrt(x*x + y*y);
        }
        void print(){
            std::cout << '[' << x << "; " << y
                << ']' << std::endl;
        }
        std::ostream& print(std::ostream& os){
            os << '[' << x << "; " << y
                << ']';
            return os;
        }
        void setX(double x){this->x = x;}
        void setY(double x){this->y = y;}
        double getX(){return x;}
        double getY(){return y;}
        int getNumWek(){return num_wek;}
};

int Wektor2D::num_wek = 0;

Wektor2D operator+(Wektor2D w1, Wektor2D w2){
    Wektor2D w{w1.getX() + w2.getX(), w1.getY()+w2.getY()};
    return w;
}
double operator*(Wektor2D w1, Wektor2D w2){
    return w1.getX()*w2.getX() + w1.getY() * w2.getY();
}
