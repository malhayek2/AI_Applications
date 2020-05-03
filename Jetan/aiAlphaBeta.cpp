#include "aiAlphaBeta.h"
#include <ctime>
#include <cstdlib>
#include <sstream>

namespace ai
{
  namespace Jetan
  {
    // PlyData::PlyData(double utility_in)
    //   : move_ok(false),

    //     utility(utility_in)
    // {
    // }
    
      const double MY_INFINITY = 1.e10;
      std::vector<postionValues> warrior;
      std::vector<postionValues> padwar;
      std::vector<postionValues> dwar;
      std::vector<postionValues> flier;
      std::vector<postionValues> chief;
      std::vector<postionValues> princess;
      std::vector<postionValues> thoat;
      std::vector<postionValues> pathan;
        void construcThoat(){
      //first row
      thoat.push_back(postionValues({0, 9,-5.0}));
      thoat.push_back(postionValues({1, 9,-4.0}));
      thoat.push_back(postionValues({2, 9,-3.0}));
      thoat.push_back(postionValues({3, 9,-3.0}));
      thoat.push_back(postionValues({4, 9,-3.0}));
      thoat.push_back(postionValues({5, 9,-3.0}));
      thoat.push_back(postionValues({6, 9,-3.0}));
      thoat.push_back(postionValues({7, 9,-3.0}));
      thoat.push_back(postionValues({8, 9,-4.0}));
      thoat.push_back(postionValues({9, 9,-5.0}));
      //second row
      thoat.push_back(postionValues({0, 8,-4.0}));
      thoat.push_back(postionValues({1, 8,-2.0}));
      thoat.push_back(postionValues({2, 8, 0.0}));
      thoat.push_back(postionValues({3, 8, 0.0}));
      thoat.push_back(postionValues({4, 8, 0.0}));
      thoat.push_back(postionValues({5, 8, 0.0}));
      thoat.push_back(postionValues({6, 8, 0.0}));
      thoat.push_back(postionValues({7, 8, 0.0}));
      thoat.push_back(postionValues({8, 8,-2.0}));
      thoat.push_back(postionValues({9, 8,-4.0}));
      //thrid row
      thoat.push_back(postionValues({0, 7,-3.0}));
      thoat.push_back(postionValues({1, 7, 0.5}));
      thoat.push_back(postionValues({2, 7, 0.5}));
      thoat.push_back(postionValues({3, 7, 1.0}));
      thoat.push_back(postionValues({4, 7, 1.5}));
      thoat.push_back(postionValues({5, 7, 1.5}));
      thoat.push_back(postionValues({6, 7, 1.0}));
      thoat.push_back(postionValues({7, 7, 0.5}));
      thoat.push_back(postionValues({8, 7, 0.5}));
      thoat.push_back(postionValues({9, 7,-3.0}));
      //4th ro
      thoat.push_back(postionValues({0, 6,-3.0}));
      thoat.push_back(postionValues({1, 6, 0.0}));
      thoat.push_back(postionValues({2, 6, 1.5}));
      thoat.push_back(postionValues({3, 6, 1.5}));
      thoat.push_back(postionValues({4, 6, 2.0}));
      thoat.push_back(postionValues({5, 6, 2.0}));
      thoat.push_back(postionValues({6, 6, 2.0}));
      thoat.push_back(postionValues({7, 6, 1.5}));
      thoat.push_back(postionValues({8, 6, 1.5}));
      thoat.push_back(postionValues({9, 6,-3.0}));
      //5th ro
      thoat.push_back(postionValues({0, 5,-3.0}));
      thoat.push_back(postionValues({1, 5, 0.5}));
      thoat.push_back(postionValues({2, 5, 2.0}));
      thoat.push_back(postionValues({3, 5, 2.0}));
      thoat.push_back(postionValues({4, 5, 2.5}));
      thoat.push_back(postionValues({5, 5, 2.5}));
      thoat.push_back(postionValues({6, 5, 2.5}));
      thoat.push_back(postionValues({7, 5, 2.0}));
      thoat.push_back(postionValues({8, 5, 0.5}));
      thoat.push_back(postionValues({9, 5,-3.0}));
      //6th ro
      thoat.push_back(postionValues({0, 4,-3.0}));
      thoat.push_back(postionValues({1, 4, 0.5}));
      thoat.push_back(postionValues({2, 4, 2.0}));
      thoat.push_back(postionValues({3, 4, 2.0}));
      thoat.push_back(postionValues({4, 4, 2.5}));
      thoat.push_back(postionValues({5, 4, 2.5}));
      thoat.push_back(postionValues({6, 4, 2.5}));
      thoat.push_back(postionValues({7, 4, 2.0}));
      thoat.push_back(postionValues({8, 4, 0.5}));
      thoat.push_back(postionValues({9, 4,-3.0}));
      //7th
      thoat.push_back(postionValues({0, 3,-3.0}));
      thoat.push_back(postionValues({1, 3,-0.5}));
      thoat.push_back(postionValues({2, 3, 0.5}));
      thoat.push_back(postionValues({3, 3, 0.5}));
      thoat.push_back(postionValues({4, 3, 1.0}));
      thoat.push_back(postionValues({5, 3, 1.0}));
      thoat.push_back(postionValues({6, 3, 1.5}));
      thoat.push_back(postionValues({7, 3, 1.0}));
      thoat.push_back(postionValues({8, 3,-0.5}));
      thoat.push_back(postionValues({9, 3,-3.0}));
      //8th
      thoat.push_back(postionValues({0, 2,-3.0}));
      thoat.push_back(postionValues({1, 2,-1.0}));
      thoat.push_back(postionValues({2, 2, 0.0}));
      thoat.push_back(postionValues({3, 2, 0.0}));
      thoat.push_back(postionValues({4, 2, 1.0}));
      thoat.push_back(postionValues({5, 2, 1.0}));
      thoat.push_back(postionValues({6, 2, 1.0}));
      thoat.push_back(postionValues({7, 2, 0.0}));
      thoat.push_back(postionValues({8, 2,-1.0}));
      thoat.push_back(postionValues({9, 2,-3.0}));
      //9th
      thoat.push_back(postionValues({0, 1,-4.0}));
      thoat.push_back(postionValues({1, 1,-2.0}));
      thoat.push_back(postionValues({2, 1,-1.0}));
      thoat.push_back(postionValues({3, 1,-1.0}));
      thoat.push_back(postionValues({4, 1,-0.5}));
      thoat.push_back(postionValues({5, 1,-0.5}));
      thoat.push_back(postionValues({6, 1,-1.0}));
      thoat.push_back(postionValues({7, 1,-1.0}));
      thoat.push_back(postionValues({8, 1,-2.0}));
      thoat.push_back(postionValues({9, 1,-4.0}));
      //10t
      thoat.push_back(postionValues({0, 0,-5.0}));
      thoat.push_back(postionValues({1, 0,-4.0}));
      thoat.push_back(postionValues({2, 0,-3.0}));
      thoat.push_back(postionValues({3, 0,-3.0}));
      thoat.push_back(postionValues({4, 0,-2.0}));
      thoat.push_back(postionValues({5, 0,-2.0}));
      thoat.push_back(postionValues({6, 0,-2.0}));
      thoat.push_back(postionValues({7, 0,-3.0}));
      thoat.push_back(postionValues({8, 0,-4.0}));
      thoat.push_back(postionValues({9, 0,-5.0}));
    }
    void construcpathan(){
      //first row
      pathan.push_back(postionValues({0, 9, 0.0}));
      pathan.push_back(postionValues({1, 9,0.0}));
      pathan.push_back(postionValues({2, 9,0.0}));
      pathan.push_back(postionValues({3, 9,0.0}));
      pathan.push_back(postionValues({4, 9,0.0}));
      pathan.push_back(postionValues({5, 9,0.0}));
      pathan.push_back(postionValues({6, 9,0.0}));
      pathan.push_back(postionValues({7, 9,0.0}));
      pathan.push_back(postionValues({8, 9,0.0}));
      pathan.push_back(postionValues({9, 9,0.0}));
      //second row
      pathan.push_back(postionValues({0, 8, 0.5}));
      pathan.push_back(postionValues({1, 8, 0.5}));
      pathan.push_back(postionValues({2, 8, -1.0}));
      pathan.push_back(postionValues({3, 8, -1.0}));
      pathan.push_back(postionValues({4, 8, -2.0}));
      pathan.push_back(postionValues({5, 8, -2.0}));
      pathan.push_back(postionValues({6, 8, -2.0}));
      pathan.push_back(postionValues({7, 8, -1.0}));
      pathan.push_back(postionValues({8, 8, 0.5}));
      pathan.push_back(postionValues({9, 8, 0.5}));
      //thrid row
      pathan.push_back(postionValues({0, 7, 2.0}));
      pathan.push_back(postionValues({1, 7, 2.0}));
      pathan.push_back(postionValues({2, 7, 2.0}));
      pathan.push_back(postionValues({3, 7, 2.0}));
      pathan.push_back(postionValues({4, 7, 2.0}));
      pathan.push_back(postionValues({5, 7, 2.0}));
      pathan.push_back(postionValues({6, 7, 2.0}));
      pathan.push_back(postionValues({7, 7, 2.0}));
      pathan.push_back(postionValues({8, 7, 2.0}));
      pathan.push_back(postionValues({9, 7, 2.0}));
      //4th ro
      pathan.push_back(postionValues({0, 6, 3.0}));
      pathan.push_back(postionValues({1, 6,3.0}));
      pathan.push_back(postionValues({2, 6, 3.0}));
      pathan.push_back(postionValues({3, 6, 3.0}));
      pathan.push_back(postionValues({4, 6, 3.0}));
      pathan.push_back(postionValues({5, 6, 3.0}));
      pathan.push_back(postionValues({6, 6, 3.0}));
      pathan.push_back(postionValues({7, 6, 3.0}));
      pathan.push_back(postionValues({8, 6, 3.0}));
      pathan.push_back(postionValues({9, 6, 3.0}));
      //5th row
      pathan.push_back(postionValues({0, 5, 3.3}));
      pathan.push_back(postionValues({1, 5, 3.3}));
      pathan.push_back(postionValues({2, 5, 3.3}));
      pathan.push_back(postionValues({3, 5, 3.3}));
      pathan.push_back(postionValues({4, 5, 3.3}));
      pathan.push_back(postionValues({5, 5, 3.3}));
      pathan.push_back(postionValues({6, 5, 3.3}));
      pathan.push_back(postionValues({7, 5, 3.3}));
      pathan.push_back(postionValues({8, 5, 3.3}));
      pathan.push_back(postionValues({9, 5, 3.3}));
      //6th row
      pathan.push_back(postionValues({0, 4, 3.5}));
      pathan.push_back(postionValues({1, 4, 3.5}));
      pathan.push_back(postionValues({2, 4, 3.5}));
      pathan.push_back(postionValues({3, 4, 3.5}));
      pathan.push_back(postionValues({4, 4, 3.5}));
      pathan.push_back(postionValues({5, 4, 3.5}));
      pathan.push_back(postionValues({6, 4, 3.5}));
      pathan.push_back(postionValues({7, 4, 3.5}));
      pathan.push_back(postionValues({8, 4, 3.5}));
      pathan.push_back(postionValues({9, 4, 3.5}));
      //7t4
      pathan.push_back(postionValues({0, 3, 4.0}));
      pathan.push_back(postionValues({1, 3, 4.0}));
      pathan.push_back(postionValues({2, 3, 4.0}));
      pathan.push_back(postionValues({3, 3, 4.0}));
      pathan.push_back(postionValues({4, 3, 4.0}));
      pathan.push_back(postionValues({5, 3, 4.0}));
      pathan.push_back(postionValues({6, 3, 4.0}));
      pathan.push_back(postionValues({7, 3, 4.0}));
      pathan.push_back(postionValues({8, 3, 4.0}));
      pathan.push_back(postionValues({9, 3, 4.0}));
      //8t3
      pathan.push_back(postionValues({0, 2, 4.5}));
      pathan.push_back(postionValues({1, 2, 4.5}));
      pathan.push_back(postionValues({2, 2, 4.5}));
      pathan.push_back(postionValues({3, 2, 4.5}));
      pathan.push_back(postionValues({4, 2, 4.5}));
      pathan.push_back(postionValues({5, 2, 4.5}));
      pathan.push_back(postionValues({6, 2, 4.5}));
      pathan.push_back(postionValues({7, 2, 4.5}));
      pathan.push_back(postionValues({8, 2, 4.5}));
      pathan.push_back(postionValues({9, 2, 4.5}));
      //9t
      pathan.push_back(postionValues({0, 1, 5.0}));
      pathan.push_back(postionValues({1, 1, 5.0}));
      pathan.push_back(postionValues({2, 1, 5.0}));
      pathan.push_back(postionValues({3, 1, 5.0}));
      pathan.push_back(postionValues({4, 1, 5.0}));
      pathan.push_back(postionValues({5, 1, 5.0}));
      pathan.push_back(postionValues({6, 1, 5.0}));
      pathan.push_back(postionValues({7, 1, 5.0}));
      pathan.push_back(postionValues({8, 1, 5.0}));
      pathan.push_back(postionValues({9, 1, 5.0}));
      //10th
      pathan.push_back(postionValues({0, 0, 0.0}));
      pathan.push_back(postionValues({1, 0, 0.0}));
      pathan.push_back(postionValues({2, 0, 0.0}));
      pathan.push_back(postionValues({3, 0, 0.0}));
      pathan.push_back(postionValues({4, 0, 0.0}));
      pathan.push_back(postionValues({5, 0, 0.0}));
      pathan.push_back(postionValues({6, 0, 0.0}));
      pathan.push_back(postionValues({7, 0, 0.0}));
      pathan.push_back(postionValues({8, 0, 0.0}));
      pathan.push_back(postionValues({9, 0, 0.0}));
    }
    // warrior might need to be next to someone 
    void construcwarrior(){
      //first row
      warrior.push_back(postionValues({0, 9,-5.0}));
      warrior.push_back(postionValues({1, 9,-4.0}));
      warrior.push_back(postionValues({2, 9,-3.0}));
      warrior.push_back(postionValues({3, 9,-3.0}));
      warrior.push_back(postionValues({4, 9,-3.0}));
      warrior.push_back(postionValues({5, 9,-3.0}));
      warrior.push_back(postionValues({6, 9,-3.0}));
      warrior.push_back(postionValues({7, 9,-3.0}));
      warrior.push_back(postionValues({8, 9,-4.0}));
      warrior.push_back(postionValues({9, 9,-5.0}));
      //second ro
      warrior.push_back(postionValues({0, 8,-4.0}));
      warrior.push_back(postionValues({1, 8,-2.0}));
      warrior.push_back(postionValues({2, 8, 0.0}));
      warrior.push_back(postionValues({3, 8, 0.0}));
      warrior.push_back(postionValues({4, 8, 0.0}));
      warrior.push_back(postionValues({5, 8, 0.0}));
      warrior.push_back(postionValues({6, 8, 0.0}));
      warrior.push_back(postionValues({7, 8, 0.0}));
      warrior.push_back(postionValues({8, 8,-2.0}));
      warrior.push_back(postionValues({9, 8,-4.0}));
      //thrid row
      warrior.push_back(postionValues({0, 7,-3.0}));
      warrior.push_back(postionValues({1, 7, 0.5}));
      warrior.push_back(postionValues({2, 7, 0.5}));
      warrior.push_back(postionValues({3, 7, 1.0}));
      warrior.push_back(postionValues({4, 7, 1.5}));
      warrior.push_back(postionValues({5, 7, 1.5}));
      warrior.push_back(postionValues({6, 7, 1.0}));
      warrior.push_back(postionValues({7, 7, 0.5}));
      warrior.push_back(postionValues({8, 7, 0.5}));
      warrior.push_back(postionValues({9, 7,-3.0}));
      //4th ro
      warrior.push_back(postionValues({0, 6,-3.0}));
      warrior.push_back(postionValues({1, 6, 0.0}));
      warrior.push_back(postionValues({2, 6, 1.5}));
      warrior.push_back(postionValues({3, 6, 1.5}));
      warrior.push_back(postionValues({4, 6, 2.0}));
      warrior.push_back(postionValues({5, 6, 2.0}));
      warrior.push_back(postionValues({6, 6, 2.0}));
      warrior.push_back(postionValues({7, 6, 1.5}));
      warrior.push_back(postionValues({8, 6, 1.5}));
      warrior.push_back(postionValues({9, 6,-3.0}));
      //5th row
      warrior.push_back(postionValues({0, 5,-3.0}));
      warrior.push_back(postionValues({1, 5, 0.5}));
      warrior.push_back(postionValues({2, 5, 2.0}));
      warrior.push_back(postionValues({3, 5, 2.0}));
      warrior.push_back(postionValues({4, 5, 2.5}));
      warrior.push_back(postionValues({5, 5, 2.5}));
      warrior.push_back(postionValues({6, 5, 2.5}));
      warrior.push_back(postionValues({7, 5, 2.0}));
      warrior.push_back(postionValues({8, 5, 0.5}));
      warrior.push_back(postionValues({9, 5,-3.0}));
      //6th ro
      warrior.push_back(postionValues({0, 4,-3.0}));
      warrior.push_back(postionValues({1, 4, 0.5}));
      warrior.push_back(postionValues({2, 4, 2.0}));
      warrior.push_back(postionValues({3, 4, 2.0}));
      warrior.push_back(postionValues({4, 4, 2.5}));
      warrior.push_back(postionValues({5, 4, 2.5}));
      warrior.push_back(postionValues({6, 4, 2.5}));
      warrior.push_back(postionValues({7, 4, 2.0}));
      warrior.push_back(postionValues({8, 4, 0.5}));
      warrior.push_back(postionValues({9, 4,-3.0}));
      //7th
      warrior.push_back(postionValues({0, 3,-3.0}));
      warrior.push_back(postionValues({1, 3,-0.5}));
      warrior.push_back(postionValues({2, 3, 0.5}));
      warrior.push_back(postionValues({3, 3, 0.5}));
      warrior.push_back(postionValues({4, 3, 1.0}));
      warrior.push_back(postionValues({5, 3, 1.0}));
      warrior.push_back(postionValues({6, 3, 1.5}));
      warrior.push_back(postionValues({7, 3, 1.0}));
      warrior.push_back(postionValues({8, 3,-0.5}));
      warrior.push_back(postionValues({9, 3,-3.0}));
      //8th
      warrior.push_back(postionValues({0, 2,-3.0}));
      warrior.push_back(postionValues({1, 2,-1.0}));
      warrior.push_back(postionValues({2, 2, 0.0}));
      warrior.push_back(postionValues({3, 2, 0.0}));
      warrior.push_back(postionValues({4, 2, 1.0}));
      warrior.push_back(postionValues({5, 2, 1.0}));
      warrior.push_back(postionValues({6, 2, 1.0}));
      warrior.push_back(postionValues({7, 2, 0.0}));
      warrior.push_back(postionValues({8, 2,-1.0}));
      warrior.push_back(postionValues({9, 2,-3.0}));
      //9th
      warrior.push_back(postionValues({0, 1,-4.0}));
      warrior.push_back(postionValues({1, 1,-2.0}));
      warrior.push_back(postionValues({2, 1,-1.0}));
      warrior.push_back(postionValues({3, 1,-1.0}));
      warrior.push_back(postionValues({4, 1,-0.5}));
      warrior.push_back(postionValues({5, 1,-0.5}));
      warrior.push_back(postionValues({6, 1,-1.0}));
      warrior.push_back(postionValues({7, 1,-1.0}));
      warrior.push_back(postionValues({8, 1,-2.0}));
      warrior.push_back(postionValues({9, 1,-4.0}));
      //10th
      warrior.push_back(postionValues({0, 0,-5.0}));
      warrior.push_back(postionValues({1, 0,-4.0}));
      warrior.push_back(postionValues({2, 0,-3.0}));
      warrior.push_back(postionValues({3, 0,-3.0}));
      warrior.push_back(postionValues({4, 0,-2.0}));
      warrior.push_back(postionValues({5, 0,-2.0}));
      warrior.push_back(postionValues({6, 0,-2.0}));
      warrior.push_back(postionValues({7, 0,-3.0}));
      warrior.push_back(postionValues({8, 0,-4.0}));
      warrior.push_back(postionValues({9, 0,-5.0}));
    }
    void construcpadwar(){
      //first row
      padwar.push_back(postionValues({0, 9,-5.0}));
      padwar.push_back(postionValues({1, 9,-4.0}));
      padwar.push_back(postionValues({2, 9,-3.0}));
      padwar.push_back(postionValues({3, 9,-3.0}));
      padwar.push_back(postionValues({4, 9,-3.0}));
      padwar.push_back(postionValues({5, 9,-3.0}));
      padwar.push_back(postionValues({6, 9,-3.0}));
      padwar.push_back(postionValues({7, 9,-3.0}));
      padwar.push_back(postionValues({8, 9,-4.0}));
      padwar.push_back(postionValues({9, 9,-5.0}));
      //second row
      padwar.push_back(postionValues({0, 8,-4.0}));
      padwar.push_back(postionValues({1, 8,-2.0}));
      padwar.push_back(postionValues({2, 8, 0.0}));
      padwar.push_back(postionValues({3, 8, 0.0}));
      padwar.push_back(postionValues({4, 8, 0.0}));
      padwar.push_back(postionValues({5, 8, 0.0}));
      padwar.push_back(postionValues({6, 8, 0.0}));
      padwar.push_back(postionValues({7, 8, 0.0}));
      padwar.push_back(postionValues({8, 8,-2.0}));
      padwar.push_back(postionValues({9, 8,-4.0}));
      //thrid row
      padwar.push_back(postionValues({0, 7,-3.0}));
      padwar.push_back(postionValues({1, 7, 0.5}));
      padwar.push_back(postionValues({2, 7, 0.5}));
      padwar.push_back(postionValues({3, 7, 1.0}));
      padwar.push_back(postionValues({4, 7, 1.5}));
      padwar.push_back(postionValues({5, 7, 1.5}));
      padwar.push_back(postionValues({6, 7, 1.0}));
      padwar.push_back(postionValues({7, 7, 0.5}));
      padwar.push_back(postionValues({8, 7, 0.5}));
      padwar.push_back(postionValues({9, 7,-3.0}));
      //4th ro
      padwar.push_back(postionValues({0, 6,-3.0}));
      padwar.push_back(postionValues({1, 6, 0.0}));
      padwar.push_back(postionValues({2, 6, 1.5}));
      padwar.push_back(postionValues({3, 6, 1.5}));
      padwar.push_back(postionValues({4, 6, 2.0}));
      padwar.push_back(postionValues({5, 6, 2.0}));
      padwar.push_back(postionValues({6, 6, 2.0}));
      padwar.push_back(postionValues({7, 6, 1.5}));
      padwar.push_back(postionValues({8, 6, 1.5}));
      padwar.push_back(postionValues({9, 6,-3.0}));
      //5th ro
      padwar.push_back(postionValues({0, 5,-3.0}));
      padwar.push_back(postionValues({1, 5, 0.5}));
      padwar.push_back(postionValues({2, 5, 1.0}));
      padwar.push_back(postionValues({3, 5, 1.0}));
      padwar.push_back(postionValues({4, 5, 2.5}));
      padwar.push_back(postionValues({5, 5, 2.5}));
      padwar.push_back(postionValues({6, 5, 1.5}));
      padwar.push_back(postionValues({7, 5, 1.0}));
      padwar.push_back(postionValues({8, 5, 0.5}));
      padwar.push_back(postionValues({9, 5,-3.0}));
      //6th row
      padwar.push_back(postionValues({0, 4,-3.0}));
      padwar.push_back(postionValues({1, 4, 0.5}));
      padwar.push_back(postionValues({2, 4, 1.0}));
      padwar.push_back(postionValues({3, 4, 1.0}));
      padwar.push_back(postionValues({4, 4, 2.5}));
      padwar.push_back(postionValues({5, 4, 1.5}));
      padwar.push_back(postionValues({6, 4, 2.5}));
      padwar.push_back(postionValues({7, 4, 2.0}));
      padwar.push_back(postionValues({8, 4, 0.5}));
      padwar.push_back(postionValues({9, 4,-3.0}));
      //7th
      padwar.push_back(postionValues({0, 3,-3.0}));
      padwar.push_back(postionValues({1, 3,-0.5}));
      padwar.push_back(postionValues({2, 3, 0.5}));
      padwar.push_back(postionValues({3, 3, 0.5}));
      padwar.push_back(postionValues({4, 3, 1.0}));
      padwar.push_back(postionValues({5, 3, 1.0}));
      padwar.push_back(postionValues({6, 3, 1.5}));
      padwar.push_back(postionValues({7, 3, 1.0}));
      padwar.push_back(postionValues({8, 3,-0.5}));
      padwar.push_back(postionValues({9, 3,-3.0}));
      //8th
      padwar.push_back(postionValues({0, 7,-3.0}));
      padwar.push_back(postionValues({1, 2,-1.0}));
      padwar.push_back(postionValues({2, 2, 0.0}));
      padwar.push_back(postionValues({3, 2, 0.0}));
      padwar.push_back(postionValues({4, 2, 1.0}));
      padwar.push_back(postionValues({5, 2, 1.0}));
      padwar.push_back(postionValues({6, 2, 1.0}));
      padwar.push_back(postionValues({7, 2, 0.0}));
      padwar.push_back(postionValues({8, 2,-1.0}));
      padwar.push_back(postionValues({9, 2,-3.0}));
      //9t
      padwar.push_back(postionValues({0, 1,-4.0}));
      padwar.push_back(postionValues({1, 1,-2.0}));
      padwar.push_back(postionValues({2, 1,-1.0}));
      padwar.push_back(postionValues({3, 1,-1.0}));
      padwar.push_back(postionValues({4, 1,-0.5}));
      padwar.push_back(postionValues({5, 1,-0.5}));
      padwar.push_back(postionValues({6, 1,-1.0}));
      padwar.push_back(postionValues({7, 1,-1.0}));
      padwar.push_back(postionValues({8, 1,-2.0}));
      padwar.push_back(postionValues({9, 1,-4.0}));
      //10th
      padwar.push_back(postionValues({0, 0,-5.0}));
      padwar.push_back(postionValues({1, 0,-4.0}));
      padwar.push_back(postionValues({2, 0,-3.0}));
      padwar.push_back(postionValues({3, 0,-3.0}));
      padwar.push_back(postionValues({4, 0,-2.0}));
      padwar.push_back(postionValues({5, 0,-2.0}));
      padwar.push_back(postionValues({6, 0,-2.0}));
      padwar.push_back(postionValues({7, 0,-3.0}));
      padwar.push_back(postionValues({8, 0,-4.0}));
      padwar.push_back(postionValues({9, 0,-5.0}));
    }
    void construcdwar(){
      //first row
      dwar.push_back(postionValues({0, 9,-5.0}));
      dwar.push_back(postionValues({1, 9,-4.0}));
      dwar.push_back(postionValues({2, 9,-3.0}));
      dwar.push_back(postionValues({3, 9,-3.0}));
      dwar.push_back(postionValues({4, 9,-3.0}));
      dwar.push_back(postionValues({5, 9,-3.0}));
      dwar.push_back(postionValues({6, 9,-3.0}));
      dwar.push_back(postionValues({7, 9,-3.0}));
      dwar.push_back(postionValues({8, 9,-4.0}));
      dwar.push_back(postionValues({9, 9,-5.0}));
      //second row
      dwar.push_back(postionValues({0, 8,-4.0}));
      dwar.push_back(postionValues({1, 8,-2.0}));
      dwar.push_back(postionValues({2, 8, 0.0}));
      dwar.push_back(postionValues({3, 8, 0.0}));
      dwar.push_back(postionValues({4, 8, 0.0}));
      dwar.push_back(postionValues({5, 8, 0.0}));
      dwar.push_back(postionValues({6, 8, 0.0}));
      dwar.push_back(postionValues({7, 8, 0.0}));
      dwar.push_back(postionValues({8, 8,-2.0}));
      dwar.push_back(postionValues({9, 8,-4.0}));
      //thrid row
      dwar.push_back(postionValues({0, 7,-3.0}));
      dwar.push_back(postionValues({1, 7, 0.5}));
      dwar.push_back(postionValues({2, 7, 0.5}));
      dwar.push_back(postionValues({3, 7, 1.0}));
      dwar.push_back(postionValues({4, 7, 1.5}));
      dwar.push_back(postionValues({5, 7, 1.5}));
      dwar.push_back(postionValues({6, 7, 1.0}));
      dwar.push_back(postionValues({7, 7, 0.5}));
      dwar.push_back(postionValues({8, 7, 0.5}));
      dwar.push_back(postionValues({9, 7,-3.0}));
      //4th row
      dwar.push_back(postionValues({0, 6,-3.0}));
      dwar.push_back(postionValues({1, 6, 0.0}));
      dwar.push_back(postionValues({2, 6, 1.5}));
      dwar.push_back(postionValues({3, 6, 1.5}));
      dwar.push_back(postionValues({4, 6, 2.0}));
      dwar.push_back(postionValues({5, 6, 2.0}));
      dwar.push_back(postionValues({6, 6, 2.0}));
      dwar.push_back(postionValues({7, 6, 1.5}));
      dwar.push_back(postionValues({8, 6, 1.5}));
      dwar.push_back(postionValues({9, 6,-3.0}));
      //5th ro
      dwar.push_back(postionValues({0, 5,-3.0}));
      dwar.push_back(postionValues({1, 5, 0.5}));
      dwar.push_back(postionValues({2, 5, 2.0}));
      dwar.push_back(postionValues({3, 5, 1.0}));
      dwar.push_back(postionValues({4, 5, 1.5}));
      dwar.push_back(postionValues({5, 5, 1.5}));
      dwar.push_back(postionValues({6, 5, 2.5}));
      dwar.push_back(postionValues({7, 5, 2.0}));
      dwar.push_back(postionValues({8, 5, 0.5}));
      dwar.push_back(postionValues({9, 5,-3.0}));
      //6th ro5
      dwar.push_back(postionValues({0, 4,-3.0}));
      dwar.push_back(postionValues({1, 4, 0.5}));
      dwar.push_back(postionValues({2, 4, 2.0}));
      dwar.push_back(postionValues({3, 4, 2.0}));
      dwar.push_back(postionValues({4, 4, 2.5}));
      dwar.push_back(postionValues({5, 4, 2.5}));
      dwar.push_back(postionValues({6, 4, 2.5}));
      dwar.push_back(postionValues({7, 4, 2.0}));
      dwar.push_back(postionValues({8, 4, 0.5}));
      dwar.push_back(postionValues({9, 4,-3.0}));
      //7th
      dwar.push_back(postionValues({0, 3,-3.0}));
      dwar.push_back(postionValues({1, 3,-0.5}));
      dwar.push_back(postionValues({2, 3, 0.5}));
      dwar.push_back(postionValues({3, 3, 1.5}));
      dwar.push_back(postionValues({4, 3, 1.0}));
      dwar.push_back(postionValues({5, 3, 1.0}));
      dwar.push_back(postionValues({6, 3, 1.5}));
      dwar.push_back(postionValues({7, 3, 1.0}));
      dwar.push_back(postionValues({8, 3,-0.5}));
      dwar.push_back(postionValues({9, 3,-3.0}));
      //8th
      dwar.push_back(postionValues({0, 2,-3.0}));
      dwar.push_back(postionValues({1, 2,-1.0}));
      dwar.push_back(postionValues({2, 2, 0.0}));
      dwar.push_back(postionValues({3, 2, 0.0}));
      dwar.push_back(postionValues({4, 2, 1.0}));
      dwar.push_back(postionValues({5, 2, 1.0}));
      dwar.push_back(postionValues({6, 2, 1.0}));
      dwar.push_back(postionValues({7, 2, 0.0}));
      dwar.push_back(postionValues({8, 2,-1.0}));
      dwar.push_back(postionValues({9, 2,-3.0}));
      //9t
      dwar.push_back(postionValues({0, 1,-4.0}));
      dwar.push_back(postionValues({1, 1,-2.0}));
      dwar.push_back(postionValues({2, 1,-1.0}));
      dwar.push_back(postionValues({3, 1,-1.0}));
      dwar.push_back(postionValues({4, 1,-0.5}));
      dwar.push_back(postionValues({5, 1,-0.5}));
      dwar.push_back(postionValues({6, 1,-1.0}));
      dwar.push_back(postionValues({7, 1,-1.0}));
      dwar.push_back(postionValues({8, 1,-2.0}));
      dwar.push_back(postionValues({9, 1,-4.0}));
      //10th
      dwar.push_back(postionValues({0, 0,-5.0}));
      dwar.push_back(postionValues({1, 0,-4.0}));
      dwar.push_back(postionValues({2, 0,-3.0}));
      dwar.push_back(postionValues({3, 0,-3.0}));
      dwar.push_back(postionValues({4, 0,-2.0}));
      dwar.push_back(postionValues({5, 0,-2.0}));
      dwar.push_back(postionValues({6, 0,-2.0}));
      dwar.push_back(postionValues({7, 0,-3.0}));
      dwar.push_back(postionValues({8, 0,-4.0}));
      dwar.push_back(postionValues({9, 0,-5.0}));
    }
  void construcflier(){
      //first row
      flier.push_back(postionValues({0, 9,-5.0}));
      flier.push_back(postionValues({1, 9,-4.0}));
      flier.push_back(postionValues({2, 9,-3.0}));
      flier.push_back(postionValues({3, 9,-3.0}));
      flier.push_back(postionValues({4, 9,-3.0}));
      flier.push_back(postionValues({5, 9,-3.0}));
      flier.push_back(postionValues({6, 9,-3.0}));
      flier.push_back(postionValues({7, 9,-3.0}));
      flier.push_back(postionValues({8, 9,-4.0}));
      flier.push_back(postionValues({9, 9,-5.0}));
      //second ro
      flier.push_back(postionValues({0, 8,-4.0}));
      flier.push_back(postionValues({1, 8,-2.0}));
      flier.push_back(postionValues({2, 8, 0.0}));
      flier.push_back(postionValues({3, 8, 0.0}));
      flier.push_back(postionValues({4, 8, 0.0}));
      flier.push_back(postionValues({5, 8, 0.0}));
      flier.push_back(postionValues({6, 8, 0.0}));
      flier.push_back(postionValues({7, 8, 0.0}));
      flier.push_back(postionValues({8, 8,-2.0}));
      flier.push_back(postionValues({9, 8,-4.0}));
      //thrid ro
      flier.push_back(postionValues({0, 7,-3.0}));
      flier.push_back(postionValues({1, 7, 0.5}));
      flier.push_back(postionValues({2, 7, 0.5}));
      flier.push_back(postionValues({3, 7, 1.0}));
      flier.push_back(postionValues({4, 7, 1.5}));
      flier.push_back(postionValues({5, 7, 1.5}));
      flier.push_back(postionValues({6, 7, 0.0}));
      flier.push_back(postionValues({7, 7, 0.5}));
      flier.push_back(postionValues({8, 7, 0.5}));
      flier.push_back(postionValues({9, 7,-3.0}));
      //4th ro
      flier.push_back(postionValues({0,6,-3.0}));
      flier.push_back(postionValues({1, 6, 0.0}));
      flier.push_back(postionValues({2, 6, -1.5}));
      flier.push_back(postionValues({3, 6, 1.5}));
      flier.push_back(postionValues({4, 6, 1.0}));
      flier.push_back(postionValues({5, 6, 1.0}));
      flier.push_back(postionValues({6, 6, 1.0}));
      flier.push_back(postionValues({7, 6, 1.5}));
      flier.push_back(postionValues({8, 6, -1.5}));
      flier.push_back(postionValues({9, 6,-3.0}));
      //5th row
      flier.push_back(postionValues({0, 5,-3.0}));
      flier.push_back(postionValues({1, 5, 0.5}));
      flier.push_back(postionValues({2, 5, 1.0}));
      flier.push_back(postionValues({3, 5, 1.0}));
      flier.push_back(postionValues({4, 5, 1.5}));
      flier.push_back(postionValues({5, 5, 1.5}));
      flier.push_back(postionValues({6, 5, 1.5}));
      flier.push_back(postionValues({7, 5, 1.5}));
      flier.push_back(postionValues({8, 5, 0.5}));
      flier.push_back(postionValues({9, 5,-3.0}));
      //6th ro
      flier.push_back(postionValues({0, 4,-3.0}));
      flier.push_back(postionValues({1, 4, 0.5}));
      flier.push_back(postionValues({2, 4, 1.0}));
      flier.push_back(postionValues({3, 4, 1.0}));
      flier.push_back(postionValues({4, 4, 1.5}));
      flier.push_back(postionValues({5, 4, 1.5}));
      flier.push_back(postionValues({6,4,  1.5}));
      flier.push_back(postionValues({7, 4, 1.0}));
      flier.push_back(postionValues({8, 4, 0.5}));
      flier.push_back(postionValues({9, 4,-3.0}));
      //7th
      flier.push_back(postionValues({0, 3,-3.0}));
      flier.push_back(postionValues({1, 3,-0.5}));
      flier.push_back(postionValues({2, 3, 0.5}));
      flier.push_back(postionValues({3, 3, 1.5}));
      flier.push_back(postionValues({4, 3, 1.0}));
      flier.push_back(postionValues({5, 3, 1.0}));
      flier.push_back(postionValues({6, 3, -1.5}));
      flier.push_back(postionValues({7, 3, -1.0}));
      flier.push_back(postionValues({8, 3,-0.5}));
      flier.push_back(postionValues({9, 3,-3.0}));
      //8t
      flier.push_back(postionValues({0, 2,-3.0}));
      flier.push_back(postionValues({1, 2,-1.0}));
      flier.push_back(postionValues({2, 2, 0.0}));
      flier.push_back(postionValues({3, 2, 0.0}));
      flier.push_back(postionValues({4, 2, -1.0}));
      flier.push_back(postionValues({5, 2, -1.0}));
      flier.push_back(postionValues({6, 2, -1.0}));
      flier.push_back(postionValues({7, 2, 0.0}));
      flier.push_back(postionValues({8, 2,-1.0}));
      flier.push_back(postionValues({9, 2,-3.0}));
      //9th
      flier.push_back(postionValues({0, 1,-4.0}));
      flier.push_back(postionValues({1, 1,-2.0}));
      flier.push_back(postionValues({2, 1,-1.0}));
      flier.push_back(postionValues({3, 1,-1.0}));
      flier.push_back(postionValues({4, 1,-0.5}));
      flier.push_back(postionValues({5, 1,-0.5}));
      flier.push_back(postionValues({6, 1,-1.0}));
      flier.push_back(postionValues({7, 1,-1.0}));
      flier.push_back(postionValues({8, 1,-2.0}));
      flier.push_back(postionValues({9, 1,-4.0}));
      //10th
      flier.push_back(postionValues({0, 0,-5.0}));
      flier.push_back(postionValues({1, 0,-4.0}));
      flier.push_back(postionValues({2, 0,-3.0}));
      flier.push_back(postionValues({3, 0,-3.0}));
      flier.push_back(postionValues({4, 0,-2.0}));
      flier.push_back(postionValues({5, 0,-2.0}));
      flier.push_back(postionValues({6, 0,-2.0}));
      flier.push_back(postionValues({7, 0,-3.0}));
      flier.push_back(postionValues({8, 0,-4.0}));
      flier.push_back(postionValues({9, 0,-5.0}));
    }
      void construcchief(){
      //first row
      chief.push_back(postionValues({0, 9,-1.5}));
      chief.push_back(postionValues({1, 9,-1.5}));
      chief.push_back(postionValues({2, 9,-1.5}));
      chief.push_back(postionValues({3, 9,-1.5}));
      chief.push_back(postionValues({4, 9,-1.0}));
      chief.push_back(postionValues({5, 9,-1.0}));
      chief.push_back(postionValues({6, 9,-1.0}));
      chief.push_back(postionValues({7, 9,-1.5}));
      chief.push_back(postionValues({8, 9,-1.5}));
      chief.push_back(postionValues({9, 9,-1.5}));
      //second row
      chief.push_back(postionValues({0, 8,0.0}));
      chief.push_back(postionValues({1, 8,0.0}));
      chief.push_back(postionValues({2, 8,1.0}));
      chief.push_back(postionValues({3, 8,1.0}));
      chief.push_back(postionValues({4, 8,1.0}));
      chief.push_back(postionValues({5, 8,1.0}));
      chief.push_back(postionValues({6, 8, 1.0}));
      chief.push_back(postionValues({7, 8,0.0}));
      chief.push_back(postionValues({8, 8,0.0}));
      chief.push_back(postionValues({9, 8,0.0}));
      //thrid row
      chief.push_back(postionValues({0, 7,-1.0}));
      chief.push_back(postionValues({1, 7, 1.0}));
      chief.push_back(postionValues({2, 7, 1.0}));
      chief.push_back(postionValues({3, 7, 1.0}));
      chief.push_back(postionValues({4, 7, 1.5}));
      chief.push_back(postionValues({5, 7, 1.5}));
      chief.push_back(postionValues({6, 7, 1.0}));
      chief.push_back(postionValues({7, 7, 0.5}));
      chief.push_back(postionValues({8, 7, 0.5}));
      chief.push_back(postionValues({9, 7,-3.0}));
      //4th ro
      chief.push_back(postionValues({0, 6,-1.0}));
      chief.push_back(postionValues({1, 6, -1.0}));
      chief.push_back(postionValues({2, 6, -1.0}));
      chief.push_back(postionValues({3, 6, -1.0}));
      chief.push_back(postionValues({4, 6, 1.0}));
      chief.push_back(postionValues({5, 6, 1.0}));
      chief.push_back(postionValues({6, 6, 1.0}));
      chief.push_back(postionValues({7, 6, -1.0}));
      chief.push_back(postionValues({8, 6, -1.0}));
      chief.push_back(postionValues({9, 6,-3.0}));
      //5th ro6
      chief.push_back(postionValues({0, 5,-3.0}));
      chief.push_back(postionValues({1, 5, 0.5}));
      chief.push_back(postionValues({2, 5, 1.0}));
      chief.push_back(postionValues({3, 5, 1.0}));
      chief.push_back(postionValues({4, 5, 1.5}));
      chief.push_back(postionValues({5, 5, 1.5}));
      chief.push_back(postionValues({6, 5, 1.5}));
      chief.push_back(postionValues({7, 5, 1.0}));
      chief.push_back(postionValues({8, 5, 0.5}));
      chief.push_back(postionValues({9, 5,-3.0}));
      //6th row
      chief.push_back(postionValues({0, 4,-3.0}));
      chief.push_back(postionValues({1, 4, 0.5}));
      chief.push_back(postionValues({2, 4, 1.0}));
      chief.push_back(postionValues({3, 4, 1.0}));
      chief.push_back(postionValues({4, 4, 1.5}));
      chief.push_back(postionValues({5, 4, 1.5}));
      chief.push_back(postionValues({6, 4, 1.5}));
      chief.push_back(postionValues({7, 4, 1.0}));
      chief.push_back(postionValues({8, 4, -0.5}));
      chief.push_back(postionValues({9, 4,-3.0}));
      //7th
      chief.push_back(postionValues({0, 3,-1.0}));
      chief.push_back(postionValues({1, 3,-0.5}));
      chief.push_back(postionValues({2, 3, 0.5}));
      chief.push_back(postionValues({3, 3, 1.5}));
      chief.push_back(postionValues({4, 3, 1.0}));
      chief.push_back(postionValues({5, 3, 1.0}));
      chief.push_back(postionValues({6, 3, 1.5}));
      chief.push_back(postionValues({7, 3, 1.0}));
      chief.push_back(postionValues({8, 3,-0.5}));
      chief.push_back(postionValues({9, 3,-1.0}));
      //8th
      chief.push_back(postionValues({0, 2,-1.0}));
      chief.push_back(postionValues({1, 2,-1.0}));
      chief.push_back(postionValues({2, 2, 0.0}));
      chief.push_back(postionValues({3, 2, 0.0}));
      chief.push_back(postionValues({4, 2, 1.0}));
      chief.push_back(postionValues({5, 2, 1.0}));
      chief.push_back(postionValues({6, 2, 1.0}));
      chief.push_back(postionValues({7, 2, 0.0}));
      chief.push_back(postionValues({8, 2,-1.0}));
      chief.push_back(postionValues({9, 2,-1.0}));
      //9th
      chief.push_back(postionValues({0, 1,-1.0}));
      chief.push_back(postionValues({1, 1,-2.0}));
      chief.push_back(postionValues({2, 1,1.0}));
      chief.push_back(postionValues({3, 1,1.0}));
      chief.push_back(postionValues({4, 1,0.5}));
      chief.push_back(postionValues({5, 1,0.5}));
      chief.push_back(postionValues({6, 1,0.0}));
      chief.push_back(postionValues({7, 1,1.0}));
      chief.push_back(postionValues({8, 1,0.0}));
      chief.push_back(postionValues({9, 1,-1.0}));
      //10th
      chief.push_back(postionValues({0, 0,-3.0}));
      chief.push_back(postionValues({1, 0,-3.0}));
      chief.push_back(postionValues({2, 0,-1.0}));
      chief.push_back(postionValues({3, 0,-1.0}));
      chief.push_back(postionValues({4, 0,-1.0}));
      chief.push_back(postionValues({5, 0,-1.0}));
      chief.push_back(postionValues({6, 0,-1.0}));
      chief.push_back(postionValues({7, 0,-1.0}));
      chief.push_back(postionValues({8, 0,-2.0}));
      chief.push_back(postionValues({9, 0,-2.0}));
    }


