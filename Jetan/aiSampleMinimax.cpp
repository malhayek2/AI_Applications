#include "aiSampleMinimax.h"

namespace ai
{
  namespace Jetan
  {
    PlyData::PlyData(double utility_in)
      : move_ok(false),
        utility(utility_in)
    {
    }
    
    Minimax::Minimax(ai::Agent::Options *opts)
    : max_depth(3)
    {
      if(opts->GetArgInt("user1") > 0)
        {
          this->max_depth = opts->GetArgInt("user1");
        }
      {
        char buf[128];
        std::sprintf(buf, "Minimax-%d", this->max_depth);
        SetName(buf);
      }
      
      std::cout << "Options:" << std::endl;
      std::cout << "-U num : maximum search depth (in ply)." << std::endl;
    }
    
    Minimax::~Minimax()
    {
    }
    
    ai::Agent::Action * Minimax::Program(const ai::Agent::Percept * percept)
    {
      ai::Jetan::Action *action = new ai::Jetan::Action;
      // check data memebers!
      std::string board_str = percept->GetAtom("BOARD").GetValue();
      ai::Jetan::Board board(board_str);
      
      int player = atoi(percept->GetAtom("PLAYER_NUMBER").GetValue().c_str());

      PlyData ply_data = this->PickMove(board, player);

      if(ply_data.move_ok)
        {
          action->SetCode(ai::Jetan::Action::MOVE);
          action->SetMove(ply_data.move);
        }
      else
        {
          /* no legal move, or bad choice */
          action->SetCode(ai::Jetan::Action::QUIT);
        }
      return action;
    }

    PlyData Minimax::PickMove(const ai::Jetan::Board &board, int player)
    {
      PlyData ply_data = this->Max(board, player, 1);
      return ply_data;
    }

    PlyData Minimax::Max(const ai::Jetan::Board &board, int player, int depth)
    {
      PlyData ply_data(-1.e6);
      if(board.HaveWinner() || depth > this->max_depth)
        {
          ply_data.utility = this->Evaluate(board, player);
          return ply_data;
        }

      ai::Jetan::Board my_board(board);
      const std::vector<ai::Jetan::MoveData> & moves = my_board.DetermineLegalMoves(player);
      int i;
      for(i = 0; i < (int)moves.size(); i++)
        {
          ai::Jetan::Board tmp_board(board);
          tmp_board.Move(player, moves[i]);
          PlyData tmp_ply_data = this->Min(tmp_board, player, depth + 1 );
          if(tmp_ply_data.utility > ply_data.utility)
            {
              ply_data.utility = tmp_ply_data.utility;
              ply_data.move    = moves[i];
              ply_data.move_ok = true;
            }
        }
      
      return ply_data;
    }
    
    PlyData Minimax::Min(const ai::Jetan::Board &board, int player, int depth)
    {
      PlyData ply_data(1.e6);
      if(board.HaveWinner() || depth > this->max_depth)
        {
          ply_data.utility = this->Evaluate(board, player);
          return ply_data;
        }
      
      int other_player = (player == 1) ? 2 : 1;
      ai::Jetan::Board my_board(board);
      const std::vector<ai::Jetan::MoveData> & moves = my_board.DetermineLegalMoves(other_player);
      int i;
      for(i = 0; i < (int)moves.size(); i++)
        {
          ai::Jetan::Board tmp_board(board);
          tmp_board.Move(other_player, moves[i]);
          PlyData tmp_ply_data = this->Max(tmp_board, player, depth + 1);
          if(tmp_ply_data.utility < ply_data.utility)
            {
              ply_data.utility = tmp_ply_data.utility;
              ply_data.move    = moves[i];
              ply_data.move_ok = true;
            }
        }
      
      return ply_data;
    }
    
