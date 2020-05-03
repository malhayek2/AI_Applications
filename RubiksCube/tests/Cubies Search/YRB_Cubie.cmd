config apply_solution 1
config cube_display 3
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+06
config storage_limit 1e+06

echo ------------------init Red_blue edge goal ----------
init goal \
    ****w**** ****g**** ****rr*** ***bb**** ****o**** ****y**** \

run astarSearch.cmd

echo ------------------init Yellow_red edge goal ----------
init goal \
    ****w**** ****g**** ****rr*r* ***bb**** ****o**** *y**y**** \

run astarSearch.cmd

echo ------------------init 2x2x2 YRB goal ----------
init goal \
    ****w**** ****g**** ****rr*rr ***bb*bb* ****o**** *yy*yy*** \
    
run astarSearch.cmd


echo Was it solved?
equal goal