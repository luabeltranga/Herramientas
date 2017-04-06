//---------------------------------------------------------------------------
#include "fractal.h"

//---------------------------------------------------------------------------
// Complex Fractal Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// setIterations
// Sets the maximum number of iterations undergone by a point.
// Returns false if number of iterations is less than 1.
//---------------------------------------------------------------------------

bool ComplexFractal::setIterations ( long set )
{
    bool result = false;
    if ( iterations > 0 ) {
        iterations = set;
        result = true;
    }
    return result;
}


//---------------------------------------------------------------------------
// Mandelbrot Definitions
//---------------------------------------------------------------------------

bool Mandelbrot::setDegree ( int set )
{
    bool result = false;
    if ( set > 1 ) {
        degree = set;
        result = true;
    }
    return result;
}

//---------------------------------------------------------------------------
// getLevel
// Returns a percentage of the mazimum number of iterations required for the
// given point to tend to infinity.  A value of unity indicates the point
// never tends to infinity
//---------------------------------------------------------------------------

float Mandelbrot::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (0, 0);
    Complex c (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        z = z.pow(degree) + c;
        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Julia Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Julia object (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float Julia::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        z = z.pow(degree) + c;
        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Lambda Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Lambda object (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float Lambda::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        z = c * z * (Complex(1, 0) - z );
        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Barnsley Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Barnsley object
// (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float Barnsley::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    Complex c (x, y );
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        if ( z.real() >= 0 ) {
            z = (z-Complex(1, 0))*c;
        }
        else {
            z = (z+Complex(1, 0))*c;
        }
        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Pheonix Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Pheonix object (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float Pheonix::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    Complex c (x, y);
    Complex y1 (0, 0);
    Complex oldZ (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        oldZ = z;
        z = z.pow(degree) + Complex (c.real(), 0) + Complex ( 0, c.imag() ) * y1;
        y1 = oldZ;

        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Man-of-war Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Man-of-war object
// (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float ManOfWar::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    Complex z1 (x, y);
    Complex oldZ (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        oldZ = z;
        z = z.pow(3) + z1 + c;
        z1 = oldZ;

        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Spider Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Spider object (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float Spider::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    Complex c (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        z = z.pow(degree) + c;
        c = c/Complex(2,0) + z;

        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Sierpinski Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Sierpinski object
// (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float Sierpinski::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        if ( z.imag() > 0.5 ) {
            z = Complex ( 2*z.real(), 2*z.imag()-1 );
        }
        else if ( z.real() > 0.5 ) {
            z = Complex ( 2*z.real()-1, 2*z.imag() );
        }
        else {
            z = Complex ( 2, 0 ) * z;
        }

        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Burning Ship Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getLevel
// Same as Mandelbrot, except for a Burning Ship object
// (see Mandelbrot::getLevel)
//---------------------------------------------------------------------------

float BurningShip::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (0, 0);
    Complex c (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        z = z.pow(degree);
        z = Complex ( z.real(), fabsl(z.imag()) );
        z = z - c;

        if ( z.modulusSquared() > 4 ) {
            level = i;
            done = true;
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Newton-Raphson Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// setRoots
// Assigns the roots used in the function and derivative of this Newton-
// Raphson object.
//---------------------------------------------------------------------------

bool NewtonRaphson::setRoots ( int num, Complex *rts )
{
    bool result = true;
    numRoots = num;
    if ( numRoots < 2 ) {
        numRoots = 0;
        result = false;
    }
    else {
        if ( roots ) {
            delete [] roots;
        }
        roots = new Complex [numRoots];
        for ( int i = 0; i < numRoots; i++ ) {
            roots[i] = rts[i];
        }
    }
    return result;
}

//---------------------------------------------------------------------------
// function
// The function f(z) used in the Newton-Raphson algorithm
//---------------------------------------------------------------------------

Complex NewtonRaphson::function ( Complex z )
{
    Complex result (1, 0);
    for ( int i = 0; i < numRoots; i++ ) {
        result = result * (z - roots[i]);
    }
    return result;
}

//---------------------------------------------------------------------------
// function
// The derivative of the function f(z) used in the Newton-Raphson algorithm.
//---------------------------------------------------------------------------

Complex NewtonRaphson::derivative ( Complex z )
{
    Complex result (0, 0);
    Complex part;
    for ( int i = 0; i < numRoots; i++ ) {
        part = Complex (1, 0);
        for ( int j = 0; j < numRoots; j++ ) {
            if ( i != j ) {
                part = part * (z - roots[j]);
            }
        }
        result = result + part;
    }
    return result;
}

//---------------------------------------------------------------------------
// getRoots
// Returns the roots currently defined for the function.
//---------------------------------------------------------------------------

void NewtonRaphson::getRoots ( Complex *rts )
{
    if ( roots ) {
        for ( int i = 0; i < numRoots; i++ ) {
            rts[i] = roots[i];
        }
    }
}

//---------------------------------------------------------------------------
// getLevel
// Similar to Mandelbrot.  Returns the percentage of the maximum number of
// iterations required for the given point to converge to one of the
// supplied roots.
//---------------------------------------------------------------------------

float NewtonRaphson::getLevel ( long double x, long double y )
{
    bool done = false;
    Complex z (x, y);
    int level = iterations;

    for ( int i = 0; (i < iterations && !done); i++ ) {
        z = z - function(z)/derivative(z);
        for ( int j = 0; j < numRoots; j++ ) {
            if ( roots[j].real()-tolerance < z.real() &&
                roots[j].real()+tolerance > z.real() &&
                roots[j].imag()-tolerance < z.imag() &&
                roots[j].imag()+tolerance > z.imag() ) {
                level = i;
                done = true;
            }
        }
    }

    return (float)level/(float)iterations;
}

//---------------------------------------------------------------------------
// Attractor Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Lorenz Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// getNextPoint
// Returns the next point in the Lorenz orbit given a starting point <x,y,z>
//---------------------------------------------------------------------------

void Lorenz::getNextPoint ( long double *x, long double *y, long double *z )
{
    double x0, y0, z0;
    x0 = *x;
    y0 = *y;
    z0 = *z;

    *x = x0 + stepSize * a * (y0 - x0);
    *y = y0 + stepSize * (x0 * (b - z0) - y0);
    *z = z0 + stepSize * (x0 * y0 - c * z0);
}

//---------------------------------------------------------------------------
// getNextPoint
// Returns the next point in the Duffing orbit given a starting point <x,y,z>
//---------------------------------------------------------------------------

void Duffing::getNextPoint ( long double *x, long double *y, long double *z )
{
    double x0, y0, z0;
    x0 = *x;
    y0 = *y;
    z0 = *z;

    *x = x0 + stepSize * y0;
    *y = y0 + stepSize * (x0 - x0*x0*x0 - a*y0 + b*cos (c*z0*(stepSize)));
    (*z)++;
}

//---------------------------------------------------------------------------
// getNextPoint
// Returns the next point in the Rossler orbit given a starting point <x,y,z>
//---------------------------------------------------------------------------

void Rossler::getNextPoint ( long double *x, long double *y, long double *z )
{
    double x0, y0, z0;
    x0 = *x;
    y0 = *y;
    z0 = *z;

    *x = x0 + stepSize * ( -y0 - x0);
    *y = y0 + stepSize * (x0 + a*y0);
    *z = z0 + stepSize * (b + z0) * (x0 - c);
}

//---------------------------------------------------------------------------
// getNextPoint
// Returns the next point in the HopALong orbit given a starting point
// <x,y,z>
//---------------------------------------------------------------------------

void HopAlong::getNextPoint ( long double *x, long double *y, long double *z )
{
    double x0, y0;
    x0 = *x;
    y0 = *y;

    *x = y0 - (x0 > 0 ? 1 : (x0 < 0 ? -1 : 0))*sqrt(fabsl(b*x0-c));

    *y = a - x0;
}

//---------------------------------------------------------------------------
// PlasmaFractal Definitions
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// generate
// Creates the plasma cloud using the Diamond-Square algorithm of generation
//---------------------------------------------------------------------------

void PlasmaFractal::generate ( int w, int h )
{
    bool done = false;
    float max, min;
    int pow = 0, side, no;
    float rough;

    size = 1;

    for ( int i = 0; (i < 100 && !done); i++ ) {
        size <<= 1;
        pow++;
        if ( w <= size && h <= size ) {
            done = true;
        }
    }
    size++;

    if ( field ) {
        delete [] field;
    }

    field = new float[size*size];
    field[0] = getRand();
    field[size-1] = getRand();
    field[size*(size-1)] = getRand();
    field[size*(size-1)+size-1] = getRand();

    side = size-1;
    no = 1;
    rough = roughness;
    makeDiamond ( 0, 0, side, rough );
    makeSquare ( 0, 0, side, rough );

    for ( int i = 0; i < pow; i++ ) {
        side >>= 1;
        no <<= 1;
        for ( int j = 0; j < no; j++ ) {
            for ( int k = 0; k < no; k++ ) {
                makeDiamond ( j*side, k*side, side, rough );
                makeSquare ( j*side, k*side, side, rough );
            }
        }
        rough *= roughness;
    }

    max = field[0];
    min = field[0];
    for ( int i = 0; i < size*size; i++ ) {
        if ( field[i] > max ) {
            max = field[i];
        }
        if ( field[i] < min ) {
            min = field[i];
        }
    }
    for ( int i = 0; i < size*size; i++ ) {
        field[i] = (field[i]-min)/(max-min);
    }
}


//---------------------------------------------------------------------------
// makeSquare
// The Square step of the Diamond-Square Algorithm
//---------------------------------------------------------------------------

void PlasmaFractal::makeSquare ( int x, int y, int side, float rough )
{
	int mx, my;
    if ( side != 1 ) {
        mx = x + side/2;
        my = y + side/2;

    	// West
        field[my*size+x] = (field[y*size+x] + field[(y+side)*size+x]
                                        + field[my*size+mx] ) / 3.0
                                        + getRand() * rough;
        // North
        field[y*size+mx] = (field[y*size+x] + field[y*size+x+side]
                                        + field[my*size+mx] ) / 3.0
                                        + getRand() * rough;
        // East
        field[my*size+x+side] = (field[y*size+x+side] +
                                        field[(y+side)*size+x+side] +
                                        field[my*size+mx] ) / 3.0
                                        + getRand() * rough;
        // South
        field[(y+side)*size+mx] = (field[(y+side)*size+x+side] +
                                        field[(y+side)*size+x] +
                                        field[my*size+mx] ) / 3.0
                                        + getRand() * rough;
    }
}

//---------------------------------------------------------------------------
// makeDiamond
// The Diamond step of the Diamond-Square Algorithm
//---------------------------------------------------------------------------

void PlasmaFractal::makeDiamond ( int x, int y, int side, float rough )
{
	int mx, my;
    if ( side != 1 ) {
        mx = x + side/2;
        my = y + side/2;
        field[my*size+mx] = ( field[y*size+x] + field[y*size+x+side] +
                                    field[(y+side)*size+x] +
                                    field[(y+side)*size+x+side] ) / 4.0 +
                                    getRand() * rough;
    }
}

