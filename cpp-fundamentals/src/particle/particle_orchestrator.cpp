#include "particle_orchestrator.h"

namespace gmcc {
Particle_Orchestrator::Particle_Orchestrator(): last_iteration_time(0)  {
  m_p_particles = new Particle[N_PARTICLES];
}

Particle_Orchestrator::~Particle_Orchestrator() { delete[] m_p_particles; }

void Particle_Orchestrator::move_particles_based_on_elapsed(const int &elapsed) {
  int interval = last_iteration_time - elapsed;
  for(int i=0; i<N_PARTICLES; i++) {
    m_p_particles[i].move(interval);
  }
  last_iteration_time = elapsed;
}
} // namespace gmcc
