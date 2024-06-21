#ifndef PARTICLE_ORCHESTRATOR_H_
#define PARTICLE_ORCHESTRATOR_H_
#include "particle.h"

namespace gmcc {
class Particle_Orchestrator {
private:
  Particle *m_p_particles;

public:
  static const int N_PARTICLES = 4000;

public:
  Particle_Orchestrator();
  virtual ~Particle_Orchestrator();
  const Particle *const get_particles() { return m_p_particles; }
};

} // namespace gmcc
#endif
