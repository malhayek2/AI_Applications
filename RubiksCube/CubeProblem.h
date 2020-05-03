#ifndef _CUBEPROBLEM_H_
#define _CUBEPROBLEM_H_

#include "ai_search.h"
#include "CubeModel.h"
#include <map>
namespace ai {
  namespace rubiks {
    
    class Problem : public ai::Search::Problem {

    public:
      enum HeuristicEnum{OLD_HEURISTIC, MANHATTAN_CORNERS_EDGES_HEURISTIC,  MANHATTAN_EDGES_HEURISTIC, COLOR_COUNT_HEURISTIC=10};
      Problem( ai::Search::State *initial_state_in, const std::vector< Cube >& goal_cube_in );
      // Problem( ai::Search::State *initial_state_in );
      virtual ~Problem( );
      
      virtual bool GoalTest( const ai::Search::State * const state_in ) const;
      virtual std::vector<ai::Search::Action *> Actions( const ai::Search::State * const state_in );
      virtual ai::Search::State *Result( const ai::Search::State * const state_in, const ai::Search::Action * const action_in );
      //added
      void setAllowedMoves( const std::map< std::string, Move >& allowed_moves );
      virtual double Heuristic(const ai::Search::State  * const state_in) const;
      double oldHeuristic(const ai::Search::State  * const state_in) const;
      double manAllEdgesHeuristic(const ai::Search::State  * const state_in) const ;
      double manAllEdgesCornersHeuristic(const ai::Search::State  * const state_in) const ;
      double colorCountHeurisitc(const ai::Search::State * const state_in) const;
      void setHeuristic(HeuristicEnum heuristic);
      virtual double StepCost( const ai::Search::State  * const state1_in,
                               const ai::Search::Action * const action_in,
                               const ai::Search::State  * const state2_in ) const;
      
    protected:
      const std::vector< Cube >& mgoal_cube_in;
      std::map< std::string, Move > mAllowed_Moves;
      // int mHeuristic;
         
      HeuristicEnum mHeuristic;
    };
    
  }
}


#endif /* _RECTANGLEPROBLEM_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
