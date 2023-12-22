#ifndef ULTRASONIC_H
#define ULTRASONIC_H

class ultrasonic{
  public:
    ultrasonic();
    double get_distance();
  private:
    long duration;
    long distance;
};

#endif