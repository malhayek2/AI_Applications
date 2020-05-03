config apply_solution 1
config cube_display 3
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+07
config storage_limit 1e+07
echo ------------------init White_green edge goal ----------
init goal \
    ***ww**** *g**g**** ****r**** ****b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init White_orange edge goal----------
init goal \
    *w*ww**** *g**g**** ****r**** ****b**** *o**o**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WGO goal --------------
init goal \
    ww*ww**** gg*gg**** ****r**** ****b**** *oo*oo*** ****y**** \

run astarSearch.cmd
echo ------------------init white_blue edge ----------
init goal \
    ww*www*** gg**g**** ****r**** *b**b**** *oo*oo*** ****y**** \

run astarSearch.cmd
echo ------------------init blue_orange goal----------
init goal \
    ww*www*** gg**g**** ****r**** *b**bb*** *oooo**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WBO goal ----------
init goal \
    www*www** gg**g**** ****r**** *bb*bb*** ooooo**** ****y**** \

run astarSearch.cmd
echo ------------------init white_green edge goal -----
init goal \
    wwwwwww** gg**g**** ****r**** *bb*b**** ooooo**** ****y**** \

run astarSearch.cmd
echo ------------------init white_red goal----------
init goal \
    wwwwwwww* gg**g**** *r**r**** *bb*b**** ooooo**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WGR goal ----------
init goal \
    wwwwwwww* ggg*gg*** rr*rr**** *bb*b**** ooooo**** ****y**** \

run astarSearch.cmd
echo ------------------init Red_blue edge goal ----------
init goal \
    wwwwwwww* ggg*g**** rr*rrr*** *bbbb**** ooooo**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WBR goal ----------
init goal \
    wwwwwwwww ggg*g**** rrrrrr*** bbbbb**** ooooo**** ****y**** \

run astarSearch.cmd
echo ------------------init Yellow_green edge goal ----------
init goal \
    wwwwwwwww ggg*g**g* rrrrrr*** bbbbb**** ooooo**** ***yy**** \

run astarSearch.cmd
echo ------------------init Yellow_orange edge goal----------
init goal \
    wwwwwwwww ggg*g**g* rrrrrr*** bbbbb**** ooooo**o* ***yy**y* \

run astarSearch.cmd
echo ------------------init 2x2x2 YGO goal ----------
init goal \
    wwwwwwwww ggggg*gg* rrrrrr*** bbbbb**** oooooo*oo ***yy*yy* \

run astarSearch.cmd
echo ------------------init Yellow_blue edge goal----------
init goal \
    wwwwwwwww ggggg*gg* rrrrrr*** bbbbb**b* oooooo*oo ***yyyyy* \

run astarSearch.cmd
echo ------------------init 2x2x2 YBO goal ----------
init goal \
    wwwwwwwww ggggg*gg* rrrrrr*** bbbbbb*bb ooooooooo ***yyyyyy \

run astarSearch.cmd
echo ------------------init Red_Green edge goal ----------
init goal \
    wwwwwwwww gggggggg* rrrrrr*** bbbbbb*bb ooooooooo ***yyyyyy \

run astarSearch.cmd
echo ------------------init Yellow_red edge goal ----------
init goal \
    wwwwwwwww gggggggg* rrrrrr*r* bbbbbb*bb ooooooooo *y*yyyyyy \

run astarSearch.cmd
echo ------------------init 2x2x2 YRG goal ----------
init goal \
    wwwwwwwww ggggggggg rrrrrrrr* bbbbbb*bb ooooooooo yy*yyyyyy \

run astarSearch.cmd

echo ------------------init 2x2x2 YRB goal ----------
init goal \
    wwwwwwwww ggggggggg rrrrrrrrr bbbbbbbbb ooooooooo yyyyyyyyy \
    
run astarSearch.cmd

