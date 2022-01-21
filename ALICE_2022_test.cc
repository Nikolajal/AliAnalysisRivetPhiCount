// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Tools/AliceCommon.hh"
#include "Rivet/Projections/AliceCommon.hh"
#include "Rivet/Projections/HepMCHeavyIon.hh"
#include "Rivet/Projections/UnstableParticles.hh"
#include "Rivet/Projections/CentralityProjection.hh"

namespace Rivet {


    /// @brief Add a short analysis description here
    /// PDG code IDs used in the code:
    /// \phi = 333
    /// K+- = 333

  class ALICE_2017_I1511864 : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(ALICE_2022_Test);


      /// @name Analysis methods
      ///@{

      /// Book histograms and initialise projections before the run
      void init() {
      
          // Initialise and register projections
          declare( UnstableParticles ( Cuts::absrap < 0.5 ), "_AnalysisCuts" );
          
          // Declare the HepMC HeavyIon
          declare(HepMCHeavyIon(), "HepMC");
          
          // Declare centrality projection
          declareCentrality(ALICE::V0MMultiplicity(), "ALICE_2015_PBPBCentrality", "V0M", "V0M");
          
          // Book histograms for pT spectra
          book(_h["pp.0276.kst.spec.00_00"],  "d01-x01-y01" );
          book(_h["pp.0276.phi.spec.00_00"],  "d02-x01-y01" );
          book(_h["Pb.0276.kst.spec.00_05"],  "d03-x01-y01" );
          book(_h["Pb.0276.kst.spec.05_10"],  "d04-x01-y01" );
          book(_h["Pb.0276.kst.spec.10_20"],  "d05-x01-y01" );
          book(_h["Pb.0276.kst.spec.20_30"],  "d06-x01-y01" );
          book(_h["Pb.0276.kst.spec.30_40"],  "d07-x01-y01" );
          book(_h["Pb.0276.kst.spec.40_50"],  "d08-x01-y01" );
          book(_h["Pb.0276.phi.spec.00_05"],  "d09-x01-y01" );
          book(_h["Pb.0276.phi.spec.05_10"],  "d10-x01-y01" );
          book(_h["Pb.0276.phi.spec.10_20"],  "d11-x01-y01" );
          book(_h["Pb.0276.phi.spec.20_30"],  "d12-x01-y01" );
          book(_h["Pb.0276.phi.spec.30_40"],  "d13-x01-y01" );
          book(_h["Pb.0276.phi.spec.40_50"],  "d14-x01-y01" );
          book(_h["Pb.0276.phi.spec.60_80"],  "d15-x01-y01" );
          // Utilities for later
          book(_h["Pb.0276.kst.spec.60_80"],  "Pb.0276.kst.spec.60_80",  refData(15, 1,  1));
          
          // Book histograms for ratios to Kaon spectra
          book(_s["Pb.0276.kst.ovrK.00_05"],  "d16-x01-y01" );
          book(_s["pp.0276.kst.ovrK.00_00"],  "d17-x01-y01" );
          book(_s["Pb.0276.phi.ovrK.00_05"],  "d18-x01-y01" );
          book(_s["pp.0276.phi.ovrK.00_00"],  "d19-x01-y01" );
          
          // - // Utilities for the Ratios
          book(_h["Pb.0276.kst.spec.utlt"],  "Pb.0276.kst.spec.utlt",  refData(16, 1,  1));
          book(_h["Pb.0276.kst.spec.u80t"],  "Pb.0276.kst.spec.u80t",  refData(25, 1,  1));
          book(_h["pp.0276.kst.spec.utlt"],  "pp.0276.kst.spec.utlt",  refData(17, 1,  1));
          book(_h["Pb.0276.phi.spec.utlt"],  "Pb.0276.phi.spec.utlt",  refData(18, 1,  1));
          book(_h["Pb.0276.phi.spec.u80t"],  "Pb.0276.phi.spec.u80t",  refData(28, 1,  1));
          book(_h["pp.0276.phi.spec.utlt"],  "pp.0276.phi.spec.utlt",  refData(19, 1,  1));
          
          // - // Kaon Spectra utility
          book(_h["Pb.0276.kan.spec.utlK"],  "Pb.0276.kan.spec.utlK",  refData(16, 1,  1));
          book(_h["pp.0276.kan.spec.utlK"],  "pp.0276.kan.spec.utlK",  refData(17, 1,  1));
          book(_h["Pb.0276.kan.spec.utlP"],  "Pb.0276.kan.spec.utlP",  refData(18, 1,  1));
          book(_h["pp.0276.kan.spec.utlP"],  "pp.0276.kan.spec.utlP",  refData(19, 1,  1));

          // Book histograms for ratios to Pi spectra
          book(_s["Pb.0276.kst.ovrP.00_05"],  "d20-x01-y01" );
          book(_s["pp.0276.kst.ovrP.00_00"],  "d21-x01-y01" );
          book(_s["Pb.0276.phi.ovrP.00_05"],  "d22-x01-y01" );
          book(_s["pp.0276.phi.ovrP.00_00"],  "d23-x01-y01" );
          
          // - // Pi Spectra utility
          book(_h["Pb.0276.pis.spec.utlK"],  "Pb.0276.pis.spec.utlK",  refData(20, 1,  1));
          book(_h["pp.0276.pis.spec.utlK"],  "pp.0276.pis.spec.utlK",  refData(21, 1,  1));
          book(_h["Pb.0276.pis.spec.utlP"],  "Pb.0276.pis.spec.utlP",  refData(22, 1,  1));
          book(_h["pp.0276.pis.spec.utlP"],  "pp.0276.pis.spec.utlP",  refData(23, 1,  1));
          
          // Book histograms for ratios to Proton spectra
          book(_s["Pb.0276.kst.ovPr.00_05"],  "d24-x01-y01" );
          book(_s["Pb.0276.kst.ovPr.60_80"],  "d25-x01-y01" );
          book(_s["pp.0276.kst.ovPr.00_00"],  "d26-x01-y01" );
          book(_s["Pb.0276.phi.ovPr.00_05"],  "d27-x01-y01" );
          book(_s["Pb.0276.phi.ovPr.60_80"],  "d28-x01-y01" );
          book(_s["pp.0276.phi.ovPr.00_00"],  "d29-x01-y01" );
          
          // - // Proton Spectra utility
          book(_h["Pb.0276.prt.spec.u05K"],  "Pb.0276.prt.spec.u05K",  refData(24, 1,  1));
          book(_h["Pb.0276.prt.spec.u80K"],  "Pb.0276.prt.spec.u80K",  refData(25, 1,  1));
          book(_h["pp.0276.prt.spec.utlK"],  "pp.0276.prt.spec.utlK",  refData(26, 1,  1));
          book(_h["Pb.0276.prt.spec.u05P"],  "Pb.0276.prt.spec.u05P",  refData(27, 1,  1));
          book(_h["Pb.0276.prt.spec.u80P"],  "Pb.0276.prt.spec.u80P",  refData(28, 1,  1));
          book(_h["pp.0276.prt.spec.utlP"],  "pp.0276.prt.spec.utlP",  refData(29, 1,  1));
          
          // R_{AA}
          book(_s["Pb.0276.kst.spec.00_05"],  "d30-x01-y01" );
          book(_s["Pb.0276.kst.spec.05_10"],  "d31-x01-y01" );
          book(_s["Pb.0276.kst.spec.20_30"],  "d32-x01-y01" );
          book(_s["Pb.0276.kst.spec.40_50"],  "d33-x01-y01" );
          book(_s["Pb.0276.phi.spec.00_05"],  "d34-x01-y01" );
          book(_s["Pb.0276.phi.spec.05_10"],  "d35-x01-y01" );
          book(_s["Pb.0276.phi.spec.20_30"],  "d36-x01-y01" );
          book(_s["Pb.0276.phi.spec.40_50"],  "d37-x01-y01" );
      
      }

