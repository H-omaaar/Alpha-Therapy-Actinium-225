#include "DetectorConstruction.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}

DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4NistManager* nist = G4NistManager::Instance();

    // Define materials
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    G4Material* tissue = nist->FindOrBuildMaterial("G4_TISSUE_SOFT_ICRP");

    // Define the world volume
    G4double world_size = 10.0 * cm;
    G4Box* solidWorld = new G4Box("World", world_size / 2, world_size / 2, world_size / 2);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, true);

    // Define the cancer cell
    G4double cell_radius = 1.0 * mm;
    G4Sphere* solidCancerCell = new G4Sphere("CancerCell", 0, cell_radius, 0, 2 * M_PI, 0, M_PI);
    G4LogicalVolume* logicCancerCell = new G4LogicalVolume(solidCancerCell, tissue, "CancerCell");
    new G4PVPlacement(0, G4ThreeVector(), logicCancerCell, "CancerCell", logicWorld, false, 0, true);

    // Define the surrounding healthy tissue
    G4double tissue_inner_radius = cell_radius;
    G4double tissue_outer_radius = 5.0 * mm;
    G4Sphere* solidHealthyTissue = new G4Sphere("HealthyTissue", tissue_inner_radius, tissue_outer_radius, 0, 2 * M_PI, 0, M_PI);
    G4LogicalVolume* logicHealthyTissue = new G4LogicalVolume(solidHealthyTissue, tissue, "HealthyTissue");
    new G4PVPlacement(0, G4ThreeVector(), logicHealthyTissue, "HealthyTissue", logicWorld, false, 0, true);

    // Visualization attributes
    G4VisAttributes* visAttributesCell = new G4VisAttributes(G4Colour(1.0, 0.0, 0.0)); // Red color for cancer cell
    logicCancerCell->SetVisAttributes(visAttributesCell);

    G4VisAttributes* visAttributesTissue = new G4VisAttributes(G4Colour(0.5, 0.5, 0.5)); // Grey color for healthy tissue
    logicHealthyTissue->SetVisAttributes(visAttributesTissue);

    return physWorld;
}

