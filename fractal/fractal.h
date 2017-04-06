//---------------------------------------------------------------------------
#include "complex.h"
#include <math.h>

#ifndef fractalH
#define fractalH

//---------------------------------------------------------------------------
// ComplexFractal
//
// Base class for Newton Raphson Basins, Mandelbrot sets, and all subsets
// thereof.
//---------------------------------------------------------------------------

class ComplexFractal {
    public:
        ComplexFractal () {
            iterations = 50;        // Default # of iterations
        }

        // Sets the maximum number of iterations
        bool setIterations ( long set );

        // Return the maximum number of iterations currently used in this
        // fractal
        long getIterations ( void ) {
            return iterations;
        }
    protected:
        long iterations;            // maximum number of iterations
};

//---------------------------------------------------------------------------
// Attractor
//
// Base class for strange attractors, such as Lorenz.
//---------------------------------------------------------------------------

class Attractor {
    public:
        Attractor () {
            stepSize = 0.001;           // Default precision
            noPoints = 100000;		// Default number of plotted points
        }

	// Sets the parameters a, b, and c.  Their use depends on which
	// 
        virtual void setParameters ( long double a, long double b,
            long double c ) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        virtual void getParameters ( long double *a, long double *b,
            long double *c ) {
            *a = this->a;
            *b = this->b;
            *c = this->c;
        }
        virtual long double getStepSize ( void ) { return stepSize; }
        virtual void setStepSize ( long double set ) { stepSize = set; }
        long getNumPoints ( void ) {
            return noPoints;
        }
        bool setNumPoints ( long set ) {
            bool result = false;
            if ( set > 0 ) {
                noPoints = set;
                result = true;
            }
            return result;
        }
        virtual void getNextPoint ( long double *x, long double *y,
            long double *z ) = 0;
    protected:
        long double a, b, c;
        long double stepSize;
        long noPoints;
};


//---------------------------------------------------------------------------
// Mandelbrot
//
// Encapsulates the functionality of a Mandelbrot set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class Mandelbrot : public ComplexFractal {
    public:
        Mandelbrot () {
            iterations = 100;       // More iterations for Mandelbrot set
            degree = 2;             // Default quadratic mandelbrot
        }
        // Sets the degree 'n' used in the recursive function z -> z^n + c
        bool setDegree ( int set );

        // Returns the current degree
        int getDegree ( void ) {
            return degree;
        }

        // Core function of Mandelbrot.
        virtual float getLevel ( long double x, long double y );

    protected:
        int degree;		    // power 'n' of expression z -> z^n +c
};


//---------------------------------------------------------------------------
// Julia
//
// Encapsulates the functionality of a Julia set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class Julia : public Mandelbrot {
    public:
        Julia () {
            iterations = 20;
            c = Complex ( 0, 1 );
        }
        virtual float getLevel ( long double x, long double y );
        void setConstant ( Complex con ) {
            c = con;
        }
        Complex getConstant ( void ) {
            return c;
        }
    protected:
        Complex c;
};

//---------------------------------------------------------------------------
// Lambda
//
// Encapsulates the functionality of a Lambda set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class Lambda : public Julia {
    public:
        Lambda () {
            iterations = 100;
            c = Complex ( 0.2, 1 );
        }
        virtual float getLevel ( long double x, long double y );
};

//---------------------------------------------------------------------------
// Barnsley
//
// Encapsulates the functionality of a Barnsley set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class Barnsley : public Mandelbrot {
    public:
        Barnsley () {
            iterations = 50;
        }
        virtual float getLevel ( long double x, long double y );
};

//---------------------------------------------------------------------------
// Pheonix
//
// Encapsulates the functionality of a Pheonix set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class Pheonix : public Mandelbrot {
    public:
        Pheonix () : Mandelbrot () {}
        virtual float getLevel ( long double x, long double y );
};

//---------------------------------------------------------------------------
// Spider
//
// Encapsulates the functionality of a Spider set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class Spider : public Mandelbrot {
    public:
        Spider () : Mandelbrot () {}
        virtual float getLevel ( long double x, long double y );
};

//---------------------------------------------------------------------------
// ManOfWar
//
// Encapsulates the functionality of a Man o' War set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class ManOfWar : public Julia {
    public:
        ManOfWar () {
            iterations = 50;
            c = Complex (0, 0);
        }
        virtual float getLevel ( long double x, long double y );
};

