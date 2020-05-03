#ifndef _AISAMPLEMINIMAX_H_
#define _AISAMPLEMINIMAX_H_
#include <ai_jetan.h>
namespace ai
{
  namespace Jetan
  {
    class PlyData
    {
    public:
      PlyData(double utility_in);
      bool move_ok;
      ai::Jetan::MoveData move;
      double utility;
    };
    
    class Minimax : public ai::Agent::AgentProgram
    {
    public:
      Minimax(ai::Agent::Options *opts);
      ~Minimax();
      virtual ai::Agent::Action * Program(const ai::Agent::Percept * percept);
    protected:
      PlyData PickMove(const ai::Jetan::Board &board, int player);
      PlyData Max(const ai::Jetan::Board &board, int player, int depth);
      PlyData Min(const ai::Jetan::Board &board, int player, int depth);

      double Evaluate(const ai::Jetan::Board &board, int player);
    private:
      //for testing prob start with  6-8
      int max_depth;
    };
  }
}
#endif /* _AISAMPLEMINIMAX_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