    double Minimax::Evaluate(const ai::Jetan::Board &board, int player)
    {
      int winner = board.HaveWinner();
      int other_player = (player == 1) ? 2 : 1;
      /*3 means tie*/
      if(winner == 3)
        { /* tie games are worth 0 */
          return 0.0;
        }
        /**/
      else if(winner == player)
        { /* wins are worth 1 */
          return 1.0;
        }
      else if(winner == other_player)
        { /* wins are worth -1 */
          return -1.0;
        }
        else{

        }
        std::cout << "Player passed value " << player << std::endl;
        //virtual bool Move( int player, const MoveData &move_in ); moves player
        // virtual bool IsLegal( int player, const MoveData &move_in );
        // virtual bool Winner( int player ) const;
        // virtual int HaveWinner( ) const;
        // virtual void DetermineAttackedLocations( int player, SetOfBoardLocations& locations ) const;
        //virtual const std::vector< MoveData >& DetermineLegalMoves( int player );
        //irtual const std::vector< MoveData >& GetLastMoves( ) const;
        //  virtual const std::vector< double >& GetPlayerTimes( ) const;
        //     virtual unsigned int GetTotalMoves( ) const;
        //virtual const BoardData& GetBoard( ) const;
        //virtual void SetBoard( const BoardData &board_in );
        //BoardData currentData = board.GetBoard();
        //std::cout << "currentData.player_turn " << currentData.player_turn  << std::endl;
        ai::Jetan::Board my_board(board);
        const std::vector< ai::Jetan::MoveData > & moves = my_board.DetermineLegalMoves( player );
        const BoardData& data = board.GetBoard( );
        unsigned int i;
        // data.pieces[].mLocation.x 
        // mType( PANTHAN )!
        //      switch( type ) {
        // case WARRIOR:
        //MovePath #0
        // steps dx 0 steps dy 0
        // steps dx 0 steps dy 0
        // MovePath #1 
        // steps dx 0 steps dy -2 (steps) (BoardOffset)
        // steps dx 1 steps dy -2
        // MovePath #2

         for( i = 0; i < 40; i++ ) {
       

          int mtype = (int)data.pieces[i].mType;
          // std::vector< MoveData > legal_moves;
          const std::vector< MovePath > paths = data.pieces[i].mPaths->getPaths() ;
      switch( mtype ) {
      case 0:
        std::cout << "WARRIOR" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << " Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                  for (unsigned k = 0; k < paths.size() ; k++){
                    std::cout << "MovePath #" << k << std::endl;
                    for(unsigned j = 0; j < paths[k].steps.size(); j++){
                    std::cout << "steps dx " <<  (int)paths[k].steps[j].dx  << " steps dy "<< (int)paths[k].steps[i].dy << std::endl;  
                    }
                    
                  }
                  // know legal moves per peice
                  // logic
                  // determine this move will put in danger -1
                  // determine this move kill off a unit (reward based on unit type)
                  // this move doesnt do either look 3 steps into the future? this is advanced!
                  //my_board.Move(player,  const MoveData &move_in)

        break;
      case 1:
        std::cout << "PADWAR" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
        break;
      case 2:
        std::cout << "DWAR" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
        break;
      case 3:
        std::cout << "FLIER" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
        break;
      case 4:
        std::cout << "CHIEF" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
        break;
      case 5:
        std::cout << "PRINCESS" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
        break;
      case 6:
        std::cout << "THOAT" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
        break;
      case 7:
        std::cout << "PANTHAN" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
                  << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
        break;
      default:
        {
          std::stringstream ss;
          ss << "Unknown Jetan::Piece::TYPE ( ";
          ss << (int) mtype;
          ss << " )";
         
        }
      }
          }

          for( i = 0; i < moves.size( ); i++ ) {
        ( ( std::cout ) 
                  << "move " << i << " :: " << moves[ i ]
                  << std::endl );
      }

      // for (unsigned int i = 0; i < 10 ; i++){
      //   for (unsigned int j = 0; j < 10 ; i++){
      //   std::cout << data.squares[i][j] << std::endl;
      //   }
      // }
        // for (unsigned int i= 0;  i < currentData.pieces.size(); i++){
        //   std::cout << currentData.pieces[i] << std::endl;
        // }
        // if (currentData.player_turn == 7){
        //   // tie
        //   return 0.0;
        // }
        return 2;

    }
    
  }
}
