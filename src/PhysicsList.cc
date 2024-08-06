#include "PhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    // Register decay physics
    RegisterPhysics(new G4DecayPhysics());

    // Register EM physics
    RegisterPhysics(new G4EmStandardPhysics());

    // Register radioactive decay physics
    RegisterPhysics(new G4RadioactiveDecayPhysics());
}

PhysicsList::~PhysicsList() {}
