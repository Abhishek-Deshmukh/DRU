//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file DRUDetectorConstruction.cc
/// \brief Implementation of the DRUDetectorConstruction class

#include <G4Colour.hh>
#include "DRUDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "CADMesh.hh"

DRUDetectorConstruction::DRUDetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(nullptr)
{ }

DRUDetectorConstruction::~DRUDetectorConstruction()
= default;

G4VPhysicalVolume* DRUDetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
    G4Colour  white   (1.0, 1.0, 1.0) ;  // white
    G4Colour  grey    (0.5, 0.5, 0.5) ;  // grey
    G4Colour  black   (0.0, 0.0, 0.0) ;  // black
    G4Colour  red     (1.0, 0.0, 0.0) ;  // red
    G4Colour  green   (0.0, 1.0, 0.0) ;  // green
    G4Colour  blue    (0.0, 0.0, 1.0) ;  // blue
    G4Colour  cyan    (0.0, 1.0, 1.0) ;  // cyan
    G4Colour  magenta (1.0, 0.0, 1.0) ;  // magenta
    G4Colour  yellow  (1.0, 1.0, 0.0) ;  // yellow
  // ENVELOPE
  // specifications
  G4double env_sizeXY = 0.2*m;
  G4double env_sizeZ = 0.2*m;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");


  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

  //     
  // World
  //
  G4double world_sizeXY = 1.2*env_sizeXY;
  G4double world_sizeZ  = 1.2*env_sizeZ;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
  
  auto* solidWorld =
    new G4Box("World",                       //its name
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size
      
  auto* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(nullptr,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      nullptr,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
  //     
  // Envelope
  //  
  auto* solidEnv =
    new G4Box("Envelope",                    //its name
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size
      
  auto* logicEnv =
    new G4LogicalVolume(solidEnv,            //its solid
                        env_mat,             //its material
                        "Envelope");         //its name
               
  new G4PVPlacement(nullptr,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicEnv,                //its logical volume
                    "Envelope",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
 
  //     
  // Donut
  //  
  G4Material* donut_mat = nist->FindOrBuildMaterial("G4_Ge");
  auto* donut_vis = new G4VisAttributes(blue);
        
  // Importing obj/Donut.obj
  auto donutMesh = CADMesh::TessellatedMesh::FromOBJ("./objs/Donut.obj");
                      
  auto* logicDonut =
    new G4LogicalVolume(donutMesh->GetSolid(),        //its solid
                        donut_mat,          //its material
                        "Donut");           //its name
  logicDonut->SetVisAttributes(donut_vis);
               
  new G4PVPlacement(nullptr,                       //no rotation
                    G4ThreeVector(0, 0, 0),  //at position
                    logicDonut,             //its logical volume
                    "Donut",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  //     
  // Coin
  //
  G4Material* coin_mat = nist->FindOrBuildMaterial("G4_Si");
  auto* coin_vis = new G4VisAttributes(green);

  // Importing obj/Coin.obj
  auto coinMesh = CADMesh::TessellatedMesh::FromOBJ("./objs/Coin.obj");

  auto* logicCoin =
    new G4LogicalVolume(coinMesh->GetSolid(),       //its solid
                        coin_mat,          //its material
                        "Coin");           //its name
                        logicCoin->SetVisAttributes(coin_vis);
               
  new G4PVPlacement(nullptr,                       //no rotation
                    G4ThreeVector(0, 0, 0),  //at position
                    logicCoin,               //its logical volume
                    "Coin",                  //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                

  //     
  // Inner Housing
  //
  G4Material* inner_housing_mat = nist->FindOrBuildMaterial("G4_Cu");
  auto* inner_housing_vis = new G4VisAttributes(red);

  // Importing obj/InnerHousing.obj
  auto innerHousingMesh = CADMesh::TessellatedMesh::FromOBJ("./objs/InnerHousing.obj");
                
  auto* logicInnerHousing =
    new G4LogicalVolume(innerHousingMesh->GetSolid(),       //its solid
                        inner_housing_mat,          //its material
                        "InnerHousing");           //its name
  logicInnerHousing->SetVisAttributes(inner_housing_vis);
               
  new G4PVPlacement(nullptr,                       //no rotation
                    G4ThreeVector(0, 0, 0),  //at position
                    logicInnerHousing,               //its logical volume
                    "InnerHousing",                  //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking


  //     
  // Outer Housing
  //
  G4Material* outer_housing_mat = nist->FindOrBuildMaterial("G4_Cu");
  auto* outer_housing_vis = new G4VisAttributes(red);

  // Importing obj/OuterHousing.obj
  auto outerHousingMesh = CADMesh::TessellatedMesh::FromOBJ("./objs/OuterHousing.obj");
                
  auto* logicOuterHousing =
    new G4LogicalVolume(outerHousingMesh->GetSolid(),       //its solid
                        outer_housing_mat,          //its material
                        "OuterHousing");           //its name
  logicOuterHousing->SetVisAttributes(outer_housing_vis);
               
  new G4PVPlacement(nullptr,                       //no rotation
                    G4ThreeVector(0, 0, 0),  //at position
                    logicOuterHousing,       //its logical volume
                    "OuterHousing",          //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking

  // Set Coin as scoring volume
  //
  fScoringVolume = logicCoin;

  //always return the physical World
  return physWorld;
}