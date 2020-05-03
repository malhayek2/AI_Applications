// CPP Program to find sum of Manhattan distance 
// between all the pairs of given points 
#include "Manhattan.h"
    class CubeM;

    class MoveM {
    public:
      // M_EQ is named strangely due to cmath's M_E, the constant for the numeric constant e.
      // Don't know why we can't scope it away, but we can't.
      // M_IDENTITY is, I, and causes the cube to stay the same.
      // M_U is, U, the clockwise rotation of the Upper face.
      // M_UP is, U', the counter-clockwise rotation of the Upper face.
      // Similar for Lower, Front, Right, Left, and Down faces.
      // enum BasicMove { M_IDENTITY, M_U, M_UP, M_L, M_LP, M_F, M_FP, M_R, M_RP, M_B, M_BP, M_D, M_DP, 
      //                  M_EQ, M_EP, M_M, M_MP, M_S, M_SP, M_X, M_XP, M_Y, M_YP, M_Z, M_ZP };

      // Default constructor, no initialization
      MoveM( );
      // Construct one of the basic moves
      MoveM( const BasicMoveM basic_move );

      // read-only access to the transform vector
      const std::vector< int >& getTransform( ) const;

      // the number of quarter-turns required to perform the move.
      // each of the x, y, z transforms add 0.001 to the cost.
      double getCost( ) const;
      
      // a textual representation of the move, e.g. "U F' D' L"
      const std::string& getName( ) const;

      /* replace this->mTransform contents with the composite of move1 followed by move2
       * It's OK if move1 == *this.
       * Don't get too tricky.  If move2 == *this, errors will occur.
       * Returns *this by reference.
       */
      MoveM& compose( const MoveM& move2, const MoveM& move1 );
      /*
       * move3 = move1 * move2 
       * is the same as
       * move3.compose( move1, move2 )
       */
     MoveM operator*( const MoveM& rhs ) const;
      
      /*
       * cube2 =MoveM* cube1
       * is the same as
       * cube2.applyMove( move, cube1 )
       */
      CubeM operator*( const CubeM& rhs ) const;

    protected:
      ///////////////////////////////////
      // hard-coded mappings of the basic moves
      void buildIdentity( );
      void buildU( );
      void buildUPrime( );
      void buildL( );
      void buildLPrime( );
      void buildF( );
      void buildFPrime( );
      void buildR( );
      void buildRPrime( );
      void buildB( );
      void buildBPrime( );
      void buildD( );
      void buildDPrime( );
      void buildE( );
      void buildEPrime( );
      void buildM( );
      void buildMPrime( );
      void buildS( );
      void buildSPrime( );
      void buildX( );
      void buildXPrime( );
      void buildY( );
      void buildYPrime( );
      void buildZ( );
      void buildZPrime( );
      // hard-coded mappings of the basic moves
      ///////////////////////////////////

      /* dst_index = mTransform[ src_index ] */
      std::vector< int > mTransform;

      double mCost; // quarter-turn metric cost

      std::string mName; // notational name of the move
    private:
    };
    
    /*
     *
     *MoveMclass
     *
     **************************************************************/
    
    /**************************************************************
     *
     * Cube class
     *
     */
    
    class CubeM {
    public:
      // Default, constructs a solved cube
      CubeM( );

      // all facelets are the same
      // '*' facelets match anything
      bool operator==( const CubeM& rhs ) const;
      // one or more facelets are different
      bool operator!=( const CubeM& rhs ) const;
      // for the first differing facelet, lhs is less than rhs
      bool operator<( const CubeM& rhs ) const;

      // changes the cube into 54 unique facelet values
      // instead of the 6 color-based facelet values
      void buildTestPattern( );
      
      // assigns to the facelets the values in the string
      // string must have exactly 54 characters
      // no checks for valid facelet values are made
      void assignFromString( const std::string& s );

      // assigns to the facelets the solved values
      void assignSolved( );

      // returns the facelets for read-only access
      const std::vector< Facelet >& getFacelets( ) const;

      /* copies cube.mFacelets, being transformed by move.mTransform,
       * into this->mFacelets.
       * *this and cube must be different cubes.
       * returns *this by reference
       *
       * example: cube2.applyMove( move, cube1 );
       * cube2 is a copy of cube1, withMoveMapplied
       */
      CubeM& applyMove( const MoveM& move, const CubeM& cube );
      
      /* copies cube.mFacelets, being reverse transformed by 
       * move.mTransform, into this->mFacelets.
       * *this and cube must be different cubes.
       * returns *this by reference
       *
       * example: cube2.applyMove( move, cube1 );
       * cube2 is a copy of cube1, with the reverse ofMoveMapplied
       */
      CubeM& unapplyMove( const MoveM& move, const CubeM& cube );
      
      /* 
       * Cube *MoveMsafely does unapplyMove( )
       *
       * example: cube2 = cube1 * move;
       * cube2 is a copy of cube1, with the reverse ofMoveMapplied
       */
      CubeM operator*( const MoveM& rhs ) const;

      /* 
       * mergeCube modifies the current cube,
       * Cube + Cube produces a new cube, where 
       *  '*' + 'x' -> 'x'
       *  'x' + '*' -> 'x'
       *  'x' + 'x' -> 'x'
       *  '*' + '*' -> '*'
       *  'x' + 'y' -> exception
       */
      CubeM& mergeCube( const CubeM& cube );
      /*
       * cube1 + cube2 is the same as
       * cube1.mergeCube( cube2 );
       */
      CubeM operator+( const CubeM& rhs ) const;
      // helper function display to cout
      // void displayCube() const;
      // display the cube in the "T" format
      std::ostream& tDisplay( std::ostream& os ) const;
      // display the cube with the 54 facelets concatenated into 1 word
      std::ostream& oneWordDisplay( std::ostream& os ) const;
      // display the cube with each face making a word, all in 1 line
      std::ostream& oneLineDisplay( std::ostream& os ) const;

      /* replaces any '*' facelets with 'x' facelets */
      void wildcardToX( );

    protected:
      // the 54 facelets
      std::vector< Facelet > mFacelets;

    private:
    };



    MoveM::MoveM( ) 
      : mTransform( NUM_FACELETS_TOTAL ), mCost( 0.0 ), mName( "Uninitialized" ) {
      // empty
    }

    // Construct one of the basic moves
    MoveM::MoveM( const BasicMoveM basic_move )
      : mTransform( NUM_FACELETS_TOTAL ), mCost( 0.0 ), mName( "Uninitialized" ) {
      switch( basic_move ) {
      case M_IDENTITY: buildIdentity( ); break;
      case M_U:  buildU( ); break;
      case M_UP: buildUPrime( ); break;
      case M_L:  buildL( ); break;
      case M_LP: buildLPrime( ); break;
      case M_F:  buildF( ); break;
      case M_FP: buildFPrime( ); break;
      case M_R:  buildR( ); break;
      case M_RP: buildRPrime( ); break;
      case M_B:  buildB( ); break;
      case M_BP: buildBPrime( ); break;
      case M_D:  buildD( ); break;
      case M_DP: buildDPrime( ); break;
      case M_EQ: buildE( ); break;
      case M_EP: buildEPrime( ); break;
      case M_M:  buildM( ); break;
      case M_MP: buildMPrime( ); break;
      case M_S:  buildS( ); break;
      case M_SP: buildSPrime( ); break;
      case M_X:  buildX( ); break;
      case M_XP: buildXPrime( ); break;
      case M_Y:  buildY( ); break;
      case M_YP: buildYPrime( ); break;
      case M_Z:  buildZ( ); break;
      case M_ZP: buildZPrime( ); break;
      default: 
        std::stringstream ss;
        ss << "Unknown BasicMove: ( " << (int)basic_move << " )";
        //throw Exception( ss.str( ) );
        break;
      }
    }

    // read-only access to the transform vector
    const std::vector< int >& MoveM::getTransform( ) const {
      return mTransform;
    }

    // the number of quarter-turns required to perform the move.
    // each of the x, y, z transforms add 0.001 to the cost.
    double MoveM::getCost( ) const {
      return mCost;
    }

    // a textual representation of the move, e.g. "U F' D' L"
    const std::string& MoveM::getName( ) const {
      return mName;
    }

    /* replace this->mTransform contents with the composite of move1 followed by move2
     * It's OK if move1 == *this.
     * Don't get too tricky.  If move2 == *this, errors will occur.
     * Returns *this by reference.
     */
    MoveM& MoveM::compose( const MoveM& move2, const MoveM& move1 ) {
      /* move1 == *this is ok, move2 == *this is not ok */
      if ( &move2 == this ) {
        std::stringstream ss;
        ss << "move2 can not be *this, will cause errors.";
        //throw Exception( ss.str( ) );
      }
      unsigned int i1, i2, i3;
      for( i1 = 0; i1 < mTransform.size( ); i1++ ) {
        i2 = move1.mTransform[ i1 ];
        i3 = move2.mTransform[ i2 ];
        this->mTransform[ i1 ] = i3;
      }
      this->mCost = move2.mCost + move1.mCost;
      this->mName = move1.mName + " " + move2.mName;
      return *this;
    }

    /*
     * move3 = move1 * move2 
     * is the same as
     * move3.compose( move1, move2 )
     */
   MoveM MoveM::operator*( const MoveM& rhs ) const {
     MoveM m;
      return m.compose( *this, rhs );
    }
    
    /*
     * cube2 =MoveM* cube1
     * is the same as
     * cube2.applyMove( move, cube1 )
     */
    CubeM MoveM::operator*( const CubeM& rhs ) const {
      CubeM c;
      return c.applyMove( *this, rhs );
    }
    
    ///////////////////////////////////////////////////////////
    // hard-coded mappings of the basic moves
    void MoveM::buildIdentity( ) {
      mName = "";
      unsigned int i;
      for( i = 0; i < mTransform.size( ); i++ ) {
        mTransform[ i ] = i;
      }
    }

    void MoveM::buildU( ) {
      mCost = 1.0;
      buildIdentity( );
      mName = "U";
      mTransform[ 0 ] = 2;
      mTransform[ 1 ] = 5;
      mTransform[ 2 ] = 8;
      mTransform[ 3 ] = 1;
      mTransform[ 5 ] = 7;
      mTransform[ 6 ] = 0;
      mTransform[ 7 ] = 3;
      mTransform[ 8 ] = 6;

      mTransform[ 9 ] = 36;
      mTransform[ 10 ] = 37;
      mTransform[ 11 ] = 38;
      mTransform[ 18 ] = 9;
      mTransform[ 19 ] = 10;
      mTransform[ 20 ] = 11;
      mTransform[ 27 ] = 18;
      mTransform[ 28 ] = 19;
      mTransform[ 29 ] = 20;
      mTransform[ 36 ] = 27;
      mTransform[ 37 ] = 28;
      mTransform[ 38 ] = 29;
    }

    void MoveM::buildUPrime( ) {
     MoveM u( M_U );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 1.0;
      mName = "U'";
    }

    void MoveM::buildL( ) {
      mCost = 1.0;
      buildIdentity( );
      mName = "L";
      mTransform[ 9 ] = 11;
      mTransform[ 10 ] = 14;
      mTransform[ 11 ] = 17;
      mTransform[ 12 ] = 10;
      mTransform[ 14 ] = 16;
      mTransform[ 15 ] = 9;
      mTransform[ 16 ] = 12;
      mTransform[ 17 ] = 15;

      mTransform[ 0 ] = 18;
      mTransform[ 3 ] = 21;
      mTransform[ 6 ] = 24;
      mTransform[ 18 ] = 45;
      mTransform[ 21 ] = 48;
      mTransform[ 24 ] = 51;
      mTransform[ 45 ] = 44;
      mTransform[ 48 ] = 41;
      mTransform[ 51 ] = 38;
      mTransform[ 38 ] = 6;
      mTransform[ 41 ] = 3;
      mTransform[ 44 ] = 0;
    }

    void MoveM::buildLPrime( ) {
     MoveM u( M_L );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 1.0;
      mName = "L'";
    }

    void MoveM::buildF( ) {
      mCost = 1.0;
      buildIdentity( );
      mName = "F";
      mTransform[ 18 ] = 20;
      mTransform[ 19 ] = 23;
      mTransform[ 20 ] = 26;
      mTransform[ 21 ] = 19;
      mTransform[ 23 ] = 25;
      mTransform[ 24 ] = 18;
      mTransform[ 25 ] = 21;
      mTransform[ 26 ] = 24;

      mTransform[ 6 ] = 27;
      mTransform[ 7 ] = 30;
      mTransform[ 8 ] = 33;
      mTransform[ 27 ] = 47;
      mTransform[ 30 ] = 46;
      mTransform[ 33 ] = 45;
      mTransform[ 47 ] = 17;
      mTransform[ 46 ] = 14;
      mTransform[ 45 ] = 11;
      mTransform[ 17 ] = 6;
      mTransform[ 14 ] = 7;
      mTransform[ 11 ] = 8;
    }

    void MoveM::buildFPrime( ) {
     MoveM u( M_F );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 1.0;
      mName = "F'";
    }

    void MoveM::buildR( ) {
      buildIdentity( );
      mCost = 1.0;
      mName = "R";
      mTransform[ 27 ] = 29;
      mTransform[ 28 ] = 32;
      mTransform[ 29 ] = 35;
      mTransform[ 30 ] = 28;
      mTransform[ 32 ] = 34;
      mTransform[ 33 ] = 27;
      mTransform[ 34 ] = 30;
      mTransform[ 35 ] = 33;

      mTransform[ 8 ] = 36;
      mTransform[ 5 ] = 39;
      mTransform[ 2 ] = 42;
      mTransform[ 36 ] = 53;
      mTransform[ 39 ] = 50;
      mTransform[ 42 ] = 47;
      mTransform[ 53 ] = 26;
      mTransform[ 50 ] = 23;
      mTransform[ 47 ] = 20;
      mTransform[ 26 ] = 8;
      mTransform[ 23 ] = 5;
      mTransform[ 20 ] = 2;
    }

    void MoveM::buildRPrime( ) {
     MoveM u( M_R );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 1.0;
      mName = "R'";
    }

    void MoveM::buildB( ) {
      buildIdentity( );
      mCost = 1.0;
      mName = "B";
      mTransform[ 36 ] = 38;
      mTransform[ 37 ] = 41;
      mTransform[ 38 ] = 44;
      mTransform[ 39 ] = 37;
      mTransform[ 41 ] = 43;
      mTransform[ 42 ] = 36;
      mTransform[ 43 ] = 39;
      mTransform[ 44 ] = 42;

      mTransform[ 2 ] = 9;
      mTransform[ 1 ] = 12;
      mTransform[ 0 ] = 15;
      mTransform[ 9 ] = 51;
      mTransform[ 12 ] = 52;
      mTransform[ 15 ] = 53;
      mTransform[ 51 ] = 35;
      mTransform[ 52 ] = 32;
      mTransform[ 53 ] = 29;
      mTransform[ 35 ] = 2;
      mTransform[ 32 ] = 1;
      mTransform[ 29 ] = 0;
    }

    void MoveM::buildBPrime( ) {
     MoveM u( M_B );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 1.0;
      mName = "B'";
    }

    void MoveM::buildD( ) {
      mCost = 1.0;
      buildIdentity( );
      mName = "D";
      mTransform[ 45 ] = 47;
      mTransform[ 46 ] = 50;
      mTransform[ 47 ] = 53;
      mTransform[ 48 ] = 46;
      mTransform[ 50 ] = 52;
      mTransform[ 51 ] = 45;
      mTransform[ 52 ] = 48;
      mTransform[ 53 ] = 51;

      mTransform[ 24 ] = 33;
      mTransform[ 25 ] = 34;
      mTransform[ 26 ] = 35;
      mTransform[ 33 ] = 42;
      mTransform[ 34 ] = 43;
      mTransform[ 35 ] = 44;
      mTransform[ 42 ] = 15;
      mTransform[ 43 ] = 16;
      mTransform[ 44 ] = 17;
      mTransform[ 15 ] = 24;
      mTransform[ 16 ] = 25;
      mTransform[ 17 ] = 26;
    }

    void MoveM::buildDPrime( ) {
     MoveM u( M_D );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 1.0;
      mName = "D'";
    }

    void MoveM::buildE( ) {
      mCost = 2.0;
      buildIdentity( );
      mName = "E";
      mTransform[ 12 ] = 21;
      mTransform[ 13 ] = 22;
      mTransform[ 14 ] = 23;
      mTransform[ 21 ] = 30;
      mTransform[ 22 ] = 31;
      mTransform[ 23 ] = 32;
      mTransform[ 30 ] = 39;
      mTransform[ 31 ] = 40;
      mTransform[ 32 ] = 41;
      mTransform[ 39 ] = 12;
      mTransform[ 40 ] = 13;
      mTransform[ 41 ] = 14;
    }

    void MoveM::buildEPrime( ) {
     MoveM u( M_EQ );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 2.0;
      mName = "E'";
    }

    void MoveM::buildM( ) {
      mCost = 2.0;
      buildIdentity( );
      mName = "M";
      mTransform[ 1 ] = 19;
      mTransform[ 4 ] = 22;
      mTransform[ 7 ] = 25;
      mTransform[ 19 ] = 46;
      mTransform[ 22 ] = 49;
      mTransform[ 25 ] = 52;
      mTransform[ 46 ] = 43;
      mTransform[ 49 ] = 40;
      mTransform[ 52 ] = 37;
      mTransform[ 43 ] = 1;
      mTransform[ 40 ] = 4;
      mTransform[ 37 ] = 7;
    }

    void MoveM::buildMPrime( ) {
     MoveM u( M_M );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 2.0;
      mName = "M'";
    }

    void MoveM::buildS( ) {
      mCost = 2.0;
      buildIdentity( );
      mName = "S";
      mTransform[ 3 ] = 28;
      mTransform[ 4 ] = 31;
      mTransform[ 5 ] = 34;
      mTransform[ 28 ] = 50;
      mTransform[ 31 ] = 49;
      mTransform[ 34 ] = 48;
      mTransform[ 50 ] = 16;
      mTransform[ 49 ] = 13;
      mTransform[ 48 ] = 10;
      mTransform[ 16 ] = 3;
      mTransform[ 13 ] = 4;
      mTransform[ 10 ] = 5;
    }

    void MoveM::buildSPrime( ) {
     MoveM u( M_S );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 2.0;
      mName = "S'";
    }

    void MoveM::buildX( ) {
      mName = "x";
      mCost = 0.001;
      // Up
      mTransform[ 0 ] = 44;
      mTransform[ 1 ] = 43;
      mTransform[ 2 ] = 42;
      mTransform[ 3 ] = 41;
      mTransform[ 4 ] = 40;
      mTransform[ 5 ] = 39;
      mTransform[ 6 ] = 38;
      mTransform[ 7 ] = 37;
      mTransform[ 8 ] = 36;

      // Left
      mTransform[ 9 ] = 15;
      mTransform[ 10 ] = 12;
      mTransform[ 11 ] = 9;
      mTransform[ 12 ] = 16;
      mTransform[ 13 ] = 13;
      mTransform[ 14 ] = 10;
      mTransform[ 15 ] = 17;
      mTransform[ 16 ] = 14;
      mTransform[ 17 ] = 11;

      // Front
      mTransform[ 18 ] = 0;
      mTransform[ 19 ] = 1;
      mTransform[ 20 ] = 2;
      mTransform[ 21 ] = 3;
      mTransform[ 22 ] = 4;
      mTransform[ 23 ] = 5;
      mTransform[ 24 ] = 6;
      mTransform[ 25 ] = 7;
      mTransform[ 26 ] = 8;

      // Right
      mTransform[ 27 ] = 29;
      mTransform[ 28 ] = 32;
      mTransform[ 29 ] = 35;
      mTransform[ 30 ] = 28;
      mTransform[ 31 ] = 31;
      mTransform[ 32 ] = 34;
      mTransform[ 33 ] = 27;
      mTransform[ 34 ] = 30;
      mTransform[ 35 ] = 33;

      // Back
      mTransform[ 36 ] = 53;
      mTransform[ 37 ] = 52;
      mTransform[ 38 ] = 51;
      mTransform[ 39 ] = 50;
      mTransform[ 40 ] = 49;
      mTransform[ 41 ] = 48;
      mTransform[ 42 ] = 47;
      mTransform[ 43 ] = 46;
      mTransform[ 44 ] = 45;

      // Down
      mTransform[ 45 ] = 18;
      mTransform[ 46 ] = 19;
      mTransform[ 47 ] = 20;
      mTransform[ 48 ] = 21;
      mTransform[ 49 ] = 22;
      mTransform[ 50 ] = 23;
      mTransform[ 51 ] = 24;
      mTransform[ 52 ] = 25;
      mTransform[ 53 ] = 26;
    }

    void MoveM::buildXPrime( ) {
     MoveM u( M_X );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 0.001;
      mName = "x'";
    }

    void MoveM::buildY( ) {
      mName = "y";
      mCost = 0.001;
      // Up
      mTransform[ 0 ] = 2;
      mTransform[ 1 ] = 5;
      mTransform[ 2 ] = 8;
      mTransform[ 3 ] = 1;
      mTransform[ 4 ] = 4;
      mTransform[ 5 ] = 7;
      mTransform[ 6 ] = 0;
      mTransform[ 7 ] = 3;
      mTransform[ 8 ] = 6;

      // Left
      mTransform[ 9 ] = 36;
      mTransform[ 10 ] = 37;
      mTransform[ 11 ] = 38;
      mTransform[ 12 ] = 39;
      mTransform[ 13 ] = 40;
      mTransform[ 14 ] = 41;
      mTransform[ 15 ] = 42;
      mTransform[ 16 ] = 43;
      mTransform[ 17 ] = 44;

      // Front
      mTransform[ 18 ] = 9;
      mTransform[ 19 ] = 10;
      mTransform[ 20 ] = 11;
      mTransform[ 21 ] = 12;
      mTransform[ 22 ] = 13;
      mTransform[ 23 ] = 14;
      mTransform[ 24 ] = 15;
      mTransform[ 25 ] = 16;
      mTransform[ 26 ] = 17;

      // Right
      mTransform[ 27 ] = 18;
      mTransform[ 28 ] = 19;
      mTransform[ 29 ] = 20;
      mTransform[ 30 ] = 21;
      mTransform[ 31 ] = 22;
      mTransform[ 32 ] = 23;
      mTransform[ 33 ] = 24;
      mTransform[ 34 ] = 25;
      mTransform[ 35 ] = 26;

      // Back
      mTransform[ 36 ] = 27;
      mTransform[ 37 ] = 28;
      mTransform[ 38 ] = 29;
      mTransform[ 39 ] = 30;
      mTransform[ 40 ] = 31;
      mTransform[ 41 ] = 32;
      mTransform[ 42 ] = 33;
      mTransform[ 43 ] = 34;
      mTransform[ 44 ] = 35;

      // Down
      mTransform[ 45 ] = 51;
      mTransform[ 46 ] = 48;
      mTransform[ 47 ] = 45;
      mTransform[ 48 ] = 52;
      mTransform[ 49 ] = 49;
      mTransform[ 50 ] = 46;
      mTransform[ 51 ] = 53;
      mTransform[ 52 ] = 50;
      mTransform[ 53 ] = 47;
    }

    void MoveM::buildYPrime( ) {
     MoveM u( M_Y );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 0.001;
      mName = "y'";
    }

    void MoveM::buildZ( ) {
      mName = "z";
      mCost = 0.001;
      // Up
      mTransform[ 0 ] = 29;
      mTransform[ 1 ] = 32;
      mTransform[ 2 ] = 35;
      mTransform[ 3 ] = 28;
      mTransform[ 4 ] = 31;
      mTransform[ 5 ] = 34;
      mTransform[ 6 ] = 27;
      mTransform[ 7 ] = 30;
      mTransform[ 8 ] = 33;

      // Left
      mTransform[ 9 ] = 2;
      mTransform[ 10 ] = 5;
      mTransform[ 11 ] = 8;
      mTransform[ 12 ] = 1;
      mTransform[ 13 ] = 4;
      mTransform[ 14 ] = 7;
      mTransform[ 15 ] = 0;
      mTransform[ 16 ] = 3;
      mTransform[ 17 ] = 6;

      // Front
      mTransform[ 18 ] = 20;
      mTransform[ 19 ] = 23;
      mTransform[ 20 ] = 26;
      mTransform[ 21 ] = 19;
      mTransform[ 22 ] = 22;
      mTransform[ 23 ] = 25;
      mTransform[ 24 ] = 18;
      mTransform[ 25 ] = 21;
      mTransform[ 26 ] = 24;

      // Right
      mTransform[ 27 ] = 47;
      mTransform[ 28 ] = 50;
      mTransform[ 29 ] = 53;
      mTransform[ 30 ] = 46;
      mTransform[ 31 ] = 49;
      mTransform[ 32 ] = 52;
      mTransform[ 33 ] = 45;
      mTransform[ 34 ] = 48;
      mTransform[ 35 ] = 51;

      // Back
      mTransform[ 36 ] = 42;
      mTransform[ 37 ] = 39;
      mTransform[ 38 ] = 36;
      mTransform[ 39 ] = 43;
      mTransform[ 40 ] = 40;
      mTransform[ 41 ] = 37;
      mTransform[ 42 ] = 44;
      mTransform[ 43 ] = 41;
      mTransform[ 44 ] = 38;

      // Down
      mTransform[ 45 ] = 11;
      mTransform[ 46 ] = 14;
      mTransform[ 47 ] = 17;
      mTransform[ 48 ] = 10;
      mTransform[ 49 ] = 13;
      mTransform[ 50 ] = 16;
      mTransform[ 51 ] = 9;
      mTransform[ 52 ] = 12;
      mTransform[ 53 ] = 15;
    }

    void MoveM::buildZPrime( ) {
     MoveM u( M_Z );
      buildIdentity( );
      compose( u, *this );
      compose( u, *this );
      compose( u, *this );
      mCost = 0.001;
      mName = "z'";
    }
    // hard-coded mappings of the basic moves
    ///////////////////////////////////////////////////////////
    
    
    /*
     *
     *MoveMclass
     *
     **************************************************************/
    
    /**************************************************************
     *
     * Cube class
     *
     */

    // Solved cube constructed
    CubeM::CubeM( ) 
      : mFacelets( NUM_FACELETS_TOTAL ) {
      const char * const facelets = "wgrboy";
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        mFacelets[ i ] = facelets[ i / NUM_FACELETS_PER_SIDE ];
      }
    }

    // all facelets are the same
    // '*' facelets match anything
    bool CubeM::operator==( const CubeM& rhs ) const {
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        if( ( mFacelets[ i ] != rhs.mFacelets[ i ] ) &&
            ( rhs.mFacelets[ i ] != '*' ) &&
            ( mFacelets[ i ] != '*' ) ) {
          return false;
        }
      }
      return true;
    }

    // one or more facelets are different
    bool CubeM::operator!=( const CubeM& rhs ) const {
      return !( *this == rhs );
    }

    // for the first differing facelet, lhs is less than rhs
    bool CubeM::operator<( const CubeM& rhs ) const {
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        if ( mFacelets[ i ] < rhs.mFacelets[ i ] ) {
          // less than
          return true;
        } else if ( mFacelets[ i ] > rhs.mFacelets[ i ] ) {
          // greater than
          return false;
        }
      }
      // equal
      return false;
    }

    // changes the cube into 54 unique facelet values
    // instead of the 6 color-based facelet values
    void CubeM::buildTestPattern( ) {
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        mFacelets[ i ] = 'A' + i;
      }
    }

    // assigns to the facelets the values in the string
    // string must have exactly 54 characters
    // no checks for valid facelet values are made
    void CubeM::assignFromString( const std::string& s ) {
      if( s.size( ) != mFacelets.size( ) ) {
        std::stringstream ss;
        ss << "Assignment string of incorrect length: \"" << s << "\"";
        //throw Exception( ss.str( ) );
      }
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        mFacelets[ i ] = s[ i ];
      }
    }

    // assigns to the facelets the solved values
    void CubeM::assignSolved( ) {
      assignFromString( "wwwwwwwwwgggggggggrrrrrrrrrbbbbbbbbboooooooooyyyyyyyyy" );
    }

    // returns the facelets for read-only access
    const std::vector< Facelet >& CubeM::getFacelets( ) const {
      return mFacelets;
    }
 
    /* copies cube.mFacelets, being transformed by move.mTransform,
     * into this->mFacelets.
     * *this and cube must be different cubes.
     * returns *this by reference
     *
     * example: cube2.applyMove( move, cube1 );
     * cube2 is a copy of cube1, withMoveMapplied
     */
    CubeM& CubeM::applyMove( const MoveM& move, const CubeM& cube ) {
      if ( &cube == this ) {
        std::stringstream ss;
        ss << "cube can not be *this, will cause errors.";
       // throw Exception( ss.str( ) );
      }
      const std::vector< int >& transform = move.getTransform( );
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        this->mFacelets[ transform[ i ] ] = cube.mFacelets[ i ];
      }
      return *this;
    }

    /* copies cube.mFacelets, being reverse transformed by 
     * move.mTransform, into this->mFacelets.
     * *this and cube must be different cubes.
     * returns *this by reference
     *
     * example: cube2.applyMove( move, cube1 );
     * cube2 is a copy of cube1, with the reverse ofMoveMapplied
     */
    CubeM& CubeM::unapplyMove( const MoveM& move, const CubeM& cube ) {
      if ( &cube == this ) {
        std::stringstream ss;
        ss << "cube can not be *this, will cause errors.";
        //throw Exception( ss.str( ) );
      }
      const std::vector< int >& transform = move.getTransform( );
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        this->mFacelets[ i ] = cube.mFacelets[ transform[ i ] ];
      }
      return *this;
    }
    
    /* 
     * Cube *MoveMsafely does unapplyMove( )
     *
     * example: cube2 = cube1 * move;
     * cube2 is a copy of cube1, with the reverse ofMoveMapplied
     */
    CubeM CubeM::operator*( const MoveM& rhs ) const {
      CubeM c;
      return c.unapplyMove( rhs, *this );
    }

    /* 
     * mergeCube modifies the current cube,
     * Cube + Cube produces a new cube, where 
     *  '*' + 'x' -> 'x'
     *  'x' + '*' -> 'x'
     *  'x' + 'x' -> 'x'
     *  '*' + '*' -> '*'
     *  'x' + 'y' -> exception
     */
    CubeM& CubeM::mergeCube( const CubeM& cube ) {
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        if( mFacelets[ i ] == '*' ) {
          mFacelets[ i ] = cube.mFacelets[ i ];
        } else if( cube.mFacelets[ i ] == '*' ) {
          // no change
        } else if( mFacelets[ i ] == cube.mFacelets[ i ] ) {
          // no change
        } else {
          std::stringstream ss;
          ss << "Can not merge cubes with non-matching non-wildcards" << std::endl;
          oneLineDisplay( ss );
          ss << std::endl;
          cube.oneLineDisplay( ss );
          ss << std::endl;
         // throw Exception( ss.str( ) );
        }
      }
      return *this;
    }

    /*
     * cube1 + cube2 is the same as
     * cube1.mergeCube( cube2 );
     */
    CubeM CubeM::operator+( const CubeM& rhs ) const {
      CubeM c = *this;
      return c.mergeCube( rhs );
    }


    // display the cube in the "T" format
    std::ostream& CubeM::tDisplay( std::ostream& os ) const {
      unsigned int i, j;
      
      /* Up face */
      os << "     ";
      for( i = 0; i < 3; i++ ) {
        os << mFacelets[ i ];
      }
      os << std::endl;

      os << "     ";
      for( i = 3; i < 6; i++ ) {
        os << mFacelets[ i ];
      }
      os << std::endl;

      os << "     ";
      for( i = 6; i < 9; i++ ) {
        os << mFacelets[ i ];
      }
      os << std::endl;


      /* Middle faces */
      os << std::endl;
      for( j = 0; j < 9; j+=3 ) {
        for( i = 9+j; i < 12+j; i++ ) {
          os << mFacelets[ i ];
        }
        os << "  ";
        for( i = 18+j; i < 21+j; i++ ) {
          os << mFacelets[ i ];
        }
        os << "  ";
        for( i = 27+j; i < 30+j; i++ ) {
          os << mFacelets[ i ];
        }
        os << "  ";
        for( i = 36+j; i < 39+j; i++ ) {
          os << mFacelets[ i ];
        }
        os << std::endl;
      }
      os << std::endl;

      /* Down face */
      os << "     ";
      for( i = 45; i < 48; i++ ) {
        os << mFacelets[ i ];
      }
      os << std::endl;

      os << "     ";
      for( i = 48; i < 51; i++ ) {
        os << mFacelets[ i ];
      }
      os << std::endl;

      os << "     ";
      for( i = 51; i < 54; i++ ) {
        os << mFacelets[ i ];
      }
      os << std::endl;


      return os;
    }

    // display the cube with the 54 facelets concatenated into 1 word
    std::ostream& CubeM::oneWordDisplay( std::ostream& os ) const {
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        os << mFacelets[ i ];
      }
      return os;
    }

    // display the cube with each face making a word, all in 1 line
    std::ostream& CubeM::oneLineDisplay( std::ostream& os ) const {
      unsigned int i;
      for( i = 0; i < mFacelets.size( ); i++ ) {
        if( i > 0 && i % NUM_FACELETS_PER_SIDE == 0 ) {
          os << " ";
        }
        os << mFacelets[ i ];
      }
      return os;
    }

    /* replaces any '*' facelets with 'x' facelets */
    void CubeM::wildcardToX( ) {
      for( auto it = mFacelets.begin( ); it != mFacelets.end( ); it++ ) {
        if( *it == '*' ) {
          *it = 'x';
        }
      }
    }
