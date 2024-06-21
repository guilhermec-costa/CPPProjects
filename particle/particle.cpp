#include "particle.h"
#include <cstdlib>
#include <stdlib.h>
namespace gmcc {
Particle::Particle() {
  // value between -1 and 1
  m_x = (2.0 * rand() / RAND_MAX) - 1;
  m_y = (2.0 * rand() / RAND_MAX) - 1;
}

Particle::~Particle() {
  // TODO    
}
} // namespace gmcc
