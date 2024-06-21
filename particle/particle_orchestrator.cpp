#include "particle_orchestrator.h"

namespace gmcc {
Particle_Orchestrator::Particle_Orchestrator() {
  m_p_particles = new Particle[N_PARTICLES];
}

Particle_Orchestrator::~Particle_Orchestrator() { delete[] m_p_particles; }
} // namespace gmcc
