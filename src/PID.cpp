#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd, double lim_up_error, double lim_lo_error, double lim_up_i, double lim_lo_i, double lim_up_total, double lim_lo_total) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = 0.0;
	d_error = 0.0;
	i_error = 0.0;
	error_prev = 0.0;

	this->lim_up_error = lim_up_error;
	this->lim_lo_error = lim_lo_error;
	this->lim_up_i = lim_up_i;
	this->lim_lo_i = lim_lo_i;
	this->lim_up_total = lim_up_total;
	this->lim_lo_total = lim_lo_total;
}

void PID::UpdateError(double error) {
	UpperLowerLimits(error, lim_up_error, lim_lo_error); //Set upper/lower limits of error
	p_error = error;
	d_error = error - error_prev;
	i_error += error;
	error_prev = error;
	UpperLowerLimits(i_error, lim_up_i, lim_lo_i); // Set upper/lower limits of i_error
}

double PID::TotalError() {
	double totalError = Kp * p_error + Kd * d_error + Ki * i_error;
	UpperLowerLimits(totalError, lim_up_total, lim_lo_total);
	return totalError;
}

void PID::UpperLowerLimits(double &x, double upper, double lower) {
	// Set upper/lower limits of x
	if (upper < lower) {
		return;
	}
	
	if (x > upper) {
		x = upper;
	}
	else if (x < lower) {
		x = lower;
	}
}

