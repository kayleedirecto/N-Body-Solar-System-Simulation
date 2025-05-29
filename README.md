# N Body Solar System Simulation

This was the personal project I did for my Scientific Computing course in 2021. I wanted to simulate the N-body problem, predicting how celestial objects move and interact with each other via the force of gravity. 

## The Math 

We can predict the orbital motions of these objects by determining their instantaneous positions and velocities at any given time from their interactive forces. 

The gravitational force of attraction between two planets is the net force causing a planet to orbit around a source planet. Using Newton's first law, we can use the gravitational force to determine the acceleration the orbiting planet experiences at any given time. From the acceleration, we can obtain the instantaneous velocity and position of the planet, to plot its orbit. 

The gravitational force between two objects is given by:

$F_g = \frac{G{m_s}{m_o}}{r^2}$

where $m_s$ is the mass of the source planet, $m_o$ is the mass of the orbiting planet, $r$ is the distance between them, and $G$ is the universal gravitational constant. 

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

## The Results 

The main simulation with the solar system in its entirety can be found in final.cpp. 

I started with Mercury's orbit around the sun. We can see an accurate elliptical shaped orbit, as well as the presence of its perihelion (point in the orbit where it is closest to the sun) and its aphelion (point where it is farthest from the sun). 

<img width="400" alt="Screenshot 2025-05-29 at 1 10 20 PM" src="https://github.com/user-attachments/assets/819040a2-e2de-47bf-a164-4fd8ef182f51" />

Increasing the number of orbits to 1000, we can see a "thicker" plot. This is most likely due to the precession of Mercury's orbits around the sun, i.e. the entire orbit path was rotating, causing the perihelion and aphelion to rotate around the sun. 

<img width="400" alt="Screenshot 2025-05-29 at 1 14 43 PM" src="https://github.com/user-attachments/assets/a4516cb5-7d9b-4b12-aa15-43d73b61188d" />

We can see the full solar system here: 

<img width="400" alt="Screenshot 2025-05-29 at 1 26 23 PM" src="https://github.com/user-attachments/assets/5c5a05e8-aa92-47a1-935d-da3e97a82ff6" />

## The Sanity Checks 

Although my results looked accurate, I wanted to perform checks on the energy and momentum on the system. Assuming this is a closed system, the total energy and momentum should stay constant throughout the simulation. These checks can be found in energy.cpp. 

I summed the total kinetic and potential energy of the solar system at each timestep, and ensure the value remained constant. The same was done for the linear momentum. We see below that energy and momentum are relatively constant, with slight oscillations, possibly due to round off or precision errors from the leapfrog integration. 

<img width="400" alt="Screenshot 2025-05-29 at 1 33 43 PM" src="https://github.com/user-attachments/assets/b85e8c94-da86-4777-8fca-d4c34922e37e" />

<img width="400" alt="Screenshot 2025-05-29 at 1 33 55 PM" src="https://github.com/user-attachments/assets/f24774ed-5061-466b-ad34-1b3e7299b013" />

## The Fun Part  

As a fun addition, I decided to add a 10th body - a comet. This script can be found in extension.cpp. I modeled it after a real comet, Oumuamua. Below we can see the path the simulation predicted and the actual path of the comet. 

<img width="400" alt="Screenshot 2025-05-29 at 1 37 01 PM" src="https://github.com/user-attachments/assets/02078898-db28-46ac-ae86-e67c57d6debf" />

![image](https://github.com/user-attachments/assets/2e1c2c90-de58-4543-96f1-0e174e1e6985)

I wanted to experiment with different masses of the comet, to see how its path would change. The mass of Oumuamua is on the order of $10^4$ kg. Increasing this to around $10^25$ kg caused the angle between its entry annd exit to decrease. Intuitively this makes sense, as larger masses would experience a greater pull from the sun's gravitational force, causing it to ricochet out of the solar system closer to its path of entry. 

<img width="400" alt="Screenshot 2025-05-29 at 1 53 42 PM" src="https://github.com/user-attachments/assets/989338b7-a624-4251-81cd-7f9914045089" />

The simulation began to break down when the mass was increased to $10^26$ kg. 

<img width="400" alt="Screenshot 2025-05-29 at 1 54 36 PM" src="https://github.com/user-attachments/assets/13e7c86d-4f5c-4f91-919e-5cc19381c0b1" />

I continued increasing the mass to observe interesting outcomes. At $10^27$ kg: 

<img width="400›" alt="Screenshot 2025-05-29 at 1 55 42 PM" src="https://github.com/user-attachments/assets/0938ac8c-4119-43f3-9be4-91a520c9b472" />

At $10^30# kg: 

<img width="400" alt="Screenshot 2025-05-29 at 1 56 07 PM" src="https://github.com/user-attachments/assets/36def2ad-f115-4a45-86b7-87da6ecc8a8f" />

Let's hope we never find out if this is an accurate simulation or not. 
