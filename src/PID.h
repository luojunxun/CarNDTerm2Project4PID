#ifndef PID_H
#define PID_H

class PID {
public:
  /* Errors */
  double p_error;
  double i_error;
  double d_error;
  double error_prev;

  /* Coefficients */ 
  double Kp;
  double Ki;
  double Kd;

  /* Limits of error, integrator and total*/
  double lim_up_error;
  double lim_lo_error;
  double lim_up_i;
  double lim_lo_i;
  double lim_up_total;
  double lim_lo_total;

  /* Constructor */
  PID();

  /* Destructor */
  virtual ~PID();

  /* Initialize PID */
  void Init(double Kp, double Ki, double Kd, double lim_up_error, double lim_lo_error, double lim_up_i, double lim_lo_i, double lim_up_total, double lim_lo_total);

  /* Update the PID error variables given cross track error */
  void UpdateError(double error);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  void UpperLowerLimits(double &x, double upper, double lower);
};

#endif /* PID_H */
