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
/// \file DRUEventAction.hh
/// \brief Definition of the DRUEventAction class

#ifndef DRUEventAction_h
#define DRUEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "DRUAnalyser.hh"

class DRURunAction;

/// Event action class
///

class DRUEventAction : public G4UserEventAction
{
  public:
    DRUEventAction(DRURunAction* runAction);
    virtual ~DRUEventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddEdepVeto(G4double edep) { fEdepVeto += edep; }
    void AddEdepCoin(G4double edep) { fEdepCoin += edep; }
    void AddEdepTopDonut(G4double edep) { fEdepTopDonut += edep; }
    void AddEdepTopCylinder(G4double edep) { fEdepTopCylinder += edep; }
    void AddEdepBotDonut(G4double edep) { fEdepBotDonut += edep; }
    void AddEdepBotCylinder(G4double edep) { fEdepBotCylinder += edep; }

  private:
    DRURunAction* fRunAction;
    G4double     fEdepVeto;
    G4double     fEdepCoin;
    G4double     fEdepTopDonut;
    G4double     fEdepTopCylinder;
    G4double     fEdepBotDonut;
    G4double     fEdepBotCylinder;
    Analyser*    store;
};

#endif
