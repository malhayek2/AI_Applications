#include <cstdio>
#include <cstring>
#include "starterGimliKnowledgeBase.h"
#include <sstream>
#include <vector>
namespace starter
{

  GimliKnowledgeBase::GimliKnowledgeBase()
    : ai::PL::KnowledgeBase(),
    width(4),
    height(4)
  {
    // nothing here
  }
  GimliKnowledgeBase::~GimliKnowledgeBase()
  {
    // nothing here
  }

  void GimliKnowledgeBase::SetSize(int width_in, int height_in) 
  {
    width = width_in;
    height = height_in;
  }

  bool GimliKnowledgeBase::AskGold(int x_in, int y_in)
  {
   bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "Gold_" << x_in << "_" << y_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }
  // not used
  bool GimliKnowledgeBase::AskNoPit(int x_in, int y_in)
  {
  bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "!Pit_" << x_in << "_" << y_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }
  // not used
  bool GimliKnowledgeBase::AskPit(int x_in, int y_in)
  {
  bool rval;
  //bool tval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "Breeze_" << x_in << "_" << y_in;
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }
  // not used
  bool GimliKnowledgeBase::AskNoWumpus(int x_in, int y_in)
  {
  bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "!Wumpus_" << x_in << "_" << y_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }
  // not used
  bool GimliKnowledgeBase::AskWumpus(int x_in, int y_in)
  {
  bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "Stench_" << x_in << "_" << y_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }
  // not used
  bool GimliKnowledgeBase::AskNotSafe(int x_in, int y_in)
  {
 bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "!Safe_" << x_in << "_" << y_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }

  bool GimliKnowledgeBase::AskSafe(int x_in, int y_in)
  {
  bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "Safe_" << x_in << "_" << y_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }

  bool GimliKnowledgeBase::AskVisited(int x_in, int y_in)
  {
  bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "Visited_" << x_in << "_" << y_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }
  
