#ifndef _AIMOSPH_H_
#define _AIMOSPH_H_
#include <ai_jetan.h>
#include <vector>
#include "aiSampleMinimax.h"
#include "aiAlphaBeta.h"
namespace ai
{
  namespace Jetan
  {
    // struct postionValues
    // {

    //   int x;
    //   int y;
    //   double value;
      
    // };
	// class PlyData
 //    {
 //    public:
 //      PlyData(double utility_in);
 //      bool move_ok;
 //      ai::Jetan::MoveData move;
 //      // uti 
 //      double utility;
 //    };

    class Mosph : public ai::Agent::AgentProgram
    {
    public:
    	enum EvaluationOptions
    	{
    		PIECE_COUNT, PIECE_COUNT_WIN
    	};
      Mosph(ai::Agent::Options *opts);
      ~Mosph();
      virtual ai::Agent::Action * Program(const ai::Agent::Percept * percept);

    protected:
	  PlyData PickMove(const ai::Jetan::Board &board, int player);
      PlyData Max(const ai::Jetan::Board &board, int player, int depth, double alpha, double beta);
      PlyData Min(const ai::Jetan::Board &board, int player, int depth, double alpha, double beta);
      double getPieceValue(const ai::Jetan::Board &board, int player);
      double EvaluatePieceCount(const ai::Jetan::Board &board, int player);
      double EvaluatePieceCountWin(const ai::Jetan::Board &board, int player);
      double Evaluate(const ai::Jetan::Board &board, int player);
    private:
	 int max_depth;
	 EvaluationOptions evaluation_method;

    };
  }
}
#endif /*_AIMOSPH_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
