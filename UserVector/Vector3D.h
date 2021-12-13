#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
template <class T>
class Vector3D
{
private:
	T Vect[3];
public:
	Vector3D(T x, T y, T z) {
		this->Vect[0] = x;
		this->Vect[1] = y;
		this->Vect[2] = z;
	}
	Vector3D(const Vector3D&) = delete;
	Vector3D& operator=(const Vector3D&) = delete;
	void print()const;// affichage du vecteur
	T at(unsigned int)const;
	bool operator==(const Vector3D&)const;
	bool operator!=(const Vector3D&)const;
	
			
	T& operator[](unsigned int);
	T scalaire(const Vector3D&)const;// le produit scalaire de deux vecteurs
	Vector3D* operator*(const T&)const;// le produit d'un vecteur par un scalaire
	Vector3D* operator+(const Vector3D&)const;// la somme de deux vecteurs
	Vector3D* operator-(const Vector3D&)const;// la soustraction de deux vecteurs
	Vector3D* vectoriel(const Vector3D&)const;// le produit vectorielle de deux vecteurs
	T module()const;// la module d'un vecteur
	
};

template<class T>
void Vector3D<T>::print() const
{
	for (int i = 0; i < 3; i++)
	{
		cout <<"Vect[" << i << "] = " << this->Vect[i] << endl;
	}
}

template<class T>
T Vector3D<T>::at(unsigned int i) const
{
	assert(i >= 0 && i < 3);// en mode debogage
	return this->Vect[i];// sinon retourner l'élément 
}
template<class T>
bool Vector3D<T>::operator==(const Vector3D& V1) const
{
	for (int i = 0; i < 3; i++)
		if (this->Vect[i] != V1.Vect[i])return false;
	return true;
}

template<class T>
bool Vector3D<T>::operator!=(const Vector3D& V2) const
{
	if(this->operator==(V2)==true)
		return false;
	return true;
}

template<class T>
T& Vector3D<T>::operator[](unsigned int i)
{
	assert(i >= 0 && i < 3);// en mode debogage
	return this->Vect[i];// sinon retourner l'élément 
}

template<class T>
T Vector3D<T>::scalaire(const Vector3D& V) const
{
	T res(0);
	for (int i = 0; i < 3; i++)
	{
		res = res + this->Vect[i] * V.Vect[i];
	}
	//res = ((this->Vect[0] * V.Vect[0])+(this->Vect[1] * V.Vect[1])+(this->Vect[2] * V.Vect[2]));
	return res;
}

template<class T>
Vector3D<T>* Vector3D<T>::operator+(const Vector3D<T>& V) const
{
	Vector3D* Vres = new Vector3D(this->Vect[0] + V.Vect[0],
								this->Vect[1] + V.Vect[1],
								this->Vect[2] + V.Vect[2]);
	return Vres;
}

template<class T>
Vector3D<T>* Vector3D<T>::operator-(const Vector3D<T>& V) const
{
	Vector3D* Vres = new Vector3D(this->Vect[0] - V.Vect[0],
								this->Vect[1] - V.Vect[1], 
								this->Vect[2] - V.Vect[2]);
	return Vres;
}

template<class T>
Vector3D<T>* Vector3D<T>::vectoriel(const Vector3D<T>& V) const
{
	T x = (this->Vect[1] * V.Vect[2]) - (this->Vect[2] * V.Vect[1]);
	T y = (this->Vect[2] * V.Vect[0]) - (this->Vect[0] * V.Vect[2]);
	T z = (this->Vect[0] * V.Vect[1]) - (this->Vect[1] * V.Vect[0]);
	Vector3D* Vres = new Vector3D(x, y, z);
	return Vres;
}

template<class T>
T Vector3D<T>::module() const
{
	T res = sqrt(pow(this->Vect[0], 2) + pow(this->Vect[1], 2) + pow(this->Vect[2], 2));
	return res;
}

template<class T>
Vector3D<T>* Vector3D<T>::operator*(const T& val)const
{
	Vector3D* Vres = new Vector3D(this->Vect[0] * val, this->Vect[1] * val, this->Vect[2] * val);
	return Vres;
}


