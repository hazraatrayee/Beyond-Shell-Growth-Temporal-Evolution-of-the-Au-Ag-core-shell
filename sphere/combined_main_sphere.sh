#!/bin/bash
echo "Enter the grid value"
read grid
echo "$grid">grid.txt
./size_sphere
./ri_modification_sphere
echo "Calculation of spectrum for spherical particle:"
	size=`cat size.txt`
	size1=`cat size1.txt`
	for ((i=0;i<=600;i++))
	do
	echo "$i">count.txt
	./ri_reading_sphere
	w=`cat w.txt`
	m1_re=`cat m1_re.txt`
	m1_im=`cat m1_im.txt`
./adda -dir sphere,run_$i,grid_$grid,size_$size1 -grid $grid -size $size -lambda $w -m $m1_re 	$m1_im -save_geom
	done
./result_sphere
