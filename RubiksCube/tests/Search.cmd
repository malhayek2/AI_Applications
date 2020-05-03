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
    *w**w**** ****g**** ****r**** ****b**** *o**o**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WGO goal --------------
init goal \
    ww*ww**** gg*gg**** ****r**** ****b**** *oo*oo*** ****y**** \

run astarSearch.cmd
echo ------------------init white_blue edge ----------
init goal \
    ****ww*** ****g**** ****r**** *b**b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init blue_orange goal----------
init goal \
    ****w**** ****g**** ****r**** ****bb*** ***oo**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WBO goal ----------
init goal \
    *ww*ww*** ****g**** ****r**** *bb*bb*** oo*oo**** ****y**** \

run astarSearch.cmd
echo ------------------init white_green edge goal -----
init goal \
    ***ww**** *g**g**** ****r**** ****b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init white_red goal----------
init goal \
    ****w**w* ****g**** *r**r**** ****b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WGR goal ----------
init goal \
    ***ww*ww* *gg*gg*** rr*rr**** ****b**** ***oo**** ****y**** \

run astarSearch.cmd
echo ------------------init Red_blue edge goal ----------
init goal \
    ****w**** ****g**** ****rr*** ***bb**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WBR goal ----------
init goal \
    ****ww*ww ****g**** *rr*rr*** bb*bb**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init Yellow_green edge goal ----------
init goal \
    ****w**** ****g**g* ****r**** ****b**** ****o**** ***yy**** \

run astarSearch.cmd
echo ------------------init Yellow_orange edge goal----------
init goal \
    ****w**** ****g**** ****r**** ****b**** ****o**o* ****y**y* \

run astarSearch.cmd
echo ------------------init 2x2x2 YGO goal ----------
init goal \
    ****w**** ***gg*gg* ****r**** ****b**** ****oo*oo ***yy*yy* \

run astarSearch.cmd
echo ------------------init Yellow_blue edge goal----------
init goal \
    ****w**** ****g**** ****r**** ****b**b* ****o**** ****yy*** \

run astarSearch.cmd
echo ------------------init 2x2x2 YBO goal ----------
init goal \
    ****w**** ****g**** ****r**** ****bb*bb ***oo*oo* ****yy*yy \

run astarSearch.cmd
echo ------------------init Red_Green edge goal ----------
init goal \
    ****w**** ****gg*** ***rr**** ****b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init Yellow_red edge goal ----------
init goal \
    ****w**** ****g**** ****r**r* ****b**** ****o**** *y**y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 YRG goal ----------
init goal \
    ****w**** ****gg*gg ***rr*rr* ****b**** ****o**** yy*yy**** \

run astarSearch.cmd

echo ------------------init 2x2x2 YRB goal ----------
init goal \
    ****w**** ****g**** ****rr*rr ***bb*bb* ****o**** *yy*yy*** \
    
run astarSearch.cmd

