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
/// \file DRUPrimaryGeneratorAction.cc
/// \brief Implementation of the DRUPrimaryGeneratorAction class

#include "DRUPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "DRURandomEnergyGenerator.hh"

DRUPrimaryGeneratorAction::DRUPrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(nullptr),
  fEnvelopeBox(nullptr)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);

  // Energy generator
  energy_generator = new DRURandomEnergyGenerator();

  // particle default settings
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="gamma");
  fParticleGun->SetParticleDefinition(particle);

}

DRUPrimaryGeneratorAction::~DRUPrimaryGeneratorAction()
{
  delete fParticleGun;
}

void DRUPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the beginning of each event
  //

  // In order to avoid dependence of PrimaryGeneratorAction
  // on DetectorConstruction class we get Envelope volume
  // from G4LogicalVolumeStore.
  G4cout << "Event ID: " << anEvent->GetEventID() << G4endl;

  G4double envSizeXY = 0;
  G4double envSizeZ = 0;

  if (!fEnvelopeBox)
  {
    G4LogicalVolume* envLV
      = G4LogicalVolumeStore::GetInstance()->GetVolume("Envelope");
    if ( envLV ) fEnvelopeBox = dynamic_cast<G4Box*>(envLV->GetSolid());
  }

  if ( fEnvelopeBox ) {
    envSizeXY = fEnvelopeBox->GetXHalfLength()*2.;
    envSizeZ = fEnvelopeBox->GetZHalfLength()*2.;
  }
  else  {
    G4ExceptionDescription msg;
    msg << "Envelope volume of box shape not found.\n";
    msg << "Perhaps you have changed geometry.\n";
    msg << "The gun will be place at the center.";
    G4Exception("DRUPrimaryGeneratorAction::GeneratePrimaries()",
     "MyCode0002",JustWarning,msg);
  }

  G4double size = 0.9;
  G4double x_big = size * envSizeXY /2;
  G4double y_big = size * envSizeXY /2;
  G4double z_big = size * envSizeZ  /2;
  G4double x_small = 5 * cm;
  G4double y_small = 5 * cm;
  G4double z_small = 5 * cm;
  G4double x, y, z, energy, u, v, w, norm, a, b, c;

  // Muller method for generating random point on the sphere surface
  u = G4UniformRand() - 0.5; // goes form -0.5 to 0.5
  v = G4UniformRand() - 0.5;
  w = G4UniformRand() - 0.5;
  norm = sqrt(u*u + v*v + w*w);
  x = (u/norm)*x_big;
  y = (v/norm)*y_big;
  z = (w/norm)*z_big;

  u = G4UniformRand() - 0.5; // goes form -0.5 to 0.5
  v = G4UniformRand() - 0.5;
  w = G4UniformRand() - 0.5;
  norm = sqrt(u*u + v*v + w*w);
  a = (u/norm)*x_small;
  b = (v/norm)*y_small;
  c = (w/norm)*z_small;
  energy = energy_generator->get_energy();

  fParticleGun->SetParticlePosition(G4ThreeVector(x*mm,y*mm,z*mm));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(a-x,b-y,c-z));
  fParticleGun->SetParticleEnergy(energy*keV);
  fParticleGun->GeneratePrimaryVertex(anEvent);
}
