#include "CubeProblem.h"
#include "CubeState.h"
#include "CubeAction.h"
#include "CubeAppData.h"
#include "CubeModel.h"
#include "Manhattan.h"
#include <sstream>

namespace ai {
  namespace rubiks {

    Problem::Problem( ai::Search::State *initial_state_in , const std::vector< Cube >& goal_cube_in) 
      : ai::Search::Problem( initial_state_in ), mgoal_cube_in(goal_cube_in), mAllowed_Moves(), mHeuristic(MANHATTAN_CORNERS_EDGES_HEURISTIC)  {

    }

    Problem::~Problem( ) {
      // empty
    }

    bool Problem::GoalTest( const ai::Search::State * const state_in ) const {

      const State * const state = dynamic_cast< const State * const >( state_in );
      for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
        if (mgoal_cube_in[i] == state->getCube()){
          return true;
        }
      }

      return false;
    }
    void Problem::setHeuristic(HeuristicEnum heuristic){

      this->mHeuristic = heuristic;
     // std::cout << "this->mHeuristic" << heuristic << std::endl;
    }

    std::vector<ai::Search::Action *> Problem::Actions( const ai::Search::State * const state_in ) {
      //const State * const rs1 = dynamic_cast<const State * const>(state_in);
      std::vector<ai::Search::Action *> actions;
      for( auto it = mAllowed_Moves.begin( ); it != mAllowed_Moves.end( ); it++ ) {
        actions.push_back(new ai::rubiks::Action(it->second));
      }
      return actions;
    }

    ai::Search::State *Problem::Result( const ai::Search::State * const state_in, const ai::Search::Action * const action_in ) {
      const State * const state = dynamic_cast< const State * const >( state_in );
      const Action * const action = dynamic_cast< const Action * const >( action_in );
      //Cube& Cube::applyMove( const Move& move, const Cube& cube )
      Cube thisCube = state->getCube();
      return new State( thisCube.applyMove(action->getMove(), state->getCube() ) ) ;

    }
    
    double Problem::StepCost( const ai::Search::State  * const state1_in,
                              const ai::Search::Action * const action_in,
                              const ai::Search::State  * const state2_in ) const {
      const Action * const action = dynamic_cast< const Action * const >( action_in );
      return action->getMove( ).getCost( );
    }

