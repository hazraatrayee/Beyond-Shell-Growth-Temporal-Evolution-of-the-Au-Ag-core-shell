#!/bin/bash
echo "Enter the grid value"
read grid
echo "$grid">grid.txt
./size_bishell
echo "Enter the percentage of Au in intermediate alloy layer"
		read GMF
		echo "$GMF">GMF.txt
		./refractive_index_calculator_bishell
./ri_modification_bishell
 echo "Calculation of spectrum for bishell particle"
	size=`cat size.txt`
	size1=`cat size1.txt`
	size2=`cat size2.txt`
	size3=`cat size3.txt`
	coat_ratioI=`cat coat_ratioI.txt`
	coat_ratioII=`cat coat_ratioII.txt`
	for ((i=0;i<=600;i++))
	do
	echo "$i">count.txt
	./ri_reading_bishell
	w=`cat w.txt`
	m1_re=`cat m1_re.txt`
	m1_im=`cat m1_im.txt`
	m2_re=`cat m2_re.txt`
	m2_im=`cat m2_im.txt`
	m3_re=`cat m3_re.txt`
	m3_im=`cat m3_im.txt`
./adda -dir bishell,run_$i,grid_$grid,size_$size1,core_$size2,inter_dia_$size3 -grid $grid -size $size -shape bishell $coat_ratioI $coat_ratioII -m $m1_re $m1_im $m2_re $m2_im $m3_re $m3_im  -lambda $w -save_geom
	done
./result_bishell

