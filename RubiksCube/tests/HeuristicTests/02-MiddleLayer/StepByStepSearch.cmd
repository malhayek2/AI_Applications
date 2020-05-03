config apply_solution 1
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+06
config storage_limit 1e+06
config heuristic 1
echo init cube wwbrwoogbrbgrggbwowwyorrbyroywwbyyogrbgbogyrrwggoybyyo

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
    wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***ry**** \
    wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***oy**** \


run astarSearch.cmd
moves D D' R R' F F' B B'

echo g-o L
echo ------------------init Red_blue edge goal ----------
init goal \
    wwwwwwwww ggg*g**** rrr*rr*** bbbbb**** ooo*o**** ****y**** \

run astarSearch.cmd
echo ---------- init red_green edge goal ----------------
init goal \
    wwwwwwwww ggg*gg*** rrrrr**** bbbbb**** ooo*o**** ****y**** \

run astarSearch.cmd

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
echo moves D R D' R' D' B' D B
echo --- sometimes it fails here....
init goal \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ****y**** \

run astarSearch.cmd

echo ---- middle layer sloved --------

equal goal