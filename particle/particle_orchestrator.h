#ifndef PARTICLE_ORCHESTRATOR_H_
#define PARTICLE_ORCHESTRATOR_H_
#include "particle.h"

namespace gmcc {
class Particle_Orchestrator {
private:
  Particle *m_p_particles;
  int last_iteration_time;
public:
  static const int N_PARTICLES = 5500;

public:
  Particle_Orchestrator();
  virtual ~Particle_Orchestrator();
  const Particle *const get_particles() { return m_p_particles; }
  void move_particles_based_on_elapsed(const int &elapsed);
};

} // namespace gmcc
#endif
