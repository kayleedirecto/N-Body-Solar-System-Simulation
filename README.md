# N Body Solar System Simulation

This was the personal project I did for my Scientific Computing course in 2021. I wanted to simulate the N-body problem, predicting how celestial objects move and interact with each other via the force of gravity. 

## The Math 

We can predict the orbital motions of these objects by determining their instantaneous positions and velocities at any given time from their interactive forces. 

The gravitational force of attraction between to planets is the net force causing a planet to orbit around a source planet. Using Newton's first law, we can use the gravitational force to determine the acceleration the orbiting planet experiences at any given time. From the acceleration, we can obtain the instantaneous velocity and position of the planet, to plot its orbit. 

The gravitational force between two objects is given by:

$F_g = \frac{G{m_s}{m_o}}{r^2}$

Subbing this in to Newton's first law: 

$F_g = ma$ 

$\frac{G{m_s}{m_o}}{r^2} = {m_o}{a_o}$ 

Note that the left hand side acceleration, $a_o$, is associated with the orbiting mass, $m_o$. Now simplifying, 

$a_o = \frac{G{m_s}}{r^2}$

We see that the acceleration of the orbiting planet now only depends on the mass of the source planet, the gravitational constant, and the square of the distance between them. 

We can now solve for the velocity and position of the orbiting planet at a given instant. As acceleration is the first deriva†ive of velocity, we can substitute this in the equation to get: 

$\frac{dv_x}{dt} = \frac{G{m_s}}{{r_x}^2}$

$\frac{dv_y}{dt} = \frac{G{m_s}}{{r_y}^2}$

And using the fact that velocity is the first derivative of the position, we get: 

$\frac{dx}{dt} = v_x$

$\frac{dy}{dt} = v_y$

We now have a series of differential equations for the position and velocities of the orbiting planet. 

## The Method 

To solve these differential equations, I used leapfrog integration. In this method, the initial acceleration at timestep t = 0 is calculated. Using this acceleration, the velocity at a half timestep, t = 1/2,  is calculated, which is then used to calculate the position at a full timestep, t = 1. The velocity is then "caught up" to a full timestep by using the acceleration at the full timestep, t = 1. This repeats over all timsteps. In this way, the position and velocity "leapfrog" over each other, which gives relatively accurate integrations. The algorithm can be mathematically written as: 

$v_{i+\frac{1}{2}} = v_i + {a_i}\frac{\Delta t}{2}$

$x_{i+1} = x_i + v_i + \frac{\Delta t}{2}$

$v_{i+1} = v_{i + \frac{1}{2}} + {a_{i + 1}}\frac{\Delta t}{2}$

To model the whole solar system and account for the interactions of the orbiting planet with the other 8 planets plus the sum, I summed the acceleration due to the gravitational force between the orbiting planet and each source mass. 

## Results 

The main simulation with the solar system in its entirety can be found in final.cpp. 

I started with Mercury's orbit around the sun. We can see an accurate elliptical shaped orbit, as well as the presence of its perihelion (point in the orbit where it is closest to the sun) and its aphelion (point where it is farthest from the sun). 

<img width="400" alt="Screenshot 2025-05-29 at 1 10 20 PM" src="https://github.com/user-attachments/assets/819040a2-e2de-47bf-a164-4fd8ef182f51" />

Increasing the number of orbits to 1000, we can see a "thicker" plot. This is most likely due to the precession of Mercury's orbits around the sun, i.e. the entire orbit path was rotating, causing the perihelion and aphelion to rotate around the sun. 

<img width="400" alt="Screenshot 2025-05-29 at 1 14 43 PM" src="https://github.com/user-attachments/assets/a4516cb5-7d9b-4b12-aa15-43d73b61188d" />

We can see the full solar system here: 

<img width="400" alt="Screenshot 2025-05-29 at 1 26 23 PM" src="https://github.com/user-attachments/assets/5c5a05e8-aa92-47a1-935d-da3e97a82ff6" />


 




