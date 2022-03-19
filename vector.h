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
	vector2D operator -();	
	
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


class vector3D
{
public:	
	vector3D(float x = 0.f, float y = 0.f, float z = 0.f);

	// sum	
	vector3D operator +(const vector3D &other);
	void operator +=(const vector3D &other);

	// diff
	vector3D operator -(const vector3D &other);	
	vector3D operator -();	
	
	void operator -=(const vector3D &other);
	
	// mult
	void operator *=(const float num);	
	vector3D operator *(const float num);	

	// div
	void operator /=(const float num);	
	vector3D operator /(const float num);	
	
	float scalar(const vector3D &other);
	float dist(const vector3D &other);
	
	float length();
	vector3D normalize();
	void setZero();

	float x,y,z;
};

#endif // VECTOR_H
