/** 
 * @file VecnD.h
 * Définit un vecteur 3D générique.
 */

#ifndef _VecnD_H
#define _VecnD_H

#include <cassert>
#include <cmath>
#include <ostream>
#include <istream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <boost/tokenizer.hpp>
#include "../GUI/wxIncludes"
#include "../GUI/Conversions.h"

// Ce define est supprimé à la fin du fichier
#define __VecnD__EPSILON__ 1e-10

typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

/**  Vecteur générique à n dimensions.
 * Représente un vecteur de n scalaires du type spécifié. 
 * @remarks Il existe des types prédéfinis: #VecnDd, #VecnDi, etc.
 */
template <class T> 
class VecnD
{
private:
    
protected:
    
	std::vector<T> coordinates;
    
public:
    
    typedef typename std::vector<T>::size_type size_type;
    
    /** Constructeur par défaut.
     * Initialise les coordonnées à (0,0,0). */
    VecnD(int n = 3) : coordinates(n, T(0))
    {
        
    }
    
	/** Constructeur de copie.
     * @param[in] src Vecteur à partir duquel effectuer la copie. */
	VecnD(const VecnD& src) : coordinates(src.coordinates)
	{
		
	}
    
	/** Constructeur surchargé.
     * Prend deux valeurs en argument.
     * @param[in] x Coordonnée en x.
     * @param[in] y Coordonnée en y.*/
	VecnD(const T& x, const T& y) : coordinates(0)
	{
		coordinates.push_back(x);
		coordinates.push_back(y);
	}
	/** Constructeur surchargé.
     * Prend trois valeurs en argument.
     * @param[in] x Coordonnée en x.
     * @param[in] y Coordonnée en y.
     * @param[in] z Coordonnée en z. */
	VecnD(const T& x, const T& y, const T& z) : coordinates(0)
	{
		coordinates.push_back(x);
		coordinates.push_back(y);
		coordinates.push_back(z);
	}
	
	/** Constructeur surchargé.
     * Prend une chaîne de la forme (x1,x2,...xn) comme argument */
	VecnD(std::string s)
	{
		assert(s.size()>2 && s[0]=='(' && s[s.size()-1]==')');
		std::string t(s.substr(1,s.size()-2));
		tokenizer tokens(t, boost::char_separator<char>(","));
		for (tokenizer::iterator tok_iter = tokens.begin(); tok_iter != tokens.end(); ++tok_iter)
		{
			std::istringstream i(*tok_iter); T r; i >> r;
			addComponent(r);
		}
	}
	
	void addComponent(const T& c)
	{
		coordinates.push_back(c);
	}
	
	/** Opérateur d'indexation.
     * Récupère la valeur d'une composante.
     * @param[in] index Index de la composante à récupérer.
     * @return La composante spécifiée. */
	const T& operator[](const size_type index) const {
		assert(index<coordinates.size());
		return coordinates[index];
	}
    
	/** Opérateur d'indexation.
     * Affecte une valeur à une composante.
     * @param[in] index Index de la composante à affecter.
     * @return La composante spécifiée. */
	T& operator[](const size_type index) {
		assert(index<coordinates.size());
		return coordinates[index];
	}
	
	/* Méthodes */
    
	/** Dimension.
     * @return La dimension du vecteur. */
	size_type dim() const
	{
		return coordinates.size();
	}
	/** Normalise le vecteur.
     * @return La longueur précédente du vecteur. 
     * @remarks Le type des composantes reste le même, attention si ce sont des entiers,
     * utiliser #normalized plutôt. */
	double normalize() {
		double l(length());
		if(l>__VecnD__EPSILON__) for (size_type i(0); i<dim(); ++i) coordinates[i]=T(coordinates[i]/l);
		return l;
	}
    
	/** Retourne la longueur du vecteur.
     * @return La longueur actuelle du vecteur. */
	double length() const {
		return sqrt(lengthsquared());
	}
	