    void Problem::setAllowedMoves( const std::map< std::string, Move >& allowed_moves ){

    mAllowed_Moves = allowed_moves;
    

    }
    double Problem::oldHeuristic(const ai::Search::State  * const state_in)const {
      // total of miss place faclets /20
      const State * const state = dynamic_cast< const State * const >( state_in );
      const std::vector< Facelet > mFacelets = state->getCube().getFacelets();
      double misPlaceFacelets = 0.0;
      
      double h = 0.0;
      for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
      const std::vector< Facelet > goalsFacelets = mgoal_cube_in[i].getFacelets();  
          for( int unsigned j = 0; j < goalsFacelets.size( ); j++ ) {
            if((mFacelets[j] != goalsFacelets[j]) && (mFacelets[j] != '*') &&  goalsFacelets[j] != '*' ){
              
              misPlaceFacelets++;
            }
            
          }
          if (h == 0){
              h = misPlaceFacelets;
          }else if (h > misPlaceFacelets ){
              h =  misPlaceFacelets;
          }
          misPlaceFacelets = 0;
      }
      return (h/(double)20.0);
      }
      double Problem::manAllEdgesCornersHeuristic(const ai::Search::State  * const state_in)const{
      const State * const state = dynamic_cast< const State * const >( state_in );
      const std::vector< Facelet > mFacelets = state->getCube().getFacelets();
      double h = 0.0;
      for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
        Manhattan newM;
        double thisGoalH = 0.0;
        (thisGoalH = newM.heursticSumAllFacelets(mFacelets,mgoal_cube_in[i].getFacelets()) );
        if (h == 0){
          h = thisGoalH;
        }else if (h > thisGoalH){
          h = thisGoalH;
        }
         
      }
      // h = (h /(double)mgoal_cube_in.size());
      return h;
      
        
      }
      double Problem::manAllEdgesHeuristic(const ai::Search::State  * const state_in)const{
      const State * const state = dynamic_cast< const State * const >( state_in );
      const std::vector< Facelet > mFacelets = state->getCube().getFacelets();
      double h = 0.0;
      for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
        Manhattan newM;
        double thisGoalH = 0.0;
        (thisGoalH = newM.heursticSumAllFacelets(mFacelets,mgoal_cube_in[i].getFacelets()) );
        if (h == 0){
          h = thisGoalH;
        }else if (h > thisGoalH){
          h = thisGoalH;
        }
        
      }
      return h; 
      }
      double Problem::colorCountHeurisitc(const ai::Search::State * const state_in) const{
      double counter = 0.0;
      const State * const state = dynamic_cast< const State * const >( state_in );
      const std::vector< Facelet > mFacelets = state->getCube().getFacelets();
      std::vector<Facelet> unique;
      unique.push_back('z');
      for( int unsigned j = 0; j < mFacelets.size( ); j++ ) {
        for(int unsigned k = 0; k < unique.size() ;k++){
          if(mFacelets[j] != unique[k] ){
            counter++;
            unique.push_back(mFacelets[j]);
          }
          if(j== 5 || j ==11 || j ==17 || j == 23 || j == 29){
            for(unsigned int m = 0; m < unique.size();m++){
              unique.clear();
            }
          }
        }
      }
      return counter;
    }
    double Problem::Heuristic(const ai::Search::State  * const state_in) const{
      const State * const state = dynamic_cast< const State * const >( state_in );
      double h = 0.0;
      if( mgoal_cube_in.size() == 0) {return 0;}
      switch( mHeuristic ) {
      // 0 old
        case OLD_HEURISTIC:
          default: // fall through
          h = oldHeuristic( state );
          //std::cout << "oldHeuristic" << std::endl;
          break;
          // 1 Manhattan distance for all edges + corners
        case MANHATTAN_CORNERS_EDGES_HEURISTIC:
          //std::cout << "Calling all problem function " << std::endl;
          h = manAllEdgesCornersHeuristic( state );
          break;
        case MANHATTAN_EDGES_HEURISTIC:
          h = manAllEdgesHeuristic( state );
          break;
        case COLOR_COUNT_HEURISTIC:
          h = colorCountHeurisitc(state);
          
          break;

      }
      return h;      
    }
      

    
  
  }
}
    /*old Heuristic **/
    /*      const State * const state = dynamic_cast< const State * const >( state_in );
      const std::vector< Facelet > mFacelets = state->getCube().getFacelets();
      // std::vector<double> heursticPerGoal;
      //const char * const facelets = "wgrboy";
      
      if( mgoal_cube_in.size() == 0) {return 0;}

      for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
      double misPlaceFacelets = 0.0;
      const std::vector< Facelet > goalsFacelets = mgoal_cube_in[i].getFacelets();  
          for( int unsigned j = 0; j < goalsFacelets.size( ); j++ ) {
            if((mFacelets[j] != goalsFacelets[j]) && (mFacelets[j] != '*') &&  goalsFacelets[j] != '*' ){
              
              misPlaceFacelets++;
            }
          }
          heursticPerGoal.push_back(misPlaceFacelets/(double)20.0);
      }

      // for (unsigned int i = 0 ; i < heursticPerGoal.size()-1; i++){
      //   if(heursticPerGoal.size()==1){
      //     break;
      //   }
      //   if(heursticPerGoal[i] < heursticPerGoal[i+1] ){}
      // }
      // for( int unsigned i = 0; i < mFacelets.size( ); i++ ) {
      //   if (mFacelets[i] != facelets[ i / 9 ]){
      //     misPlaceFacelets++;
      //   }
      // }
      //std::cout << misPlaceFacelets/(double)20 << std::endl;
      // return heursticPerGoal[i];
      return (misPlaceFacelets/(double)20.0);*/