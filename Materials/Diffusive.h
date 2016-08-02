#ifndef __DIFFUSIVE_H__
#define __DIFFUSIVE_H__


#include "Material.h"

class Diffusive : public Material
{
public :

	double diffuseCoefficient;

	Diffusive();
	Diffusive(Texture* albedo_, const double& dc);

	Ray scatter(const ShadeRec& sr) const;
	virtual double getDiffuseCoefficiency() const;
};

#endif
