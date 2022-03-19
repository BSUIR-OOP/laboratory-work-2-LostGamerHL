#ifndef VECTOR_H
#define VECTOR_H


class vector2D
{
public:	
	vector2D(float x = 0.f, float y = 0.f);

	// sum	
	vector2D operator +(const vector2D &other);
	void operator +=(const vector2D &other);

	// diff
	vector2D operator -(const vector2D &other);	
	void operator -=(const vector2D &other);
	
	// mult
	void operator *=(const float num);	
	vector2D operator *(const float num);	

	// div
	void operator /=(const float num);	
	vector2D operator /(const float num);	
	
	float scalar(const vector2D &other);
	float dist(const vector2D &other);
	
	
	float length();
	vector2D normalize();
	void setZero();

	float x,y;
};

#endif // VECTOR_H