// #include "CubeModel.h"
// #include "CubeModel.cpp"
Manhattan::Manhattan(){}
Manhattan::~Manhattan( ) {
      // empty
}
double Manhattan::distancesum(std::vector<double> x, std::vector<double> y,std::vector<double> z) 
{ 
    double sum = 0.0; 
    // x0 current x1 sloved
    // for each point, finding distance to 
    // rest of the point 
    for ( unsigned int i = 0; i < x.size()-1; i+=2){
        //cout <<   x[i] << endl;
        // for (int j = i + 1; j < y.size(); j++){
              sum += (abs(x[i] - x[i+1]) + 
              abs(y[i] - y[i+1]) +
              abs(z[i] - z[i+1])); 

        // }
    } 
    //std::cout << "SUM " << sum << std::endl;
    return sum; 
} 
std::vector< Facelet > applyMove(std::vector< Facelet > thisCube , MoveM  move, const std::vector< Facelet > currentCube ) {
  // if ( &cube == this ) {
  //   std::stringstream ss;
  //   ss << "cube can not be *this, will cause errors.";
  //   throw Exception( ss.str( ) );         this->mFacelets[ transform[ i ] ] = cube.mFacelets[ i ];
  // }
  const std::vector< int >& transform = move.getTransform( );
  unsigned int i;
  for( i = 0; i < currentCube.size( ); i++ ) {
    thisCube[ transform[ i ] ] = currentCube[ i ];
  }
  return thisCube;
}

