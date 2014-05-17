#ifndef PARTICLE_H
#define	PARTICLE_H

#include <cmath>
#include "SimConstants.h"
#include "Vector2f.h"
#include "Matrix2f.h"

class Particle {
public:
	float volume, mass, density;
	Vector2f position, velocity;
	Matrix2f velocity_gradient;
	//Lame parameters (_s denotes starting configuration)
	float lambda_s, lambda, mu_s, mu;
	//Deformation gradient (elastic and plastic parts)
	Matrix2f def_elastic, def_plastic;
	//Cached SVD's for elastic deformation gradient
	Matrix2f svd_w, svd_v;
	Vector2f svd_e;
	//Cached determinants
	float det_elastic, det_plastic;
	//Grid interpolation weights
	Vector2f grid_position;
	Vector2f weight_gradient[16];
	float weights[16];

	Particle();
	Particle(const Vector2f& pos, const Vector2f& vel, float mass, float lambda, float mu);
	virtual ~Particle();

	//Update position, based on velocity
	void updatePos();
	//Update deformation gradient
	void updateGradient();
	//Compute stress force; call after updateSVD() and updateDet()
	Matrix2f stressForce();
};

#endif
