#ifndef _MANHATTAN_H_
#define _MANHATTAN_H_
#include <map>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>


typedef char Facelet; // wgrboy*
enum BasicMoveM { M_IDENTITY, M_U, M_UP, M_L, M_LP, M_F, M_FP, M_R, M_RP, M_B, M_BP, M_D, M_DP, 
                       M_EQ, M_EP, M_M, M_MP, M_S, M_SP, M_X, M_XP, M_Y, M_YP, M_Z, M_ZP };
class Manhattan{
public:
	Manhattan();
  	virtual ~Manhattan( );
  	/*sum of distances sumALL(current misplaced faclets + orignals place)*/
	double distancesum(std::vector<double> x, std::vector<double> y,std::vector<double> z);
  	/*number every tile according to expected dataModel*/
	std::vector < std::string > getFaceletsToValue(const std::vector< Facelet > mFacelets);
	/*Helper Functions for testing & debugging...*/
	std::vector< Facelet > assignFromString( const std::string& s );
	void display( std::vector< std::string > mFacelets);
	std::vector< Facelet > getSolvedFaclets();
	void testFaceletsValue();
	void testACSIIValues();
	/*End of Testing*/
	//this heurstic is not as good as the edge one
	double heursticSumAllFacelets(const std::vector< Facelet > currentCube,const std::vector< Facelet > goalsFacelets);
	double heursticsumAllEdges(const std::vector< Facelet > currentCube, const std::vector< Facelet > goalsFacelets);
  
protected:
const std::vector <std::string> slovedCube = {"w9","w8","w7","w6","w5","w4","w3","w2","w1"
,"g9","g6","g3","g17","g14","g12","g26","g23","g20"
,"r3","r2","r1","r12","r11","r10","r20","r19","r18"
,"b1","b4","b7","b10","b13","b15","b18","b21","b24"
,"o7","o8","o9","o15","o16","o17","o24","o25","o26"
,"y20","y19","y18","y23","y22","y21","y26","y25","y24"};
// Return the sum of distance between all 
// the pair of points. 
const std::vector <std::vector<double>> coords = {{0.5,0.5,0},{1.5,0.5,0},{0,0.5,0},{0.5,1.5,0},{1.5,1.5,0},{2.5,1.5,0},{0.5,2.5,0},{1.5,2.5,0},{2.5,2.5,0}
,{0,0.5,0.5},{0,1.5,0.5},{0,2.5,0.5},{0,0.5,1.5},{0,1.5,1.5},{0,2.5,1.5},{0,0.5,2.5},{0,1.5,2.5},{0,2.5,2.5}
,{0.5,3,0.5},{1.5,3,0.5},{2.5,3,0.5},{0.5,3,1.5},{1.5,3,1.5},{2.5,3,1.5},{0.5,3,2.5},{1.5,3,2.5},{2.5,3,2.5}
,{3,2.5,0.5},{3,1.5,0.5},{3,0.5,0.5},{3,2.5,1.5},{3,1.5,1.5},{3,0.5,1.5},{3,2.5,2.5},{3,1.5,2.5},{3,2.5,2.5}
,{2.5,0,0.5},{1.5,0,0.5},{0.5,0,0.5},{2.5,0,1.5},{1.5,0,1.5},{0.5,0,1.5},{2.5,0,2.5},{1.5,0,2.5},{0.5,0,2.5}
,{0.5,2.5,3},{1.5,2.5,3},{2.5,2.5,3},{0.5,1.5,3},{1.5,2.5,3},{2.5,1.5,3},{0.5,0.5,3},{1.5,0.5,3},{2.5,0.5,3}};
const std::vector <int > edgeIndexes =  {1,3,5,7,12,14,16,23,25,32,34,43,37,10,28,19,41,21,48,30,46,39,50,52};
const std::vector <int > edgefirstIndexes =  {1,3,5,7,12,14,16,23,25,32,34,43};
const std::vector <int > edgesecondIndexes =  {37,10,28,19,41,21,48,30,46,39,50,52};
const std::vector <int > cornersfirstIndexes =  {0,2,6,8,51,53,45,47};
const std::vector <int > cornerssecondIndexes =  {9,29,11,27,15,35,17,33};
const std::vector <int > cornersthirdIndexes =  {38,36,18,20,44,42,24,26};
};

	
	
    /**************************************************************
     *
     * Facelet type
     *
     */

    /* By storing the facelets as chars, each cube requires 54 bytes.
     * This is the best we can do without bit-packing, which would slow
     * down operations on the cube.
     */
    typedef char Facelet; // wgrboy*

    // a few handy constants
    const int NUM_SIDES = 6;
    const int NUM_FACELETS_PER_SIDE = 9;
    const int NUM_FACELETS_TOTAL = NUM_SIDES * NUM_FACELETS_PER_SIDE;
    #endif /* _MANHATTAN_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
    /*
     *
     * Facelet type
     *
     **************************************************************/

    /**************************************************************
     *
     *MoveMclass
     *
     */

    /*
     * TheMoveMclass represents the abstract concept of 0 or more
     * 90 degree rotations of a face or slice.  For the 3x3x3 cube,
     * the base rotations are the 2 90-degree rotations of each of the
     * 6 faces, for 12 basic moves.  All other moves are compositions
     * of these 12 moves.  If this code is ever adapted for higher
     * dimension cubes, this concept will need to be amended, to
     * allow for middle slice moves.
     *
     * We add 6 additional basic moves.  These are the rotations of
     * the entire cube about one of the major axes: x, y, z, in both
     * directions.
     *
     * In concept, theMoveMwould be represented by a matrix
     * to map old state into new state.  However, since each facelet
     * goes from exactly one place to exactly one place, we
     * will just use a 1-d mapping vector for where each facelet moves.
     *
     */
    // forward declaration the Cube class, needed by theMoveMclass.