      /// Perform the per-event analysis
      void analyze(const Event& event) {
          
          // Analysis physics selection
          const UnstableParticles &_EventParticles = apply<UnstableParticles>(event, "_AnalysisCuts");
          
          // Identify the beam ID
          PdgIdPair _BeamType = beamIds();
          
          // Selecting proton-proton events
          if ( _BeamType.first == 2212 && _BeamType.second == 2212 ) {

              // Loop over event particles
              for ( const Particle& Current_Particle : _EventParticles.particles() ) {
                      
                  // Filling histograms for Phi Meson
                  if (Current_Particle.abspid() == 313) {
                      _h["pp.0276.kst.spec.00_00"]->fill( Current_Particle.pT() / GeV );
                      _h["pp.0276.kst.spec.utlt"]->fill( Current_Particle.pT() / GeV );
                  }
                      
                  // Filling histograms for Kaon Star Meson
                  if (Current_Particle.abspid() == 333) {
                      _h["pp.0276.phi.spec.00_00"]->fill( Current_Particle.pT() / GeV );
                      _h["pp.0276.phi.spec.utlt"]->fill( Current_Particle.pT() / GeV );
                  }
                  
                  // Filling histograms for Kaon Meson
                  if (Current_Particle.abspid() == 321) {
                      _h["pp.0276.kan.spec.utlK"]->fill( Current_Particle.pT() / GeV );
                      _h["pp.0276.kan.spec.utlP"]->fill( Current_Particle.pT() / GeV );
                  }
                  
                  // Filling histograms for Kaon Meson
                  if (Current_Particle.abspid() == 211) {
                      _h["pp.0276.pis.spec.utlK"]->fill( Current_Particle.pT() / GeV );
                      _h["pp.0276.pis.spec.utlP"]->fill( Current_Particle.pT() / GeV );
                  }
              }
              // Ending proton-proton and starting lead-lead events
          } else if ( _BeamType.first == 1000822080 && _BeamType.second == 1000822080 ) {
              
              // Prepare centrality & number of participants projection and value
              const CentralityProjection&   centrProj =  apply<CentralityProjection>( event, "V0M" );
              const HepMCHeavyIon &         partcProj =  apply<HepMCHeavyIon>( event, "HepMC" );
              
              // Centrality %
              const double _CentrVals = centrProj();
              const double _PartcVals = partcProj.Npart_proj() + partcProj.Npart_targ();
              
              // Iteration counter
              int iCentrName = -1;
              
              for ( double& _CentrBinsEdge : _CentrBins ) {
                  
                  ++iCentrName;
                  
                  // Selecting Centrality
                  if ( _CentrVals >= _CentrBinsEdge || iCentrName == 6 ) continue;
                  
                  // Loop over event particles
                  for ( const Particle& Current_Particle : _EventParticles.particles() ) {
                      
                      // Filling histograms for Kaon Star Meson
                      if (Current_Particle.abspid() == 313) {
                          _h[ "Pb.0276.kst.spec." + _CentrName[iCentrName] ]->fill( Current_Particle.pT() / GeV );
                      }
                          
                      // Filling histograms for Phi Meson
                      if (Current_Particle.abspid() == 333) {
                          _h[ "Pb.0276.phi.spec." + _CentrName[iCentrName] ]->fill( Current_Particle.pT() / GeV );
                      }
                      
                      if ( iCentrName == 0 ) {
                          
                          // Filling histograms for Kaon Star Meson
                          if (Current_Particle.abspid() == 313) {
                              _h["Pb.0276.kst.spec.utlt"]->fill( Current_Particle.pT() / GeV );
                          }
                          
                          // Filling histograms for Phi Meson
                          if (Current_Particle.abspid() == 333) {
                              _h["Pb.0276.phi.spec.utlt"]->fill( Current_Particle.pT() / GeV );
                          }
                          
                          // Filling histograms for Kaon Meson
                          if (Current_Particle.abspid() == 321) {
                              _h["Pb.0276.kan.spec.utlK"]->fill( Current_Particle.pT() / GeV );
                              _h["Pb.0276.kan.spec.utlP"]->fill( Current_Particle.pT() / GeV );
                          }
                          
                          // Filling histograms for Kaon Meson
                          if (Current_Particle.abspid() == 211) {
                              _h["Pb.0276.pis.spec.utlK"]->fill( Current_Particle.pT() / GeV );
                              _h["Pb.0276.pis.spec.utlP"]->fill( Current_Particle.pT() / GeV );
                          }
                          
                          // Filling histograms for Proton
                          if (Current_Particle.abspid() == 2212) {
                              _h["Pb.0276.prt.spec.u05K"]->fill( Current_Particle.pT() / GeV );
                              _h["Pb.0276.prt.spec.u05P"]->fill( Current_Particle.pT() / GeV );
                          }
                      }
                      if ( iCentrName == 7 ) {
                          
                          // Filling histograms for Kaon Star Meson
                          if (Current_Particle.abspid() == 313) {
                              _h["Pb.0276.kst.spec.utlt"]->fill( Current_Particle.pT() / GeV );
                          }
                          
                          // Filling histograms for Phi Meson
                          if (Current_Particle.abspid() == 333) {
                              _h["Pb.0276.phi.spec.utlt"]->fill( Current_Particle.pT() / GeV );
                          }
                          
                          // Filling histograms for Proton
                          if (Current_Particle.abspid() == 2212) {
                              _h["Pb.0276.prt.spec.u80K"]->fill( Current_Particle.pT() / GeV );
                              _h["Pb.0276.prt.spec.u80P"]->fill( Current_Particle.pT() / GeV );
                          }
                      }
                  }
                  break;
              }
          }
      }


