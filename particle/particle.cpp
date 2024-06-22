#include "particle.h"
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
namespace gmcc {
Particle::Particle() {
  // value between -1 and 1
  m_x = (2.0 * rand() / RAND_MAX) - 1;
  m_y = (2.0 * rand() / RAND_MAX) - 1;
  m_xspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
  m_yspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
}

Particle::~Particle() {
  // TODO
}

void Particle::move() {
  m_x += m_xspeed;
  m_y += m_yspeed;

  if(m_x < -1 || m_x >= 1) {
    m_xspeed = -m_xspeed;
  }

  if(m_y <= -1 || m_y >= 1) {
    m_yspeed = -m_yspeed;
  }
}
} // namespace gmcc
