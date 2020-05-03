config apply_solution 1
config cube_display 3
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+06
config storage_limit 1e+06

echo ------------------init white_green edge goal -----
init goal \
    ***ww**** *g**g**** ****r**** ****b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init white_red goal----------
init goal \
    ***ww**w* *g**g**** *r**r**** ****b**** ****o**** ****y**** \

run astarSearch.cmd
echo ------------------init 2x2x2 WGR goal ----------
init goal \
    ***ww*ww* *gg*gg*** rr*rr**** ****b**** ***oo**** ****y**** \

run astarSearch.cmd


echo Was it solved?
equal goal