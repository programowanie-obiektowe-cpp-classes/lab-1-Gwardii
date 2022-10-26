class Wektor2D{
    double x;
    double y;

    public:
        Wektor2D(){
            x = 0;
            y = 0;
        }
        Wektor2D(double x, double y){
            this->x = x;
            this->y = y;
        }
        Wektor2D(const Wektor2D& source) : Wektor2D{source.x, source.y}{}
        ~Wektor2D(){
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
};

Wektor2D operator+(Wektor2D w1, Wektor2D w2){
    Wektor2D w{w1.getX() + w2.getX(), w1.getY()+w2.getY()};
    return w;
}
double operator*(Wektor2D w1, Wektor2D w2){
    return w1.getX()*w2.getX() + w1.getY() * w2.getY();
}