      /// Normalise histograms etc., after the run
      void finalize() {
          
          // Scaling to number of events
          scale( _h["pp.0276.kst.spec.00_00"], 1./sumW() );
          scale( _h["pp.0276.phi.spec.00_00"], 1./sumW() );
          scale( _h["Pb.0276.kst.spec.utlt"], 1./sumW() );
          scale( _h["pp.0276.kst.spec.utlt"], 1./sumW() );
          scale( _h["Pb.0276.phi.spec.utlt"], 1./sumW() );
          scale( _h["pp.0276.phi.spec.utlt"], 1./sumW() );
          scale( _h["Pb.0276.kan.spec.utlK"], 1./sumW() );
          scale( _h["pp.0276.kan.spec.utlK"], 1./sumW() );
          scale( _h["Pb.0276.kan.spec.utlP"], 1./sumW() );
          scale( _h["pp.0276.kan.spec.utlP"], 1./sumW() );
          scale( _h["Pb.0276.pis.spec.utlK"], 1./sumW() );
          scale( _h["pp.0276.pis.spec.utlK"], 1./sumW() );
          scale( _h["Pb.0276.pis.spec.utlP"], 1./sumW() );
          scale( _h["pp.0276.pis.spec.utlP"], 1./sumW() );
          scale( _h["Pb.0276.prt.spec.u05K"], 1./sumW() );
          scale( _h["Pb.0276.prt.spec.u80K"], 1./sumW() );
          scale( _h["pp.0276.prt.spec.utlK"], 1./sumW() );
          scale( _h["Pb.0276.prt.spec.u05P"], 1./sumW() );
          scale( _h["Pb.0276.prt.spec.u80P"], 1./sumW() );
          scale( _h["pp.0276.prt.spec.utlP"], 1./sumW() );
          for ( string& _CentrNameHisto : _CentrName ) {
              scale( _h["Pb.0276.kst.spec." + _CentrNameHisto ], 1./sumW() );
              scale( _h["Pb.0276.phi.spec." + _CentrNameHisto ], 1./sumW() );
          }
          
          // Ratios to Kaons
          divide(_h["Pb.0276.kst.spec.utlt"],_h["Pb.0276.kan.spec.utlK"],_s["Pb.0276.kst.ovrK.00_05"]);
          divide(_h["pp.0276.kst.spec.utlt"],_h["pp.0276.kan.spec.utlK"],_s["pp.0276.kst.ovrK.00_00"]);
          divide(_h["Pb.0276.phi.spec.utlt"],_h["Pb.0276.kan.spec.utlP"],_s["Pb.0276.phi.ovrK.00_05"]);
          divide(_h["pp.0276.phi.spec.utlt"],_h["pp.0276.kan.spec.utlP"],_s["pp.0276.phi.ovrK.00_00"]);
          
          // Ratios to Pis
          divide(_h["Pb.0276.kst.spec.utlt"],_h["Pb.0276.pis.spec.utlK"],_s["Pb.0276.kst.ovrP.00_05"]);
          divide(_h["pp.0276.kst.spec.utlt"],_h["pp.0276.pis.spec.utlK"],_s["pp.0276.kst.ovrP.00_00"]);
          divide(_h["Pb.0276.phi.spec.utlt"],_h["Pb.0276.pis.spec.utlP"],_s["Pb.0276.phi.ovrP.00_05"]);
          divide(_h["pp.0276.phi.spec.utlt"],_h["pp.0276.pis.spec.utlP"],_s["pp.0276.phi.ovrP.00_00"]);
          
          // Ratios to Protons
          scale( _h["Pb.0276.phi.spec.utlt"], 2. );
          scale( _h["Pb.0276.phi.spec.u80t"], 2. );
          scale( _h["pp.0276.phi.spec.utlt"], 2. );
          divide(_h["Pb.0276.prt.spec.u05K"],_h["Pb.0276.kst.spec.utlt"],_s["Pb.0276.kst.ovPr.00_05"]);
          divide(_h["Pb.0276.prt.spec.u80K"],_h["Pb.0276.kst.spec.u80t"],_s["Pb.0276.kst.ovPr.60_80"]);
          divide(_h["pp.0276.prt.spec.utlK"],_h["pp.0276.kst.spec.utlt"],_s["pp.0276.kst.ovPr.00_00"]);
          divide(_h["Pb.0276.prt.spec.u05P"],_h["Pb.0276.phi.spec.utlt"],_s["Pb.0276.phi.ovPr.00_05"]);
          divide(_h["Pb.0276.prt.spec.u80P"],_h["Pb.0276.phi.spec.u80t"],_s["Pb.0276.phi.ovPr.60_80"]);
          divide(_h["pp.0276.prt.spec.utlP"],_h["pp.0276.phi.spec.utlt"],_s["pp.0276.phi.ovPr.00_00"]);
          scale( _h["pp.0276.phi.spec.utlt"], 1./2. );
          
          // Ratios for R_{AA} calculations
          divide(_h["Pb.0276.kst.spec.00_05"],_h["pp.0276.kst.spec.utlt"],_s["Pb.0276.kst.spec.00_05"]);
          divide(_h["Pb.0276.kst.spec.05_10"],_h["pp.0276.kst.spec.utlt"],_s["Pb.0276.kst.spec.05_10"]);
          divide(_h["Pb.0276.kst.spec.20_30"],_h["pp.0276.kst.spec.utlt"],_s["Pb.0276.kst.spec.20_30"]);
          divide(_h["Pb.0276.kst.spec.40_50"],_h["pp.0276.kst.spec.utlt"],_s["Pb.0276.kst.spec.40_50"]);
          divide(_h["Pb.0276.kst.spec.00_05"],_h["pp.0276.phi.spec.utlt"],_s["Pb.0276.phi.spec.00_05"]);
          divide(_h["Pb.0276.kst.spec.05_10"],_h["pp.0276.phi.spec.utlt"],_s["Pb.0276.phi.spec.05_10"]);
          divide(_h["Pb.0276.kst.spec.20_30"],_h["pp.0276.phi.spec.utlt"],_s["Pb.0276.phi.spec.20_30"]);
          divide(_h["Pb.0276.kst.spec.40_50"],_h["pp.0276.phi.spec.utlt"],_s["Pb.0276.phi.spec.40_50"]);
          
      }

      ///@}


      /// @name Histograms
      ///@{
      
      map<string, Histo1DPtr> _h;
      map<string, Scatter2DPtr> _s;
      
      // Centrality bins used in the analysis
      vector<double> _CentrBins = { 5., 10., 20., 30., 40., 50., 60., 80. };
      vector<string> _CentrName = { "00_05", "05_10", "10_20", "20_30", "30_40", "40_50", "50_60", "60_80" };
      
      ///@}


    };


  DECLARE_RIVET_PLUGIN(ALICE_2022_Test);

}
