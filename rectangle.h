class Rectangle
{
    public:
    // Variables (btw public member variables are not a good 
    //   practice, you should set them as private and access them 
    //   via accessor methods, that is what encapsulation is)
    double l;
    double w;

    // constructor
    Rectangle();
    // Methods
    double Area();
    double Perim();
};
