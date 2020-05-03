config apply_solution 1
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+07
config storage_limit 1e+07

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
echo-----Solved White Cross-----------------
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
echo ------------------init Red_blue edge goal ----------
init goal \
    wwwwwwwww ggg*g**** rrr*rr*** bbbbb**** ooo*o**** ****y**** \

run astarSearch.cmd
echo ---------- init red_green edge goal ----------------
init goal \
    wwwwwwwww ggg*gg*** rrrrrr*** bbbbb**** ooo*o**** ****y**** \

run astarSearch.cmd

echo ------------------init blue_orange goal----------
init goal \
    wwwwwwwww ggg*gg*** rrrrrr*** bbbbbbb*** oooooo**** ****y**** \

run astarSearch.cmd

echo ------------------init green_orange goal----------
init goal \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbbb*** ooooooo*** ****y**** \

run astarSearch.cmd
echo ---- middle layer sloved --------
echo ---- bottom layer has to match one of the following ------
init goal \ 
    wwwwwwwww gggggg*** rrrrrr*** bbbbbbb*** ooooooo*** *y*yy**** \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbbb*** ooooooo*** ***yyy*** \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbbb*** ooooooo*** *y*yyy*y* \

run astarSearch.cmd

echo ------------------init bottom yellow goal----------
init goal \
    wwwwwwwww gggggg*** rrrrrr*** bbbbbbb*** ooooooo*** yyyyyyyyy \

run astarSearch.cmd
echo --- A, B or A, D or B, C ---- 
echo ---init yellow corners YBO && YGO || YBO && YRG || YGO && YRB --- 
init goal \
    wwwwwwwww ggggggg** rrrrrr*** bbbbbbb**b oooooooo*o yyyyyyyyy \
    wwwwwwwww gggggg**g rrrrrrr** bbbbbbb**b oooooooo** yyyyyyyyy \
	wwwwwwwww ggggggg** rrrrrr**r bbbbbbbb** ooooooo**o yyyyyyyyy \    
run astarSearch.cmd
echo --- search sloved state ----
init goal \
    wwwwwwwww ggggggggg rrrrrrrrr bbbbbbbbbb oooooooooo yyyyyyyyy \
