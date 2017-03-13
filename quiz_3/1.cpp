// escriba aca el comando que uso para compilar este codigo :

//

#include <cstdio>

#include <gsl/gsl_ieee_utils.h>

int main (void)

{

double d = 1.0/3.0;

float f = 2.0/3.0;

// print float

std::printf (" f=");

gsl_ieee_printf_float(&f);

std::printf ("\n");

// print double

std::printf (" d=");

gsl_ieee_printf_double(&d);

std::printf ("\n");

return 0;

}
