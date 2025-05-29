# N Body Solar System Simulation

This was the personal project I did for my Scientific Computing course in 2021. I wanted to simulate the N-body problem, predicting how celestial objects move and interact with each other via the force of gravity. 

## The Math 

We can predict the orbital motions of these objects by determining their instantaneous positions and velocities at any given time from their interactive forces. 

The gravitational force of attraction between to planets is the net force causing a planet to orbit around a source planet. Using Newton's first law, we can use the gravitational force to determine the acceleration the orbiting planet experiences at any given time. From the acceleration, we can obtain the instantaneous velocity and position of the planet, to plot its orbit. 

The gravitational force between two objects is given by: <br>
$F_g = \frac{G{m_s}{m_o}}{r^2}$

Subbing this in to Newton's first law: <br>
$F_g = ma$ <br>
$\frac{G{m_s}{m_o}}{r^2} = {m_o}a$ <br> 
Note that the left hand side acceleration is associated with the orbiting mass, $m_o$, and not the source planet. 




