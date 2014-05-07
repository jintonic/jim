set grid
set size 0.6,0.6 
set terminal postscript eps enhanced color
set output "Tdp.eps"
set key right bottom box
set xlabel "relative humidity [%]"
set ylabel "dew point [degree in Celsius]"
plot "Tdp.dat" u 1:2 title "0 degree C" w l,\
       "Tdp.dat" u 1:3 title "10 degree C" w l,\
       "Tdp.dat" u 1:4 title "20 degree C" w l,\
       "Tdp.dat" u 1:5 title "30 degree C" w l
set output # close output file
