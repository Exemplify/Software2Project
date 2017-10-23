#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cmath>
#include <vector>

using namespace std;

enum class VectorType
{
    xy = 1,
    rt
};
/**
 * @class xyVector struct
 * @brief Container structure for standardized association of the x-y-cartesian vector form.
 */
struct xyVector
{
    /**
     * @brief Default constructor for the xyVector struct.
     * @return xyVector struct by value.
     */
	xyVector() {};
    
    /**
     * @brief Constructor for the xyVector struct.
     * @param X The x value of the cartesian vector.
     * @param Y The y value of the cartesian vector.
     */
	xyVector(double X, double Y):
	x{X},
	y{Y}
	{}
    
    /**
     * @brief Simple xyVector struct equivalency operator overload. For basic struct comparison.
     * @param rhs The xyVector struct valuethat this is compared against. Used by constant reference.
     * @return boolean of the equivalency.
     */
	bool operator==(const xyVector& rhs ) const
	{
		if (x == rhs.x && y == rhs.y)
			return true;
		else
			return false;
	}
    double x;
    double y;
};

/**
 * @class rtVector struct
 * @brief Container structure for standardized association of the radius-theta-polar vector form.
 */
struct rtVector
{
    /**
     * @brief Default constructor for the rtVector struct.
     * @return rtVector struct by value.
     */
	rtVector()
	{}
    
    /**
     * @brief Constructor for the rtVector struct.
     * @param R The radius value of the polar vector
     * @param T The theta value of the polar vector
     */
	rtVector(double R, double T):
	r{R},
	t{T}
	{}
    double r;
    double t;
};

/**
 * @class Vector2D
 * @brief Defines the base mathematical element used, the Vector2D element. Contains structs of two self-contained vector types,
 * the xyVector and the rtVector. Defines the associated creation of the objects, and the logical operator overload associated
 * with vector mathematics. The tigonometric mathematical vector relationships are based on radians.
 */
class Vector2D
{
public:
    // Default Constructor
    Vector2D();
    // Scalar Constructor
    Vector2D(double val1, double val2, const VectorType& vectype = VectorType::xy);
    // Vector Constructor for xyVector
    Vector2D(const xyVector vec);
    // Vector Constructor for rtVector
    Vector2D(const rtVector vec);
    // Copy constructor
    Vector2D(const Vector2D& rhs);
    
    // cartesian position function
    /**
     * @brief Allows the xyVector struct value of the Vector2D object to be querried.
     * Fundamentally the cartesian representation of the Vector2D position.
     * @return xyVector struct.
     */
    xyVector getXYVector() const;
    
    // polar position function
    /**
     * @brief Allows the rtVector struct value of the Vector2D object to be querried.
     * Fundamentally the polar representation of the Vector2D position.
     * @return rtVector struct.
     */
    rtVector getRTVector() const;
    
    // overload operators defined
    /**
     * @brief thisVector2D = rhsVector2D:
     * The assignment operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that this must be assigned. Used by constant reference.
     * @return Vector2D of this assignment by reference.
     */
    Vector2D& operator = (const Vector2D& rhs); 
    
    /**
     * @brief thisVector2D == rhsVector2D:
     * The equivalancy operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that this is compared against. Used by constent reference.
     * @return boolean of the equivalency.
     */
    bool operator ==(const Vector2D& rhs) const;
    
    /**
     * @brief newVector2D = thisVector2D + rhsVector2D:
     * The vector addition and create operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that this is added with. Used by constant reference.
     * @return Vector2D of outcome by value.
     */
    Vector2D operator + (const Vector2D& rhs) const;
    
    /**
     * @brief newVector2D = thisVector2D - rhsVector2D:
     * The vector subtraction and create operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that this has subtracted off with. Used by constant reference.
     * @return Vector2D of outcome by value.
     */
    Vector2D operator - (const Vector2D& rhs) const;
    
    /**
     * @brief newVector2D = thisVector2D * rhsVector2D:
     * The vector multiplication and create operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that this is multiplied with. Used by constant reference.
     * @return Vector2D of outcome by value.
     */
    Vector2D operator * (const Vector2D& rhs) const;
    
