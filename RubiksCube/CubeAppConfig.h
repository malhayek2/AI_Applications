#ifndef _CUBEAPPCONFIG_H_
#define _CUBEAPPCONFIG_H_

#include <string>
#include <iostream>
#include <map>
#include "CubeProblem.h"

namespace ai {
  namespace rubiks {

    class AppConfig {
    public:
      AppConfig( );
      bool updateOption( const std::string& option, const std::string& value );
      std::string listOptions( ) const;
      void showConfiguration( std::ostream& os ) const;
      
      // allow 180 degree turns as part of the legal moves
      void enableHalfTurns( );
      void disableHalfTurns( );
      bool halfTurns( ) const;

      // allow slice turns as part of the legal moves
      void enableSliceTurns( );
      void disableSliceTurns( );
      bool sliceTurns( ) const;

      // how to display cubes
      void displayCubeAsT( );
      void displayCubeAsOneWord( );
      void displayCubeAsOneLine( );
      bool cubeDisplayT( ) const;
      bool cubeDisplayOneWord( ) const;
      bool cubeDisplayOneLine( ) const;

      // how to display moves
      void displayMoveAsName( );
      void displayMoveAsSubMoves( );
      bool moveDisplayAsName( ) const;
      bool moveDisplayAsSubMoves( ) const;

      // auto transform starting cube's *s to xs
      void enableInitialCubeAutoRemoveWildcard( );
      void disableInitialCubeAutoRemoveWildcard( );
      bool initialCubeAutoRemoveWildcard( ) const;

      // show a prompt for the user
      void enablePrompt( );
      void disablePrompt( );
      bool prompt( ) const;

      // search options
      int depthLimit( ) const;
      void setDepthLimit( const int limit );
      int idsDepth( ) const;
      void setIDSDepth( const int depth );
      int idsLimit( ) const;
      void setIDSLimit( const int limit );
      double aStarLimit( ) const;
      void setAStarLimit( const double limit );
      double generationLimit( ) const;
      void setGenerationLimit( const double limit );
      double storageLimit( ) const;
      void setStorageLimit( const double limit );
      //void setHeuristic(const int heruistic);
      void enableApplySolution( );
      void disableApplySolution( );
      bool applySolution( ) const;

      // how to display search results
      void setDisplaySolutionHuman( );
      void setDisplaySolutionMachine( );
      bool displaySolutionHuman( ) const;
      bool displaySolutionMachine( ) const;
      // heuristic options.
      int heuristic() const;
      void setOldHeuristic();
      void setManhattanEdgesCornersHeuristic();
      void setManhattanEdgesHeuristic( );

    protected:
      std::map< std::string, double > mOptions;

    private:
    };

  }
}


#endif /* _CUBEAPPCONFIG_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
