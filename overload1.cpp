#include <iostream>
class example
{
public:
    float a;
    float b;
    example operator+(const example& obj);
    void operator=(const example& obj);
};

void example::operator=(const example& obj)
{
    (*this).a = obj.a;
    (*this).b = obj.b;

    return;
}

example example::operator+(const example& obj2)
{
    example tmp_obj = *this;
    tmp_obj.a = tmp_obj.a + obj2.a;
    tmp_obj.b = tmp_obj.b + obj2.b;
    return tmp_obj;
}

int main(void)
{
    example obj1, obj2, obj3;

    obj1.a = 1.5;
    obj1.b = 1.5;

    obj2.a = 20;
    obj2.b = 20;

    obj3.a = 0;
    obj3.b = 0;

    obj3 = obj1 + obj2;

    std::cout << "obj1.a = " << obj1.a << " \tobj1.b = " << obj1.b << "\nobj2.a = " << obj2.a << "\tobj2.b = " << obj2.b <<  "\nResultat :\nobj3.a = " <<  obj3.a << "  " << "\tobj3.b =" << obj3.b << "\n";

    return 0;
}
