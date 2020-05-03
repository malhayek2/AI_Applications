
#include <ai_agent.h>

#include "aiSampleManual.h"
#include "aiSampleRandom.h"
#include "aiSampleMinimax.h"
#include "aiAlphaBeta.h"

namespace ai
{
  namespace Agent
  {
    AgentProgram *AgentProgramSelect(Options *opts)
    {
      AgentProgram *agent_program = 0;
      switch(opts->GetArgChr("agent"))
        {
        case 'M':
          agent_program = new ai::Jetan::Manual(opts);
          break;
        case 'r':
          agent_program = new ai::Jetan::Random(opts);
          break;
        case 'x':
          agent_program = new ai::Jetan::Minimax(opts);
          break;
        case 'a':
          agent_program = new ai::Jetan::AlphaBeta(opts);
          break;

        default:
          std::cout << "Unknown agent program " << opts->GetArgChr("agent") << std::endl
                    << "M : Manual" << std::endl
                    << "r : Random" << std::endl
                    << "x : MinMax" << std::endl
                    << "a : AlphaBeta" << std::endl
      
		    << std::endl;
          exit(1);
          break;
        }
      return agent_program;
    }
  }
}
