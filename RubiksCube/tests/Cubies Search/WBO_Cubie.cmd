config apply_solution 1
config cube_display 3
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+06
config storage_limit 1e+06

echo ------------------init white_blue edge ----------
init goal \
    ****ww*** ****g**** ****r**** *b**b**** ****o**** ****y**** \

run astarSearch.cmd

echo ------------------init blue_orange goal----------
init goal \
    ****ww*** ****g**** ****r**** *b**bb*** ***oo**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WBO goal ----------
init goal \
    *ww*ww*** ****g**** ****r**** *bb*bb*** oo*oo**** ****y**** \

run astarSearch.cmd

echo Was it solved?
equal goal