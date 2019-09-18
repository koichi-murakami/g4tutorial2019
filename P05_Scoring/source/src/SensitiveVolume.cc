//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SensitiveVolume.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "SensitiveVolume.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"
#include "G4HCofThisEvent.hh"


//------------------------------------------------------------------------------
  SensitiveVolume::SensitiveVolume(G4String name)
  : G4VSensitiveDetector(name)
{}
//------------------------------------------------------------------------------
  SensitiveVolume::~SensitiveVolume()
{}
//------------------------------------------------------------------------------
  void SensitiveVolume::Initialize(G4HCofThisEvent*)
{

     sum_eDep_1 = 0.;
     sum_stepLength_1 =0.; 
     sum_eDep_2 = 0.;
     sum_stepLength_2 =0.;

   G4cout << "==  Initialize sum_eDeps and sum_stepLengths   " <<G4endl;
}
//------------------------------------------------------------------------------
  void SensitiveVolume::EndOfEvent(G4HCofThisEvent*)
{

   G4cout <<  " sum_eDep_1 = "<< sum_eDep_1 << " sum_stepLength_1 = " << sum_stepLength_1 <<G4endl;
   G4cout <<  " sum_eDep_2 = "<< sum_eDep_2 << " sum_stepLength_2 = " << sum_stepLength_2 <<G4endl;
}

//------------------------------------------------------------------------------
  G4bool SensitiveVolume::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{

   G4StepPoint* pre = aStep->GetPreStepPoint() ;
   G4int copyNo = pre->GetPhysicalVolume()->GetCopyNo() ;
  
// get total energy deposit in this step "edep"  and  accumulate it in "sum_eDep"
    G4double edep = aStep->GetTotalEnergyDeposit();

// get step length and accumulate it
    G4double stepLength = 0.;
    if ( aStep->GetTrack()->GetDefinition()->GetPDGCharge() != 0. ) {
      stepLength = aStep->GetStepLength();
    }
    if(copyNo == 1000) {
	sum_eDep_1 = sum_eDep_1 + edep; sum_stepLength_1 = sum_stepLength_1 + stepLength;
	}
    if(copyNo == 2000) {
	sum_eDep_2 = sum_eDep_2 + edep; sum_stepLength_2 = sum_stepLength_2 + stepLength;
	}

    


  return true;
}






