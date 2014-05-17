#ifndef SIMCONSTANTS_H
#define	SIMCONSTANTS_H

static const float
	TIMESTEP = .01,
	FLIP_PERCENT = .95,			//Weight to give FLIP update over PIC
	CRIT_COMPRESS = .975,		//Fracture threshold for compression
	CRIT_STRETCH = 1.0075,		//Fracture threshold for stretching
	HARDENING = 10,				//How much plastic deformation strengthens material
	DENSITY = 240,				//Density of snow in kg/m^3 (Stomakhin suggests 400, I'm adjusting for 2D)
	YOUNGS_MODULUS = 1.4e5,		//Young's modulus (springiness)
	POISSONS_RATIO = .2;		//Poisson's ratio (transverse/axial strain ratio)

#endif
