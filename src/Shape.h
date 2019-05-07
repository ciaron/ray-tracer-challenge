#ifndef SHAPE_H
#define SHAPE_H

class Shape {

private:
    int _id;
public:
    static int count;

    Shape()
    {
        _id = count;
        ++count;
    }

    int id() const { return _id; }
    //virtual vector<float> intersect(const Shape& s) =0;

};

#endif