      void construcprincess(){
      //first row
      princess.push_back(postionValues({0, 9,2.0}));
      princess.push_back(postionValues({1, 9,3.0}));
      princess.push_back(postionValues({2, 9,1.0}));
      princess.push_back(postionValues({3, 9,1.0}));
      princess.push_back(postionValues({4, 9,0.0}));
      princess.push_back(postionValues({5, 9,0.0}));
      princess.push_back(postionValues({6, 9,1.0}));
      princess.push_back(postionValues({7, 9,1.0}));
      princess.push_back(postionValues({8, 9,3.0}));
      princess.push_back(postionValues({9, 9,2.0}));
      //second row
      princess.push_back(postionValues({0, 8,2.0}));
      princess.push_back(postionValues({1, 8,2.0}));
      princess.push_back(postionValues({2, 8, 0.0}));
      princess.push_back(postionValues({3, 8, 0.0}));
      princess.push_back(postionValues({4, 8, 0.0}));
      princess.push_back(postionValues({5, 8, 0.0}));
      princess.push_back(postionValues({6, 8, 0.0}));
      princess.push_back(postionValues({7, 8, 0.0}));
      princess.push_back(postionValues({8, 8,2.0}));
      princess.push_back(postionValues({9, 8,2.0}));
      //thrid ro
      princess.push_back(postionValues({0, 7,-3.0}));
      princess.push_back(postionValues({1, 7, -0.5}));
      princess.push_back(postionValues({2, 7, -0.5}));
      princess.push_back(postionValues({3, 7, -1.0}));
      princess.push_back(postionValues({4, 7, -1.5}));
      princess.push_back(postionValues({5, 7, -1.5}));
      princess.push_back(postionValues({6, 7, -1.0}));
      princess.push_back(postionValues({7,7, -0.5}));
      princess.push_back(postionValues({8,7, -0.5}));
      princess.push_back(postionValues({9, 7,-3.0}));
      //4th row
      princess.push_back(postionValues({0, 6,-3.0}));
      princess.push_back(postionValues({1, 6, 0.0}));
      princess.push_back(postionValues({2, 6, -1.5}));
      princess.push_back(postionValues({3, 6, -1.5}));
      princess.push_back(postionValues({4, 6, -4.0}));
      princess.push_back(postionValues({5, 6, -4.0}));
      princess.push_back(postionValues({6, 6, -4.0}));
      princess.push_back(postionValues({7, 6, -1.5}));
      princess.push_back(postionValues({8, 6, -1.5}));
      princess.push_back(postionValues({9, 6,-3.0}));
      //5th row
      princess.push_back(postionValues({0, 5,-3.0}));
      princess.push_back(postionValues({1, 5, -3.0}));
      princess.push_back(postionValues({2, 5,-3.0}));
      princess.push_back(postionValues({3, 5,-3.0}));
      princess.push_back(postionValues({4, 5,-3.0}));
      princess.push_back(postionValues({5, 5, -3.0}));
      princess.push_back(postionValues({6, 5, -3.0}));
      princess.push_back(postionValues({7, 5, -3.0}));
      princess.push_back(postionValues({8, 5, -3.0}));
      princess.push_back(postionValues({9, 5,-3.0}));
      //6th ro5
      princess.push_back(postionValues({0, 4,-5.0}));
      princess.push_back(postionValues({1, 4, -5.0}));
      princess.push_back(postionValues({2,4, -5.0}));
      princess.push_back(postionValues({3, 4, -5.0}));
      princess.push_back(postionValues({4, 4, -5.0}));
      princess.push_back(postionValues({5, 4, -5.0}));
      princess.push_back(postionValues({6, 4, -5.0}));
      princess.push_back(postionValues({7, 4, -5.0}));
      princess.push_back(postionValues({8, 4, -5.0}));
      princess.push_back(postionValues({9, 4,-5.0}));
      //7t
      princess.push_back(postionValues({0, 3,-5.0}));
      princess.push_back(postionValues({1, 3,-5.5}));
      princess.push_back(postionValues({2, 3,-5.0}));
      princess.push_back(postionValues({3, 3,-5.0}));
      princess.push_back(postionValues({4, 3,-5.0}));
      princess.push_back(postionValues({5, 3, -5.0}));
      princess.push_back(postionValues({6, 3, -5.0}));
      princess.push_back(postionValues({7, 3, -5.0}));
      princess.push_back(postionValues({8, 3,-5.0}));
      princess.push_back(postionValues({9, 3,-5.0}));
      //8t3
      princess.push_back(postionValues({0, 2,-5.0}));
      princess.push_back(postionValues({1, 2,-5.0}));
      princess.push_back(postionValues({2, 2, -5.0}));
      princess.push_back(postionValues({3, 2, -5.0}));
      princess.push_back(postionValues({4, 2,-5.0}));
      princess.push_back(postionValues({5, 2, -5.0}));
      princess.push_back(postionValues({6, 2,-5.0}));
      princess.push_back(postionValues({7, 2,-5.0}));
      princess.push_back(postionValues({8, 2,-5.0}));
      princess.push_back(postionValues({9, 2,-5.0}));
      //9th
      princess.push_back(postionValues({0, 1,-5.0}));
      princess.push_back(postionValues({1, 1,-5.0}));
      princess.push_back(postionValues({2, 1,-5.0}));
      princess.push_back(postionValues({3, 1,-5.0}));
      princess.push_back(postionValues({4, 1,-5.5}));
      princess.push_back(postionValues({5, 1,-5.5}));
      princess.push_back(postionValues({6, 1,-5.0}));
      princess.push_back(postionValues({7, 1,-5.0}));
      princess.push_back(postionValues({8, 1,-5.0}));
      princess.push_back(postionValues({9, 1,-5.0}));
      //10th
      princess.push_back(postionValues({0, 0,-5.0}));
      princess.push_back(postionValues({1, 0,-5.0}));
      princess.push_back(postionValues({2, 0,-5.0}));
      princess.push_back(postionValues({3, 0,-5.0}));
      princess.push_back(postionValues({4, 0,-5.0}));
      princess.push_back(postionValues({5, 0,-5.0}));
      princess.push_back(postionValues({6, 0,-5.0}));
      princess.push_back(postionValues({7, 0,-5.0}));
      princess.push_back(postionValues({8, 0,-5.0}));
      princess.push_back(postionValues({9, 0,-5.0}));
    }
    double getpanthanPostionValue(int dx, int dy, int player) {
      if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < pathan.size(); i++) {
        //std::cout <<  "pathan v all " << pathan[i].value << pathan.size() <<  std::endl;
        if ((pathan[i].x == dx) && (pathan[i].y == dy)) {
          //std::cout << "size" << pathan.size() <<  " given x y" << dx << dy << "pathan v " << pathan[i].value << std::endl;
          return pathan[i].value;
        }
      }
      return 0.0;
    }
    double getchiefPostionValue(int dx, int dy, int player) {
            if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < chief.size(); i++) {
        if ((chief[i].x == dx) && (chief[i].y == dy)) {
         // std::cout << "given x y" << dx << dy << "chief v " << chief[i].value << std::endl;
          return chief[i].value;
        }
      }
      return 0.0;
    }
    double getflierPostionValue(int dx, int dy, int player) {
            if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < flier.size(); i++) {
        if ((flier[i].x == dx) && (flier[i].y == dy)) {
          //std::cout << "given x y" << dx << dy << "flier v " << flier[i].value << std::endl;
          return flier[i].value;
        }
      }
      return 0.0;
    }
    double getdwarPostionValue(int dx, int dy, int player) {
            if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < dwar.size(); i++) {
        if ((dwar[i].x == dx) && (dwar[i].y == dy)) {
          //std::cout << "given x y" << dx << dy << "dwar v " << dwar[i].value << std::endl;
          return dwar[i].value;
        }
      }
      return 0.0;
    }
    double getpadwarPostionValue(int dx, int dy, int player) {
            if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < padwar.size(); i++) {
        if ((padwar[i].x == dx) && (padwar[i].y == dy)) {
          //std::cout << "given x y" << dx << dy << "padwar v " << padwar[i].value << std::endl;
          return padwar[i].value;
        }
      }
      return 0.0;
    }
    double getwarriorPostionValue(int dx, int dy, int player) {
            if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < warrior.size(); i++) {
        if ((warrior[i].x == dx) && (warrior[i].y == dy)) {
          //std::cout << "given x y" << dx << dy << "warrior v " << warrior[i].value << std::endl;
          return warrior[i].value;
        }
      }
      return 0.0;
    }
    double getthoatPostionValue(int dx, int dy, int player) {
      if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < thoat.size(); i++) {
        //std::cout << "thoat vector values " << thoat[i].x << thoat[i].y << thoat[i].value << std::endl;
        if ((thoat[i].x == dx) && (thoat[i].y == dy)) {
          //std::cout << "given x y" << dx << dy << "thoat v " << thoat[i].value << std::endl;
          return thoat[i].value;
        }
      }
      return 0.0;
    }
    double getprincessPostionValue(int dx, int dy, int player) {
            if((player == 1)){
        if(dy == 0){
          dy = 9;
        }else if (dy == 1){
          dy = 8;
        }else if (dy == 2){
          dy = 7;
        }else if (dy == 3){
          dy = 6;
        }else if (dy == 4){
          dy = 5;
        }else if (dy == 5){
          dy = 4;
        }else if (dy == 6){
          dy = 3;
        }else if (dy == 7){
          dy = 2;
        }else if (dy == 8){
          dy = 1;
        }else if (dy == 9){
          dy = 0;
        }
      }
      for (unsigned int i = 0; i < princess.size(); i++) {
        if ((princess[i].x == dx) && (princess[i].y == dy)) {
          //std::cout << "given x y" << dx << dy << "princess v " << princess[i].value << std::endl;
          return princess[i].value;
        }
      }
      return 0.0;
    }

    AlphaBeta::AlphaBeta( ai::Agent::Options *opts )
    :max_depth(3),
    evaluation_method(PIECE_COUNT)
    {
      construcprincess();
      construcchief();
      construcflier();
      construcdwar();
      construcpadwar();
      construcpathan();
      construcThoat();
      construcwarrior();
      if(opts->GetArgInt("user1") > 0 ){ // -U --user1
        this->max_depth =(opts->GetArgInt("user1"));
      }
      if(opts->GetArgInt("user2") > 0 ){ // -v user2
        this->evaluation_method = static_cast<EvaluationOptions>  (opts->GetArgInt("user2"));
      }
      std::stringstream ss;
      ss << "AlphaBeta" ; 
      ss << "-d " << this->max_depth;
      ss << "-e " << this->evaluation_method ;
      SetName( "AlphaBeta" );
    }
    
    AlphaBeta::~AlphaBeta( ) {
    }
    
    ai::Agent::Action * AlphaBeta::Program( const ai::Agent::Percept * percept ) {
      ai::Jetan::Action *action = new ai::Jetan::Action;

      // construcpathan();
      std::string board_str = percept->GetAtom( "BOARD" ).GetValue( );
      ai::Jetan::Board board( board_str );

      std::stringstream ss( percept->GetAtom( "PLAYER_NUMBER" ).GetValue( ) );
      int player = 0;
      ss >> player;
      
      //const std::vector< ai::Jetan::MoveData > & moves = board.DetermineLegalMoves( player );

      // int player = atoi(percept->GetAtom("PLAYER_NUMBER").GetValue().c_str());

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
    PlyData AlphaBeta::PickMove(const ai::Jetan::Board &board, int player)
    {
      // aplha -, beta + 
      PlyData ply_data = this->Max(board, player, 1, -MY_INFINITY, MY_INFINITY);
      return ply_data;
    }

    PlyData AlphaBeta::Max(const ai::Jetan::Board &board, int player, int depth, double alpha, double beta)
    {
      // current knowung - infi
      PlyData ply_data(-MY_INFINITY);
      // cutoff max depth or winner
      if(board.HaveWinner() || depth > this->max_depth)
        {
          ply_data.utility = this->Evaluate(board, player);
          return ply_data;
        }

      ai::Jetan::Board my_board(board);
      // legal moves 
      const std::vector<ai::Jetan::MoveData> & moves = my_board.DetermineLegalMoves(player);
      int i;
      for(i = 0; i < (int)moves.size(); i++)
        {
          ai::Jetan::Board tmp_board(board);
          tmp_board.Move(player, moves[i]);
          PlyData tmp_ply_data = this->Min(tmp_board, player, depth + 1, alpha, beta);
          if(tmp_ply_data.utility > ply_data.utility)
            {
              ply_data.utility = tmp_ply_data.utility;
              ply_data.move    = moves[i];
              ply_data.move_ok = true;
              if(ply_data.utility >= beta)
                { /* parent node has a better (or equal) child, so this node will not be chosen */
                  break;
                }
              if(ply_data.utility > alpha)
                {
                  alpha = ply_data.utility;
                }
            }
        }

      return ply_data;
    }

    PlyData AlphaBeta::Min(const ai::Jetan::Board &board, int player, int depth, double alpha, double beta)
    {
      PlyData ply_data(MY_INFINITY);
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
          PlyData tmp_ply_data = this->Max(tmp_board, player, depth + 1, alpha, beta);
          if(tmp_ply_data.utility < ply_data.utility)
            {
              ply_data.utility = tmp_ply_data.utility;
              ply_data.move    = moves[i];
              ply_data.move_ok = true;
              if(ply_data.utility <= alpha)
                { /* parent node has a better (or equal) child, so this node will not be chosen */
                  break;
                }
              if(ply_data.utility < beta)
                {
                  beta = ply_data.utility;
                }
            }
        }

      return ply_data;
    }

    double AlphaBeta::Evaluate(const ai::Jetan::Board &board, int player){
      double v = 0.0;
      switch(this->evaluation_method)
      {
        default:

        case PIECE_COUNT:
          v = this->EvaluatePieceCount(board, player);
          break;
        case PIECE_COUNT_WIN:
          v = this->EvaluatePieceCountWin(board, player);
          break;
        case POSITION_MANHATTAN:
          v = this->EvaluatePoistionManhattan(board, player);

      }
      return v;
    }
    double AlphaBeta::EvaluatePoistionManhattan(const ai::Jetan::Board &board, int player){
    // std::cout << "WARRIOR" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
    //     << " Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
     double counter = 0.0;
     const  BoardData& data = board.GetBoard();
     for(int i =0; i < 40 ; i++){
      counter = counter + (12 - (abs((double)data.pieces[ i ].mLocation.x-4.5)+abs((double)data.pieces[ i ].mLocation.y - 4.5))); 
     } 
     return counter;
    }
    double AlphaBeta::EvaluatePieceCount(const ai::Jetan::Board &board, int player)
    {
      const  BoardData& board_data = board.GetBoard();
      //int other_player = (player == 1) ? 2 : 1;
      double live_pieces = 0.0;

      for (int i = 0; i < 20 ; i++){
        if (board_data.pieces[i].mAlive){
          if(player == 1){
            live_pieces += 1;  
          }else{
            live_pieces -= 1;
          }
        }
        
      }
    for (int i = 20; i < 40 ; i++){
      if (board_data.pieces[i].mAlive){
        if(player == 2){
          live_pieces -= 1;  
        }else{
          live_pieces += 1;
        }
      }
    }
      return live_pieces;
    }


    double AlphaBeta::EvaluatePieceCountWin(const ai::Jetan::Board &board, int player)
    {
      //const  BoardData& board_data = board.GetBoard();

      // if(board_data.player_turn == 5){
      //   if(player ==1){
      //    return (MY_INFINITY / 2.0);
      //   }else{
      //    return (-MY_INFINITY / 2.0);
      //   }
      // }else if(board_data.player_turn == 6){
      //   if(player ==1){
      //    return (-MY_INFINITY / 2.0);
      //   }else{
      //    return (MY_INFINITY / 2.0);
      //   }
      // } else if(board_data.player_turn == 7){
      //   if(player ==1){
      //    return 0.0;
      //   }else{
      //    return 0.0;
      //   }
      // }
      // return  this->EvaluatePieceCount(board, player);
      ai::Jetan::Board my_board(board);
      const BoardData& data = board.GetBoard( );
      const std::vector< ai::Jetan::MoveData > & moves = my_board.DetermineLegalMoves( player );
      std::vector<MoveData> lastMoves = board.GetLastMoves();
      double value = 0.0;
      int test = 0;
      // if(data.used_escape == 0 ){
      //   value = value + 5
      // }
      for(unsigned int j = 0; j < lastMoves.size(); j++){
             
             for(unsigned int k = 0; k < moves.size() ; k++){
                  if(lastMoves[j] < moves[k] ){
                        value = value + 1;
                  }else if ( moves[k] <  lastMoves[j]){
                        value = value ;
                  }else{
                        value = value - 3;
                  }
             }
                  
             
      }
      for(unsigned int i = 0; i < 40; i++ ) {
         

        int mtype = (int)data.pieces[i].mType;
        //std::vector< MoveData > legal_moves;
        //const std::vector< MovePath > paths = data.pieces[i].mPaths->getPaths() ;
        //std::cout << "type" << mtype << std::endl;
        switch( mtype ) {
        
        case 0:
        test++;
          // std::cout << "WARRIOR" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << " Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if (((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive) ){
                      value = value + 16;
                      //std::cout << "warrior added value" << std::endl;              
                      value = value + getwarriorPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player );  
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){
                      value = value - 16;
                    }else if (((int)data.pieces[i].mPlayer != player) && (data.pieces[i].mAlive)){
                      value = value - 16;
                      value = value - getwarriorPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y ,player);
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 18; 
                    }
                    //value = value + getwarriorPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y );
          break;
        case 1:
        test++;
          // std::cout << "PADWAR" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if (((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive) ){
                      value = value + 16;
                      value = value + getpadwarPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player );  
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){
                      value = value - 16;

                    }else if (((int)data.pieces[i].mPlayer != player) && (data.pieces[i].mAlive)){
                      value = value - 16;
                      value = value - getpadwarPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y ,player);
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 18; 
                    }
          break;
        case 2:
        test++;
          // std::cout << "DWAR" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if (((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive) ){
                      value = value + 48;
                      value = value + getdwarPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player );  
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){
                      value = value - 48;
                    }else if (((int)data.pieces[i].mPlayer != player) && (data.pieces[i].mAlive)){
                      value = value - 48;
                      value = value - getdwarPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y ,player);
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 50; 
                    }
          break;
        case 3:
        test++;
          // std::cout << "FLIER" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if (((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive) ){
                      value = value + 96;
                      value = value + ((getflierPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )*1.1));  
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){
                      value = value - 96;
                    }else if (((int)data.pieces[i].mPlayer != player) && (data.pieces[i].mAlive)){
                      value = value - 96;
                      value = value - ((getflierPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )*1.1));
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 100; 
                    }
          break;
        case 4:
        test++;
          // std::cout << "CHIEF" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if (((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive) ){
                      value = value + 400;  
                      value = value + ((getchiefPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )));
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){
                      value = value - 400;
                    }else if (((int)data.pieces[i].mPlayer != player) && (data.pieces[i].mAlive)){
                      value = value - ((getchiefPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )));
                      value = value - 400;
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 420; 
                      
                    }
          break;
        case 5:
        test++;
          // std::cout << "PRINCESS" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if (((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive) ){
                      value = value + 1500;  
                      value = value + ((getprincessPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )));
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){

                      value = value - 3000;
                    }else if (((int)data.pieces[i].mPlayer != player) && (data.pieces[i].mAlive)){
                      value = value - 1500;
                      value = value - ((getprincessPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y ,player)));
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 3000; 
                    }
          break;
        case 6:
        test++;
          // std::cout << "THOAT" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if ((((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive)) ){
                      value = value + 24;  
                      value = value + ((getthoatPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )));
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){
                      value = value - 24;
                    }else if (((int)data.pieces[i].mPlayer != player )&& (data.pieces[i].mAlive)){
                      value = value - 24;
                      value = value - ((getthoatPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )));
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 27; 
                    }
          break;
        case 7:
        test++;
          // std::cout << "PANTHAN" <<  "Located at " << " :: " << (int)data.pieces[ i ].mLocation.x << "," << (int)data.pieces[ i ].mLocation.y
          //           << "Owned by " << (int)data.pieces[i].mPlayer  << std::endl;
                    if (((int)data.pieces[i].mPlayer == player) && (data.pieces[i].mAlive) ){
                      value = value + 5;
                      value = value + ((getpanthanPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player)) );  
                    }else if (((int)data.pieces[i].mPlayer == player) && (!data.pieces[i].mAlive)){
                      value = value - 5;
                    }else if (((int)data.pieces[i].mPlayer != player) && (data.pieces[i].mAlive)){
                      value = value - 5;
                      value = value - ((getpanthanPostionValue((int)data.pieces[ i ].mLocation.x,(int)data.pieces[ i ].mLocation.y,player )));
                    }else if (((int)data.pieces[i].mPlayer != player) && (!data.pieces[i].mAlive)){
                      value = value + 7; 
                    }
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
      //std::cout << value << "    " << test << std::endl;
      return value;
    }
  }
}
