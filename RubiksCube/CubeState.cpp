#include "CubeState.h"
#include "ai_search.h"
#include <iostream>
#include <sstream>

namespace ai {
  namespace rubiks {

    State::State( const Cube& cube )
      : mCube( cube ) {
    }

    State::State( const State& rhs ) {
      *this = rhs;
    }

    State::~State( ) {
    }

    void State::Display() const {         
        mCube.tDisplay(std::cout);
    }

    bool State::IsEqual(const ai::Search::State * const state_in) const {
      const State * const state = dynamic_cast< const State * const >( state_in );
      
      return (mCube == state->mCube);
    }

    bool State::IsLessThan(const ai::Search::State * const state_in) const {
      const State * const state = dynamic_cast< const State * const >( state_in );
      return mCube < state->mCube;
    }

    bool State::operator==( const State& rhs ) const {
      return this->IsEqual( &rhs );
    }

    State& State::operator=( const State& rhs) {
      mCube = rhs.mCube;
      return *this;
    }
    
    const Cube& State::getCube( ) const {
      return mCube;
    }

    Cube& State::getCube( ) {
      return mCube;
    }
      
  }
}

std::ostream& operator<<( std::ostream& os, const ai::rubiks::State& state ) {
  
  // os << "Default" << std::endl;
  return state.getCube().tDisplay(os);
}