    /**
     * @brief newVector2D = thisVector2D * scalar:
     * The scalar multiplication and create operator overload defined for the Vector2D class.
     * @param scalar The double value that this is multiplied with. Used by constant reference.
     * @return Vector2D of outcome by value.
     */
    Vector2D operator * (const double& scalar) const;
    
    /**
     * @brief newVector2D = thisVector2D / scalar:
     * The scalar division and create operator overload defined for the Vector2D class.
     * @param scalar The double value that this is divided with. Used by constant reference.
     * @return Vector2D of outcome by value.
     */
    Vector2D operator / (const double& scalar) const;
    
    /**
     * @brief thisVector2d = thisVector2D + rhsVector2D:
     * The vector addition and assignment operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that is added to this. Used by constant reference.
     * @return Vector2D of this as the outcome by reference.
     */
    Vector2D& operator += (const Vector2D& rhs);
    
    /**
     * @brief thisVector2D = thisVector2D - rhsVector2D:
     * The vector subtraction and assignment operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that is subtracted from this. Used by constant reference.
     * @return Vector2D of this as the outcome by reference.
     */
    Vector2D& operator -= (const Vector2D& rhs);
    
    /**
     * @brief thisVector2D = thisVector2D * rhsVector2D:
     * The vector multiplication and assignment operator overload defined for the Vector2D class.
     * @param rhs The Vector2D value that is multiplied with this. Used by constant reference.
     * @return Vector2D of this as the outcome by reference.
     */
    Vector2D& operator *= (const Vector2D& rhs);
    
    /**
     * @brief thisVector2D = thisVector2D * scalar:
     * The scalar multiplication and assignment operator overload defined for the Vector2D class.
     * @param scale The double value that is multiplied with this. Used by constant reference.
     * @return Vector2D of this as the outcome by reference.
     */
    Vector2D& operator *= (const double scale);
    
    /**
     * @brief thisVector2D = thisVector2D / scalar:
     * The scalar division and assignment operator overload defined for the Vector2D class.
     * @param scale The double value that divides this. Used by constant reference.
     * @return Vector2D of this as the outcome by reference.
     */
    Vector2D& operator /= (const double scale);
    
    // magnitude function
    /**
     * @brief Static function that calculates the vector magnitude of a Vector2D object.
     * Uses the origin as a comparative mathematical reference.
     * @param lhs The input Vector2D object being querried. Used by constant reference.
     * @return double of the vector magnitude result by value.
     */
    static double magnitude(const Vector2D& lhs);
    /**
     * @brief Static function that calculates the relative vector magnitude between two Vector2D objects.
     * @param lhs The first Vector2D object being querried. Used by constant reference.
     * @param rhs The second Vector2D object being queried. Used by constant reference.
     * @return double of the vector magnitude result by value.
     */
    static double magnitude(const Vector2D& lhs, const Vector2D& rhs);
    
    // normalize function
    /**
     * @brief Normalize function of a Vector2D object. Normalises the Vector2D object, to a unirary magnitude/radius,
     * creates a new Vector2D objectfor the returned result. This Vector2D object remains costant under query.
     * @return Vector2D of the normalized Vector2D object by value.
     */
    Vector2D normalize() const;
    
	static Vector2D origin;
	static Vector2D right;
	static Vector2D left;
	static Vector2D up;
	static Vector2D down;
    
private:
    //private variables
    xyVector _xyvec;
    rtVector _rtvec;
    
    //static variable Vector2D origin
    static double magnitude_tolerance;
    
    //private class functions
    /**
     * @brief Private function to calculate the radius from the xyVector struct, to be privately stored in the rtVector struct.
     */
    void radius();
    
    /**
     * @brief Private function to calculate the theta/angle from the xyVector struct, to be privately stored in the rtVector struct.
     */
    void theta();
    
    /**
     * @brief Private function to calculate the x-cartesian value from the rtVector struct, to be privately stored in the xyVector struct.
     */
    void xVal();
    
    /**
     * @brief Private function to calculate the y-cartesian value from the rtVector struct, to be privately stored in the xyVector struct.
     */
    void yVal();
};

#endif