class Vecteur2D
{
public:
double x,y;

inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

inline Vecteur2D(const char * s);
inline const Vecteur2D operator + (const Vecteur2D & u) const;
inline const Vecteur2D operator * (const double & a) const;
inline const Vecteur2D operator - () const;

operator string() const;
}; // classe Vecteur2D

