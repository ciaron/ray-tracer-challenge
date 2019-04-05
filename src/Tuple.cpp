class Tuple {
private:
    float xval,yval,zval,wval;
public:
    Tuple(float x=0.0, float y=0.0, float z=0.0, float w=0.0) {
	    xval=x;
		yval=y;
		zval=z;
		wval=w;
	}
    float x() { return xval; }
    float y() { return yval; }
    float z() { return zval; }
    float w() { return wval; }

    bool isPoint() { return true; }

};
	
	