std::vector< Facelet > correctAxis(const std::vector< Facelet > currentCube){
 // w 4, g 13, r 22, b 31,o 40, y49 
  //z
  // const BasicMove zz() ;
  // const BasicMove xx();
  // const BasicMove yy();
  // Move u( M_U );
  MoveM z(M_Z);
  MoveM x(M_X);
  MoveM y(M_Y);
  std::vector< Facelet > thisCube = currentCube;
  if (currentCube[4] != 'w' && currentCube[13]!='g' && currentCube[22]=='r' && currentCube[31] !='b' && currentCube[40] == 'o' && currentCube[49] != 'y'  ){
     correctAxis(applyMove(thisCube ,z , currentCube ));
  }
  if (currentCube[4] != 'w' && currentCube[13] =='g' && currentCube[22]!='r' && currentCube[31] =='b' && currentCube[40] != 'o' && currentCube[49] != 'y'  ){
     correctAxis(applyMove(thisCube ,x , currentCube ));
  }
  if (currentCube[4] == 'w' && currentCube[13] !='g' && currentCube[22]!='r' && currentCube[31] !='b' && currentCube[40] != 'o' && currentCube[49] == 'y'  ){
     correctAxis(applyMove(thisCube ,y , currentCube ));
  }
  return currentCube;

      // Cube thisCube = state->getCube();
      // return new State( thisCube.applyMove(action->getMove(), state->getCube() ) ) ;

}

