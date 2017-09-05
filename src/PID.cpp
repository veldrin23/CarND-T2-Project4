#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
	firstIteration = true;
}

void PID::UpdateError(double cte) {
	if(firstIteration) {
		cte_old = cte;
		time_old = std::clock();
		firstIteration = false;
	}

	time = std::clock();
	p_error = -Kp *cte;

	delta_cte = cte - cte_old;
	delta_time = (time- time_old)*1.0f/CLOCKS_PER_SEC;

	if (delta_time < 0.00001) {
        d_error = 0;
    } else {
        d_error = -Kd * delta_cte / delta_time;
    }

    cte_old = cte;
    time_old = time;

    sum_cte += cte;
    i_error = -Ki * sum_cte;
}

double PID::TotalError() {
	return p_error + d_error + i_error;
}

