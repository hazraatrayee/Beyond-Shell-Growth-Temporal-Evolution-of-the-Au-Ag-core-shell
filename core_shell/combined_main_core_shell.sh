#!/bin/bash
echo "Enter the grid value"
read grid
echo "$grid">grid.txt
./size_core_shell
./ri_modification_core_shell
echo "Calculation of spectrum for core-shell particle"
	size=`cat size.txt`
	size1=`cat size1.txt`
	size2=`cat size2.txt`
	ratio=`cat ratio.txt`
	for ((i=0;i<=600;i++))
	do
	echo "$i">count.txt
	./ri_reading_core_shell
	w=`cat w.txt`
	m1_re=`cat m1_re.txt`
	m1_im=`cat m1_im.txt`
	m2_re=`cat m2_re.txt`
	m2_im=`cat m2_im.txt`
./adda -dir core-shell,run_$i,grid_$grid,size_$size1,core_$size2 -grid $grid -size $size -shape coated $ratio -m $m1_re $m1_im $m2_re $m2_im  -lambda $w -save_geom
	done
./result_core_shell