//---------------------------------------------------------------------------
// Sierpinski
//
// Encapsulates the functionality of a Sierpinski set.  Based on the supplied
// iterations and degree, getLevel will return a value for a complex point 'z'
//---------------------------------------------------------------------------

class Sierpinski : public Mandelbrot {
    public:
        Sierpinski () {
            iterations = 50;
        }
        virtual float getLevel ( long double x, long double y );
};

//---------------------------------------------------------------------------
// BurningShip
//
// Encapsulates the functionality of a Burning Ship set.  Based on the
// supplied iterations and degree, getLevel will return a value for a
// complex point 'z'
//---------------------------------------------------------------------------

class BurningShip : public Mandelbrot {
    public:
        BurningShip () {
            iterations = 50;
        }
        virtual float getLevel ( long double x, long double y );
};

//---------------------------------------------------------------------------
// NewtonRaphson
//
// Encapsulates the functionality of a Burning Ship set.  Based on the
// supplied iterations and degree, getLevel will return a value for a
// complex point 'z'
//---------------------------------------------------------------------------

class NewtonRaphson : public ComplexFractal {
    public:
        NewtonRaphson () {
            tolerance = 0.000002;
            iterations = 50;
            numRoots = 3;
            roots = new Complex[numRoots];
            roots[0] = Complex ( 1, 0 );
            roots[1] = Complex ( -0.5, sqrt(3)/2 );
            roots[2] = Complex ( -0.5, -sqrt(3)/2 );
        }
        int getNumRoots ( void ) {
            return numRoots;
        }
        bool setRoots ( int num, Complex *rts );
        void getRoots ( Complex *rts );
        virtual float getLevel ( long double x, long double y );
    protected:
        Complex function ( Complex z );
        Complex derivative ( Complex z );
        Complex *roots;
        long double tolerance;
        int numRoots;
};


//---------------------------------------------------------------------------
// Lorenz
//
// Encapsulates the functionality of a Lorenz attractor.  Returns the points
// of the orbit in succession.
//---------------------------------------------------------------------------

class Lorenz : public Attractor {
    public:
        Lorenz () : Attractor() {
            a = 10;
            b = 28;
            c = 10.0/3.0;
        }
        virtual void getNextPoint ( long double *x, long double *y,
            long double *z );
};

//---------------------------------------------------------------------------
// Rossler
//
// Encapsulates the functionality of a Rossler attractor.  Returns the points
// of the orbit in succession.
//---------------------------------------------------------------------------

class Rossler : public Attractor {
    public:
        Rossler () : Attractor() {
            a = 0.2;
            b = 0.2;
            c = 5.7;
        }
        virtual void getNextPoint ( long double *x, long double *y,
            long double *z );
};

//---------------------------------------------------------------------------
// Duffing
//
// Encapsulates the functionality of a Duffing attractor.  Returns the points
// of the orbit in succession.
//---------------------------------------------------------------------------

class Duffing : public Attractor {
    public:
        Duffing () : Attractor() {
            a = 0.25;
            b = 0.3;
            c = 1.0;
        }
        virtual void getNextPoint ( long double *x, long double *y,
            long double *z );
};

//---------------------------------------------------------------------------
// HopAlong
//
// Encapsulates the functionality of a HopAlong attractor.  Returns the points
// of the orbit in succession.
//---------------------------------------------------------------------------

class HopAlong : public Attractor {
    public:
        HopAlong () : Attractor() {
            a = 0.25;
            b = 0.3;
            c = 1.0;
        }
        virtual void getNextPoint ( long double *x, long double *y,
            long double *z );
};


//---------------------------------------------------------------------------
// PlasmaFractal
//
// Encapsulates the functionality of a Plasma Cloud fractal.  Generates a
// plasma cloud and returns the colour of the point (x,y) in the cloud
//---------------------------------------------------------------------------

class PlasmaFractal {
    public:
        PlasmaFractal () {
            roughness = 0.6;
        }
        void setRoughness ( long double set ) {
            roughness = set;
        }
        long double getRoughness ( void ) {
            return roughness;
        }
        virtual float getLevel ( int x, int y ) {
            return field[y*size+x];
        }
        float getRand ( void ) {
            return random ( 20000 )/10000.0 - 1.0;
        }

        void generate ( int w, int h );
        void makeSquare ( int x, int y, int side, float rough );
        void makeDiamond ( int x, int y, int side, float rough );
        ~PlasmaFractal () {
            delete [] field;
        }

    private:
        long double roughness;
        float *field;
        int size;
};
//---------------------------------------------------------------------------
#endif
