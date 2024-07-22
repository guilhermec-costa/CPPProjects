#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <iomanip>
namespace gmcc {
struct Particle {
  double m_x;
  double m_y;
  double m_speed;
  double m_direction;

  Particle();
  virtual ~Particle();
  void move(const int &interval);

private:
  void init();
};
} // namespace gmcc
#endif
