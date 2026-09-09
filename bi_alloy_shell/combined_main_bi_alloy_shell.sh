#!/bin/bash
echo "Enter the grid value"
read grid
echo "$grid">grid.txt
./size_bi_alloy_shell
echo "Enter the percentage of Au in intermediate alloy layer"
		read GMF_inter
		echo "$GMF_inter">GMF_inter.txt
		./refractive_index_calculator_bi_alloy_shell_inter
echo "Enter the percentage of Au in outer alloy layer"
		read GMF_outer
		echo "$GMF_outer">GMF_outer.txt
		./refractive_index_calculator_bi_alloy_shell_outer
./ri_modification_bi_alloy_shell
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
	./ri_reading_bi_alloy_shell
	w=`cat w.txt`
	m1_re=`cat m1_re.txt`
	m1_im=`cat m1_im.txt`
	m2_re=`cat m2_re.txt`
	m2_im=`cat m2_im.txt`
	m3_re=`cat m3_re.txt`
	m3_im=`cat m3_im.txt`
./adda -dir bi_alloy_shell,run_$i,grid_$grid,size_$size1,core_$size2,inter_dia_$size3 -grid $grid -size $size -shape bishell $coat_ratioI $coat_ratioII -m $m1_re $m1_im $m2_re $m2_im $m3_re $m3_im  -lambda $w -save_geom
	done
./result_bi_alloy_shell

