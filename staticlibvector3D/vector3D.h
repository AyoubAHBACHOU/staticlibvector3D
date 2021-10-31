#pragma once
#include<iostream>
using namespace std;
namespace geo
{
	class Vector3D
	{
	private:
		float vect[3];

	public:
		Vector3D(float x = 0.0, float y = 0.0, float z = 0.0);
		Vector3D(const Vector3D&) = delete;
		Vector3D& operator=(const Vector3D&) = delete;
		void print() const;
		float at(unsigned int) const;
		bool operator==(const Vector3D& v) const;
		bool operator!=(const Vector3D& v) const;
		float& operator[](unsigned int);
		float module()const;
		//le produit scalaire
		float operator*(const Vector3D& v)const;
		//le produit d'un vecteur et une valeur
		void operator*(float val);	
		//le produit vectoriel
		Vector3D* operator^(const Vector3D& v)const;
		Vector3D* operator+(const Vector3D& v)const;
		Vector3D* operator-(const Vector3D& v)const;
		void operator/(float val);
		//friend void display(vector3D& v); -5






	};
	//void display(vector3D &v);
}