	/** Retourne la longueur du vecteur au carré.
     * @return La longueur actuelle du vecteur au carré. */
	double lengthsquared() const {
		return (double)std::inner_product(coordinates.begin(), coordinates.end(), coordinates.begin(), 0.0, std::plus<double>(), std::multiplies<double>());
	}
	
	/** Retourne un vecteur colinéaire normalisé.
     * @return Un vecteur unitaire colinéaire. */
	VecnD normalized() const {
		VecnD res(*this);
		res.normalize();
		return res;
	}
	
	/** Retourne le produit vectoriel de deux vecteurs (main droite).
     * @param[in] v Le deuxième vecteur (this x v).
     * @return Le produit vectoriel dans l'ordre: this cross argument. */
	VecnD crossP(const VecnD& v) const {
		assert(dim()==3);
		return operator^(*this,v);
	}
    
	/* OPERATEURS INTERNES */
    
	/** Opérateur d'affectation. */
	VecnD& operator=(const VecnD& right) {
		assert(this != &right);
		coordinates = right.coordinates;
		return (*this);
	}
    
	/** Opérateur d'addition avec assignation. */
	VecnD& operator+=(const VecnD& right) {
		for (size_type i(0); i<dim(); ++i) coordinates[i]+=right[i];
		return (*this);
	}
    
	/** Opérateur de soustraction avec assignation. */
	VecnD& operator-=(const VecnD& right) {
		for (size_type i(0); i<dim(); ++i) coordinates[i]-=right.coordinates[i];
		return (*this);
	}
    
	/** Opérateur de multiplication par un scalaire avec assignation. */
	VecnD& operator*=(const T& scalar) {
		for (size_type i(0); i<dim(); ++i) coordinates[i]*=scalar;
		return (*this);
	}
    
	/** Opérateur de division par un scalaire avec assignation. */
	VecnD& operator/=(const T& scalar) {
		assert(std::fabs(scalar-T(0))>0);
		for (size_type i(0); i<dim(); ++i) coordinates[i]/=scalar;
		return (*this);
	}
	
    
	/* OPERATEURS EXTERNES */
    
	/* Opérateurs binaires */
    
	/** Produit scalaire de deux vecteurs
     * @param[in] left Le vecteur de gauche.
     * @param[in] right Le vecteur de droite.
     * @return La valeur du produit scalaire. */
	friend T operator*(const VecnD& left, const VecnD& right)
	{
		return std::inner_product(left.coordinates.begin(), left.coordinates.end(), right.coordinates.begin(), T(0));
	}
    
	/** Somme vectorielle */
	friend VecnD operator+(const VecnD& left, const VecnD& right)
	{
		assert(left.dim()==right.dim());
		VecnD v(left);
		std::transform(v.coordinates.begin(),v.coordinates.end(), right.coordinates.begin(), v.coordinates.begin(), std::plus<T>());
		return v;
	}
    
	/** Différence vectorielle */
	friend VecnD operator-(const VecnD& left, const VecnD& right)
	{
		assert(left.dim()==right.dim());
		VecnD v(left);
		std::transform(v.coordinates.begin(),v.coordinates.end(), right.coordinates.begin(), v.coordinates.begin(), std::minus<T>());
		return v;
	}
    
	/** Produit externe.
     * @param[in] scalar Un scalaire.
     * @param[in] vec Un vecteur.
     * @return Produit externe scalaire*vecteur. */
	friend VecnD operator*(const T& scalar, const VecnD& vec)
	{
		VecnD v(static_cast<int>(vec.dim()));
		for (size_type i(0); i<vec.dim(); ++i) v.coordinates[i]=scalar*vec.coordinates[i];
		return v;
	}
    
	/** Produit externe.
     * @param[in] vec Un vecteur.
     * @param[in] scalar Un scalaire.
     * @return Produit externe vecteur*scalaire. */
	friend VecnD operator*(const VecnD& vec, const T& scalar)
	{
		return operator*(scalar, vec);
	}
    
