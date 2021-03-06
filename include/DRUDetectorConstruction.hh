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
/// \file DRUDetectorConstruction.hh
/// \brief Definition of the DRUDetectorConstruction class

#ifndef DRUDetectorConstruction_h
#define DRUDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.

class DRUDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DRUDetectorConstruction();
    virtual ~DRUDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    
    G4LogicalVolume* GetCoinVolume() const { return fCoinVolume; }
    G4LogicalVolume* GetVetoVolume() const { return fVetoVolume; }
    G4LogicalVolume* GetTopDonutVolume() const { return fTopDonutVolume; }
    G4LogicalVolume* GetTopCylinderVolume() const { return fTopCylinderVolume; }
    G4LogicalVolume* GetBotDonutVolume() const { return fBotDonutVolume; }
    G4LogicalVolume* GetBotCylinderVolume() const { return fBotCylinderVolume; }

  protected:
    G4LogicalVolume*  fCoinVolume;
    G4LogicalVolume* fVetoVolume;
    G4LogicalVolume*  fTopDonutVolume;
    G4LogicalVolume* fTopCylinderVolume;
    G4LogicalVolume*  fBotDonutVolume;
    G4LogicalVolume* fBotCylinderVolume;
};

#endif

