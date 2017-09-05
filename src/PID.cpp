#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	Kp = Kp;
	Ki = Ki;
	Ki = Ki;
	firstIteration = true;
}

void PID::UpdateError(double cte) {
	if(firstIteration) {
		cte_old = cte;
		time_old = std::clock();
		firstIteration = false;
	}

	time = std::clock();
	p_error = -Kp *cte

	delta_cte = cte - cte_old;
	dt = (time- time_old)*1.0f/CLOCKS_PER_SEC;

	if (dt < 0.00001) {
        d_error = 0;
    } else {
        d_error = -Kd * delta_cte / dt;
    }

    cte_old = cte;
    time_old = time;

    sum_cte += cte;
    i_error = -Ki * sum_cte;
}

double PID::TotalError() {
	return p_error + d_error + i_error;
}

