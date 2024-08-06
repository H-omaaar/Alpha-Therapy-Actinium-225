#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction() : G4UserSteppingAction() {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    // Record each step for visualization
    G4Track* track = step->GetTrack();
    if (track->GetDefinition()->GetParticleName() == "alpha") {
        G4double kineticEnergy = track->GetKineticEnergy();
        G4cout << "Alpha particle step at position: " 
               << track->GetPosition() << " with energy: " 
               << kineticEnergy / MeV << " MeV" << G4endl;
    }
}

