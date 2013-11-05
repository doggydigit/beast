#include "Matrix33.h"

Matrix33::Matrix33()
{
	matrice[0][0]=1; matrice[0][1]=0; matrice[0][2]=0;
	matrice[1][0]=0; matrice[1][1]=1; matrice[1][2]=0;
	matrice[2][0]=0; matrice[2][1]=0; matrice[2][2]=1;
}

Matrix33::Matrix33(double d1, double d2, double d3)
{
	matrice[0][0]=d1; matrice[0][1]=0; matrice[0][2]=0;
	matrice[1][0]=0; matrice[1][1]=d2; matrice[1][2]=0;
	matrice[2][0]=0; matrice[2][1]=0; matrice[2][2]=d3;
}

Matrix33::Matrix33(double d1, double d2, double d3, double d4, double d5, double d6, double d7, double d8, double d9)
{
	matrice[0][0]=d1; matrice[0][1]=d2; matrice[0][2]=d3;
	matrice[1][0]=d4; matrice[1][1]=d5; matrice[1][2]=d6;
	matrice[2][0]=d7; matrice[2][1]=d8; matrice[2][2]=d9;
}

double Matrix33::getCoefficient(int i, int j) const
{
	if (i>2 || i<0 || j>2 || j<0) throw std::string("Invalid line or column");
	return matrice[i][j];
}

void Matrix33::setCoefficient(double c, int i, int j)
{
	if (i>2 || i<0 || j>2 || j<0) throw std::string("Invalid line or column");
	matrice[i][j]=c;
}

Matrix33& Matrix33::operator+=(Matrix33 const& m)
{
	for(int i(0); i<3; ++i)
	{
		for(int j(0); j<3; ++j)
		{
			matrice[i][j]+=m.matrice[i][j];
		}	
	}
	
	return *this;
}

Matrix33 Matrix33::operator+(Matrix33 const& m) const
{
	Matrix33 r(*this);
	
	r+=m;
	
	return r;
}

Matrix33& Matrix33::operator-=(Matrix33 const& m)
{
	for(int i(0); i<3; ++i)
	{
		for(int j(0); j<3; ++j)
		{
			matrice[i][j]-=m.matrice[i][j];
		}	
	}
	return *this;
}

Matrix33 Matrix33::operator-(Matrix33 const& m) const
{
	Matrix33 r(*this);
	
	r-=m;
	
	return r;
}

Matrix33& Matrix33::operator*=(Matrix33 const& m)
{
	Matrix33 c(*this);
	
	for(int i(0); i<3; ++i)
	{
		for(int j(0); j<3; ++j)
		{
			matrice[i][j]=0;
			for (int k(0); k<3; ++k) matrice[i][j]+=c.matrice[i][k]*m.matrice[k][j];
		}	
	}
	
	return *this;
}

Matrix33 Matrix33::operator*(Matrix33 const& m) const
{
	Matrix33 r(*this);
	
	r*=m;
	
	return r;
}

VecnD<double> Matrix33::operator*(VecnD<double> const& v) const
{
	VecnD<double> r(3);
	
	for(int i(0); i<3; ++i)
	{
		double coefficient(0);
		for (int k(0); k<3; ++k) coefficient+=this->matrice[i][k]*v[k];
		
		r[i]=coefficient;
	}
	
	return r;
}

Matrix33 operator*(double d, Matrix33 const& m)
{
	Matrix33 r;
	for (int i(0); i<3; ++i)
	{
		for (int j(0); j<3; ++j)
		{
			r.setCoefficient(d*m.getCoefficient(i,j),i,j);
		}
	}
	return r;
}

std::ostream& operator<<(std::ostream& s, Matrix33 const& m)
{
	for (int i(0); i<3; ++i)
	{
		for (int j(0); j<3; ++j)
		{
			s<<m.getCoefficient(i,j);
			if (j!=3) std::cout<<' ';
		}
		s<<std::endl;
	}
	return s;
}

Matrix33 Matrix33::transp() const
{
	Matrix33 r;
	
	for (int i(0); i<3; ++i)
	{
		for (int j(0); j<3; ++j)
		{
			r.setCoefficient(matrice[j][i],i,j);
		}
	}
	
	return r;
}

double Matrix33::det() const
{
	double det(matrice[0][0]*(matrice[1][1]*matrice[2][2]-matrice[1][2]*matrice[2][1])
			-matrice[0][1]*(matrice[1][0]*matrice[2][2]-matrice[1][2]*matrice[2][0])
			+matrice[0][2]*(matrice[1][0]*matrice[2][1]-matrice[1][1]*matrice[2][0]));
	
	if (abs(det)<1e-12) return 0;
	return det;
}

Matrix33 Matrix33::inv() const
{
	double determinant(det());
	
	if (determinant==0) throw std::string("Singular Matrix");
	
	Matrix33 r(matrice[1][1]*matrice[2][2]-matrice[1][2]*matrice[2][1],
	matrice[0][2]*matrice[2][1]-matrice[0][1]*matrice[2][2],
	matrice[0][1]*matrice[1][2]-matrice[0][2]*matrice[1][1],
	matrice[1][2]*matrice[2][0]-matrice[1][0]*matrice[2][2],
	matrice[0][0]*matrice[2][2]-matrice[0][2]*matrice[2][0],
	matrice[0][2]*matrice[1][0]-matrice[0][0]*matrice[1][2],
	matrice[1][0]*matrice[2][1]-matrice[1][1]*matrice[2][0],
	matrice[0][1]*matrice[2][0]-matrice[0][0]*matrice[2][1],
	matrice[0][0]*matrice[1][1]-matrice[0][1]*matrice[1][0]);
	
	r=(1/determinant)*r;
	
	return r;
}

Matrix33 Matrix33::cholesky() const
{
	Matrix33 A;
	Matrix33 M(*this);
	
	for (int k=0; k<2; ++k)
	{
		A.matrice[k][k]=sqrt(M.matrice[k][k]);
		for (int s(k); s<3; ++s) A.matrice[s][k]=M.matrice[s][k]/A.matrice[k][k];
		for (int j(k); j<3; ++j)
		{
			for (int i(j-1); i<3; ++i) M.matrice[i][k]-=A.matrice[i][k]*A.matrice[j][k];
		}
	}
	
	A.matrice[2][2]=sqrt(matrice[2][2]);
	
	return A;
}
