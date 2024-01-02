#include <iostream>
#include <cmath>
#include "cpgplot.h"

using namespace std;

// Acceleration functions:
float xacceleration (float G, float x1, float y1, float x2, float y2, float m1) 
{
  float r, r3, xdistance, ydistance;
  xdistance = x2-x1;
  ydistance = y2-y1;
  r = sqrt(xdistance*xdistance+ydistance*ydistance);
  return -(G*m1)*xdistance/r/r/r;
}

float yacceleration (float G, float x1, float y1, float x2, float y2, float m1) 
{
  float r, r3, xdistance, ydistance;
  xdistance = x2-x1;
  ydistance = y2-y1;
  r = sqrt(xdistance*xdistance+ydistance*ydistance);
  return -(G*m1)*ydistance/r/r/r;
}

float Uenergy (float G, float m1, float m2, float x1, float x2, float y1, float y2)
{
  float r, xdistance, ydistance; 
  xdistance = x2-x1;
  ydistance = y2-y1; 
  r = sqrt(xdistance*xdistance+ydistance*ydistance);
  return ((-G*m1)/r)*m2;
}

int main ()
{

  // Declarations:
  int nplanet = 9; // number of planets 
  const float G = 6.67e-11; // G
  float x[nplanet], y[nplanet], vx[nplanet], vy[nplanet], m[nplanet]; // arrays for position, velocity, and mass
  float r, r3, ax, ay; 
  float t=0;
  int nintervals = 10000;
  float dt = 5.203e9/nintervals; 
  float xearth[nintervals+1], yearth[nintervals+1], xsun[nintervals+1], ysun[nintervals+1],xjupiter[nintervals+1], yjupiter[nintervals+1];
  float xmerc[nintervals+1], ymerc[nintervals+1], xven[nintervals+1], yven[nintervals+1], xmars[nintervals+1], ymars[nintervals+1], xsat[nintervals+1], ysat[nintervals+1], xuran[nintervals+1], yuran[nintervals+1], xnep[nintervals+1], ynep[nintervals+1];
  int istep,splanet,oplanet; // splanet = source planet, oplanet = orbiting planet
  float v[nplanet], KEstep[nintervals+1], KEtotal, PEtotal, PEstep[nintervals+1], Etotal[nintervals+1];
  float momentum[nintervals+1], Ptotal, Px, Py; 
  float time[nintervals+1];

  // Setting up plot:
  // Open a plot window
  if (!cpgopen("/XWINDOW")) return 1;
  // Set-up plot axes
  cpgenv(0,5.3e9,2e31,4e31,0,1);
  // Label axes
  cpglab("Time", "Linear Momentum", "Total Linear Momentum of Solar System");

  // Initilize values:
  // Sun = element 0
  x[0] = 0;
  y[0] = 0;
  vx[0] = 0; 
  vy [0] = 0;
  m[0] = 1.99e30;
  // Mercury = element 1  
  x[1] = 68.8e9;
  y[1] = 0;
  vx[1] = 0;
  vy[1] = 47.9e3;
  m[1] = 3.285e23;
  // Venus = element 2  
  x[2] = 108.26e9;
  y[2] = 0;
  vx[2] = 0;
  vy[2] = 35e3;
  m[2] = 3.285e23;
  // Earth = element 3
  x[3] = 1.4787e11;
  y[3] = 0;
  vx[3] = 0;
  vy[3] = 30e3;
  m[3] = 4.87e24;
  // Mars = 4 
  x[4] = 237.85e9;
  y[4] = 0;
  vx[4] = 0;
  vy[4] = 24.1e3;
  m[4] = 6.39e23;
  // Jupiter = element 5
  x[5] = 748.45e9;
  y[5] = 0;
  vx[5] = 0;
  vy[5] = 13.1e3;
  m[5] = 1.898e27;
  // Saturn = 6
  x[6] = 1.48e12;
  y[6] = 0;
  vx[6] = 0;
  vy[6] = 9.7e3;
  m[6] = 5.683e26;
  // Uranus = 7
  x[7] = 2.95e12;
  y[7] = 0;
  vx[7] = 0;
  vy[7] = 6.8e3;
  m[7] = 8.681e25;
  // Neptune = 8
  x[8] = 4.47e12;
  y[8] = 0;
  vx[8] = 0;
  vy[8] = 5.4e3;
  m[8] = 1.024e26;

  time[0] = t;


// Plotting planets
  for (istep=0;istep<=nintervals;istep++) {

    xsun[istep] = x[0];
    ysun[istep] = y[0];

    xmerc[istep] = x[1]; 
    ymerc[istep] = y[1]; 

    xven[istep] = x[2];
    yven[istep] = y[2]; 
    
    // Reset total energy/momentum for each step
    KEtotal = 0;
    PEtotal = 0;
    Px = 0;
    Py=0;

    
    // Calculating acceleration of planets 
    for (oplanet=0; oplanet<nplanet;oplanet++) {
      ax = 0;
      ay = 0;

      for (splanet=0; splanet<nplanet; splanet++) {

        if (oplanet==splanet) continue;

     
        ax = ax + xacceleration (G,x[splanet],y[splanet],x[oplanet],y[oplanet],m[splanet]);
        ay = ay + yacceleration (G,x[splanet],y[splanet],x[oplanet],y[oplanet],m[splanet]);

      // Calculates sum of acceleration from each planet on orbiting planet
      
      }

      vx[oplanet] = vx[oplanet]+ax*(dt/2);
      vy[oplanet] = vy[oplanet]+ay*(dt/2);
      x[oplanet] = x[oplanet]+vx[oplanet]*dt;
      y[oplanet] = y[oplanet]+vy[oplanet]*dt;

      ax = 0;
      ay = 0;

      for (splanet=0; splanet<nplanet; splanet++) {

        if (oplanet==splanet) continue;

     
        ax = ax + xacceleration (G,x[splanet],y[splanet],x[oplanet],y[oplanet],m[splanet]);
        ay = ay + yacceleration (G,x[splanet],y[splanet],x[oplanet],y[oplanet],m[splanet]);
      }

      vx[oplanet] = vx[oplanet]+ax*(dt/2);
      vy[oplanet] = vy[oplanet]+ay*(dt/2);

    // Calculate kinetic energy 
      v[oplanet] = sqrt(vx[oplanet]*vx[oplanet] + vy[oplanet]*vy[oplanet]);
      KEtotal = KEtotal+ (.5*m[oplanet]*v[oplanet]*v[oplanet]);

    // Calculate gravitational potential energy 
      for (splanet=0; splanet<nplanet; splanet++) {

        if (splanet<=oplanet) continue;
        PEtotal = PEtotal + Uenergy(G, m[oplanet], m[splanet], x[oplanet], x[splanet], y[oplanet], y[splanet]);
      }
 
    // Calculate linear momentum
      Px = Px + m[oplanet]*vx[oplanet];
      Py = Py + m[oplanet]*vy[oplanet];

    }

    // Ensure energy is conserved at each step
      KEstep[istep] = KEtotal;
      PEstep[istep] = PEtotal;
      Etotal[istep] = KEstep[istep]+PEstep[istep];

      Px = Px; 
      Py = Py; 
      Ptotal = Px+Py; 
      momentum[istep] = Ptotal; 
    

    
    //cout << "Total energy = " << Etotal[istep] << "\n";
    //cout << "momentum = " << momentum[istep] << "\n";

      t = t+dt; 
      time[istep] = t;
  }

  //cpgsci(4);
 // cpgline(nintervals+1,time,Etotal);
  cpgsci(5);
  cpgline(nintervals+1,time,momentum);

  cpgclos();

}
