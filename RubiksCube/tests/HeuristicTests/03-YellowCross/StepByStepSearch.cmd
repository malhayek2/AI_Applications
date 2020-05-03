config apply_solution 1
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+07
config storage_limit 1e+07
config heuristic 1
echo init cube yyyywrbwbrowggbogwrryorwooyoygbbygbrogbboogggbwrryrwww

echo ------------------init white_blue edge ----------
init goal \
    ****ww*** ****g**** ****r**** *b**b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init White_orange edge goal----------
init goal \
    *w**ww*** ****g**** ****r**** *b**b**** *o**o**** ****y**** \

run astarSearch.cmd
echo ------------------init white_green edge goal -----
init goal \
    *w*www*** *g**g**** ****r**** *b**b**** *o**o**** ****y**** \

run astarSearch.cmd
echo ------------------init white_red goal----------
init goal \
    *w*www*w* *g**g**** *r**r**** *b**b**** *o**o**** ****y**** \

run astarSearch.cmd
echo -----Solved White Cross-----------------
echo ----- switch heuristic to corners + edges ------
config heuristic 1
echo ------------------init white_Green_orange corner----------
init goal \
    ww*www*w* gg**g**** *r**r**** *b**b**** *oo*o**** ****y**** \

run astarSearch.cmd
echo ------------------init white_Blue_orange corner----------
init goal \
    wwwwww*w* gg**g**** *r**r**** *bb*b**** ooo*o**** ****y**** \

run astarSearch.cmd
echo ------------------init white_green_red corner----------
init goal \
    wwwwwwww* ggg*g**** rr**r**** *bb*b**** ooo*o**** ****y**** \

run astarSearch.cmd

echo ------------------init white_blue_red corner----------
init goal \
    wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**** ****y**** \

run astarSearch.cmd
echo ------white corners sloved ------
echo ----- switch heuristic to edges only ------
config heuristic 1
echo if they are oppiste then R U' R' U F' U U F U F' U U F

echo ---------- init LEFT OR RIGHT STATE goal for R-B Edge ----------------
init goal \
    wwwwwwwww ggg*g**** rrr*r**r* bbb*b**** ooo*o**** *b**y**** \
    wwwwwwwww ggg*g**** rrr*r**** bbb*b**b* ooo*o**** ****yr*** \


run astarSearch.cmd
moves D D' R R' F F' B B'


echo ------------------init Red_blue edge goal ----------
init goal \
    wwwwwwwww ggg*g**** rrr*rr*** bbbbb**** ooo*o**** ****y**** \

run astarSearch.cmd
echo ---------- init red_green edge goal ----------------
init goal \
    wwwwwwwww ggg*gg*** rrrrr**** bbbbb**** ooo*o**** ****y**** \

run astarSearch.cmd
moves basic
echo ------------------init green_orange edge goal----------
init goal \
    wwwwwwwww gggggg*** rrrrr**** bbbbb**** ooo*oo*** ****y**** \

run astarSearch.cmd
echo -- 3 possible casees LEFT RIGHT or double LEFT ------
echo moves D D' R R' F F' for r-b 
echo add B for green orange
echo because they are flipped commands are incorrect 
echo blue on yellow translate  U R U' R' U' F' U F -> D' R' D R D F D' F'
echo greeon orange F' D' R' B D B R D F
echo red on yellow U R U' R' U F' U F -> D F D' F' D R' D R

echo ----- switch heuristic to edges and corners ------
config heuristic 1
echo ------------------init blue_orange edge goal----------

echo --- sometimes it fails here....
init goal \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ****y**** \

run astarSearch.cmd

echo ---- middle layer sloved --------


echo ---- Yellow Cross attempts ------
echo backwards L
echo F U R U' R' F' -> yellow cross
init goal \ 
wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** ***yy**y* \
wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** y**yy**yy \
wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** **y*y*yy* \


echo Line
echo F R U R' U' F' -> yellow cross
init goal \
wwwwwwwww gggggg*** rrrrrr*** bbbbbb*y* oooooo*** *y**y**y* \
wwwwwwwww gggggg*** rrrrrr*** bbbbbb*y* oooooo*** *y**y**yy \
wwwwwwwww gggggg*** rrrrrr*** bbbbbb*y* oooooo*** yyy*y*yyy \

echo dot
echo L alg -> line
init goal \
wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** ****y**** \
wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** y***y**** \
wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** y*y*y*y*y \


echo cross 
init goal \
wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yyy*y* \
wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *yyyyy*y* \
wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** yy*yyyyy* \


init goal \ 
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yyy*y* \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *yyyyy*y* \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** yy*yyyyy* \
    wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** ****y**** \
    wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** y***y**** \
    wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** y*y*y*y*y \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*y* oooooo*** *y**y**y* \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*y* oooooo*** *y**y**yy \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*y* oooooo*** yyy*y*yyy \
    wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** ***yy**y* \
    wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** y**yy**yy \
    wwwwwwwww gggggg*** rrrrrr*y* bbbbbb*y* oooooo*** **y*y*yy* \

run astarSearch.cmd

echo ---------------------------------------------------------
echo ---- bottom layer has to match one of the following ------
init goal \ 
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yy**** \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ***yyy*** \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yyy*y* \

run astarSearch.cmd

echo ------------------init bottom yellow goal----------
echo --failed here
echo R R' F F' B U U' L L'
echo wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yyyyy* \
echo wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *yyyyy*y* \
echo wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yyyyy* \
init goal \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** yyyyyyyyy \

run astarSearch.cmd
echo --- A, B or A, D or B, C ---- 
echo ---init yellow corners YBO && YGO || YBO && YRG || YGO && YRB --- 
init goal \
    wwwwwwwww ggggggg** rrrrrr*** bbbbbb**b ooooooo*o yyyyyyyyy \
    wwwwwwwww gggggg**g rrrrrrr** bbbbbb**b ooooooo** yyyyyyyyy \
    wwwwwwwww ggggggg** rrrrrr**r bbbbbbb** oooooo**o yyyyyyyyy \    

run astarSearch.cmd
echo --- search sloved state ----
init goal \
    wwwwwwwww ggggggggg rrrrrrrrr bbbbbbbbb ooooooooo yyyyyyyyy \

run astarSearch.cmd


equal goal