	/** Division externe.
     * @param[in] vec Un vecteur.
     * @param[in] scalar Un scalaire.
     * @return Division externe vecteur/scalaire.
     * @remarks On ne définit pas le produit externe scalaire/vecteur qui n'a pas de sens. */
	friend VecnD operator/(const VecnD& vec, const T& scalar)
	{
		assert(scalar > __VecnD__EPSILON__);
		return operator*(vec, 1/scalar);
	}
    
	/** Produit vectoriel
     * @param[in] left Un vecteur.
     * @param[in] right Un scalaire.
     * @return produit vectoriel  externe left ^ right
     */
	friend VecnD operator^(const VecnD& left, const VecnD& right)
	{
		assert(left.dim()==3 && left.dim()==right.dim());
		VecnD v(3);
		for(unsigned int i(0); i<3; ++i) v[i]=(left[(i+1)%3]*right[(i+2)%3]-left[(i+2)%3]*right[(i+1)%3]);
		return v;
	}
    
	/* Opérateurs logiques */
    
	/** Opérateur d'égalité.
     * Compare les composantes respectives entre deux vecteurs.
     * @return vrai si toutes les composantes sont identiques. */
	friend bool operator==(const VecnD& left, const VecnD& right)
	{
		if (left.dim()!=right.dim()) return false;
		
		for (size_type i(0); i<left.dim(); ++i) if (left.coordinates[i] - right.coordinates[i] > __VecnD__EPSILON__) return false;
		return true;
	}
    
	/** Opérateur de différence logique.
     * @return faux si toutes les composantes sont identiques. */
	friend bool operator!=(const VecnD& left, const VecnD& right)
	{
		return !operator==(left,right);
	}
    
	/** Opérateur d'infériorité stricte sur les normes. */
	friend bool operator<(const VecnD& left, const VecnD& right)
	{
		return left.length() < right.length();
	}
	
	/** Opérateur d'infériorité sur les normes. */
	friend bool operator<=(const VecnD& left, const VecnD& right)
	{
		return left.length() <= right.length();
	}
    
	/** Opérateur de supériorité stricte sur les normes. */
	friend bool operator>(const VecnD& left, const VecnD& right)
	{
		return left.length() > right.length();
	}
    
	/** Opérateur de supériorité sur les normes. */
	friend bool operator>=(const VecnD& left, const VecnD& right)
	{
		return left.length() >= right.length();
	}
    
	/** Ecriture dans un flot de sortie. */
	friend std::ostream& operator<<(std::ostream& stream, const VecnD& vec)
	{
		stream<<"(";
		for (size_type i(0); i<vec.dim(); ++i)
		{
			stream<<vec.coordinates[i];
			if (i<vec.dim()-1) stream<<',';
		}
		stream<<')';
		return stream;
	}
    
     //Lecture depuis un flot d'entrée.
     friend std::istream& operator>>(std::istream& stream, VecnD& vec)
     {
		 char d(0);
		 stream >> d >> vec._x >> d >> vec._y >> d >> vec._z >> d;
		 return stream;
     }
     
	/* Opérateurs unaires */
	
	/** Opérateur moins unaire.
     * Inverse le signe des composantes d'un vecteur.
     * @param[in] vec Un vecteur.
     * @return Un nouveau vecteur avec les composantes de signe opposé. */
	friend VecnD operator-(const VecnD& vec)
	{
		return operator*(vec,-1);
	}
	
	void draw(VecnD position) const
    {
        glBegin(GL_LINES);
        glVertex3d(position[0],position[1],position[2]);
        glVertex3d(coordinates[0]+position[0],coordinates[1]+position[1],coordinates[2]+position[2]);
        glEnd();
    }
};

typedef VecnD<signed long>      VecnDl;
typedef VecnD<unsigned long>	VecnDul;
typedef VecnD<signed int>       VecnDi; 
typedef VecnD<unsigned int>     VecnDui;
typedef VecnD<signed short>     VecnDs; 
typedef VecnD<unsigned short>	VecnDus;
typedef VecnD<signed char>      VecnDb; 
typedef VecnD<unsigned char>	VecnDub;
typedef VecnD<float>            VecnDf; 
typedef VecnD<double>           VecnDd; 

#undef __VecnD__EPSILON__

#endif
