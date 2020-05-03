config apply_solution 1
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+06
config storage_limit 1e+06
config heuristic 1

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
echo config heuristic 1

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

echo Was it solved?
equal goal
