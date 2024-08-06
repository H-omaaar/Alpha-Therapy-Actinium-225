#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"
#include "Randomize.hh"
#include "G4Alpha.hh"
#include "G4RandomDirection.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    G4int n_particle = 1;
    fParticleGun = new G4ParticleGun(n_particle);

    // Define the particle type and properties
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("alpha");
    if (!particle) {
        G4cerr << "Error: alpha particle definition not found!" << G4endl;
        return;
    }
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(5.8 * MeV);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction() {
    delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    // Randomly distribute the emission points within the cancer cell
    G4double radius = 1.0 * mm;
    G4ThreeVector position = G4RandomDirection() * (G4UniformRand() * radius);
    fParticleGun->SetParticlePosition(position);
    fParticleGun->GeneratePrimaryVertex(anEvent);

    // Print position and energy for debugging
    G4cout << "Alpha particle generated at position: " << position 
           << " with energy: " << fParticleGun->GetParticleEnergy() / MeV << " MeV" << G4endl;
}
