#include "particle.h"
#include <cmath>
#include <cstdlib>
#include <stdlib.h>
namespace gmcc {
Particle::Particle() : m_x(0), m_y(0) {
  this->init();
}

Particle::~Particle() {
  // TODO
}

void Particle::init() {
  m_x = 0;
  m_y = 0;
  m_direction = (2 * M_PI * rand()) / RAND_MAX;
  m_speed = (0.03 * rand()) / RAND_MAX;
  m_speed *= m_speed;
}

void Particle::move(const int &interval) {

  m_direction += interval * 0.0003;
  double x_speed = m_speed * cos(m_direction);
  double y_speed = m_speed * sin(m_direction);

  m_x += x_speed * interval;
  m_y += y_speed * interval;

  if(m_x < -1 || m_x > 1 || m_y < -1  || m_y > 1) {
    this->init();
  }

  if(rand() < RAND_MAX/100) {
    this->init();
  }
}
} // namespace gmcc
