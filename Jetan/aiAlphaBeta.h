#ifndef _AIALPHABETA_H_
#define _AIALPHABETA_H_
#include <ai_jetan.h>
#include <vector>
#include "aiSampleMinimax.h"
namespace ai
{
  namespace Jetan
  {
	// class PlyData
 //    {
 //    public:
 //      PlyData(double utility_in);
 //      bool move_ok;
 //      ai::Jetan::MoveData move;
 //      // uti 
 //      double utility;
 //    };
    struct postionValues
    {

      int x;
      int y;
      double value;
      
    };
    class AlphaBeta : public ai::Agent::AgentProgram
    {
    public:
    	enum EvaluationOptions
    	{
    		PIECE_COUNT, PIECE_COUNT_WIN, POSITION_MANHATTAN
    	};
      AlphaBeta(ai::Agent::Options *opts);
      ~AlphaBeta();
      virtual ai::Agent::Action * Program(const ai::Agent::Percept * percept);

    protected:
	  PlyData PickMove(const ai::Jetan::Board &board, int player);
      PlyData Max(const ai::Jetan::Board &board, int player, int depth, double alpha, double beta);
      PlyData Min(const ai::Jetan::Board &board, int player, int depth, double alpha, double beta);
      double EvaluatePieceCount(const ai::Jetan::Board &board, int player);
      double EvaluatePieceCountWin(const ai::Jetan::Board &board, int player);
      double EvaluatePoistionManhattan(const ai::Jetan::Board &board, int player);
      double Evaluate(const ai::Jetan::Board &board, int player);
    private:
	 int max_depth;
	 EvaluationOptions evaluation_method;
    };
  }
}
#endif /*_AIALPHABETA_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
