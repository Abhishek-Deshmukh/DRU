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
/// \file DRUEventAction.cc
/// \brief Implementation of the DRUEventAction class

#include "DRUEventAction.hh"
#include "DRURunAction.hh"

#include "DRUPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "DRUAnalyser.hh"

DRUEventAction::DRUEventAction(DRURunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction),
  fEdepVeto(0.),
  fEdepCoin(0.),
  fEdepTopDonut(0.),
  fEdepTopCylinder(0.),
  fEdepBotDonut(0.),
  fEdepBotCylinder(0.)
{
    store = Analyser::GetInstance();
}

DRUEventAction::~DRUEventAction()
= default;

void DRUEventAction::BeginOfEventAction(const G4Event*)
{
  fEdepVeto = 0.;
  fEdepCoin = 0.;
  fEdepTopDonut = 0.;
  fEdepTopCylinder = 0.;
  fEdepBotDonut = 0.;
  fEdepBotCylinder = 0.;

}

void DRUEventAction::EndOfEventAction(const G4Event*)
{
  // accumulate statistics in run action
  fRunAction->AddEdep(fEdepVeto - fEdepCoin);
  G4double ParticleEnergy;
  const auto *fPrimAction = static_cast<const DRUPrimaryGeneratorAction*>(G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
  if (!fPrimAction)return;
  ParticleEnergy = fPrimAction->GetParticleGun()->GetParticleEnergy();
  store->AppendRow(ParticleEnergy, fEdepCoin, fEdepVeto, fEdepTopDonut, fEdepTopCylinder, fEdepBotDonut, fEdepBotCylinder);

}
