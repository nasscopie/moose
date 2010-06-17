#include "Material.h"

#ifndef EXAMPLEMATERIAL_H
#define EXAMPLEMATERIAL_H

//Forward Declarations
class ExampleMaterial;

template<>
InputParameters validParams<ExampleMaterial>();

/**
 * Example material class that defines a few properties.
 */
class ExampleMaterial : public Material
{
public:
  ExampleMaterial(std::string name,
                  MooseSystem & moose_system,
                  InputParameters parameters);

protected:
  virtual void computeProperties();

private:
  Real _input_diffusivity;

  /**
   * Create two MooseArray Refs to hold the current
   * and previous material properties respectively
   */
  MooseArray<Real> & _diffusivity;
  MooseArray<Real> & _diffusivity_old;
};

#endif //EXAMPLEMATERIAL_H
