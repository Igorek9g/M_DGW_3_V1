

#ifndef CPROJECT_PRIMARYGEN_HH
#define CPROJECT_PRIMARYGEN_HH


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

#include "G4Event.hh"

#include "G4SystemOfUnits.hh"

#include "G4Gamma.hh"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <iostream>
#include <loader.hh>
//#include <loader.cc>

class G4ParticleGun;
class G4Event;

/*class mast : DetGeometry
{
public:
    G4ThreeVector* W= boxPos;
    mast get = boxPos;
};*/

class PrimaryGen : public G4VUserPrimaryGeneratorAction
{
private:
    G4ParticleGun*  gun;
public:
    DetGeometry* B;
    PrimaryGen();
    virtual ~PrimaryGen();
    virtual void GeneratePrimaries(G4Event*);
};

#endif //CPROJECT_PRIMARYGEN_HH
