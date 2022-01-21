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

  class ALICE_2022_Test : public Analysis {
  public:

    /// Constructor
    DEFAULT_RIVET_ANALYSIS_CTOR(ALICE_2022_Test);


      /// @name Analysis methods
      ///@{

      /// Book histograms and initialise projections before the run
      void init() {
      
          // Initialise and register projections
          declare( ALICE::PrimaryParticles( Cuts::absrap < 0.5 && Cuts::abscharge == 1 ), "AliPrimary" );
          
          // Declare centrality projection
          //declareCentrality(ALICE::V0MMultiplicity(), "ALICE_2015_PBPBCentrality", "V0M", "V0M");
          
          // Book histograms for pT spectra
          book(_h1D["ptspec.0333.1D"],  100,  0.,     30. );
          book(_h2D["ptspec.0333.2D"],  100,  0.,     30.,    100,    0., 30. );
          
          // Book histograms for production statistics
          book(_h1D["prdprb.0333.XD"],  10,   -0.5,   9.5 );
          
      }

      /// Perform the per-event analysis
      void analyze( const Event& event ) {
          
          // Analysis physics selection
          const ALICE::PrimaryParticles &_EventParticles = applyProjection<ALICE::PrimaryParticles>( event, "AliPrimary" );
          
          // Identify the beam ID
          //PdgIdPair _BeamType = beamIds();
          
          std::vector<Particle> kCurrent_Event_Phis;
          // Loop over event particles
          for ( const Particle& Current_Particle : _EventParticles.Particles() ) {
              // Selecting phi
              if ( Current_Particle.abspid() == 333 ) kCurrent_Event_Phis.push_back( Particle );
          }
          
          // Second loop to work on the phis
          for ( const Particle& iCurrent_Particle : kCurrent_Event_Phis ) {
              //
              _h1D["ptspec.0333.1D"]->fill( iCurrent_Particle.pT()/GeV );
              //
              for ( const Particle& jCurrent_Particle : kCurrent_Event_Phis ) {
                  //
                  _h2D["ptspec.0333.2D"]->fill( iCurrent_Particle.pT()/GeV, jCurrent_Particle.pT()/GeV );
                  //
              }
          }
          
          // Histrograms that do no need loop
          _h1D["ptspec.0333.1D"]->fill( kCurrent_Event_Phis.size() );
      }


      /// Normalise histograms etc., after the run
      void finalize() {
          
          // Scaling to number of events
          scale( _h1D["ptspec.0333.1D"], 1./sumW() );
          scale( _h2D["ptspec.0333.2D"], 1./sumW() );
          scale( _h1D["prdprb.0333.XD"], 1./sumW() );
          
      }

      ///@}


      /// @name Histograms
      ///@{
      
      map<string, Histo1DPtr> _h1D;
      map<string, Histo2DPtr> _h2D;
      map<string, Scatter2DPtr> _s;
      
      // Centrality bins used in the analysis
      vector<double> _CentrBins = { 5., 10., 20., 30., 40., 50., 60., 80. };
      vector<string> _CentrName = { "00_05", "05_10", "10_20", "20_30", "30_40", "40_50", "50_60", "60_80" };
      
      ///@}


    };


  DECLARE_RIVET_PLUGIN(ALICE_2022_Test);

}