  bool GimliKnowledgeBase::AskAimedAtWumpus(int x_in, int y_in, int direction_in)
  {
  bool rval;
  ai::PL::KnowledgeBase question;
  std::stringstream ss;
  ss << "Aimed_" << x_in << "_" << y_in << "_" << direction_in;  
  question.AddSentence(ss.str());
  rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval)
  {
      return true;
  }
    return false;
  }
  
  void GimliKnowledgeBase::TellNoGlitter(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Glitter_" << x_in << "_" << y_in;
    AddSentence(ss.str());
    ss.str("");
    ss << "!Gold_" << x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellGlitter(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "Glitter_" << x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellNoBreeze(int x_in, int y_in)
  {
    std::stringstream jj;

    jj << "!Breeze_" << x_in << "_" << y_in;

    AddSentence(jj.str());
    std::cout << jj.str() << std::endl;
    int x = x_in;
    int y = y_in;
    jj.str("");
    if(x+1 > width){
      if(y-1 <1){

       jj << "!Breeze_"<< x << "_" << y << " => ((!Pit_" << x << "_" << y << ") & (!Pit_" << x-1 << "_" << y << ") & (!Pit_" << x << "_" << y+1 <<  "))";
              AddSentence(jj.str());
          jj.str("");
      }else{
               jj << "!Breeze_"<< x << "_" << y << " => ((!Pit_" << x << "_" << y << ") & (!Pit_" << x-1 << "_" << y << ") & (!Pit_" << x << "_" << y+1 << ") & (!Pit_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
          jj.str("");
      }
        
    }else if(y+1 > height){
        jj << "!Breeze_"<< x << "_" << y << " => ((!Pit_" << x << "_" << y << ") & (!Pit_" << x+1 << "_" << y << ") & (!Pit_" << x-1 << "_" << y << ") & (!Pit_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
          jj.str("");
        
    }else if (x-1 < 1){
      if(y-1 <1){
         jj << "!Breeze_"<< x << "_" << y << " => ((!Pit_" << x << "_" << y << ") & (!Pit_" << x+1 << "_" << y << ") & (!Pit_" << x << "_" << y+1 <<  "))";
              AddSentence(jj.str());
          jj.str("");
      }else{
                 jj << "!Breeze_"<< x << "_" << y << " => ((!Pit_" << x << "_" << y << ") & (!Pit_" << x+1 << "_" << y << ") & (!Pit_" << x << "_" << y+1 << ") & (!Pit_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
          jj.str("");
      }

        
    }else if (y-1 < 1){
        jj << "!Breeze_"<< x << "_" << y << " => ((!Pit_" << x << "_" << y << ") & (!Pit_" << x+1 << "_" << y << ") & (!Pit_" << x-1 << "_" << y << ") & (!Pit_" << x << "_" << y+1 << "))";
              AddSentence(jj.str());
          jj.str("");
        
    }else{
        jj << "!Breeze_"<< x << "_" << y << " => ((!Pit_" << x << "_" << y << ") & (!Pit_" << x+1 << "_" << y << ") & (!Pit_" << x-1 << "_" << y << ") & (!Pit_" << x << "_" << y+1 << ") & (!Pit_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
          jj.str("");
        
    }
  }
  void GimliKnowledgeBase::TellBreeze(int x_in, int y_in)
  {
  //   bool rval;
  //   ai::PL::KnowledgeBase question;
  //   std::stringstream ss;
  //   ss << "Breeze_" << x_in << "_" << y_in;  
  //   question.AddSentence(ss.str());
  //   ss.str("");
  //   rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  // if(rval == false)
  // {
  //   std::cout << "ask Breeze false" <<std::endl;
  //   std::stringstream ss;
  //   ss << "Breeze_" << x_in << "_" << y_in;
  //   AddSentence(ss.str());
  //}
    std::stringstream ss;

    ss << "Breeze_" << x_in << "_" << y_in;
    std::cout << ss.str() << std::endl;
    AddSentence(ss.str());
    ss.str("");
    int x = x_in;
    int y = y_in;
    ss.str("");
    std::stringstream jj;
        if (x+1 > width){
          if(y-1 <1){
          jj << "Breeze_"<< x << "_" << y << " => ((Pit_" << x << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 <<  "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
          }else{
                      jj << "Breeze_"<< x << "_" << y << " => ((Pit_" << x << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
          }

        }
        else if (x-1 < 1){
          if(y-1 < 1){
          jj << "Breeze_"<< x << "_" << y << " => ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
          }else{
          jj << "Breeze_"<< x << "_" << y << " => ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
          }

        }
        else if (y+1 >height){
          jj << "Breeze_"<< x << "_" << y << " => ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
        }
        else if (y-1 < 1){
          jj << "Breeze_"<< x << "_" << y << " => ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
        }
        else{
          jj << "Breeze_"<< x << "_" << y << " => ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
        }
  }
  void GimliKnowledgeBase::TellNoStench(int x_in, int y_in)
  {
    std::stringstream jj;
    jj << "!Stench_" << x_in << "_" << y_in;
    AddSentence(jj.str());
    std::cout << jj.str() << std::endl;
    jj.str("");
    int x = x_in;
    int y = y_in;
    if(x+1 > width){
      if(y-1 < 1){

       jj << "!Stench_"<< x << "_" << y << " => ((!Wumpus_" << x << "_" << y << ") & (!Wumpus_" << x-1 << "_" << y << ") & (!Wumpus_" << x << "_" << y+1 << "))";
              AddSentence(jj.str());
              std::cout << jj.str() << std::endl;
          jj.str("");
      }else{

       jj << "!Stench_"<< x << "_" << y << " => ((!Wumpus_" << x << "_" << y << ") & (!Wumpus_" << x-1 << "_" << y << ") & (!Wumpus_" << x << "_" << y+1 << ") & (!Wumpus_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
              std::cout << jj.str() << std::endl;
          jj.str("");
      }
        
    }else if(y+1 > height){

        jj << "!Stench_"<< x << "_" << y << " => ((!Wumpus_" << x << "_" << y << ") & (!Wumpus_" << x+1 << "_" << y << ") & (!Pit_" << x-1 << "_" << y << ") & (!Wumpus_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
              std::cout << jj.str() << std::endl;
          jj.str("");
        
    }else if (x-1 < 1){
        if(y-1 <1){
         jj << "!Stench_"<< x << "_" << y << " => ((!Wumpus_" << x << "_" << y << ") & (!Wumpus_" << x+1 << "_" << y << ") & (!Wumpus_" << x << "_" << y+1 <<  "))";
          AddSentence(jj.str());
          std::cout << jj.str() << std::endl;
          jj.str("");
        }else{
           jj << "!Stench_"<< x << "_" << y << " => ((!Wumpus_" << x << "_" << y << ") & (!Wumpus_" << x+1 << "_" << y << ") & (!Wumpus_" << x << "_" << y+1 << ") & (!Wumpus_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
              std::cout << jj.str() << std::endl;
          jj.str("");
        }

        
    }else if (y-1 < 1){
        jj << "!Stench_"<< x << "_" << y << " => ((!Wumpus_" << x << "_" << y << ") & (!Wumpus_" << x+1 << "_" << y << ") & (!Wumpus_" << x-1 << "_" << y << ") & (!Wumpus_" << x << "_" << y+1 << "))";
              AddSentence(jj.str());
              std::cout << jj.str() << std::endl;
          jj.str("");
        
    }else{
        jj << "!Stench_"<< x << "_" << y << " => ((!Wumpus_" << x << "_" << y << ") & (!Wumpus_" << x+1 << "_" << y << ") & (!Wumpus_" << x-1 << "_" << y << ") & (!Wumpus_" << x << "_" << y+1 << ") & (!Wumpus_" << x << "_" << y-1 << "))";
              AddSentence(jj.str());
              std::cout << jj.str() << std::endl;
          jj.str("");
        
    }
  }
  void GimliKnowledgeBase::TellStench(int x_in, int y_in)
  {
    bool rval;
    ai::PL::KnowledgeBase question;
   std::stringstream ss;
    ss << "WD";  
    question.AddSentence(ss.str());
    ss.str("");
    rval = (DPLL_Entails(question) == ai::PL::Symbol::KNOWN_TRUE);
  if(rval == true)
  {
    // std::cout << "ask Stench_ false" <<std::endl;
    // ss << "Stench_" << x_in << "_" << y_in;
    // AddSentence(ss.str());
    // ss.str("");
  }else{
    std::stringstream jj;
    jj << "Stench_" << x_in << "_" << y_in;
    AddSentence(jj.str());
    jj.str("");
    int x = x_in;
    int y = y_in;
    
        // wumpus and a pit can be in the same place
        //ss << "Wumpus_" << x << "_" << y << "=> (!Pit_" << x << "_" << y <<")";
        if (x+1 > width){
          if(y-1<1){
          jj << "Stench_"<< x << "_" << y << " => ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
          }else{
          jj << "Stench_"<< x << "_" << y << " => ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
          }

        }
        else if (x-1 < 1){
          if(y-1 <1){
            jj << "Stench_"<< x << "_" << y << " => ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 <<  "))";
          AddSentence(jj.str());
          jj.str("");            
          }else{

          }

        }
        else if (y+1 >height){
          jj << "Stench_"<< x << "_" << y << " => ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");

        }
        else if (y-1 < 1){

          jj << "Stench_"<< x << "_" << y << " => ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
        

        }
        else{
          jj << "Stench_"<< x << "_" << y << " => ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");

        }
  }
  //  std::cout << "ask Stench_ false" <<std::endl;



  }
  void GimliKnowledgeBase::TellNoPit(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Pit_" << x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellWumpusDead()
  {
    // just call NO wumps everywhere and see how it goes
    // int x, y;
    // for (x = 1; x <= width ; x++){
    //   for (y = 1; y <= height; y++){
    //     TellNoWumpus(x,y);
    //   }
    // }
    std::stringstream ss;
    ss << "WD";
    AddSentence(ss.str());
    ss.str("");

  }
  void GimliKnowledgeBase::TellNoWumpus(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "!Wumpus_" << x_in << "_" << y_in;
    AddSentence(ss.str()); 
  }
  void GimliKnowledgeBase::TellWumpus(int x_in, int y_in)
  {
    std::stringstream ss;
    ss << "Wumpus_" << x_in << "_" << y_in;
    AddSentence(ss.str());
       // std::stringstream ss;
    ss.str("");
    int x;
    int y;
    // int width = 4;
    // int height = 4;
    ss << "Wumpus_" << x_in << "_" << y_in << " <=> ( ";
    for (x = 1; x <= width ; x++){
      for (y = 1; y <= height; y++){
        if (y != y_in && x!= x_in){
            ss << "(!Wumpus_" << x << "_" << y << ")" ;
        if ((x != width || y != height)){
            ss << " & ";
          }
        }

        
      }
    }
    ss << ")";
    std::cout << ss.str() << std::endl;
    AddSentence(ss.str());
  }
  
  void GimliKnowledgeBase::TellVisited(int x_in, int y_in)
  {
    //if visited that means there is no pit and wumpus, and it is Safe
    std::stringstream ss;
    ss << "Visited_" << x_in << "_" << y_in;
    AddSentence(ss.str());
  }
  void GimliKnowledgeBase::TellGlitterRules() 
  {
    // and visited rules
    std::stringstream jj;
    int x, y;
    for (x = 1; x <= width ; x++){
      for (y = 1; y <= height; y++){
      jj << "Glitter_" << x << "_" << y << " <=> " << " Gold_" << x << "_" << y ;
          AddSentence(jj.str());
          jj.str("");
      jj << "Visited_" << x << "_" << y << " => " << "((!Pit_" << x << "_" << y << ")" << " & " << " (!Wumpus_" << x << "_" << y << "))"  ;
          AddSentence(jj.str());
          jj.str("");
      }
    }

  }
void GimliKnowledgeBase::TellBreezeRules()
  {
    int x, y;
    for (x = 1; x <= width ; x++){
      for (y = 1; y <= height; y++){
        std::stringstream jj;
        if (x+1 > width){
          if(y-1 < 1){
            jj << "Breeze_"<< x << "_" << y << " <=> ((Pit_" << x << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
          }else{
          jj << "Breeze_"<< x << "_" << y << " <=> ((Pit_" << x << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
          }

        }
        else if (x-1 < 1){
          if(y-1 < 1 ){
            jj << "Breeze_"<< x << "_" << y << " <=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
          }else{
            jj << "Breeze_"<< x << "_" << y << " <=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
          }

        }
        else if (y+1 >height){
          jj << "Breeze_"<< x << "_" << y << " <=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else if (y-1 < 1){
          jj << "Breeze_"<< x << "_" << y << " <=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else{
          jj << "Breeze_"<< x << "_" << y << " <=> ((Pit_" << x << "_" << y << ") | (Pit_" << x+1 << "_" << y << ") | (Pit_" << x-1 << "_" << y << ") | (Pit_" << x << "_" << y+1 << ") | (Pit_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
      }
    }
  }
  void GimliKnowledgeBase::TellStenchRules()
  {
    int x, y;
    for (x = 1; x <= width; x++){
      for (y = 1; y <= height; y++){
        std::stringstream jj;
        // wumpus and a pit can be in the same place
        //ss << "Wumpus_" << x << "_" << y << "=> (!Pit_" << x << "_" << y <<")";
        if (x+1 > width){
           if(y-1 < 1){
            jj << "Stench_"<< x << "_" << y << " <=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
           }else{
          jj << "Stench_"<< x << "_" << y << " <=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
           }

        }
        else if (x-1 < 1){
          if(y-1 < 1){
            jj << "Stench_"<< x << "_" << y << " <=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 <<  "))";
            AddSentence(jj.str());
            jj.str(""); 
          }else{
            jj << "Stench_"<< x << "_" << y << " <=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") | (Wumpus_" << x << "_" << y-1 << "))";
            AddSentence(jj.str());
            jj.str(""); 
          }
           
        }
        else if (y+1 >height){

          jj << "Stench_"<< x << "_" << y << " <=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else if (y-1 < 1){
          jj << "Stench_"<< x << "_" << y << " <=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << "))";
          AddSentence(jj.str());
          jj.str("");
        }
        else{
          jj << "Stench_"<< x << "_" << y << " <=> ((Wumpus_" << x << "_" << y << ") |(Wumpus_" << x+1 << "_" << y << ") | (Wumpus_" << x-1 << "_" << y << ") | (Wumpus_" << x << "_" << y+1 << ") | (Wumpus_" << x << "_" << y-1 << "))";
          AddSentence(jj.str());
          jj.str("");

        }
      }
    }
    std::cout << "Stench_DONE" << std::endl;
    //DeadWumpus Rules
    // std::stringstream ss;
    // //int x, y;
    // ss << "WD =>";
    // for (x = 1; x <= width ; x++){
    //   for (y = 1; y <= height; y++){
        
    //     ss << "(!Wumpus_" << x << "_" << y << ")" ;
    //     if ((x != width || y != height)){
    //         ss << " & ";
    //     }
        
    //   }
    // }
    // ss << ")";
    // AddSentence(ss.str());
    // ss.str("");
    std::cout << "WD_DONE" << std::endl;
    // Aimed Rules
    std::vector<int> directions;
    directions.push_back(270);
    directions.push_back(180);
    directions.push_back(90);
    directions.push_back(0);
    std::stringstream jj;
    // int x, y;
    // int width = 2;
    // int height = 2;
    for (x = 1; x <= width ; x++){
        for (y = 1; y <= height; y++){
            for (unsigned int i = 0 ; i < directions.size(); i++){
                if(directions[i] == 0){
                   // std::cout << directions[i] << std::endl;
                    jj << "Aimed_"<< x << "_" << y << "_" << directions[i] << " <=>  "; 
                    for (int sub_x = x; sub_x <= width ; sub_x++){
                    jj << " Wumpus_" << sub_x << "_" << y << "";    
                        if(sub_x != width){
                            jj << "|";
                        }
                    }
                    jj << "";
                    AddSentence(jj.str());
                    jj.str("");
                }
                if(directions[i] == 90){
                    jj << "Aimed_"<< x << "_" << y << "_" << directions[i] << " <=>  "; 
                    for (int sub_y = y; sub_y <= height ; sub_y++){
                    jj << "Wumpus_" << x << "_" << sub_y << "" ;    
                        if(sub_y != height){
                            jj << "|";
                        }
                    }
                    jj << "";
                    AddSentence(jj.str());
                    jj.str("");
                    
                }//// # directions 0 => right, 90 => up,180 =>left, 270 => down
                if(directions[i] == 180){
                    jj << " Aimed_"<< x << "_" << y << "_" << directions[i] << " <=>  "; 
                    for (int sub_x = x; sub_x > 0 ; sub_x--){
                    jj << " Wumpus_" << sub_x << "_" << y << "";    
                        if(sub_x != 1){
                            jj << "|";
                        }
                    }
                    jj << "";
                    AddSentence(jj.str());
                    jj.str("");
                    
                }
                if(directions[i] == 270){
                  jj << "Aimed_"<< x << "_" << y << "_" << directions[i] << " <=>  "; 
                    for (int sub_y = y; sub_y > 0 ; sub_y--){
                    jj << "Wumpus_" << x << "_" << sub_y << "";    
                        if(sub_y != 1){
                            jj << "|";
                        }
                    }
                    jj << "";
                    AddSentence(jj.str());
                    jj.str("");
                    
                }     
            }
        }
    }


  }
  void GimliKnowledgeBase::TellSafeRules()
  {
    int x, y;
    std::stringstream ss;
    for( x = 1; x <= width; x++){
      for( y = 1; y <= height; y++ ){
        ss << "Safe_"<< x <<"_"<< y <<" <=> (((!Pit_" << x << "_" << y << ") & (!Wumpus_" << x << "_" << y << ")) | WD)";
        AddSentence(ss.str());
        ss.str("");
      }
    }
    //jj << "Wumpus_1_2 => Safe_2_1";
    // AddSentence(jj.str());
    // jj.str("");
  }

};
