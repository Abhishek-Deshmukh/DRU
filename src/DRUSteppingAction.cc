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
/// \file DRUSteppingAction.cc
/// \brief Implementation of the DRUSteppingAction class

#include "DRUSteppingAction.hh"
#include "DRUEventAction.hh"
#include "DRUDetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

DRUSteppingAction::DRUSteppingAction(DRUEventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction),
  fCoinVolume(nullptr),
  fVetoVolume(nullptr)
{}

DRUSteppingAction::~DRUSteppingAction()
{}

void DRUSteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fCoinVolume) {
    const DRUDetectorConstruction* detectorConstruction
      = static_cast<const DRUDetectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fCoinVolume = detectorConstruction->GetCoinVolume();
    fVetoVolume = detectorConstruction->GetVetoVolume();
    fTopDonutVolume = detectorConstruction->GetTopDonutVolume();
    fTopCylinderVolume = detectorConstruction->GetTopCylinderVolume();
    fBotDonutVolume = detectorConstruction->GetBotDonutVolume();
    fBotCylinderVolume = detectorConstruction->GetBotCylinderVolume();
  }

  // get volume of the current step
  G4LogicalVolume* volume 
    = step->GetPreStepPoint()->GetTouchableHandle()
      ->GetVolume()->GetLogicalVolume();
      
  // check if we are in Coin/Veto volume
    // collect energy deposited in this step
  if (volume == fCoinVolume) {
      fEventAction->AddEdepCoin(step->GetTotalEnergyDeposit());
  } else if (volume == fVetoVolume) {
      fEventAction->AddEdepVeto(step->GetTotalEnergyDeposit());
  } else if (volume == fTopDonutVolume) {
      fEventAction->AddEdepTopDonut(step->GetTotalEnergyDeposit());
  } else if (volume == fTopCylinderVolume) {
      fEventAction->AddEdepTopCylinder(step->GetTotalEnergyDeposit());
  } else if (volume == fBotDonutVolume) {
      fEventAction->AddEdepBotDonut(step->GetTotalEnergyDeposit());
  } else if (volume == fBotCylinderVolume) {
      fEventAction->AddEdepBotCylinder(step->GetTotalEnergyDeposit());
  }
}
