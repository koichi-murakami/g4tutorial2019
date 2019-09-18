//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SensitiveVolume.hh
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef SensitiveVolume_h
#define SensitiveVolume_h 1

#include "G4VSensitiveDetector.hh"
class G4Step;

//------------------------------------------------------------------------------
  class SensitiveVolume : public G4VSensitiveDetector
//------------------------------------------------------------------------------
{
  public:
      SensitiveVolume(G4String);
     ~SensitiveVolume();

      void Initialize(G4HCofThisEvent*);
      G4bool ProcessHits(G4Step*, G4TouchableHistory*);
      void EndOfEvent(G4HCofThisEvent*);
private:
    G4double sum_eDep_1;
    G4double sum_stepLength_1;
    G4double sum_eDep_2;
    G4double sum_stepLength_2;

};
#endif