/*************BASED OFF this doc https://www.cs.princeton.edu/courses/archive/fall06/cos402/papers/korfrubik.pdf *************/
/*****Facelet number is based off  http://iamthecu.be/ **/
//numbering systems to calcuate the m distance. and knowing which tiles goes where!  
//wwwwwwwww || ggggggggg               ||   rrrrrrrrr              ||   bbbbbbbb    
//987654321 || 9,6,3,17,14,12,26,23,20 || 3,2,1,12,11,10,20,19,18  || 1,4,7,10,13,15,18,21,24 ||  
//ooooooooo              ||  yyyyyyggo
//789,15,16,17,24,25,26  || 20,19,18,23,22,21,26,25,24
//      www
//      www
//      www

// ggg  rrr  bbb  ooo
// ggg  rrr  bbb  ooo
// ggg  rrr  bbb  ooo

//      yyy
//      yyy
//      yyy  
//Looks like this
//      9 8 7
//      6 5 4
//      3 2 1

// 9 6 3   3 2 1   1 4 7   7 8 9
// 171412  121110  101315  151617
// 262320  201918  182124  242526

//      201918
//      232221
//      262524
//Indexes!
//      012
//      345
//      678

// 91011  181920  272829  363738
// 121314  212223  303132  394041
// 151617  242526  333435  424344

//      454647
//      484950
//      515253  

//edges values any 12 position and 2 orientation (eg 25 correct )
//corners any of the 8 position and 3 orientation (WRG )

//WGO, WBO, WGR, WBR upper
//YGO, YBO, YGR, YBR lower
//2nd orientation ()
//GWO, BWO, GWR, BWR upper
//GYO, BYO, GYO, BYR lower
//3rd orientation ()
//OGW, OBW, RGW, RBW upper
//OGY, OBY, OGY, RBY lower

// x,y,z plane
//      (0.5,0.5,0) (1.5,0.5,0) (0,0.5,0)
//      (0.5,1.5,0) (1.5,1.5,0) (2.5,1.5,0)
//      (0.5,2.5,0) (1.5,2.5,0) (2.5,2.5,0)

// (0,0.5,0.5) (0,1.5,0.5) (0,2.5,0.5)  (0.5,3,0.5 ) (1.5,3,0.5) (2.5,3,0.5)   (3,2.5,0.5) (3,1.5,0.5) (3,0.5,0.5)  
// (0,0.5,1.5) (0,1.5,1.5) (0,2.5,1.5)  (0.5,3,1.5)  (1.5,3,1.5) (2.5,3,1.5)   (3,2.5,1.5) (3,1.5,1.5) (3,0.5,1.5)  
// (0,0.5,2.5) (0,1.5,2.5) (0,2.5,2.5)  (0.5,3,2.5)  (1.5,3,2.5) (2.5,3,2.5)   (3,2.5,2.5) (3,1.5,2.5) (3,2.5,2.5)  
    // (2.5,0,0.5) (1.5,0,0.5) (0.5,0,0.5)
    // (2.5,0,1.5) (1.5,0,1.5) (0.5,0,1.5)
    // (2.5,0,2.5) (1.5,0,2.5) (0.5,0,2.5)  


//      (0.5,2.5,3) (1.5,2.5,3)  (2.5,2.5,3)
//      (0.5,1.5,3) (1.5,1.5,3)  (2.5,1.5,3)
//      (0.5,0.5,3) (1.5,0.5,3)  (2.5,0.5,3)

// data looks like this for example

//      w9w8w7
//      w60w4
//      w3w2w1

// g9g6g3  r3r2r1  b1b4b7  o7o8o9
// g170g12  r120r10  b10*b15  o150o17
// g26g23g20  r20r19r18  b18b21b24  o24o25o26

//      y20y19y18
//      y230y21
//      y26y25y24



//      w7g23r1
//      r190o25
//      o26b4r3

// o7y19y26  g26w4w3  g3y25b1  w1y23b7
// o150o17  g170o8  w80y21  b210b15
// r20r12o9  w9r2y24  b24r10y18  r18g6g20

//      g9w2o24
//      g120b10
//      y20w6b18