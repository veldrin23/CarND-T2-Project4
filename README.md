# CARND Term 2 
# Project 4 - PID controller 


---

## P, I and D
### **P**roportional controller
This is the first term I played with. In short, the P factor determines how sharp the vehicle turns. A higher value makes the vehicle turn faster. 

Below is a video of a scenario where the P factor is too high.

You can see the vehicle's turn rate is excessive. 
### **I**ntegral controller
The Integral factor dampens the steering angle based on the cumulative error (cte). This includes the sum of positive and negative values, which means that pendulum-esque movements of the vehicle (as views from above) decreases this adjustment. 

Below is a video of a scenario where the I factor is too high.



### **D**ifferential controller
The differential controller aims to smooth out the steering angle based on the change in cte. As the vehicle gets closer the the ground truth (the cte value decreases), the steering angle will become less acute.

Having a large D value will make the vehicle become too excited to get back on track, which will make it overshoot the ground truth mark.

## Tuning
This was done manually, my C++ expertise was not on the level to dynamically tune the parameters on the fly. 
The steps can also be found in the main.cpp script, but here was what I experienced:

* I started with PID = [2.9, 10.3, 0.5], which was taken as is from the lessons. It was way too extreme, the vehichle took super sharp turns and couldn't 'stick' to the groud truth.


[![1](https://img.youtube.com/vi/y3ozUZpePZ0/0.jpg)](https://youtu.be/y3ozUZpePZ0?t=1s)


* After that I decreased the P factor to 0.3: [0.3, 10.3, 0.5]. This did not have the desired change. The vehicle still turned too sharply. 


[![2](https://img.youtube.com/vi/XtBnPXdcdjw/0.jpg)](https://youtu.be/XtBnPXdcdjw)
 
 
* Next step was to decrease the I value so that the vehicle is less sensitive the the cumulative errors.  [0.3, 1.0, 0.5]


[![3](https://img.youtube.com/vi/qyzyV2Bzhes/0.jpg)](https://youtu.be/qyzyV2Bzhes)


* This kept the vehicle on the road at least, but the sporadic left/ right turning was not desired [0.3, 0.1, 0.5]


[![4](https://img.youtube.com/vi/Eey-qAtxiig/0.jpg)](https://youtu.be/Eey-qAtxiig)


* Decreasing I even more: [0.3, .001, 0.5]


[![5](https://img.youtube.com/vi/6DoT7PcBN2w/0.jpg)](https://youtu.be/6DoT7PcBN2w)


* Did not have the desired effect, need to decreasse D [0.3, .001, 0.05]


[![6](https://img.youtube.com/vi/5RgGFUqoiOM/0.jpg)](https://youtu.be/5RgGFUqoiOM)


* Close, but still too jerky: [0.03, .0005, 0.015]


[![7](https://img.youtube.com/vi/xLUXHcAMo4o/0.jpg)](https://youtu.be/xLUXHcAMo4o)


* This works 

  
  
