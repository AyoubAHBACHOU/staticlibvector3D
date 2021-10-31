#include "pch.h"
#include "vector3D.h"
#include <assert.h>
#include<iostream>
using namespace std;
using namespace geo;

Vector3D::Vector3D(float x, float y, float z)
{
	this->vect[0] = x;
	this->vect[1] = y;
	this->vect[2] = z;
}

void Vector3D::print() const
{
	for (int i = 0; i < 3; i++)
	{
		cout << "vect[" << i << "]=" << this->at(i)<< endl;
	}
}

float Vector3D::at(unsigned int i) const
{
	assert(i >= 0 && i < 3);
	try
	{
		if (i < 0 || i >= 3) throw "rang erre";
		return this->vect[i];
	}

	catch(char* e )
	{
		cout << e << endl;
	}
	
}

bool Vector3D::operator==(const Vector3D& v) const
{
	bool res = true;
	for (int i = 0; i < 3; i++)
	{
		res = res && (this->at(i) == v.at(i));
	}
	return res;
}

bool Vector3D::operator!=(const Vector3D& v) const
{
	bool res = !(*this == v);
	return res;
}

float& geo::Vector3D::operator[](unsigned int i)
{
	assert(i >= 0 && i < 3);//debug
	try//release
	{
		if (i < 0 || i >= 3) throw "rang erre";
		return this->vect[i];
	}

	catch (char* e)
	{
		cout << e << endl;
	}
	
}

float geo::Vector3D::module() const
{
	return (sqrt(pow(this->at(0), 2) + pow(this->at(1), 2) + pow(this->at(2), 2)));;
}

float geo::Vector3D::operator*(const Vector3D& v) const
{
	return(this->at(0) * v.at(0) + this->at(1) * v.at(1) + this->at(2) * v.at(2));
}

void geo::Vector3D::operator*(float val)
{
	this->vect[0] *= val;
	this->vect[1] *= val;
	this->vect[2] *= val;
}

Vector3D* geo::Vector3D::operator^(const Vector3D& v) const
{
	Vector3D* res = new Vector3D();
	res->vect[0] = this->at(1) * v.at(2) - this->at(2) * v.at(1);
	res->vect[1] = this->at(0) * v.at(2) - this->at(2) * v.at(0);
	res->vect[2] = this->at(0) * v.at(1) - this->at(1) * v.at(0);
	return res;
}

Vector3D* geo::Vector3D::operator+(const Vector3D& v) const
{
	Vector3D* add = new Vector3D();
	add->vect[0] = this->at(0) + v.at(0);
	add->vect[1] = this->at(1) + v.at(1);
	add->vect[2] = this->at(2) + v.at(2);
	return add;
}

Vector3D* geo::Vector3D::operator-(const Vector3D& v) const
{
	Vector3D* sous = new Vector3D();
	sous->vect[0] = this->at(0) - v.at(0);
	sous->vect[1] = this->at(1) - v.at(1);
	sous->vect[2] = this->at(2) - v.at(2);
	return sous;
}

void geo::Vector3D::operator/(float val)
{
	this->vect[0] /= val;
	this->vect[1] /= val;
	this->vect[2] /= val;
}

/*void geo::display(vector3D& v)
{
	for (int i = 0; i < 3; i++)
	{
		cout << "vect[" << i << "]=" << v.vect[i] << endl;
	}
}*/
