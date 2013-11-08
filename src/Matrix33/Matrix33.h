/*
 * EPFL
 * Projets en informatique pour SV
 * Projet 2013-2014
 * Roger Küng, Corentin Perret, Jamila Sam
 */

#ifndef Matrix33_H
#define Matrix33_H

#include <vector>
#include <iostream>

#include "../VecnD/VecnD.h"

class Matrix33
{
	private:
	
	double matrice[3][3];

	public:
	
	Matrix33();
	Matrix33(double d1, double d2, double d3);
	Matrix33(double d1, double d2, double d3, double d4, double d5, double d6, double d7, double d8, double d9);

	double getCoefficient(int i, int j) const;
	
	void setCoefficient(double c, int i, int j); 
	
	Matrix33& operator+=(Matrix33 const& m);
	Matrix33 operator+(Matrix33 const& m) const;
	Matrix33& operator-=(Matrix33 const& m);
	Matrix33 operator-(Matrix33 const& m) const; 
	Matrix33& operator*=(Matrix33 const& m);
	Matrix33 operator*(Matrix33 const& m) const;
	VecnD<double> operator*(VecnD<double> const& v) const;

	Matrix33 transp() const;
	
	double det() const;
	
	Matrix33 inv() const;
	
	Matrix33 cholesky() const;

};

	Matrix33 operator*(double d, Matrix33 const& m);
	std::ostream& operator<<(std::ostream& s, Matrix33 const& m);

#endif