// Driven Program 
// char, int color, value 
//std::map< char,int> distance;
std::vector < std::string > Manhattan::getFaceletsToValue(const std::vector< Facelet > mFacelets){
    //look for corspending edges 
    std::vector < std::string > mFaceletsValues(54);
    unsigned int i;
    for( i = 0; i < mFaceletsValues.size( ); i++ ) {
        mFaceletsValues[ i ] = "*" ;
    }
    //total of 12 edges
    std::map< std::string,int> edges;
    edges["wo"] = 8;edges["wg"] = 6;edges["wb"] = 4;
    edges["wr"] = 2;edges["go"] = 17;edges["gr"] = 12;
    edges["gy"] = 23;edges["rb"] = 10;edges["ry"] = 19;
    edges["bo"] = 15;edges["by"] = 21;edges["oy"] = 25;
    std::map< std::string,int> corners;
    corners["wgo"] = 9;corners["wbo"] = 7;corners["wgr"] = 3;corners["wbr"] = 1;
    corners["ygo"] = 26;corners["ybo"] = 24;corners["ygr"] = 20;corners["ybr"] = 18;

    for( auto it = corners.begin( ); it != corners.end( ); it++ ) {
        for(unsigned int i = 0; i < cornersfirstIndexes.size(); i++){
            // combinations of WGR,WRG,RWG,RGW,GWR,GRW
            std::string currentString = "";
            int acsiicurrentString = 0;
            int acsiicornerString = 0;


            currentString = currentString + mFacelets[cornersfirstIndexes[i]] + mFacelets[cornerssecondIndexes[i]] + mFacelets[cornersthirdIndexes[i]] ;

            for (char c : currentString) {
                acsiicurrentString += c*c;

            }
            for (char c :  it->first) {
                acsiicornerString += c*c;
            }

            if(acsiicurrentString == acsiicornerString ){
            mFaceletsValues[cornersfirstIndexes[i]] =  mFacelets[cornersfirstIndexes[i]] + std::to_string(it->second);
            mFaceletsValues[cornerssecondIndexes[i]] = mFacelets[cornerssecondIndexes[i]] + std::to_string(it ->second);
            mFaceletsValues[cornersthirdIndexes[i]] = mFacelets[cornersthirdIndexes[i]] + std::to_string(it ->second);
            currentString = "";
            acsiicurrentString = 0;
            acsiicornerString = 0;

            }
        }


    }



    for( auto it = edges.begin( ); it != edges.end( ); it++ ) {
        for(unsigned int i = 0; i < edgefirstIndexes.size(); i++){
            std::string thisString = "";
            int asciiedgeString = 0;
            int acsiicurrentString = 0;
            thisString = thisString + mFacelets[edgefirstIndexes[i]] + mFacelets[edgesecondIndexes[i]];
            for (char c : thisString) {
                acsiicurrentString += c*c;
            }
            for (char c :  it->first) {
                asciiedgeString += c*c;
            }

            if(acsiicurrentString == asciiedgeString ){
            mFaceletsValues[edgefirstIndexes[i]] =  mFacelets[edgefirstIndexes[i]] + std::to_string(it->second);
            mFaceletsValues[edgesecondIndexes[i]] = mFacelets[edgesecondIndexes[i]] + std::to_string(it ->second);
            thisString = "";
            asciiedgeString = 0;
            acsiicurrentString = 0;
            }
        }


    }

    return mFaceletsValues;
}
/**Testing && Helper Fucntions **/
std::vector< Facelet > Manhattan::assignFromString( const std::string& s ) {
    std::vector< Facelet > mFacelets(54);
    unsigned int i;
    for( i = 0; i < mFacelets.size( ); i++ ) {
        mFacelets[ i ] = s[ i ];
    }
    return mFacelets;
}
void Manhattan::display( std::vector< std::string > mFacelets)  {
      unsigned int i, j;
      
      /* Up face */
      std::cout << "     ";
      for( i = 0; i < 3; i++ ) {
        std::cout << mFacelets[ i ];
      }
      std::cout << std::endl;

      std::cout << "     ";
      for( i = 3; i < 6; i++ ) {
        std::cout << mFacelets[ i ];
      }
      std::cout << std::endl;

      std::cout << "     ";
      for( i = 6; i < 9; i++ ) {
        std::cout << mFacelets[ i ];
      }
      std::cout << std::endl;


      /* Middle faces */
      std::cout << std::endl;
      for( j = 0; j < 9; j+=3 ) {
        for( i = 9+j; i < 12+j; i++ ) {
          std::cout << mFacelets[ i ];
        }
        std::cout << "  ";
        for( i = 18+j; i < 21+j; i++ ) {
          std::cout << mFacelets[ i ];
        }
        std::cout << "  ";
        for( i = 27+j; i < 30+j; i++ ) {
          std::cout << mFacelets[ i ];
        }
        std::cout << "  ";
        for( i = 36+j; i < 39+j; i++ ) {
          std::cout << mFacelets[ i ];
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;

      /* Down face */
      std::cout << "     ";
      for( i = 45; i < 48; i++ ) {
        std::cout << mFacelets[ i ];
      }
      std::cout << std::endl;

      std::cout << "     ";
      for( i = 48; i < 51; i++ ) {
        std::cout << mFacelets[ i ];
      }
      std::cout << std::endl;

      std::cout << "     ";
      for( i = 51; i < 54; i++ ) {
        std::cout << mFacelets[ i ];
      }
      std::cout << std::endl;


      
}
std::vector< Facelet > Manhattan::getSolvedFaclets()
{
    std::vector< Facelet > mFacelets(54);
    const char * const facelets = "wgrboy";
    unsigned int i;
    for( i = 0; i < mFacelets.size( ); i++ ) {
        mFacelets[ i ] = facelets[ i / 9 ];
    }
    return mFacelets;
}
void Manhattan::testFaceletsValue(){
    std::vector< Facelet > c1 = assignFromString("wgrrwoobroyyogorrogwwgrowrygybwbybrywybbobrgggwogybywb");
    int centerCube = 0;
    std::vector < std::string > c1Values = getFaceletsToValue(c1);
    for(unsigned int i = 0; i < c1Values.size( ); i++ ) {
        if(c1Values[i].length()  < 2){
        centerCube++;
        }
    }
    if(centerCube > 6){
        std::cout << "TEST FAILED!! " << std::endl;
    }else{
        std::cout << "TEST PASSED!! " << std::endl;
    }
}
void Manhattan::testACSIIValues(){
    int unsigned matched = 0;
    std::vector <std::string> strings = {"wo", "wg", "wb", "wr", "go", "gr", "gy", "rb", "ry", "bo", "by", "oy", "wgo", "wbo", "wgr",
        "wbr", "ygo", "ybo", "ygr", "ybr"
    };
    
    std::vector <int> values;
    for (unsigned int i = 0; i < strings.size(); i++){
        int v1 = 0;
        for (char c : strings[i]) {
         v1 += c*c;
        }
        values.push_back(v1);
    }
    std::cout << " string vector size " << values.size() << std::endl;
    for (unsigned int i = 0 ; i < values.size(); i++ ){
       
        for(unsigned k = 0; k < values.size(); k++){
            if (values[i] == values[k] ){
            //cout << strings[i] << " == " << strings[k] << endl;
            matched++;
                
            }            
        }

    }
    if(matched > strings.size()){
        std::cout << "Test failed";
    }else{
        std::cout << "Test Passed!";
    }
}
/**End of Testing*/
double Manhattan::heursticSumAllFacelets(const std::vector< Facelet > currentCube, const std::vector< Facelet > goalsFacelets){
// compute edges for heurstic since corners tend to take more time and less benefit
// if all edges are wildcard default heurstic
        std::vector< Facelet > correctedCube = correctAxis(currentCube); 
    
    std::vector < std::string > currentCubeFaceletsValues = getFaceletsToValue(correctedCube);
    //std::cout << "currentCube values assigned " << std::endl;
    std::vector<double> xCoords;
    std::vector<double> yCoords;
    std::vector<double> zCoords;
     // for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
      // const std::vector< Facelet > goalsFacelets = mgoal_cube_in[i].getFacelets();  
    std::vector < std::string > goalFaceletsValues = getFaceletsToValue(goalsFacelets);
    //std::cout << "goal cube values assigned " << std::endl;
          // display(currentCubeFaceletsValues);
          //display(goalFaceletsValues);
          for( int unsigned j = 0; j < goalFaceletsValues.size( ); j++ ) {
            //std::cout << "goal loop" << std::endl;
            if((currentCubeFaceletsValues[j] != goalFaceletsValues[j]) && (currentCubeFaceletsValues[j] != "*") &&  goalFaceletsValues[j] != "*" ){
              // misplacedFaceletsIndex.push_back(j);
              //std::cout << "mismatch w goalsValue condition passed " << std::endl;

                for(unsigned int i = 0; i < slovedCube.size(); i++){
                  if(currentCubeFaceletsValues[j] == slovedCube[i]){
                    //std::cout << "match w CubeValue w SlovedCube condition passed at  " << j << std::endl;
                    xCoords.push_back(coords[j][0]);
                    xCoords.push_back(coords[i][0]);
                    yCoords.push_back(coords[j][1]);
                    yCoords.push_back(coords[i][1]);
                    zCoords.push_back(coords[j][2]);
                    zCoords.push_back(coords[i][2]);
                  }
                }              
            }
            
      }
  //  }
      if (xCoords.size() != 0 ){
        return distancesum(xCoords,yCoords,zCoords)/(double)8.0;
      }
      //std::cout <<"M returned value " << distancesum(xCoords,yCoords,zCoords)/(double)8.0 << std::endl;
      return 0.0;
      // cout << "Dis " << dis << endl; 
    // cout << mismatch << endl;
// }

}
double Manhattan::heursticsumAllEdges(const std::vector< Facelet > currentCube, const std::vector< Facelet > goalsFacelets){
// compute edges for heurstic since corners tend to take more time and less benefit
// if all edges are wildcard default heurstic
    std::vector< Facelet > correctedCube = correctAxis(currentCube); 
    
    std::vector < std::string > currentCubeFaceletsValues = getFaceletsToValue(correctedCube);
// for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
    std::vector<double> xCoords;
    std::vector<double> yCoords;
    std::vector<double> zCoords;
    
    
    //for( unsigned int i = 0; i < mgoal_cube_in.size(); i++){
     // const std::vector< Facelet > goalsFacelets = mgoal_cube_in[i].getFacelets();  
          std::vector < std::string > goalFaceletsValues = getFaceletsToValue(goalsFacelets);
          // display(currentCubeFaceletsValues);
          // display(goalFaceletsValues);
          for( int unsigned j = 0; j < edgeIndexes.size( ); j++ ) {
            if((currentCubeFaceletsValues[edgeIndexes[j]] != goalFaceletsValues[edgeIndexes[j]]) && (currentCubeFaceletsValues[edgeIndexes[j]] != "*") &&  goalFaceletsValues[j] != "*" ){
              // misplacedFaceletsIndex.push_back(j);
              

                for(unsigned int i = 0; i < slovedCube.size(); i++){
                  if(currentCubeFaceletsValues[edgeIndexes[j]] == slovedCube[i]){
                    xCoords.push_back(coords[edgeIndexes[j]][0]);
                    xCoords.push_back(coords[i][0]);
                    yCoords.push_back(coords[edgeIndexes[j]][1]);
                    yCoords.push_back(coords[i][1]);
                    zCoords.push_back(coords[edgeIndexes[j]][2]);
                    zCoords.push_back(coords[i][2]);
                  }
                }              
            }
            
      }
   // }
      if (xCoords.size() != 0 ){
        return distancesum(xCoords,yCoords,zCoords)/(double)8.0;
      }
      return 0.0;
    // cout << mismatch << endl;
// }

}



// int main() 
// { 
//     std::vector< Facelet > sloved = assignFromString("ggyrwogbbyyybgowowrrybryrgboybbbrrwwrwogowgrbgywgyoowo");
//     //std::vector < std::string > mFaceletsValues = getFaceletsToValue(sloved);
//     heursticsumAllEdges(sloved);
//     // cout << "{";
//     // for(unsigned int i = 0; i < mFaceletsValues.size( ); i++ ) {
//     //     cout << "\"" << mFaceletsValues[ i ] << "\"" << ","  ; 
//     // }
//     // cout << "}";
//     //display(mFaceletsValues);
    
//     // cout << mFaceletsValues;
//     // test();
//     return 0; 
// } 
