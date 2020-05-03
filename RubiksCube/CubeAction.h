#ifndef _CUBEACTION_H_
#define _CUBEACTION_H_

#include "ai_search.h"
#include "CubeModel.h"

namespace ai {
  namespace rubiks {

    class Action : public ai::Search::Action {
    public:

      Action( const Move& move );
      virtual ~Action( );
      virtual void Display( ) const;
      
      const Move& getMove( ) const;
      
    protected:
      Move mMove;
      
    private:
      
    };

  }
}

std::ostream& operator<<( std::ostream& os, const ai::rubiks::Action& action );



#endif /* _CUBEACTION_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
