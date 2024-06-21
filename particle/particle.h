#ifndef PARTICLE_H_
#define PARTICLE_H_
namespace gmcc {
struct Particle {
  double m_x;
  double m_y;

public:
  Particle();
  virtual ~Particle();
};
} // namespace gmcc
#endif
