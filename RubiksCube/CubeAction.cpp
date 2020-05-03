#include "CubeAction.h"
#include <iostream>
namespace ai {
  namespace rubiks {
// contructor with empty
    Action::Action( const Move& move ) 
      : mMove( move ) {
    }

    Action::~Action( ) {
    }

    const Move& Action::getMove( ) const {
      return mMove;
    }

    void Action::Display( ) const {

      std::cout << "Name :" << this->getMove().getName() << "Cost : " << this->getMove().getCost() << std::endl;
    }



  }
}

std::ostream& operator<<( std::ostream& os, const ai::rubiks::Action& action ) {
  os << action.getMove().getName();
  return os;
}
