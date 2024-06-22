#include "particle_orchestrator.h"

namespace gmcc {
Particle_Orchestrator::Particle_Orchestrator() {
  m_p_particles = new Particle[N_PARTICLES];
}

Particle_Orchestrator::~Particle_Orchestrator() { delete[] m_p_particles; }

void Particle_Orchestrator::move_particles() {
  for(int i=0; i<N_PARTICLES; i++) {
    m_p_particles[i].move();
  }
}
} // namespace gmcc
